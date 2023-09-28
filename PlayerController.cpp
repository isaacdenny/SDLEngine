#include "PlayerController.h"
#include "Input.h"

#define JUMP -1200
#define SIZE 25
#define SPEED 600
#define GRAVITY 60

bool can_jump = false;
float x_vel = 0, y_vel = 0;

void PlayerController::onStart()
{
}

void PlayerController::onUpdate() {
	x_vel = (Input::getKeyDown(Input::D) - Input::getKeyDown(Input::A)) * SPEED;
	y_vel += GRAVITY;
	if (Input::getKeyDown(Input::SPACE) && can_jump)
	{
		can_jump = false;
		y_vel = JUMP;
	}
	
	if (!Input::getKeyDown(Input::SPACE) && getEntity()->getLocation()[1] >= 480)
		can_jump = true;
	getEntity()->translate(x_vel / 60, y_vel / 60);
}
