#include "Enemy.h"

namespace {
const float kMoveLimitTop = 100.f;
const float kMoveLimitBottom = 620.f;
}

Enemy::Enemy() {
	position_.x = 950.f;
	position_.y = 320.f;
	width_ = 90.f;
	height_ = 90.f;
	radius_ = 45.f;
	speed_ = 20.f;
}

void Enemy::Update() {
	position_.y += speed_;

	if (position_.y < kMoveLimitTop || position_.y > kMoveLimitBottom) {
		speed_ *= -1.f;
	}
}