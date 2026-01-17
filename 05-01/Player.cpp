#include "Player.h"

Player::Player() : speed_(6.f) {
	position_.x = 200.f;
	position_.y = 320.f;
	width_ = 60.f;
	height_ = 60.f;
}

void Player::MoveRight() {
	position_.x += speed_;
}

void Player::MoveLeft() {
	position_.x -= speed_;
}