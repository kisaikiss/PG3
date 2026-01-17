#pragma once
#include "IScene.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"

#include <memory>
#include <list>

class GameScene :
	public IScene {
public:
	void Init() override;
	void Fin() override;
	void Update() override;
	void Draw() override;

	void AddPlayerBullet(Vector2 position);
private:
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
	std::list<std::unique_ptr<PlayerBullet>> playerBullets_;
};

