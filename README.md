# 🚗 2D Animated Roadside Scene

[![OpenGL](https://img.shields.io/badge/OpenGL-3.3%2B-5586A4?logo=opengl&logoColor=white)](https://www.opengl.org/)
[![GLUT](https://img.shields.io/badge/Toolkit-GLUT%20%2F%20FreeGLUT-green.svg)](https://www.opengl.org/resources/libraries/glut/)
[![Language](https://img.shields.io/badge/Language-C%2B%2B%20%2F%20C-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)

> **East Delta University**  
> **Department of Computer Science & Engineering**  
> **Course Name:** Computer Graphics Lab  
> **Course ID:** CSE 322.5  
> **Repository:** https://github.com/mdjameee400/2d-roadside-animation.git

---

## 📖 Project Overview

This **2D Animated Roadside Scene** is built using **C++** and the **OpenGL Utility Toolkit (GLUT)** for the Computer Graphics Lab (CSE 322.5) course at East Delta University. The project demonstrates real-time 2D computer graphics rendering, hierarchical transformations, mathematical parametric modeling, and interactive keyboard event handling.

Everything in the scene is rendered entirely from scratch using fundamental OpenGL primitives (`GL_POLYGON`, `GL_LINES`, `GL_TRIANGLES`) and custom trigonometric circle algorithms — without importing any external image textures or assets.

---

## 📸 Screenshots

| Scenario 1: Initial Scene Setup | Scenario 2: Traffic Progression |
| :---: | :---: |
| ![Scenario 1](resources/img/one.png) | ![Scenario 2](resources/img/scenario%20two.png) |
| **Scenario 3: Open Road & Flying Birds** | **Scenario 4: Cloud Drifting & Continuous Loop** |
| ![Scenario 3](resources/img/scenario%20three.png) | ![Scenario 4](resources/img/scenario%20four.png) |

---

## 🎥 Animation Demo

<div align="center">
  <img src="resources/img/2D_Street_View-ezgif.gif" width="85%" alt="2D Animated Roadside Scene Demo" style="border-radius: 8px; box-shadow: 0 4px 12px rgba(0,0,0,0.25);" />
  <p><em>Real-time 2D animated roadside scene with continuous traffic, flapping birds, and drifting clouds</em></p>
</div>

---

## 📁 Scene Components

| Component | Description |
| :--- | :--- |
| `Sky & Sun` | Vibrant sky backdrop (`GL_POLYGON`) with a parametric radiant yellow sun and orthogonal line rays (`GL_LINES`) |
| `Drifting Clouds` | Overlapping multi-circle cloud clusters with auto-drift and interactive user keyboard translation |
| `Animated Birds` | Flocking bird silhouettes with dynamic trigonometric sinusoidal wing-flapping physics |
| `House & Scenery` | Layered residential home with roof triangle, dual-pane tinted windows, door knob, and surrounding landscape |
| `Foliage & Flora` | Multi-canopy large trees, roadside small trees, clustered green bushes, and vibrant blooming flowers |
| `Roadway & Lighting` | Dark asphalt roadway with iterative dashed lane markings, green verge, and roadside streetlight |
| `Moving Vehicles` | Streamlined red sports car and dual-color cargo truck with windows, headlights, and hubbed wheels |

---

## 🎮 Controls

| Key | Action |
| :--- | :--- |
| <kbd>← Left Arrow</kbd> | Drift clouds to the left (`shift -= 2`) |
| <kbd>→ Right Arrow</kbd> | Drift clouds to the right (`shift += 2`) |
| **Autonomous** | Cars, trucks, clouds, and birds animate continuously upon launch |

---

## 🧩 Features

- **Mathematical Circle & Ellipse Generation** — Custom `circle(rx, ry, cx, cy)` function leveraging standard trigonometry (`cos` and `sin` across 360°) to generate smooth curved surfaces for the sun, clouds, tree foliage, flower petals, and vehicle wheels.
- **Sinusoidal Wing Flapping Physics** — Real-time wing flapping computed dynamically using `sin(birdShift * 0.15) * 8` to oscillate bird wing vertices up and down during flight.
- **Differential Vehicle Speeds & Looping** — The red sports car moves at `tx += 0.9` while the cyan cargo truck moves at `bx += 0.7`, featuring automatic boundary wrap-around logic (`tx > 500 -> -500`, `bx > 500 -> -510`) to maintain continuous organic traffic flow.
- **Matrix Stack Isolation** — All animated models (vehicles, birds, clouds) are encapsulated within `glPushMatrix()` and `glPopMatrix()` calls to prevent coordinate transformations from spilling into static environment geometry.
- **Interactive & Ambient Cloud Motion** — Clouds drift continuously across the sky (`shift += 0.1`) while seamlessly accepting real-time user steering inputs via GLUT special key callback (`glutSpecialFunc`).
- **Layered 2D Depth Ordering** — Renders geometry using the classic painter's algorithm order (Sky → Bushes → Ground → Trees → House → Road & Streetlight → Birds & Clouds → Vehicles → Foreground Flowers).
- **Flicker-Free Double Buffering** — Utilizes `GLUT_DOUBLE` with `glutSwapBuffers()` and smooth frame triggering via `glutPostRedisplay()`.

---

## 📂 Project Directory Structure

```text
2d-roadside-animation/
├── resources/
│   └── img/
│       ├── 2D_Street_View-ezgif.gif # Live animation recording
│       ├── one.png                  # Scenario 1: Initial Scene Setup
│       ├── scenario two.png         # Scenario 2: Traffic Progression
│       ├── scenario three.png       # Scenario 3: Open Road & Flying Birds
│       └── scenario four.png        # Scenario 4: Cloud Drift & Vehicle Loop
├── .gitignore                       # Excludes heavy video files from repository
├── main.cpp                         # Complete OpenGL / GLUT source code
└── README.md                        # Project documentation & walkthrough
```

---

## 🛠️ Installation and Configuration

This project is an OpenGL-based graphics project developed in **C/C++** using **FreeGLUT**. The instructions below outline how to set up the project on Windows using **Code::Blocks** with the **MSYS2 MinGW64** environment.

### 1. Requirements & Prerequisites

- **Operating System:** Windows OS
- **IDE:** Code::Blocks
- **Compiler & Toolchain:** MSYS2 MinGW64
- **Graphics API:** OpenGL
- **Toolkit:** FreeGLUT

---

### 2. Setup and Installation

#### Step 1: Install MSYS2
1. Download and install MSYS2 from: [https://www.msys2.org/](https://www.msys2.org/)
2. During installation, use the default installation directory:
   ```text
   C:\msys64
   ```

#### Step 2: Install FreeGLUT via MSYS2
1. Open **MSYS2 MinGW 64-bit** from the Start Menu.
   > [!IMPORTANT]
   > Make sure to use the **MINGW64 terminal** (`MSYS2 MinGW 64-bit`).

2. Run the following command:
   ```bash
   pacman -S mingw-w64-x86_64-freeglut
   ```
3. When prompted, enter `Y` and press `Enter` to confirm the installation.
4. After installation, FreeGLUT headers and libraries will be available under:
   ```text
   C:\msys64\mingw64
   ```

---

### 3. Code::Blocks Configuration

1. Launch **Code::Blocks** and open the project.
2. Go to: **Project → Build options...**
3. Select the **project name** from the left panel so settings apply across all build targets.

#### A. Compiler Search Directory
- Navigate to: **Search directories → Compiler**
- Click **Add** and insert:
  ```text
  C:\msys64\mingw64\include
  ```

#### B. Linker Search Directory
- Navigate to: **Search directories → Linker**
- Click **Add** and insert:
  ```text
  C:\msys64\mingw64\lib
  ```

#### C. Linker Libraries
- Open the **Linker settings** tab.
- In the **Link libraries** section, click **Add** and include:
  ```text
  freeglut
  opengl32
  glu32
  ```
- Click **OK** to save the configuration.

#### D. FreeGLUT Runtime DLL
- Copy the FreeGLUT DLL from:
  ```text
  C:\msys64\mingw64\bin\libfreeglut.dll
  ```
  to your project's executable output directory:
  ```text
  YourProject\bin\Debug\
  ```
  > [!NOTE]
  > `libfreeglut.dll` must reside in the same folder as the built `.exe` for the application to launch successfully.

---

### 4. Running the Project / Code Integration

1. Open the project in **Code::Blocks**.
2. In the **Management** side panel, expand the **Sources** folder and ensure `main.cpp` is included.
3. If starting from a new template, replace the default boilerplate with this repository's [main.cpp](file:///d:/East%20Delta%20University/9th%20sem/Graphics%20Lab%20%28GLUT%20project%20%29/main.cpp).
4. Build and run the project using <kbd>F9</kbd> (or go to **Build → Build and run**).
5. The OpenGL graphics window titled *"Moving Cars Project"* will appear with the active animation.

---

### 5. Alternative: GCC / MinGW Command Line (Windows)

Open a terminal or PowerShell in the root folder and run:

```bash
g++ main.cpp -o roadside_animation.exe -I"C:\msys64\mingw64\include" -L"C:\msys64\mingw64\lib" -lfreeglut -lopengl32 -lglu32
```

Launch the executable:

```bash
./roadside_animation.exe
```

---

### 6. Alternative: Linux (Ubuntu / Debian)

Install OpenGL and FreeGLUT development packages:

```bash
sudo apt update
sudo apt install build-essential freeglut3-dev libglu1-mesa-dev libgl1-mesa-dev
```

*(Note: If compiling on Linux, comment out or remove `#include <windows.h>` in `main.cpp`)*

Compile and execute:

```bash
g++ main.cpp -o roadside_animation -lGL -lGLU -lglut
./roadside_animation
```

---

### ⚙️ Technologies Used

- **Language:** C / C++
- **Graphics API:** OpenGL
- **Windowing & Input:** FreeGLUT
- **Environment:** MSYS2 MinGW64
- **IDE:** Code::Blocks
- **Platform:** Windows OS / Linux

---

## 👥 Group Information & Contributors

| Student Name | Student ID | Department | Role / Contribution |
| :--- | :--- | :--- | :--- |
| **[MD Abdullah Al Jamee](https://github.com/mdjameee400)** | *233028912* | CSE | Animation & Road Physics |
| **[Efti Hasan](https://github.com/Efti-Hasan)** | *233031412* | CSE | Environment, Lighting & Sky Cycle |
| **[Chowdhury Shams Intisar](https://github.com/intisar)** | *233030512* | CSE | Vehicle Modeling, Transformations & Interactivity |
