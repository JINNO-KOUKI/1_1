#pragma once

#include "LinkedList.h"

/// @brief		�L���[�N���X
/// @tparam T	�L���[�Ɋi�[����^
/// @detail		�����̃f�[�^�Ǘ��ɂ́ALinkedList<T>�𗘗p���Ă��܂��B
template <typename T>
class Queue
{
public:

	/// @brief	�f�t�H���g�R���X�g���N�^
	/// @detail ����A�����͂���܂���B
	Queue() {}

	/// @brief	�f�X�g���N�^
	/// @detail	����A�����͂���܂���B
	~Queue() {}

public:

	/// @brief			�L���[�Ƀf�[�^��ǉ�����
	/// @tparam T		�i�[����Ă���f�[�^�^
	/// @param inData	�ǉ�����f�[�^
	/// @return			����I�� : TRUE, �ُ�I�� : FALSE
	/// @details		�L���[�̖����Ƀf�[�^���v�b�V�����܂��B\n
	///					�V�K�������̊m�ۂɎ��s�����ۂɁAAssert���������܂��B
	inline bool Push(const T& inData);

	/// @brief			�L���[�̃f�[�^�����o��
	/// @tparam T		�i�[����Ă���f�[�^�^
	/// @param outData	���o���f�[�^�̊i�[��
	/// @return			����I�� : TRUE, �ُ�I�� : FALSE
	/// @detail			�L���[�̐擪����f�[�^���|�b�v���܂��B\n
	inline bool Pop(T& outData);

	/// @brief		�i�[����Ă���f�[�^�����擾����
	/// @tparam T	�i�[����Ă���f�[�^�^
	/// @return		�f�[�^��
	/// @detail		���݁A�X�^�b�N�Ɋi�[����Ă���f�[�^�����擾���܂��B
	inline unsigned int Size() const noexcept;

private:
	/// @brief �f�[�^�̊i�[�Ɏg�p����o�������X�g
	LinkedList<T> _List;
};

#include "Queue.inl"