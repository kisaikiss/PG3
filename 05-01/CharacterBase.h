#pragma once
#include "MathStructs.h"

/// <summary>
/// キャラクター基底クラス
/// </summary>
class CharacterBase {
public:
	/// <summary>
	/// キャラクター全体の初期化処理
	/// </summary>
	static void Initialize();
	virtual ~CharacterBase() = default;

	/// <summary>
	/// 更新処理の純粋仮想関数
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

protected:
	Vector2 position_;

	// 描画用の幅
	float width_;
	// 描画用の高さ
	float height_;

	// テクスチャハンドル
	static int sTextureHandle;
};

