#include <iostream>

//引数を二つ受け取り、値の小さい方を返す
template <typename T>
T Min(T a, T b) {
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

int main() {
	//int型の変数を二つ宣言と初期化
	int intA = 10;
	int intB = 11;
	//二つのint型の変数をMin関数へ入れて比較し、表示
	std::cout << Min(intA, intB) << std::endl;

	//float型の変数を二つ宣言と初期化
	float floatA = 13.2f;
	float floatB = 11.4f;
	//二つのfloat型の変数をMin関数へ入れて比較し、表示
	std::cout << Min(floatA, floatB) << std::endl;

	//double型の変数を二つ宣言と初期化
	double doubleA = 34.02;
	double doubleB = 12.23;
	//二つのdouble型の変数をMin関数へ入れて比較し、表示
	std::cout << Min(doubleA, doubleB) << std::endl;

	return 0;
}