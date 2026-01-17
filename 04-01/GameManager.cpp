#include "GameManager.h"
#include "Novice.h"
#include "InputManager.h"
#include "CharacterBase.h"

#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"

using namespace std;

void GameManager::Init() {
	currentSceneNo_ = SCENE::TITLE;
	prevSceneNo_ = SCENE::TITLE;
	sceneMap_[SCENE::TITLE] = make_unique<TitleScene>();
	sceneMap_[SCENE::GAME] = make_unique<GameScene>();
	sceneMap_[SCENE::CLEAR] = make_unique<ClearScene>();
	CharacterBase::Initialize();
}

int GameManager::Run() {

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		InputManager* inputManager = InputManager::GetInstance();

		inputManager->Update();

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneMap_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneMap_[prevSceneNo_]->Fin();
			sceneMap_[currentSceneNo_]->Init();
		}

		sceneMap_[currentSceneNo_]->Update();

		sceneMap_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager->GetPreKeys()[DIK_ESCAPE] == 0 && inputManager->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}
