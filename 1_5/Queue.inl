#pragma once

/// @brief			�L���[�Ƀf�[�^��ǉ�����
/// @tparam T		�i�[����Ă���f�[�^�^
/// @param inData	�ǉ�����f�[�^
/// @return			����I�� : TRUE, �ُ�I�� : FALSE
/// @details		�L���[�̖����Ƀf�[�^���v�b�V�����܂��B\n
///					�V�K�������̊m�ۂɎ��s�����ۂɁAAssert���������܂��B
template <typename T>
inline bool Queue<T>::Push(const T& inData)
{
	return _List.Insert(_List.ConstEnd(), inData);
}

/// @brief			�L���[�̃f�[�^�����o��
/// @tparam T		�i�[����Ă���f�[�^�^
/// @param outData	���o���f�[�^�̊i�[��
/// @return			����I�� : TRUE, �ُ�I�� : FALSE
/// @detail			�L���[�̐擪����f�[�^���|�b�v���܂��B\n
template <typename T>
inline bool Queue<T>::Pop(T& outData)
{
	// �v�f����0�Ȃ�΁A���������ɏI��
	if (_List.Size() == 0) { return false; }

	// �擪�v�f�̃C�e���[�^������
	LinkedList<T>::ConstIterator it = _List.ConstBegin();

	// �i�[��ϐ��ɁA�擪�v�f����
	outData = *it;

	// ���X�g����A�擪�v�f���폜
	return _List.Remove(it);
}

/// @brief		�i�[����Ă���f�[�^�����擾����
/// @tparam T	�i�[����Ă���f�[�^�^
/// @return		�f�[�^��
/// @detail		���݁A�X�^�b�N�Ɋi�[����Ă���f�[�^�����擾���܂��B
template <typename T>
inline unsigned int Queue<T>::Size() const noexcept
{
	return _List.Size();
}