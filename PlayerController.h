#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include"Directive.h"
using namespace std;

class PlayerController :
    public Directive
{
public:
    void onStart() override;
    void onUpdate() override;
};

#endif

