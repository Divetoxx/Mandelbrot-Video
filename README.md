[![Language](https://img.shields.io/badge/Language-English-blue)](#english)
[![Язык](https://img.shields.io/badge/Язык-Русский-red)](#russian)

[![Download Windows](https://img.shields.io/badge/Download-Windows-brightgreen?logo=windows)](https://github.com/Divetoxx/Mandelbrot-Video/releases/latest/download/Mandelbrot_windows_x64.zip )
[![Download Linux](https://img.shields.io/badge/Download-Linux-orange?logo=linux)](https://github.com/Divetoxx/Mandelbrot-Video/releases/latest/download/Mandelbrot_linux_x64.tar.gz)
[![Source Code](https://img.shields.io/badge/Source_Code-ZIP-orange?logo=github)](https://github.com/Divetoxx/Mandelbrot-Video/archive/refs/heads/main.zip)
[![Source Code](https://img.shields.io/badge/Source_Code-TAR.GZ-lightgrey?logo=github)](https://github.com/Divetoxx/Mandelbrot-Video/archive/refs/heads/main.tar.gz)


<a name="english"></a>
# 🇺🇸 English Version

# Mandelbrot CLI: Renderer with Perturbation Theory (with a $10^{-308}$ hardware limit)

## Credits & Acknowledgments

This project implements advanced orbit phase management paradigms and perturbation algorithms 
developed by the fractal research community. Special thanks to the following authors and pioneers 
from the Fractal Forums, whose collaborative work made this engine possible:
* **Kevin Martin** - for pioneering loop optimization and edge-case escape techniques.
* **Zhuoran Yu** - for developing the dynamic orbit re-basing paradigm.
* **Claude Heiland-Allen** - for extensive deep zoom research and the creation of the MDZ project.

## Key Features:

* **High-Precision Reference:** The 5000-bit reference trajectory is computed exactly once per zoom layer.
* **Hardware-Native Performance:** Blazing-fast math for billions of pixels utilizing hardware-native double registers.
* When using double-precision floating-point numbers (on the order of $10^{-15}$), perturbation theory only allows you to zoom down to the **$10^{-308}$ level-no further.**
* **Innovative Algorithm:** Revolutionary *Reference Reset to Zero* implementation.
* **True 8x8 SSAA:** Pristine, anti-aliased image quality with 64 independent samples per pixel.
* **OpenMP Multi-threading:** High-speed parallel computing to maximize CPU utilization.
* **Yes, this is FFmpeg**-the 'Swiss Army knife' of video processing.

## Arbitrary Precision Arithmetic (Infinite Depth)

The engine is completely free from the hardware limitations of standard 64-bit (`double`) and 128-bit (`__float128`) data types, 
which inevitably lose significance and produce pixelated blocks at depths beyond $10^{-15}$ and $10^{-34}$ respectively.
* **MPFR/GMP Integration**: All high-precision navigation, mouse clicking, and keyboard arrow zooming are handled within a deep binary memory 
structure configured to **5000-bit precision**.
* **308-Digit Decimal Coordinate Cache (Hardware Double Wall):** Viewport coordinates are stored in `Mandelbrot.txt`. While the MPFR 
reference radar computes the center at 5000-bit precision, the hardware native `double` exponent limits the fast pixel engine to a maximum 
depth of $10^{-308}$, providing pristine clarity up to this physical silicon barrier.


## Blazing Fast Perturbation Theory

Deep fractal rendering no longer requires heavy "long-division-style" arbitrary precision math for every individual pixel, which 
historically slowed down deep zoom software by thousands of times.
* **Single-Pass Reference Calculation**: The ultra-heavy MPFR BigFloat radar calculates the precise reference trajectory 
for **only one central pixel per frame and strictly ONCE** at the beginning of the render.
* **Hardware-Accelerated Double Math**: The rest of the viewport (billions of super-sampled pixels) is processed concurrently at the 
native speed of the CPU's hardware `double` registers, calculating only tiny deviations (deltas) from the central axis. 
This optimization boosts rendering speeds by up to 1000x!

## Revolutionary Reference Reset to Zero Algorithm

This is a tremendous point of pride: the engine now operates under the exact same mathematical and architectural principles as the world's most advanced.
* **Dynamic Reset to Zero**: Now, each pixel checks the ratio of its full coordinates against 
its current delta at every step. If the delta grows too large or the central reference orbit terminates, the thread 
dynamically **resets its reading index to zero**, turning the accumulated coordinates into a new autonomous origin.
* **One-Step Beyond Escape Loop Optimization**: To squeeze maximum performance out of the CPU, the MPFR reference radar records 
exactly **one additional point** into the reference orbit array immediately after it exceeds the escape radius.
* **Elimination of Branching (Branch Unrolling)**: This elegant trick completely eliminated cumbersome `if` and `OR` conditions 
from the deepest iteration loop. The processor no longer wastes clock cycles on branch prediction, allowing the compiler 
to perfectly vectorize the math.


## Project Purpose

This is a high-end CLI workstation designed for the automated production of professional fractal video art. 
It manages the entire pipeline: from heavy-duty mathematical computations to the final assembly of the video 
file.

### Key Features:

*    **End-to-End Video Production**: The engine renders 255 high-precision frames, applies a smooth palette rotation, and automatically 
invokes FFmpeg to compile the final .mp4 video.
*    **Hardware-Aware Encoding**: The program detects your hardware to choose the best encoding strategy:
     - NVIDIA GPU detected: Uses h264_nvenc for ultra-fast hardware-accelerated encoding.
     - CPU only: Uses libx264 with professional-grade presets for maximum quality.
*    **Cinematic Quality (Full HD 1080p)**: Every video is rendered using SSAA 8x8 (64 Samples Per Pixel). This ensures that fine 
fractal details are perfectly reconstructed without the "sparkling" or aliasing artifacts common in digital video.
*    **Smart Cleanup**: Once the video is successfully compiled, the utility automatically deletes the temporary BMP 
frames (which can take up several gigabytes), leaving you only with the final Mandelbrot.mp4.

## Why use this?

*    **Content Generation**: Perfect for creating high-quality seamless loops for meditation videos, VJ sets, or motion backgrounds.
*    **Hardware Benchmark**: A unique hybrid workload that stresses the CPU with massive OpenMP parallel math and the GPU with video encoding.
*    **Full Automation**: No need to remember complex FFmpeg flags — just run the app, choose a location, and get a professional video file.
	
## Yes, this is FFmpeg-the 'Swiss Army knife' of video processing. 

In 2026, it remains the industry standard, 
powered by an open-source community. From YouTube and Netflix to professional movie studios, 
everyone relies on it. And yes, it's completely free.

## All-in-one: 

This repository already includes ffmpeg binaries for Windows and Linux. No manual installation is required!

## OpenMP

OpenMP is a standard that tells the compiler, "Take this loop and distribute the iterations among the different processor cores."
Yes, using OpenMP you are doing parallel programming at the Multithreading level.
Everything is powered by **OpenMP** parallel loops for maximum performance.
OpenMP - Scalability: Your code will run equally efficiently on a 4-core laptop and a 128-core server.

## 8x8 Supersampling (64 Samples Per Pixel)

Super-Sampling Anti-Aliasing (SSAA) is a high-end technique increasing samples per pixel to enhance image quality, 
with 8x (N=8) rendering scenes at 8x resolution on both axes to produce 64 samples per pixel. 
This process calculates an extreme number of pixels-scaling to a 15360 x 8640 grid for a 1920 x 1080
target-before downscaling to remove jaggies and improve detail.

I decided to take the visual quality to a completely different level. This engine implements
True 8x8 Supersampling Anti-Aliasing (SSAA) with 64 independent samples per single screen pixel, utilizing Direct RGB-Space Integration.
Instead of a standard 1920x1080 render, the engine internally processes a massive 15,360 x 8,640 sub-pixel grid!
After calculating all 64 samples for a pixel, they are downsampled into one.
Key Technical Advantages:
*    64-Point Fractal Sampling: Each final screen pixel is computed from sixty-four independent fractal coordinate points.
*    High-Precision Per-Channel RGB Accumulation: The engine first calculates the specific 24-bit color for every single sub-pixel before performing any blending.
*    Noise Elimination: By accumulating color intensities (R, G, B) rather than raw iteration counts, we completely eliminate "chromatic noise." The result is a crystal-clear, razor-sharp image where every micro-filament is perfectly reconstructed.
*    True Color Integration: Our solution performs integration directly in the RGB color space. By computing the exact Red, Green, and Blue components for each sub-pixel before downsampling, we achieve a cinematic level of smoothness and structural integrity that 8-bit or iteration-based renderers simply cannot match.

## Generating 255 Frames: Optimization Strategy

This is an efficient pre-render strategy: we calculate the heavy mathematics (iteration counts) 
once, store the raw data, and then rapidly generate frames by shifting colors and downsampling.
Since calculating a 15360x8640 fractal 255 times is computationally expensive, we split the task into two stages.

### Stage 1: Iteration Map Generation (Raw Data)

Instead of BMP files, we create a single data buffer where we store only the iteration number (t) for each pixel.
*    For 15360x8640 using uint8_t, the resulting file/buffer is approximately 132 MB.

### Stage 2: 255-Frame Rendering (Color + Anti-aliasing)

We read the iteration map and perform the following for each frame:
*    Downsample: Process an 8x8 pixel block from the high-res map.
*    Color Mapping: Map each pixel value to a shifted color palette.
*    Smoothing: Average the colors (Supersampling Anti-Aliasing) to produce a final 1920x1080 frame.

### Why is this so fast?
*    Memory Efficiency: The iterMap array (~132 MB) easily fits into modern RAM. The heavy do-while calculation loop runs only once for the entire animation.
*    Palette Rotation: Stage 2 avoids long double arithmetic and squaring. It only involves integer addition and memory lookups.
*    Parallelism: Stage 2 is perfectly scalable. All 255 frames can be rendered simultaneously across CPU cores.
*    True Downsampling: We implement honest 8x8 averaging, resulting in superior image quality compared to simple resizing.
Once all 255 BMP files are generated, use FFmpeg to encode them into the final video.


## Visual Aesthetics

The Red, Green, and Blue channels are calculated using sine and cosine waves to create smooth color transitions:
```C++
        pal[a][0] = (uint8_t)round(127.0 + 127.0 * cos(2.0 * PI * a / 255.0)); // Blue
        pal[a][1] = (uint8_t)round(127.0 + 127.0 * sin(2.0 * PI * a / 255.0)); // Green
        pal[a][2] = (uint8_t)round(127.0 + 127.0 * sin(2.0 * PI * a / 255.0)); // Red
```

## License and Third-Party Software

### My Code

This project is licensed under the **MIT License**.

### FFmpeg

This software uses libraries from the **FFmpeg** project under the **LGPLv2.1** (or GPLv3, depending on the build). 
*   FFmpeg is a trademark of Fabrice Bellard, originator of the FFmpeg project.
*   You can find the source code and more information at [https://ffmpeg.org](https://ffmpeg.org).
*   The FFmpeg binaries included in the releases are provided as-is, and no modifications have been made to the FFmpeg source code.


## The Mandelbrot Set: A Mathematical Absolute

It is truly one of the few objects that connects us to something absolutely objective and infinite, 
transcending biology and history. Even if our entire universe and all its atoms were to vanish tomorrow, 
the equation would remain true. It is not "written" on the stars; it is embedded in the structure of logic itself. 
This makes the Mandelbrot Set a kind of absolute.

Mathematics does not depend on biology, having legs, or the level of technology. Inhabitants of the Andromeda galaxy and 
sentient oceans in another supergalaxy will see the exact same Mandelbrot set. 

The Mandelbrot set exists independently of our minds and technology. It is an infinite mathematical structure that 
has always existed. Computers do not create it; they merely act as a camera.


## Controls & Automation (CLI)

The program operates on a "one-click" principle: you select the location, and the rest (calculation, encoding, cleanup) happens automatically.

| Action | Input | Description |
| :--- | :--- | :--- |
| **Presets** | `1` - `6` + `ENTER` | Choose one of the 6 built-in deep-zoom cinematic locations. |
| **Custom Point** | `7` + `ENTER` | Load custom coordinates (`absc`, `ordi`, `size`) from `Mandelbrot.txt`. |
| **Rendering** | **Step 1 (Auto)** | High-precision calculation of 255 frames using **OpenMP** and **SSAA 8x8**. |
| **Encoding** | **FFmpeg** | **Portable Mode**: The app automatically detects `ffmpeg` in the local folder. Automatic frame-to-MP4 compilation (30 FPS). |
| **Cleanup** | **Auto** | Automatic deletion of temporary BMP files after the video is finished. |


```C++
        case 1: absc_str = "-1.7491976289657893741942376816272921165326158557416159"; ordi_str = "-0.00000042530777152440422725855012159249401150956515248"; size_str = "0.0000000000000000000000000000000000000000000000000043"; break;
        case 2: absc_str = "-1.7490781615052017316791245451566330412"; ordi_str = "0.0000055099190662909660251309856720635"; size_str = "0.000000000000000000000000000000000215"; break;
        case 3: absc_str = "-1.748943661768663337207355215321150725806353337382441467976"; ordi_str = "-0.0000073748967541889836640985849393311615399776865199722998"; size_str = "0.0000000000000000000000000000000000000000000000000000001"; break;
        case 4: absc_str = "-1.7489740586384718864866264297253934254"; ordi_str = "-0.0002265965897111407857153825623868331"; size_str = "0.00000000000000000000000000000000007"; break;
        case 5: absc_str = "-1.7499458649755745940752606707005571"; ordi_str = "-0.0000000852088539604644334731909824511"; size_str = "0.00000000000000000000000000000000001"; break;
        case 6: absc_str = "-1.267078059171397835210199054200436920994876769284288837862647"; ordi_str = "-0.123788215196292957558264285607075473360968832625384429809391"; size_str = "0.0000000000000000000000000000000000000000000000000000000023"; break;
```

## Mandelbrot.txt File Structure

To load custom coordinates (option 7 in the menu), create a Mandelbrot.txt file in the application folder. 
The file must contain three numbers separated by a newline:
*    Abscissa (Center X coordinate)
*    Ordinate (Center Y coordinate)
*    Size (Zoom level/Area size)

Example file content:

![Mandelbrot txt](Mandelbrot.png)

## Look at the results! The smoothness is incredible 

https://github.com/user-attachments/assets/852adaf6-5921-486d-b7cb-6d3e326302a8

https://github.com/user-attachments/assets/01edb228-9685-4f66-ba3b-a5492d3d3045

https://github.com/user-attachments/assets/2dbb60b2-5be4-4bb6-be1c-3f4f1d3cef77

https://github.com/user-attachments/assets/66c067b8-1237-48cb-905f-b7049e8a0677

https://github.com/user-attachments/assets/2c90c6d0-2889-43a8-9d02-60ca35922cd5

https://github.com/user-attachments/assets/d4d28260-9c7f-4ba7-8ce9-9f04c07ee58c


**[Download Latest Version (Windows & Linux)](https://github.com/Divetoxx/Mandelbrot-Video/releases)**


# 🇷🇺 Русская версия
<a name="russian"></a>

# Консольный рендерер Мандельброта с методом возмущений и предела $10^{-308}$

## Благодарности (Credits)

Этот проект использует передовые математические алгоритмы и идеи динамического управления фазой орбит, 
разработанные фрактальным сообществом. Особая благодарность авторам и исследователям с Fractal Forums, 
чей совместный труд лег в основу этого движка:
* **Kevin Martin** - автор фундаментальных методов векторизации и оптимизации циклов возмущений.
* **Zhuoran Yu** - разработчик концепции динамического сброса орбит.
* **Claude Heiland-Allen** - исследователь экстремального фрактального приближения и создатель проекта MDZ.

## Ключевые особенности:

* Расчёт опорной траектории на 5000 бит всего один раз.
* Реактивный расчёт миллиарда пикселей на аппаратном double.
* При использовании чисел с плавающей запятой двойной точности (порядка $10^{-15}$) теория возмущений позволяет приблизиться к уровню **$10^{-308}$ - не дальше.**
* Революционный алгоритм Reference Reset to Zero.
* Настоящий SSAA 8x8 для идеально сглаженного изображения без алиасинга.
* Параллелизм OpenMP для высокоскоростного многопоточного рендеринга.
* Да, это FFmpeg - "швейцарский армейский нож" для обработки видео.

## Безграничная точность (Arbitrary Precision Arithmetic)

Движок полностью избавлен от аппаратных ограничений 64-битных (`double`) и 128-битных (`__float128`) чисел, которые неизбежно слепнут и выдают 
пиксельные квадраты на глубинах более $10^{-15}$ и $10^{-34}$.
* **Интеграция MPFR/GMP**: Вся высокоточная навигация, пересчёт масштаба при кликах мыши и движении стрелочками клавиатуры ведутся 
внутри сверхглубокой бинарной памяти с точностью **5000 бит**!
* **308 десятичных знаков в текстовом кэше (Hardware Double Wall)**: 
Координаты кадра сохраняются и считываются из файла `Mandelbrot.txt`. Навигация и радар MPFR работают на глубине до 5000 бит, 
однако скоростной пиксельный дельта-движок ограничен аппаратной экспонентой `double`, что позволяет исследовать безупречно четкие 
структуры на запредельных масштабах **вплоть до $10^{-308}$ знаков**.


## Реактивный метод возмущений (Perturbation Theory)

Рендеринг глубоких фракталов больше не требует тяжелых вычислений <в столбик> для каждого пикселя, что обычно замедляло программы в тысячи раз.
* **Однократный расчёт опоры**: Сверхтяжелый BigFloat-радар MPFR вычисляет точную траекторию всего для **одной-единственной центральной точки 
кадра и строго ОДИН раз** в начале рендеринга.
* **Аппаратное ускорение на double**: Весь остальной массив экрана (миллиарда супер-пикселей) рассчитывается параллельно на бешеной скорости 
чистых, аппаратных регистров `double` процессора, вычисляя лишь микроскопические отклонения (дельты) от центральной оси. 
Скорость генерации взлетела в 1000 раз!

## Революционный алгоритм Reference Reset to Zero

Это огромный повод для гордости. Ваша программа теперь работает по тем же математическим принципам, что и самые передовые фрактальные движки в мире.
* **Динамический сброс на ноль**: Теперь пиксель на каждом шаге проверяет соотношение своих полных координат и дельты. Если дельта становится 
слишком большой или кэш центра иссякает, поток прямо на лету **сбрасывает индекс чтения на ноль**, превращая накопленные координаты 
в новую автономную точку.
* **Хакерская оптимизация цикла (One-Step Beyond Escape)**: Чтобы выжать максимум скорости из процессора, радар MPFR записывает 
строго **одну дополнительную точку** в массив опорной орбиты сразу после того, как она превышает радиус ухода. 
* **Уничтожение ветвлений (Branch Unrolling)**: Этот изящный трюк позволил полностью избавиться от громоздких `if` и `OR`-условий 
внутри самого глубокого цикла итераций. Процессор больше не тратит такты на предсказание переходов, а компилятор смог идеально векторизовать 
код.


## О проекте

Это консольная станция для автоматизированного создания профессионального видео-арта на основе множества Мандельброта. 
Программа берет на себя весь цикл производства: от тяжелых математических вычислений до финальной сборки готового видеофайла.

### Что делает эта программа:
*    **Полный цикл видеопроизводства**: Программа рассчитывает 255 кадров фрактала, применяет эффект плавной ротации палитры и автоматически 
вызывает FFmpeg для сборки видео в формате .mp4.
*    **Интеллектуальный рендеринг**: Программа сама определяет наличие видеокарты NVIDIA.
     - Если есть GPU — используется аппаратное ускорение h264_nvenc для мгновенного сжатия.
     - Если видеокарта не найдена — используется профессиональный CPU-кодировщик libx264 с глубокой оптимизацией.
*    **Кинематографическое качество (Full HD 1080p)**: Каждое видео создается с использованием SSAA 8x8. Это значит, что для каждого 
кадра выполняется в 64 раза больше вычислений, чем обычно, чтобы полностью исключить мерцание и шум в видео.
*    **Автоматическая очистка**: После успешной сборки видео программа сама удаляет промежуточные BMP-файлы (которые могут 
занимать гигабайты), оставляя вам только готовый результат Mandelbrot.mp4.

## Для чего это нужно:
*    **Генерация контента**: Создание идеальных зацикленных (loop) фонов для медитации, VJ-сетов или YouTube-каналов.
*    **Демонстрация мощи железа**: Проект сочетает интенсивные вычисления на CPU (OpenMP) и скоростное кодирование на GPU.
*    **Удобство**: Вам не нужно знать команды командной строки FFmpeg — программа всё сделает за вас. 

## Да, это FFmpeg - "швейцарский армейский нож" для обработки видео.

В 2026 году он остается отраслевым стандартом, 
поддерживаемым сообществом разработчиков открытого программного обеспечения. 
От YouTube и Netflix до профессиональных киностудий - все на него полагаются. И да, он совершенно бесплатный.

## Всё включено: 

Этот репозиторий уже содержит исполняемые файлы ffmpeg для Windows и Linux. Никакой ручной установки не требуется - всё работает прямо <из коробки>!


## OpenMP

OpenMP - это стандарт, который говорит компилятору: "Возьми этот цикл и сам раздай итерации разным ядрам процессора".
Используя OpenMP, вы занимаетесь параллельным программированием на уровне многопоточности (Multithreading).
OpenMP - масштабируемость: ваш код будет одинаково эффективно работать как на 4-ядерном ноутбуке,
так и на 128-ядерном сервере.


## Суперсэмплинг 8x8 (64 прохода на один пиксель)

Суперсэмплинг (SSAA) - ресурсоемкий метод сглаживания, увеличивающий число выборок на пиксель для повышения качества изображения. 
При значении 8x (N=8) сцена рендерится в разрешении, в 8 раз превышающем целевое, по обеим осям, создавая 64 (или 8 х 8) выборки 
на пиксель. Изображение просчитывается в более высоком разрешении, а затем принудительно уменьшается до разрешения дисплея, 
устраняя лесенки и улучшая чёткость. Это очень высокая нагрузка! Это не 1920 на 1080 пикселя а в 8x8 больше - 15360 на 8640 пикселя!

Я решил вывести качество изображения на совершенно новый уровень. Этот движок использует
истинное сглаживание 8x8 Supersampling Anti-Aliasing (SSAA) с 64 независимыми сэмплами на каждый пиксель экрана, используя прямую интеграцию в RGB-пространство.
Вместо стандартного рендеринга 1920x1080, движок обрабатывает внутри себя огромную сетку из 15360 x 8640 субпикселей!

После вычисления всех 64 сэмплов для пикселя, они уменьшаются до одного.
Ключевые технические преимущества:
*   64-точечное фрактальное сэмплирование: каждый конечный пиксель экрана вычисляется из шестидесяти четырех независимых 
фрактальных координатных точек.
*   Высокоточное накопление RGB-цвета по каналам: движок сначала вычисляет конкретный 24-битный цвет для каждого субпикселя, 
прежде чем выполнять какое-либо смешивание.
*   Устранение шума: Накапливая интенсивность цвета (R, G, B), а не просто подсчитывая количество итераций, мы полностью 
устраняем <хроматический шум>. В результате получается кристально чистое, резкое изображение, где каждая микронить идеально воссоздана.
*   Интеграция истинного цвета: Наше решение выполняет интеграцию непосредственно в цветовом пространстве RGB. 
Вычисляя точные компоненты красного, зеленого и синего цветов для каждого субпикселя перед понижением разрешения, 
мы достигаем кинематографического уровня плавности и структурной целостности, недостижимого для 8-битных или итерационных рендеров.


## Генерация 255 кадров

Это отличная стратегия оптимизации! Вы хотите применить пререндер: сначала рассчитать тяжелую математику (номера итераций) один раз, сохранить их, а затем быстро генерировать кадры, просто меняя цвета и уменьшая размер.
Поскольку считать 15360x8640 255 раз - это безумие, мы разделим задачу на два этапа.

### Этап 1: Генерация <карты итераций> (Raw Data)
Вместо BMP мы создадим один огромный файл, где для каждого пикселя запишем только число t (номер итерации). 
Для 15360x8640 при использовании uint8_t файл займет около 132 МБ.

### Этап 2: Генерация 255 кадров (Цвет + Сглаживание)
Теперь мы читаем эту карту и для каждого кадра делаем:
Берем блок 8x8 пикселей из большой карты.
Красим каждый пиксель согласно сдвинутой палитре.
Усредняем цвета (это и есть сглаживание) и записываем в файл 1920x1080.

### Почему это сработает быстро?
*    **Память**: Массив iterMap занимает около 132 МБ. Это легко помещается в современную оперативную память. Тяжелый цикл do-while выполняется только один раз для всей анимации.
*    **Вращение палитры**: В этапе 2 нет long double, нет возведения в квадрат. Только сложение целых чисел и чтение из памяти.
*    **Параллелизм**: Этап 2 тоже идеально распараллеливается. 255 кадров будут вылетать очень быстро. Реализован честный Downsampling. Мы берем блок 8x8 и усредняем их. 
Когда у вас будет 255 файлов bmp, используйте ffmpeg, чтобы собрать их в видео.


## Визуальная эстетика

Красный, зеленый и синий каналы рассчитываются с использованием синусоидальных и косинусоидальных волн для создания плавных цветовых переходов:
```C++
        pal[a][0] = (uint8_t)round(127.0 + 127.0 * cos(2.0 * PI * a / 255.0)); // Blue
        pal[a][1] = (uint8_t)round(127.0 + 127.0 * sin(2.0 * PI * a / 255.0)); // Green
        pal[a][2] = (uint8_t)round(127.0 + 127.0 * sin(2.0 * PI * a / 255.0)); // Red
```

## Лицензия и стороннее программное обеспечение

### Мой код

Этот проект распространяется под лицензией **MIT**.

### FFmpeg

Это программное обеспечение использует библиотеки из проекта **FFmpeg** под лицензией **LGPLv2.1** (или GPLv3, в зависимости от сборки).
* FFmpeg является товарным знаком Фабриса Беллара, создателя проекта FFmpeg.
* Исходный код и дополнительную информацию можно найти по адресу [https://ffmpeg.org](https://ffmpeg.org).
* Бинарные файлы FFmpeg, включенные в релизы, предоставляются как есть, и в исходный код FFmpeg не вносились никакие изменения.


## Множество Мандельброта: Математический абсолют

Это поистине один из немногих объектов, который связывает нас с чем-то абсолютно объективным и бесконечным,
превосходящим биологию и историю. Даже если бы вся наша Вселенная и все её атомы исчезли завтра,
уравнение осталось бы верным. Оно не <написано> на звёздах; оно заложено в самой структуре логики.
Это делает множество Мандельброта своего рода абсолютом.

Математика не зависит от биологии, наличия ног или уровня технологий. Жители галактики Андромеда и разумные океаны 
в другой супергалактике увидят абсолютно то же самое множество Мандельброта. 

Множество Мандельброта существует независимо от нашего разума и технологий. 
Это бесконечная математическая структура, которая существовала всегда. Компьютеры не создают её; они лишь 
выступают в роли камеры.

## Управление и автоматизация (CLI & Automation)

Программа работает по принципу <одной кнопки>: вы выбираете локацию, а остальное (расчет, кодирование, очистка) происходит автоматически.

| Действие | Ввод | Описание |
| :--- | :--- | :--- |
| **Выбор локации** | `1` - `6` + `ENTER` | Выбор одной из 6 встроенных точек мандельброта - глубокого зума. |
| **Свои координаты** | `7` + `ENTER` | Загрузка координат (`absc`, `ordi`, `size`) из файла `Mandelbrot.txt`. |
| **Рендеринг (Авто)** | **Шаг 1** | Расчет 255 кадров с использованием **OpenMP** и **SSAA 8x8**. |
| **Сборка (Авто)** | **FFmpeg** | **Portable Mode**: Программа сама найдет `ffmpeg` в своей папке. Автоматическое кодирование в MP4 (30 FPS). |
| **Очистка** | **Авто** | Удаление временных кадров после успешного создания видео. |


```C++
        case 1: absc_str = "-1.7491976289657893741942376816272921165326158557416159"; ordi_str = "-0.00000042530777152440422725855012159249401150956515248"; size_str = "0.0000000000000000000000000000000000000000000000000043"; break;
        case 2: absc_str = "-1.7490781615052017316791245451566330412"; ordi_str = "0.0000055099190662909660251309856720635"; size_str = "0.000000000000000000000000000000000215"; break;
        case 3: absc_str = "-1.748943661768663337207355215321150725806353337382441467976"; ordi_str = "-0.0000073748967541889836640985849393311615399776865199722998"; size_str = "0.0000000000000000000000000000000000000000000000000000001"; break;
        case 4: absc_str = "-1.7489740586384718864866264297253934254"; ordi_str = "-0.0002265965897111407857153825623868331"; size_str = "0.00000000000000000000000000000000007"; break;
        case 5: absc_str = "-1.7499458649755745940752606707005571"; ordi_str = "-0.0000000852088539604644334731909824511"; size_str = "0.00000000000000000000000000000000001"; break;
        case 6: absc_str = "-1.267078059171397835210199054200436920994876769284288837862647"; ordi_str = "-0.123788215196292957558264285607075473360968832625384429809391"; size_str = "0.0000000000000000000000000000000000000000000000000000000023"; break;
```

## Структура файла Mandelbrot.txt

Для загрузки пользовательских координат (пункт 7 в меню), создайте текстовый файл Mandelbrot.txt в папке с программой. 
Файл должен содержать три числа, разделенных переносом строки:
*    Abscissa (Координата X центра)
*    Ordinate (Координата Y центра)
*    Size (Масштаб/Размер области)

Пример содержания файла:

![Mandelbrot txt](Mandelbrot.png)


## Посмотрите на результаты! Невероятная плавность работы

https://github.com/user-attachments/assets/852adaf6-5921-486d-b7cb-6d3e326302a8

https://github.com/user-attachments/assets/01edb228-9685-4f66-ba3b-a5492d3d3045

https://github.com/user-attachments/assets/2dbb60b2-5be4-4bb6-be1c-3f4f1d3cef77

https://github.com/user-attachments/assets/66c067b8-1237-48cb-905f-b7049e8a0677

https://github.com/user-attachments/assets/2c90c6d0-2889-43a8-9d02-60ca35922cd5

https://github.com/user-attachments/assets/d4d28260-9c7f-4ba7-8ce9-9f04c07ee58c



**[Скачать последнюю версию (Windows и Linux)](https://github.com/Divetoxx/Mandelbrot-Video/releases)**



