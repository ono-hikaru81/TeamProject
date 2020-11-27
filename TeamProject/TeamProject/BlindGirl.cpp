#include "DxLib.h"
#include "BlindGirl.h"
#include "Main.h"

Girl::Girl()
{
	// ステータス
	m_Hp = 2;

	// 位置座標 
	m_PosX = 80;
	m_PosY = WindowHeight - 450;

	// 実行確認
	m_StopExec = true;
	m_WalkExec = false;
	m_JumpExec = false;

	// 画像保存
	m_WaitGraph = NULL;
	m_WalkGraph = NULL;
	m_JumpGraph = NULL;
}

Girl::~Girl()
{
}

void Girl::Move()
{

}

void Girl::Draw()
{
	m_WaitGraph = LoadGraph("res/Character/raf/taikiB_R.png");
	m_WalkGraph = LoadGraph("res/Character/raf/girl_walk1.png");
	m_JumpGraph = LoadGraph("res/Character/raf/junp_R_B.png");

	if (m_StopExec == true)
	{
		DrawRotaGraph(m_PosX, m_PosY, 1.0, 0.0, m_WaitGraph, TRUE);
	}
	else if (m_WalkExec == true)
	{
		DrawRotaGraph(m_PosX, m_PosY, 1.0, 0.0, m_WalkGraph, TRUE);
	}
	else if (m_JumpExec == true)
	{
		DrawRotaGraph(m_PosX, m_PosY, 1.0, 0.0, m_JumpGraph, TRUE);
	}
}
