#ifndef BLINDGIRL
#define BLINDGIRL

class Girl
{
public:
	Girl();
	virtual ~Girl();

public:
	void Move();
	void Draw();

private:
	int m_walk;
	int m_timer;
	float m_girlposx;
	float m_girlposy;
	float m_speed;
	float m_gravity;
	bool m_floating;
};

#endif // !BLINDGIRL

