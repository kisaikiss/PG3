#pragma once
#include <memory>
#include <map>

#include "IScene.h"

class GameManager {
public:
	GameManager() = default;
	~GameManager() = default;
	void Init();
	int Run();
private:
	std::map<SCENE, std::unique_ptr<IScene>> sceneMap_;

	SCENE currentSceneNo_;
	SCENE prevSceneNo_;
};

