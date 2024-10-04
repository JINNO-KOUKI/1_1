//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ
#include <gtest/gtest.h>

// 例。自分の双方向リスト
#include "../1_2/MyList.h"

#include "List_ManualTest.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		データ数の取得機能について、constのメソッドであるかのテスト
			@details	ID:リスト-8(手動)\n
						データ数の取得機能のテストです。\n
						constのメソッドであるかを確認しています。\n
						有効にしてコンパイルが通れば成功です。\n
						TT_TEST_GET_DATA_NUM_IS_CONSTマクロを定義すると有効になります。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_IS_CONST
			const MyList list;
			EXPECT_EQ(0, list.Size());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		リスト末尾のデータ追加について、非constが保障されているかのテスト
			@details	ID:リスト-15(手動)\n
						リスト末尾のデータ追加テストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_INSERT_WHEN_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const MyList list;
			MyList::ConstIterator it = list.ConstEnd();
			list.Insert(it, ResultData());//ここでエラー
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		リスト先頭のデータ削除について、非constが保障されているかのテスト
			@details	ID:リスト-22(手動)\n
						リスト先頭のデータ削除テストです。\n
						非constが保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_REMOVE_WHEN_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestRemoveWhenConst)
		{
#if defined TT_TEST_REMOVE_WHEN_CONST
			const MyList list;
			MyList::ConstIterator it = list.ConstBegin();
			list.Remove(it);//ここでエラー
#endif //TT_TEST_REMOVE_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		先頭イテレータの取得について、constリストから取得できないことが保障されているかのテスト
			@details	ID:リスト-28(手動)\n
						先頭イテレータの取得テストです。\n
						constリストからの取得の禁止が保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_GET_BEGIN_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetBeginIteratorWhenConst)
		{
#if defined TT_TEST_GET_BEGIN_ITERATOR_WHEN_CONST
			const MyList list;
			MyList::Iterator it = list.Begin();	// ここでエラー
#endif //TT_TEST_GET_BEGIN_ITERATOR_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		先頭コンストイテレータの取得について、constリストから取得できることが保障されているかのテスト
			@details	ID:リスト-34(手動)\n
						先頭コンストイテレータの取得テストです。\n
						constリストからの取得が保障されているかを確認しています。\n
						有効にしてコンパイルエラーにならなければ成功です。\n
						TT_TEST_GET_BEGIN_CONST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetBeginConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_BEGIN_CONST_ITERATOR_WHEN_CONST
			const MyList list;
			MyList::ConstIterator it = list.ConstBegin();
#endif //TT_TEST_GET_BEGIN_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		末尾イテレータの取得について、constリストから取得できないことが保障されているかのテスト
			@details	ID:リスト-40(手動)\n
						末尾イテレータの取得テストです。\n
						constリストからの取得の禁止が保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_GET_END_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetEndIteratorWhenConst)
		{
#if defined TT_TEST_GET_END_ITERATOR_WHEN_CONST
			const MyList list;
			MyList::Iterator it = list.End();	// ここでエラー
#endif //TT_TEST_GET_END_ITERATOR_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		末尾コンストイテレータの取得について、constリストから取得できることが保障されているかのテスト
			@details	ID:リスト-46(手動)\n
						末尾コンストイテレータの取得テストです。\n
						constリストからの取得が保障されているかを確認しています。\n
						有効にしてコンパイルエラーにならなければ成功です。\n
						TT_TEST_GET_END_CONST_ITERATOR_WHEN_CONSTマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetEndConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_END_CONST_ITERATOR_WHEN_CONST
			const MyList list;
			MyList::ConstIterator it = list.ConstEnd();	// ここでエラー
#endif //TT_TEST_GET_END_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		コンストイテレータから取得した要素に対して、値の代入が行えないことが保障されているかのテスト
			@details	ID:Iterator-2(手動)\n
						イテレータの指す要素の取得テストです。\n
						コンストイテレータを介した、値の代入の禁止が保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_SET_FROM_CONST_ITERATORマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestSetFromConstIterator)
		{
#if defined TT_TEST_SET_FROM_CONST_ITERATOR
			MyList list;
			MyList::ConstIterator it = list.ConstEnd();	
			(*it)._Score = 99;	// ここでエラー
#endif //TT_TEST_SET_FROM_CONST_ITERATOR
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		コンストイテレータからイテレータのコピーが作成されないことが保障されているかのテスト
			@details	ID:Iterator-17(手動)\n
						イテレータのコピーテストです。\n
						コンストイテレータからイテレータのコピーの作成の禁止が保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_COPY_CONST_TO_NORMALマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestCopyConstToNormal)
		{
#if defined TT_TEST_COPY_CONST_TO_NORMAL
			MyList list;
			MyList::ConstIterator cit = list.ConstEnd();	
			MyList::Iterator it(cit);	// ここでエラー
#endif //TT_TEST_COPY_CONST_TO_NORMAL
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		イテレータにコンストイテレータを代入できないことが保障されているかのテスト
			@details	ID:Iterator-19(手動)\n
						イテレータの代入テストです。\n
						イテレータへのコンストイテレータの代入の禁止が保障されているかを確認しています。\n
						有効にしてコンパイルエラーになれば成功です。\n
						TT_TEST_ASSIGN_CONST_TO_NORMALマクロを定義すると有効になります。\n

			@return		なし
		*//***********************************************************************************/
		TEST(ListManualTest, TestAssignConstToNormal)
		{
#if defined TT_TEST_ASSIGN_CONST_TO_NORMAL
			MyList list;
			MyList::ConstIterator cit = list.ConstEnd();	
			MyList::Iterator it;
			it = cit;// ここでエラー
#endif //TT_TEST_ASSIGN_CONST_TO_NORMAL
			SUCCEED();
		}

	}	// chapter2
}	//	ex01_DataStructure
