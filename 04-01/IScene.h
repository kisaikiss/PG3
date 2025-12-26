#pragma once
enum class SCENE {
	TITLE,
	GAME,
	CLEAR,
};

class IScene {
public:
	virtual ~IScene() = default;

	virtual void Init() = 0;
	virtual void Fin() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	SCENE GetSceneNo() { return sSceneNo; }
protected:
	static SCENE sSceneNo;
};

