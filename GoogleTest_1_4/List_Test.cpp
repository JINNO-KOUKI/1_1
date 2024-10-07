// GoogleTestのヘッダ
#include <gtest/gtest.h>

// 自身のリスト
#include "../1_4/LinkedList.h"


namespace ex01_DataStructure
{
	namespace chapter4
	{

		//=================================== クイックソート ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合のソートの実行テスト
			@details	ID:リスト-0\n
						データのソート機能のテストです。\n
						リストが空である場合の挙動を確認しています。\n
						エラー含め、何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEmpty) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				bool operator==(const UserData& other) const
				{
					return this->_Age == other._Age && this->_Stature == other._Stature;
				}
			};
			LinkedList<UserData> list;

			EXPECT_NO_THROW(list.Sort(false, &UserData::_Age));
			EXPECT_NO_THROW(list.Sort(false, &UserData::_Stature));
		}

		/**********************************************************************************//**
			@brief		要素が1つである場合のソートの実行テスト
			@details	ID:リスト-1\n
						データのソート機能のテストです。\n
						要素が1つである場合の挙動を確認しています。\n
						エラー含め、何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenOnce) {

			struct UserData
			{
				int		_Age;
				float	_Stature;
			};
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData())) << "初期要素の挿入に失敗";

			EXPECT_NO_THROW(list.Sort(false, &UserData::_Age));
			EXPECT_NO_THROW(list.Sort(false, &UserData::_Stature));
		}

		/**********************************************************************************//**
			@brief		要素が2つ以上である場合のソートの実行テスト
			@details	ID:リスト-2\n
						データのソート機能のテストです。\n
						要素が2つ以上である場合の挙動を確認しています。\n
						要素が指定したキーに準じて、指定した順に並べば成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenMulti) {

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
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "初期要素の挿入に失敗";

			// --- Ageに対するソートテスト
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			LinkedList<UserData>::ConstIterator it = list.Begin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			
			// --- Statureに対するソートテスト
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_EQ(UserData(1, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
		}

		/**********************************************************************************//**
			@brief		同じキーを持つ要素がある場合のソートの実行テスト
			@details	ID:リスト-3\n
						データのソート機能のテストです。\n
						同じキーを持つ要素がある場合の挙動を確認しています。\n
						そのキーを指定したときに、ソートされて並ぶが同じ要素の順序は保証されなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenEqualElem) {

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
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "初期要素の挿入に失敗";

			// --- Ageに対するソートテスト
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			LinkedList<UserData>::ConstIterator it = list.Begin();
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 30.0f) == *it) || (UserData(2, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

			// --- Statureに対するソートテスト
			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_TRUE((UserData(2, 10.0f) == *it) || (UserData(3, 10.0f) == *it)) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
		}

		/**********************************************************************************//**
			@brief		要素が整列済みである場合のソートの実行テスト
			@details	ID:リスト-4\n
						データのソート機能のテストです。\n
						要素が整列済みである場合の挙動を確認しています。\n
						要素の順序に変動がなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenFinishedSort) {

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
			LinkedList<UserData> list;
			
			// --- Ageに対するソートテスト
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			LinkedList<UserData>::ConstIterator it = list.Begin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";

			ASSERT_TRUE(list.Clear());

			// --- Statureに対するソートテスト
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
		}

		/**********************************************************************************//**
			@brief		整列済みリストに要素を挿入した後のソートの実行テスト
			@details	ID:リスト-5\n
						データのソート機能のテストです。\n
						要素が整列済みである整列済みリストの各所に新規要素を挿入した後、ソートを実行した場合の挙動を確認しています。\n
						正しくソートされれば成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenAfterInsert) {

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
			LinkedList<UserData> list;

			// --- Ageに対するソートテスト
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";

			LinkedList<UserData>::ConstIterator it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "追加要素の挿入に失敗";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "追加要素の挿入に失敗";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Age));

			it = list.Begin();
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "リスト要素が想定されている順序になっていない";

			ASSERT_TRUE(list.Clear());

			// --- Statureに対するソートテスト
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 10.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";

			it = list.Begin();
			++it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(4, 50.0f))) << "追加要素の挿入に失敗";
			it = list.End();
			--it;
			ASSERT_TRUE(list.Insert(list.End(), UserData(5, 40.0f))) << "追加要素の挿入に失敗";

			ASSERT_NO_THROW(list.Sort(false, &UserData::_Stature));

			it = list.Begin();
			EXPECT_EQ(UserData(3, 10.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(2, 20.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(1, 30.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(5, 40.0f), *it) << "リスト要素が想定されている順序になっていない";
			++it;
			EXPECT_EQ(UserData(4, 50.0f), *it) << "リスト要素が想定されている順序になっていない";
		}

		/**********************************************************************************//**
			@brief		キーを指定しなかった際のソートの実行テスト
			@details	ID:リスト-6\n
						データのソート機能のテストです。\n
						キーを指定せずにソートを実行した場合の挙動を確認しています。\n
						エラー含め、何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(DataSortTest, TestSortWhenNullKey) {

			struct UserData
			{
				int		_Age;
				float	_Stature;

				UserData() : _Age(0), _Stature(0.0f) {}
				
				UserData(int age, float stature)
					: _Age(age), _Stature(stature) {}
			};
			LinkedList<UserData> list;
			
			ASSERT_TRUE(list.Insert(list.End(), UserData(1, 30.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(3, 20.0f))) << "初期要素の挿入に失敗";
			ASSERT_TRUE(list.Insert(list.End(), UserData(2, 10.0f))) << "初期要素の挿入に失敗";

			// 質問した内容に該当する箇所のため、一時的にコメントアウトしています。
			//EXPECT_DEATH(list.Sort(false, nullptr), "Assertion failed. *");
		}

	}
}