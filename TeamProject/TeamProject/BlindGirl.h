#ifndef BLINDGIRL
#define BLINDGIRL

class Girl
{
public:
	// ステータス
	int m_Hp;

	// 位置座標
	int m_PosX;
	int m_PosY;

	// 実行確認
	bool m_StopExec;
	bool m_WalkExec;
	bool m_JumpExec;

private:
	// 画像保存
	int m_WaitGraph;
	int m_WalkGraph;
	int m_JumpGraph;

public:
	Girl();
	virtual ~Girl();

public:
	void Move();
	void Draw();
};

#endif // !BLINDGIRL

