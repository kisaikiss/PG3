#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

using namespace std;

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);
	fn(roll, userGuess);
}

void ShowResult(int roll, int userGuess) {
	cout << "出目は" << roll << "でした。" << endl;
	if (roll % 2 == userGuess) {
		cout << "正解" << endl;
	} else {
		cout << "不正解" << endl;
	}
}

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

	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}