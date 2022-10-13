#include "DxLib.h"
#include "movingwall.h"


MovingWall::MovingWall()
{
	m_color = 0;
	m_isFill = false;
}

MovingWall::~MovingWall()
{

}

void MovingWall::init()
{

}

void MovingWall::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;
}

void MovingWall::setPos(Vec2 pos)
{
	m_pos = pos;
}

void MovingWall::setSize(float x, float y)
{
	m_size.x = x;
	m_size.y = y;
}

void MovingWall::update()
{









}

void MovingWall::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, m_color, m_isFill);
}