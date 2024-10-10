#pragma once

#include "LinkedList.h"

/// @brief				�n�b�V���`�F�C���@��p�����f�[�^�R���e�i�N���X
/// @tparam Key			�v�f�ɕR�Â���L�[�̌^
/// @tparam Value		�i�[�������v�f�̌^
/// @tparam Func		�n�b�V���l�����߂�֐�(�n�b�V���֐�)
/// @tparam BucketSize	�o�P�b�g�T�C�Y(�n�b�V���l�̍ő��ސ�)
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
class ChainHash
{
	/// @brief �n�b�V���l�̌^
	using Hash = unsigned int;

public:
	/// @brief �L�[�Ɨv�f���Z�b�g�Ŋi�[���邽�߂̃y�A�\����
	struct Pair
	{
		/// @brief �v�f�ɕR�Â���L�[
		Key		_Key;
		/// @brief ���ۂɊi�[����v�f
		Value	_Value;

		/// @brief �f�t�H���g�R���X�g���N�^
		Pair() : _Key(Key()), _Value(Value()) {}

		/// @brief			�����t���R���X�g���N�^
		/// @param key		�L�[���
		/// @param value	�i�[�v�f
		Pair(Key key, Value value) : _Key(key), _Value(value) {}

		/// @brief				������r���Z�q
		/// @param other		�E�ӗv�f
		/// @return				��r����
		/// @detail				�L�[�Ɨv�f���ꂼ�ꂪ�A���ׂē��ꂩ�ǂ����Ŕ��f���܂�
		bool operator==(const Pair& other) const noexcept;
	};

public:
	/// @brief				�n�b�V���e�[�u���ɁA�V�K�v�f��ǉ�����
	/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
	/// @tparam Value		�i�[����v�f�̃f�[�^�^
	/// @param inKey		�i�[����v�f�̃L�[(���)
	/// @param inValue		�i�[����v�f
	/// @return				����I�� : TRUE  �ُ�I�� : FALSE
	/// @details			�L�[�����ɁA�V�K�v�f��ǉ����܂��B\n
	///						�o�^����L�[�́A���̃n�b�V���e�[�u���̒��ň�ӂȂ��̂ł���K�v������܂��B\n
	///						�d������L�[�����Ɋi�[����Ă���ꍇ�AFALSE�ŏI�����܂��B
	bool Add(const Key& inKey, const Value& inValue);

	/// @brief				�n�b�V���e�[�u������A�v�f���폜����
	/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
	/// @param inKey		�폜����v�f�Ɋ��蓖�Ă��Ă���L�[
	/// @return				����I�� : TRUE  �ُ�I�� : FALSE
	/// @details			�w�肳�ꂽ�L�[�ɊY������v�f���A���̃e�[�u������폜���܂��B\n
	///						�L�[�ɊY������v�f���i�[����Ă��Ȃ��ꍇ�AFALSE�ŏI�����܂��B
	bool Remove(const Key& inKey);

	/// @brief				�n�b�V���e�[�u������A�v�f����������
	/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
	/// @tparam Value		�i�[����v�f�̃f�[�^�^
	/// @param inKey		�����Ɏg�p����L�[
	/// @param outValue		�������ʗv�f���i�[����ϐ�
	/// @return				�v�f�������� : TRUE  �v�f��������Ȃ� or �ُ�I�� : FALSE
	/// @details			�w�肳�ꂽ�L�[�����蓖�Ă��Ă���v�f���A���̃e�[�u�����猟�����܂��B\n
	///						������Ȃ������ꍇ�AFALSE�ŏI�����܂��B
	bool Find(const Key& inKey, Value& outValue) const;

	/// @brief				�n�b�V���l����A�Y���`�F�C�����擾����
	/// @param inHash		�擾�������`�F�C���̃n�b�V���l
	/// @param outList		�擾�����`�F�C�����i�[���郊�X�g�ϐ�
	/// @return				����I�� : TRUE  �ُ�I�� : FALSE
	/// @details			�^����ꂽ�n�b�V���l�ƁA��v����L�[���i�[����Ă���`�F�C�����X�g���擾���܂��B\n
	///						�Y���̃`�F�C�������݂��Ȃ����͈���v�f���i�[����Ă��Ȃ��ꍇ�AFALSE�ŏI�����܂��B\n
	///						�i�[�惊�X�g�ϐ��Ɋ��Ƀf�[�^���i�[����Ă��閔�̓��X�g�̃R�s�[�����s�����ꍇ�ɂ��AFALSE�ŏI�����܂��B
	bool GetChainByHash(const unsigned int& inHash, LinkedList<Pair>& outList) const;

	/// @brief				�i�[����Ă���S�Ă̗v�f���擾����
	/// @param outList		�擾�����v�f���i�[���郊�X�g�ϐ�
	/// @return				����I�� : TRUE  �ُ�I�� : FALSE
	/// @details			���̃n�b�V���e�[�u���Ɋi�[����Ă��邷�ׂĂ̗v�f���擾���܂��B\n
	///						�i�[�惊�X�g�ϐ��Ɋ��ɗv�f���i�[����Ă���ꍇ�AFALSE�ŏI�����܂��B\n
	///						���X�g�̃R�s�[�Ɏ��s�����ꍇ�AAssert���������܂��B
	bool GetAllData(LinkedList<Pair>& outList) const;

	/// @brief				�i�[����Ă���v�f�����擾����
	/// @return				�i�[����Ă���v�f��
	/// @details			���̃n�b�V���e�[�u���Ɋi�[����Ă���v�f�����擾���܂��B
	unsigned int Size() const noexcept;

	/// @brief				�g�p���̃`�F�C���̐����擾����
	/// @return				�g�p���̃`�F�C���̐�
	/// @details			��ł��v�f���i�[����Ă���`�F�C���̐����擾���܂��B\n
	///						�`�F�C���̐��̓n�b�V���l�̐��ɓ��������߁A����Ƀn�b�V���ʂŐU�蕪�����Ă��邩���m�F�ł��܂��B\n
	unsigned int ChainSize() const noexcept;

private:
	/// @brief �e�n�b�V���l�ʂɗv�f���Ǘ����邽�߂̃`�F�C��(�o�������X�g)
	LinkedList<Pair> _List[BucketSize];
};

#include "ChainHash.inl"