[English](#english) | [Русский](#russian)
<a name="english"></a>

# Mandelbrot set Video. 80-bit long double. OpenMP. Supersampling 8x8 (64 passes).

## Video encoding
Sequential BMP frames (frame_000.bmp to frame_254.bmp) compiled into Mandelbrot.mp4 using FFmpeg.

## Controls & Hotkeys
Keys [1-3]: Choose one of three predefined locations within the Mandelbrot set to generate. 
Automated Animation Suite: Generates a sequence of 255 high-precision BMP frames and automatically compiles them 
into a seamless 30 FPS video loop using integrated FFmpeg.

```C++
absc = -0.5503432753421602; ordi = -0.6259312704294012; size_val = 0.000000000000225;
absc = -0.691488093510181825; ordi = -0.465680729473216972; size_val = 0.0000000000000017;
absc = -0.550345905862346513; ordi = 0.625931416301985337; size_val = 0.0000000000000029;
```

Key [4]: Read coordinates/parameters from three lines in Mandelbrot.txt
Automated Animation Suite: Generates a sequence of 255 high-precision BMP 
frames and automatically compiles them into a seamless 30 FPS video loop using integrated FFmpeg.

![Mandelbrot txt](Mandelbrot.png)


## High-Precision Rendering (80-bit)
Most Mandelbrot explorers use standard **64-bit double precision**, which leads to "pixelation" at zoom levels around $10^{14}$. 
This project leverages **80-bit Extended Precision Arithmetic** (`long double`) to push the boundaries of the fractal:

*   **My Implementation (80-bit):** Provides **4 extra decimal digits** of precision, allowing you to explore **10,000x deeper** ($10^{18}$ range).
*   **Hardware Optimized:** Directly utilizes the **x87 FPU registers** for maximum mathematical depth.

## OpenMP
OpenMP is a standard that tells the compiler, "Take this loop and distribute the iterations among the different processor cores."
Yes, using OpenMP you are doing parallel programming at the Multithreading level.
Everything is powered by **OpenMP** parallel loops for maximum performance.
OpenMP - Scalability: Your code will run equally efficiently on a 4-core laptop and a 128-core server.


## 8x8 Supersampling (64 Samples Per Pixel)
Super-Sampling Anti-Aliasing (SSAA) is a high-end technique increasing samples per pixel to enhance image quality, 
with 8x (N=8) rendering scenes at 8x resolution on both axes to produce 64 samples per pixel. 
This process calculates an extreme number of pixels-scaling to a 15360 x 15360 grid for a 1920 x 1920
target-before downscaling to remove jaggies and improve detail.

I decided to take the visual quality to a completely different level. This engine implements
True 8x8 Supersampling Anti-Aliasing (SSAA) with 64 independent samples per single screen pixel, utilizing Direct RGB-Space Integration.
Instead of a standard 1920x1920 render, the engine internally processes a massive 15,360 x 15,360 sub-pixel grid!
After calculating all 64 samples for a pixel, they are downsampled into one.
Key Technical Advantages:

*    64-Point Fractal Sampling: Each final screen pixel is computed from sixty-four independent fractal coordinate points.
*    High-Precision Per-Channel RGB Accumulation: The engine first calculates the specific 24-bit color for every single sub-pixel before performing any blending.
*    Noise Elimination: By accumulating color intensities (R, G, B) rather than raw iteration counts, we completely eliminate "chromatic noise." The result is a crystal-clear, razor-sharp image where every micro-filament is perfectly reconstructed.
*    True Color Integration: Our solution performs integration directly in the RGB color space. By computing the exact Red, Green, and Blue components for each sub-pixel before downsampling, we achieve a cinematic level of smoothness and structural integrity that 8-bit or iteration-based renderers simply cannot match.


## Visual Aesthetics
The Red, Green, and Blue channels are calculated using sine and cosine waves to create smooth color transitions:
127 + 127 * cos(2 * PI * a / 255) and 127 + 127 * sin(2 * PI * a / 255).


## Look at the results! The smoothness is incredible 

https://github.com/user-attachments/assets/77f35c8b-98df-4b2b-ba09-b887dfff9f89


**[Download Latest Version (Windows & Linux)](https://github.com/Divetoxx/Mandelbrot/releases)**


## License and Third-Party Software

### My Code
This project is licensed under the **MIT License**.

### FFmpeg
This software uses libraries from the **FFmpeg** project under the **LGPLv2.1** (or GPLv3, depending on the build). 
* FFmpeg is a trademark of Fabrice Bellard, originator of the FFmpeg project.
* You can find the source code and more information at [https://ffmpeg.org](https://ffmpeg.org).
* The FFmpeg binaries included in the releases are provided as-is, and no modifications have been made to the FFmpeg source code.



<a name="russian"></a>
# Множество Мандельброта видео. 80-бит long double. OpenMP. Суперсэмплинг 8x8 (64 прохода).

## Видео 
Последовательные кадры в формате BMP (от frame_000.bmp до frame_254.bmp), скомпилированные в файл Mandelbrot.mp4 с использованием FFmpeg.


## Горячие клавиши
Утилита из командной строке. Либо клавиша 1-3 - это одно из шести разных мест множество Мандельброта.
Пакет автоматизированной анимации: генерирует последовательность из 255 высокоточных кадров в формате BMP 
и автоматически компилирует их в бесшовный видеоролик с частотой 30 кадров в секунду, используя встроенный FFmpeg.

```C++
absc = -0.5503432753421602; ordi = -0.6259312704294012; size_val = 0.000000000000225;
absc = -0.691488093510181825; ordi = -0.465680729473216972; size_val = 0.0000000000000017;
absc = -0.550345905862346513; ordi = 0.625931416301985337; size_val = 0.0000000000000029;
```

Либо читает из файла Mandelbrot.txt три строки - клавиша 4.
Пакет автоматизированной анимации: генерирует последовательность из 255 высокоточных кадров в формате BMP 
и автоматически компилирует их в бесшовный видеоролик с частотой 30 кадров в секунду, используя встроенный FFmpeg.

![Mandelbrot txt](Mandelbrot.png)



## Высокоточная отрисовка (80-бит)
Большинство исследователей фрактала Мандельброта используют стандартную **64-битную двойную точность**,
что приводит к "пикселизации" при масштабировании около $10^{14}$.
В этом проекте используется **80-битная арифметика с расширенной точностью** (<long double>) для расширения границ фрактала:

* **Моя реализация (80-бит):** Обеспечивает **4 дополнительных десятичных знака** точности, позволяя исследовать **в 10 000 раз глубже** (диапазон $10^{18}$).
* **Аппаратная оптимизация:** Непосредственно использует **регистры FPU x87** для максимальной глубины математических вычислений.


## OpenMP
OpenMP - это стандарт, который говорит компилятору: "Возьми этот цикл и сам раздай итерации разным ядрам процессора".
Используя OpenMP, вы занимаетесь параллельным программированием на уровне многопоточности (Multithreading).
OpenMP - масштабируемость: ваш код будет одинаково эффективно работать как на 4-ядерном ноутбуке,
так и на 128-ядерном сервере.


## Суперсэмплинг 8x8 (64 прохода на один пиксель)
Суперсэмплинг (SSAA) - ресурсоемкий метод сглаживания, увеличивающий число выборок на пиксель для повышения качества изображения. 
При значении 8x (N=8) сцена рендерится в разрешении, в 8 раз превышающем целевое, по обеим осям, создавая 64 (или 8 х 8) выборки 
на пиксель. Изображение просчитывается в более высоком разрешении, а затем принудительно уменьшается до разрешения дисплея, 
устраняя лесенки и улучшая чёткость. Это очень высокая нагрузка! Это не 1920 на 1920 пикселя а в 8x8 больше - 15360 на 15360 пикселя!

Я решил вывести качество изображения на совершенно новый уровень. Этот движок использует
истинное сглаживание 8x8 Supersampling Anti-Aliasing (SSAA) с 64 независимыми сэмплами на каждый пиксель экрана, используя прямую интеграцию в RGB-пространство.
Вместо стандартного рендеринга 1920x1920, движок обрабатывает внутри себя огромную сетку из 15 360 x 15 360 субпикселей!

После вычисления всех 64 сэмплов для пикселя, они уменьшаются до одного.
Ключевые технические преимущества:

* 64-точечное фрактальное сэмплирование: каждый конечный пиксель экрана вычисляется из шестидесяти четырех независимых 
фрактальных координатных точек.
* Высокоточное накопление RGB-цвета по каналам: движок сначала вычисляет конкретный 24-битный цвет для каждого субпикселя, 
прежде чем выполнять какое-либо смешивание.
* Устранение шума: Накапливая интенсивность цвета (R, G, B), а не просто подсчитывая количество итераций, мы полностью 
устраняем <хроматический шум>. В результате получается кристально чистое, резкое изображение, где каждая микронить идеально воссоздана.
* Интеграция истинного цвета: Наше решение выполняет интеграцию непосредственно в цветовом пространстве RGB. 
Вычисляя точные компоненты красного, зеленого и синего цветов для каждого субпикселя перед понижением разрешения, 
мы достигаем кинематографического уровня плавности и структурной целостности, недостижимого для 8-битных или итерационных рендеров.


## Визуальная эстетика
Красный, зеленый и синий каналы рассчитываются с использованием синусоидальных и косинусоидальных волн для создания плавных цветовых переходов:
127 + 127 * cos(2 * PI * a / 255) и 127 + 127 * sin(2 * PI * a / 255).


## Посмотрите на результаты! Невероятная плавность работы

https://github.com/user-attachments/assets/77f35c8b-98df-4b2b-ba09-b887dfff9f89



**[Скачать последнюю версию (Windows и Linux)](https://github.com/Divetoxx/Mandelbrot/releases)**


## Лицензия и стороннее программное обеспечение

### Мой код
Этот проект распространяется под лицензией **MIT**.

### FFmpeg
Это программное обеспечение использует библиотеки из проекта **FFmpeg** под лицензией **LGPLv2.1** (или GPLv3, в зависимости от сборки).

* FFmpeg является товарным знаком Фабриса Беллара, создателя проекта FFmpeg.

* Исходный код и дополнительную информацию можно найти по адресу [https://ffmpeg.org](https://ffmpeg.org).

* Бинарные файлы FFmpeg, включенные в релизы, предоставляются как есть, и в исходный код FFmpeg не вносились никакие изменения.

