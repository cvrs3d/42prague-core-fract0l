# Mandelbrot Set Visualization

Welcome to the Mandelbrot Set Visualization project! This project aims to create stunning visual representations of the Mandelbrot set using simple math and X-Window API the MinilibX.

## Introduction

The Mandelbrot set is a famous fractal that has captivated mathematicians and artists alike. This project provides tools to generate and explore the intricate patterns of the Mandelbrot set.

## Features

- **Rendering adjustment**: Generate high-quality images of the Mandelbrot set.
- **Zoom and Pan**: Explore different regions of the Mandelbrot set with interactive zoom and pan functionality.

## Installation

To get started with the Mandelbrot Set Visualization project, follow these steps:

1. Clone the repository:
	```bash
	git clone https://github.com/cvrs3d/42prague-core-fract0l.git
	```
2. Navigate to the project directory:
	```bash
	cd mandelbrot
	```
3. Make the project
	```bash
	make
	```

## Usage
To choose between a multiprocessing version (faster) or a normal version (slower), make sure to build the bonus part first by running `make bonus`.

The program will automatically use the appropriate mode based on the build.

!!! WARNING !!!
BE ADVISED THAT MULTIPROCESSING MODE REQUIRES 4 CORES!!!
If your computer has fewer CPU cores than specified in your program, the operating system will still manage to run the processes, but it may lead to suboptimal performance. Here's what typically happens:

1. **Context Switching**: The operating system will perform context switching, where it rapidly switches between processes to give the illusion that they are running simultaneously. This can lead to increased overhead and reduced performance due to the time spent switching contexts.

2. **Increased Load**: The CPU will be under increased load, which can lead to higher temperatures and potentially thermal throttling, where the CPU reduces its speed to prevent overheating.

3. **Longer Execution Time**: The overall execution time of your program may increase because the CPU has to divide its time among more processes than it has cores.

4. **Resource Contention**: Other applications running on your system may experience slower performance because the CPU is heavily utilized by your program.


To generate a Mandelbrot set image, run the following command:

```bash
./fractol mandelbrot
```

To generate a Julia set image, run the following command:

```bash
./fractol julia <real part> <imaginary without i>
```


## Resources

For better understanding here are the useful links:

minilibX API - [Documentation](https://harm-smits.github.io/42docs/libs/minilibx)

Julia Set - [Wiki](https://en.wikipedia.org/wiki/Julia_set)

Mandelbrot Set - [Wiki](https://en.wikipedia.org/wiki/Mandelbrot_set)

Numberphile channel - [Mandelbrot Playlist Youtube](https://www.youtube.com/watch?v=FFftmWSzgmk&list=PLt5AfwLFPxWL7NpD_DKO28XhS0Ugctkpu&ab_channel=Numberphile)
