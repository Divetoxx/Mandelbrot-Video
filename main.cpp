#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <string>
#include <atomic>
#include <omp.h>
#include <cstdio>
using namespace std;
const double PI = 3.14159265358979323846;
#pragma pack(push, 1)
struct BMPHeader {
    uint16_t type{0x4D42};
    uint32_t size{0};
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    uint32_t offBits{54};
    uint32_t structSize{40};
    int32_t  width{0};
    int32_t  height{0};
    uint16_t planes{1};
    uint16_t bitCount{24};
    uint32_t compression{0};
    uint32_t sizeImage{0};
    int32_t  xpelsPerMeter{2834};
    int32_t  ypelsPerMeter{2834};
    uint32_t clrUsed{0};
    uint32_t clrImportant{0};
};
#pragma pack(pop)
void save_bmp(const string& filename, const vector<uint8_t>& data, int w, int h) {
    int rowSize = (w * 3 + 3) & ~3;
    BMPHeader header;
    header.width = w;
    header.height = h;
    header.sizeImage = rowSize * h;
    header.size = header.sizeImage + 54;
    ofstream f(filename, ios::binary);
    f.write(reinterpret_cast<char*>(&header), 54);
    f.write(reinterpret_cast<const char*>(data.data()), data.size());
    f.close();
}
int main() {
    long double absc, ordi, size_val;
    int choice;
    std::cout << "Select point (1-9): ";
    if (!(std::cin >> choice)) choice = 1;
    switch (choice) {
        case 1: absc = -0.5503432753421602L; ordi = -0.6259312704294012L; size_val = 0.0000000000004L; break;
        case 2: absc = -0.691488093510181825L; ordi = -0.465680729473216972L; size_val = 0.000000000000003L; break;
        case 3: absc = -0.550345905862346513L; ordi = 0.625931416301985337L; size_val = 0.000000000000005L; break;
        case 4: absc = -1.78577278039667471L; ordi = -0.00000075696313293L; size_val = 0.000000000000004L; break;
        case 5: absc = -1.785772754399825165L; ordi = -0.000000756806080773L; size_val = 0.0000000000000014L; break;
        case 6: absc = -1.40353608594492038L; ordi = -0.02929181552009826L; size_val = 0.000000000000095L; break;
        case 7: absc = -1.7485462508265219L; ordi = 0.000002213770706L; size_val = 0.00000000000029L; break;
        case 8: absc = -1.94053809966024986L; ordi = -0.00000120260253359L; size_val = 0.00000000000003L; break;
        case 9:
        {
            ifstream ff("Mandelbrot.txt");
            if (!ff.is_open()) {
              cerr << "Error: Mandelbrot.txt not found!" << endl;
              return 1;
            }
            ff >> absc >> ordi >> size_val;
            ff.close();
            break;
        }
        default:
            std::cout << "Error: No such point!" << std::endl;
            return 1;
    }
    const int targetW = 1920;
    const int targetH = 1080;
    const int scale = 8;
    const int rawW = targetW * scale;
    const int rawH = targetH * scale;
    cout << "Step 1: Calculating Raw Map (" << rawW << "x" << rawH << ")..." << endl;
    vector<uint8_t> iterMap(rawW * rawH);
    long double step = size_val / rawW;
    long double startX = absc - (size_val / 2.0);
    long double startY = ordi - (step * rawH / 2.0);
    atomic<int> linesDone{0};
    #pragma omp parallel for schedule(dynamic)
    for (int b = 0; b < rawH; ++b) {
        for (int a = 0; a < rawW; ++a) {
            long double m = startX + a * step;
            long double n = startY + b * step;
            long double c = m, d = n, cc, dd;
            int t = 50000;
            do {
                cc = c * c; 
                dd = d * d;
                d = (c + c) * d + n;
                c = cc - dd + m;
                t--;
            } while (t > 0 && (cc + dd <= 1000000.0L));
            if (t == 0) {
                iterMap[b * rawW + a] = 255;
            } else {
                iterMap[b * rawW + a] = (uint8_t)(t % 255);
            }
        }
        if (++linesDone % 100 == 0) cout << "Progress: " << linesDone << "/" << rawH << "\r" << flush;
    }
    uint8_t pal[256][3];
    for (int a = 0; a < 255; ++a) {
        pal[a][0] = (uint8_t)round(127 + 127 * cos(2 * PI * a / 255.0));
        pal[a][1] = (uint8_t)round(127 + 127 * sin(2 * PI * a / 255.0));
        pal[a][2] = (uint8_t)round(127 + 127 * sin(2 * PI * a / 255.0));
    }
    pal[255][0] = 255; pal[255][1] = 255; pal[255][2] = 255;
    cout << "\nStep 2: Rendering frames..." << endl;
    int rowSize = (targetW * 3 + 3) & ~3;
    for (int frame = 0; frame < 255; ++frame) {
        vector<uint8_t> frameData(rowSize * targetH);
        #pragma omp parallel for schedule(static)
        for (int y = 0; y < targetH; ++y) {
            for (int x = 0; x < targetW; ++x) {
                uint32_t rSum = 0, gSum = 0, bSum = 0;
                for (int j = 0; j < scale; ++j) {
                    for (int i = 0; i < scale; ++i) {
                        uint8_t t = iterMap[(y * scale + j) * rawW + (x * scale + i)];
                        int colorIdx;
                            if (t == 255) {
                            colorIdx = 255;
                        } else {
                          colorIdx = (t - frame + 255) % 255;
                        }
                        bSum += pal[colorIdx][0];
                        gSum += pal[colorIdx][1];
                        rSum += pal[colorIdx][2];
                    }
                }
                int outIdx = y * rowSize + x * 3;
                frameData[outIdx + 0] = (uint8_t)(bSum >> 6);
                frameData[outIdx + 1] = (uint8_t)(gSum >> 6);
                frameData[outIdx + 2] = (uint8_t)(rSum >> 6);
            }
        }
        string filename = "frame_" + to_string(1000 + frame).substr(1) + ".bmp";
        save_bmp(filename, frameData, targetW, targetH);
        cout << "Frame " << frame << "/254 saved.   \r" << flush;
    }

    cout << "\nStep 3: Compiling video with FFmpeg..." << endl;
    string ffmpegExe = "ffmpeg.exe";
#ifndef _WIN32
    ffmpegExe = "./ffmpeg";
#endif
    string checkCmd = ffmpegExe + " -encoders -hide_banner | findstr h264_nvenc > nul 2>&1";
#ifndef _WIN32
    checkCmd = ffmpegExe + " -encoders -hide_banner | grep h264_nvenc > /dev/null 2>&1";
#endif
    bool hasNVENC = (system(checkCmd.c_str()) == 0);
    string videoCmd = ffmpegExe + " -y -stream_loop 3 -framerate 30 -i frame_%03d.bmp -bsf:v h264_metadata=video_full_range_flag=0 ";
    if (hasNVENC) {
        cout << "NVIDIA GPU detected! Using h264_nvenc for high-speed encoding..." << endl;
        videoCmd += "-c:v h264_nvenc -b:v 30M -profile:v high -coder 1 -rc-lookahead 32 ";
    } else {
        cout << "NVIDIA GPU not found. Using libx264 (CPU)..." << endl;
        videoCmd += "-c:v libx264 -refs 6 -me_method umh -partitions all -psy 0 -qp 20 -subq 9 -me_range 24 -deblock -6:-6 -bf 6 -i_qfactor 2 -trellis 0 -b_strategy 2 ";
    }
    videoCmd += "-color_range full -pix_fmt yuv420p Mandelbrot.mp4";
    int ret = system(videoCmd.c_str());

        if (ret == 0) {
        cout << "\nVideo compilation successful! Cleaning up frames..." << endl;
        for (int i = 0; i < 255; ++i) {
            string filename = "frame_" + to_string(1000 + i).substr(1) + ".bmp";
            std::remove(filename.c_str());
        }
        cout << "Done. Result saved as Mandelbrot.mp4" << endl;
    } else {
        cerr << "\nError: FFmpeg failed or not found. BMP frames are preserved in the folder." << endl;
    }
    return 0;
}

