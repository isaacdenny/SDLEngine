#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include<string>
#include<vector>
#include<set>
#include"Enhancer.h"

using namespace std;

class GameEntity
{
private:
	string m_name;
	set<Enhancer*> m_enhancers;
	vector<int> m_location;
	vector<int> m_rotation;
	vector<int> m_scale;
public:
	string getName() { return m_name; }
	set<Enhancer*> getEnhancers() { return m_enhancers; }
	vector<int> getLocation() { return m_location; }
	vector<int> getRotation() { return m_rotation; }
	vector<int> getScale() { return m_scale; }

	GameEntity(string name) : m_name(name), m_location({ 0, 0, 0 }), m_rotation({ 0, 0, 0 }), m_scale({ 25, 25, 0 }) {}

	void addEnhancer(Enhancer* new_enhancer)
	{
		new_enhancer->setEntity(this);
		m_enhancers.insert(new_enhancer);
	}


	void translate(int x, int y)
	{
		m_location[0] += x;
		m_location[1] += y;
	}

	void translateTo(int x, int y)
	{
		m_location[0] = x;
		m_location[1] = y;
	}
};

#endif