#ifndef ENHANCER_H
#define ENHANCER_H

class GameEntity;

class Enhancer
{
private:
	GameEntity* m_entity;
public:
	Enhancer();
	GameEntity* getEntity() { return m_entity; }
	virtual void onStart();
	virtual void onUpdate();
	void setEntity(GameEntity* e);
};

#endif

