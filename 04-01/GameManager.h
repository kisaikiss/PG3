#pragma once
#include <memory>
#include <map>

#include "IScene.h"

/// <summary>
/// ゲームマネジメントクラス
/// </summary>
class GameManager {
public:
	GameManager() = default;
	~GameManager() = default;
	/// <summary>
	/// 初期化処理
	/// </summary>
	void Init();

	/// <summary>
	/// ゲームを走らせる
	/// </summary>
	/// <returns>正常に終了すると0を返す</returns>
	int Run();
private:
	std::map<SCENE, std::unique_ptr<IScene>> sceneMap_;

	SCENE currentSceneNo_;
	SCENE prevSceneNo_;
};

