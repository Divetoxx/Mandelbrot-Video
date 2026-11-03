[![Language](https://img.shields.io/badge/Language-English-blue)](#english)
[![Язык](https://img.shields.io/badge/Язык-Русский-red)](#russian)

[![Download Windows](https://img.shields.io/badge/Download-Windows-brightgreen?logo=windows)](https://github.com/Divetoxx/Mandelbrot-Video/releases/latest/download/Mandelbrot_windows_x64.zip )
[![Download Linux](https://img.shields.io/badge/Download-Linux-orange?logo=linux)](https://github.com/Divetoxx/Mandelbrot-Video/releases/latest/download/Mandelbrot_linux_x64.tar.gz)
[![Source Code](https://img.shields.io/badge/Source_Code-ZIP-orange?logo=github)](https://github.com/Divetoxx/Mandelbrot-Video/archive/refs/heads/main.zip)
[![Source Code](https://img.shields.io/badge/Source_Code-TAR.GZ-lightgrey?logo=github)](https://github.com/Divetoxx/Mandelbrot-Video/archive/refs/heads/main.tar.gz)


<a name="english"></a>
# 🇺🇸 English Version

# Mandelbrot VIDEO

## Preview fragment of the Mandelbrot set video, length 10 seconds (full video is 2 minutes), 1,080 x 1,080 pixels.

```C++
const char * CENTER_RE = "-1.74919762896578937419423768162729211653261585574161734756645570271259437106847945278504682550816934045282325615313706071032";
const char * CENTER_IM = "0.00000042530777152440422725855012159249401150956515141283650516485787465219754670517629100020435541143321258687777670349987";
const int TOTAL_FRAMES = 3600; 
const char* START_VIEW_STR = "1.02e-99";
const char* END_VIEW_STR   = "1.02e-119";
```


## About the Project

**Mandelbrot VIDEO** is a high-tech, production-grade CLI workstation built for the automated generation 
of cinematic fractal video art. Instead of basic color cycle loops, this engine computes a truly captivating, 
**deep fractal zoom** using perfect logarithmic step scaling. The program fully automates the entire production 
pipeline—from highly complex, multi-threaded arbitrary-precision math down to frame preparation and subsequent encoding.

## Core Features:

* **Massive Fractal Journey**: The engine handles large-scale rendering sequences (up to 3600 frames), calculating an ultra-deep 
exponential zoom with 1000-bit precision to deliver a stunning effect of infinite immersion.
* **Dynamic Color Shifts**: A smooth, cyclic palette rotation (`frame % 255`) is applied to every single zoom step, creating 
a hypnotic, pulsing "live" fractal illusion.
* **Intelligent Rendering & Encoding Pipeline**: The utility automatically scans the system for NVIDIA CUDA cores.
  * *If a GPU is detected*: Hardware acceleration via `h264_nvenc` is engaged for blazing-fast, "on-the-fly" video encoding.
  * *If no GPU is found*: It gracefully falls back to the industry-standard CPU encoder `libx264`, backed by deep multi-threaded optimization.
* **Cinematic Quality (SSAA 3x3)**: Each scene is rendered using a true 3x3 Super-Sampling Anti-Aliasing (SSAA) grid. This 
means 9 times more calculations are executed per frame to completely eliminate digital flickering and aliasing noise 
along the ultra-fine fractal filaments.
* **Frame Archive Preservation**: The engine retains the entire sequence of raw frames in uncompressed BMP format, 
giving you the freedom to manage your image archive manually or re-encode the video at any time without re-running 
the heavy mathematical calculations.

## Use Cases & Benefits:

* **Professional Content Creation**: Generate highly engaging, seamless, high-resolution video loops perfectly suited for 
meditation videos, VJ sets, live wallpapers, or educational sci-pop content on YouTube.
* **Extreme Stress Testing & Benchmarking**: A perfect hybrid workload to verify PC stability. The program pushes the 
CPU to 100% load during the BLA perturbation matrix math, while simultaneously saturating the GPU with hardware video 
encoding blocks.
* **Complete Media Data Control**: You receive not just a compiled video file, but an entire high-definition library 
of uncompressed source frames, fully ready for further creative experiments, upscaling, or custom post-processing.

## Preview fragment of the Mandelbrot set video, length 10 seconds (full video is 1 minutes), 1,080 x 1,080 pixels.

```C++
const char * CENTER_RE = "-0.8432337645307515133246117300038447886638913178942914768815245";
const char * CENTER_IM = "0.2238180415580699591398982954803114403955748218705388777865576";
const int TOTAL_FRAMES = 1800; 
const char* START_VIEW_STR = "1.29e-49";
const char* END_VIEW_STR   = "1.29e-57";
```


## Credits & Acknowledgments

This project implements advanced orbit phase management paradigms and perturbation algorithms developed 
by the fractal research community. Special thanks to the following authors and pioneers from the Fractal Forums, 
whose collaborative work made this engine possible:

* **Kevin Martin** — for pioneering loop optimization and edge-case escape techniques.
* **Zhuoran Yu** — for developing the dynamic reference relocalization and orbit re-basing paradigm.
* **James Ward Martin (JWM)** — for the creation of the pioneering MDZ (Mandelbrot Deep Zoom) project utilizing MPFR/GMP libraries.
* **Claude Heiland-Allen** — for extensive deep zoom mathematical research, preservation of fractal software legacy, 
and advanced palette conversion algorithms.



## Key Features:

* **High-Precision Reference Orbit**: The core reference trajectory is computed with 1000-bit precision exactly once per 
zoom layer using the industry-standard GNU MPFR library.
* **Hardware-Accelerated Perturbation Math**: Blazing-fast delta calculations for millions of pixels utilizing the native 
double-precision hardware registers of the CPU.
* **Perturbation Boundaries**: While native double-precision floats are normally limited to depths around $10^{-15}$, 
this perturbation-driven engine safely pushes the boundary down to $10^{-308}$ before requiring a new reference point.
* **Dynamic Orbit Re-basing**: Automatic relocation and re-centering of the reference orbit to prevent breakdown and 
maintain accuracy during extreme zoom phases.
* **Bivariate Linear Approximation (BLA Skip-100)**: Significantly cuts down rendering times by mathematically "jumping 
over" 100 iterations at once across smooth regions of the fractal.
* **True Super-Sampling 3x3 SSAA (Direct RGB Integration)**: Immaculate, anti-aliased image quality featuring 9 independent 
sub-pixel samples per pixel. Downsampling blends directly in the RGB color space, completely eliminating chromatic noise 
and shimmering artifacts.
* **Pure C++11 Multi-threading**: Native, high-speed parallel computation built entirely on standard language primitives, 
scaling seamlessly across all modern CPU core architectures.
* **Built-in FFmpeg Pipeline**: Directly interfaces with FFmpeg—the "Swiss Army knife" of video processing—to encode frames 
on the fly without extra scripts.


## Фрагмент видеоролика о множестве Мандельброта, длительность 10 секунд (полное видео - 1 минута), разрешение 1080 x 1080 пикселей.

```C++
const char * CENTER_RE = "-0.12702288604303376058504940552835636145639339878096842408417373730140553";
const char * CENTER_IM = "0.98728474138900681012772182210671973643707041031463043446236865072311861";
const int TOTAL_FRAMES = 1800; 
const char* START_VIEW_STR = "4.95e-61";
const char* END_VIEW_STR   = "4.95e-69";
```

## Arbitrary Precision Arithmetic (Infinite Depth)

The engine is completely free from the hardware limitations of standard data types—such as the native 64-bit (`double`) 
and the extended 80-bit (`long double`) floats—which inevitably lose significance and produce pixelated 
blocks at precision depths beyond $10^{-15}$ and $10^{-19}$ respectively.

* **MPFR/GMP Integration:** All high-precision coordinate navigation, mouse-click viewport targeting, and grid step 
calculations are handled within an isolated binary memory structure configured to a pristine **1000-bit precision**.
* **308-Digit Decimal Silicon Barrier:** The dynamic exponent range of the hardware-native `double` register limits 
the high-speed delta pixel engine to a maximum theoretical depth of **$10^{-308}$ digits**. Current viewport coordinates 
are safely stored and retrieved via the `Mandelbrot.txt` configuration file, guaranteeing flawless structural clarity 
of mathematical micro-filaments right up to this physical silicon boundary.



## High-Speed Perturbation Theory

Rendering extreme close-ups no longer requires arbitrary-precision arithmetic for each individual pixel.

* **High-Precision Reference Orbit:** MPFR BigFloat computes the exact trajectory for **one central pixel once** per frame.
* **Hardware-Accelerated Computation:** The rest of the screen is processed via hardware `double` registers by 
calculating relative deviations (deltas), accelerating frame generation up to 1000x.


## Dynamic Reference Relocalization (Orbit Re-basing)

This is a tremendous point of pride: the engine operates under the exact same mathematical and architectural principles 
as the world's most advanced Mandelbrot renderers.
*   **Dynamic Reset to Zero**: At every step, each pixel monitors the ratio of its absolute coordinates against its current delta. 
If the delta drifts too far or the primary reference orbit terminates, the execution thread dynamically 
**resets its tracking index to zero**, establishing the accumulated coordinates as a new autonomous origin 
and eliminating precision artifacts.
*   **One-Step Beyond Escape Loop Optimization**: To squeeze maximum performance out of the CPU, the MPFR reference 
tracker records exactly **one additional point** into the orbit array immediately after exceeding the escape radius. 
This precise boundary definition guarantees flawless orbit re-basing.
*   **Deep Loop Branch Optimization**: This elegant layout significantly streamlines conditions within the deepest 
iteration loop. By minimizing heavy branching and avoiding complex nested conditions where possible, the code improves 
branch prediction efficiency and allows the CPU pipeline to execute the core mathematics with maximum throughput.


## Bilinear Approximation

The rendering engine achieves a massive performance leap by integrating the Bilinear Approximation 
method (**BLA Skip-100**).

* **Coefficient Matrix Precomputation:** The algorithm precomputes the transformation matrices for intervals of exactly 
100 iterations.
* **Massive Iteration Skipping:** If the current deviation (delta) point lies safely within the computed radius 
of convergence relative to the reference orbit, the execution thread skips 100 iterations at once in a single mathematical 
step. This drastically minimizes CPU clock cycles and delivers an exponential speedup across the smooth, 
uniform filaments of the Mandelbrot set.


## Pure C++11 Multi-threading

High-speed parallel computing built directly into the language standard. Scales transparently across architectures-delivering 
flawless 100% CPU utilization whether running on a 4-core laptop or a 128-core high-performance server without external dependencies.


## True 3x3 SSAA: 9-Sample Direct RGB Integration Space

To take visual quality to a completely level, the engine implements **True 3x3 Super-Sampling Anti-Aliasing (SSAA)**, 
processing **9 independent sub-pixel fractal coordinates** per single final screen pixel to completely eliminate aliasing along 
the Mandelbrot set's complex boundaries.

### Mathematical Fallacy of the Standard Approach
Traditional rendering methods incorrectly average raw iteration counts or palette indices before applying color:
* **Standard Way:** `Color( (iter_1 + iter_2 + ... + iter_9) / 9 )`

Because fractal color palettes are strictly non-linear, calculating the arithmetic mean of iteration indices yields an 
unrelated color, resulting in jarring chromatic contours, pixelated artifacts, and high-contrast digital noise.

### Engineering Solution: 9-Point Optical RGB Integration
Instead of averaging raw algorithm steps, our engine computes the exact 24-bit/32-bit color for every single one 
of the 9 sub-pixels independently before any blending occurs. It then performs high-precision, per-channel accumulation 
of their color intensities:
* **Direct RGB Integration Algorithm:** `(Color(iter_1) + Color(iter_2) + ... + Color(iter_9)) / 9`

### Key Technical Advantages:
* **9-Point Fractal Sampling:** Every final screen pixel is reconstructed from sixty-four independent fractal coordinate 
points, capturing sub-pixel microstructures smaller than a physical monitor pixel.
* **Complete Noise Elimination:** By accumulating independent Red, Green, and Blue intensities prior to downsampling rather 
than raw iteration values, we completely eradicate "chromatic noise."
* **Cinematic Structural Integrity:** Performing integration directly in the RGB color space ensures a true optical blend. This delivers 
an ultra-smooth, continuous gradient and pristine image quality that standard 8-bit or index-based renderers simply cannot match.


## Yes, this is FFmpeg-the 'Swiss Army knife' of video processing. 

In 2026, it remains the industry standard, 
powered by an open-source community. From YouTube and Netflix to professional movie studios, 
everyone relies on it. And yes, it's completely free.

## All-in-one: 

This repository already includes ffmpeg binaries for Windows and Linux. No manual installation is required!


## License and Third-Party Software

### My Code

This project is licensed under the **MIT License**.

### FFmpeg

This software uses libraries from the **FFmpeg** project under the **LGPLv2.1** (or GPLv3, depending on the build). 
*   FFmpeg is a trademark of Fabrice Bellard, originator of the FFmpeg project.
*   You can find the source code and more information at [https://ffmpeg.org](https://ffmpeg.org).
*   The FFmpeg binaries included in the releases are provided as-is, and no modifications have been made to the FFmpeg source code.





**[Download Latest Version (Windows & Linux)](https://github.com/Divetoxx/Mandelbrot-Video/releases)**




# 🇷🇺 Русская версия
<a name="russian"></a>

# Мандельброт ВИДЕО

## Фрагмент видеоролика о множестве Мандельброта, длительность 10 секунд (полное видео - 2 минуты), разрешение 1080 x 1080 пикселей.

```C++
const char * CENTER_RE = "-1.74919762896578937419423768162729211653261585574161734756645570271259437106847945278504682550816934045282325615313706071032";
const char * CENTER_IM = "0.00000042530777152440422725855012159249401150956515141283650516485787465219754670517629100020435541143321258687777670349987";
const int TOTAL_FRAMES = 3600; 
const char* START_VIEW_STR = "1.02e-99";
const char* END_VIEW_STR   = "1.02e-119";
```



## О проекте

**Мандельброт ВИДЕО** — это высокотехнологичная CLI-станция промышленного уровня, созданная для автоматизированной 
генерации кинематографического видео-арта. Данный движок рассчитывает полноценное, захватывающее **глубокое погружение во фрактал** 
с идеальной логарифмической плавностью шага. Программа полностью берёт на себя весь цикл производства — 
от сложнейших многопоточных вычислений длинной арифметики до подготовки кадров и последующего кодирования.

## Что делает эта программа:

* **Масштабное фрактальное путешествие**: Движок рассчитывает масштабные последовательности (до 3600 кадров), 
вычисляя сверхглубокий экспоненциальный зум с точностью 1000 бит, обеспечивая потрясающий эффект бесконечного погружения.
* **Динамическое переливание цвета**: На каждый шаг приближения накладывается плавное циклическое смещение палитры (`frame % 255`), 
что создаёт гипнотический эффект «живого», пульсирующего фрактала.
* **Интеллектуальный рендеринг**: Утилита автоматически сканирует систему на наличие ядер NVIDIA.
  * *Если найден GPU*: для мгновенного сжатия видео «на лету» активируется аппаратное ускорение `h264_nvenc`.
  * *Если GPU нет*: запускается профессиональный процессорный кодировщик `libx264` с глубокой многопоточной оптимизацией.
* **Кинематографическое качество (SSAA 3x3)**: Каждая сцена рендерится с честным сглаживанием SSAA 3x3. Это значит, 
что для каждого кадра выполняется в 9 раз больше вычислений, чтобы полностью исключить цифровое мерцание и шум на стыках микронитей фрактала.
* **Сохранение архива кадров**: Движок сохраняет всю последовательность файлов в исходном качестве BMP, позволяя вам 
вручную управлять архивом изображений и повторно пережимать видео без повторных вычислений.

## Для чего это нужно:

* **Создание профессионального контента**: Генерация залипательных бесшовных видео-лупов высокого разрешения для 
медитаций, VJ-сетов, живых обоев или научно-популярных блогов на YouTube.
* **Экстремальный стресс-тест и бенчмарк**: Идеальный гибридный workload для проверки стабильности ПК. Программа 
выжимает 100% мощности из CPU при расчёте BLA-матриц возмущений и параллельно до предела загружает GPU блоками 
аппаратного кодирования.
* **Полный контроль над медиа-данными**: Вы получаете не только скомпилированный видеофайл, но и полную библиотеку 
несжатых кадров высокой четкости, готовую для любых дальнейших экспериментов и постобработки.

## Фрагмент видеоролика о множестве Мандельброта, длительность 10 секунд (полное видео - 1 минута), разрешение 1080 x 1080 пикселей.

```C++
const char * CENTER_RE = "-0.8432337645307515133246117300038447886638913178942914768815245";
const char * CENTER_IM = "0.2238180415580699591398982954803114403955748218705388777865576";
const int TOTAL_FRAMES = 1800; 
const char* START_VIEW_STR = "1.29e-49";
const char* END_VIEW_STR   = "1.29e-57";
```


## Благодарности и признание авторства (Credits & Acknowledgments)

Этот проект использует передовые алгоритмы метода возмущений и концепции управления фазами орбит, 
разработанные мировым фрактальным сообществом. Особая благодарность следующим авторам и первопроходцам 
с Fractal Forums, чей совместный труд сделал создание этого движка возможным:

* **Kevin Martin** — за новаторские методы векторизации, оптимизацию глубоких циклов и точное определение границ ухода орбит.
* **Zhuoran Yu** — за разработку математической концепции динамической релокализации опорной точки и перебазирования орбит (Orbit Re-basing).
* **James Ward Martin (JWM)** — за создание фундаментального проекта MDZ (Mandelbrot Deep Zoom), заложившего основы применения 
библиотек MPFR/GMP для сверхглубокого погружения.
* **Claude Heiland-Allen** — за колоссальные математические исследования фрактального зума, сохранение исходного 
программного наследия сообщества и разработку продвинутых алгоритмов трансформации палитр.


## Ключевые особенности:

* **Высокоточная опорная орбита:** Опорная траектория с точностью 1000 бит вычисляется строго один раз для каждого слоя приближения 
с использованием библиотеки GNU MPFR.
* **Аппаратное ускорение:** Сверхбыстрые математические расчеты для миллионов пикселей за счет использования аппаратных регистров 
double процессора.
* **При использовании чисел** с плавающей запятой двойной точности (порядка $10^{-15}$) теория возмущений позволяет приблизиться 
к уровню $10^{-308}$ — не дальше.
* **Динамическая релокализация опорной точки** (Перебазирование орбиты / Orbit Re-basing).
* **Билинейная аппроксимация (BLA Skip-100):** Расчет выполняется существенно быстрее за счет одновременного «перепрыгивания» 
через 100 итераций на гладких участках фрактала.
* **Настоящий суперсэмплинг 3x3 SSAA (Прямая интеграция в RGB):** Безупречное, сглаженное качество изображения с 9 независимыми 
выборками на один пиксель. Смешивание происходит напрямую в цветовом пространстве RGB, что полностью устраняет хроматический шум.
* **Многопоточность на чистом C++11:** Высокоскоростные параллельные вычисления, встроенные напрямую в стандарт языка и прозрачно 
масштабируемые на любые архитектуры процессоров.
* **Да, это FFmpeg**: "швейцарский армейский нож" для обработки видео.


## Фрагмент видеоролика о множестве Мандельброта, длительность 10 секунд (полное видео - 1 минута), разрешение 1080 x 1080 пикселей.

```C++
const char * CENTER_RE = "-0.12702288604303376058504940552835636145639339878096842408417373730140553";
const char * CENTER_IM = "0.98728474138900681012772182210671973643707041031463043446236865072311861";
const int TOTAL_FRAMES = 1800; 
const char* START_VIEW_STR = "4.95e-61";
const char* END_VIEW_STR   = "4.95e-69";
```


## Безграничная точность (Arbitrary Precision Arithmetic)

Движок полностью избавлен от аппаратных ограничений стандартных типов данных — нативного 64-битного (`double`) 
и расширенного 80-битного (`long double`), которые неизбежно теряют значащие разряды и приводят к пикселизации 
кадра («эффекту квадратов») на масштабах приближения глубже $10^{-15}$ и $10^{-19}$.

* **Интеграция MPFR/GMP:** Вся высокоточная координатная навигация, масштабирование при кликах мыши и расчет шага 
сетки осуществляются внутри изолированной бинарной памяти с точностью **1000 бит**.
* **Физический лимит в 308 знаков:** Экспоненциальный диапазон аппаратного регистра `double` ограничивает скоростной 
дельта-движок максимальной теоретической глубиной погружения в **$10^{-308}$ знаков**. Текущие координаты кадра 
сохраняются и считываются через файл `Mandelbrot.txt`, гарантируя безупречную четкость математических микроструктур 
на пороге кремниевого барьера.


## Реактивный метод возмущений (Perturbation Theory)

Рендеринг экстремальных приближений больше не требует выполнения ресурсоемких длинных вычислений произвольной точности 
для каждого отдельного пикселя, что исторически замедляло фрактальный софт в тысячи раз.

* **Высокоточная опорная орбита:** Сверхтяжелый BigFloat-радар MPFR рассчитывает абсолютную и точную траекторию всего 
для **одной центральной точки кадра и строго один раз** перед началом рендеринга.
* **Аппаратное ускорение вычислений:** Весь остальной массив экрана (миллионы пикселей) просчитывается параллельно на нативной 
скорости процессорных регистров `double`. Алгоритм вычисляет лишь микроскопические отклонения (дельты) от центральной опорной оси, 
что обеспечивает колоссальный выигрыш в производительности и ускоряет генерацию кадра до 1000 раз!


## Динамическая релокализация опорной точки (Перебазирование орбиты)

Это предмет особой гордости: движок работает на тех же математических и архитектурных принципах, 
что и самые продвинутые рендереры Мандельброта в мире.

* **Динамический сброс в ноль (Dynamic Reset to Zero)**: На каждом шаге для каждого пикселя отслеживается соотношение его абсолютных 
координат и текущего отклонения (дельты). Если дельта уходит слишком далеко или основная опорная орбита завершается, поток 
вычислений динамически сбрасывает индекс отслеживания в ноль. Это превращает накопленные координаты в новое автономное начало 
отсчета и полностью устраняет артефакты точности.
* **Оптимизация цикла <На один шаг за предел ухода> (One-Step Beyond Escape Loop Optimization)**: Чтобы выжать максимум производительности 
из CPU, трекер опорной орбиты MPFR записывает ровно одну дополнительную точку в массив орбиты сразу после того, как она превышает 
радиус ухода (escape radius). Такое точное определение границы гарантирует безупречное перебазирование орбиты.
* **Оптимизация ветвлений в глубоком цикле (Deep Loop Branch Optimization)**: Эта элегантная структура кода существенно упрощает 
условия внутри самого глубокого цикла итераций. Минимизируя тяжелые ветвления и избегая сложных вложенных условий там, где это 
возможно, код повышает эффективность предсказателя ветвлений процессора и позволяет конвейеру CPU выполнять базовые математические 
расчеты с максимальной пропускной способностью.


## Билинейная аппроксимация (Bilinear Approximation)

Расчет фрактала выполняется существенно быстрее за счет интеграции метода билинейной аппроксимации (**BLA Skip-100**). 

* **Предварительный расчет матриц:** Движок заранее вычисляет коэффициенты трансформации матриц для шагов 
по 100 итераций.
* **Масштабный пропуск итераций:** Если текущая точка дельты находится в пределах безопасного радиуса сходимости 
относительно опорной орбиты, алгоритм «перепрыгивает» сразу 100 итераций за один математический шаг. 
Это кардинально снижает нагрузку на процессор и обеспечивает колоссальный прирост скорости рендеринга 
на гладких участках множества Мандельброта.


## Многопоточность на чистом C++11 (Pure C++11 Multi-threading)

Высокоскоростные параллельные вычисления, встроенные напрямую в стандарт языка. 
Алгоритм прозрачно масштабируется на любые архитектуры, обеспечивая безупречную 
100%-ю загрузку процессора как на 4-ядерном ноутбуке, так и на 128-ядерном 
высокопроизводительном сервере - абсолютно без внешних зависимостей.


## Истинное сглаживание SSAA 3x3: 9-точечная интеграция в RGB-пространство

Для достижения визуального качества в движке реализован алгоритм суперсэмплинга **True 3x3 SSAA**, 
где каждый пиксель формируется на основе **9 независимых субпиксельных координат**. Это позволяет 
устранить алиасинг, возникающий из-за того, что микронити множества Мандельброта меньше физического пикселя.

### Математическая несостоятельность стандартного подхода
Классический подход ошибочно усредняет сырые значения итераций до окрашивания:
* `Color( (iter_1 + iter_2 + ... + iter_9) / 9 )`

Поскольку палитры нелинейны, это проецирует результат на случайный цвет, вызывая ложные хроматические контуры и артефакты.

### Инженерное решение: 9-точечная оптическая интеграция в RGB
Движок вычисляет цвет для каждого из 9 субпикселей независимо до смешивания, выполняя поканальное накопление:
* `(Color(iter_1) + Color(iter_2) + ... + Color(iter_9)) / 9`

### Ключевые технические преимущества:
* **Фрактальное сэмплирование:** Захват микроструктур, меньших размера пикселя.
* **Устранение шума:** Ликвидация хроматического шума за счет работы с каналами RGB.
* **Кинематографическая целостность:** Обеспечение плавных градиентов и высокого качества графики.


## Да, это FFmpeg - "швейцарский армейский нож" для обработки видео.

В 2026 году он остается отраслевым стандартом, 
поддерживаемым сообществом разработчиков открытого программного обеспечения. 
От YouTube и Netflix до профессиональных киностудий - все на него полагаются. И да, он совершенно бесплатный.

## Всё включено: 

Этот репозиторий уже содержит исполняемые файлы ffmpeg для Windows и Linux. Никакой ручной установки не требуется - всё работает прямо <из коробки>!


## Лицензия и стороннее программное обеспечение

### Мой код

Этот проект распространяется под лицензией **MIT**.

### FFmpeg

Это программное обеспечение использует библиотеки из проекта **FFmpeg** под лицензией **LGPLv2.1** (или GPLv3, в зависимости от сборки).
* FFmpeg является товарным знаком Фабриса Беллара, создателя проекта FFmpeg.
* Исходный код и дополнительную информацию можно найти по адресу [https://ffmpeg.org](https://ffmpeg.org).
* Бинарные файлы FFmpeg, включенные в релизы, предоставляются как есть, и в исходный код FFmpeg не вносились никакие изменения.




**[Скачать последнюю версию (Windows и Linux)](https://github.com/Divetoxx/Mandelbrot-Video/releases)**


