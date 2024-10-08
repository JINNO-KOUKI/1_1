// GoogleTest�̃w�b�_
#include <gtest/gtest.h>

// ���g�̃��X�g
#include "../1_4/LinkedList.h"

// -- ��r�Ɏg�p����֐��I�u�W�F�N�g
#define COMP_AGE_ASC		[](const UserData& a, const UserData& b) {return a._Age < b._Age; } 
#define COMP_AGE_DESC		[](const UserData& a, const UserData& b) {return a._Age > b._Age; }
#define COMP_STATURE_ASC	[](const UserData& a, const UserData& b) {return a._Stature < b._Stature; }
#define COMP_STATURE_DESC	[](const UserData& a, const UserData& b) {return a._Stature > b._Stature; }

namespace ex01_DataStructure
{
	namespace chapter4
	{
		/// @brief �e�X�g�ɗ��p����\����
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

		//=================================== �N�C�b�N�\�[�g ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-0\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
						�G���[�܂߁A�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEmpty) {

			LinkedList<UserData> list;

			// -- ���בւ����s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- ���Ճe�X�g
			EXPECT_EQ(0, list.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�(���X�g�ɗ\�����Ȃ��ύX���������Ă���)";
		}

		/**********************************************************************************//**
			@brief		�v�f��1�ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-1\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f��1�ł���ꍇ�̋������m�F���Ă��܂��B\n
						�G���[�܂߁A�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenOnce) {

			LinkedList<UserData> list;
			
			// -- ��������
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// -- ���בւ����s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- ���Ճe�X�g
			EXPECT_EQ(1, list.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�(���X�g�ɗ\�����Ȃ��ύX���������Ă���)";
			EXPECT_EQ(UserData(1, 10.0f), *(list.Begin())) << "�z�肵�Ă���v�f�ƈقȂ�(���X�g�ɗ\�����Ȃ��ύX���������Ă���)";
		}

		/**********************************************************************************//**
			@brief		�v�f��2�ȏ�ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-2\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f��2�ȏ�ł���ꍇ�̋������m�F���Ă��܂��B\n
						�v�f���w�肵���L�[�ɏ����āA�w�肵�����ɕ��ׂΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenMulti) {

			LinkedList<UserData> list;
			
			// -- ��������
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "�����v�f�̑}���Ɏ��s";

			// ======== Age�ɑ΂��鏸���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- �����m�F
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			
			// ======== Age�ɑ΂���~���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ======== Stature�ɑ΂��鏸���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ======== Stature�ɑ΂���~���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

		}

		/**********************************************************************************//**
			@brief		�����L�[�����v�f������ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-3\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�����L�[�����v�f������ꍇ�̋������m�F���Ă��܂��B\n
						���̃L�[���w�肵���Ƃ��ɁA�\�[�g����ĕ��Ԃ������v�f�̏����͕ۏ؂���Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEqualElem) {

			LinkedList<UserData> list;
			
			// -- ��������
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// ======== Age�ɑ΂��鏸���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- �����m�F
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ======== Age�ɑ΂���~���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ======== Stature�ɑ΂��鏸���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ======== Stature�ɑ΂���~���\�[�g�e�X�g ========

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(2, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

		}

		/**********************************************************************************//**
			@brief		�v�f������ς݂ł���ꍇ�̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-4\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f������ς݂ł���ꍇ�̋������m�F���Ă��܂��B\n
						�v�f�̏����ɕϓ����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenFinishedSort) {

			LinkedList<UserData> list;
			
			// ======== Age�ɑ΂��鏸���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- �����m�F
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ���X�g�̏�����
			ASSERT_TRUE(list.Clear());

			// ======== Age�ɑ΂���~���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ���X�g�̏�����
			ASSERT_TRUE(list.Clear());

			// ======== Stature�ɑ΂��鏸���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ���X�g�̏�����
			ASSERT_TRUE(list.Clear());

			// ======== Stature�ɑ΂���~���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

		}

		/**********************************************************************************//**
			@brief		����ς݃��X�g�ɗv�f��}��������̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-5\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�v�f������ς݂ł��鐮��ς݃��X�g�̊e���ɐV�K�v�f��}��������A�\�[�g�����s�����ꍇ�̋������m�F���Ă��܂��B\n
						�������\�[�g�����ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenAfterInsert) {

			LinkedList<UserData> list;

			// ======== Age�ɑ΂��鏸���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// -- ���Ԃւ̗v�f�}��
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "�ǉ��v�f�̑}���Ɏ��s";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "�ǉ��v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ���X�g�̏�����
			ASSERT_TRUE(list.Clear());

			// ======== Age�ɑ΂���~���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";

			// -- ���Ԃւ̗v�f�}��
			it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "�ǉ��v�f�̑}���Ɏ��s";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "�ǉ��v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(5, 40.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ���X�g�̏�����
			ASSERT_TRUE(list.Clear());

			// ======== Stature�ɑ΂��鏸���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";

			// -- ���Ԃւ̗v�f�}��
			it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "�ǉ��v�f�̑}���Ɏ��s";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "�ǉ��v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";

			// ���X�g�̏�����
			ASSERT_TRUE(list.Clear());

			// ======== Stature�ɑ΂���~���\�[�g�e�X�g ========

			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// -- ���Ԃւ̗v�f�}��
			it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "�ǉ��v�f�̑}���Ɏ��s";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "�ǉ��v�f�̑}���Ɏ��s";

			// �\�[�g���s
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- �����m�F
			it = list.ConstBegin();
			EXPECT_EQ(UserData(4, 50.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
		}

		/**********************************************************************************//**
			@brief		�L�[���w�肵�Ȃ������ۂ̃\�[�g�̎��s�e�X�g
			@details	ID:���X�g-6\n
						�f�[�^�̃\�[�g�@�\�̃e�X�g�ł��B\n
						�L�[���w�肹���Ƀ\�[�g�����s�����ꍇ�̋������m�F���Ă��܂��B\n
						�G���[�܂߁A�����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenNullKey) {

			LinkedList<UserData> list;
			
			// -- �����v�f�̑}��
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "�����v�f�̑}���Ɏ��s";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "�����v�f�̑}���Ɏ��s";

			// -- �\�[�g���s
			EXPECT_NO_THROW(list.Sort(nullptr));

			// -- ���Ճe�X�g
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
			++it;
			EXPECT_EQ(UserData(2, 10.0f), *it) << "���X�g�v�f���z�肳��Ă��鏇���ɂȂ��Ă��Ȃ�";
		}

	}
}