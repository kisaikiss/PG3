#pragma once
#include "CharacterBase.h"

class GameScene;

/// <summary>
/// プレイヤークラス
/// </summary>
class Player :
    public CharacterBase {
public:
    Player(GameScene* gameScene);
    void Update() override;
private:
    Vector2 velocity_; // 速度
    GameScene* gameScene_; // 弾を発射するために使う
};

