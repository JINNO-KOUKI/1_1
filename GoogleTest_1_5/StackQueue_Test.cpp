// GoogleTest�̃w�b�_
#include <gtest/gtest.h>

// ���g�̃��X�g
#include "../1_5/Stack.h"
#include "../1_5/Queue.h"


namespace ex01_DataStructure
{
	namespace chapter5
	{
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

				Stack<int> stack;

				// �T�C�Y�擾�e�X�g
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

				Stack<int> stack;

				// �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";

				// �T�C�Y�擾�e�X�g
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

				Stack<int> stack;

				// �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";

				// �i�[�v�f�̃|�b�v
				int tValue;
				ASSERT_TRUE(stack.Pop(tValue)) << "�v�f�̃|�b�v�Ɏ��s";

				// �T�C�Y�擾�e�X�g
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

#if 0		// �v�f�̃v�b�V���Ɏ��s����������A�u�������m�ۂ̎��s�v�����Ȃ����߃X�L�b�v
				Stack<int> stack;

				// �����v�f�̃v�b�V��(���s�z��)
				ASSERT_FALSE(stack.Push(1)) << "���s����͂��̃v�b�V���ɐ������Ă��܂���";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(0, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
#endif
			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��s�����ۂ̎��s�e�X�g	
				@details	ID:�X�^�b�N-4\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��2�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackGetDataNumTest, TestGetDataNumAfterTwoPush) {

				Stack<int> stack;

				// -- �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(2)) << "�����v�f�̒ǉ��Ɏ��s";

				// �T�C�Y�擾�e�X�g
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

				Stack<int> stack;

				// �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(2)) << "�����v�f�̒ǉ��Ɏ��s";
				
				// �i�[�v�f�̃|�b�v
				int tValue;
				ASSERT_TRUE(stack.Pop(tValue)) << "�����v�f�̃|�b�v�Ɏ��s";

				// �T�C�Y�擾�e�X�g
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

				Stack<int> stack;

				// �i�[�v�f�̃|�b�v(���s�z��)
				int tValue;
				ASSERT_FALSE(stack.Pop(tValue)) << "���s����͂��̃|�b�v�ɐ������Ă��܂���";

				// �T�C�Y�̎擾�e�X�g
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

				Stack<int> stack;

				// �v�f�̃v�b�V���e�X�g
				ASSERT_TRUE(stack.Push(1)) << "�v�f�̒ǉ��Ɏ��s";

				// �m�F�e�X�g
				EXPECT_EQ(1, stack.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-9\n
							�f�[�^�̃v�b�V���@�\�̃e�X�g�ł��B\n
							���X�g�����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A���X�g�̖����ɗv�f���ǉ������ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPushTest, TestPushWhenMultiElem) {

				Stack<int> stack;

				// -- �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(2)) << "�����v�f�̒ǉ��Ɏ��s";

				// �����v�f�������X�g�ւ̃v�b�V���e�X�g
				ASSERT_TRUE(stack.Push(3)) << "�����v�f�������Ԃł́A�v�f�̒ǉ��Ɏ��s";

				// -- �m�F�e�X�g(�����̃f�[�^�Ƃ̔�r)
				int tValue;
				ASSERT_TRUE(stack.Pop(tValue)) << "�v�f�̃|�b�v�Ɏ��s";
				EXPECT_EQ(3, tValue) << "���X�g�̖����ɑ΂��āA�v�f�𐳏�Ƀv�b�V���ł��Ă��Ȃ�����";

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

				Stack<int> stack;

				// ���X�g����̏�Ԃł̃|�b�v�e�X�g(���s�z��)
				int tValue;
				EXPECT_FALSE(stack.Pop(tValue)) << "���s����͂��̃|�b�v�ɐ������Ă��܂���";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�X�^�b�N-12\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�����v�f�������œn����A�v�f���폜����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(StackPopTest, TestPopWhenMultiElem) {

				Stack<int> stack;

				// -- �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(2)) << "�����v�f�̒ǉ��Ɏ��s";

				// -- �i�[�v�f�̃|�b�v�e�X�g
				int tValue;
				ASSERT_TRUE(stack.Pop(tValue)) << "�v�f�̃|�b�v�Ɏ��s";

				// -- �m�F�e�X�g(�����̃f�[�^�ł��邩&�T�C�Y������ɕϓ����Ă��邩)
				EXPECT_EQ(2, tValue) << "�����̃f�[�^�𐳏�Ɏ擾�ł��Ă��Ȃ�";
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

				Stack<int> stack;

				// -- �����v�f�̃v�b�V��
				ASSERT_TRUE(stack.Push(1)) << "�����v�f�̒ǉ��Ɏ��s";
				ASSERT_TRUE(stack.Push(2)) << "�����v�f�̒ǉ��Ɏ��s";

				// -- �����v�f�������Ԃł̘A���|�b�v�e�X�g(2��)
				int tValueA;
				ASSERT_TRUE(stack.Pop(tValueA)) << "�����v�f�������Ԃł̃|�b�v�Ɏ��s";
				int tValueB;
				ASSERT_TRUE(stack.Pop(tValueB)) << "�����v�f�������Ԃł̃|�b�v�Ɏ��s";

				// -- �m�F�e�X�g(�������珇�Ɏ擾�ł��Ă���&�T�C�Y������ɕϓ����Ă���)
				EXPECT_EQ(2, tValueA) << "�������珇�Ƀf�[�^���擾�ł��Ă��Ȃ�";
				EXPECT_EQ(1, tValueB) << "�������珇�Ƀf�[�^���擾�ł��Ă��Ȃ�";
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

				Queue<int> queue;

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(0, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f���v�b�V�������ۂ̎��s�e�X�g
				@details	ID:�L���[-1\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f���v�b�V��������̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPush) {

				Queue<int> queue;

				// �����v�f�̃v�b�V��
				ASSERT_TRUE(queue.Push(1)) << "�����v�f�̃v�b�V���Ɏ��s";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(1, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f���|�b�v�����ۂ̎��s�e�X�g
				@details	ID:�L���[-2\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f���|�b�v������̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPop) {

				Queue<int> queue;

				// -- �i�[�v�f�̃|�b�v(���s�z��)
				int tValue;
				ASSERT_FALSE(queue.Pop(tValue)) << "���s����͂��̃|�b�v�ɐ���";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(0, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f�̃v�b�V���Ɏ��s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-3\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V���Ɏ��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPushFailed) {

#if 0		// �v�f�̃v�b�V���Ɏ��s����������A�u�������m�ۂ̎��s�v�����Ȃ����߃X�L�b�v
				Queue<int> queue;

				// �v�f�̃v�b�V��(���s�z��)
				ASSERT_FALSE(queue.Push(1)) << "���s����͂��̃v�b�V���ɐ���";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(0, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
#endif
			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-4\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��2�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterTwoPush) {

				Queue<int> queue;

				// -- �����v�f�̃v�b�V��(2��)
				ASSERT_TRUE(queue.Push(1)) << "�����v�f�̃v�b�V���Ɏ��s";
				ASSERT_TRUE(queue.Push(2)) << "�����v�f�̃v�b�V���Ɏ��s";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(2, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�b�V����2��A�|�b�v��1��s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-5\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							�v�f�̃v�b�V����2��A�|�b�v��1��s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��1�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterTwoPushAndOnePop) {

				Queue<int> queue;

				// -- �����v�f�̃v�b�V��(2��)
				ASSERT_TRUE(queue.Push(1)) << "�����v�f�̃v�b�V���Ɏ��s";
				ASSERT_TRUE(queue.Push(2)) << "�����v�f�̃v�b�V���Ɏ��s";

				// -- �i�[�v�f�̃|�b�v(1��)
				int tValue;
				ASSERT_TRUE(queue.Pop(tValue)) << "�i�[�v�f�̃|�b�v�Ɏ��s";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(1, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�|�b�v���s�����ۂ̎��s�e�X�g
				@details	ID:�L���[-6\n
							�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
							��̃��X�g�ɑ΂��ă|�b�v���s�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��0�ł���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueueGetDataNumTest, TestGetDataNumAfterPopEmpty) {

				Queue<int> queue;

				// -- �i�[�v�f�̃|�b�v(���s�z��)
				int tValue;
				ASSERT_FALSE(queue.Pop(tValue)) << "���s����͂��̃|�b�v�ɐ���";

				// �T�C�Y�擾�e�X�g
				EXPECT_EQ(0, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
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

				Queue<int> queue;

				// ���X�g����̏�Ԃł̃v�b�V���e�X�g
				ASSERT_TRUE(queue.Push(1)) << "���X�g����̏�Ԃł̃v�b�V���Ɏ��s";

				// �m�F�e�X�g(�v�f��������ɕϓ����Ă��邩)
				EXPECT_EQ(1, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�L���[-9\n
							�f�[�^�̃v�b�V���@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A���X�g�̖����ɗv�f���ǉ������ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePushTest, TestPushWhenMultiElem) {

				Queue<int> queue;

				// -- �����v�f�̃v�b�V��(2��)
				ASSERT_TRUE(queue.Push(1)) << "�����v�f�̃v�b�V���Ɏ��s";
				ASSERT_TRUE(queue.Push(2)) << "�����v�f�̃v�b�V���Ɏ��s";

				// �����v�f�������Ԃł̃v�b�V���e�X�g
				ASSERT_TRUE(queue.Push(3)) << "�����v�f�������Ԃł̃v�b�V���Ɏ��s";

				// -- �m�F�e�X�g(�����ɒǉ�����Ă���&�T�C�Y������ɕϓ����Ă���)
				EXPECT_EQ(3, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
				int tValue;
				ASSERT_TRUE(queue.Pop(tValue)) << "�i�[�v�f�̃|�b�v�Ɏ��s";
				ASSERT_TRUE(queue.Pop(tValue)) << "�i�[�v�f�̃|�b�v�Ɏ��s";
				ASSERT_TRUE(queue.Pop(tValue)) << "�i�[�v�f�̃|�b�v�Ɏ��s";
				EXPECT_EQ(3, tValue) << "�����Ƀf�[�^�𐳏�ɒǉ��ł��Ă��Ȃ�";
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

				Queue<int> queue;

				// -- ���X�g����̏�Ԃł̃|�b�v�e�X�g(���s�z��)
				int tValue;
				ASSERT_FALSE(queue.Pop(tValue)) << "���s����͂��̃|�b�v�ɐ���";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̎��s�e�X�g
				@details	ID:�L���[-12\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�擪�v�f�������œn����A�v�f���폜����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePopTest, TestPopWhenMultiElem) {

				Queue<int> queue;

				// -- �����v�f�̃v�b�V��(2��)
				ASSERT_TRUE(queue.Push(1)) << "�����v�f�̃v�b�V���Ɏ��s";
				ASSERT_TRUE(queue.Push(2)) << "�����v�f�̃v�b�V���Ɏ��s";

				// -- ���X�g�ɕ����v�f�������Ԃł̃|�b�v�e�X�g
				int tValue;
				ASSERT_TRUE(queue.Pop(tValue)) << "�v�f�����������Ԃł̃|�b�v�Ɏ��s";

				// �m�F�e�X�g(�����v�f�̐擪�̃f�[�^�Ɠ���&�T�C�Y������ɕϓ����Ă���)
				EXPECT_EQ(1, tValue) << "�擪�̃f�[�^�𐳏�Ɏ擾�ł��Ă��Ȃ�";
				EXPECT_EQ(1, queue.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�̕�������s�e�X�g
				@details	ID:�L���[-13\n
							�f�[�^�̃|�b�v�@�\�̃e�X�g�ł��B\n
							���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋������m�F���Ă��܂��B\n
							�߂�l��TRUE���A�擪�v�f���珇�Ɉ����œn����Ă���ΐ����ł��B\n
			*//***********************************************************************************/
			TEST(QueuePopTest, TestMultiPopWhenMultiElem) {

				Queue<int> queue;

				// -- �����v�f�̃v�b�V��(2��)
				ASSERT_TRUE(queue.Push(1)) << "�����v�f�̃v�b�V���Ɏ��s";
				ASSERT_TRUE(queue.Push(2)) << "�����v�f�̃v�b�V���Ɏ��s";

				// -- �����v�f�������Ԃł̘A���|�b�v�e�X�g(2��)
				int tValueA;
				ASSERT_TRUE(queue.Pop(tValueA)) << "�����v�f�������Ԃł̃|�b�v�Ɏ��s";
				int tValueB;
				ASSERT_TRUE(queue.Pop(tValueB)) << "�����v�f�������Ԃł̃|�b�v�Ɏ��s";

				// -- �m�F�e�X�g(�擪���珇�Ɏ擾�ł��Ă���&�T�C�Y������ɕϓ����Ă���)
				EXPECT_EQ(1, tValueA) << "�擪���珇�Ƀf�[�^���擾�ł��Ă��Ȃ�";
				EXPECT_EQ(2, tValueB) << "�擪���珇�Ƀf�[�^���擾�ł��Ă��Ȃ�";
				EXPECT_EQ(0, queue.Size()) << "���X�g����v�f���폜�ł��Ă��Ȃ�";
			}

		}
		
	}
}