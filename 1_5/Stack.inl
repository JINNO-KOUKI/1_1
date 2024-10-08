#pragma once

/// @brief			�X�^�b�N�Ƀf�[�^��ǉ�����
/// @tparam T		�i�[����Ă���f�[�^�^
/// @param inData	�ǉ�����f�[�^
/// @return			����I�� : TRUE, �ُ�I�� : FALSE
/// @details		�X�^�b�N�̖����Ƀf�[�^���v�b�V�����܂��B\n
///					�V�K�������̊m�ۂɎ��s�����ۂɁAAssert���������܂��B\n
///					�� �����̃f�[�^�I�ɂ́A���X�g�̐擪�ɑ}�����Ă��܂��B\n
///					   ���o���ۂ��擪������o���Ă��邽�߁A���x������܂���B
template <typename T>
inline bool Stack<T>::Push(const T& inData)
{
	return _List.Insert(_List.ConstBegin(), inData);
}

/// @brief			�X�^�b�N�̃f�[�^�����o��
/// @tparam T		�i�[����Ă���f�[�^�^
/// @param outData	���o���f�[�^�̊i�[��
/// @return			����I�� : TRUE, �ُ�I�� : FALSE
/// @details		�X�^�b�N�̖�������f�[�^���|�b�v���܂��B\n
///					�� �����̃f�[�^�I�ɂ́A���X�g�̐擪������o���Ă��܂��B\n
///					   �f�[�^�̑}�������擪�ɑ}�����Ă���̂ŁA���x������܂���B
template <typename T>
inline bool Stack<T>::Pop(T& outData)
{
	// �v�f����0�Ȃ�΁A���������ɏI��
	if (_List.Size() == 0) { return false; }

	// �擪�v�f�̃C�e���[�^������
	LinkedList<T>::ConstIterator it = _List.ConstBegin();

	// �i�[��ϐ��ɁA�����v�f����
	outData = *it;

	// ���X�g����A�擪�v�f���폜
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
