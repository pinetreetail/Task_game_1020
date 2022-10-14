#pragma once

#include "Vec2.h"
#include "movingwall.h"
#include "player.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void init();

	void update();

	void draw();

private:

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

};