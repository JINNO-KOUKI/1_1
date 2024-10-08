// GoogleTestのヘッダ
#include <gtest/gtest.h>

// 自身のリスト
#include "../1_4/LinkedList.h"

// -- 比較に使用する関数オブジェクト
#define COMP_AGE_ASC		[](const UserData& a, const UserData& b) {return a._Age < b._Age; } 
#define COMP_AGE_DESC		[](const UserData& a, const UserData& b) {return a._Age > b._Age; }
#define COMP_STATURE_ASC	[](const UserData& a, const UserData& b) {return a._Stature < b._Stature; }
#define COMP_STATURE_DESC	[](const UserData& a, const UserData& b) {return a._Stature > b._Stature; }

namespace ex01_DataStructure
{
	namespace chapter4
	{
		/// @brief テストに利用する構造体
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

		//=================================== クイックソート ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合のソートの実行テスト
			@details	ID:リスト-0\n
						データのソート機能のテストです。\n
						リストが空である場合の挙動を確認しています。\n
						エラー含め、何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEmpty) {

			LinkedList<UserData> list;

			// -- 並べ替え実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- 普遍テスト
			EXPECT_EQ(0, list.Size()) << "想定しているサイズと異なる(リストに予期しない変更が発生している)";
		}

		/**********************************************************************************//**
			@brief		要素が1つである場合のソートの実行テスト
			@details	ID:リスト-1\n
						データのソート機能のテストです。\n
						要素が1つである場合の挙動を確認しています。\n
						エラー含め、何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenOnce) {

			LinkedList<UserData> list;
			
			// -- 初期準備
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 10.0f))) << "初期要素の挿入に失敗";

			// -- 並べ替え実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- 普遍テスト
			EXPECT_EQ(1, list.Size()) << "想定しているサイズと異なる(リストに予期しない変更が発生している)";
			EXPECT_EQ(UserData(1, 10.0f), *(list.Begin())) << "想定している要素と異なる(リストに予期しない変更が発生している)";
		}

		/**********************************************************************************//**
			@brief		要素が2つ以上である場合のソートの実行テスト
			@details	ID:リスト-2\n
						データのソート機能のテストです。\n
						要素が2つ以上である場合の挙動を確認しています。\n
						要素が指定したキーに準じて、指定した順に並べば成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenMulti) {

			LinkedList<UserData> list;
			
			// -- 初期準備
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "初期要素の挿入に失敗";

			// ======== Ageに対する昇順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- 順序確認
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			
			// ======== Ageに対する降順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

			// ======== Statureに対する昇順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";

			// ======== Statureに対する降順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

		}

		/**********************************************************************************//**
			@brief		同じキーを持つ要素がある場合のソートの実行テスト
			@details	ID:リスト-3\n
						データのソート機能のテストです。\n
						同じキーを持つ要素がある場合の挙動を確認しています。\n
						そのキーを指定したときに、ソートされて並ぶが同じ要素の順序は保証されなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEqualElem) {

			LinkedList<UserData> list;
			
			// -- 初期準備
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "初期要素の挿入に失敗";

			// ======== Ageに対する昇順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- 順序確認
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

			// ======== Ageに対する降順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";

			// ======== Statureに対する昇順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";

			// ======== Statureに対する降順ソートテスト ========

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";

		}

		/**********************************************************************************//**
			@brief		要素が整列済みである場合のソートの実行テスト
			@details	ID:リスト-4\n
						データのソート機能のテストです。\n
						要素が整列済みである場合の挙動を確認しています。\n
						要素の順序に変動がなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenFinishedSort) {

			LinkedList<UserData> list;
			
			// ======== Ageに対する昇順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- 順序確認
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

			// リストの初期化
			ASSERT_TRUE(list.Clear());

			// ======== Ageに対する降順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";

			// リストの初期化
			ASSERT_TRUE(list.Clear());

			// ======== Statureに対する昇順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";

			// リストの初期化
			ASSERT_TRUE(list.Clear());

			// ======== Statureに対する降順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

		}

		/**********************************************************************************//**
			@brief		整列済みリストに要素を挿入した後のソートの実行テスト
			@details	ID:リスト-5\n
						データのソート機能のテストです。\n
						要素が整列済みである整列済みリストの各所に新規要素を挿入した後、ソートを実行した場合の挙動を確認しています。\n
						正しくソートされれば成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenAfterInsert) {

			LinkedList<UserData> list;

			// ======== Ageに対する昇順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";

			// -- 中間への要素挿入
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "追加要素の挿入に失敗";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "追加要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_ASC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "リスト要素が想定されている順序になっていない";

			// リストの初期化
			ASSERT_TRUE(list.Clear());

			// ======== Ageに対する降順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";

			// -- 中間への要素挿入
			it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "追加要素の挿入に失敗";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "追加要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_AGE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(5, 40.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";

			// リストの初期化
			ASSERT_TRUE(list.Clear());

			// ======== Statureに対する昇順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";

			// -- 中間への要素挿入
			it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "追加要素の挿入に失敗";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "追加要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_ASC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "リスト要素が想定されている順序になっていない";

			// リストの初期化
			ASSERT_TRUE(list.Clear());

			// ======== Statureに対する降順ソートテスト ========

			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";

			// -- 中間への要素挿入
			it = list.ConstBegin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "追加要素の挿入に失敗";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "追加要素の挿入に失敗";

			// ソート実行
			ASSERT_NO_THROW(list.Sort(COMP_STATURE_DESC));

			// -- 順序確認
			it = list.ConstBegin();
			EXPECT_EQ(UserData(4, 50.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
		}

		/**********************************************************************************//**
			@brief		キーを指定しなかった際のソートの実行テスト
			@details	ID:リスト-6\n
						データのソート機能のテストです。\n
						キーを指定せずにソートを実行した場合の挙動を確認しています。\n
						エラー含め、何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenNullKey) {

			LinkedList<UserData> list;
			
			// -- 初期要素の挿入
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "初期要素の挿入に失敗";

			// -- ソート実行
			EXPECT_NO_THROW(list.Sort(nullptr));

			// -- 普遍テスト
			LinkedList<UserData>::ConstIterator it = list.ConstBegin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
		}

	}
}