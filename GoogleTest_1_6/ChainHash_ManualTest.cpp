//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ。
#include <gtest/gtest.h>

// 例。自分の双方向リスト
#include "../1_6/ChainHash.h"

#include "ChainHash_ManualTest.h"

namespace ex01_DataStructure
{
	namespace chapter6
	{
		/// @brief 適切なハッシュ関数
		unsigned int GoodHash(int key) { return static_cast<unsigned int>(key); }
		/// @brief 不適切なハッシュ関数
		void BadHash(int) { return; }

		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		チェインハッシュのテンプレート機能について、不適切なハッシュ関数を指定できないかのテスト
			@details	ID:ハッシュテーブル-0(手動)\n
						チェインハッシュのクラス挙動のテストです。\n
						不適切なハッシュ関数を指定できないかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_CHAIN_HASH_TEMPLATEマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ChainHashManualTest, TestChainHashTemplate)
		{
#if defined TT_TEST_CHAIN_HASH_TEMPLATE

			ChainHash<int, int, BadHash, 10> chainHash;	// ここでエラー
			
#endif //TT_TEST_CHAIN_HASH_TEMPLATE
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		チェインハッシュのサイズ取得機能について、constのメソッドであるかのテスト
			@details	ID:ハッシュテーブル-12(手動)\n
						チェインハッシュのサイズ取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ChainHashManualTest, TestGetDataNumIsConst)
		{
#if defined TT_TEST_GET_DATA_NUM_IS_CONST

			const ChainHash<int, int, GoodHash, 10> chainHash;
			chainHash.Size();
			
#endif //TT_TEST_GET_DATA_NUM_IS_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		チェインハッシュのデータ挿入機能について、非constのメソッドであるかのテスト
			@details	ID:ハッシュテーブル-18(手動)\n
						チェインハッシュのデータ挿入機能のテストです。\n
						非constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_ADD_DATA_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ChainHashManualTest, TestAddDataIsNotConst)
		{
#if defined TT_TEST_ADD_DATA_IS_NOT_CONST

			const ChainHash<int, int, GoodHash, 10> chainHash;
			chainHash.Add(0, 1);	// ここでエラー

#endif //TT_TEST_ADD_DATA_IS_NOT_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		チェインハッシュのデータ削除機能について、非constのメソッドであるかのテスト
			@details	ID:ハッシュテーブル-26(手動)\n
						チェインハッシュのデータ削除機能のテストです。\n
						非constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通らなければ成功です。\n
						TT_TEST_REMOVE_DATA_IS_NOT_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ChainHashManualTest, TestRemoveDataIsNotConst)
		{
#if defined TT_TEST_REMOVE_DATA_IS_NOT_CONST

			const ChainHash<int, int, GoodHash, 10> chainHash;
			chainHash.Remove(0);	// ここでエラー

#endif //TT_TEST_REMOVE_DATA_IS_NOT_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		チェインハッシュのデータ検索機能について、constのメソッドであるかのテスト
			@details	ID:ハッシュテーブル-34(手動)\n
						チェインハッシュのデータ検索機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_FIND_DATA_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(ChainHashManualTest, TestFindDataIsConst)
		{
#if defined TT_TEST_FIND_DATA_IS_CONST

			const ChainHash<int, int, GoodHash, 10> chainHash;
			int tValue = 0;
			chainHash.Find(0, tValue);

#endif //TT_TEST_FIND_DATA_IS_CONST
			SUCCEED();
		}


	}	// chapter6
}	//	ex01_DataStructure
