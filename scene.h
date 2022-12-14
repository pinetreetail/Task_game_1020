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

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

};