#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(Vector2 position) {
	position_ = position;
	width_ = 30.f;
	height_ = 30.f;
	radius_ = 15.f;
}

void PlayerBullet::Update() {
	const float kSpeed = 20.f;
	position_.x += kSpeed;
}