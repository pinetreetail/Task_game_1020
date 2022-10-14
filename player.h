#pragma once

#include "Vec2.h"

class Player 
{
public:
	Player();
	virtual ~Player();

	// �v���C���[�̏�����
	void init();

	// �f�[�^�̐ݒ�
	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x);
	void setColor(unsigned int color) { m_color = color; }
	void setFill(bool fill) { m_isFill = fill; }

	// ����
	void update();
	// �`��
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	bool isDead() const { return m_isDead; }

private:

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	// �~�̔��a
	float m_radius;

	// �J���[
	unsigned int m_color;
	// �h��Ԃ�
	bool m_isFill;

	bool m_isDead;

};