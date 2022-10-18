#include "DxLib.h"

#include "game.h"
#include "player.h"
#include "movingwall.h"



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);

	Player player;
	player.setPos(150.0f, 360.0f);
	player.setSize(40.0f);
	player.setColor(GetColor(0, 255, 0));
	player.setFill(true);

	
	MovingWall movingwall;
	movingwall.setPos(1280.0f, 360.0f);
	movingwall.setSize(40.0f, 70.0f);
	movingwall.setColor(GetColor(255, 255, 0));
	movingwall.setFill(false);

	


	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// 画面のクリア
		ClearDrawScreen();

		player.update();
		movingwall.update();

		player.draw();
		movingwall.draw();
		
		// 裏画面を表画面に入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// fpsを６０に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
