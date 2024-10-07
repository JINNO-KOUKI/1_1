#pragma once

#include "LinkedList.h"

/// @brief		キュークラス
/// @tparam T	キューに格納する型
/// @detail		内部のデータ管理には、LinkedList<T>を利用しています。
template <typename T>
class Queue
{
public:
	Queue();
	~Queue();

public:
	bool Push(const T& inData);
	bool Pop(T& outData);

private:
	/// @brief データの格納に使用する双方向リスト
	LinkedList<T> _List;
};