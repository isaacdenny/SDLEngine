#ifndef ENGINE_H
#define ENGINE_H

#include<iostream>
#include <set>
#include<SDL2/SDL.h>

#include"GameEntity.h"
#include"Enhancer.h"
#include"Input.h"
#include"Shield.h"

using namespace std;

#define WIDTH 640
#define HEIGHT 480
#define FPS 120

class Engine
{
private:
	SDL_Window* m_gameWindow;
	SDL_Renderer* m_renderer;
	SDL_Event* m_event;
	set<GameEntity*> m_entitiesInScene;
public:
	Engine() : m_event(new SDL_Event), m_renderer(), m_gameWindow() {}

	void R_renderObjects()
	{
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		SDL_RenderClear(m_renderer);
		// Draw all gameObjects in the scene
		for (GameEntity* ge : m_entitiesInScene)
		{
			vector<int> location = ge->getLocation();
			vector<int> scale = ge->getScale();
			SDL_Rect rect = { (int)location[0], (int)location[1], scale[0], scale[1] }; // 0 = X, 1 = Y

			SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(m_renderer, &rect);
			SDL_RenderPresent(m_renderer);
		}
	}

	void E_startEntities()
	{
		for (GameEntity* ge : m_entitiesInScene) {
			for (Enhancer* e : ge->getEnhancers()) {
				e->onStart();
			}
		}
	}

	void E_updateEntities()
	{
		for (GameEntity* ge : m_entitiesInScene) {
			for (Enhancer* e : ge->getEnhancers()) {
				e->onUpdate();
			}
		}
	}
	void E_addEntity(GameEntity* e) {
		m_entitiesInScene.insert(e);
	}

	void G_endPlay() {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_gameWindow);
		SDL_Quit();
	}

	void R_buildWindow() {
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "Error initializing SDL: " << SDL_GetError();
			return;
		}
		std::cout << "SDL successfully initialized" << std::endl;

		m_gameWindow = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

		if (!m_gameWindow) {
			std::cout << "Error creating window: " << SDL_GetError();
			G_endPlay();
			return;
		}

		Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
		m_renderer = SDL_CreateRenderer(m_gameWindow, -1, render_flags);
		if (!m_renderer) {
			std::cout << "Error creating renderer: " << SDL_GetError();
			G_endPlay();
			return;
		}
	}

	void G_play() {
		R_buildWindow();
		E_startEntities();
		bool running = true;
		while (running) {

			// TODO: Keep track of deltaTime

			E_updateEntities();
			while (SDL_PollEvent(m_event)) {
				pollInputs(m_event);
				switch (m_event->type) {
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
				}
			}
			R_renderObjects();
			E_delay();
		}
		G_endPlay();
	}
	void E_delay() {
		SDL_Delay(1000 / FPS);
	}
};

#endif

