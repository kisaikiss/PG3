#include <stdio.h>
#include <list>

int main() {
	//1970年の山手線の駅名リストを作成
	std::list<const char*> yamanote{"Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani","Nippori",
	"Tabata","Komagome","Sugamo","Otsuka","Ikebukuro","Mejiro","Takabanobaba","Shin-Okubo","Shinjuku",
	"Yoyogi","Harajuku","Shibuya","Ebisu","Meguro","Gotanda","Osaki","Shinagawa","Tamachi","Hamamatucho","Shimbashi","Yurakucho"};
	
	//1970年の山手線の駅名リストを表示
	printf("1970\n");
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		printf(*itr);
		printf("\n");
	}

	//2019年の山手線の駅名リストを表示
	printf("\n2019\n");
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		//イテレータの要素が田端だった場合、前に西日暮里を追加して表示する
		if (*itr == "Tabata") {
			itr = yamanote.insert(itr,"Nishi-Nippori");
			printf(*itr);
			printf("\n");
			++itr;
		}
		printf(*itr);
		printf("\n");
	}

	//2022年の山手線の駅名リストを表示
	printf("\n2022\n");
	for (auto itr = yamanote.begin(); itr != yamanote.end(); ++itr) {
		//イテレータの要素が田町だった場合、前に高輪ゲートウェイを追加して表示する
		if (*itr == "Tamachi") {
			itr = yamanote.insert(itr, "Takanawa-Gateway");
			printf(*itr);
			printf("\n");
			++itr;
		}
		printf(*itr);
		printf("\n");
	}

	return 0;
}