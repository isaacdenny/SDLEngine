#ifndef COLLIDER_H
#define COLLIDER_H

#include "Enhancer.h"
#include"GameEntity.h"
#include <vector>
using namespace std;

class Shield :
    public Enhancer
{
private:
	void onStart() override {}
    void onUpdate() override {
		vector<int> pos = getEntity()->getLocation();
		if (pos[0] <= 0)
			getEntity()->translateTo(0, pos[1]);
		if (pos[0] >= 640 + 25)
			getEntity()->translateTo(640 - 25, pos[1]);
		if (pos[1] <= 0)
			getEntity()->translateTo(pos[0], 0);
		if (pos[1] >= 480 + 25)
		{
			getEntity()->translateTo(pos[0], 480 - 25);
		}
	}
};

#endif
