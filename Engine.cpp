#include"Engine.h"
#include"Input.h"
#include"Enhancer.h"
#include"Shield.h"
#include"PlayerController.h"

Engine::Engine() : m_event(new SDL_Event), m_renderer(), m_window()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError();
		return;
	}
	std::cout << "SDL successfully initialized" << std::endl;

	m_window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	if (!m_window) {
		std::cout << "Error creating window: " << SDL_GetError();
		shutDown();
		return;
	}

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	m_renderer = SDL_CreateRenderer(m_window, -1, render_flags);
	if (!m_renderer) {
		std::cout << "Error creating renderer: " << SDL_GetError();
		shutDown();
		return;
	}

	GameEntity* p = new GameEntity("Player");
	p->addEnhancer(new PlayerController()); // custom directive example
	p->addEnhancer(new Shield());
	m_entitiesInScene.insert(p);
}

bool Engine::pollEvents()
{
	// Handle events
	while (SDL_PollEvent(m_event)) {
		Input::pollInputs(m_event);
		switch (m_event->type) {
		case SDL_QUIT:
			return true;
			break;
		default:
			break;
		}
	}

	return false;
}

void Engine::renderObjects()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	// Draw all gameObjects in the scene
	for (GameEntity* ge : m_entitiesInScene)
	{
		vector<int> location = ge->getLocation();
		vector<int> scale = ge->getScale();
		SDL_Rect rect = { (int)location[0], (int)location[1], scale[0], scale[1]}; // 0 = X, 1 = Y

		SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(m_renderer, &rect);
		SDL_RenderPresent(m_renderer);
	}
}

void Engine::startEntities()
{
	for (GameEntity* ge : m_entitiesInScene) {
		for (Enhancer* e : ge->getEnhancers()) {
			e->onStart();
		}
	}
}

void Engine::updateEntities()
{
	for (GameEntity* ge : m_entitiesInScene) {
		for (Enhancer* e : ge->getEnhancers()) {
			e->onUpdate();
		}
	}
}

void Engine::shutDown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Engine::delay() {
	SDL_Delay(1000 / FPS);
}
