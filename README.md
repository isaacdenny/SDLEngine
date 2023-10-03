# SDL Engine

![SDL Engine Logo](link_to_your_logo.png)

Welcome to SDL Engine, a simple C++ game engine framework built using libSDL2.0. This project is a personal portfolio project designed to showcase my skills in game engine development. It provides a wide range of features, including hardware-accelerated rendering, debug shape drawing, continuous or discrete collision detection, sprite parsing & animation, and much more.

## Features

- **Hardware-Accelerated Rendering**: Utilize the full potential of your hardware for smooth and efficient game graphics.

- **Debug Shape Drawing**: Easily visualize and debug collision shapes and hitboxes within your game.

- **Collision Detection**: Choose between continuous or discrete collision detection methods, depending on your game's requirements.

- **Sprite Parsing & Animation**: Effortlessly load and animate sprites to bring your game characters and objects to life.

- **Audio Support**: Integrate sound effects and background music into your games with ease.

- **Input Handling**: Manage user input efficiently, including keyboard, mouse, and game controller support.

- **Cross-Platform**: Develop games for multiple platforms, thanks to the cross-platform capabilities of libSDL2.0.

## Getting Started

To get started with SDL Engine, follow these steps:

### Building from source

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/isaacdenny/SDLEngine.git
   ```
2. Build the solution with Visual Studio
3. Link the .lib file in the output folders to your project and include the SDLEngine header files
4. Create a driver file like this one to get started:
   ```
   #include<SDLEngine/Engine.h>
   
   int main() {
   	Engine engine;
   	GameEntity p("Player");
   	p.addEnhancer(new Shield);
   	p.addEnhancer(new SimplePlayerController);
   	engine.E_addEntity(&p);
   
   	engine.G_play();
   
   	return 0;
   }
   ```
   
