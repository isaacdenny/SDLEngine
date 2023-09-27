#ifndef INPUT_H
#define INPUT_H

#include<iostream>
#include<vector>
#include<cctype>
#include<SDL2/SDL.h>

using namespace std;

class Input
{
private:
	static bool m_jump_pressed, m_left_pressed, m_right_pressed;
public:
	static const int SPACE = 32;
	static const int D = 100;
	static const int A = 97;
	static void pollInputs(SDL_Event* event);
	static bool getKeyDown(char k);
};

#endif

