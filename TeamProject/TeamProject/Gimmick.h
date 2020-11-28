
#ifndef GIMMICK_H
#define GIMMICK_H

class Gimmick
{
public:
	int m_TreeDraw;//木の画像保存
	int m_Angle;
	int m_Radian;
	int m_cooltime;

public:
	Gimmick();
	~Gimmick();

public:
	void BridgeMove();
	void BridgeDraw();

public:
	bool CheckHit();
};



#endif // !GIMMICK_H
