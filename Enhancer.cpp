#include"Enhancer.h"
#include"GameEntity.h"

Enhancer::Enhancer() : m_entity(nullptr)
{
}
void Enhancer::onStart()
{
}

void Enhancer::onUpdate()
{
}

void Enhancer::setEntity(GameEntity* e)
{
	m_entity = e;
}

