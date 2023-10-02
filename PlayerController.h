#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include"Directive.h"
using namespace std;

#define JUMP -1200
#define SIZE 25
#define SPEED 600
#define GRAVITY 60

class PlayerController :
    public Directive
{
private:
	bool can_jump = false;
	float x_vel = 0, y_vel = 0;
public:
	void onStart() override {}
    void onUpdate() override {
		x_vel = (getKeyDown(D) - getKeyDown(A)) * SPEED;
		y_vel += GRAVITY;
		if (getKeyDown(SPACE) && can_jump)
		{
			can_jump = false;
			y_vel = JUMP;
		}

		if (!getKeyDown(SPACE) && getEntity()->getLocation()[1] >= 480)
			can_jump = true;
		getEntity()->translate(x_vel / 60, y_vel / 60);
	}
};

#endif

