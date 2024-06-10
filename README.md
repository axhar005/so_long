# My 2D Game Project with MLX42

Welcome to the GitHub repository for my 2D game project using the `mlx42` library! My name is Olivier Boucher, and I am a student passionate about game development. This repository contains all the files and resources needed to understand and contribute to my game.

<img src="https://imgur.com/PhHo9TH.png" alt="Main Game Image" width="400">

## Game Description

In this game, you play as a character who must navigate through various levels, avoiding enemies and reaching the exit door. The objective is to collect all the collectables (trees) to unlock the exit door. The game is developed in C and uses the `mlx42` library for graphical rendering.

## Features

- **2D Graphics**: Utilizes the `mlx42` library for 2D graphics rendering.
- **Dynamic Camera System**: Loads and renders only the elements visible on the screen, improving performance.
- **Auto-Tiling System**: Automatically adjusts tiles to fit the surrounding environment seamlessly.
- **Build System**: Allows for easy changes to tiles (blocks).
- **Varied Levels**: Different levels with obstacles and enemie to overcome.

## Camera System

The camera system is designed to load and render only the parts of the level that are visible on the screen. This reduces the load on the CPU and improves overall game performance. Here is an overview of how it works:

- **Position Detection**: The camera follows the player's position and determines which parts of the level need to be rendered.
- **Dynamic Loading**: Elements outside the screen are not loaded, reducing resource usage.

## Build System

The build system allows for easy changes to the game's tiles, which is particularly useful for testing different appearances and visual styles. Each tile (block) has a linking texture that automatically updates when a new tile is placed, making it perfect with the build tool.

<img src="https://imgur.com/cqKfepT.png" alt="Build Image 1" width="400">
<img src="https://imgur.com/tn6lD0D.png" alt="Build Image 2" width="400">
<img src="https://imgur.com/OKwsZ1F.png" alt="Build Image 3" width="400">
<img src="https://imgur.com/7YJlBb8.png" alt="Enemy and Exit Door" width="400">

## How to Play

1. Clone the repository: `git clone https://github.com/axhar005/so_long`
2. Navigate to the project directory: `cd so_long`
3. Install the dependencies for `mlx42` as specified in the [MLX42 repository](https://github.com/codam-coding-college/MLX42), including `glfw`.
4. Compile the project: `make`
5. Launch the game: `./so_long "map path"` (example: `./so_long map/"choose a map"`)

### Additional Controls

- Press `b` for build mode
- Press `o` or `p` to change tiles, and press the right mouse button to place tiles


## Creating Maps

To create a map for the game, simply create a `.ber` file with the following tile designations:

<img src="https://imgur.com/MxRTOyG.png" alt="Map Example" width="200">


- `1` for walls
- `0` for floors
- `E` for the exit
- `C` for collectables (trees)
- `P` for the player

Ensure the player (`P`) is placed in a safe area surrounded by walls (`1`), and that all collectables (`C`) and the exit (`E`) are accessible.

Save your `.ber` file in the appropriate directory, and you can load it using the game's launch command.

## Contact

If you have any questions or would like to discuss the project, feel free to reach out:

- **LinkedIn**: [Olivier Boucher](https://www.linkedin.com/in/olivier-boucher-8047262b7/)

---

Thank you for visiting my 2D game project repository! I am excited to continue developing and sharing my work with you.
