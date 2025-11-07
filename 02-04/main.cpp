#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

using namespace std;

int main() {
	srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

	int roll = rand() % 6;

	int userGuess{};
	do {
		cout << "偶数か奇数か(奇数 : 1、偶数 : 0)を入力 : ";
		cin >> userGuess;
		if (userGuess == 1 || userGuess == 0) {
			break;
		} else {
			cout << "無効な入力です。再入力してください" << endl;
		}
	} while (true);

	// 出目と正解か不正解かを出力するラムダ式を入れた関数ポインタ
	function<void(int, int)> showResult = [](int roll, int userGuess) {
		cout << "出目は" << roll << "でした。" << endl;
		if (roll % 2 == userGuess) {
			cout << "正解" << endl;
		} else {
			cout << "不正解" << endl;
		}
		};

	// 指定した時間だけ待つラムダ式を入れた関数ポインタ
	function<void(function<void(int, int)>, int, int, int)> delayReveal = [](function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {
		Sleep(delayMs);
		fn(roll, userGuess);
		};

	delayReveal(showResult, 3000, roll, userGuess);

	return 0;
}