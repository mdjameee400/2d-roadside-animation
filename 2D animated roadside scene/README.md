# 🚗 2D Animated Roadside Scene

[![OpenGL](https://img.shields.io/badge/OpenGL-3.3%2B-5586A4?logo=opengl&logoColor=white)](https://www.opengl.org/)
[![GLUT](https://img.shields.io/badge/Toolkit-GLUT%20%2F%20FreeGLUT-green.svg)](https://www.opengl.org/resources/libraries/glut/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20C-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-0078D6?logo=windows&logoColor=white)](https://github.com/mdjameee400/2d-roadside-animation)
[![Course](https://img.shields.io/badge/Course-Computer%20Graphics%20Lab-orange.svg)](#group-information)

> **East Delta University — Department of Computer Science & Engineering**  
> **Course:** Computer Graphics & Multimedia Lab (GLUT Final Project)  
> **Repository:** [https://github.com/mdjameee400/2d-roadside-animation.git](https://github.com/mdjameee400/2d-roadside-animation.git)

---

## 📌 Table of Contents
- [📖 Project Overview](#-project-overview)
- [✨ Key Features](#-key-features)
- [🎬 Demo & Visual Preview](#-demo--visual-preview)
- [🎮 Interactive Controls](#-interactive-controls)
- [📐 Technical Architecture & Transformations](#-technical-architecture--transformations)
- [📁 Project Directory Structure](#-project-directory-structure)
- [⚙️ Prerequisites & Dependencies](#️-prerequisites--dependencies)
- [🛠️ Build & Installation Guide](#️-build--installation-guide)
  - [Method 1: GCC / MinGW Command Line (Recommended)](#method-1-gcc--mingw-command-line-recommended)
  - [Method 2: Code::Blocks IDE](#method-2-codeblocks-ide)
  - [Method 3: Visual Studio](#method-3-visual-studio)
  - [Method 4: Linux (Ubuntu/Debian)](#method-4-linux-ubuntudebian)
- [🚀 How to Run](#-how-to-run)
- [👥 Group Information & Contributors](#-group-information--contributors)
- [📜 License](#-license)

---

## 📖 Project Overview

The **2D Animated Roadside Scene** is an interactive computer graphics simulation built using **C++** and the **OpenGL Utility Toolkit (GLUT / FreeGLUT)**. 

The project brings to life a bustling roadside environment featuring multiple layers of real-time animations, geometric transformations, and user-driven interactions. It demonstrates foundational and advanced 2D computer graphics concepts, including double buffering for smooth frame rendering, hierarchical modeling, trigonometric motion dynamics, and real-time state manipulation (such as day/night cycles and weather transitions).

---

## ✨ Key Features

### 🚘 1. Dynamic Traffic & Vehicle Animation
* **Multi-Lane Traffic:** Moving cars, buses, and transport vehicles traversing across the scene at varying realistic speeds.
* **Rotating Wheels:** Applied 2D rotational transformations (`glRotatef`) synchronized with the translational velocity (`glTranslatef`) of each vehicle.
* **Vehicle Variations:** Unique body styling, multi-colored chassis, transparent windows, and illuminated headlights/taillights.

### 🏞️ 2. Dynamic Environment & Weather Cycles
* **Day & Night Simulation:** Seamless background color interpolation transitioning between bright sunny day, twilight, and dark night skies.
* **Celestial Bodies:** Moving Sun and Moon with orbit paths, glowing corona effects, and twinkling stars in night mode.
* **Floating Clouds & Windmills:** Multi-layer parallax cloud movement and spinning aerodynamic windmill blades.
* **Roadside Vegetation & Infrastructure:** Swaying trees, streetlights with dynamic night illumination cones, road divider markings, sidewalks, and roadside houses/billboards.
* **Precipitation System (Rain Mode):** Animated rainfall particle effect with adjustable intensity.

### 🎮 3. Real-Time User Interactivity
* Keyboard hotkeys to toggle day/night modes, toggle weather/rain, accelerate/decelerate traffic, pause/resume animations, and switch scene cameras.
* Mouse click interactions to spawn obstacles, trigger vehicle horns/lights, or interact with environmental elements.

---

## 🎬 Demo & Visual Preview

### 📸 Scene Preview Showcase

| Day Mode Scene | Night Mode with Streetlights |
| :---: | :---: |
| ![Day Scene Preview](assets/screenshot_day.png) | ![Night Scene Preview](assets/screenshot_night.png) |
| *Vibrant roadside scenery with active vehicles & clear sky* | *Illuminated headlights, streetlamps, stars, and moon* |

### 🎞️ Live Animated Demonstration (GIF)

<div align="center">
  <img src="assets/demo.gif" alt="2D Animated Roadside Scene Demo" width="850px" />
  <p><em>Real-time demonstration of vehicles, wheel rotation, cloud drift, and interactive transitions.</em></p>
</div>

> **Note:** Place your project screenshot and GIF recordings inside the `assets/` folder as `assets/demo.gif`, `assets/screenshot_day.png`, and `assets/screenshot_night.png`.

---

## 🎮 Interactive Controls

The project provides interactive keyboard and mouse inputs to control the animation in real-time:

| Key / Input | Action / Function | Description |
| :--- | :--- | :--- |
| <kbd>D</kbd> / <kbd>d</kbd> | **Day Mode** | Switches the sky and environment lighting to daytime |
| <kbd>N</kbd> / <kbd>n</kbd> | **Night Mode** | Enables night mode with starry sky, moon, and streetlights |
| <kbd>R</kbd> / <kbd>r</kbd> | **Rain / Weather** | Toggles rainfall particle animation ON / OFF |
| <kbd>▲ Up Arrow</kbd> | **Speed Up** | Increases the velocity of traveling vehicles |
| <kbd>▼ Down Arrow</kbd> | **Slow Down** | Decreases vehicle speed |
| <kbd>Space</kbd> / <kbd>P</kbd> | **Pause / Resume** | Freezes or unfreezes all animations |
| <kbd>H</kbd> / <kbd>h</kbd> | **Headlights** | Toggles vehicle headlights ON / OFF |
| <kbd>Left Mouse Click</kbd> | **Interactive Trigger** | Interacts with objects at cursor coordinates |
| <kbd>Esc</kbd> | **Exit** | Closes the OpenGL graphics window |

---

## 📐 Technical Architecture & Transformations

The project leverages core OpenGL graphics pipeline concepts:

```
                  +-------------------------------+
                  |      glutMainLoop() Event     |
                  +---------------+---------------+
                                  |
            +---------------------+---------------------+
            |                                           |
            v                                           v
  +--------------------+                      +--------------------+
  |  display() Routine |                      |  timer() Callback  |
  +---------+----------+                      +---------+----------+
            |                                           |
    +-------+-------+                           +-------+-------+
    |               |                           |               |
    v               v                           v               v
 [Sky & Sun]   [Road & Trees]            [Update X/Y]    [Rotate Angles]
    |               |                           |               |
    +-------+-------+                           +-------+-------+
            |                                           |
            v                                           v
   [Vehicles & Wheels]                          [glutPostRedisplay]
            |
            v
   [glutSwapBuffers()]
```

### Transformations Applied:
1. **Translation (`glTranslatef`):** Moves cars, buses, clouds, rain drops, and celestial objects along horizontal and vertical trajectories.
2. **Rotation (`glRotatef`):** Rotates the spokes of car wheels around their local origins, as well as the blades of roadside windmills.
3. **Scaling (`glScalef`):** Used for perspective depth scaling (smaller vehicles on distant lanes, larger vehicles up close).
4. **Hierarchical Matrix Stack (`glPushMatrix` / `glPopMatrix`):** Isolates transformations for individual vehicle parts (e.g., body vs. wheels) to prevent state bleeding.
5. **Double Buffering (`GLUT_DOUBLE | GLUT_RGB`):** Eliminates screen tearing and flickering for a smooth 60 FPS experience.

---

## 📁 Project Directory Structure

```text
2d-roadside-animation/
├── assets/                       # Demo media & preview assets
│   ├── demo.gif                  # Animated preview GIF
│   ├── screenshot_day.png        # Daytime output screenshot
│   └── screenshot_night.png      # Nighttime output screenshot
├── include/                      # Header files (if modularized)
│   └── GL/                       # GLUT / FreeGLUT headers (glut.h, freeglut.h)
├── lib/                          # Library dependencies
│   ├── libfreeglut.a             # Static/Import library for MinGW
│   └── glut32.lib                # MSVC/MinGW lib
├── src/                          # Source code files
│   └── main.cpp                  # Main application source code
├── freeglut.dll                  # FreeGLUT Runtime DLL (Windows)
├── glut32.dll                    # GLUT 32-bit Runtime DLL (Windows)
├── Makefile                      # Make build configuration (optional)
└── README.md                     # Comprehensive project documentation
```

---

## ⚙️ Prerequisites & Dependencies

To compile and run this project, make sure you have:
* **C++ Compiler:** GCC / G++ (MinGW on Windows) or MSVC (Visual Studio)
* **OpenGL Libraries:** Standard OpenGL library (`opengl32` / `libGL`)
* **GLU Library:** OpenGL Utility library (`glu32` / `libGLU`)
* **GLUT / FreeGLUT Toolkit:** `freeglut` or `glut32` development files (`.h`, `.lib`, `.dll`)

---

## 🛠️ Build & Installation Guide

### Method 1: GCC / MinGW Command Line (Recommended)

1. Open your terminal / Command Prompt / PowerShell in the project directory.
2. Compile using `g++` linking GLUT and OpenGL libraries:

```bash
g++ -Wall -O2 src/main.cpp -o roadside_animation.exe -lfreeglut -lopengl32 -lglu32
```
*(If using standard `glut32` replace `-lfreeglut` with `-lglut32`)*

3. Ensure `freeglut.dll` (or `glut32.dll`) is located in the same directory as `roadside_animation.exe` (or in `C:\Windows\System32` / `C:\Windows\SysWOW64`).

---

### Method 2: Code::Blocks IDE

1. Open **Code::Blocks** and go to **File** $\rightarrow$ **New** $\rightarrow$ **Project...**
2. Select **GLUT project** and click **Go**.
3. Choose your project title and directory.
4. Specify the **GLUT location** (the folder containing `include` and `lib` directories).
5. Configure Linker Settings:
   - Go to **Project** $\rightarrow$ **Build options...** $\rightarrow$ **Linker settings**.
   - Add the following link libraries in **Other linker options**:
     ```text
     -lfreeglut -lopengl32 -lglu32
     ```
6. Replace the generated template in `main.cpp` with your project's `main.cpp`.
7. Copy `freeglut.dll` or `glut32.dll` to your project's output folder (`bin/Debug` or `bin/Release`).
8. Press <kbd>F9</kbd> to **Build and Run**.

---

### Method 3: Visual Studio

1. Create a new **C++ Empty Project** or **Console App** in Visual Studio.
2. Under **Project Properties** $\rightarrow$ **C/C++** $\rightarrow$ **General** $\rightarrow$ **Additional Include Directories**, add the path to the `include` folder.
3. Under **Linker** $\rightarrow$ **General** $\rightarrow$ **Additional Library Directories**, add the path to the `lib` folder.
4. Under **Linker** $\rightarrow$ **Input** $\rightarrow$ **Additional Dependencies**, add:
   ```text
   opengl32.lib;glu32.lib;freeglut.lib;
   ```
5. Add `main.cpp` to the **Source Files** folder.
6. Copy `freeglut.dll` next to the compiled `.exe` file.
7. Build and run using <kbd>Ctrl</kbd> + <kbd>F5</kbd>.

---

### Method 4: Linux (Ubuntu/Debian)

1. Install FreeGLUT and development packages:
```bash
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev libgl1-mesa-dev
```

2. Compile the source:
```bash
g++ src/main.cpp -o roadside_animation -lGL -lGLU -lglut
```

3. Run the executable:
```bash
./roadside_animation
```

---

## 🚀 How to Run

Once compiled, launch the program either by double-clicking the executable file or via terminal:

```bash
# On Windows
./roadside_animation.exe

# On Linux
./roadside_animation
```

Use the [Interactive Controls](#-interactive-controls) to interact with the animation in real time.

---

## 👥 Group Information & Contributors

This project is developed as part of the **Graphics Lab (GLUT Project)** at **East Delta University (EDU)**.

| Student Name | Student ID | Department | Role / Contribution |
| :--- | :--- | :--- | :--- |
| **Md. Jamee** | *[Your Student ID]* | CSE, East Delta University | Project Lead, Animation & Road Physics |
| **[Group Member 2]** | *[Student ID]* | CSE, East Delta University | Environment, Lighting & Sky Cycle |
| **[Group Member 3]** | *[Student ID]* | CSE, East Delta University | Vehicle Modeling, Transformations & Interactivity |

---

## 📜 License

This project is created for educational and academic assessment purposes for the **Graphics Lab** course at **East Delta University**. Feel free to use and reference this codebase for academic learning.

---

<div align="center">
  <sub>Built with ❤️ using C++ and OpenGL GLUT | East Delta University</sub>
</div>
