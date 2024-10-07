// GoogleTest�̃w�b�_
#include <gtest/gtest.h>

// ���g�̃��X�g
#include "../1_5/Stack.h"
#include "../1_5/Queue.h"


namespace ex01_DataStructure
{
	namespace chapter5
	{
		/// @brief �e�X�g�Ɏg�p����A�i�[�v�f
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

		//=================================== �X�^�b�N - �f�[�^���̎擾 ===================================
		namespace stack_GetDataNumTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-0\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumWhenEmpty) {

				Stack<UserData> stack;

				EXPECT_EQ(0, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f���v�b�V�������ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-1\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f���v�b�V��������̋������m�F���Ă��܂��B\n
							�߂�l��1�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterPush) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";

				EXPECT_EQ(1, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f���|�b�v�����ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-2\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f���|�b�v������̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterPop) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";

				UserData tUserData;
				ASSERT_TRUE(stack.Pop(tUserData)) << "�v�f�̃|�b�v�Ɏ��s";

				EXPECT_EQ(0, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f�̃v�b�V���Ɏ��s�����ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-3\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V���Ɏ��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterPushFailed) {

				Stack<UserData> stack;

				ASSERT_FALSE(stack.Push(UserData(1, 10.0f))) << "���s����͂��̃v�b�V���ɐ������Ă��܂���";

				EXPECT_EQ(0, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��s�����ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-4\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��2�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterTwoPush) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(UserData(2, 20.0f))) << "�����v�f�̒ǉ��Ɏ��s";

				EXPECT_EQ(2, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��A�|�b�v��1��s�����ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-5\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��A�|�b�v��1��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��1�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterTwoPushAndOnePop) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(UserData(2, 20.0f))) << "�����v�f�̒ǉ��Ɏ��s";
				
				UserData tUserData;
				ASSERT_TRUE(stack.Pop(tUserData)) << "�����v�f�̃|�b�v�Ɏ��s";

				EXPECT_EQ(1, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s�����ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-6\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							��̃��X�g�ɑ΂��ă|�b�v���s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterPopEmpty) {

				Stack<UserData> stack;

				UserData tUserData;
				ASSERT_FALSE(stack.Pop(tUserData)) << "���s����͂��̃|�b�v�ɐ������Ă��܂���";

				EXPECT_EQ(0, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

		}

		//=================================== �X�^�b�N - �v�b�V�� ===================================
		namespace stack_PushTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-8\n
							�f�[�^�̃v�b�V���@�\�̃e�X�g�ł��B\n
							���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A���X�g�ɗv�f���ǉ������ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPushTest, TestPushWhenEmpty) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�v�f�̒ǉ��Ɏ��s";
				EXPECT_EQ(1, stack.Size()) << "�ǉ����ꂽ�͂��̗v�f������ɒǉ��ł��Ă��Ȃ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-9\n
							�f�[�^�̃v�b�V���@�\�̃e�X�g�ł��B\n
							���X�g�����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A���X�g�̖����ɗv�f���ǉ������ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPushTest, TestPushWhenMultiElem) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(UserData(2, 20.0f))) << "�����v�f�̒ǉ��Ɏ��s";

				ASSERT_TRUE(stack.Push(UserData(3, 30.0f))) << "�����v�f�������Ԃł́A�v�f�̒ǉ��Ɏ��s";

				UserData tUserData;
				ASSERT_TRUE(stack.Pop(tUserData)) << "�v�f�̃|�b�v�Ɏ��s";

				EXPECT_EQ(UserData(3, 30.0f), tUserData) << "���X�g�̖����ɑ΂��āA�v�f�𐳏�Ƀv�b�V���ł��Ă��Ȃ�����";

			}

		}

		//=================================== �X�^�b�N - �|�b�v ===================================
		namespace stack_PopTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-11\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��FALSE�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPopTest, TestPopWhenEmpty) {

				Stack<UserData> stack;

				UserData tUserData;
				EXPECT_FALSE(stack.Pop(tUserData)) << "���s����͂��̃|�b�v�ɐ������Ă��܂���";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-12\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�����v�f�������œn����A�v�f���폜����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPopTest, TestPopWhenMultiElem) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(UserData(2, 20.0f))) << "�����v�f�̒ǉ��Ɏ��s";

				UserData tUserData;
				ASSERT_TRUE(stack.Pop(tUserData)) << "�v�f�̃|�b�v�Ɏ��s";
				EXPECT_EQ(UserData(2, 20.0f), tUserData) << "�|�b�v���ꂽ�v�f���A�z�肵�Ă�����̂ƈقȂ�";
				EXPECT_EQ(1, stack.Size()) << "���X�g����v�f���폜�ł��Ă��Ȃ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̕�������s�e�X�g
				@details	ID:�X�^�b�N-13\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�����v�f���珇�Ɉ����œn����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPopTest, TestMultiPopWhenMultiElem) {

				Stack<UserData> stack;

				ASSERT_TRUE(stack.Push(UserData(1, 10.0f))) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(UserData(2, 20.0f))) << "�����v�f�̒ǉ��Ɏ��s";

				UserData tUserData;
				ASSERT_TRUE(stack.Pop(tUserData)) << "�v�f�̃|�b�v�Ɏ��s";
				EXPECT_EQ(UserData(2, 20.0f), tUserData) << "�|�b�v���ꂽ�v�f���A�z�肵�Ă�����̂ƈقȂ�";
				ASSERT_TRUE(stack.Pop(tUserData)) << "�v�f�̃|�b�v�Ɏ��s";
				EXPECT_EQ(UserData(1, 10.0f), tUserData) << "�|�b�v���ꂽ�v�f���A�z�肵�Ă�����̂ƈقȂ�";

				EXPECT_EQ(0, stack.Size()) << "���X�g����v�f���폜�ł��Ă��Ȃ�";
			}

		}

		//=================================== �L���[ - �f�[�^���̎擾 ===================================
		namespace queue_GetDataNumTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�L���[-0\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumWhenEmpty) {

			}

			/**********************************************************************************//**
				@brief		�v�f���v�b�V�������ۂ̎��s�e�X�g
				@details	ID:�L���[-1\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f���v�b�V��������̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPush) {

			}

			/**********************************************************************************//**
				@brief		�v�f���|�b�v�����ۂ̎��s�e�X�g
				@details	ID:�L���[-2\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f���|�b�v������̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPop) {

			}

			/**********************************************************************************//**
				@brief		�v�f�̃v�b�V���Ɏ��s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-3\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V���Ɏ��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPushFailed) {

			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-4\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��2�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterTwoPush) {

			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��A�|�b�v��1��s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-5\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��A�|�b�v��1��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��1�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterTwoPushAndOnePop) {

			}

			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-6\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							��̃��X�g�ɑ΂��ă|�b�v���s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPopEmpty) {

			}

		}

		//=================================== �L���[ - �v�b�V�� ===================================
		namespace queue_PushTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�L���[-8\n
							�f�[�^�̃v�b�V���@�\�̃e�X�g�ł��B\n
							���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A���X�g�ɗv�f���ǉ������ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePushTest, TestPushWhenEmpty) {

			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�L���[-9\n
							�f�[�^�̃v�b�V���@�\�̃e�X�g�ł��B\n
							���X�g�����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A���X�g�̖����ɗv�f���ǉ������ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePushTest, TestPushWhenMultiElem) {

			}

		}

		//=================================== �L���[ - �|�b�v ===================================
		namespace queue_PopTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�L���[-11\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g����ł���ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��FALSE�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePopTest, TestPopWhenEmpty) {

			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�L���[-12\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�����v�f�������œn����A�v�f���폜����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePopTest, TestPopWhenMultiElem) {

			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̕�������s�e�X�g
				@details	ID:�L���[-13\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�����v�f���珇�Ɉ����œn����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePopTest, TestMultiPopWhenMultiElem) {

			}

		}
		
	}
}