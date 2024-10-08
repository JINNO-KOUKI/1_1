//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ。
#include <gtest/gtest.h>

// 例。自分の双方向リスト
#include "../1_5/Stack.h"
#include "../1_5/Queue.h"

#include "StackQueue_ManualTest.h"

namespace ex01_DataStructure
{
	namespace chapter5
	{
		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		スタックのサイズ取得機能について、constのメソッドであるかのテスト
			@details	ID:スタック-7(手動)\n
						スタックのサイズ取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_STACK_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(StackQueueManualTest, TestStackGetDataNumIsConst)
		{
#if defined TT_TEST_STACK_GET_DATA_NUM_IS_CONST

			const Stack<int> stack;
			stack.Size();
#endif //TT_TEST_STACK_GET_DATA_NUM_IS_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		スタックのプッシュ機能について、非constのメソッドであるかのテスト
			@details	ID:スタック-10(手動)\n
						スタックのプッシュ機能のテストです。\n
						非constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_STACK_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(StackQueueManualTest, TestStackPushIsNotConst)
		{
#if defined TT_TEST_STACK_PUSH_IS_NOT_CONST

			const Stack<int> stack;
			stack.Push(1);	// ここでエラー
#endif //TT_TEST_STACK_PUSH_IS_NOT_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		スタックのポップ機能について、非constのメソッドであるかのテスト
			@details	ID:スタック-14(手動)\n
						スタックのポップ機能のテストです。\n
						非constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_STACK_POP_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(StackQueueManualTest, TestStackPopIsNotConst)
		{
#if defined TT_TEST_STACK_POP_IS_NOT_CONST

			const Stack<int> stack;
			int tValue;
			stack.Pop(tValue);	// ここでエラー
#endif //TT_TEST_STACK_POP_IS_NOT_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		キューのサイズ取得機能について、constのメソッドであるかのテスト
			@details	ID:キュー-7(手動)\n
						キューのサイズ取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_QUEUE_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(StackQueueManualTest, TestQueueGetDataNumIsConst)
		{
#if defined TT_TEST_QUEUE_GET_DATA_NUM_IS_CONST

			const Queue<int> queue;
			queue.Size();
#endif //TT_TEST_QUEUE_GET_DATA_NUM_IS_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		キューのプッシュ機能について、非constのメソッドであるかのテスト
			@details	ID:キュー-10(手動)\n
						キューのプッシュ機能のテストです。\n
						非constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_QUEUE_PUSH_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(StackQueueManualTest, TestQueuePushIsNotConst)
		{
#if defined TT_TEST_QUEUE_PUSH_IS_NOT_CONST

			const Queue<int> queue;
			queue.Push(1);	// ここでエラー
#endif //TT_TEST_QUEUE_PUSH_IS_NOT_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		キューのポップ機能について、非constのメソッドであるかのテスト
			@details	ID:キュー-14(手動)\n
						キューのポップ機能のテストです。\n
						非constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_QUEUE_POP_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(StackQueueManualTest, TestQueuePopIsNotConst)
		{
#if defined TT_TEST_QUEUE_POP_IS_NOT_CONST

			const Queue<int> queue;
			int tValue;
			queue.Pop(tValue);	// ここでエラー
#endif //TT_TEST_QUEUE_POP_IS_NOT_CONST
			SUCCEED();
		}


	}	// chapter5
}	//	ex01_DataStructure
