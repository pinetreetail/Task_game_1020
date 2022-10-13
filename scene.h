#pragma once

#include "Vec2.h"
#include "movingwall.h"
#include "player.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

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

};