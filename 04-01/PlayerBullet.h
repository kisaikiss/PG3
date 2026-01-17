#pragma once
#include "CharacterBase.h"
class PlayerBullet :
    public CharacterBase {
public:
    PlayerBullet(Vector2 position);
    void Update() override;
};

