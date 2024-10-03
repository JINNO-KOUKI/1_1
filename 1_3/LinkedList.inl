#pragma once

#include <cassert>
#include "ResultData.h"



/// @brief ���X�g���̃f�[�^�����擾���܂�
/// @return ���X�g���̃f�[�^��
inline unsigned int LinkedList::Size() const noexcept { return _Size; }

/// @brief				�V�K�v�f��}������
/// @param inIterator	�}������ꏊ�������C�e���[�^
/// @param inResultData �}�����鐬�уf�[�^
/// @return				�f�[�^�̑}���ɐ��������ꍇ��TRUE�A���s�����ꍇ��FALSE
/// @details			�}����̓C�e���[�^�������v�f�̒��O�ł��B\n
///						���ȉ��̏����ɓ��Ă͂܂�ꍇ�A�}��������FALSE�ŏI�����܂��B\n
///						�E�֘A�t�����ꂽ���X�g������\n
///						�E�C�e���[�^�̎w���v�f������\n
///						�E�V�K�������̊m�ۂɎ��s
inline bool LinkedList::Insert(const Iterator& inIterator, const ResultData& inResultData)
{
	// ���g�Ɗ֘A�̖����C�e���[�^�̏ꍇ�́A���������ɏI��
	if (inIterator._List != this) { return false; }
	// �C�e���[�^�������l���w���ꍇ���A�I��
	if (inIterator._Target == nullptr) { return false; }

	// �V�K�m�[�h���쐬
	Node* tNewNode = new (std::nothrow) Node();
	if (tNewNode == nullptr)
	{	// �������m�ۂɎ��s

		return false;
	}

	// �}���ӏ��̒��O�v�f���擾
	Node* tPrev = inIterator._Target->_Prev;

	// ���уf�[�^��ݒ�
	tNewNode->_ResultData = inResultData;

	// -- �C�e���[�^�̎w���v�f�̎�O�ɁA�V�K�m�[�h��z�u
	tNewNode->_Prev = tPrev;
	tNewNode->_Next = inIterator._Target;
	tPrev->_Next = tNewNode;
	inIterator._Target->_Prev = tNewNode;


	// �V�K�m�[�h���擪�v�f��������
	if (tNewNode == _EOL._Next)
	{
		// -- �C�e���[�^�̍X�V
		_Begin = Iterator(_EOL._Next, this);
		_ConstBegin = ConstIterator(_EOL._Next, this);
	}
	// �v�f�����X�V
	++_Size;

	return true;
}

/// @brief				�v�f���폜����
/// @param inIterator	�폜�������v�f���w���C�e���[�^
/// @return				�폜�ɐ���������TRUE�A���s������FALSE
/// @details			�C�e���[�^���w�������v�f���폜���āA�O��̗v�f���Ȃ��܂��B\n
///						�폜��A�C�e���[�^�̎w���v�f�͖����ɂȂ�܂��B\n
///						���ȉ��̏����ɓ��Ă͂܂�ꍇ�A����������FALSE�ŏI�����܂��B\n
///						�E�C�e���[�^�̎w���v�f������\n
///						�E�C�e���[�^���_�~�[�m�[�h���w���Ă���\n
///						�E�֘A�t�����ꂽ���X�g������
inline bool LinkedList::Remove(const Iterator& inIterator)
{
	// ���g�Ɗ֘A�̖����C�e���[�^�̏ꍇ�́A���������ɏI��
	if (inIterator._List != this) { return false; }

	if (inIterator._Target != nullptr && inIterator._Target != &_EOL)
	{	// �C�e���[�^�̎w���v�f���L���l(null�ł��Ȃ��A�_�~�[�ł��Ȃ�)�������ꍇ

		Node* tPrev = inIterator._Target->_Prev;
		Node* tNext = inIterator._Target->_Next;

		// �폜�v�f�̑O����Ȃ���
		tPrev->_Next = tNext;
		tNext->_Prev = tPrev;

		// �폜�v�f��delete
		delete inIterator._Target;

		// �v�f�����X�V
		--_Size;
		// -- �C�e���[�^���X�V
		_Begin = Iterator(_EOL._Next, this);
		_ConstBegin = ConstIterator(_EOL._Next, this);

		return true;
	}
	else
	{	// �C�e���[�^���L���l�łȂ�

		return false;
	}
}

/// @brief		���X�g�Ɋi�[����Ă��邷�ׂĂ̗v�f���폜����
/// @return		�폜�ɐ���������TRUE�A���s������FALSE
///	@details	�v�f����0�̏ꍇ�A����������TRUE�ŏI�����܂��B\n
///				�v�f���ȏ�ɍ폜���������������ꍇ��A���ׂĂ̗v�f���������J������Ȃ������ꍇ�A\n
///				Assert���������܂��B
inline bool LinkedList::Clear()
{
	// �v�f��0��������I��
	if (!_Size) { return true; }

	// �Ō���̃m�[�h���擾
	Node* tNode = _EOL._Prev;

	// -- �_�~�[�m�[�h���w�������܂ŌJ��Ԃ�
	while (true)
	{
		// ��O�̗v�f�Ɉړ�
		tNode = tNode->_Prev;

		// ���̗v�f���폜
		delete tNode->_Next;

		// �T�C�Y���X�V
		--_Size;

		// �T�C�Y�����̒l�ɂȂ����ꍇ�AAssert�𔭐�������
		assert(_Size >= 0);

		// �_�~�[�m�[�h���w����������I��
		if (tNode == &_EOL) { break; }
	}
	// �z��ʂ�S�v�f�̍폜���������Ă��Ȃ��ꍇ�AAssert�𔭐�������
	assert(_Size == 0);

	// -- �����o�ϐ��̏�����
	_EOL._Prev = &_EOL;
	_EOL._Next = &_EOL;
	_Begin = Iterator(&_EOL, this);
	_ConstBegin = ConstIterator(&_EOL, this);

	return true;
}

/// @brief	�擪�̃C�e���[�^���擾����
/// @return	�擪�̃C�e���[�^
/// @detail	�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
inline LinkedList::Iterator LinkedList::Begin() noexcept { return _Begin; }

/// @brief	�����̃C�e���[�^���擾����
/// @return �����̃C�e���[�^
/// @detail	�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
inline LinkedList::Iterator LinkedList::End() noexcept { return _End; }

/// @brief	�擪�̃R���X�g�C�e���[�^���擾����
/// @return �擪�̃R���X�g�C�e���[�^
/// @detail	�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
inline LinkedList::ConstIterator LinkedList::ConstBegin() const noexcept { return _ConstBegin; }

/// @brief	�����̃R���X�g�C�e���[�^���擾����
/// @return �����̃R���X�g�C�e���[�^
/// @detail	�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
inline LinkedList::ConstIterator LinkedList::ConstEnd() const noexcept { return _ConstEnd; }

/// @brief		���X�g�̐擪�v�f���擾����
/// @return		���X�g�̐擪�v�f
/// @details	�v�f������i�[����Ă��Ȃ��ꍇ�́AAssert���������܂��B\n
///				�n�����l�̓R�s�[�ł��B
inline ResultData LinkedList::Front() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Next->_ResultData;
}

/// @brief		���X�g�̖����v�f���擾����
/// @return		���X�g�̖����v�f
/// @details	�v�f������i�[����Ă��Ȃ��ꍇ�́AAssert���������܂��B\n
///				�n�����l�̓R�s�[�ł��B
inline ResultData LinkedList::Back() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Prev->_ResultData;
}

/// @brief		�_�~�[�m�[�h���w���C�e���[�^���擾����
/// @return		�_�~�[�m�[�h���w���C�e���[�^
/// @details	�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B\n
///				End()�ŕԂ����C�e���[�^�Ɠ���ł��B\n
///				���̊֐��R���̂��̈ȊO�ŁA�_�~�[�m�[�h���w���C�e���[�^�ł��邱�Ƃ��z�肳���ۂ�\n
///				����̃C�e���[�^���m�F���邽�߂Ɏg�p���܂��B
inline const LinkedList::Iterator& LinkedList::Dummy() noexcept { return _Dummy; }

/// @brief		�_�~�[�m�[�h���w���R���X�g�C�e���[�^���擾����
/// @return		�_�~�[�m�[�h���w���R���X�g�C�e���[�^
/// @details	�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B\n
///				ConstEnd()�ŕԂ����R���X�g�C�e���[�^�Ɠ���ł��B\n
///				���̊֐��R���̂��̈ȊO�ŁA�_�~�[�m�[�h���w���R���X�g�C�e���[�^�ł��邱�Ƃ��z�肳���ۂ�\n
///				����̃R���X�g�C�e���[�^���m�F���邽�߂Ɏg�p���܂��B
inline const LinkedList::ConstIterator& LinkedList::ConstDummy() const noexcept { return _ConstDummy; }


