#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include"Transform.h"

class GameObject
{
private:
	string m_name;
	Transform* m_transform;
public:
	GameObject();
	GameObject(string name);
	virtual void onStart();
	virtual void onUpdate();
	string getName() { return m_name; }
	Transform* getTransform() { return m_transform; }
};

#endif