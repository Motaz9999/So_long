# So_long - 42 Amman Project

![Score](https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42)
![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge)
![Testing](https://img.shields.io/badge/Testing-%20%20Valgrind-orange?style=for-the-badge)

## 🎮 Introduction

**So_long** is a small 2D game project created as part of the 42 curriculum. The goal is to build a graphical game using the **MiniLibX** library, where the player collects items and escapes the map while avoiding enemies.

This project goes beyond the basics by implementing **Bonus Features** such as sprite animation, enemy logic, and an on-screen HUD.

I achieved a score of **125/100**, demonstrating robust logic, clean code, and advanced error handling.

---

## 🌟 Bonus Features Implementation

I successfully implemented the bonus part of the project, adding significant complexity to the game engine:

### 1. Sprite Animation
Instead of static images, the game features animated Collectibles (Coins) and Player movements.
*   **Logic:** I used `mlx_loop_hook` to create a frame timer. Every 2000 cycles, the game updates the `current_frame` index.
*   **Rendering:** The `render_game` function dynamically selects the texture (`collectible[0]` to `collectible[3]`) based on the current frame state to create a smooth spinning effect.

### 2. Enemies (`Z`)
The map supports a new character type: **Enemies**.
*   **Parsing:** The map parser was updated to accept the character `Z`.
*   **Collision:** If the player moves into a tile occupied by `Z`, the game triggers the `enemy_touch` function, printing "You Lose!" and closing the game immediately.

### 3. On-Screen Move Counter
Instead of only printing moves to the shell, the game displays the move count directly on the window.
*   **Implementation:** Using `mlx_string_put` inside the render loop, the move count is converted to a string (`ft_itoa`) and drawn on the top-left corner of the screen in white (`0x00FFFFFF`).

---

## 🛠️ How It Works (Core Mechanics)

### 1. The Engine (MiniLibX)
The game utilizes **MiniLibX**, the 42 school's graphical library. I implemented a complete game loop that handles:
*   **Window Management:** Creating and destroying windows cleanly.
*   **Event Handling:** Listening for key presses (WASD/Arrows) and window close events (`X` button).
*   **Rendering:** Drawing images (sprites) to the window buffer using `mlx_put_image_to_window`.

### 2. Map Parsing & Validation
The core logic resides in the map parser (`src/make_map/` and `bonus/make_map/`). It strictly validates `.ber` files:
*   **Rectangularity:** Checks that every row has the exact same width.
*   **Walls:** Ensures the map is completely enclosed by walls (`1`).
*   **Pathfinding (Flood Fill):** I implemented a recursive **Flood Fill algorithm** to verify that the Player (`P`) can actually reach all Collectibles (`C`) and the Exit (`E`). If the path is blocked, the game refuses to start.

### 3. Memory Management
A critical part of this project was ensuring **0 memory leaks**.
*   Every `malloc` is protected.
*   If an error occurs (invalid map, missing file, allocation failure), a custom error handler frees all previously allocated memory (grids, images, structs) before exiting.
*   The `Get Next Line` utility is optimized to prevent static variable leaks.

---

## 🧪 The "Ultimate" Test Suite

To ensure perfection, I went beyond the standard requirements and implemented an automated **Unit Testing Suite** using **GoogleTest (C++)**.

**Note:** *I utilized AI assistance to architect this advanced testing framework to simulate edge cases that are manually impossible to trigger.*

### What makes this test suite special?
1.  **Mocking MiniLibX:** Since CI/CD environments and terminals don't have screens, we created "Fake" versions of `mlx_init` and `mlx_new_window`. This allows the logic to be tested without needing a GUI.
2.  **Malloc Torture Test:** This is the most extreme test. The test runner wraps the system `malloc` function. It runs the map parser hundreds of times, forcing `malloc` to fail at the 1st call, then the 2nd, then the 3rd, and so on.
    *   **Goal:** To prove that if the system runs out of memory at *any* specific millisecond, the game will catch it, free previous allocations, and exit without a Segfault or Leak.
3.  **Valgrind Integration:** The test suite runs inside Valgrind to verify that `Heaps are freed` and `No leaks are possible`.

---

## 📥 Installation

### 1. Prerequisites (Linux)
You need `make`, `gcc`, and the X11 development libraries for MiniLibX.

```bash
sudo apt-get update
sudo apt-get install build-essential libx11-dev libxext-dev libbsd-dev
```

### 2. Compile the Game
Clone the repo and compile the mandatory or bonus version.

```bash
# Clone
git clone https://github.com/Motaz9999/So_long so_long
cd so_long

# Compile Mandatory (Basic Game)
make

# Compile Bonus (Animations, Enemies, HUD)
make bonus
```

---

## 🕹️ How to Play

### 1. Run the Game
Execute the program by passing a valid map file as an argument:

```bash
# Run Mandatory
./so_long map/valid_map.ber

# Run Bonus (if compiled with make bonus)
./so_long_bonus map/valid_map.ber
```

### 2. Controls
Use the keyboard to control the main character:

| Key | Action |
| :--- | :--- |
| **W** or **⬆️** | Move Up |
| **S** or **⬇️** | Move Down |
| **A** or **⬅️** | Move Left |
| **D** or **➡️** | Move Right |
| **ESC** or **Click X** | Close the game cleanly |

---

## ⚙️ Running the Automated Tests

I created a custom C++ test suite using **GoogleTest** to verify logic and memory safety without needing a graphical environment.

### 1. Install Dependencies
You need CMake, Valgrind, and a C++ compiler:
```bash
sudo apt-get install cmake g++ valgrind
```

### 2. Build and Run
Navigate to the test directory, build the suite, and run it with Valgrind to ensure perfection:

```bash
# 1. Go to the test folder
cd tests

# 2. Build the tests (creates the executable)
mkdir -p build && cd build
cmake ..
make

# 3. Run the Ultimate Test
# This runs logic checks AND the "Malloc Torture Test"
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --error-exitcode=42 \
         ./run_tests
```

### Expected Output
You should see green text indicating all tests passed and a Valgrind summary stating:
> **"All heap blocks were freed -- no leaks are possible"**

---

## 📂 Project Structure

Here is the breakdown of the source code organization:

```text
.
├── bonus/              # Bonus source code (Animation, Enemy, HUD logic)
│   ├── animate/        # Sprite loop hook logic
│   ├── make_input/     # Bonus input handling
│   ├── make_map/       # Bonus map validation
│   └── make_textures/  # Loading arrays of textures
├── src/                # Mandatory source code
│   ├── make_map/       # Map parsing, validation, and Flood Fill logic
│   ├── make_input/     # Key hooks and player movement logic
│   ├── make_render/    # Graphics rendering and game loop
│   ├── make_textures/  # Image and XPM loading
│   └── includes/       # Header files (so_long.h)
├── libft/              # Custom C library (Linked list, strings, etc.)
├── get_next_line/      # Utility to read map files line-by-line
├── minilibx-linux/     # The graphics library
├── map/                # Collection of valid and invalid .ber maps
├── textures/           # Game assets (Player, Wall, Collectible, etc.)
└── tests/              # GoogleTest integration and Mock MLX library
```

---

**Author:** moodeh - intra
**Campus:** 42 Amman