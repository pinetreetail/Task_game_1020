#pragma once

#include "Vec2.h"

class MovingWall
{
public:
	MovingWall();
	virtual ~MovingWall();

	// プレイヤーの初期化
	void init();

	// データの設定
	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x, float y);
	void setColor(unsigned int color) { m_color = color; }
	void setFill(bool fill) { m_isFill = fill; }

	// 処理
	void update();
	// 描画
	void draw();

	// 情報の取得
	Vec2 getPos() const { return m_pos; }


private:

	// 表示位置
	Vec2 m_pos;

	// サイズ
	Vec2 m_size;

	// 移動
	Vec2 m_vec;

	// カラー
	unsigned int m_color;
	// 塗りつぶし
	bool m_isFill;

};
