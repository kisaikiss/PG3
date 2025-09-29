#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

int main() {
	//gmailの配列が書かれたファイルを開く
	std::string filePath = "PG3_2025_01_02.txt";
	std::ifstream file(filePath);

	//gmailの単方向リストとファイルの行の変数を宣言
	std::vector<std::string> gmail;
	std::string line;

	//ファイルを,区切りで読み込んでgmail単方向リストへ入れる
	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string token;

		while (std::getline(ss, token, ',')) {
			gmail.push_back(token);
		}

	}
	
	//gmailの中身をソートする
	std::sort(gmail.begin(), gmail.end());

	//gmailの中身を全て表示
	for (auto itr = gmail.begin(); itr != gmail.end(); ++itr) {
		std::cout << *itr << std::endl;
	}
	return 0;
}