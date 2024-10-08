//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ。
#include <gtest/gtest.h>

// 例。自分の双方向リスト
#include "../1_4/LinkedList.h"

#include "List_ManualTest.h"

namespace ex01_DataStructure
{
	namespace chapter4
	{
		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		データのソート機能について、不適切なキー指定ができないかのテスト
			@details	ID:リスト-7(手動)\n
						データのソート機能のテストです。\n
						不適切なキー指定が禁止されているかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_SORT_BY_FRAUD_KEYマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestSortByFraudKey)
		{
#if defined TT_TEST_SORT_BY_FRAUD_KEY
			struct UserData
			{
				int _Age;
				float _Stature;
			};
			struct Dummy
			{
				int value;
			};
			LinkedList<UserData> list;
			list.Sort([](const Dummy& a, const Dummy& b) {return a.value < b.value; });	// ここでエラー
#endif //TT_TEST_SORT_BY_FRAUD_KEY
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		データのソート機能について、constのメソッドであるかのテスト
			@details	ID:リスト-8(手動)\n
						データのソート機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_SORT_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestSortIsConst)
		{
#if defined TT_TEST_SORT_IS_CONST
			struct UserData
			{
				int _Age;
				float _Stature;
			};
			const LinkedList<UserData> list;
			list.Sort(false, &UserData::_Age);	// ここでエラー
#endif //TT_TEST_SORT_IS_CONST
			SUCCEED();
		}


	}	// chapter4
}	//	ex01_DataStructure
