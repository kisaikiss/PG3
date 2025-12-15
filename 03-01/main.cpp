#include <iostream>

using namespace std;

/// <summary>
/// 敵クラス
/// </summary>
class Enemy {
public:
	void Update() {
		(this->*func[static_cast<size_t>(phase_)])();
	}

private:
	void Approach() {
		cout << "接近" << endl;
		phase_ = Phase::kShoot;
	}

	void Shoot() {
		cout << "射撃" << endl;
		phase_ = Phase::kWithdrawal;
	}

	void Withdrawal() {
		cout << "離脱" << endl;
	}

	// メンバ関数ポインタのテーブル
	static void (Enemy::*func[])();

	// 敵の状態を表すenum
	enum class Phase {
		kApproach,
		kShoot,
		kWithdrawal,
	};
	Phase phase_ = Phase::kApproach;
};

void (Enemy::*Enemy::func[])() = {
		&Enemy::Approach,
		&Enemy::Shoot,
		&Enemy::Withdrawal
};

int main() {
	Enemy enemy;
	for (uint32_t i = 0; i < 3; i++) {
		enemy.Update();
	}

	return 0;
}