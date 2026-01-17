#include "GameScene.h"
#include "MathCalculations.h"

using namespace std;

void GameScene::Init() {
	player_ = make_unique<Player>(this);
	enemy_ = make_unique<Enemy>();
}

void GameScene::Fin() {
	player_.reset();
	enemy_.reset();
	playerBullets_.clear();
}

void GameScene::Update() {
	player_->Update();
	enemy_->Update();
	for (auto& bullet : playerBullets_) {
		bullet->Update();

		// 弾と敵の当たり判定
		if (Length(enemy_->GetPosition() - bullet->GetPosition()) <= enemy_->GetRadius() + bullet->GetRadius()) {
			sSceneNo = SCENE::CLEAR;
		}

	}


}

void GameScene::Draw() {
	player_->Draw();
	enemy_->Draw();
	for (auto& bullet : playerBullets_) bullet->Draw();
}

void GameScene::AddPlayerBullet(Vector2 position) {
	playerBullets_.push_back(make_unique<PlayerBullet>(position));
}
