#ifndef ENGINE_H
#define ENGINE_H

using namespace std;
#include<iostream>
#include <set>
#include<SDL2/SDL.h>

#include"Input.h"
#include "GameObject.h"

#define WIDTH 640
#define HEIGHT 480
#define FPS 120

class Engine
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event* m_event;
	set<GameObject*> m_gameObjectsInScene;
public:
	Engine();
	bool pollEvents();
	void renderObjects();
	void startObjects();
	void updateObjects();
	void shutDown();
	void delay();
};

#endif

