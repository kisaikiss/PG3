#include <Novice.h>

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>

const char kWindowTitle[] = "LE2A_06_コバヤシ_マサト_PG3_06-02";

// 引数で指定したCSVをマップチップデータへ入れる
void loadCSV(const std::string& path, std::vector<std::vector<int>>& mapData) {
	std::ifstream file(path);
	if (!file.is_open()) {
		return;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::vector<int> row;
		std::stringstream ss(line);
		std::string cell;

		while (std::getline(ss, cell, ',')) {
			row.push_back(std::stoi(cell));
		}
		mapData.push_back(row);
	}

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 600, 600);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// 宣言と初期化

	// マップチップデータ
	std::vector<std::vector<int>> mapData;

	// ブロックの大きさ
	const int kBlockSize = 24;

	// ブロックの画像
	int blockGraph = Novice::LoadTexture("./block.png");

	// バックグラウンドループを抜けるかどうか
	bool isExit = false;

	// ミューテックス
	std::mutex mutex;

	// バックグラウンドループ
	std::thread th([&]() {
		while (!isExit) {
			std::lock_guard<std::mutex> lock(mutex);

			// マップ読み込み
			loadCSV("./06-02.csv", mapData);
			isExit = true;
		}
		});


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		//背景の描画
		Novice::DrawBox(0, 0, 600, 600, 0.0f, BLACK, kFillModeSolid);

		//マップの描画
		{
			std::lock_guard<std::mutex> lock(mutex);
			for (size_t y = 0; y < mapData.size(); y++) {
				for (size_t x = 0; x < mapData[y].size(); x++) {
					//もしmap[y][x]が0以外なら
					if (mapData[y][x]) {
						//ブロックを描画する
						Novice::DrawSprite(static_cast<int>(x) * kBlockSize, static_cast<int>(y) * kBlockSize, blockGraph, 1.0f, 1.0f, 0.0f, WHITE);
					}

				}
			}
		}
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	isExit = true;
	th.join();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
