#ifndef BLINDGIRL
#define BLINDGIRL

#include"Player.h"
#include "../Function/Camera.h"

enum ActionType
{
	Wait,
	Move,
	Jump,
	Damage,
	Death
};

class Girl
{
public:
	// ステータス
	int m_Hp;
	int m_Speed;
	int m_JumpVelocity;

	static const int InitialSpeed = 20;

	// 位置座標
	int m_PosX;
	int m_PosY;
	int m_PrevPosX;
	int m_PrevPosY;
	int m_CenterPosX;
	int m_CenterPosY;

	// 実行確認
	bool m_StopExec;
	bool m_WalkExec;
	bool m_JumpExec;
	bool m_IsFloatingAir;

private:
	// 画像保存
	int m_Girl;

	int m_ActStop;
	int m_ActSpeed;
	int m_WaitIndex;
	int m_WlkIndex;
	int m_DedIndex;
	static const int m_GirlMax = 21;
	static const int m_MotionMax = 4;
	static const int m_DedMotionMax = 3;
	int m_Girls[m_GirlMax];
	int m_WatMotionR[m_MotionMax] = {0,1,0,2};
	int m_WatMotionL[m_MotionMax] = {11,12,11,13};
	int m_WlkMotionR[m_MotionMax] = { 3,4,5,6 };
	int m_WlkMotionL[m_MotionMax] = { 14,15,16,17 };
	int m_DedMotionR[m_DedMotionMax] = {8,9,10};
	int m_DedMotionL[m_DedMotionMax] = {19,20,21};

	ActionType m_CurrentAction;

public:
	Girl();
	virtual ~Girl();

public:

	void Move(Player player);
	void Draw(Player player, Camera camera);

	int GetPosX();
	int GetPosY();
	int GetCenterPosX();
	int GetCenterPosY();
	void InitTexture();
	void ReleaseTexture();
	void AdjustToMapChipEdgePosition(EdgeType contact_edge_, int contact_pos_);
};

#endif // !BLINDGIRL
