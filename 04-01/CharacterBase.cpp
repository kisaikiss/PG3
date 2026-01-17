#include "CharacterBase.h"
#include <Novice.h>

int CharacterBase::sTextureHandle = 0;

void CharacterBase::Initialize() {
	sTextureHandle = Novice::LoadTexture("./NoviceResources/white1x1.png");
}

void CharacterBase::Draw() {
	Vector2Int leftTop = { static_cast<int>(position_.x - width_ / 2.f), static_cast<int>(position_.y - height_ / 2.f) };
	Vector2Int rightTop = { static_cast<int>(position_.x + width_ / 2.f), static_cast<int>(position_.y - height_ / 2.f) };
	Vector2Int leftBottom = { static_cast<int>(position_.x - width_ / 2.f), static_cast<int>(position_.y + height_ / 2.f) };
	Vector2Int rightBottom = { static_cast<int>(position_.x + width_ / 2.f), static_cast<int>(position_.y + height_ / 2.f) };

	Novice::DrawQuad(leftTop.x, leftTop.y, rightTop.x, rightTop.y, leftBottom.x, leftBottom.y, rightBottom.x, rightBottom.y,
		0, 0, 1, 1, sTextureHandle, 0xffffffff);
}