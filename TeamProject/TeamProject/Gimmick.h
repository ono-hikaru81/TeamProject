
#ifndef BRIDGE_H
#define BRIDGE_H

class Bridge
{
public:
	Bridge();
	~Bridge();

public:
	void Move();
	void Draw();

public:
	bool CheckHit();

public:
	int m_TreeDraw;//木の画像保存
	int m_Angle;
	int m_Radian;
	int m_cooltime;
};



#endif // !BRIDGE_H
