#ifndef INPUT_H
#define INPUT_H

static bool jump_pressed, left_pressed, right_pressed;
const int SPACE = 32;
const int D = 100;
const int A = 97;

static void pollInputs(SDL_Event* event)
{
	switch (event->type) {
	case SDL_KEYDOWN:
		switch (event->key.keysym.scancode) {
		case SDL_SCANCODE_SPACE:
			jump_pressed = true;
			break;
		case SDL_SCANCODE_A:
			left_pressed = true;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			right_pressed = true;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event->key.keysym.scancode)
		{
		case SDL_SCANCODE_SPACE:
			jump_pressed = false;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			left_pressed = false;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			right_pressed = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

static bool getKeyDown(char k) // change to string to support const names like "JUMP" or "RIGHT"
{
	k = tolower(k);
	switch (k) {
	case SPACE:
		return jump_pressed;
		break;
	case D:
		return right_pressed;
		break;
	case A:
		return left_pressed;
		break;
	default:
		return false;
		break;
	}
}

#endif