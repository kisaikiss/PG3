#include "ClearScene.h"
#include "InputManager.h"

#include <Novice.h>

void ClearScene::Update() {
	if (InputManager::GetInstance()->GetKeys()[DIK_SPACE] && !InputManager::GetInstance()->GetPreKeys()[DIK_SPACE]) {
		sSceneNo = SCENE::TITLE;
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(20, 20, "Clear");
}
