#ifndef DIRECTIVE_H
#define DIRECTIVE_H

#include"Enhancer.h"
#include"GameEntity.h"
class Directive :
    public Enhancer
{
private:
    void onStart() override;
    void onUpdate() override;
};

#endif 