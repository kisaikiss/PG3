#pragma once

/// <summary>
/// シングルトンのインプットマネージャ
/// </summary>
class InputManager final {
public:
	static InputManager* GetInstance() {
		static InputManager instance;
		return &instance;
	}

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	char* GetKeys() { return keys_; }
	char* GetPreKeys() { return preKeys_; }
	
	InputManager(const InputManager& obj) = delete;
	InputManager& operator=(const InputManager& obj) = delete;

private:
	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	InputManager() = default;
	~InputManager() = default;
};

