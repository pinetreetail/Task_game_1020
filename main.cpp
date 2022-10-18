#include "DxLib.h"

#include "game.h"
#include "player.h"
#include "movingwall.h"



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�C���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
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
		// ��ʂ̃N���A
		ClearDrawScreen();

		player.update();
		movingwall.update();

		player.draw();
		movingwall.draw();
		
		// ����ʂ�\��ʂɓ���ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// fps���U�O�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
