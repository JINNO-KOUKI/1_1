#pragma once

#include "LinkedList.h"

/// @brief		スタッククラス
/// @tparam T	スタックに格納する型
/// @detail		内部のデータ管理には、LinkedList<T>を利用しています。
template <typename T>
class Stack
{
public:
	Stack();
	~Stack();

public:
	bool Push(const T& inData);
	bool Pop(T& outData);

	unsigned int Size();

private:
	/// @brief データの格納に使用する双方向リスト
	LinkedList<T> _List;
};