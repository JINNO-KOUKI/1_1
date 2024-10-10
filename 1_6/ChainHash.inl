#pragma once


/// @brief				������r���Z�q
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @param other		�E�ӗv�f
/// @return				��r����
/// @detail				�L�[�Ɨv�f���ꂼ�ꂪ�A���ׂē��ꂩ�ǂ����Ŕ��f���܂�
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Pair::operator==(const Pair& other) const noexcept
{
	return (_Key == other._Key) && (_Value == other._Value);
}

/// @brief				�n�b�V���e�[�u���ɁA�V�K�v�f��ǉ�����
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @param inKey		�i�[����v�f�̃L�[(���)
/// @param inValue		�i�[����v�f
/// @return				����I�� : TRUE  �ُ�I�� : FALSE
/// @details			�L�[�����ɁA�V�K�v�f��ǉ����܂��B\n
///						�o�^����L�[�́A���̃n�b�V���e�[�u���̒��ň�ӂȂ��̂ł���K�v������܂��B\n
///						�d������L�[�����Ɋi�[����Ă���ꍇ�AFALSE�ŏI�����܂��B\n
///						�n�b�V���l���o�P�b�g�T�C�Y�𒴉߂���ꍇ��FALSE�ŏI�����܂��B
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Add(const Key& inKey, const Value& inValue)
{
	// ����L�[���i�[����Ă��Ȃ����`�F�b�N
	Value tValue;
	if (Find(inKey, tValue))
	{	// �i�[����Ă�����

		// �����I��
		return false;
	}
	else
	{	// �i�[����Ă��Ȃ�������

		// �n�b�V���l�����߂�
		Hash tHash = Func(inKey);
		// �Ώۃ`�F�C���̐擪�ɒǉ�
		_List[tHash].Insert(_List[tHash].Begin(), Pair(inKey, inValue));
	}
	
	// ����I��
	return true;
}

/// @brief				�n�b�V���e�[�u������A�v�f���폜����
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @param inKey		�폜����v�f�Ɋ��蓖�Ă��Ă���L�[
/// @return				����I�� : TRUE  �ُ�I�� : FALSE
/// @details			�w�肳�ꂽ�L�[�ɊY������v�f���A���̃e�[�u������폜���܂��B\n
///						�L�[�ɊY������v�f���i�[����Ă��Ȃ��ꍇ�AFALSE�ŏI�����܂��B\n
///						�n�b�V���l���o�P�b�g�T�C�Y�𒴉߂���ꍇ��FALSE�ŏI�����܂��B
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Remove(const Key& inKey)
{
	// -- �ΏۃL�[�̗v�f���i�[����Ă��邩�m�F
	Value tValue;
	if (Find(inKey, tValue))
	{	// �i�[����Ă�����

		// �n�b�V���l�����߂�
		Hash tHash = Func(inKey);
		
		// -- �Y���v�f�܂ŃC�e���[�^���V�[�N���č폜
		for (auto it = _List[tHash].Begin(); it != _List[tHash].End(); ++it)
		{
			// �폜�Ώۂ�����������
			if ((*it)._Key == inKey)
			{
				// �Y���v�f���`�F�C������폜���ďI��
				_List[tHash].Remove(it);
				return true;
			}
		}
	}
	else
	{	// �i�[����Ă��Ȃ�������

		// �����I��
		return false;
	}

	// ����ł���΂����ɂ͗��Ȃ�
	// Find()�ɂ���ėv�f���������Ă���̂ɁA�폜�ł��Ȃ�����
	return false;
}

/// @brief				�n�b�V���e�[�u������A�v�f����������
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @param inKey		�����Ɏg�p����L�[
/// @param outValue		�������ʗv�f���i�[����ϐ�
/// @return				�v�f�������� : TRUE  �v�f��������Ȃ� or �ُ�I�� : FALSE
/// @details			�w�肳�ꂽ�L�[�����蓖�Ă��Ă���v�f���A���̃e�[�u�����猟�����܂��B\n
///						������Ȃ������ꍇ�AFALSE�ŏI�����܂��B\n
///						�n�b�V���l���o�P�b�g�T�C�Y�𒴉߂���ꍇ��FALSE�ŏI�����܂��B
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Find(const Key& inKey, Value& outValue) const
{
	// �n�b�V���l���v�Z
	Hash tHash = Func(inKey);

	// �n�b�V���l���o�P�b�g�T�C�Y�𒴂��Ă�����A�����I��
	if (tHash >= BucketSize) { return false; }

	// -- �Ώۂ̃`�F�C��������`�T��
	for (auto it = _List[tHash].ConstBegin(); it != _List[tHash].ConstEnd(); ++it)
	{
		// -- �T���L�[�Ɠ���̃L�[������������
		if ((*it)._Key == inKey)
		{
			// -- �o�͗p�ϐ��ɗv�f�������ďI��
			outValue = (*it)._Value;
			return true;
		}
	}

	// ������Ȃ������̂ŁAfalse�ŏI��
	return false;
}

/// @brief				�n�b�V���l����A�Y���`�F�C�����擾����
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @param inHash		�擾�������`�F�C���̃n�b�V���l
/// @param outList		�擾�����`�F�C�����i�[���郊�X�g�ϐ�
/// @return				����I�� : TRUE  �ُ�I�� : FALSE
/// @details			�^����ꂽ�n�b�V���l�ƁA��v����L�[���i�[����Ă���`�F�C�����X�g���擾���܂��B\n
///						�Y���̃`�F�C�������݂��Ȃ����͈���v�f���i�[����Ă��Ȃ��ꍇ�AFALSE�ŏI�����܂��B\n
///						�i�[�惊�X�g�ϐ��Ɋ��Ƀf�[�^���i�[����Ă��閔�̓��X�g�̃R�s�[�����s�����ꍇ�ɂ��AFALSE�ŏI�����܂��B
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::GetChainByHash(const unsigned int& inHash, LinkedList<Pair>& outList)
{
	// �w�肳�ꂽ�n�b�V���l���o�P�b�g�T�C�Y�𒴂��Ă�����A�����I��
	if (inHash >= BucketSize) { return false; }
	// �Y���`�F�C���ɗv�f�����݂��Ȃ��ꍇ���A�����I��
	if (_List[inHash].Size() == 0) { return false; }

	// ���X�g���R�s�[
	if (!_List[inHash].Copy(outList))
	{	// �R�s�[�Ɏ��s������
		
		// �����I��
		return false;
	}

	// ����I��
	return true;
}

/// @brief				�i�[����Ă���S�Ă̗v�f���擾����
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @param outList		�擾�����v�f���i�[���郊�X�g�ϐ�
/// @return				����I�� : TRUE  �ُ�I�� : FALSE
/// @details			���̃n�b�V���e�[�u���Ɋi�[����Ă��邷�ׂĂ̗v�f���擾���܂��B\n
///						�i�[�惊�X�g�ϐ��Ɋ��ɗv�f���i�[����Ă���ꍇ�AFALSE�ŏI�����܂��B\n
///						���X�g�̃R�s�[�Ɏ��s�����ꍇ�AAssert���������܂��B
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::GetAllData(LinkedList<Pair>& outList)
{
	// �i�[�惊�X�g�ɂ��łɃf�[�^�����݂�����A���������ɏI��
	if (outList.Size() > 0) { return false; }

	for (unsigned int i = 0; i < BucketSize; ++i)
	{
		// �e�`�F�C�����X�g���������Ă���
		if (!outList.Append(_List[i]))
		{	// �����Ɏ��s������

			// Append��Assert�ȊO�ňُ�I�����邱�Ƃ͖����̂ŁA
			// ���������ɗ�����v���I�ȃG���[�̉\�������邽��Assert�𔭐�������
			assert(false);
		}
	}

	// ����I��
	return true;
}

/// @brief				�i�[����Ă���v�f�����擾����
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @return				�i�[����Ă���v�f��
/// @details			���̃n�b�V���e�[�u���Ɋi�[����Ă���v�f�����擾���܂��B
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline unsigned int ChainHash<Key, Value, Func, BucketSize>::Size() const noexcept
{
	unsigned int tSize = 0;

	// -- ���ׂẴ`�F�C���𑖍�
	for (int i = 0; i < BucketSize; ++i)
	{
		// �e�`�F�C���̃T�C�Y�����Z
		tSize += _List[i].Size();
	}

	// �e�`�F�C���̃T�C�Y�̍��v�l��Ԃ�
	return tSize;
}

/// @brief				�g�p���̃`�F�C���̐����擾����
/// @tparam Key			�L�[�Ƃ��ė��p����f�[�^�̌^
/// @tparam Value		�i�[����v�f�̃f�[�^�^
/// @tparam Func		�n�b�V���֐�
/// @tparam BucketSize	�o�P�b�g�T�C�Y
/// @return				�g�p���̃`�F�C���̐�
/// @details			��ł��v�f���i�[����Ă���`�F�C���̐����擾���܂��B\n
///						�`�F�C���̐��̓n�b�V���l�̐��ɓ��������߁A����Ƀn�b�V���ʂŐU�蕪�����Ă��邩���m�F�ł��܂��B\n
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline unsigned int ChainHash<Key, Value, Func, BucketSize>::ChainSize() const noexcept
{
	unsigned int tSize = 0;

	// -- ���ׂẴ`�F�C���𑖍�
	for (int i = 0; i < BucketSize; ++i)
	{
		// ��ł��`�F�C���ɗv�f������΃C���N�������g
		if (_List[i].Size()) { ++tSize; }
	}

	// �v�f���܂܂�Ă���`�F�C���̐���Ԃ�
	return tSize;
}