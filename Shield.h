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
    void handleCollisions();
    void onStart() override;
    void onUpdate() override;
};

#endif
