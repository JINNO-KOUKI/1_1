// GoogleTestのヘッダ
#include <gtest/gtest.h>

// 自身のリスト
#include "../1_3/LinkedList.h"

namespace ex01_DataStructure
{
	namespace chapter3
	{

		//=================================== データ数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合のデータ数の取得テスト
			@details	ID:リスト-0\n
						データ数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
			LinkedList<int> list;
			EXPECT_EQ(0, list.Size()) << "想定されているサイズと異なる";
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-1\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPush)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.End();
			ASSERT_TRUE(list.Insert(it, 1)) << "要素の挿入に失敗";
			EXPECT_EQ(1, list.Size()) << "想定されているサイズと異なる";
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際のデータ数の取得テスト
			@details	ID:リスト-2\n
						データ数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		//TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
		//{
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
// 			MyList list;
// 			MyList::Iterator it = list.End();
// 			ASSERT_FALSE(list.Insert(it, ResultData()));
// 			EXPECT_EQ(0, list.Size());
		//}
		// 中略


		/**********************************************************************************//**
			@brief		データの挿入を行った際のデータ数の取得テスト
			@details	ID:リスト-3\n
						データ数の取得機能のテストです。\n
						データの挿入を行った際の戻り値を確認しています。\n
						データ数が1増えていれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumPush)
		{
			LinkedList<int> list;
			
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";
			EXPECT_EQ(1, list.Size()) << "想定されているサイズと異なる";
		}

		/**********************************************************************************//**
			@brief		データの挿入に失敗した際のデータ数の取得テスト
			@details	ID:リスト-4\n
						データ数の取得機能のテストです。\n
						データの挿入に失敗した際の戻り値を確認しています。\n
						データ数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumPushFailed)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it;
			ASSERT_FALSE(list.Insert(it, 1)) << "成功しないはずの挿入が成功してしまった";

			EXPECT_EQ(0, list.Size()) << "想定している要素数と異なる";
		}

		/**********************************************************************************//**
			@brief		データの削除を行った際のデータ数の取得テスト
			@details	ID:リスト-5\n
						データ数の取得機能のテストです。\n
						データの削除を行った際の戻り値を確認しています。\n
						データ数が0になれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumRemove)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.End();
			ASSERT_TRUE(list.Insert(it, 1)) << "要素の挿入に失敗";
			it = list.Begin();
			ASSERT_TRUE(list.Remove(it)) << "要素の削除に失敗";
			EXPECT_EQ(0, list.Size()) << "想定されているサイズと異なる";
		}
		
		/**********************************************************************************//**
			@brief		データの削除が失敗した際の戻り値の取得テスト
			@details	ID:リスト-6\n
						データ数の取得機能のテストです。\n
						データの削除に失敗した際の戻り値を確認しています。\n
						要素数が1のままであれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumRemoveFailed)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.End();
			ASSERT_TRUE(list.Insert(it, 1)) << "要素の挿入に失敗";
			it = list.End();
			ASSERT_FALSE(list.Remove(it)) << "要素の削除に失敗";
			EXPECT_EQ(1, list.Size()) << "想定されているサイズと異なる";
		}

		/**********************************************************************************//**
			@brief		リストが空である場合に、データの削除を行った際のデータ数の取得テスト
			@details	ID:リスト-7\n
						データ数の取得機能のテストです。\n
						リストが空である場合に、データの削除を行った際の戻り値を確認しています。\n
						データ数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumEmptyRemove)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.Begin();
			ASSERT_FALSE(list.Remove(it)) << "要素の削除に失敗";
			EXPECT_EQ(0, list.Size()) << "想定されているサイズと異なる";
		}
		
		//=================================== データの挿入 ===================================
		
		/**********************************************************************************//**
			@brief		リストが空である場合に、データを追加した際の挙動テスト
			@details	ID:リスト-9\n
						データの挿入テストです。\n
						リストが空である場合にデータを挿入した際の挙動を確認しています。\n
						先頭・末尾それぞれで要素を追加できていれば成功です。\n
		*//***********************************************************************************/
		TEST(InsertTest, TestInsertToEmpty)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.Begin(), 11)) << "先頭への挿入に失敗";
			EXPECT_EQ(11, list.Front()) << "先頭へのデータ挿入後の先頭要素が、想定しているものと異なる";

			ASSERT_TRUE(list.Clear()) << "リストのクリアに失敗";

			ASSERT_TRUE(list.Insert(list.End(), 22)) << "末尾への挿入に失敗";
			EXPECT_EQ(22, list.Front()) << "末尾へのデータ挿入後の末尾要素が、想定しているものと異なる";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭に要素を挿入した際の挙動テスト
			@details	ID:リスト-10\n
						データの挿入テストです。\n
						リスト複数の要素がある場合に、先頭イテレータを使用してデータを挿入した際の挙動を確認しています。\n
						先頭に要素を追加できていれば成功です。\n
		*//***********************************************************************************/
		TEST(InsertTest, TestInsertToFront)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";
			
			ASSERT_TRUE(list.Insert(list.Begin(), 11)) << "先頭への要素の挿入に失敗";
			EXPECT_EQ(11, list.Front()) << "先頭へのデータ挿入後の先頭要素が、想定しているものと異なる";
			LinkedList<int>::Iterator it = list.Begin();
			++it;
			EXPECT_EQ(1, (*it)) << "初期要素が、挿入要素の次に配置されていない";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾に要素を挿入した際の挙動テスト
			@details	ID:リスト-11\n
						データの挿入テストです。\n
						リスト複数の要素がある場合に、末尾イテレータを使用してデータを挿入した際の挙動を確認しています。\n
						末尾に要素を追加できていれば成功です。\n
		*//***********************************************************************************/
		TEST(InsertTest, TestInsertToBack)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";

			ASSERT_TRUE(list.Insert(list.End(), 11)) << "末尾への要素の挿入に失敗";

			EXPECT_EQ(1, list.Front()) << "初期要素が、挿入要素の前に配置されていない";
			EXPECT_EQ(11, list.Back()) << "末尾へのデータ挿入後の末尾要素が、想定しているものと異なる";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもない箇所に要素を挿入した際の挙動テスト
			@details	ID:リスト-12\n
						データの挿入テストです。\n
						リスト複数の要素がある場合に、先頭でも末尾でもないイテレータを使用してデータを挿入した際の挙動を確認しています。\n
						指定したイテレータの位置に要素を追加できていれば成功です。\n
		*//***********************************************************************************/
		TEST(InsertTest, TestInsertToCenter)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(it, 11)) << "中央への要素の挿入に失敗";
			
			LinkedList<int>::Iterator chkIt = list.Begin();
			EXPECT_EQ(1, *chkIt) << "初期要素<1>の配置が想定と異なる";
			++chkIt;
			EXPECT_EQ(11, *chkIt) << "中間に挿入した要素が想定した箇所に配置されていない";
			++chkIt;
			EXPECT_EQ(2, *chkIt) << "初期要素<2>の配置が想定と異なる";
			++chkIt;
			EXPECT_EQ(3, *chkIt) << "初期要素<3>の配置が想定と異なる";
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを使用して要素を挿入した際の挙動テスト
			@details	ID:リスト-13\n
						データの挿入テストです。\n
						ConstIteratorを使用してデータを挿入した際の挙動を確認しています。\n
						指定したイテレータの位置に要素を追加できていれば成功です。\n
		*//***********************************************************************************/
		TEST(InsertTest, TestConstInsert)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";

			LinkedList<int>::ConstIterator cit = list.ConstEnd();
			ASSERT_TRUE(list.Insert(cit, 33)) << "末尾への要素の挿入に失敗";
		
			cit = list.ConstBegin();
			++cit;
			ASSERT_TRUE(list.Insert(cit, 22)) << "中央への要素の挿入に失敗";

			cit = list.ConstBegin();
			ASSERT_TRUE(list.Insert(cit, 11)) << "先頭への要素の挿入に失敗";

			LinkedList<int>::Iterator chkIt = list.Begin();
			EXPECT_EQ(11, *chkIt) << "先頭に追加した要素の配置が想定と異なる";
			++chkIt;
			EXPECT_EQ(1, *chkIt) << "初期要素<1>の配置が想定と異なる";
			++chkIt;
			EXPECT_EQ(22, *chkIt) << "中央に追加した要素の配置が想定と異なる";
			++chkIt;
			EXPECT_EQ(2, *chkIt) << "初期要素<2>の配置が想定と異なる";
			++chkIt;
			EXPECT_EQ(33, *chkIt) << "末尾に追加した要素の配置が想定と異なる";
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを使用して要素を挿入した際の挙動テスト
			@details	ID:リスト-14\n
						データの挿入テストです。\n
						不正なイテレータを使用してデータを挿入した際の挙動を確認しています。\n
						何も変化が起きなければ成功です。\n
		*//***********************************************************************************/
		TEST(InsertTest, TestFraudInsert)
		{
			LinkedList<int> listA;
			LinkedList<int> listB;

			LinkedList<int>::Iterator nullIt;
			EXPECT_EQ(false, listA.Insert(nullIt, 1)) << "無効なイテレータでの挿入に成功してしまった";
			EXPECT_EQ(false, listA.Insert(listB.Begin(), 1)) << "別リストのイテレータでの挿入に成功してしまった";
		}

		//=================================== データの削除 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、削除を行った際の挙動テスト
			@details	ID:リスト-16\n
						データの削除テストです。\n
						リストが空である場合に、要素の削除処理を行った際の挙動を確認しています。\n
						何も変化が起きなければ成功です。\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestEmptyRemove)
		{
			LinkedList<int> list;
			
			EXPECT_EQ(false, list.Remove(list.Begin())) << "先頭イテレータでの削除に成功してしまった";
			EXPECT_EQ(false, list.Remove(list.End())) << "末尾イテレータでの削除に成功してしまった";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して削除を行った際の挙動テスト
			@details	ID:リスト-17\n
						データの削除テストです。\n
						リストに複数の要素がある場合に、先頭イテレータを指定して削除処理を行った際の挙動を確認しています。\n
						先頭要素が削除されれば成功です。\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToFront)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1));
			ASSERT_TRUE(list.Insert(list.End(), 2));
			
			ASSERT_TRUE(list.Remove(list.Begin())) << "先頭要素の削除に失敗しました。";
			EXPECT_EQ(2, list.Front()) << "先頭要素が、想定されるものと異なる";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して削除を行った際の挙動テスト
			@details	ID:リスト-18\n
						データの削除テストです。\n
						リストに複数の要素がある場合に、末尾イテレータを指定して削除処理を行った際の挙動を確認しています。\n
						何も起きなければ成功です。\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToBack)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1));
			ASSERT_TRUE(list.Insert(list.End(), 2));
			
			ASSERT_FALSE(list.Remove(list.End())) << "末尾イテレータでの削除に成功してしまった";
			EXPECT_EQ(2, list.Size()) << "想定される要素数と異なる";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除を行った際の挙動テスト
			@details	ID:リスト-19\n
						データの削除テストです。\n
						リストに複数の要素がある場合に、中間要素をイテレータで指定して削除処理を行った際の挙動を確認しています。\n
						イテレータで指定した要素が削除されれば成功です。\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestRemoveToCenter)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1));
			ASSERT_TRUE(list.Insert(list.End(), 2));
			ASSERT_TRUE(list.Insert(list.End(), 3));
			
			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Remove(it)) << "中間イテレータでの削除に失敗";

			EXPECT_EQ(1, list.Front()) << "想定される要素の配置と異なる";
			EXPECT_EQ(3, list.Back()) << "想定される要素の配置と異なる";
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないコンストイテレータを渡して削除を行った際の挙動テスト
			@details	ID:リスト-20\n
						データの削除テストです。\n
						リストに複数の要素がある場合に、中間要素をコンストイテレータで指定して削除処理を行った際の挙動を確認しています。\n
						コンストイテレータで指定した要素が削除されれば成功です。\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestConstRemoveToCenter)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1));
			ASSERT_TRUE(list.Insert(list.End(), 2));
			ASSERT_TRUE(list.Insert(list.End(), 3));
			
			LinkedList<int>::ConstIterator cit = list.ConstBegin();
			++cit;
			ASSERT_TRUE(list.Remove(cit)) << "中間コンストイテレータでの削除に失敗";

			EXPECT_EQ(1, list.Front()) << "想定される要素の配置と異なる";
			EXPECT_EQ(3, list.Back()) << "想定される要素の配置と異なる";
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して削除を行った際の挙動テスト
			@details	ID:リスト-21\n
						データの削除テストです。\n
						不正なイテレータで要素の削除処理を行った際の挙動を確認しています。\n
						何も起きなければ成功です。\n
		*//***********************************************************************************/
		TEST(RemoveTest, TestFraudRemove)
		{
			LinkedList<int> listA;
			LinkedList<int> listB;

			ASSERT_TRUE(listA.Insert(listA.End(), 1));
			
			LinkedList<int>::Iterator nullIt;
			EXPECT_EQ(false, listA.Remove(listB.Begin())) << "別リストのイテレータでの削除に成功してしまった";
			EXPECT_EQ(false, listA.Remove(nullIt)) << "無効なイテレータでの削除に成功してしまった";
		}

		//=================================== 先頭イテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-23\n
						先頭イテレータの取得テストです。\n
						リストが空である場合に、先頭イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginIteratorTest, TestGetBeginIteratorWhenEmpty)
		{
			LinkedList<int> list;
			
			LinkedList<int>::Iterator dummy = list.End();
			EXPECT_EQ(dummy, list.Begin()) << "ダミーノード以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が1である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-24\n
						先頭イテレータの取得テストです。\n
						リストの要素数が1である場合に、先頭イテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginIteratorTest, TestGetBeginIteratorWhenOnce)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			
			EXPECT_EQ(1, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が複数である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-25\n
						先頭イテレータの取得テストです。\n
						リストの要素数が複数である場合に、先頭イテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginIteratorTest, TestGetBeginIteratorWhenMulti)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";
			
			EXPECT_EQ(1, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-26\n
						先頭イテレータの取得テストです。\n
						リストの先頭・中間・末尾に要素を挿入した後、先頭イテレータを取得した際の挙動を確認しています。\n
						何れの場合も先頭要素を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginIteratorTest, TestGetBeginIteratorWhenAfterInsert)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";

			
			ASSERT_TRUE(list.Insert(list.Begin(), 11)) << "先頭への挿入に失敗した";
			EXPECT_EQ(11, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(it, 22)) << "中間への挿入に失敗した";
			EXPECT_EQ(11, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";

			ASSERT_TRUE(list.Insert(list.End(), 33)) << "末尾への挿入に失敗した";
			EXPECT_EQ(11, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの削除を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-27\n
						先頭イテレータの取得テストです。\n
						リストの先頭・中間・末尾の要素を削除した後、先頭イテレータを取得した際の挙動を確認しています。\n
						何れの場合も先頭要素を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginIteratorTest, TestGetBeginIteratorWhenAfterRemove)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 4)) << "初期要素の挿入に失敗した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Remove(it)) << "中間要素の削除に失敗した";
			EXPECT_EQ(1, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";

			it = list.End();
			--it;
			ASSERT_TRUE(list.Remove(it)) << "末尾要素の削除に失敗した";
			EXPECT_EQ(1, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";

			ASSERT_TRUE(list.Remove(list.Begin())) << "先頭要素の削除に失敗した";
			EXPECT_EQ(3, *(list.Begin())) << "先頭要素以外を指すイテレータを取得した";
		}

		//=================================== 先頭コンストイテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-29\n
						先頭コンストイテレータの取得テストです。\n
						リストが空である場合に、先頭コンストイテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginConstIteratorTest, TestGetBeginConstIteratorWhenEmpty)
		{
			LinkedList<int> list;

			LinkedList<int>::ConstIterator dummy = list.ConstEnd();
			EXPECT_EQ(dummy, list.ConstBegin()) << "ダミーノード以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が1である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-30\n
						先頭コンストイテレータの取得テストです。\n
						リストの要素数が1である場合に、先頭コンストイテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginConstIteratorTest, TestGetBeginConstIteratorWhenOnce)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";

			EXPECT_EQ(1, *(list.ConstBegin())) << "先頭要素以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が複数である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-31\n
						先頭コンストイテレータの取得テストです。\n
						リストの要素数が複数である場合に、先頭コンストイテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginConstIteratorTest, TestGetBeginConstIteratorWhenMulti)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";

			EXPECT_EQ(1, *(list.ConstBegin())) << "先頭要素以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-32\n
						先頭コンストイテレータの取得テストです。\n
						リストの先頭・中間・末尾に要素を挿入した後、先頭コンストイテレータを取得した際の挙動を確認しています。\n
						何れの場合も先頭要素を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginConstIteratorTest, TestGetBeginConstIteratorWhenAfterInsert)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";


			ASSERT_TRUE(list.Insert(list.Begin(), 11)) << "先頭への挿入に失敗した";
			EXPECT_EQ(11, *(list.ConstBegin())) << "先頭要素以外を指すイテレータを取得した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(it, 22)) << "中間への挿入に失敗した";
			EXPECT_EQ(11, *(list.ConstBegin())) << "先頭要素以外を指すイテレータを取得した";

			ASSERT_TRUE(list.Insert(list.End(), 33)) << "末尾への挿入に失敗した";
			EXPECT_EQ(11, *(list.ConstBegin())) << "先頭要素以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの削除を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-33\n
						先頭コンストイテレータの取得テストです。\n
						リストの先頭・中間・末尾の要素を削除した後、先頭コンストイテレータを取得した際の挙動を確認しています。\n
						何れの場合も先頭要素を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(BeginConstIteratorTest, TestGetBeginConstIteratorWhenAfterRemove)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 4)) << "初期要素の挿入に失敗した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Remove(it)) << "中間要素の削除に失敗した";
			EXPECT_EQ(1, *(list.ConstBegin())) << "先頭要素以外を指すコンストイテレータを取得した";

			it = list.End();
			--it;
			ASSERT_TRUE(list.Remove(it)) << "末尾要素の削除に失敗した";
			EXPECT_EQ(1, *(list.ConstBegin())) << "先頭要素以外を指すコンストイテレータを取得した";

			ASSERT_TRUE(list.Remove(list.Begin())) << "先頭要素の削除に失敗した";
			EXPECT_EQ(3, *(list.ConstBegin())) << "先頭要素以外を指すコンストイテレータを取得した";
		}

		//=================================== 末尾イテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-35\n
						末尾イテレータの取得テストです。\n
						リストが空である場合に、末尾イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestGetEndIteratorWhenEmpty)
		{
			LinkedList<int> list;

			LinkedList<int>::Iterator dummy = list.Dummy();
			EXPECT_EQ(dummy, list.End()) << "ダミーノード以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が1である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-36\n
						末尾イテレータの取得テストです。\n
						リストの要素数が1である場合に、末尾イテレータを取得した際の挙動を確認しています。\n
						末尾(ダミーノード)を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestGetEndIteratorWhenOnce)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";

			LinkedList<int>::Iterator dummy = list.Dummy();
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が複数である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-37\n
						末尾イテレータの取得テストです。\n
						リストの要素数が複数である場合に、末尾イテレータを取得した際の挙動を確認しています。\n
						末尾(ダミーノード)を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestGetEndIteratorWhenMulti)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";

			LinkedList<int>::Iterator dummy = list.Dummy();
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-38\n
						末尾イテレータの取得テストです。\n
						リストの先頭・中間・末尾に要素を挿入した後、末尾イテレータを取得した際の挙動を確認しています。\n
						何れの場合も末尾(ダミーノード)を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestGetEndIteratorWhenAfterInsert)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator dummy = list.Dummy();

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";


			ASSERT_TRUE(list.Insert(list.Begin(), 11)) << "先頭への挿入に失敗した";
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(it, 22)) << "中間への挿入に失敗した";
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";

			ASSERT_TRUE(list.Insert(list.End(), 33)) << "末尾への挿入に失敗した";
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの削除を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-39\n
						末尾イテレータの取得テストです。\n
						リストの先頭・中間・末尾の要素を削除した後、末尾イテレータを取得した際の挙動を確認しています。\n
						何れの場合も末尾(ダミーノード)を指すイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndIteratorTest, TestGetEndIteratorWhenAfterRemove)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator dummy = list.Dummy();

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 4)) << "初期要素の挿入に失敗した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Remove(it)) << "中間要素の削除に失敗した";
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";

			it = list.End();
			--it;
			ASSERT_TRUE(list.Remove(it)) << "末尾要素の削除に失敗した";
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";

			ASSERT_TRUE(list.Remove(list.Begin())) << "先頭要素の削除に失敗した";
			EXPECT_EQ(dummy, list.End()) << "末尾(ダミーノード)以外を指すイテレータを取得した";
		}

		//=================================== 末尾コンストイテレータの取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-41\n
						末尾コンストイテレータの取得テストです。\n
						リストが空である場合に、末尾コンストイテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestGetEndConstIteratorWhenEmpty)
		{
			LinkedList<int> list;

			LinkedList<int>::ConstIterator dummy = list.ConstDummy();
			EXPECT_EQ(dummy, list.ConstEnd()) << "ダミーノード以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が1である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-42\n
						末尾コンストイテレータの取得テストです。\n
						リストの要素数が1である場合に、末尾コンストイテレータを取得した際の挙動を確認しています。\n
						末尾(ダミーノード)を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestGetEndConstIteratorWhenOnce)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";

			LinkedList<int>::ConstIterator dummy = list.ConstDummy();
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		リストの要素数が複数である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-43\n
						末尾コンストイテレータの取得テストです。\n
						リストの要素数が複数である場合に、末尾コンストイテレータを取得した際の挙動を確認しています。\n
						末尾(ダミーノード)を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestGetEndConstIteratorWhenMulti)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";

			LinkedList<int>::ConstIterator dummy = list.ConstDummy();
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの挿入を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-44\n
						末尾コンストイテレータの取得テストです。\n
						リストの先頭・中間・末尾に要素を挿入した後、末尾コンストイテレータを取得した際の挙動を確認しています。\n
						何れの場合も末尾(ダミーノード)を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestGetEndConstIteratorWhenAfterInsert)
		{
			LinkedList<int> list;
			LinkedList<int>::ConstIterator dummy = list.ConstDummy();

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";


			ASSERT_TRUE(list.Insert(list.Begin(),11)) << "先頭への挿入に失敗した";
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(it, 22)) << "中間への挿入に失敗した";
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";

			ASSERT_TRUE(list.Insert(list.End(), 33)) << "末尾への挿入に失敗した";
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";
		}

		/**********************************************************************************//**
			@brief		データの削除を行った場合に、呼び出した際の挙動テスト
			@details	ID:リスト-45\n
						末尾コンストイテレータの取得テストです。\n
						リストの先頭・中間・末尾の要素を削除した後、末尾コンストイテレータを取得した際の挙動を確認しています。\n
						何れの場合も末尾(ダミーノード)を指すコンストイテレータが取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(EndConstIteratorTest, TestGetEndConstIteratorWhenAfterRemove)
		{
			LinkedList<int> list;
			LinkedList<int>::ConstIterator dummy = list.ConstDummy();

			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗した";
			ASSERT_TRUE(list.Insert(list.End(), 4)) << "初期要素の挿入に失敗した";

			LinkedList<int>::Iterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Remove(it)) << "中間要素の削除に失敗した";
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";

			it = list.End();
			--it;
			ASSERT_TRUE(list.Remove(it)) << "末尾要素の削除に失敗した";
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";

			ASSERT_TRUE(list.Remove(list.Begin())) << "先頭要素の削除に失敗した";
			EXPECT_EQ(dummy, list.ConstEnd()) << "末尾(ダミーノード)以外を指すコンストイテレータを取得した";
		}


		//=================================== イテレータの指す要素の取得 ===================================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で、呼び出した際の挙動テスト
			@details	ID:Iterator-0\n
						イテレータの指す要素の取得テストです。\n
						リストの参照がない状態で、イテレータの指す要素を取得した際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestGetElemToNullListRef)
		{
			LinkedList<int>::Iterator it;
			EXPECT_DEATH(*it, "Assertion failed. *");

			LinkedList<int>::ConstIterator cit;
			EXPECT_DEATH(*cit, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		Iteratorから取得した要素に対して、値の代入が行えるかの挙動テスト
			@details	ID:Iterator-1\n
						イテレータの指す要素の取得テストです。\n
						Iteratorから取得した要素に対して、値の代入が行った際の挙動を確認しています。\n
						値が正しく変更されていれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestUpdateElemFromIterator)
		{
			LinkedList<int> list;

			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の代入に失敗";

			LinkedList<int>::Iterator it = list.Begin();
			(*it) = 99;
			it = list.Begin();

			EXPECT_EQ(99, *it) << "イテレータを介した値の代入が正しく行われていない";
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-3\n
						イテレータの指す要素の取得テストです。\n
						リストが空の際の先頭イテレータに対して、値の取得を行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestGetFromIteratorWhenEmpty)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_DEATH(*it, "Assertion failed. *");
			EXPECT_DEATH(*cit, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-4\n
						イテレータの指す要素の取得テストです。\n
						末尾イテレータに対して、値の取得を行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetTest, TestGetFromEndIterator)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.End();
			LinkedList<int>::ConstIterator cit = list.ConstEnd();

			EXPECT_DEATH(*it, "Assertion failed. *");
			EXPECT_DEATH(*cit, "Assertion failed. *");
		}

		//=================================== イテレータをリストの末尾に向かって一つ進める ===================================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-5\n
						イテレータのインクリメントテストです。\n
						リストの参照がない状態でインクリメントを行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrementTest, TestIncrementWhenNullListRef)
		{
			LinkedList<int>::Iterator it;
			LinkedList<int>::ConstIterator cit;

			EXPECT_DEATH(it++, "Assertion failed. *");
			EXPECT_DEATH(cit++, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		リストの空の状態で呼び出した際の挙動テスト
			@details	ID:Iterator-6\n
						イテレータのインクリメントテストです。\n
						リストが空の状態でインクリメントを行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrementTest, TestIncrementWhenListEmpty)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_DEATH(it++, "Assertion failed. *");
			EXPECT_DEATH(cit++, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-7\n
						イテレータのインクリメントテストです。\n
						末尾イテレータに対してインクリメントを行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrementTest, TestIncrementToEndIterator)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";
			LinkedList<int>::Iterator it = list.End();
			LinkedList<int>::ConstIterator cit = list.ConstEnd();

			EXPECT_DEATH(it++, "Assertion failed. *");
			EXPECT_DEATH(cit++, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		リストに2つ以上の要素がある場合に、呼び出した際の挙動テスト
			@details	ID:Iterator-8\n
						イテレータのインクリメントテストです。\n
						2つ以上の要素を持つリストのイテレータに対して、インクリメントを行った際の挙動を確認しています。\n
						すべての格納要素が正しく参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrementTest, TestIncrementNormal)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_EQ(1, *it) << "初期要素<1>の参照が想定しているものと異なる";
			EXPECT_EQ(1, *cit) << "初期要素<1>の参照が想定しているものと異なる";
			++it;
			++cit;
			EXPECT_EQ(2, *it) << "初期要素<2>の参照が想定しているものと異なる";
			EXPECT_EQ(2, *cit) << "初期要素<2>の参照が想定しているものと異なる";
			++it;
			++cit;
			EXPECT_EQ(3, *it) << "初期要素<3>の参照が想定しているものと異なる";
			EXPECT_EQ(3, *cit) << "初期要素<3>の参照が想定しているものと異なる";
		}

		/**********************************************************************************//**
			@brief		前置インクリメントの挙動テスト
			@details	ID:Iterator-9\n
						イテレータのインクリメントテストです。\n
						前置インクリメントを行った際の挙動を確認しています。\n
						インクリメント時と後で正しい値が参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrementTest, TestPreIncrement)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_EQ(2, *(++it)) << "インクリメント時の値が正しくない";
			EXPECT_EQ(2, *it) << "インクリメント後の値が正しくない";
			EXPECT_EQ(2, *(++cit)) << "インクリメント時の値が正しくない";
			EXPECT_EQ(2, *cit) << "インクリメント後の値が正しくない";
		}

		/**********************************************************************************//**
			@brief		後置インクリメントの挙動テスト
			@details	ID:Iterator-10\n
						イテレータのインクリメントテストです。\n
						後置インクリメントを行った際の挙動を確認しています。\n
						インクリメント時と後で正しい値が参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrementTest, TestAfterIncrement)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_EQ(1, *(it++)) << "インクリメント時の値が正しくない";
			EXPECT_EQ(2, *it) << "インクリメント後の値が正しくない";
			EXPECT_EQ(1, *(cit++)) << "インクリメント時の値が正しくない";
			EXPECT_EQ(2, *cit) << "インクリメント後の値が正しくない";
		}

		//=================================== イテレータをリストの先頭に向かって一つ進める ===================================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:Iterator-11\n
						イテレータのデクリメントテストです。\n
						リストの参照がない状態でデクリメントを行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrementTest, TestDecrementWhenNullListRef)
		{
			LinkedList<int>::Iterator it;
			LinkedList<int>::ConstIterator cit;

			EXPECT_DEATH(it--, "Assertion failed. *");
			EXPECT_DEATH(cit--, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		リストの空の状態で呼び出した際の挙動テスト
			@details	ID:Iterator-12\n
						イテレータのデクリメントテストです。\n
						リストが空の状態でデクリメントを行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrementTest, TestDecrementWhenListEmpty)
		{
			LinkedList<int> list;
			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_DEATH(it--, "Assertion failed. *");
			EXPECT_DEATH(cit--, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:Iterator-13\n
						イテレータのデクリメントテストです。\n
						先頭イテレータに対してデクリメントを行った際の挙動を確認しています。\n
						Assertが発生すれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrementTest, TestDecrementToBeginIterator)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";
			LinkedList<int>::Iterator it = list.Begin();
			LinkedList<int>::ConstIterator cit = list.ConstBegin();

			EXPECT_DEATH(it--, "Assertion failed. *");
			EXPECT_DEATH(cit--, "Assertion failed. *");
		}

		/**********************************************************************************//**
			@brief		リストに2つ以上の要素がある場合に、呼び出した際の挙動テスト
			@details	ID:Iterator-14\n
						イテレータのデクリメントテストです。\n
						2つ以上の要素を持つリストのイテレータに対して、デクリメントを行った際の挙動を確認しています。\n
						すべての格納要素が正しく参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrementTest, TestDecrementNormal)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 3)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.End();
			LinkedList<int>::ConstIterator cit = list.ConstEnd();
			it--;
			cit--;

			EXPECT_EQ(3, *it) << "初期要素<1>の参照が想定しているものと異なる";
			EXPECT_EQ(3, *cit) << "初期要素<1>の参照が想定しているものと異なる";
			--it;
			--cit;
			EXPECT_EQ(2, *it) << "初期要素<2>の参照が想定しているものと異なる";
			EXPECT_EQ(2, *cit) << "初期要素<2>の参照が想定しているものと異なる";
			--it;
			--cit;
			EXPECT_EQ(1, *it) << "初期要素<3>の参照が想定しているものと異なる";
			EXPECT_EQ(1, *cit) << "初期要素<3>の参照が想定しているものと異なる";
		}

		/**********************************************************************************//**
			@brief		前置デクリメントの挙動テスト
			@details	ID:Iterator-15\n
						イテレータのデクリメントテストです。\n
						前置デクリメントを行った際の挙動を確認しています。\n
						デクリメント時と後で正しい値が参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrementTest, TestPreDecrement)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.End();
			it--;
			LinkedList<int>::ConstIterator cit = list.ConstEnd();
			cit--;

			EXPECT_EQ(1, *(--it)) << "デクリメント時の値が正しくない";
			EXPECT_EQ(1, *it) << "デクリメント後の値が正しくない";
			EXPECT_EQ(1, *(--cit)) << "デクリメント時の値が正しくない";
			EXPECT_EQ(1, *cit) << "デクリメント後の値が正しくない";
		}

		/**********************************************************************************//**
			@brief		後置デクリメントの挙動テスト
			@details	ID:Iterator-16\n
						イテレータのデクリメントテストです。\n
						後置デクリメントを行った際の挙動を確認しています。\n
						デクリメント時と後で正しい値が参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrementTest, TestAfterDecrement)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), 2)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator it = list.End();
			it--;
			LinkedList<int>::ConstIterator cit = list.ConstEnd();
			cit--;

			EXPECT_EQ(2, *(it--)) << "デクリメント時の値が正しくない";
			EXPECT_EQ(1, *it) << "デクリメント後の値が正しくない";
			EXPECT_EQ(2, *(cit--)) << "デクリメント時の値が正しくない";
			EXPECT_EQ(1, *cit) << "デクリメント後の値が正しくない";
		}

		//=================================== イテレータのコピーを行う ===================================

		/**********************************************************************************//**
			@brief		コピー作成の挙動テスト
			@details	ID:Iterator-18\n
						イテレータのコピーテストです。\n
						コピーコンストラクトの挙動を確認しています。\n
						コピー元と同じ値が参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCopyTest, TestCopy)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator src = list.Begin();
			LinkedList<int>::Iterator dst(src);
			LinkedList<int>::ConstIterator csrc = list.ConstBegin();
			LinkedList<int>::ConstIterator cdst(csrc);

			EXPECT_EQ(src, dst) << "コピー元と値が異なる";
			EXPECT_EQ(csrc, cdst) << "コピー元と値が異なる";
		}

		//=================================== イテレータの代入を行う ===================================

		/**********************************************************************************//**
			@brief		イテレータ代入の挙動テスト
			@details	ID:Iterator-20\n
						イテレータの代入テストです。\n
						代入の挙動を確認しています。\n
						コピー元と同じ値が参照できれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorAssignTest, TestAssign)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.End(), 1)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator src = list.Begin();
			LinkedList<int>::Iterator dst;
			dst = src;
			LinkedList<int>::ConstIterator csrc = list.ConstBegin();
			LinkedList<int>::ConstIterator cdst;
			cdst = csrc;

			EXPECT_EQ(src, dst) << "コピー元と値が異なる";
			EXPECT_EQ(csrc, cdst) << "コピー元と値が異なる";
		}

		//=================================== イテレータが同一であるか、比較を行う ===================================

		/**********************************************************************************//**
			@brief		空のリストの先頭・末尾イテレータの比較の挙動テスト
			@details	ID:Iterator-21\n
						イテレータの等価比較テストです。\n
						リストが空の際の、先頭・末尾イテレータの比較結果が正しいかを確認しています。\n
						比較結果がTrueであれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCompareTest, TestEqualBeginAndEnd)
		{
			LinkedList<int> list;

			LinkedList<int>::Iterator A = list.Begin();
			LinkedList<int>::Iterator B = list.End();
			LinkedList<int>::ConstIterator cA = list.ConstBegin();
			LinkedList<int>::ConstIterator cB = list.ConstEnd();

			EXPECT_EQ(true, A == B) << "イテレータが異なる";
			EXPECT_EQ(true, cA == cB) << "イテレータが異なる";
		}

		/**********************************************************************************//**
			@brief		同一イテレータの比較の挙動テスト
			@details	ID:Iterator-22\n
						イテレータの等価比較テストです。\n
						同一のイテレータの比較結果が正しいかを確認しています。\n
						比較結果がTrueであれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCompareTest, TestEqualAandA)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator A = list.Begin();
			LinkedList<int>::Iterator B = list.Begin();
			LinkedList<int>::ConstIterator cA = list.ConstBegin();
			LinkedList<int>::ConstIterator cB = list.ConstBegin();

			EXPECT_EQ(true, A == B) << "イテレータが異なる";
			EXPECT_EQ(true, cA == cB) << "イテレータが異なる";
		}

		/**********************************************************************************//**
			@brief		異なるイテレータの比較の挙動テスト
			@details	ID:Iterator-23\n
						イテレータの等価比較テストです。\n
						異なるイテレータの比較結果が正しいかを確認しています。\n
						比較結果がFalseであれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCompareTest, TestEqualAandB)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator A = list.Begin();
			LinkedList<int>::Iterator B = list.End();
			LinkedList<int>::ConstIterator cA = list.ConstBegin();
			LinkedList<int>::ConstIterator cB = list.ConstEnd();

			EXPECT_EQ(false, A == B) << "イテレータが同一";
			EXPECT_EQ(false, cA == cB) << "イテレータが同一";
		}

		//=================================== イテレータが異なるか、比較を行う ===================================

		/**********************************************************************************//**
			@brief		空のリストの先頭・末尾イテレータの比較の挙動テスト
			@details	ID:Iterator-24\n
						イテレータの非等価比較テストです。\n
						リストが空の際の、先頭・末尾イテレータの比較結果が正しいかを確認しています。\n
						比較結果がFalseであれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCompareTest, TestNotEqualBeginAndEnd)
		{
			LinkedList<int> list;

			LinkedList<int>::Iterator A = list.Begin();
			LinkedList<int>::Iterator B = list.End();
			LinkedList<int>::ConstIterator cA = list.ConstBegin();
			LinkedList<int>::ConstIterator cB = list.ConstEnd();

			EXPECT_EQ(false, A != B) << "イテレータが同一";
			EXPECT_EQ(false, cA != cB) << "イテレータが同一";
		}

		/**********************************************************************************//**
			@brief		同一イテレータの比較の挙動テスト
			@details	ID:Iterator-25\n
						イテレータの非等価比較テストです。\n
						同一のイテレータの比較結果が正しいかを確認しています。\n
						比較結果がFalseであれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCompareTest, TestNotEqualAandA)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator A = list.Begin();
			LinkedList<int>::Iterator B = list.Begin();
			LinkedList<int>::ConstIterator cA = list.ConstBegin();
			LinkedList<int>::ConstIterator cB = list.ConstBegin();

			EXPECT_EQ(false, A != B) << "イテレータが異なる";
			EXPECT_EQ(false, cA != cB) << "イテレータが異なる";
		}

		/**********************************************************************************//**
			@brief		異なるイテレータの比較の挙動テスト
			@details	ID:Iterator-26\n
						イテレータの非等価比較テストです。\n
						異なるイテレータの比較結果が正しいかを確認しています。\n
						比較結果がTrueであれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCompareTest, TestNotEqualAandB)
		{
			LinkedList<int> list;
			ASSERT_TRUE(list.Insert(list.Begin(), 1)) << "初期要素の挿入に失敗";

			LinkedList<int>::Iterator A = list.Begin();
			LinkedList<int>::Iterator B = list.End();
			LinkedList<int>::ConstIterator cA = list.ConstBegin();
			LinkedList<int>::ConstIterator cB = list.ConstEnd();

			EXPECT_EQ(true, A != B) << "イテレータが同一";
			EXPECT_EQ(true, cA != cB) << "イテレータが同一";
		}

	}
}