#include "DxLib.h"
#include "player.h"


namespace
{
	// X方向、Y方向の最大速度
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;

	
}

Player::Player()
{
	m_color = 0;
	m_isFill = false;
	
	m_isDead = false;
}

Player::~Player()
{

}

void Player::init()
{

}

void Player::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;
}

void Player::setPos(Vec2 pos)
{
	m_pos = pos;
}

void Player::setSize(float x)
{
	m_radius = x;
}

void Player::update()
{
	if (m_isDead)	return;




	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	if (padState & PAD_INPUT_UP)
	{
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)	m_vec.y = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)	m_vec.y = kSpeedMax;
	}
	else
	{
		m_vec.y *= 0.9f;
	}

	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	else
	{
		m_vec.x *= 0.9f;
	}

	m_pos += m_vec;
}

void Player::draw()
{
	if (m_isDead)	return;

	DrawCircle(m_pos.x, m_pos.y, m_radius, m_color, m_isFill);
}