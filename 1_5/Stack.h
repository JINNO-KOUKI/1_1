#pragma once

#include "LinkedList.h"

/// @brief		�X�^�b�N�N���X
/// @tparam T	�X�^�b�N�Ɋi�[����^
/// @detail		�����̃f�[�^�Ǘ��ɂ́ALinkedList<T>�𗘗p���Ă��܂��B
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
	/// @brief �f�[�^�̊i�[�Ɏg�p����o�������X�g
	LinkedList<T> _List;
};