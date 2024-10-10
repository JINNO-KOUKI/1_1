// GoogleTest�̃w�b�_
#include <gtest/gtest.h>

// ���g�̃n�b�V���`�F�C���@�R���e�i�N���X
#include "../1_6/ChainHash.h"

namespace ex01_DataStructure
{
	namespace chapter6
	{
		/// @brief			�e�X�g�ɗ��p����n�b�V���֐�A
		unsigned int HashA(int key)
		{
			return key % 5;
		}
		/// @brief			�e�X�g�ɗ��p����n�b�V���֐�B
		unsigned int HashB(int key)
		{
			return key % 10;
		}
		/// @brief �e�X�g�ɗ��p����A���0��Ԃ��n�b�V���֐�
		unsigned int HashAllZero(int key) { return 0; }

		/// @brief �e�X�g�ɗ��p����`�F�C���n�b�V��A�̃e���v���[�g�^
		using ChainHashA = ChainHash<int, int, HashA, 5 >;
		/// @brief �e�X�g�ɗ��p����`�F�C���n�b�V��B�̃e���v���[�g�^
		using ChainHashB = ChainHash<int, int, HashB, 10 >;
		/// @brief �e�X�g�ɗ��p�����ɓ���n�b�V���݂̂̃e���v���[�g�^
		using ChainHashAllZero = ChainHash<int, int, HashAllZero, 10 >;

		//=================================== �N���X�̋��� ===================================
		namespace ClassBehaviourTest
		{
			/**********************************************************************************//**
				@brief		�Z�o���@�̈قȂ�A�K�؂ȃn�b�V���֐����e���v���[�g�ɓn�����ꍇ�̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-1\n
							�N���X�̋����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�}���֐��̖߂�l = TRUE	\n
							�E�폜�֐��̖߂�l = TRUE	\n
							�E�����֐��̖߂�l = TRUE	
			*//***********************************************************************************/
			TEST(ClassBehaviourTest, TestFuncWhenTrueHash)
			{
				// -- �ϐ��錾
				ChainHashA chainHashA;
				ChainHashB chainHashB;

				// -- �m�F�e�X�g
				// �}���֐��̎��s
				ASSERT_TRUE(chainHashA.Add(0, 1)) << "�v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHashA.Add(1, 2)) << "�v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHashB.Add(0, 1)) << "�v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHashB.Add(1, 2)) << "�v�f�̑}���Ɏ��s����";

				// �폜�֐��̎��s
				ASSERT_TRUE(chainHashA.Remove(0)) << "�v�f�̍폜�Ɏ��s����";
				ASSERT_TRUE(chainHashB.Remove(0)) << "�v�f�̍폜�Ɏ��s����";

				// �����֐��̎��s
				int tValueA = 0;
				ASSERT_TRUE(chainHashA.Find(1, tValueA)) << "�v�f�̌����Ɏ��s����";
				int tValueB = 0;
				ASSERT_TRUE(chainHashB.Find(1, tValueB)) << "�v�f�̌����Ɏ��s����";
			}
		}

		//=================================== �f�[�^���̎擾 ===================================
		namespace GetDataNumTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-2\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 0				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenEmpty)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �m�F�e�X�g
				EXPECT_EQ(0, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f��}��������̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-3\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 1				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterAdd)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f��}�����A���̃L�[�ō폜������̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-4\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 0				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterAddAndRemove)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";

				// -- �v�f�̍폜
				ASSERT_TRUE(chainHash.Remove(0)) << "�v�f�̍폜�Ɏ��s����";

				// -- �m�F�e�X�g
				EXPECT_EQ(0, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���ɑ��݂���L�[�ŗv�f��}�����A���s������̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-5\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 1				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterAddDupKey)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";

				// -- �d���L�[�ŗv�f��}��(���s�z��)
				ASSERT_FALSE(chainHash.Add(0, 2)) << "���s����͂��́A�d���L�[�ɂ��ǉ��ɐ�������";

				// -- �m�F�e�X�g
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɗv�f�����鎞�ɑ��݂��Ȃ��L�[���w�肵�v�f�̍폜�Ɏ��s�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-6\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 1				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterRemoveFailed)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";

				// -- ���݂��Ȃ��L�[�ō폜(���s�z��)
				ASSERT_FALSE(chainHash.Remove(1)) << "���s����͂��́A���݂��Ȃ��L�[�ɂ��폜�ɐ�������";

				// -- �m�F�e�X�g
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-7\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 0				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenRemoveEmpty)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �v�f�̍폜(���s�z��)
				ASSERT_FALSE(chainHash.Remove(0)) << "���s����͂��́A�v�f���Ȃ���Ԃł̍폜�ɐ���";

				// -- �m�F�e�X�g
				EXPECT_EQ(0, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-8\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 2				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenNotChain)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(�ʃn�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����Ɉ�����폜�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-9\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 1
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterRemoveOnceNotChain)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(�ʃn�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �v�f�̍폜(1��)
				ASSERT_TRUE(chainHash.Remove(0)) << "�v�f�̍폜�Ɏ��s����";

				// -- �m�F�e�X�g
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
 			}

			/**********************************************************************************//**
				@brief		�v�f�Q�������Ń`�F�C���ɂȂ������̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-10\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f�� = 2
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenChain)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�v�f�Q�������Ń`�F�C���ɂȂ������Ɉ�����폜�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-11\n
							�f�[�^���̎擾�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�v�f��			= 1
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterRemoveOnceChain)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �v�f�̍폜
				ASSERT_TRUE(chainHash.Remove(0)) << "�v�f�̍폜�Ɏ��s����";

				// --  �m�F�e�X�g
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

		}

		//=================================== �f�[�^�̑}�� ===================================
		namespace AddDataTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�}�������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-13\n
							�f�[�^�̑}���e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�}���֐��̖߂�l	= TRUE	\n
							�E�v�f��			= 1
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddWhenEmpty)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �m�F�e�X�g
				// �v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "���X�g����ł���ꍇ�̗v�f�̑}���Ɏ��s����";

				// �T�C�Y�̊m�F
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����Ȃ��ő}�������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-14\n
							�f�[�^�̑}���e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�}���֐��̖߂�l	= TRUE	\n
							�E�v�f��			= 3
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddNotDupKeyWhenMultiElem)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̑}��
				ASSERT_TRUE(chainHash.Add(2, 3)) << "�����v�f�������Ԃł̑}���Ɏ��s����";
				
				// �T�C�Y�̊m�F
				EXPECT_EQ(3, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�L�[���d�����đ}�����悤�Ƃ����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-15\n
							�f�[�^�̑}���e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�}���֐��̖߂�l	= FALSE	\n
							�E�v�f��			= 2
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddDupKeyWhenMultiElem)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̑}��(�d���L�[)(���s�z��)
				ASSERT_FALSE(chainHash.Add(1, 3)) << "���s����͂��́A�d���L�[�ɂ��}���ɐ�������";

				// �T�C�Y�̊m�F
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���Ƀ��X�g�ɂ���v�f�ƃn�b�V���l�������ɂȂ�L�[�ő}�������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-16\n
							�f�[�^�̑}���e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�}���֐��̖߂�l	= TRUE	\n
							�E�v�f��			= 2		\n
							�E�`�F�C����		= 1
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddEqHash)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̑}��(����n�b�V��)
				ASSERT_TRUE(chainHash.Add(1, 2)) << "����n�b�V���ɂ��A�v�f�̑}���Ɏ��s����";

				// �T�C�Y�̊m�F
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
				 
				// �`�F�C�����̊m�F
				EXPECT_EQ(1, chainHash.ChainSize()) << "�z�肵�Ă���`�F�C�����ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		��x�}�����A�폜������ēx�����L�[�ő}�������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-17\n
							�f�[�^�̑}���e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�}���֐��̖߂�l	= TRUE		\n
							�E�v�f��			= 1			\n
							�E�v�f				= �����v�fA
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddEqKeyWhenAddAndRemove)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";

				// -- �v�f�̍폜
				ASSERT_TRUE(chainHash.Remove(0)) << "�v�f�̍폜�Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̑}��(�����v�f�Ɠ���̃L�[)
				ASSERT_TRUE(chainHash.Add(0, 2)) << "��x�폜���ꂽ�L�[�Ɠ���̃L�[�ł̑}���Ɏ��s����";

				// �T�C�Y�̊m�F
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";

				// �i�[�v�f�̊m�F
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "�i�[�v�f�̎擾�Ɏ��s����";
				EXPECT_EQ(ChainHashA::Pair(0, 2), *(list.Begin())) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
			}

		}

		//=================================== �f�[�^�̍폜 ===================================
		namespace RemoveDataTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�폜��������悤�Ƃ����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-19\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�폜�֐��̖߂�l	= FALSE
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveWhenEmpty)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �m�F�e�X�g
				// �v�f�̍폜(���s�z��)
				ASSERT_FALSE(chainHash.Remove(0)) << "���s����͂��́A���X�g����̏�Ԃł̍폜�ɐ�������";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�č폜�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-20\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�폜�֐��̖߂�l	= TRUE		\n
							�E�v�f��			= 1			\n
							�E�i�[�v�f			= �����v�fA
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveTrueKey)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̍폜
				ASSERT_TRUE(chainHash.Remove(1)) << "�����̗v�f������ۂ́A�v�f�̍폜�Ɏ��s����";
				
				// �T�C�Y�̊m�F
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
				
				// �i�[�v�f�̊m�F
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "�i�[�v�f�̎擾�Ɏ��s����";
				EXPECT_EQ(ChainHashA::Pair(0, 1), *(list.Begin())) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�č폜���悤�Ƃ����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-21\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >					\n
							�E�폜�֐��̖߂�l	= FALSE					\n
							�E�v�f��			= 2						\n
							�E�i�[�v�f			= �����v�fA, �����v�fB
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveFalseKey)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̍폜(���݂��Ȃ��L�[)(���s�z��)
				ASSERT_FALSE(chainHash.Remove(2)) << "���s����͂��́A���݂��Ȃ��L�[�ł̍폜�ɐ�������";

				// �T�C�Y�̊m�F
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";

				// �i�[�v�f�̊m�F
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "�i�[�v�f�̎擾�Ɏ��s����";
				LinkedList<ChainHashA::Pair>::Iterator it = list.Begin();
				EXPECT_EQ(ChainHashA::Pair(0, 1), *it) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
				++it;
				EXPECT_EQ(ChainHashA::Pair(1, 2), *it) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		��x�폜�����L�[�ōēx�폜���悤�Ƃ����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-22\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�폜�֐��̖߂�l	= FALSE		\n
							�E�v�f��			= 1			\n
							�E�i�[�v�f			= �����v�fA
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveByRemovedKey)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �v�f�̍폜
				ASSERT_TRUE(chainHash.Remove(1)) << "�v�f�̍폜�Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̍폜(�폜�v�f�Ɠ���̃L�[)(���s�z��)
				ASSERT_FALSE(chainHash.Remove(1)) << "���s����͂��́A���ɍ폜�����L�[�ł̍폜�ɐ�������";

				// �T�C�Y�̊m�F
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";

				// �i�[�v�f�̊m�F
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "�i�[�v�f�̎擾�Ɏ��s����";
				EXPECT_EQ(ChainHashA::Pair(0, 1), *(list.Begin())) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�`�F�C���ɂȂ��Ă���v�f�̂���1�̃L�[���w�肵�č폜�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-23\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�폜�֐��̖߂�l	= TRUE		\n
							�E�v�f��			= 1			\n
							�E�i�[�v�f			= �����v�fA
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveOnceByChain)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̍폜
				ASSERT_TRUE(chainHash.Remove(1)) << "�`�F�C���ɂȂ��Ă���v�f�̍폜�Ɏ��s����";

				// �T�C�Y�̊m�F
				EXPECT_EQ(1, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";

				// �i�[�v�f�̊m�F
				LinkedList<ChainHashAllZero::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "�i�[�v�f�̎擾�Ɏ��s����";
				EXPECT_EQ(ChainHashAllZero::Pair(0, 1), *(list.Begin())) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�`�F�C���ɂȂ��Ă���v�f�ƃn�b�V���l�����������A���݂��Ȃ��L�[���w�肵�č폜�����ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-24\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >			\n
							�E�폜�֐��̖߂�l	= FALSE			\n
							�E�v�f��			= 2				\n
							�E�`�F�C����		= 1				\n
							�E�i�[�v�f			= �����v�fA, B
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveEqHashFalseKey)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̍폜(�����v�f�Ɠ���n�b�V��&�ʃL�[)(���s�z��)
				ASSERT_FALSE(chainHash.Remove(10)) << "���s����͂��́A����n�b�V�����s���L�[�ł̍폜�ɐ�������";

				// �T�C�Y�̊m�F
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";

				// �`�F�C�����̊m�F
				EXPECT_EQ(1, chainHash.ChainSize()) << "�z�肵�Ă���`�F�C���T�C�Y�ƈقȂ�";

				// �i�[�v�f�̊m�F
				LinkedList<ChainHashAllZero::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "�i�[�v�f�̎擾�Ɏ��s����";
				LinkedList<ChainHashAllZero::Pair>::Iterator it = list.Begin();
				EXPECT_EQ(ChainHashAllZero::Pair(1, 2), *it) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
				++it;
				EXPECT_EQ(ChainHashAllZero::Pair(0, 1), *it) << "�i�[����Ă���v�f���A�z�肵�Ă�����̂ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		�`�F�C���ɂȂ��Ă���v�f�����ɍ폜���Ă������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-25\n
							�f�[�^�̍폜�e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >			\n
							�E�폜�֐��̖߂�l	= TRUE			\n
							�E�v�f��			= 0				
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveAll)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̍폜(2��)
				ASSERT_TRUE(chainHash.Remove(1)) << "�`�F�C���ɂȂ��Ă���v�f�̍폜�Ɏ��s����";
				ASSERT_TRUE(chainHash.Remove(0)) << "�`�F�C���ɂȂ��Ă���v�f�̍폜�Ɏ��s����";

				// �T�C�Y�̊m�F
				EXPECT_EQ(0, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}
		}

		//=================================== �f�[�^�̌��� ===================================
		namespace FindDataTest
		{
			/**********************************************************************************//**
				@brief		���X�g����ł���ꍇ�ɁA�L�[���w�肵�Č��������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-27\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�����֐��̖߂�l	= FALSE	\n	
							�E�擾����			= �Ȃ�
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindWhenEmpty)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �m�F�e�X�g
				// �v�f�̌���
				int tValue = 0;
				EXPECT_FALSE(chainHash.Find(0, tValue)) << "���s����͂��́A�v�f�����݂��Ȃ���Ԃł̌����ɐ�������";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA���݂���L�[�Ŏw�肵�Č��������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-28\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�����֐��̖߂�l	= TRUE		\n	
							�E�擾����			= �����v�fA			
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindWhenMultiElem)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̌���
				int tValue = 0;
				EXPECT_TRUE(chainHash.Find(0, tValue)) << "���݂���L�[�ł̗v�f�̌����Ɏ��s����";

				// �擾���ʂ̊m�F
				EXPECT_EQ(1, tValue) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ŏw�肵�Č��������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-29\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�����֐��̖߂�l	= FALSE		\n	
							�E�擾����			= �Ȃ�			
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByFalseKeyWhenMultiElem)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̌���(���݂��Ȃ��L�[)(���s�z��)
				int tValue = 0;
				EXPECT_FALSE(chainHash.Find(2, tValue)) << "���s����͂��́A���݂��Ȃ��L�[�ł̌����ɐ�������";

				// �擾���ʂ̊m�F
				EXPECT_EQ(0, tValue) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";

			}

			/**********************************************************************************//**
				@brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�����L�[��2�A���Ō��������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-30\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >				\n
							�E�����֐��̖߂�l	= TRUE				\n	
							�E�擾����			= �����A�����v�fA	\n
							�E�v�f��			= 2
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindTwiceByEqKeyWhenMultiElem)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̌���(����L�[��2��)
				int tValueA = 0;
				EXPECT_TRUE(chainHash.Find(0, tValueA)) << "�v�f�̌����Ɏ��s����";
				int tValueB = 0;
				EXPECT_TRUE(chainHash.Find(0, tValueB)) << "�O��̌����Ɠ���̃L�[�ł́A�v�f�̌����Ɏ��s����";

				// �擾���ʂ̊m�F
				EXPECT_EQ(1, tValueA) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";
				EXPECT_EQ(1, tValueB) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";

				// �T�C�Y�̊m�F
				EXPECT_EQ(2, chainHash.Size()) << "�z�肵�Ă���T�C�Y�ƈقȂ�";
			}

			/**********************************************************************************//**
				@brief		���ɍ폜���ꂽ�L�[�Ō��������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-31\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >	\n
							�E�����֐��̖߂�l	= FALSE	\n	
							�E�擾����			= �Ȃ�
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByRemovedKey)
			{
				// -- �ϐ��錾
				ChainHashA chainHash;

				// -- �����v�f�̑}��(2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �v�f�̍폜(1��)
				ASSERT_TRUE(chainHash.Remove(1)) << "�v�f�̍폜�Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̌���(�폜�����v�f�Ɠ���̃L�[)(���s�z��)
				int tValue = 0;
				EXPECT_FALSE(chainHash.Find(1, tValue)) << "���s����͂��́A�폜�����L�[�ł̌����ɐ�������";

				// �擾���ʂ̊m�F
				EXPECT_EQ(0, tValue) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";

			}

			/**********************************************************************************//**
				@brief		�`�F�C���ɂȂ��Ă���v�f�̓���1�̃L�[���w�肵�Č��������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-32\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�����֐��̖߂�l	= TRUE		\n	
							�E�擾����			= �����v�fA	
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByOnceInChain)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̌���
				int tValue = 0;
				EXPECT_TRUE(chainHash.Find(0, tValue)) << "�`�F�C���ɂȂ��Ă���v�f�̌����Ɏ��s����";

				// �擾���ʂ̊m�F
				EXPECT_EQ(1, tValue) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";

			}

			/**********************************************************************************//**
				@brief		�`�F�C���ɂȂ��Ă���v�f������1�̍폜������ɁA�c���Ă���v�f�����������ۂ̎��s�e�X�g
				@details	ID:�n�b�V���e�[�u��-33\n
							�f�[�^�̌����e�X�g�ł��B\n
							< �m�F���� = ���҂��錋�� >		\n
							�E�����֐��̖߂�l	= TRUE		\n	
							�E�擾����			= �����v�fA	
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByOnceInChainWhenRemovedOnceInChain)
			{
				// -- �ϐ��錾
				ChainHashAllZero chainHash;

				// -- �����v�f�̑}��(����n�b�V����2��)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "�����v�f�̑}���Ɏ��s����";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "�����v�f�̑}���Ɏ��s����";

				// �v�f�̍폜(1��)
				ASSERT_TRUE(chainHash.Remove(1)) << "�`�F�C���ɂȂ��Ă���v�f�̍폜�Ɏ��s����";

				// -- �m�F�e�X�g
				// �v�f�̌���(�c���Ă��鏉���v�f)
				int tValue = 0;
				EXPECT_TRUE(chainHash.Find(0, tValue)) << "����`�F�C�����v�f���폜���ꂽ��̌����Ɏ��s����";

				// �擾���ʂ̊m�F
				EXPECT_EQ(1, tValue) << "�������ʂ��A�z�肵�Ă�����̂ƈقȂ�";

			}
		}
	}
}