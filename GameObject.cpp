#include "GameObject.h"

void GameObject::onStart()
{
}

void GameObject::onUpdate()
{
}

GameObject::GameObject() : m_name()
{
	m_transform = new Transform();
}

GameObject::GameObject(string name) : m_name(name)
{
	m_transform = new Transform();
}
