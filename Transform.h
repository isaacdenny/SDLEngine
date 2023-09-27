#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <string>
#include <vector>
using namespace std;

class Transform
{
private:
	vector<int> m_location;
	vector<int> m_rotation;
	vector<int> m_scale;
public:
	Transform();
	//Transform(vector<int> l, vector<int> r, vector<int> s);
	vector<int> getLocation() { return m_location; }
	vector<int> getRotation() { return m_rotation; }
	vector<int> getScale() { return m_scale; }
	void translate(int x, int y);
	void handleCollision();
};

#endif
