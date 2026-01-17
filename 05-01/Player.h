#pragma once
#include "CharacterBase.h"
class Player :
    public CharacterBase {
public:
    Player();

    void Update() override {};

    void MoveRight();
    void MoveLeft();

private:
    float speed_;
};

