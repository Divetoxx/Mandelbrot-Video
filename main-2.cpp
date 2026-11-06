#include <atomic>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <mpfr.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>

using std::vector;
using std::min;
using std::string;

const char* CENTER_RE = "-0.8432337645307515133246117300038447886638913178942914768815245";
const char* CENTER_IM = "0.2238180415580699591398982954803114403955748218705388777865576";
const char* START_VIEW_STR = "1.29e-49";
const char* END_VIEW_STR = "1.29e-57";
const int TOTAL_FRAMES = 1800;
const int WIDTH = 1080;
const int HEIGHT = 1080;
const int AA = 3;
const int MAX_ITER = 500000;
const double ESCAPE_RADIUS_SQUARED = 500000.0;
const int REF_SIZE = MAX_ITER + 200;

struct Complex {
    double re;
    double im;
};

#pragma pack(push, 1)
struct BMPHeader {
    uint16_t type{0x4D42};
    uint32_t size{0};
    uint32_t reserved{0};
    uint32_t offBits{54};
    uint32_t structSize{40};
    int32_t width{0};
    int32_t height{0};
    uint16_t planes{1};
    uint16_t bitCount{24};
    uint32_t compression{0};
    uint32_t sizeImage{0};
    int32_t xPixelsPerMeter{2834};
    int32_t yPixelsPerMeter{2834};
    uint32_t colorsUsed{0};
    uint32_t colorsImportant{0};
};
#pragma pack(pop)

 int main() {
    auto totalStartTime = std::chrono::high_resolution_clock::now();
    unsigned int numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4;

    const double PI = 3.14159265358979323846;
    uint8_t palette[256][3];
    for (int i = 0; i < 255; ++i) {
        palette[i][0] = static_cast<uint8_t>(std::lround(127.0 + 127.0 * std::cos(2.0 * PI * i / 255.0)));
        palette[i][1] = static_cast<uint8_t>(std::lround(127.0 + 127.0 * std::sin(2.0 * PI * i / 255.0)));
        palette[i][2] = palette[i][1];
    }
    palette[255][0] = 255; palette[255][1] = 255; palette[255][2] = 255;

    const long rawWidth = static_cast<long>(WIDTH) * AA;
    const long rawHeight = static_cast<long>(HEIGHT) * AA;
    const int rowBytes = (WIDTH * 3 + 3) & ~3;

    double final_size = std::stod(END_VIEW_STR);
    mpfr_prec_t dynamic_precision = static_cast<mpfr_prec_t>(53.0 - std::floor(std::log2(final_size))) + 20;
    if (dynamic_precision < 53) dynamic_precision = 53;

    std::fprintf(stderr, "Optimized precision calculated: %ld bits (Saved %ld bits vs 1000b)\n", 
                 dynamic_precision, 1000 - dynamic_precision);

    std::fprintf(stderr, "Calculating high-precision reference orbit using MPFR (ONCE)... ");
    auto refStartTime = std::chrono::high_resolution_clock::now();

    vector<Complex> referenceOrbit;
    referenceOrbit.reserve(REF_SIZE);

    mpfr_t centerRe, centerIm, zReMp, zImMp, tmp1, tmp2;
    mpfr_inits2(dynamic_precision, centerRe, centerIm, zReMp, zImMp, tmp1, tmp2, static_cast<mpfr_ptr>(nullptr));

    mpfr_set_str(centerRe, CENTER_RE, 10, MPFR_RNDN);
    mpfr_set_str(centerIm, CENTER_IM, 10, MPFR_RNDN);
    mpfr_set_ui(zReMp, 0, MPFR_RNDN);
    mpfr_set_ui(zImMp, 0, MPFR_RNDN);

    for (int iter = 0; iter < REF_SIZE - 1; ++iter) {
        Complex z{mpfr_get_d(zReMp, MPFR_RNDN), mpfr_get_d(zImMp, MPFR_RNDN)};
        referenceOrbit.push_back(z);
        if (z.re * z.re + z.im * z.im > ESCAPE_RADIUS_SQUARED) {
            break;
        }
        mpfr_mul(tmp1, zReMp, zImMp, MPFR_RNDN);
        mpfr_sqr(tmp2, zReMp, MPFR_RNDN);
        mpfr_sqr(zReMp, zImMp, MPFR_RNDN);
        mpfr_sub(zReMp, tmp2, zReMp, MPFR_RNDN);
        mpfr_add(zReMp, zReMp, centerRe, MPFR_RNDN);
        mpfr_mul_2ui(tmp1, tmp1, 1, MPFR_RNDN);
        mpfr_add(zImMp, tmp1, centerIm, MPFR_RNDN);
    }

    const int referenceLength = static_cast<int>(referenceOrbit.size());
    mpfr_clears(centerRe, centerIm, zReMp, zImMp, tmp1, tmp2, static_cast<mpfr_ptr>(nullptr));
    
    auto refEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> refElapsed = refEndTime - refStartTime;
    std::fprintf(stderr, "Done! Length: %d steps (Time: %.2f sec)\n\n", referenceLength, refElapsed.count());

    mpfr_t startViewMp, endViewMp, logStart, logEnd, logCurrent, viewSizeMp;
    mpfr_inits2(dynamic_precision, startViewMp, endViewMp, logStart, logEnd, logCurrent, viewSizeMp, static_cast<mpfr_ptr>(nullptr));
    mpfr_set_str(startViewMp, START_VIEW_STR, 10, MPFR_RNDN);
    mpfr_set_str(endViewMp, END_VIEW_STR, 10, MPFR_RNDN);
    mpfr_log(logStart, startViewMp, MPFR_RNDN);
    mpfr_log(logEnd, endViewMp, MPFR_RNDN);

    for (int frame = 0; frame < TOTAL_FRAMES; ++frame) {
        auto frameStartTime = std::chrono::high_resolution_clock::now();
        char current_output_file[64];
        std::sprintf(current_output_file, "%04d.bmp", frame);
        const int current_palette_frame = frame % 255;
        double progress = static_cast<double>(frame) / (TOTAL_FRAMES - 1);

        mpfr_t localTmp;
        mpfr_init2(localTmp, dynamic_precision);
        mpfr_sub(localTmp, logEnd, logStart, MPFR_RNDN);
        mpfr_mul_d(localTmp, localTmp, progress, MPFR_RNDN);
        mpfr_add(logCurrent, logStart, localTmp, MPFR_RNDN);
        mpfr_exp(viewSizeMp, logCurrent, MPFR_RNDN);
        
        const double sampleStep = mpfr_get_d(viewSizeMp, MPFR_RNDN) / rawWidth;
        mpfr_clear(localTmp);

        std::fprintf(stderr, "--- Frame %d/%d (%s) | Uniform Zoom | COLORS: %d ---\n", 
                     frame + 1, TOTAL_FRAMES, current_output_file, current_palette_frame);

        vector<Complex> coeff_A(REF_SIZE, {1.0, 0.0});
        vector<Complex> coeff_B(REF_SIZE, {0.0, 0.0});
        vector<double> rad_R(REF_SIZE, 2.0);
        vector<double> aS_squared(REF_SIZE, 0.0);
        
        for (int i = 0; i < referenceLength; ++i) {
            double r2 = referenceOrbit[i].re * referenceOrbit[i].re + referenceOrbit[i].im * referenceOrbit[i].im;
            aS_squared[i] = (r2 < ESCAPE_RADIUS_SQUARED) ? r2 : 0.0;
        }
        
        const int loop_limit = min(static_cast<int>(MAX_ITER), referenceLength - 105);

        {
            std::atomic<int> current_i{0};
            std::vector<std::thread> blaWorkers;
            for (unsigned int t = 0; t < numThreads; ++t) {
                blaWorkers.emplace_back([&]() {
                    while (true) {
                        int i = current_i++;
                        if (i >= loop_limit) break;

                        double min_r2 = ESCAPE_RADIUS_SQUARED;
                        for (int k = 0; k < 100; ++k) {
                            if (i + k >= referenceLength) break;
                            if (aS_squared[i + k] < min_r2) min_r2 = aS_squared[i + k];
                        }
                        rad_R[i] = std::sqrt(min_r2);
                        for (int k = 0; k < 100; ++k) {
                            if (i + k >= referenceLength) break;
                            double r_re = referenceOrbit[i + k].re;
                            double r_im = referenceOrbit[i + k].im;
                            double next_A_re = 2.0 * (r_re * coeff_A[i].re - r_im * coeff_A[i].im);
                            double next_A_im = 2.0 * (r_re * coeff_A[i].im + r_im * coeff_A[i].re);
                            double next_B_re = 2.0 * (r_re * coeff_B[i].re - r_im * coeff_B[i].im) + 1.0;
                            double next_B_im = 2.0 * (r_re * coeff_B[i].im + r_im * coeff_B[i].re);
                            coeff_A[i].re = next_A_re; coeff_A[i].im = next_A_im;
                            coeff_B[i].re = next_B_re; coeff_B[i].im = next_B_im;
                        }
                    }
                });
            }
            for (auto &w : blaWorkers) if (w.joinable()) w.join();
        }

        vector<uint8_t> image(static_cast<size_t>(rowBytes) * HEIGHT, 0);
        std::atomic<int> completedRows{0};
        std::mutex diskMutex;
        const Complex * reference = referenceOrbit.data();

        {
            std::atomic<int> current_y{0};
            std::vector<std::thread> renderWorkers;
            for (unsigned int t = 0; t < numThreads; ++t) {
                renderWorkers.emplace_back([&]() {
                    while (true) {
                        int y = current_y++;
                        if (y >= HEIGHT) break;

                        uint8_t* row = image.data() + static_cast<size_t>(y) * rowBytes;
                        for (int x = 0; x < WIDTH; ++x) {
                            unsigned blueSum = 0; unsigned greenSum = 0; unsigned redSum = 0;
                            for (int sampleY = 0; sampleY < AA; ++sampleY) {
                                const double deltaCIm = (static_cast<long>(y) * AA + sampleY - rawHeight / 2) * sampleStep;
                                for (int sampleX = 0; sampleX < AA; ++sampleX) {
                                    const double deltaCRe = (static_cast<long>(x) * AA + sampleX - rawWidth / 2) * sampleStep;
                                    double deltaRe = 0.0; double deltaIm = 0.0;
                                    double zRe = 0.0; double zIm = 0.0;
                                    int referenceIndex = 0;
                                    int iter = 0;
                                    while (iter < MAX_ITER) {
                                        if (zRe * zRe + zIm * zIm >= ESCAPE_RADIUS_SQUARED) {
                                            break;
                                        }
                                        double eps_abs2 = deltaRe * deltaRe + deltaIm * deltaIm;
                                        double limit_r2 = 1e-30 * rad_R[referenceIndex] * rad_R[referenceIndex];
                                        if (eps_abs2 < limit_r2 && (referenceIndex + 100 < loop_limit) && (iter + 100 < MAX_ITER)) {
                                            double backup_deltaRe = deltaRe; double backup_deltaIm = deltaIm;
                                            int backup_refIdx = referenceIndex; int backup_iter = iter;
                                            double next_eps_re = (coeff_A[referenceIndex].re * deltaRe - coeff_A[referenceIndex].im * deltaIm) + 
                                                                 (coeff_B[referenceIndex].re * deltaCRe - coeff_B[referenceIndex].im * deltaCIm);
                                            double next_eps_im = (coeff_A[referenceIndex].re * deltaIm + coeff_A[referenceIndex].im * deltaRe) + 
                                                                 (coeff_B[referenceIndex].re * deltaCIm + coeff_B[referenceIndex].im * deltaCRe);
                                            deltaRe = next_eps_re; deltaIm = next_eps_im;
                                            referenceIndex += 100; iter += 100;
                                            zRe = reference[referenceIndex].re + deltaRe;
                                            zIm = reference[referenceIndex].im + deltaIm;
                                            if (zRe * zRe + zIm * zIm >= ESCAPE_RADIUS_SQUARED) {
                                                deltaRe = backup_deltaRe; deltaIm = backup_deltaIm;
                                                referenceIndex = backup_refIdx; iter = backup_iter;
                                            } else {
                                                continue; 
                                            }
                                        }
                                        const double a = 2.0 * reference[referenceIndex].re + deltaRe;
                                        const double b = 2.0 * reference[referenceIndex].im + deltaIm;
                                        const double nextDeltaRe = a * deltaRe - b * deltaIm + deltaCRe;
                                        deltaIm = a * deltaIm + b * deltaRe + deltaCIm;
                                        deltaRe = nextDeltaRe;
                                        ++referenceIndex; ++iter;
                                        zRe = reference[referenceIndex].re + deltaRe;
                                        zIm = reference[referenceIndex].im + deltaIm;
                                        if (zRe * zRe + zIm * zIm < deltaRe * deltaRe + deltaIm * deltaIm || referenceIndex >= loop_limit) {
                                            deltaRe = zRe; deltaIm = zIm; referenceIndex = 0;
                                        }
                                    }
                                    const int remaining = MAX_ITER - iter;
                                    const uint8_t colorIndex = (remaining == 0) ? 255 : static_cast<uint8_t>(remaining % 254);

                                    const int paletteIndex = (colorIndex == 255) ? 255 : (colorIndex - current_palette_frame + 255) % 255;
                                    
                                    blueSum += palette[paletteIndex][0];
                                    greenSum += palette[paletteIndex][1];
                                    redSum += palette[paletteIndex][2];
                                }
                            }
                            const int samples = AA * AA;
                            row[x * 3 + 0] = static_cast<uint8_t>(blueSum / samples);
                            row[x * 3 + 1] = static_cast<uint8_t>(greenSum / samples);
                            row[x * 3 + 2] = static_cast<uint8_t>(redSum / samples);
                        }

                        const int done = ++completedRows;
                        if (done % 100 == 0 || done == HEIGHT) {
                            std::lock_guard<std::mutex> lock(diskMutex);
                            BMPHeader live_header;
                            live_header.width = WIDTH;
                            live_header.height = HEIGHT;
                            live_header.sizeImage = static_cast<uint32_t>(image.size());
                            live_header.size = live_header.sizeImage + 54;
                            FILE* live_file = std::fopen(current_output_file, "wb");
                            if (live_file) {
                                std::fwrite(&live_header, sizeof(live_header), 1, live_file);
                                std::fwrite(image.data(), 1, image.size(), live_file);
                                std::fflush(live_file);
                                std::fclose(live_file);
                            }
                        }
                    }
                });
            }
            for (auto &w : renderWorkers) if (w.joinable()) w.join();
        }

        auto frameEndTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> frameElapsed = frameEndTime - frameStartTime;
        std::fprintf(stderr, "-> Frame %s complete! (Time: %.2f sec)\n", current_output_file, frameElapsed.count());
    }

    auto totalEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalElapsed = totalEndTime - totalStartTime;
    std::fprintf(stderr, "\n=== SUCCESS! All 1800 frames generated in %.2f seconds ===\n", totalElapsed.count());
    std::fprintf(stderr, "Compiling video with FFmpeg...\n");
    string ffmpegExe = "ffmpeg.exe";
#ifndef _WIN32
    ffmpegExe = "./ffmpeg";
#endif
    string checkCmd = ffmpegExe + " -encoders -hide_banner | findstr h264_nvenc > nul 2>&1";
#ifndef _WIN32
    checkCmd = ffmpegExe + " -encoders -hide_banner | grep h264_nvenc > /dev/null 2>&1";
#endif
    bool hasNVENC = (system(checkCmd.c_str()) == 0);
    string videoCmd = ffmpegExe + " -y -framerate 30 -i %04d.bmp ";
        if (hasNVENC) {
        std::fprintf(stderr, "NVIDIA GPU detected! Using h264_nvenc for high-speed encoding...\n");
        videoCmd += "-c:v h264_nvenc -rc constqp -qp 20 -profile:v high -coder 1 -rc-lookahead 32 ";
    } else {
        std::fprintf(stderr, "NVIDIA GPU not found. Using libx264 (CPU)...\n");
        videoCmd += "-c:v libx264 -refs 6 -me_method umh -psy 0 -qp 20 -subq 7 -me_range 24 -deblock -6:-6 -bf 6 ";
    }
    videoCmd += "-pix_fmt yuv420p Mandelbrot-2.mp4";    
    int ret = system(videoCmd.c_str());
    if (ret == 0) {
        std::fprintf(stderr, "Done. Result saved as Mandelbrot-2.mp4\n");
    } else {
        std::fprintf(stderr, "FFmpeg failed or not found.\n");
    }
    return 0;
}
