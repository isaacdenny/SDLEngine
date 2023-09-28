#include "GameEntity.h"

GameEntity::GameEntity(string name) : m_name(name), m_location({ 0, 0, 0 }), m_rotation({ 0, 0, 0 }), m_scale({ 25, 25, 0 })
{
}

void GameEntity::addEnhancer(Enhancer* new_enhancer)
{
	new_enhancer->setEntity(this);
	m_enhancers.insert(new_enhancer);
}


void GameEntity::translate(int x, int y)
{
	m_location[0] += x;
	m_location[1] += y;
}

void GameEntity::translateTo(int x, int y)
{
	m_location[0] = x;
	m_location[1] = y;
}
