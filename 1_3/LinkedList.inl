#pragma once

#include <cassert>
#include "ResultData.h"

/// @brief		����̑o�������X�g�N���X
/// @details	�_�~�[�m�[�h���N�_�ɁA�v�f���z����悤�ɔz�u����Ă��܂��B\n
///				�_�~�[�m�[�h��_Next�͐擪�v�f�A_Prev�͖����v�f�ɂȂ�܂��B
//class LinkedList
//{
//public:
//	/// @brief �f�t�H���g�R���X�g���N�^
//	LinkedList() : _EOL(Node()), _Dummy(&_EOL, this), _ConstDummy(&_EOL, this), _Size(0) {}
//
//	/// @brief �f�X�g���N�^
//	~LinkedList() { Clear(); }
//
//private:
//	/// @brief		���X�g���̈�v�f��\���\����
//	/// @details	MyList�N���X�����ł̂ݎg�p���邽�߁A�A�N�Z�X��private�ł�
//	struct Node
//	{
//		/// @brief ���уf�[�^
//		ResultData _ResultData;
//		/// @brief �O�̃m�[�h�ւ̃|�C���^
//		Node* _Prev;
//		/// @brief ���̃m�[�h�ւ̃|�C���^
//		Node* _Next;
//
//		/// @brief	�f�t�H���g�R���X�g���N�^
//		/// @detail	������Ԃł́APrev��Next�����g�ւ̃|�C���^�������܂�
//		Node() : _ResultData(ResultData()), _Prev(this), _Next(this) {}
//
//		/// @brief			�R�s�[�R���X�g���N�^
//		/// @param other	�R�s�[��
//		Node(const Node& other)
//			: _ResultData(other._ResultData), _Prev(other._Prev), _Next(other._Next) {}
//
//		/// @brief			������r���Z�q
//		/// @param other	�E�ӗv�f
//		/// @return			��r����
//		/// @detail			�m�[�h���̊e�v�f���ꂼ�ꂪ�A���ׂē��ꂩ�ǂ����Ŕ��f���܂�
//		bool operator==(const Node& other) const noexcept
//		{
//			return (_Prev == other._Prev) && (_Next) == (other._Next) && (_ResultData) == (other._ResultData);
//		}
//
//		/// @brief			�񓙉���r���Z�q
//		/// @param other	�E�ӗv�f
//		/// @return			��r����
//		/// @detail			�m�[�h���̊e�v�f���ꂼ��ɑ΂��Ĕ�r���s���A��ł��قȂ��true��Ԃ��܂�
//		bool operator!=(const Node& other)
//		{
//			return !((_Prev == other._Prev) && (_Next) == (other._Next) && (_ResultData) == (other._ResultData));
//		}
//
//	};
//
//public:
//
//	/// @brief MyList�R���e�i�̃C�e���[�^
//	class Iterator : public ConstIterator
//	{
//	public:	// �R���X�g���N�^�Q
//
//		/// @brief	�f�t�H���g�R���X�g���N�^
//		/// @detail	������Ԃł́A�w������֘A�t�����ꂽ���X�g�����݂��Ȃ��A�s���C�e���[�^�ɂȂ�܂��B
//		Iterator() : ConstIterator() {}
//
//		/// @brief			�����t���R���X�g���N�^
//		/// @param target	�C�e���[�^���w�������m�[�h
//		/// @param list		�֘A�t�����ꂽ���X�g�̃|�C���^
//		Iterator(Node* target, LinkedList* list) : ConstIterator(target, list) {}
//
//		/// @brief	ConstIterator����̃R�s�[�R���X�g���N�^
//		/// @detail	ConstIterator���g�p���ăR�s�[���쐬�ł��Ȃ��悤�ɂ��܂�
//		Iterator(const ConstIterator&) = delete;
//
//	public:	// ���Z�q�I�[�o�[���[�h�Q
//
//		/// @brief	ConstIterator�p�R�s�[������Z�q
//		/// @detail	ConstIterator����̌Ăяo�����֎~���Ă��܂�
//		Iterator& operator=(const ConstIterator& other) = delete;
//
//		/// @brief		�C�e���[�^�̎w���v�f���const�v�f�Ƃ��Ď擾����
//		/// @return		��const�v�f
//		/// @details	���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
//		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
//		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���\n
//		///				�E�w���v�f���Ȃ�	
//		ResultData& operator*() const noexcept
//		{
//			assert(_List != nullptr);
//			assert(_Target != &_List->_EOL);
//			assert(_Target != nullptr);
//
//			return _Target->_ResultData;
//		}
//	};

//};
//









		/// @brief	�f�t�H���g�R���X�g���N�^
		/// @detail	������Ԃł́A�w������֘A�t�����ꂽ���X�g�����݂��Ȃ��A�s���C�e���[�^�ɂȂ�܂��B
		LinkedList::ConstIterator::ConstIterator() : _Target(nullptr), _List(nullptr) {}

		/// @brief			�����t���R���X�g���N�^
		/// @param target	�C�e���[�^���w�������m�[�h
		/// @param list		�֘A�t�����郊�X�g�̃|�C���^
		ConstIterator(Node* target, const LinkedList* list) : _Target(target), _List(list) {}

		/// @brief			�R�s�[�R���X�g���N�^
		/// @param other	�R�s�[��
		ConstIterator(const ConstIterator& other)
		{
			_Target = other._Target;
			_List = other._List;
		}

		/// @brief			���[�u�R���X�g���N�^
		/// @param other	�ړ���
		ConstIterator(ConstIterator&& other) noexcept
		{
			_Target = other._Target;
			_List = other._List;

			other._Target = nullptr;
			other._List = nullptr;
		}

	public:	// ���Z�q�I�[�o�[���[�h�Q

		/// @brief			�R�s�[������Z�q
		/// @param other	�R�s�[��
		/// @return			�R�s�[���ꂽ�l
		ConstIterator& operator=(const ConstIterator& other) noexcept
		{
			_Target = other._Target;
			_List = other._List;
			return *this;
		}

		/// @brief			���[�u������Z�q
		/// @param other	���[�u��
		/// @return			���[�u���ꂽ�l
		ConstIterator& operator=(ConstIterator&& other) noexcept
		{
			_Target = other._Target;
			_List = other._List;

			return *this;
		}

		/// @brief		�C�e���[�^�̎w���v�f���擾����
		/// @return		const�v�f
		/// @details	���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���\n
		///				�E�w���v�f���Ȃ�	
		const ResultData& operator*() const noexcept
		{
			assert(_List != nullptr);
			assert(_Target != &_List->_EOL);
			assert(_Target != nullptr);

			return _Target->_ResultData;
		}

		/// @brief		�O�u�C���N�������g
		/// @return		�C���N�������g���ꂽ��̒l
		/// @details	���X�g�̖����Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���
		ConstIterator& operator++()
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != &_List->_EOL);

			_Target = _Target->_Next;
			return *this;
		}

		/// @brief		�O�u�f�N�������g
		/// @return		�f�N�������g���ꂽ��̒l
		/// @details	���X�g�̐擪�Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�擪�v�f���w���C�e���[�^�ł���
		ConstIterator& operator--()
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != _List->_EOL._Next);

			_Target = _Target->_Prev;
			return *this;
		}

		/// @brief		��u�C���N�������g
		/// @return		�C���N�������g�����O�̒l
		/// @details	���X�g�̖����Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���
		ConstIterator operator++(int)
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != &_List->_EOL);

			ConstIterator tOld = *this;
			++(*this);
			return tOld;
		}

		/// @brief		��u�f�N�������g
		/// @return		�f�N�������g�����O�̒l
		/// @details	���X�g�̐擪�Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�擪�v�f���w���C�e���[�^�ł���
		ConstIterator operator--(int)
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != _List->_EOL._Next);

			ConstIterator tOld = *this;
			--(*this);
			return tOld;
		}

		/// @brief			������r���Z�q
		/// @param other	�E�ӗv�f
		/// @return			��r����
		/// @detail			�C�e���[�^�̎w�������m�[�h�Ɗ֘A�t�����ꂽ���X�g�����ꂩ���肵�܂�
		bool operator==(const ConstIterator& other) const noexcept
		{
			return (_Target == other._Target) && (_List == other._List);
		}

		/// @brief			�񓙉���r���Z�q
		/// @param other	�E�ӗv�f
		/// @return			��r����
		/// @detail			�C�e���[�^�̎w�������m�[�h�Ɗ֘A�t�����ꂽ���X�g�̂����ꂩ��ȏオ�قȂ邩���肵�܂�
		bool operator!=(const ConstIterator& other) const noexcept
		{
			return !(*this == other);
		}

	protected:
		/// @brief �C�e���[�^�̎w���Ă���m�[�h
		Node* _Target;
		/// @brief ���g�Ɗ֘A�t�����Ă��郊�X�g�̃|�C���^
		const LinkedList* _List;
	};






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
inline bool LinkedList::Insert(const LinkedList::ConstIterator& inIterator, const ResultData& inResultData)
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
inline bool LinkedList::Remove(const LinkedList::ConstIterator& inIterator)
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

	return true;
}

/// @brief	�擪�̃C�e���[�^���擾����
/// @return	�擪�̃C�e���[�^
/// @detail	�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
inline LinkedList::Iterator LinkedList::Begin() noexcept { return Iterator(_EOL._Next, this); }

/// @brief		�擪�̃C�e���[�^���擾����
/// @return		�擪�̃C�e���[�^
/// @details	�͈�for���ɑΉ������邽�߂̕ʖ��֐��ł��BBegin()�Ɠ���̓�������܂��B
///				�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
inline LinkedList::Iterator LinkedList::begin() noexcept { return Begin(); }

/// @brief	�����̃C�e���[�^���擾����
/// @return �����̃C�e���[�^
/// @detail	�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
inline LinkedList::Iterator LinkedList::End() noexcept { return Iterator(&_EOL, this); }

/// @brief		�����̃C�e���[�^���擾����
/// @return		�����̃C�e���[�^
/// @details	�͈�for���ɑΉ������邽�߂̕ʖ��֐��ł��BEnd()�Ɠ���̓�������܂��B
///				�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
inline LinkedList::Iterator LinkedList::end() noexcept { return End(); }

/// @brief	�擪�̃R���X�g�C�e���[�^���擾����
/// @return �擪�̃R���X�g�C�e���[�^
/// @detail	�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
inline LinkedList::ConstIterator LinkedList::ConstBegin() const noexcept { return ConstIterator(_EOL._Next, this); }

/// @brief	�����̃R���X�g�C�e���[�^���擾����
/// @return �����̃R���X�g�C�e���[�^
/// @detail	�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
inline LinkedList::ConstIterator LinkedList::ConstEnd() const noexcept { return ConstIterator(&_EOL, this); }

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
