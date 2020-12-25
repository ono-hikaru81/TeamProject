#ifndef STAGE_MANAGER_H
#define STAGE_MANAGER_H

#include "../SceneDifinition.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Exec();
	void Draw();

	static void SetNextScene(SceneID next_);

private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;
};

#endif // !STAGE_MANAGER_H
