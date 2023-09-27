#include "Input.h"

bool Input::m_jump_pressed = false;
bool Input::m_left_pressed = false;
bool Input::m_right_pressed = false;

void Input::pollInputs(SDL_Event* event)
{
	switch (event->type) {
	case SDL_KEYDOWN:
		switch (event->key.keysym.scancode) {
		case SDL_SCANCODE_SPACE:
			m_jump_pressed = true;
			break;
		case SDL_SCANCODE_A:
			m_left_pressed = true;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			m_right_pressed = true;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event->key.keysym.scancode)
		{
		case SDL_SCANCODE_SPACE:
			m_jump_pressed = false;
			break;
		case SDL_SCANCODE_A:
		case SDL_SCANCODE_LEFT:
			m_left_pressed = false;
			break;
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			m_right_pressed = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

bool Input::getKeyDown(char k) // change to string to support const names like "JUMP" or "RIGHT"
{
	k = tolower(k);
	switch (k) {
	case SPACE:
		return m_jump_pressed;
		break;
	case D:
		return m_right_pressed;
		break;
	case A:
		return m_left_pressed;
		break;
	default:
		return false;
		break;
	}
}
