#include "Player.h"

bool can_jump = true;
float x_vel = 0, y_vel = 0;

Player::Player()
{
}

void Player::onStart()
{
}

void Player::onUpdate() {
	x_vel = (Input::getKeyDown(Input::D) - Input::getKeyDown(Input::A)) * SPEED;
	y_vel += GRAVITY;
	if (Input::getKeyDown(Input::SPACE) && can_jump)
	{
		can_jump = false;
		y_vel = JUMP;
	}
	
	if (!Input::getKeyDown(Input::SPACE) && getTransform()->getLocation()[1] >= 480)
		can_jump = true;
	getTransform()->translate(x_vel / 60, y_vel / 60);
	getTransform()->handleCollision();
}
