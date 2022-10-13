#pragma once

#include "Vec2.h"

class MovingWall
{
public:
	MovingWall();
	virtual ~MovingWall();

	// �v���C���[�̏�����
	void init();

	// �f�[�^�̐ݒ�
	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x, float y);
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

	// �T�C�Y
	Vec2 m_size;

	// �ړ�
	Vec2 m_vec;

	// �J���[
	unsigned int m_color;
	// �h��Ԃ�
	bool m_isFill;

};
