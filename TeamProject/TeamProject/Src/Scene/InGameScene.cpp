﻿#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Function/Input.h"
#include "../Stage/Map.h"
#include "../Character/Player.h"
#include "../Function/Camera.h"
#include "../Character/BlindGirl.h"
#include "../Main.h"
#include "../UI/UI.h"
#include "../Gimmick/Gimmick.h"
#include "../Enemy/Slime.h"
#include "../Enemy/Skull.h"
#include "../Enemy/Orc.h"
#include "../Enemy/Vampire.h"
#include "../Enemy/Wolfman.h"
#include "../Enemy/Dragon.h"

static Camera camera;
static Girl girl;
static Player player;
static Map map;
static UI ui;
static Gimmick gimmick;
static Slime slime;
static Skull skull;
static Orc orc;
static Vampire vampire;
static Wolfman wolfman;
static Dragon dragon;
static StageID nextStage = StageID_1;

InGameScene::InGameScene()
{
	InitTexture();
	player.InitTexture();
	map.InitTexture();
	girl.InitTexture();
	ui.InitTexture();

	gimmick.InitTexture();
	slime.InitTexture();
	skull.InitTexture();
	orc.InitTexture();
	wolfman.InitTexture();
	vampire.InitTexture();
	dragon.InitTexture();
	orc.InitTexture();
	gimmick.GetArray(m_PosxBot,m_PosyBot, m_PosxBri, m_PosyBri,
					 m_PosxTrp, m_PosyTrp, m_PosxRok, m_PosyRok,
					m_PosxBrk, m_PosyBrk);
	
	bottonNumber = 0;
}

InGameScene::~InGameScene()
{
	ReleaseTexture();
}

void InGameScene::Exec()
{
	if (UpdateKeyState() != 0) return;

	camera.Update(player.m_PosX, player.m_Speed);

	
	//slime.SetPos(m_PosxSl);
	player.Move();
	girl.Move(player);
	
	//gimmick.BottonMove(player.m_PosX,player.m_PosY,);
	if (nextStage == StageID_1)
	{
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 0);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 1);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 0);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 1);
		slime.Exec(player.m_PosX,player.m_PosY, 0);
		slime.Exec(player.m_PosX, player.m_PosY, 1);
	}
	else if (nextStage == StageID_2)
	{
//		slime.Move(player.PosX,player.PosY, 1);
//		slime.Move(player.PosX,player.PosY, 2);
//		slime.Move(player.PosX,player.PosY, 3);
		gimmick.RockMove(player.m_PosX, player.m_PosY, 0);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 0);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 1);
	}
	else if (nextStage == StageID_3)
	{
		skull.Draw(camera, m_PosxSk, m_PosySk, 0);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 2);
		gimmick.BridgeMove(player.m_PosX,player.m_PosY ,2);

		//slime.Draw(camera, m_PosxSl, m_PosySl, 4);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 5);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 6);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 7);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 8);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 9);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 10);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 11);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 12);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 13);
		//slime.Draw(camera, m_PosxSl, m_PosySl, 14);
	}
	else if (nextStage == StageID_4)
	{
		gimmick.TrapMove(player.m_PosX, player.m_PosY, 0);
		gimmick.TrapMove(player.m_PosX, player.m_PosY, 1);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 3);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 3);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 1);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 2);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 3);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 4);
	}
	else if (nextStage == StageID_5)
	{
		gimmick.RockMove(player.m_PosX, player.m_PosY, 1);
		gimmick.RockMove(player.m_PosX, player.m_PosY, 2);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 4);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 4);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 15);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 16);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 17);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 0);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 1);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 2);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 3);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 4);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 5);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 6);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 7);
	}
	else if (nextStage == StageID_6)
	{
		gimmick.RockMove(player.m_PosX, player.m_PosY, 3);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 9);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 5);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 6);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 7);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 8);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 9);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 5);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 8);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 9);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 10);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 11);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 12);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 18);
	}
	else if (nextStage == StageID_7)
	{
		gimmick.TrapMove(player.m_PosX, player.m_PosY, 2);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 10);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 11);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 10);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 11);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 13);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 14);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 15);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 6);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 7);
		//wolfman.Exec(camera, wolfman.m_Posx, wolfman.m_Posy);
	}
	else if (nextStage == StageID_8)
	{
		if (player.m_PosX >= 960 || girl.m_PosX >= 960)
		{
			//orc.Exec(camera, m_PosxOc, m_PosyOc, 16);
			//orc.Exec(camera, m_PosxOc, m_PosyOc, 17);
			//orc.Exec(camera, m_PosxOc, m_PosyOc, 18);
			//orc.Exec(camera, m_PosxOc, m_PosyOc, 19);
			//orc.Exec(camera, m_PosxOc, m_PosyOc, 20);
		}

		if (player.m_PosX >= 3840 || girl.m_PosX >= 3840)
		{
			//skull.Exec(camera, m_PosxSk, m_PosySk, 8);
			//skull.Exec(camera, m_PosxSk, m_PosySk, 9);
			//skull.Exec(camera, m_PosxSk, m_PosySk, 10);
			//skull.Exec(camera, m_PosxSk, m_PosySk, 11);
			//skull.Exec(camera, m_PosxSk, m_PosySk, 12);
		}
	}
	else if (nextStage == StageID_9)
	{
		//slime.Exec(camera, m_PosxSl, m_PosySl, 19);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 20);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 21);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 2);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 3);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 4);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 5);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 6);
		gimmick.RockMove(player.m_PosX, player.m_PosY,  4);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 12);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 12);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 21);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 22);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 23);
	}
	else if (nextStage == StageID_10)
	{
	gimmick.BridgeMove(player.m_PosX, player.m_PosY, 13);
	gimmick.BridgeMove(player.m_PosX, player.m_PosY, 14);
	gimmick.BottonMove(player.m_PosX, player.m_PosY, 13);
	gimmick.BottonMove(player.m_PosX, player.m_PosY, 14);
	//slime.Exec(camera, m_PosxSl, m_PosySl, 22);
	//orc.Exec(camera, m_PosxOc, m_PosyOc, 24);
	//orc.Exec(camera, m_PosxOc, m_PosyOc, 25);
	//orc.Exec(camera, m_PosxOc, m_PosyOc, 26);
	//vampire.Exec(camera, vampire.m_Posx, vampire.m_Posy);
	}
	else if (nextStage == StageID_11)
	{
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 7);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 9);
		gimmick.BrockExec(player.m_PosX, player.m_PosY, 8);
		gimmick.BridgeMove(player.m_PosX, player.m_PosY, 15);
		gimmick.BottonMove(player.m_PosX, player.m_PosY, 15);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 13);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 14);
		//skull.Exec(camera, m_PosxSk, m_PosySk, 15);
		//slime.Exec(camera, m_PosxSl, m_PosySl, 23);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 27);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 28);
		//orc.Exec(camera, m_PosxOc, m_PosyOc, 29);
	}
	else if (nextStage == StageID_12)
	{
	//dragon.Exec(camera, 2400, 360);
	}
	/*gimmick.TrapMove();
	gimmick.RockMove();
	slime.Exec();
	skull.Exec();
	orc.Exec(player);
	wolfman.Exec();
	vampire.Exec();
	dragon.Exec();*/

	if (GetKeyStatus(KEY_INPUT_1) == InputState::Pushed)
	{
		nextStage = StageID_1;
	}
	else if (GetKeyStatus(KEY_INPUT_2) == InputState::Pushed)
	{
		nextStage = StageID_2;
	}
	else if (GetKeyStatus(KEY_INPUT_3) == InputState::Pushed)
	{
		nextStage = StageID_3;
	}
	else if (GetKeyStatus(KEY_INPUT_4) == InputState::Pushed)
	{
		nextStage = StageID_4;
	}
	else if (GetKeyStatus(KEY_INPUT_5) == InputState::Pushed)
	{
		nextStage = StageID_5;
	}
	else if (GetKeyStatus(KEY_INPUT_6) == InputState::Pushed)
	{
		nextStage = StageID_6;
	}
	else if (GetKeyStatus(KEY_INPUT_7) == InputState::Pushed)
	{
		nextStage = StageID_7;
	}
	else if (GetKeyStatus(KEY_INPUT_8) == InputState::Pushed)
	{
		nextStage = StageID_8;
	}
	else if (GetKeyStatus(KEY_INPUT_9) == InputState::Pushed)
	{
		nextStage = StageID_9;
	}
	else if (GetKeyStatus(KEY_INPUT_F1) == InputState::Pushed)
	{
		nextStage = StageID_10;
	}
	else if (GetKeyStatus(KEY_INPUT_F2) == InputState::Pushed)
	{
		nextStage = StageID_11;
	}
	else if (GetKeyStatus(KEY_INPUT_F3) == InputState::Pushed)
	{
		nextStage = StageID_12;
	}

	if (GetKeyStatus(KEY_INPUT_RETURN) == InputState::Pushed || player.m_Alive == false)
	{
		SceneManager::SetNextScene(SceneID_Result);
	}

	if (nextStage == StageID_1)
	{
		if (player.m_PosX + 120 >= 4200)
		{
			nextStage = StageID_2;
			InitPos();
		}
	}
	else if (nextStage == StageID_2)
	{
		if (player.m_PosX + 180 >= 4200)
		{
			nextStage = StageID_3;
			InitPos();
		}
	}
	else if (nextStage == StageID_3)
	{
		if (player.m_PosX + 180 >= 3960)
		{
			nextStage = StageID_4;
			InitPos();
		}
	}
	else if (nextStage == StageID_4)
	{
		if (player.m_PosX + 180 >= 5760)
		{
			nextStage = StageID_5;
			InitPos();
		}
	}
	else if (nextStage == StageID_5)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_6;
			InitPos();
		}
	}
	else if (nextStage == StageID_6)
	{
		if (player.m_PosX + 180 >= 6120)
		{
			nextStage = StageID_7;
			InitPos();
		}
	}
	else if (nextStage == StageID_7)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_8;
			InitPos();
		}
	}
	else if (nextStage == StageID_8)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_9;
			InitPos();
		}
	}
	else if (nextStage == StageID_9)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_10;
			InitPos();
		}
	}
	else if (nextStage == StageID_10)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_11;
			InitPos();
		}
	}
	else if (nextStage == StageID_11)
	{
		if (player.m_PosX + 180 >= 7200)
		{
			nextStage = StageID_12;
			InitPos();
		}
	}
	else if (nextStage == StageID_12)
	{
		if (player.m_PosX + 180 >= 4400)
		{
			SceneManager::SetNextScene(SceneID_Result);
		}
	}
}

void InGameScene::Draw()
{
	int BgPosX = camera.ConvertPosXWorldToScreen(0);
	int BgPosY = camera.ConvertPosYWorldToScreen(0);
	int Bg2PosX = camera.ConvertPosXWorldToScreen(1920);
	int Bg3PosX = camera.ConvertPosXWorldToScreen(3840);
	int Bg4PosX = camera.ConvertPosXWorldToScreen(5760);
	int Bg5PosX = camera.ConvertPosXWorldToScreen(480);


	if (nextStage == StageID_1)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass, TRUE);
		map.Data(nextStage);

		gimmick.BridgeDraw(camera, 0);
		gimmick.BridgeDraw(camera, 1);
		gimmick.BottonDraw(camera, 0);
		gimmick.BottonDraw(camera, 1);
		slime.Draw(camera, m_PosxSl,m_PosySl,0);
		
	}
	else if (nextStage == StageID_2)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass, TRUE);
		map.Data(nextStage);

		slime.Draw(camera,m_PosxSl,m_PosySl, 1);
		slime.Draw(camera,m_PosxSl,m_PosySl, 2);

		slime.Draw(camera,m_PosxSl,m_PosySl, 3);
		gimmick.RockDraw(camera,  0);
		gimmick.BrockDraw(camera, 0);
		gimmick.BrockDraw(camera, 1);

	}
	else if (nextStage == StageID_3)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass3, TRUE);
		map.Data(nextStage);

		skull.Draw(camera, m_PosxSk, m_PosySk,0);
		gimmick.BridgeDraw(camera, 2);
		gimmick.BottonDraw(camera, 2);
		slime.Draw(camera,m_PosxSl,m_PosySl, 4);
		slime.Draw(camera,m_PosxSl,m_PosySl, 5);
		slime.Draw(camera,m_PosxSl,m_PosySl, 6);
		slime.Draw(camera,m_PosxSl,m_PosySl, 7);
		slime.Draw(camera,m_PosxSl,m_PosySl, 8);
		slime.Draw(camera,m_PosxSl,m_PosySl, 9);
		slime.Draw(camera,m_PosxSl,m_PosySl,10);
		slime.Draw(camera,m_PosxSl,m_PosySl,11);
		slime.Draw(camera,m_PosxSl,m_PosySl,12);
		slime.Draw(camera,m_PosxSl,m_PosySl,13);
		slime.Draw(camera,m_PosxSl,m_PosySl,14);
	}
	else if (nextStage == StageID_4)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Grass3, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Grass3, TRUE);
		map.Data(nextStage);


		gimmick.TrapDraw(camera,0);
		gimmick.TrapDraw(camera,1);
		gimmick.BottonDraw(camera,3);
		gimmick.BridgeDraw(camera, 3);
		skull.Draw(camera, m_PosxSk, m_PosySk, 1);
		skull.Draw(camera, m_PosxSk, m_PosySk, 2);
		skull.Draw(camera, m_PosxSk, m_PosySk, 3);
		skull.Draw(camera, m_PosxSk, m_PosySk, 4);
	}
	else if (nextStage == StageID_5)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Grass, TRUE);
		DrawGraph(Bg5PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Cave, TRUE);
		map.Data(nextStage);

		gimmick.RockDraw(camera,1);
		gimmick.RockDraw(camera,2);
		gimmick.BottonDraw(camera, 4);//橋追加
		gimmick.BridgeDraw(camera, 4);
		slime.Draw(camera,m_PosxSl, m_PosySl, 15);
		slime.Draw(camera,m_PosxSl,m_PosySl,16);
		slime.Draw(camera,m_PosxSl,m_PosySl,17);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 0);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 1);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 2);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 3);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 4);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 5);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 6);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 7);
	}
	else if (nextStage == StageID_6)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Cave, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		gimmick.RockDraw(camera,3);
		gimmick.BridgeDraw(camera, 9);
		gimmick.BottonDraw(camera, 5);	
		gimmick.BottonDraw(camera, 6);
		gimmick.BottonDraw(camera, 7);
		gimmick.BottonDraw(camera, 8);
		gimmick.BottonDraw(camera,9);
		skull.Draw(camera, m_PosxSk, m_PosySk, 5);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 8);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 9);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 10);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 11);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 12);
		slime.Draw(camera, m_PosxSl, m_PosySl, 18);
	}
	else if (nextStage == StageID_7)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		gimmick.TrapDraw(camera,2);
		gimmick.BridgeDraw(camera, 10);
		gimmick.BridgeDraw(camera, 11);
		gimmick.BottonDraw(camera, 10);
		gimmick.BottonDraw(camera, 11);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 13);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 14);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 15);
		skull.Draw(camera, m_PosxSk, m_PosySk, 6);
		skull.Draw(camera, m_PosxSk, m_PosySk, 7);
		wolfman.Draw(camera, wolfman.m_Posx, wolfman.m_Posy);
	}
	else if (nextStage == StageID_8)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		if (player.m_PosX >= 960 || girl.m_PosX >= 960)
		{
			orc.Draw(camera, m_PosxOc, m_PosyOc, 16);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 17);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 18);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 19);
			orc.Draw(camera, m_PosxOc, m_PosyOc, 20);
		}

		if (player.m_PosX >= 3840 || girl.m_PosX >= 3840)
		{
			skull.Draw(camera, m_PosxSk, m_PosySk, 8);
			skull.Draw(camera, m_PosxSk, m_PosySk, 9);
			skull.Draw(camera, m_PosxSk, m_PosySk, 10);
			skull.Draw(camera, m_PosxSk, m_PosySk, 11);
			skull.Draw(camera, m_PosxSk, m_PosySk, 12);
		}
	}
	else if (nextStage == StageID_9)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		slime.Draw(camera, m_PosxSl, m_PosySl, 19);
		slime.Draw(camera, m_PosxSl, m_PosySl, 20);
		slime.Draw(camera, m_PosxSl, m_PosySl, 21);
		gimmick.BrockDraw(camera,2);
		gimmick.BrockDraw(camera,3);
		gimmick.BrockDraw(camera,4);
		gimmick.BrockDraw(camera,5);
		gimmick.BrockDraw(camera,6);
		gimmick.RockDraw(camera, 4);
		gimmick.BridgeDraw(camera,12);
		gimmick.BottonDraw(camera,12);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 21);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 22);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 23);
	}
	else if (nextStage == StageID_10)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		gimmick.BridgeDraw(camera,13);
		gimmick.BridgeDraw(camera,14);
		gimmick.BottonDraw(camera,13);
		gimmick.BottonDraw(camera,14);
		slime.Draw(camera, m_PosxSl, m_PosySl, 22);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 24);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 25);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 26);
		vampire.Draw(camera, vampire.m_Posx, vampire.m_Posy);
	}
	else if (nextStage == StageID_11)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		gimmick.BrockDraw(camera, 7);
		gimmick.BrockDraw(camera,9);
		gimmick.BrockDraw(camera,8);
		gimmick.BridgeDraw(camera,15);
		gimmick.BottonDraw(camera,15);
		skull.Draw(camera, m_PosxSk, m_PosySk, 13);
		skull.Draw(camera, m_PosxSk, m_PosySk, 14);
		skull.Draw(camera, m_PosxSk, m_PosySk, 15);
		slime.Draw(camera, m_PosxSl, m_PosySl, 23);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 27);
		orc.Draw(camera,m_PosxOc, m_PosyOc, 28);
		orc.Draw(camera, m_PosxOc, m_PosyOc, 29);
	}
	else if (nextStage == StageID_12)
	{
		DrawGraph(BgPosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg2PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg3PosX, BgPosY, Bg_Forest, TRUE);
		DrawGraph(Bg4PosX, BgPosY, Bg_Forest, TRUE);
		map.Data(nextStage);

		dragon.Draw(camera, 2400, 360);
	}

	map.Draw(camera);
	ui.Draw();
	player.Draw(camera);
	girl.Draw(player,camera);
}

void InGameScene::InitTexture()
{
	Bg_Grass = LoadGraph("Res/bg/Bg2.png");
	Bg_Grass2 = LoadGraph("Res/bg/1.png");
	Bg_Grass3 = LoadGraph("Res/bg/2.png");
	Bg_Forest = LoadGraph("Res/bg/forest.png");
	Bg_Forest2 = LoadGraph("Res/bg/forest goal.png");
	Bg_Forest3 = LoadGraph("Res/bg/forest��city.png");
	Bg_Cave = LoadGraph("Res/bg/seamless cave.png");
	Bg_Cave2 = LoadGraph("Res/bg/cave goal.png");
	Bg_GameClear = LoadGraph("Res/bg/gameclear.png");
	Bg_GameOver = LoadGraph("Res/bg/gameover.png");
}

void InGameScene::ReleaseTexture()
{
	DeleteGraph(Bg_Grass);
	DeleteGraph(Bg_Grass2);
	DeleteGraph(Bg_Grass3);
	DeleteGraph(Bg_Forest);
	DeleteGraph(Bg_Forest2);
	DeleteGraph(Bg_Forest3);
	DeleteGraph(Bg_Cave);
	DeleteGraph(Bg_Cave2);

	player.ReleaseTexture();
	map.ReleaseTexture();
	girl.ReleaseTexture();
	ui.ReleaseTexture();

	gimmick.ReleaseTexture();
	slime.ReleaseTexture();
	skull.ReleaseTexture();
	orc.ReleaseTexture();
	wolfman.ReleaseTexture();
	vampire.ReleaseTexture();
	dragon.ReleaseTexture();
	orc.ReleaseTexture();
}

void InGameScene::InitPos()
{
	player.m_PosX = 120;
	player.m_PosY = 780;
	camera.m_PosX = WindowHalfWidth;
	camera.m_PosY = WindowHalfHeight;
}

bool InGameScene::IsEnd() const
{
	return (player.m_Alive == false);
}
