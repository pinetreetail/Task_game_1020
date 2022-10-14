#pragma once

#include "Vec2.h"

class Player 
{
public:
	Player();
	virtual ~Player();

	// プレイヤーの初期化
	void init();

	// データの設定
	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x);
	void setColor(unsigned int color) { m_color = color; }
	void setFill(bool fill) { m_isFill = fill; }

	// 処理
	void update();
	// 描画
	void draw();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }

	bool isDead() const { return m_isDead; }

private:

	// 表示位置
	Vec2 m_pos;
	// 移動
	Vec2 m_vec;

	// 円の半径
	float m_radius;

	// カラー
	unsigned int m_color;
	// 塗りつぶし
	bool m_isFill;

	bool m_isDead;

};