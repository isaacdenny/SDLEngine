#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include <set>
#include<SDL2/SDL.h>

#include"GameEntity.h"

using namespace std;

#define WIDTH 640
#define HEIGHT 480
#define FPS 120

class Engine
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event* m_event;
	set<GameEntity*> m_entitiesInScene;
public:
	Engine();
	bool pollEvents();
	void renderObjects();
	void startEntities();
	void updateEntities();
	void shutDown();
	void delay();
};

#endif

