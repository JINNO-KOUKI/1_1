// GoogleTest�̃w�b�_
#include <gtest/gtest.h>

// ���g�̃��X�g
#include "../1_4/LinkedList.h"


namespace ex01_DataStructure
{
	namespace chapter4
	{

		//=================================== �N�C�b�N�\�[�g ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
						�G���[�܂߁A�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEmpty) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				bool operator==(const UserData& other) const
				{
					return this->_Age == other._Age && this->_Stature == other._Stature;
				}
			};
			LinkedList<UserData> list;

			EXPECT_NO_THROW(list.Sort(false, &UserData::_Age));
			EXPECT_NO_THROW(list.Sort(false, &UserData::_Stature));
		}

		/**********************************************************************************//**
			@brief		�v�f��1�ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f��1�ł���ꍇ�̋������m�F���Ă��܂��B\n
						�G���[�܂߁A�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenOnce) {

			struct UserData
			{
				int		_Age;
				float	_Stature;
			};
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData())) << "�����v�f�̑}���Ɏ��s";

			EXPECT_NO_THROW(list.Sort(false, &UserData::_Age));
			EXPECT_NO_THROW(list.Sort(false, &UserData::_Stature));
		}

		/**********************************************************************************//**
			@brief		�v�f��2�ȏ�ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-2\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f��2�ȏ�ł���ꍇ�̋������m�F���Ă��܂��B\n
						�v�f���w�肵���L�[�ɏ����āA�w�肵�����ɕ��ׂΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenMulti) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				UserData() : _Age(0), _Stature(0.0f) {}
				
				UserData(int age, float stature)
					: _Age(age), _Stature(stature) {}

				bool operator==(const UserData& other) const
				{
					return this->_Age == other._Age && this->_Stature == other._Stature;
				}
			};
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "�����v�f�̑}���Ɏ��s";

			// --- Age�ɑ΂���\�[�g�e�X�g
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			LinkedList<UserData>::ConstIterator it = list.Begin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			
			// --- Stature�ɑ΂���\�[�g�e�X�g
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
		}

		/**********************************************************************************//**
			@brief		�����L�[�����v�f������ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-3\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�����L�[�����v�f������ꍇ�̋������m�F���Ă��܂��B\n
						���̃L�[���w�肵���Ƃ��ɁA�\�[�g����ĕ��Ԃ������v�f�̏����͕ۏ؂���Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEqualElem) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				UserData() : _Age(0), _Stature(0.0f) {}
				
				UserData(int age, float stature)
					: _Age(age), _Stature(stature) {}

				bool operator==(const UserData& other) const
				{
					return this->_Age == other._Age && this->_Stature == other._Stature;
				}
			};
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// --- Age�ɑ΂���\�[�g�e�X�g
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			LinkedList<UserData>::ConstIterator it = list.Begin();
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// --- Stature�ɑ΂���\�[�g�e�X�g
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
		}

		/**********************************************************************************//**
			@brief		�v�f������ς݂ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-4\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f������ς݂ł���ꍇ�̋������m�F���Ă��܂��B\n
						�v�f�̏����ɕϓ����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenFinishedSort) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				UserData() : _Age(0), _Stature(0.0f) {}

				UserData(int age, float stature)
					: _Age(age), _Stature(stature) {}

				bool operator==(const UserData& other) const
				{
					return this->_Age == other._Age && this->_Stature == other._Stature;
				}
			};
			LinkedList<UserData> list;
			
			// --- Age�ɑ΂���\�[�g�e�X�g
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			LinkedList<UserData>::ConstIterator it = list.Begin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			ASSERT_TRUE(list.Clear());

			// --- Stature�ɑ΂���\�[�g�e�X�g
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
		}

		/**********************************************************************************//**
			@brief		����ς݃��X�g�ɗv�f��}��������̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-5\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f������ς݂ł��鐮��ς݃��X�g�̊e���ɐV�K�v�f��}��������A�\�[�g�����s�����ꍇ�̋������m�F���Ă��܂��B\n
						�������\�[�g�����ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenAfterInsert) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				UserData() : _Age(0), _Stature(0.0f) {}
				
				UserData(int age, float stature)
					: _Age(age), _Stature(stature) {}

				bool operator==(const UserData& other) const
				{
					return this->_Age == other._Age && this->_Stature == other._Stature;
				}
			};
			LinkedList<UserData> list;

			// --- Age�ɑ΂���\�[�g�e�X�g
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			LinkedList<UserData>::ConstIterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "�ǉ��v�f�̑}���Ɏ��s";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "�ǉ��v�f�̑}���Ɏ��s";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			it = list.Begin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			ASSERT_TRUE(list.Clear());

			// --- Stature�ɑ΂���\�[�g�e�X�g
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";

			it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "�ǉ��v�f�̑}���Ɏ��s";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "�ǉ��v�f�̑}���Ɏ��s";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
		}

		/**********************************************************************************//**
			@brief		�L�[���w�肵�Ȃ������ۂ̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-6\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�L�[���w�肹���Ƀ\�[�g�����s�����ꍇ�̋������m�F���Ă��܂��B\n
						�G���[�܂߁A�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenNullKey) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				UserData() : _Age(0), _Stature(0.0f) {}
				
				UserData(int age, float stature)
					: _Age(age), _Stature(stature) {}
			};
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// ���₵�����e�ɊY������ӏ��̂��߁A�ꎞ�I�ɃR�����g�A�E�g���Ă��܂��B
			//EXPECT_DEATH(list.Sort(false, nullptr), "Assertion failed. *");
		}

	}
}