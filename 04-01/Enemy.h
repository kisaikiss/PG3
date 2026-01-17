#pragma once
#include "CharacterBase.h"

/// <summary>
/// 敵クラス
/// </summary>
class Enemy :
    public CharacterBase {
public:
    Enemy();
    void Update() override;
private:
    float speed_;
};

