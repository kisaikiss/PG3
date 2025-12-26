#include "TitleScene.h"
#include "Novice.h"
#include "InputManager.h"

void TitleScene::Update() {
	if (InputManager::GetInstance()->GetKeys()[DIK_SPACE] && !InputManager::GetInstance()->GetPreKeys()[DIK_SPACE]) {
		sSceneNo = SCENE::GAME;
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(20, 20, "Title");
}
