#include <iostream>

using namespace std;

/// <summary>
/// 二つの引数を受け取り、小さい方を返す関数Mimを持ったクラス
/// </summary>
/// <typeparam name="T1">Minに渡す引数の型1</typeparam>
/// <typeparam name="T2">Minに渡す引数の型2</typeparam>
template <typename T1, typename T2>
class MinimumComparison {
public:

	T1 Min(T1 a, T2 b) {
		if (a < static_cast<T1>(b)) {
			return a;
		} else {
			return static_cast<T1>(b);
		}
	}
};

int main() {
	// 両方int型
	MinimumComparison<int, int> minIntInt;
	cout << minIntInt.Min(2, 4) << endl;
	// 両方float型
	MinimumComparison<float, float> minFloatFloat;
	cout << minFloatFloat.Min(2.4f, 4.3f) << endl;
	// 両方double型
	MinimumComparison<double, double> minDoubleDouble;
	cout << minDoubleDouble.Min(20.0, 4.87) << endl;
	/// float型とint型
	MinimumComparison<float, int> minFloatInt;
	cout << minFloatInt.Min(2.0f, 4) << endl;
	/// double型とint型
	MinimumComparison<double, int> minDoubleInt;
	cout << minDoubleInt.Min(2.01, 4) << endl;
	/// double型とfloatt型
	MinimumComparison<double, float> minDoubleFloat;
	cout << minDoubleFloat.Min(2.0, 4.3f) << endl;

	return 0;
}