// GoogleTestのヘッダ
#include <gtest/gtest.h>

// 自身のハッシュチェイン法コンテナクラス
#include "../1_6/ChainHash.h"

namespace ex01_DataStructure
{
	namespace chapter6
	{
		/// @brief			テストに利用するハッシュ関数A
		unsigned int HashA(int key)
		{
			return key % 5;
		}
		/// @brief			テストに利用するハッシュ関数B
		unsigned int HashB(int key)
		{
			return key % 10;
		}
		/// @brief テストに利用する、常に0を返すハッシュ関数
		unsigned int HashAllZero(int key) { return 0; }

		/// @brief テストに利用するチェインハッシュAのテンプレート型
		using ChainHashA = ChainHash<int, int, HashA, 5 >;
		/// @brief テストに利用するチェインハッシュBのテンプレート型
		using ChainHashB = ChainHash<int, int, HashB, 10 >;
		/// @brief テストに利用する常に同一ハッシュのみのテンプレート型
		using ChainHashAllZero = ChainHash<int, int, HashAllZero, 10 >;

		//=================================== クラスの挙動 ===================================
		namespace ClassBehaviourTest
		{
			/**********************************************************************************//**
				@brief		算出方法の異なる、適切なハッシュ関数をテンプレートに渡した場合の実行テスト
				@details	ID:ハッシュテーブル-1\n
							クラスの挙動テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・挿入関数の戻り値 = TRUE	\n
							・削除関数の戻り値 = TRUE	\n
							・検索関数の戻り値 = TRUE	
			*//***********************************************************************************/
			TEST(ClassBehaviourTest, TestFuncWhenTrueHash)
			{
				// -- 変数宣言
				ChainHashA chainHashA;
				ChainHashB chainHashB;

				// -- 確認テスト
				// 挿入関数の実行
				ASSERT_TRUE(chainHashA.Add(0, 1)) << "要素の挿入に失敗した";
				ASSERT_TRUE(chainHashA.Add(1, 2)) << "要素の挿入に失敗した";
				ASSERT_TRUE(chainHashB.Add(0, 1)) << "要素の挿入に失敗した";
				ASSERT_TRUE(chainHashB.Add(1, 2)) << "要素の挿入に失敗した";

				// 削除関数の実行
				ASSERT_TRUE(chainHashA.Remove(0)) << "要素の削除に失敗した";
				ASSERT_TRUE(chainHashB.Remove(0)) << "要素の削除に失敗した";

				// 検索関数の実行
				int tValueA = 0;
				ASSERT_TRUE(chainHashA.Find(1, tValueA)) << "要素の検索に失敗した";
				int tValueB = 0;
				ASSERT_TRUE(chainHashB.Find(1, tValueB)) << "要素の検索に失敗した";
			}
		}

		//=================================== データ数の取得 ===================================
		namespace GetDataNumTest
		{
			/**********************************************************************************//**
				@brief		リストが空である場合の実行テスト
				@details	ID:ハッシュテーブル-2\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 0				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenEmpty)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 確認テスト
				EXPECT_EQ(0, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		要素を挿入した後の実行テスト
				@details	ID:ハッシュテーブル-3\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 1				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterAdd)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		要素を挿入し、そのキーで削除した後の実行テスト
				@details	ID:ハッシュテーブル-4\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 0				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterAddAndRemove)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";

				// -- 要素の削除
				ASSERT_TRUE(chainHash.Remove(0)) << "要素の削除に失敗した";

				// -- 確認テスト
				EXPECT_EQ(0, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		既に存在するキーで要素を挿入し、失敗した後の実行テスト
				@details	ID:ハッシュテーブル-5\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 1				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterAddDupKey)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";

				// -- 重複キーで要素を挿入(失敗想定)
				ASSERT_FALSE(chainHash.Add(0, 2)) << "失敗するはずの、重複キーによる追加に成功した";

				// -- 確認テスト
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		リストに要素がある時に存在しないキーを指定し要素の削除に失敗した際の実行テスト
				@details	ID:ハッシュテーブル-6\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 1				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterRemoveFailed)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";

				// -- 存在しないキーで削除(失敗想定)
				ASSERT_FALSE(chainHash.Remove(1)) << "失敗するはずの、存在しないキーによる削除に成功した";

				// -- 確認テスト
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		リストが空である場合に、削除を行った際の実行テスト
				@details	ID:ハッシュテーブル-7\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 0				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenRemoveEmpty)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 要素の削除(失敗想定)
				ASSERT_FALSE(chainHash.Remove(0)) << "失敗するはずの、要素がない状態での削除に成功";

				// -- 確認テスト
				EXPECT_EQ(0, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		要素２つが内部でチェインになっていない時の実行テスト
				@details	ID:ハッシュテーブル-8\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 2				
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenNotChain)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(別ハッシュで2つ)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		要素２つが内部でチェインになっていない時に一方を削除した際の実行テスト
				@details	ID:ハッシュテーブル-9\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 1
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterRemoveOnceNotChain)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(別ハッシュで2つ)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 要素の削除(1回)
				ASSERT_TRUE(chainHash.Remove(0)) << "要素の削除に失敗した";

				// -- 確認テスト
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
 			}

			/**********************************************************************************//**
				@brief		要素２つが内部でチェインになった時の実行テスト
				@details	ID:ハッシュテーブル-10\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数 = 2
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenChain)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2つ)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		要素２つが内部でチェインになった時に一方を削除した際の実行テスト
				@details	ID:ハッシュテーブル-11\n
							データ数の取得テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・要素数			= 1
			*//***********************************************************************************/
			TEST(GetDataNumTest, TestSizeWhenAfterRemoveOnceChain)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2つ)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 要素の削除
				ASSERT_TRUE(chainHash.Remove(0)) << "要素の削除に失敗した";

				// --  確認テスト
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
			}

		}

		//=================================== データの挿入 ===================================
		namespace AddDataTest
		{
			/**********************************************************************************//**
				@brief		リストが空である場合に、挿入した際の実行テスト
				@details	ID:ハッシュテーブル-13\n
							データの挿入テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・挿入関数の戻り値	= TRUE	\n
							・要素数			= 1
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddWhenEmpty)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 確認テスト
				// 要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "リストが空である場合の要素の挿入に失敗した";

				// サイズの確認
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、キーが重複しないで挿入した際の実行テスト
				@details	ID:ハッシュテーブル-14\n
							データの挿入テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・挿入関数の戻り値	= TRUE	\n
							・要素数			= 3
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddNotDupKeyWhenMultiElem)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の挿入
				ASSERT_TRUE(chainHash.Add(2, 3)) << "複数要素がある状態での挿入に失敗した";
				
				// サイズの確認
				EXPECT_EQ(3, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、キーが重複して挿入しようとした際の実行テスト
				@details	ID:ハッシュテーブル-15\n
							データの挿入テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・挿入関数の戻り値	= FALSE	\n
							・要素数			= 2
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddDupKeyWhenMultiElem)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の挿入(重複キー)(失敗想定)
				ASSERT_FALSE(chainHash.Add(1, 3)) << "失敗するはずの、重複キーによる挿入に成功した";

				// サイズの確認
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		既にリストにある要素とハッシュ値が同じになるキーで挿入した際の実行テスト
				@details	ID:ハッシュテーブル-16\n
							データの挿入テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・挿入関数の戻り値	= TRUE	\n
							・要素数			= 2		\n
							・チェイン数		= 1
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddEqHash)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の挿入(同一ハッシュ)
				ASSERT_TRUE(chainHash.Add(1, 2)) << "同一ハッシュによる、要素の挿入に失敗した";

				// サイズの確認
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";
				 
				// チェイン数の確認
				EXPECT_EQ(1, chainHash.ChainSize()) << "想定しているチェイン数と異なる";
			}

			/**********************************************************************************//**
				@brief		一度挿入し、削除した後再度同じキーで挿入した際の実行テスト
				@details	ID:ハッシュテーブル-17\n
							データの挿入テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・挿入関数の戻り値	= TRUE		\n
							・要素数			= 1			\n
							・要素				= 初期要素A
			*//***********************************************************************************/
			TEST(AddDataTest, TestAddEqKeyWhenAddAndRemove)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";

				// -- 要素の削除
				ASSERT_TRUE(chainHash.Remove(0)) << "要素の削除に失敗した";

				// -- 確認テスト
				// 要素の挿入(初期要素と同一のキー)
				ASSERT_TRUE(chainHash.Add(0, 2)) << "一度削除されたキーと同一のキーでの挿入に失敗した";

				// サイズの確認
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";

				// 格納要素の確認
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "格納要素の取得に失敗した";
				EXPECT_EQ(ChainHashA::Pair(0, 2), *(list.Begin())) << "格納されている要素が、想定しているものと異なる";
			}

		}

		//=================================== データの削除 ===================================
		namespace RemoveDataTest
		{
			/**********************************************************************************//**
				@brief		リストが空である場合に、削除操作をしようとした際の実行テスト
				@details	ID:ハッシュテーブル-19\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・削除関数の戻り値	= FALSE
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveWhenEmpty)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 確認テスト
				// 要素の削除(失敗想定)
				ASSERT_FALSE(chainHash.Remove(0)) << "失敗するはずの、リストが空の状態での削除に成功した";
			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、存在するキーで指定して削除した際の実行テスト
				@details	ID:ハッシュテーブル-20\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・削除関数の戻り値	= TRUE		\n
							・要素数			= 1			\n
							・格納要素			= 初期要素A
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveTrueKey)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の削除
				ASSERT_TRUE(chainHash.Remove(1)) << "複数の要素がある際の、要素の削除に失敗した";
				
				// サイズの確認
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";
				
				// 格納要素の確認
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "格納要素の取得に失敗した";
				EXPECT_EQ(ChainHashA::Pair(0, 1), *(list.Begin())) << "格納されている要素が、想定しているものと異なる";
			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、存在しないキーで指定して削除しようとした際の実行テスト
				@details	ID:ハッシュテーブル-21\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >					\n
							・削除関数の戻り値	= FALSE					\n
							・要素数			= 2						\n
							・格納要素			= 初期要素A, 初期要素B
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveFalseKey)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の削除(存在しないキー)(失敗想定)
				ASSERT_FALSE(chainHash.Remove(2)) << "失敗するはずの、存在しないキーでの削除に成功した";

				// サイズの確認
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";

				// 格納要素の確認
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "格納要素の取得に失敗した";
				LinkedList<ChainHashA::Pair>::Iterator it = list.Begin();
				EXPECT_EQ(ChainHashA::Pair(0, 1), *it) << "格納されている要素が、想定しているものと異なる";
				++it;
				EXPECT_EQ(ChainHashA::Pair(1, 2), *it) << "格納されている要素が、想定しているものと異なる";
			}

			/**********************************************************************************//**
				@brief		一度削除したキーで再度削除しようとした際の実行テスト
				@details	ID:ハッシュテーブル-22\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・削除関数の戻り値	= FALSE		\n
							・要素数			= 1			\n
							・格納要素			= 初期要素A
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveByRemovedKey)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 要素の削除
				ASSERT_TRUE(chainHash.Remove(1)) << "要素の削除に失敗した";

				// -- 確認テスト
				// 要素の削除(削除要素と同一のキー)(失敗想定)
				ASSERT_FALSE(chainHash.Remove(1)) << "失敗するはずの、既に削除したキーでの削除に成功した";

				// サイズの確認
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";

				// 格納要素の確認
				LinkedList<ChainHashA::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "格納要素の取得に失敗した";
				EXPECT_EQ(ChainHashA::Pair(0, 1), *(list.Begin())) << "格納されている要素が、想定しているものと異なる";
			}

			/**********************************************************************************//**
				@brief		チェインになっている要素のうち1つのキーを指定して削除した際の実行テスト
				@details	ID:ハッシュテーブル-23\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・削除関数の戻り値	= TRUE		\n
							・要素数			= 1			\n
							・格納要素			= 初期要素A
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveOnceByChain)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の削除
				ASSERT_TRUE(chainHash.Remove(1)) << "チェインになっている要素の削除に失敗した";

				// サイズの確認
				EXPECT_EQ(1, chainHash.Size()) << "想定しているサイズと異なる";

				// 格納要素の確認
				LinkedList<ChainHashAllZero::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "格納要素の取得に失敗した";
				EXPECT_EQ(ChainHashAllZero::Pair(0, 1), *(list.Begin())) << "格納されている要素が、想定しているものと異なる";
			}

			/**********************************************************************************//**
				@brief		チェインになっている要素とハッシュ値が同じだが、存在しないキーを指定して削除した際の実行テスト
				@details	ID:ハッシュテーブル-24\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >			\n
							・削除関数の戻り値	= FALSE			\n
							・要素数			= 2				\n
							・チェイン数		= 1				\n
							・格納要素			= 初期要素A, B
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveEqHashFalseKey)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の削除(初期要素と同一ハッシュ&別キー)(失敗想定)
				ASSERT_FALSE(chainHash.Remove(10)) << "失敗するはずの、同一ハッシュかつ不正キーでの削除に成功した";

				// サイズの確認
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";

				// チェイン数の確認
				EXPECT_EQ(1, chainHash.ChainSize()) << "想定しているチェインサイズと異なる";

				// 格納要素の確認
				LinkedList<ChainHashAllZero::Pair> list;
				ASSERT_TRUE(chainHash.GetAllData(list)) << "格納要素の取得に失敗した";
				LinkedList<ChainHashAllZero::Pair>::Iterator it = list.Begin();
				EXPECT_EQ(ChainHashAllZero::Pair(1, 2), *it) << "格納されている要素が、想定しているものと異なる";
				++it;
				EXPECT_EQ(ChainHashAllZero::Pair(0, 1), *it) << "格納されている要素が、想定しているものと異なる";
			}

			/**********************************************************************************//**
				@brief		チェインになっている要素を順に削除していった際の実行テスト
				@details	ID:ハッシュテーブル-25\n
							データの削除テストです。\n
							< 確認項目 = 期待する結果 >			\n
							・削除関数の戻り値	= TRUE			\n
							・要素数			= 0				
			*//***********************************************************************************/
			TEST(RemoveDataTest, TestRemoveAll)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の削除(2回)
				ASSERT_TRUE(chainHash.Remove(1)) << "チェインになっている要素の削除に失敗した";
				ASSERT_TRUE(chainHash.Remove(0)) << "チェインになっている要素の削除に失敗した";

				// サイズの確認
				EXPECT_EQ(0, chainHash.Size()) << "想定しているサイズと異なる";
			}
		}

		//=================================== データの検索 ===================================
		namespace FindDataTest
		{
			/**********************************************************************************//**
				@brief		リストが空である場合に、キーを指定して検索した際の実行テスト
				@details	ID:ハッシュテーブル-27\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・検索関数の戻り値	= FALSE	\n	
							・取得結果			= なし
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindWhenEmpty)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 確認テスト
				// 要素の検索
				int tValue = 0;
				EXPECT_FALSE(chainHash.Find(0, tValue)) << "失敗するはずの、要素が存在しない状態での検索に成功した";
			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、存在するキーで指定して検索した際の実行テスト
				@details	ID:ハッシュテーブル-28\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・検索関数の戻り値	= TRUE		\n	
							・取得結果			= 初期要素A			
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindWhenMultiElem)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の検索
				int tValue = 0;
				EXPECT_TRUE(chainHash.Find(0, tValue)) << "存在するキーでの要素の検索に失敗した";

				// 取得結果の確認
				EXPECT_EQ(1, tValue) << "検索結果が、想定しているものと異なる";
			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、存在しないキーで指定して検索した際の実行テスト
				@details	ID:ハッシュテーブル-29\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・検索関数の戻り値	= FALSE		\n	
							・取得結果			= なし			
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByFalseKeyWhenMultiElem)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の検索(存在しないキー)(失敗想定)
				int tValue = 0;
				EXPECT_FALSE(chainHash.Find(2, tValue)) << "失敗するはずの、存在しないキーでの検索に成功した";

				// 取得結果の確認
				EXPECT_EQ(0, tValue) << "検索結果が、想定しているものと異なる";

			}

			/**********************************************************************************//**
				@brief		リストに複数の要素がある場合に、同じキーで2連続で検索した際の実行テスト
				@details	ID:ハッシュテーブル-30\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >				\n
							・検索関数の戻り値	= TRUE				\n	
							・取得結果			= 両方、初期要素A	\n
							・要素数			= 2
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindTwiceByEqKeyWhenMultiElem)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の検索(同一キーで2回)
				int tValueA = 0;
				EXPECT_TRUE(chainHash.Find(0, tValueA)) << "要素の検索に失敗した";
				int tValueB = 0;
				EXPECT_TRUE(chainHash.Find(0, tValueB)) << "前回の検索と同一のキーでの、要素の検索に失敗した";

				// 取得結果の確認
				EXPECT_EQ(1, tValueA) << "検索結果が、想定しているものと異なる";
				EXPECT_EQ(1, tValueB) << "検索結果が、想定しているものと異なる";

				// サイズの確認
				EXPECT_EQ(2, chainHash.Size()) << "想定しているサイズと異なる";
			}

			/**********************************************************************************//**
				@brief		既に削除されたキーで検索した際の実行テスト
				@details	ID:ハッシュテーブル-31\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >	\n
							・検索関数の戻り値	= FALSE	\n	
							・取得結果			= なし
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByRemovedKey)
			{
				// -- 変数宣言
				ChainHashA chainHash;

				// -- 初期要素の挿入(2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 要素の削除(1回)
				ASSERT_TRUE(chainHash.Remove(1)) << "要素の削除に失敗した";

				// -- 確認テスト
				// 要素の検索(削除した要素と同一のキー)(失敗想定)
				int tValue = 0;
				EXPECT_FALSE(chainHash.Find(1, tValue)) << "失敗するはずの、削除したキーでの検索に成功した";

				// 取得結果の確認
				EXPECT_EQ(0, tValue) << "検索結果が、想定しているものと異なる";

			}

			/**********************************************************************************//**
				@brief		チェインになっている要素の内の1つのキーを指定して検索した際の実行テスト
				@details	ID:ハッシュテーブル-32\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・検索関数の戻り値	= TRUE		\n	
							・取得結果			= 初期要素A	
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByOnceInChain)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// -- 確認テスト
				// 要素の検索
				int tValue = 0;
				EXPECT_TRUE(chainHash.Find(0, tValue)) << "チェインになっている要素の検索に失敗した";

				// 取得結果の確認
				EXPECT_EQ(1, tValue) << "検索結果が、想定しているものと異なる";

			}

			/**********************************************************************************//**
				@brief		チェインになっている要素うちの1つの削除した後に、残っている要素を検索した際の実行テスト
				@details	ID:ハッシュテーブル-33\n
							データの検索テストです。\n
							< 確認項目 = 期待する結果 >		\n
							・検索関数の戻り値	= TRUE		\n	
							・取得結果			= 初期要素A	
			*//***********************************************************************************/
			TEST(FindDataTest, TestFindByOnceInChainWhenRemovedOnceInChain)
			{
				// -- 変数宣言
				ChainHashAllZero chainHash;

				// -- 初期要素の挿入(同一ハッシュで2回)
				ASSERT_TRUE(chainHash.Add(0, 1)) << "初期要素の挿入に失敗した";
				ASSERT_TRUE(chainHash.Add(1, 2)) << "初期要素の挿入に失敗した";

				// 要素の削除(1回)
				ASSERT_TRUE(chainHash.Remove(1)) << "チェインになっている要素の削除に失敗した";

				// -- 確認テスト
				// 要素の検索(残っている初期要素)
				int tValue = 0;
				EXPECT_TRUE(chainHash.Find(0, tValue)) << "同一チェイン内要素が削除された後の検索に失敗した";

				// 取得結果の確認
				EXPECT_EQ(1, tValue) << "検索結果が、想定しているものと異なる";

			}
		}
	}
}