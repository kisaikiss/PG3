#include "Player.h"
#include "InputManager.h"
#include "GameScene.h"

#include <Novice.h>

namespace {
const float speed = 10.f;
}

Player::Player(GameScene* gameScene) : gameScene_(gameScene) {
	position_.x = 200.f;
	position_.y = 320.f;
	width_ = 60.f;
	height_ = 60.f;
	velocity_ = {};
}

void Player::Update() {
	InputManager* input = InputManager::GetInstance();

	velocity_.x = 0.f;
	velocity_.y = 0.f;

	if (input->GetKeys()[DIK_W]) velocity_.y -= speed;
	if (input->GetKeys()[DIK_A]) velocity_.x -= speed;
	if (input->GetKeys()[DIK_S]) velocity_.y += speed;
	if (input->GetKeys()[DIK_D]) velocity_.x += speed;



	position_ += velocity_;

	if (input->GetKeys()[DIK_SPACE] && !input->GetPreKeys()[DIK_SPACE]) gameScene_->AddPlayerBullet(position_);

}
