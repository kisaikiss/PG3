#include <Novice.h>

#include "GameManager.h"

const char kWindowTitle[] = "LE2A_06_コバヤシ_マサト_PG3_04-01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	GameManager game;
	game.Init();
	game.Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
