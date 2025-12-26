#include <iostream>
#include <memory>

using namespace std;

/// <summary>
/// 生物を表す抽象クラス
/// </summary>
class LivingThing {
public:
	/// <summary>
	/// 生物の鳴き声を表す純粋仮想関数
	/// </summary>
	virtual void Cry() = 0;
};

/// <summary>
/// 抽象クラスを継承した犬クラス
/// </summary>
class Dog final : public LivingThing {
public:
	void Cry() override {
		cout << "ワンワン" << endl;
	}
};

/// <summary>
/// 抽象クラスを継承した猫クラス
/// </summary>
class Cat final : public LivingThing {
public:
	void Cry() override {
		cout << "ニャー" << endl;
	}
};

int main() {
	unique_ptr<LivingThing> livingThing[2];

	// 犬と猫を生成
	livingThing[0] = make_unique<Dog>();
	livingThing[1] = make_unique<Cat>();

	//それぞれの鳴き声を出力
	for (int i = 0; i < 2; i++) {
		livingThing[i]->Cry();
	}

	return 0;
}