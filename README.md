# 🚗 2D Animated Roadside Scene

[![OpenGL](https://img.shields.io/badge/OpenGL-3.3%2B-5586A4?logo=opengl\&logoColor=white)](https://www.opengl.org/)
[![GLUT](https://img.shields.io/badge/Toolkit-GLUT%20%2F%20FreeGLUT-green.svg)](https://www.opengl.org/resources/libraries/glut/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20C-00599C?logo=c%2B%2B\&logoColor=white)](https://isocpp.org/)

> **East Delta University**  
> **Department of Computer Science & Engineering**  
> **Course Name:** Computer Graphics Lab  
> **Course ID:** CSE 322.5  
> **Repository:** https://github.com/mdjameee400/2d-roadside-animation.git
---

## Project Overview

We built this 2D animated roadside scene using C++ and the OpenGL Utility Toolkit (GLUT) for our Computer Graphics Lab project. The goal was to create a lively environment from scratch using only basic geometric shapes.

There are no external images or textures used in this project. Everything you see is drawn using raw OpenGL polygons and math-based circles. It is a great starting point for anyone learning how to draw shapes, apply colors, and create continuous animations in OpenGL.

---

## What's in the Scene?

🚘 **Continuous Vehicle Animation**

A red car and a cyan truck move continuously from right to left. When they drive off the screen, they automatically loop back to the start so the traffic never stops.

🏞️ **Detailed Static Environment**

The scene includes layered foreground and background trees, green bushes, and small flowers by the road. We also drew a bright blue sky, a yellow sun, and a multi-layered road with lane markings and a streetlight.

🎮 **Interactive Clouds**

You can control the clouds manually. Pressing the left or right arrow keys on your keyboard will drift the clouds across the sky.

---

## Demo Video

*Video dis ekhane*

---

## Interactive Controls

| Key                      | Action                   |
| :----------------------- | :----------------------- |
| <kbd>← Left Arrow</kbd>  | Move clouds to the left  |
| <kbd>→ Right Arrow</kbd> | Move clouds to the right |

*The car and truck animate automatically as soon as the program starts. No input is needed for them.*

---

## How It Works

Here is a quick breakdown of the logic we used:

**Drawing Circles:** OpenGL does not have a direct tool to draw circles. We wrote a custom circle function using basic trigonometry (sin and cos) to draw a 360-sided polygon. We used this logic to draw the sun, clouds, vehicle wheels, and tree leaves.

**Making Things Move:** To move the car and truck, we used variables (`tx` for the car, `bx` for the truck). We increase these numbers every frame and use `glTranslatef()` to push the vehicles left. When the vehicles go completely off-screen, we reset the values to loop them back.

**The Animation Loop:** At the end of the drawing functions, we call `glutPostRedisplay()`. This tells OpenGL to redraw the screen immediately and creates a smooth continuous animation.

**Matrix Protection:** We wrapped the car and truck code inside `glPushMatrix()` and `glPopMatrix()`. This ensures that `glTranslatef()` only moves the vehicles and the rest of the world (trees, sun, road) stays in place.

---

## Project Directory Structure

```text
2d-roadside-animation/
├── src/
│   └── moving_cars.cpp           # The main C++ source code
└── README.md                     # Project documentation
```

## Build & Installation Guide

You can run this project easily on Windows or Linux.

### Method 1: CodeBlocks IDE

1. Open Code::Blocks
2. Go to **File > New > Project**
3. Select **GLUT project** and click **Go**
4. Name your project and point it to your GLUT installation folder
5. Replace the default `main.cpp` with our `moving_cars.cpp` code
6. Hit **F9** to Build and Run

### Method 2: GCC / MinGW Command Line

Open your terminal in the project folder and run:

```bash
g++ moving_cars.cpp -o roadside_animation.exe -lfreeglut -lopengl32 -lglu32
```

Then run the program:

```bash
./roadside_animation.exe
```

### Method 3: Linux (Ubuntu/Debian)

Install GLUT if you haven't already:

```bash
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev libgl1-mesa-dev
```

Remove `#include <windows.h>` from the top of the `.cpp` file.

Compile and run:

```bash
g++ moving_cars.cpp -o roadside_animation -lGL -lGLU -lglut
./roadside_animation
```

## Group Information & Contributors
| **Student Name** | **Student ID** | **Department** | **Role / Contribution** |
|---|---|---|---|
| **[MD Abdullah Al Jamee](https://github.com/mdjameee400)** | *233028912* | CSE | Animation & Road Physics |
| **[Efti Hasan](https://github.com/Efti-Hasan)** | *233031412* | CSE | Environment, Lighting & Sky Cycle |
| **[Chowdhury Shams Intisar](https://github.com/intisar)** | *233030512* | CSE | Vehicle Modeling, Transformations & Interactivity |

