#pragma once

/// @brief			�X�^�b�N�Ƀf�[�^��ǉ�����
/// @tparam T		�i�[����Ă���f�[�^�^
/// @param inData	�ǉ�����f�[�^
/// @return			����I�� : TRUE, �ُ�I�� : FALSE
/// @details		�X�^�b�N�̖����Ƀf�[�^���v�b�V�����܂��B\n
///					�V�K�������̊m�ۂɎ��s�����ۂɁAAssert���������܂��B
template <typename T>
inline bool Stack<T>::Push(const T& inData)
{
	return _List.Insert(_List.ConstEnd(), inData);
}

/// @brief			�X�^�b�N�̃f�[�^�����o��
/// @tparam T		�i�[����Ă���f�[�^�^
/// @param outData	���o���f�[�^�̊i�[��
/// @return			����I�� : TRUE, �ُ�I�� : FALSE
/// @detail			�X�^�b�N�̖�������f�[�^���|�b�v���܂��B
template <typename T>
inline bool Stack<T>::Pop(T& outData)
{
	// �v�f����0�Ȃ�΁A���������ɏI��
	if (_List.Size() == 0) { return false; }

	// �����v�f�̃C�e���[�^������
	LinkedList<T>::ConstIterator it = _List.ConstEnd() - 1;

	// �i�[��ϐ��ɁA�����v�f����
	outData = *it;

	// ���X�g����A�����v�f���폜
	return _List.Remove(it);
}

/// @brief		�i�[����Ă���f�[�^�����擾����
/// @tparam T	�i�[����Ă���f�[�^�^
/// @return		�f�[�^��
/// @detail		���݁A�X�^�b�N�Ɋi�[����Ă���f�[�^�����擾���܂��B
template <typename T>
inline unsigned int Stack<T>::Size() const noexcept
{
	return _List.Size();
}
