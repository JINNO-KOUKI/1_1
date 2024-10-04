#pragma once

#include <string>

/// @brief 成績データ
struct ResultData
{
	/// @brief スコア
	int _Score;
	/// @brief ユーザー名
	std::string _Name;

	/// @brief コンストラクタ
	ResultData() : _Score(0), _Name("") {}

	/// @brief 引数付きコンストラクタ
	/// @param inScore 設定するスコア
	/// @param inName 設定するユーザー名
	ResultData(const int& inScore, const std::string& inName)
		: _Score(inScore), _Name(inName) {}

	/// @brief			等価比較演算子オーバーロード
	/// @detail			構造体内の各要素に対して等価比較を行い、すべて一致するかどうかで判断します。
	/// @param other	右辺要素
	/// @return			比較結果
	bool operator==(const ResultData& other) const noexcept
	{
		//if (other == nullptr) { return false; }
		return (_Score == other._Score) && (_Name == other._Name);
	}
};