#pragma once

#include <cassert>

// ====================================================================================
//		Node�̎���
// ====================================================================================

// ####### �R���X�g���N�^�Q ##########################

/// @brief		�f�t�H���g�R���X�g���N�^
/// @tparam T	�i�[����f�[�^�^
/// @detail		������Ԃł́APrev��Next�����g�ւ̃|�C���^�������܂�
template <typename T>
inline LinkedList<T>::Node::Node() : _Data(T()), _Prev(this), _Next(this) {}

/// @brief			�R�s�[�R���X�g���N�^
/// @tparam T		�i�[����f�[�^�^
/// @param other	�R�s�[��
template <typename T>
inline LinkedList<T>::Node::Node(const Node& other)
	: _Data(other._Data), _Prev(other._Prev), _Next(other._Next) {}

// ####### ���Z�q�I�[�o�[���[�h�Q ##########################

/// @brief			������r���Z�q
/// @tparam T		�i�[����f�[�^�^
/// @param other	�E�ӗv�f
/// @return			��r����
/// @detail			�m�[�h���̊e�v�f���ꂼ�ꂪ�A���ׂē��ꂩ�ǂ����Ŕ��f���܂�
template <typename T>
inline bool LinkedList<T>::Node::operator==(const Node& other) const noexcept
{
	return (_Prev == other._Prev) && (_Next) == (other._Next) && (_Data) == (other._Data);
}

/// @brief			�񓙉���r���Z�q
/// @tparam T		�i�[����f�[�^�^
/// @param other	�E�ӗv�f
/// @return			��r����
/// @detail			�m�[�h���̊e�v�f���ꂼ��ɑ΂��Ĕ�r���s���A��ł��قȂ��true��Ԃ��܂�
template <typename T>
inline bool LinkedList<T>::Node::operator!=(const Node& other)
{
	return !((_Prev == other._Prev) && (_Next) == (other._Next) && (_Data) == (other._Data));
}


// ====================================================================================
//		ConstIterator�̎���
// ====================================================================================

// ####### �R���X�g���N�^�Q ##########################

/// @brief		�f�t�H���g�R���X�g���N�^
/// @tparam T	�i�[����f�[�^�^
/// @detail		������Ԃł́A�w������֘A�t�����ꂽ���X�g�����݂��Ȃ��A�s���C�e���[�^�ɂȂ�܂��B
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator() : _Target(nullptr), _List(nullptr) {}

/// @brief			�����t���R���X�g���N�^
/// @tparam T		�i�[����f�[�^�^
/// @param target	�C�e���[�^���w�������m�[�h
/// @param list		�֘A�t�����郊�X�g�̃|�C���^
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator(Node* target, const LinkedList<T>* list) : _Target(target), _List(list) {}

/// @brief			�R�s�[�R���X�g���N�^
/// @tparam T		�i�[����f�[�^�^
/// @param other	�R�s�[��
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator(const ConstIterator& other)
{
	_Target = other._Target;
	_List = other._List;
}

/// @brief			���[�u�R���X�g���N�^
/// @tparam T		�i�[����f�[�^�^
/// @param other	�ړ���
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator(ConstIterator&& other) noexcept
{
	_Target = other._Target;
	_List = other._List;

	other._Target = nullptr;
	other._List = nullptr;
}

// ####### ���Z�q�I�[�o�[���[�h�Q ##########################

/// @brief			�R�s�[������Z�q
/// @tparam T		�i�[����f�[�^�^
/// @param other	�R�s�[��
/// @return			�R�s�[���ꂽ�l
template <typename T>
inline LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator=(const LinkedList<T>::ConstIterator& other) noexcept
{
	_Target = other._Target;
	_List = other._List;
	return *this;
}

/// @brief			���[�u������Z�q
/// @tparam	T		�i�[����f�[�^�^
/// @param other	���[�u��
/// @return			���[�u���ꂽ�l
template <typename T>
inline LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator=(ConstIterator&& other) noexcept
{
	_Target = other._Target;
	_List = other._List;

	return *this;
}

/// @brief		�C�e���[�^�̎w���v�f���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		const�v�f
/// @details	���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���\n
///				�E�w���v�f���Ȃ�	
template <typename T>
inline const T& LinkedList<T>::ConstIterator::operator*() const noexcept
{
	assert(_List != nullptr);
	assert(_Target != &_List->_EOL);
	assert(_Target != nullptr);

	return _Target->_Data;
}

/// @brief		�O�u�C���N�������g
/// @tparam T	�i�[����f�[�^�^
/// @return		�C���N�������g���ꂽ��̒l
/// @details	���X�g�̖����Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
///				�E�Q�Ɛ惊�X�g����\n
///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���
template <typename T>
inline LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator++()
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != &_List->_EOL);

	_Target = _Target->_Next;
	return *this;
}

/// @brief		�O�u�f�N�������g
/// @tparam T	�i�[����f�[�^�^
/// @return		�f�N�������g���ꂽ��̒l
/// @details	���X�g�̐擪�Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
///				�E�Q�Ɛ惊�X�g����\n
///				�E�擪�v�f���w���C�e���[�^�ł���
template <typename T>
inline LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator--()
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != _List->_EOL._Next);

	_Target = _Target->_Prev;
	return *this;
}

/// @brief		��u�C���N�������g
/// @tparam T	�i�[����f�[�^�^
/// @return		�C���N�������g�����O�̒l
/// @details	���X�g�̖����Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
///				�E�Q�Ɛ惊�X�g����\n
///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���
template <typename T>
inline LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int)
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != &_List->_EOL);

	ConstIterator tOld = *this;
	++(*this);
	return tOld;
}

/// @brief		��u�f�N�������g
/// @tparam T	�i�[����f�[�^�^
/// @return		�f�N�������g�����O�̒l
/// @details	���X�g�̐擪�Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
///				�E�Q�Ɛ惊�X�g����\n
///				�E�擪�v�f���w���C�e���[�^�ł���
template <typename T>
inline LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int)
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != _List->_EOL._Next);

	ConstIterator tOld = *this;
	--(*this);
	return tOld;
}

/// @brief			������r���Z�q
/// @tparam T		�i�[����f�[�^�^
/// @param other	�E�ӗv�f
/// @return			��r����
/// @detail			�C�e���[�^�̎w�������m�[�h�Ɗ֘A�t�����ꂽ���X�g�����ꂩ���肵�܂�
template <typename T>
inline bool LinkedList<T>::ConstIterator::operator==(const ConstIterator& other) const noexcept
{
	return (_Target == other._Target) && (_List == other._List);
}

/// @brief			�񓙉���r���Z�q
/// @tparam T		�i�[����f�[�^�^
/// @param other	�E�ӗv�f
/// @return			��r����
/// @detail			�C�e���[�^�̎w�������m�[�h�Ɗ֘A�t�����ꂽ���X�g�̂����ꂩ��ȏオ�قȂ邩���肵�܂�
template <typename T>
inline bool LinkedList<T>::ConstIterator::operator!=(const ConstIterator& other) const noexcept
{
	return !(*this == other);
}

// ====================================================================================
//		Iterator�̎���
// ====================================================================================

// ####### �R���X�g���N�^�Q ##########################

/// @brief		�f�t�H���g�R���X�g���N�^
/// @tparam T	�i�[����f�[�^�^
/// @detail		������Ԃł́A�w������֘A�t�����ꂽ���X�g�����݂��Ȃ��A�s���C�e���[�^�ɂȂ�܂��B
template <typename T>
inline LinkedList<T>::Iterator::Iterator() : LinkedList<T>::ConstIterator() {}

/// @brief			�����t���R���X�g���N�^
/// @tparam T		�i�[����f�[�^�^
/// @param target	�C�e���[�^���w�������m�[�h
/// @param list		�֘A�t�����ꂽ���X�g�̃|�C���^
template <typename T>
inline LinkedList<T>::Iterator::Iterator(Node* target, LinkedList<T>* list) : ConstIterator(target, list) {}

/// @brief		ConstIterator����̃R�s�[�R���X�g���N�^
/// @tparam T	�i�[����f�[�^�^
/// @detail		ConstIterator���g�p���ăR�s�[���쐬�ł��Ȃ��悤�ɂ��܂�
template <typename T>
inline LinkedList<T>::Iterator::Iterator(const ConstIterator&) = delete;

// ####### �R���X�g���N�^�Q ##########################

/// @brief		ConstIterator�p�R�s�[������Z�q
/// @tparam T	�i�[����f�[�^�^
/// @detail		ConstIterator����̌Ăяo�����֎~���Ă��܂�
template <typename T>
inline LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator=(const ConstIterator& other) = delete;

/// @brief		�C�e���[�^�̎w���v�f���const�v�f�Ƃ��Ď擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		��const�v�f
/// @details	���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���\n
///				�E�w���v�f���Ȃ�
template <typename T>
inline T& LinkedList<T>::Iterator::operator*() const noexcept
{
	assert(_List != nullptr);
	assert(_Target != &_List->_EOL);
	assert(_Target != nullptr);

	return _Target->_Data;
}


// ====================================================================================
//		LinkedList�̎���
// ====================================================================================

// ####### �R���X�g���N�^�Q ##########################

/// @brief	�f�t�H���g�R���X�g���N�^
/// @tparam T �i�[����f�[�^�^
template <typename T>
inline LinkedList<T>::LinkedList() : _EOL(Node()), _Dummy(&_EOL, this), _Size(0) {}

/// @brief		�f�X�g���N�^
/// @tparam T	�i�[����f�[�^�^
template <typename T>
inline LinkedList<T>::~LinkedList() { Clear(); }

// ####### �����o�֐��Q ##########################

/// @brief		���X�g���̃f�[�^�����擾���܂�
/// @tparam T	�i�[����f�[�^�^
/// @return		���X�g���̃f�[�^��
template <typename T>
inline unsigned int LinkedList<T>::Size() const noexcept { return _Size; }

/// @brief				�V�K�v�f��}������
/// @tparam T			�i�[����f�[�^�^
/// @param inIterator	�}������ꏊ�������C�e���[�^
/// @param inData		�}�����鐬�уf�[�^
/// @return				�f�[�^�̑}���ɐ��������ꍇ��TRUE�A���s�����ꍇ��FALSE
/// @details			�}����̓C�e���[�^�������v�f�̒��O�ł��B\n
///						���ȉ��̏����ɓ��Ă͂܂�ꍇ�A�}��������FALSE�ŏI�����܂��B\n
///						�E�֘A�t�����ꂽ���X�g������\n
///						�E�C�e���[�^�̎w���v�f������\n
///						�E�V�K�������̊m�ۂɎ��s
template <typename T>
inline bool LinkedList<T>::Insert(const ConstIterator& inIterator, const T& inData)
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
	tNewNode->_Data = inData;

	// -- �C�e���[�^�̎w���v�f�̎�O�ɁA�V�K�m�[�h��z�u
	tNewNode->_Prev = tPrev;
	tNewNode->_Next = inIterator._Target;
	tPrev->_Next = tNewNode;
	inIterator._Target->_Prev = tNewNode;

	// �v�f�����X�V
	++_Size;

	return true;
}

/// @brief				�v�f���폜����
/// @tparam T			�i�[����f�[�^�^
/// @param inIterator	�폜�������v�f���w���C�e���[�^
/// @return				�폜�ɐ���������TRUE�A���s������FALSE
/// @details			�C�e���[�^���w�������v�f���폜���āA�O��̗v�f���Ȃ��܂��B\n
///						�폜��A�C�e���[�^�̎w���v�f�͖����ɂȂ�܂��B\n
///						���ȉ��̏����ɓ��Ă͂܂�ꍇ�A����������FALSE�ŏI�����܂��B\n
///						�E�C�e���[�^�̎w���v�f������\n
///						�E�C�e���[�^���_�~�[�m�[�h���w���Ă���\n
///						�E�֘A�t�����ꂽ���X�g������
template <typename T>
inline bool LinkedList<T>::Remove(const ConstIterator& inIterator)
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

		return true;
	}
	else
	{	// �C�e���[�^���L���l�łȂ�

		return false;
	}
}

/// @brief		���X�g�Ɋi�[����Ă��邷�ׂĂ̗v�f���폜����
/// @tparam T	�i�[����f�[�^�^
/// @return		�폜�ɐ���������TRUE�A���s������FALSE
///	@details	�v�f����0�̏ꍇ�A����������TRUE�ŏI�����܂��B\n
///				�v�f���ȏ�ɍ폜���������������ꍇ��A���ׂĂ̗v�f���������J������Ȃ������ꍇ�A\n
///				Assert���������܂��B
template <typename T>
inline bool LinkedList<T>::Clear()
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

	return true;
}

/// @brief		�擪�̃C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�擪�̃C�e���[�^
/// @detail		�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
template <typename T>
inline LinkedList<T>::Iterator LinkedList<T>::Begin() noexcept { return Iterator(_EOL._Next, this); }

/// @brief		�擪�̃C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�擪�̃C�e���[�^
/// @details	�͈�for���ɑΉ������邽�߂̕ʖ��֐��ł��BBegin()�Ɠ���̓�������܂��B
///				�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
template <typename T>
inline LinkedList<T>::Iterator LinkedList<T>::begin() noexcept { return Begin(); }

/// @brief		�����̃C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�����̃C�e���[�^
/// @detail		�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
template <typename T>
inline LinkedList<T>::Iterator LinkedList<T>::End() noexcept { return Iterator(&_EOL, this); }

/// @brief		�����̃C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�����̃C�e���[�^
/// @details	�͈�for���ɑΉ������邽�߂̕ʖ��֐��ł��BEnd()�Ɠ���̓�������܂��B
///				�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
template <typename T>
inline LinkedList<T>::Iterator LinkedList<T>::end() noexcept { return End(); }

/// @brief		�擪�̃R���X�g�C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�擪�̃R���X�g�C�e���[�^
/// @detail		�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
template <typename T>
inline LinkedList<T>::ConstIterator LinkedList<T>::ConstBegin() const noexcept { return ConstIterator(_EOL._Next, this); }

/// @brief		�����̃R���X�g�C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�����̃R���X�g�C�e���[�^
/// @detail		�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
template <typename T>
inline LinkedList<T>::ConstIterator LinkedList<T>::ConstEnd() const noexcept { return ConstIterator(const_cast<Node*>(&_EOL), this); }

/// @brief		���X�g�̐擪�v�f���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		���X�g�̐擪�v�f
/// @details	�v�f������i�[����Ă��Ȃ��ꍇ�́AAssert���������܂��B\n
///				�n�����l�̓R�s�[�ł��B
template <typename T>
inline T LinkedList<T>::Front() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Next->_Data;
}

/// @brief		���X�g�̖����v�f���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		���X�g�̖����v�f
/// @details	�v�f������i�[����Ă��Ȃ��ꍇ�́AAssert���������܂��B\n
///				�n�����l�̓R�s�[�ł��B
template <typename T>
inline T LinkedList<T>::Back() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Prev->_Data;
}

/// @brief		�_�~�[�m�[�h���w���C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�_�~�[�m�[�h���w���C�e���[�^
/// @details	�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B\n
///				End()�ŕԂ����C�e���[�^�Ɠ���ł��B\n
///				���̊֐��R���̂��̈ȊO�ŁA�_�~�[�m�[�h���w���C�e���[�^�ł��邱�Ƃ��z�肳���ۂ�\n
///				����̃C�e���[�^���m�F���邽�߂Ɏg�p���܂��B
template <typename T>
inline const LinkedList<T>::Iterator& LinkedList<T>::Dummy() noexcept { return _Dummy; }

/// @brief		�_�~�[�m�[�h���w���R���X�g�C�e���[�^���擾����
/// @tparam T	�i�[����f�[�^�^
/// @return		�_�~�[�m�[�h���w���R���X�g�C�e���[�^
/// @details	�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B\n
///				ConstEnd()�ŕԂ����R���X�g�C�e���[�^�Ɠ���ł��B\n
///				���̊֐��R���̂��̈ȊO�ŁA�_�~�[�m�[�h���w���R���X�g�C�e���[�^�ł��邱�Ƃ��z�肳���ۂ�\n
///				����̃R���X�g�C�e���[�^���m�F���邽�߂Ɏg�p���܂��B
template <typename T>
inline const LinkedList<T>::ConstIterator& LinkedList<T>::ConstDummy() const noexcept { return static_cast<ConstIterator>(_Dummy); }
