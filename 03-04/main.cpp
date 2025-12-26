#include <iostream>
#include <numbers>
#include <cmath>
#include <memory>

using namespace std;

/// <summary>
/// 形を表す抽象クラス
/// </summary>
class IShape {
public:
	/// <summary>
	/// 形の面積を計算する
	/// </summary>
	virtual void Size() = 0;

	/// <summary>
	/// 面積の出力
	/// </summary>
	virtual void Draw() = 0;
protected:
	float area_;
};

/// <summary>
/// 円を表すクラス
/// </summary>
class Circle final : public IShape {
public:
	/// <summary>
	/// コンストラクタ。円の半径を指定する。
	/// </summary>
	/// <param name="radius">円の半径</param>
	Circle(float radius) : radius_(radius) {}
	void Size() override {
		area_ = pow(radius_, 2.0f) * numbers::pi_v<float>;
	}
	void Draw() override {
		cout << "Circle : " << area_ << endl;
	}
private:
	float radius_;
};

/// <summary>
/// 矩形を表すクラス
/// </summary>
class Rectangle final : public IShape {
public:
	/// <summary>
	/// コンストラクタ。矩形の大きさを指定する。
	/// </summary>
	/// <param name="width">矩形の幅</param>
	/// <param name="height">矩形の高さ</param>
	Rectangle(float width, float height) :
		width_(width),
		height_(height) {
	}
	void Size() override {
		area_ = height_ * width_;
	}
	void Draw() override {
		cout << "Rectangle : " << area_ << endl;
	}
private:
	float width_;
	float height_;
};


int main() {
	unique_ptr<IShape> shapes[2];

	// 二つの形を生成
	shapes[0] = make_unique<Circle>(12.0f);
	shapes[1] = make_unique<Rectangle>(12.0f, 4.0f);

	// 面積の計算とその結果の出力
	for (int i = 0; i < 2; i++) {
		shapes[i]->Size();
		shapes[i]->Draw();
	}
	return 0;
}