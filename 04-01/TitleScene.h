#pragma once
#include "IScene.h"
class TitleScene :
    public IScene {
public:
    void Init() override {};
    void Fin() override {};
    void Update() override;
    void Draw() override;
private:
};

