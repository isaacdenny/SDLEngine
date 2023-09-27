#include "Transform.h"

Transform::Transform() : m_location({0, 0, 0}), m_rotation({ 0, 0, 0 }), m_scale({ 25, 25, 0 })
{
}

//Transform::Transform(vector<int> l, vector<int> r, vector<int> s)
//{
//	m_location = l;
//	m_rotation = r;
//	m_scale = s;
//}

void Transform::translate(int x, int y)
{
	m_location[0] += x;
	m_location[1] += y;
}

void Transform::handleCollision()
{
	if (m_location[0] <= 0)
		m_location[0] = 0;
	if (m_location[0] >= 640 + 25)
		m_location[0] = 640 - 25;
	if (m_location[1] <= 0)
		m_location[1] = 0;
	if (m_location[1] >= 480 + 25)
	{
		m_location[1] = 480 - 25;
	}
}
