#pragma once

#include <cassert>

/// @brief		����̑o�������X�g�N���X
/// @tparam T	�i�[����f�[�^�^
/// @details	�_�~�[�m�[�h���N�_�ɁA�v�f���z����悤�ɔz�u����Ă��܂��B\n
///				�_�~�[�m�[�h��_Next�͐擪�v�f�A_Prev�͖����v�f�ɂȂ�܂��B
template <typename T>
class LinkedList
{
public:
	/// @brief �f�t�H���g�R���X�g���N�^
	LinkedList();

	/// @brief �f�X�g���N�^
	~LinkedList();

private:
	/// @brief		���X�g���̈�v�f��\���\����
	/// @details	MyList�N���X�����ł̂ݎg�p���邽�߁A�A�N�Z�X��private�ł�
	struct Node
	{
		/// @brief		�i�[�f�[�^
		/// @tparam T	�i�[����Ă���f�[�^�^
		T _Data;
		/// @brief �O�̃m�[�h�ւ̃|�C���^
		Node* _Prev;
		/// @brief ���̃m�[�h�ւ̃|�C���^
		Node* _Next;

		/// @brief	�f�t�H���g�R���X�g���N�^
		/// @detail	������Ԃł́APrev��Next�����g�ւ̃|�C���^�������܂�
		Node();

		/// @brief			�R�s�[�R���X�g���N�^
		/// @param other	�R�s�[��
		Node(const Node& other);

		/// @brief			������r���Z�q
		/// @param other	�E�ӗv�f
		/// @return			��r����
		/// @detail			�m�[�h���̊e�v�f���ꂼ�ꂪ�A���ׂē��ꂩ�ǂ����Ŕ��f���܂�
		bool operator==(const Node& other) const noexcept;

		/// @brief			�񓙉���r���Z�q
		/// @param other	�E�ӗv�f
		/// @return			��r����
		/// @detail			�m�[�h���̊e�v�f���ꂼ��ɑ΂��Ĕ�r���s���A��ł��قȂ��true��Ԃ��܂�
		bool operator!=(const Node& other);

	};

public:
	/// @brief LinkedList�̃R���X�g�C�e���[�^
	class ConstIterator
	{
		/// @brief		LinkedList�ւ̃t�����h������`
		/// @tparam T	�i�[����Ă���f�[�^�^
		friend LinkedList<T>;	// �����o�ϐ��ւ̃A�N�Z�X�́A�T�u�N���X��LinkedList�N���X����̂݉\�Ƃ��Ă��܂�

	public:	// �R���X�g���N�^�Q

		/// @brief	�f�t�H���g�R���X�g���N�^
		/// @detail	������Ԃł́A�w������֘A�t�����ꂽ���X�g�����݂��Ȃ��A�s���C�e���[�^�ɂȂ�܂��B
		ConstIterator();

		/// @brief			�����t���R���X�g���N�^
		/// @tparam T		�i�[����Ă���f�[�^�^
		/// @param target	�C�e���[�^���w�������m�[�h
		/// @param list		�֘A�t�����郊�X�g�̃|�C���^
		ConstIterator(Node* target, const LinkedList<T>* list);

		/// @brief			�R�s�[�R���X�g���N�^
		/// @param other	�R�s�[��
		ConstIterator(const ConstIterator& other);

		/// @brief			���[�u�R���X�g���N�^
		/// @param other	�ړ���
		ConstIterator(ConstIterator&& other) noexcept;

	public:	// ���Z�q�I�[�o�[���[�h�Q

		/// @brief			�R�s�[������Z�q
		/// @param other	�R�s�[��
		/// @return			�R�s�[���ꂽ�l
		ConstIterator& operator=(const ConstIterator& other) noexcept;

		/// @brief			���[�u������Z�q
		/// @param other	���[�u��
		/// @return			���[�u���ꂽ�l
		ConstIterator& operator=(ConstIterator&& other) noexcept;

		/// @brief		�C�e���[�^�̎w���v�f���擾����
		/// @tparam T	�i�[����Ă���f�[�^�^
		/// @return		const�v�f
		/// @details	���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���\n
		///				�E�w���v�f���Ȃ�
		const T& operator*() const noexcept;

		/// @brief		�O�u�C���N�������g
		/// @return		�C���N�������g���ꂽ��̒l
		/// @details	���X�g�̖����Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���
		ConstIterator& operator++();

		/// @brief		�O�u�f�N�������g
		/// @return		�f�N�������g���ꂽ��̒l
		/// @details	���X�g�̐擪�Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�擪�v�f���w���C�e���[�^�ł���
		ConstIterator& operator--();

		/// @brief		��u�C���N�������g
		/// @return		�C���N�������g�����O�̒l
		/// @details	���X�g�̖����Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���
		ConstIterator operator++(int);

		/// @brief		��u�f�N�������g
		/// @return		�f�N�������g�����O�̒l
		/// @details	���X�g�̐擪�Ɍ������āA���̃C�e���[�^���w�������i�߂܂�\n
		///				���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�Q�Ɛ惊�X�g����\n
		///				�E�擪�v�f���w���C�e���[�^�ł���
		ConstIterator operator--(int);

		/// @brief			������r���Z�q
		/// @param other	�E�ӗv�f
		/// @return			��r����
		/// @detail			�C�e���[�^�̎w�������m�[�h�Ɗ֘A�t�����ꂽ���X�g�����ꂩ���肵�܂�
		bool operator==(const ConstIterator& other) const noexcept;

		/// @brief			�񓙉���r���Z�q
		/// @param other	�E�ӗv�f
		/// @return			��r����
		/// @detail			�C�e���[�^�̎w�������m�[�h�Ɗ֘A�t�����ꂽ���X�g�̂����ꂩ��ȏオ�قȂ邩���肵�܂�
		bool operator!=(const ConstIterator& other) const noexcept;

	protected:
		/// @brief �C�e���[�^�̎w���Ă���m�[�h
		Node* _Target;
		/// @brief		���g�Ɗ֘A�t�����Ă��郊�X�g�̃|�C���^
		/// @tparam T	�i�[����Ă���f�[�^�^
		const LinkedList<T>* _List;
	};

	/// @brief LinkedList�̃C�e���[�^
	class Iterator : public ConstIterator
	{
	public:	// �R���X�g���N�^�Q

		/// @brief	�f�t�H���g�R���X�g���N�^
		/// @detail	������Ԃł́A�w������֘A�t�����ꂽ���X�g�����݂��Ȃ��A�s���C�e���[�^�ɂȂ�܂��B
		Iterator();

		/// @brief			�����t���R���X�g���N�^
		/// @tparam T		�i�[����Ă���f�[�^�^
		/// @param target	�C�e���[�^���w�������m�[�h
		/// @param list		�֘A�t�����ꂽ���X�g�̃|�C���^
		Iterator(Node* target, LinkedList<T>* list);

		/// @brief	ConstIterator����̃R�s�[�R���X�g���N�^
		/// @detail	ConstIterator���g�p���ăR�s�[���쐬�ł��Ȃ��悤�ɂ��܂�
		Iterator(const ConstIterator&) = delete;

	public:	// ���Z�q�I�[�o�[���[�h�Q

		/// @brief	ConstIterator�p�R�s�[������Z�q
		/// @detail	ConstIterator����̌Ăяo�����֎~���Ă��܂�
		Iterator& operator=(const ConstIterator& other) = delete;

		/// @brief		�C�e���[�^�̎w���v�f���const�v�f�Ƃ��Ď擾����
		/// @tparam T	�i�[����Ă���f�[�^�^
		/// @return		��const�v�f
		/// @details	���ȉ��̏����ɓ��Ă͂܂�ꍇ�AAssert���������܂�\n
		///				�E�֘A�t�����ꂽ���X�g���Ȃ�\n
		///				�E�_�~�[�m�[�h���w���C�e���[�^�ł���\n
		///				�E�w���v�f���Ȃ�
		T& operator*() const noexcept;
	};

	/// @brief ���X�g���̃f�[�^�����擾���܂�
	/// @return ���X�g���̃f�[�^��
	inline unsigned int Size() const noexcept;

	/// @brief				�V�K�v�f��}������
	/// @tparam T			�i�[����Ă���f�[�^�^
	/// @param inIterator	�}������ꏊ�������C�e���[�^
	/// @param inData		�}�����鐬�уf�[�^
	/// @return				�f�[�^�̑}���ɐ��������ꍇ��TRUE�A���s�����ꍇ��FALSE
	/// @details			�}����̓C�e���[�^�������v�f�̒��O�ł��B\n
	///						���ȉ��̏����ɓ��Ă͂܂�ꍇ�A�}��������FALSE�ŏI�����܂��B\n
	///						�E�֘A�t�����ꂽ���X�g������\n
	///						�E�C�e���[�^�̎w���v�f������\n
	///						�E�V�K�������̊m�ۂɎ��s
	inline bool Insert(const ConstIterator& inIterator, const T& inData);

	/// @brief				�v�f���폜����
	/// @param inIterator	�폜�������v�f���w���C�e���[�^
	/// @return				�폜�ɐ���������TRUE�A���s������FALSE
	/// @details			�C�e���[�^���w�������v�f���폜���āA�O��̗v�f���Ȃ��܂��B\n
	///						�폜��A�C�e���[�^�̎w���v�f�͖����ɂȂ�܂��B\n
	///						���ȉ��̏����ɓ��Ă͂܂�ꍇ�A����������FALSE�ŏI�����܂��B\n
	///						�E�C�e���[�^�̎w���v�f������\n
	///						�E�C�e���[�^���_�~�[�m�[�h���w���Ă���\n
	///						�E�֘A�t�����ꂽ���X�g������
	inline bool Remove(const ConstIterator& inIterator);

	/// @brief		���X�g�Ɋi�[����Ă��邷�ׂĂ̗v�f���폜����
	/// @return		�폜�ɐ���������TRUE�A���s������FALSE
	///	@details	�v�f����0�̏ꍇ�A����������TRUE�ŏI�����܂��B\n
	///				�v�f���ȏ�ɍ폜���������������ꍇ��A���ׂĂ̗v�f���������J������Ȃ������ꍇ�A\n
	///				Assert���������܂��B
	inline bool Clear();

	template <typename Key>
	inline void Sort(const bool& inIsAsc, Key T::* key);

	/// @brief	�擪�̃C�e���[�^���擾����
	/// @return	�擪�̃C�e���[�^
	/// @detail	�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
	inline Iterator Begin() noexcept;

	/// @brief		�擪�̃C�e���[�^���擾����
	/// @return		�擪�̃C�e���[�^
	/// @details	�͈�for���ɑΉ������邽�߂̕ʖ��֐��ł��BBegin()�Ɠ���̓�������܂��B
	///				�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
	inline Iterator begin() noexcept;

	/// @brief	�����̃C�e���[�^���擾����
	/// @return �����̃C�e���[�^
	/// @detail	�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
	inline Iterator End() noexcept;

	/// @brief		�����̃C�e���[�^���擾����
	/// @return		�����̃C�e���[�^
	/// @details	�͈�for���ɑΉ������邽�߂̕ʖ��֐��ł��BEnd()�Ɠ���̓�������܂��B
	///				�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B
	inline Iterator end() noexcept;

	/// @brief	�擪�̃R���X�g�C�e���[�^���擾����
	/// @return �擪�̃R���X�g�C�e���[�^
	/// @detail	�v�f��������݂��Ȃ��ꍇ�́A�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
	inline ConstIterator ConstBegin() const noexcept;

	/// @brief	�����̃R���X�g�C�e���[�^���擾����
	/// @return �����̃R���X�g�C�e���[�^
	/// @detail	�����Ȃ�ꍇ�ł��A��Ƀ_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B
	inline ConstIterator ConstEnd() const noexcept;

	/// @brief		���X�g�̐擪�v�f���擾����
	/// @tparam T	�i�[����Ă���f�[�^�^
	/// @return		���X�g�̐擪�v�f
	/// @details	�v�f������i�[����Ă��Ȃ��ꍇ�́AAssert���������܂��B\n
	///				�n�����l�̓R�s�[�ł��B
	inline T Front() const noexcept;

	/// @brief		���X�g�̖����v�f���擾����
	/// @tparam T	�i�[����Ă���f�[�^�^
	/// @return		���X�g�̖����v�f
	/// @details	�v�f������i�[����Ă��Ȃ��ꍇ�́AAssert���������܂��B\n
	///				�n�����l�̓R�s�[�ł��B
	inline T Back() const noexcept;

	/// @brief		�_�~�[�m�[�h���w���C�e���[�^���擾����
	/// @return		�_�~�[�m�[�h���w���C�e���[�^
	/// @details	�_�~�[�m�[�h���w���C�e���[�^��ԋp���܂��B\n
	///				End()�ŕԂ����C�e���[�^�Ɠ���ł��B\n
	///				���̊֐��R���̂��̈ȊO�ŁA�_�~�[�m�[�h���w���C�e���[�^�ł��邱�Ƃ��z�肳���ۂ�\n
	///				����̃C�e���[�^���m�F���邽�߂Ɏg�p���܂��B
	inline const Iterator& Dummy() noexcept;

	/// @brief		�_�~�[�m�[�h���w���R���X�g�C�e���[�^���擾����
	/// @return		�_�~�[�m�[�h���w���R���X�g�C�e���[�^
	/// @details	�_�~�[�m�[�h���w���R���X�g�C�e���[�^��ԋp���܂��B\n
	///				ConstEnd()�ŕԂ����R���X�g�C�e���[�^�Ɠ���ł��B\n
	///				���̊֐��R���̂��̈ȊO�ŁA�_�~�[�m�[�h���w���R���X�g�C�e���[�^�ł��邱�Ƃ��z�肳���ۂ�\n
	///				����̃R���X�g�C�e���[�^���m�F���邽�߂Ɏg�p���܂��B
	inline const ConstIterator& ConstDummy() const noexcept;

private:
	inline void QuickSort(const unsigned int& inLeftIndex, const unsigned int& inRightIndex);

private:
	/// @brief ���X�g�̏I�[��\���m�[�h
	Node _EOL;

	/// @brief �i�[����Ă���f�[�^��
	unsigned int _Size;

	/// @brief		�_�~�[�m�[�h���w���C�e���[�^
	/// @details	�C�e���[�^�̎w���v�f���_�~�[�m�[�h���Ƒz�肳���ۂ̔�r�̂��߂Ɏg�p���܂��B\n
	///				������Ԃ���ύX����邱�Ƃ͂���܂���B
	const Iterator _Dummy;
};

#include "LinkedList.inl"