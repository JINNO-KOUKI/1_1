#pragma once

#include <string>

/// @brief ユーザー情報をまとめて管理する構造体
struct UserData
{
	/// @brief スコア
	int _Score;
	/// @brief ユーザー名
	std::string _Name;

	/// @brief コンストラクタ
	UserData() : _Score(0), _Name("null") {}
};