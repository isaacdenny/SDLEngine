#ifndef PLAYER_H
#define PLAYER_H

#define JUMP -1200
#define SIZE 25
#define SPEED 600
#define GRAVITY 60

#include"Engine.h"

class Player :
    public GameObject
{
public:
    Player();
    void onStart() override;
    void onUpdate() override;
};

#endif

