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
	GameEntity(string name);
	string getName() { return m_name; }
	set<Enhancer*> getEnhancers() { return m_enhancers; }
	void addEnhancer(Enhancer* new_enhancer );
	vector<int> getLocation() { return m_location; }
	vector<int> getRotation() { return m_rotation; }
	vector<int> getScale() { return m_scale; }
	void translate(int x, int y);
	void translateTo(int x, int y);
};

#endif