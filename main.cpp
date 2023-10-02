#include"Engine.h"
#include"PlayerController.h"

int main(int argc, char* argv[]) {
	Engine* engine = new Engine();

	GameEntity* p = new GameEntity("Player");
	p->addEnhancer(new PlayerController()); // custom directive example
	p->addEnhancer(new Shield());
	engine->E_addEntity(p);

	engine->G_play();
	return 0;
}