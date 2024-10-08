#pragma once

#include "LinkedList.h"

/// @brief		�X�^�b�N�N���X
/// @tparam T	�X�^�b�N�Ɋi�[����^
/// @detail		�����̃f�[�^�Ǘ��ɂ́ALinkedList<T>�𗘗p���Ă��܂��B
template <typename T>
class Stack
{
public:

	/// @brief	�f�t�H���g�R���X�g���N�^
	/// @detail ����A�����͂���܂���B
	Stack() {}

	/// @brief	�f�X�g���N�^
	/// @detail	����A�����͂���܂���B
	~Stack() {}

public:

	/// @brief			�X�^�b�N�Ƀf�[�^��ǉ�����
	/// @tparam T		�i�[����Ă���f�[�^�^
	/// @param inData	�ǉ�����f�[�^
	/// @return			����I�� : TRUE, �ُ�I�� : FALSE
	/// @details		�X�^�b�N�̖����Ƀf�[�^���v�b�V�����܂��B\n
	///					�V�K�������̊m�ۂɎ��s�����ۂɁAAssert���������܂��B
	inline bool Push(const T& inData);

	/// @brief			�X�^�b�N�̃f�[�^�����o��
	/// @tparam T		�i�[����Ă���f�[�^�^
	/// @param outData	���o���f�[�^�̊i�[��
	/// @return			����I�� : TRUE, �ُ�I�� : FALSE
	/// @detail			�X�^�b�N�̖�������f�[�^���|�b�v���܂��B
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

#include "Stack.inl"