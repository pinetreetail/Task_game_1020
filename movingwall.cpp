#include "DxLib.h"
#include "game.h"
#include "movingwall.h"


namespace
{
	constexpr float kSpeed = 10.0f;
}

MovingWall::MovingWall()
{
	m_color = 0;
	m_isFill = false;

	m_vecX = kSpeed;
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
	//if (!m_isExist) return;

	m_pos.x += m_vecX;
	if (m_pos.x < 0) 
	{
		m_pos.x = 0;
		m_vecX = kSpeed;
	}
	if (m_pos.x > Game::kScreenWidth - m_size.x)
	{
		m_pos.x = Game::kScreenWidth - m_size.x;
		m_vecX = -kSpeed;
	}

	/*
	if (m_pos.x < Game::kWindowMode)
	{
		m_isExist = false;
	}
	*/

	



}

void MovingWall::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, m_color, m_isFill);
}