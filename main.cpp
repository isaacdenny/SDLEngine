#include"Engine.h"

int main(int argc, char* argv[]) {
	bool running = true;
	static Engine* engine = new Engine();

	engine->startObjects();
	while (running) {
		// Cover last frame
		engine->updateObjects();
		if (engine->pollEvents()) {
			running = false;
		}
		engine->renderObjects();
		engine->delay();
	}

	engine->shutDown();
	return 0;
}