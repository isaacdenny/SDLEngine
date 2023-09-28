#include"Engine.h"

int main(int argc, char* argv[]) {
	bool running = true;
	static Engine* engine = new Engine();

	engine->startEntities();
	while (running) {
		// Cover last frame
		engine->updateEntities();
		if (engine->pollEvents()) {
			running = false;
		}
		engine->renderObjects();
		engine->delay();
	}

	engine->shutDown();
	return 0;
}