#pragma once

#include "LinkedList.h"

/// @brief		�L���[�N���X
/// @tparam T	�L���[�Ɋi�[����^
/// @detail		�����̃f�[�^�Ǘ��ɂ́ALinkedList<T>�𗘗p���Ă��܂��B
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
	/// @brief �f�[�^�̊i�[�Ɏg�p����o�������X�g
	LinkedList<T> _List;
};