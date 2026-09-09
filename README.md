# 🚗 Car Dodger — Console Game in C

A simple **console-based Car Dodger game** written in **C**. Control your car, dodge falling obstacles, and try to achieve the highest score possible!

The game runs in the Windows console and uses keyboard controls for movement.

---

## 🎮 Game Preview

```text
###########################
#                         #
#          7              #
#                         #
#     3                   #
#                         #
#                  8      #
#                         #
#             V           #
###########################

Score: 12
```

**V** = Your Car
**0–9** = Falling Obstacles
**#** = Road Boundary

---

## ✨ Features

* 🚗 Control the car in four directions
* 🎯 Dodge randomly generated obstacles
* 🔢 Obstacles are represented using numbers `0–9`
* 🏆 Score increases whenever an obstacle successfully passes
* ⚡ Game speed increases every 5 points
* 🎲 Random obstacle positions and symbols
* 🛑 Collision detection
* ❌ Quit the game anytime using `Q`
* 💻 Designed for Windows console

---

## 🕹️ Controls

| Key     | Action     |
| ------- | ---------- |
| `A`     | Move Left  |
| `D`     | Move Right |
| `W`     | Move Up    |
| `S`     | Move Down  |
| `Q`     | Quit Game  |
| `ENTER` | Start Game |

Both uppercase and lowercase controls are supported.

---

## 📋 Requirements

To compile and run this game, you need:

* Windows OS
* A C compiler such as:

  * GCC / MinGW
  * Code::Blocks
  * Dev-C++
  * Visual Studio
* Windows console

### Required Libraries

The program uses:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
```

`conio.h` and `windows.h` are Windows-specific, so this version is **not directly compatible with Linux/macOS**.

---

## ⚙️ How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/car-dodger.git
```

### 2. Open the Project

Open the `.c` file in your preferred C IDE or terminal.

### 3. Compile Using GCC

```bash
gcc car_dodger.c -o car_dodger
```

### 4. Run

```bash
car_dodger.exe
```

---

## 🧠 How the Game Works

The game uses a simple game loop:

```text
        ┌──────────────┐
        │   Start Game │
        └──────┬───────┘
               ↓
        ┌──────────────┐
        │     Draw     │
        └──────┬───────┘
               ↓
        ┌──────────────┐
        │    Input     │
        └──────┬───────┘
               ↓
        ┌──────────────┐
        │    Logic     │
        └──────┬───────┘
               ↓
        ┌──────────────┐
        │ Game Over?   │
        └───┬──────┬───┘
            │ No   │ Yes
            ↓      ↓
       Game Loop  End
```

### Game Loop

The program repeatedly performs:

1. **Draw** the road, car, and obstacles.
2. **Check keyboard input**.
3. **Move obstacles downward**.
4. **Check for collisions**.
5. **Respawn obstacles** that leave the screen.
6. **Increase the score**.
7. **Increase game speed** as the score gets higher.

---

## 🚧 Obstacles

The game supports up to **4 obstacles** at a time:

```c
#define MAX_OBSTACLES 4
```

Each obstacle contains:

```c
typedef struct {
    int x;
    int y;
    char symbol;
} Obstacle;
```

* `x` → Horizontal position
* `y` → Vertical position
* `symbol` → Obstacle character

Obstacle positions are randomly generated using:

```c
rand() % ROAD_WIDTH
```

---

## 🏆 Scoring System

Every time an obstacle moves past the bottom of the screen:

```text
Obstacle passes
      ↓
Score +1
      ↓
Every 5 points
      ↓
Game speed increases
```

The game starts with:

```c
game_speed = 100;
```

After every 5 points, the delay is reduced by 5 milliseconds until it reaches a minimum of 25 ms.

This makes the game progressively harder.

---

## 💥 Collision Detection

The game checks whether the player's car and an obstacle occupy the same position:

```c
if (obstacles[i].x == car_x &&
    obstacles[i].y == car_y) {
    game_over = 1;
}
```

Collision detection happens both **before and after obstacle movement** to prevent the car from passing through an obstacle between frames.

---

## 🗂️ Project Structure

A simple project can be organized as:

```text
car-dodger/
│
├── car_dodger.c
├── README.md
└── LICENSE
```

---

## 🔧 Customization

You can easily modify the game constants.

### Change Road Width

```c
#define ROAD_WIDTH 25
```

For example:

```c
#define ROAD_WIDTH 35
```

### Change Screen Height

```c
#define SCREEN_HEIGHT 20
```

### Add More Obstacles

```c
#define MAX_OBSTACLES 4
```

For example:

```c
#define MAX_OBSTACLES 6
```

### Change Starting Speed

```c
int game_speed = 100;
```

Lower values make the game faster.

---

## 🚀 Possible Future Improvements

Some ideas for expanding the game:

* 🚘 Add different car designs
* 🛣️ Add road lane markings
* ❤️ Add multiple lives
* 🥇 Add a high-score system
* 🔊 Add sound effects
* 🎨 Add colors using Windows console APIs
* 💥 Add explosion animation
* 📈 Add multiple difficulty levels
* ⏸️ Add a pause option
* 🏎️ Add different vehicle types
* 🌧️ Add weather effects
* 🎵 Add background music
* 🖥️ Improve screen rendering to remove flickering

---

## 🐛 Known Limitations

* This version is designed specifically for **Windows**.
* `system("cls")` may cause visible screen flickering.
* The game uses a simple text-based graphical interface.
* The keyboard input relies on `<conio.h>`.
* The console window should be large enough to display the game properly.

---

## 📚 Concepts Demonstrated

This project is useful for practicing fundamental C programming concepts:

* Variables
* Constants
* Structures
* Arrays
* Functions
* Loops
* Conditional statements
* Random number generation
* Keyboard input
* Collision detection
* Game loops
* Basic timing
* Console rendering

---

## 👨‍💻 Author

**Priyanshu Sinha**

A beginner-friendly C console game project created for learning and experimentation.

---

## ⭐ Contributing

Feel free to fork this project and experiment with new features.

If you improve the game, you can submit a pull request with your changes.

---

## 📄 License

This project is open-source and available for educational and personal use.
