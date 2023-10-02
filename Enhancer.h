#ifndef ENHANCER_H
#define ENHANCER_H

class GameEntity;

class Enhancer
{
private:
	GameEntity* m_entity;
public:
	Enhancer() : m_entity(nullptr) {}
	GameEntity* getEntity() { return m_entity; }
	virtual void onStart() {}
	virtual void onUpdate() {}
	void setEntity(GameEntity* e) { m_entity = e; }
};

#endif

