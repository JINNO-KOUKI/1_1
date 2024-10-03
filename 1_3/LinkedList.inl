#pragma once

#include <cassert>
#include "ResultData.h"

/// @brief		自作の双方向リストクラス
/// @details	ダミーノードを起点に、要素が循環するように配置されています。\n
///				ダミーノードの_Nextは先頭要素、_Prevは末尾要素になります。
//class LinkedList
//{
//public:
//	/// @brief デフォルトコンストラクタ
//	LinkedList() : _EOL(Node()), _Dummy(&_EOL, this), _ConstDummy(&_EOL, this), _Size(0) {}
//
//	/// @brief デストラクタ
//	~LinkedList() { Clear(); }
//
//private:
//	/// @brief		リスト内の一要素を表す構造体
//	/// @details	MyListクラス内部でのみ使用するため、アクセスはprivateです
//	struct Node
//	{
//		/// @brief 成績データ
//		ResultData _ResultData;
//		/// @brief 前のノードへのポインタ
//		Node* _Prev;
//		/// @brief 次のノードへのポインタ
//		Node* _Next;
//
//		/// @brief	デフォルトコンストラクタ
//		/// @detail	初期状態では、PrevもNextも自身へのポインタを持ちます
//		Node() : _ResultData(ResultData()), _Prev(this), _Next(this) {}
//
//		/// @brief			コピーコンストラクタ
//		/// @param other	コピー元
//		Node(const Node& other)
//			: _ResultData(other._ResultData), _Prev(other._Prev), _Next(other._Next) {}
//
//		/// @brief			等価比較演算子
//		/// @param other	右辺要素
//		/// @return			比較結果
//		/// @detail			ノード内の各要素それぞれが、すべて同一かどうかで判断します
//		bool operator==(const Node& other) const noexcept
//		{
//			return (_Prev == other._Prev) && (_Next) == (other._Next) && (_ResultData) == (other._ResultData);
//		}
//
//		/// @brief			非等価比較演算子
//		/// @param other	右辺要素
//		/// @return			比較結果
//		/// @detail			ノード内の各要素それぞれに対して比較を行い、一つでも異なればtrueを返します
//		bool operator!=(const Node& other)
//		{
//			return !((_Prev == other._Prev) && (_Next) == (other._Next) && (_ResultData) == (other._ResultData));
//		}
//
//	};
//
//public:
//
//	/// @brief MyListコンテナのイテレータ
//	class Iterator : public ConstIterator
//	{
//	public:	// コンストラクタ群
//
//		/// @brief	デフォルトコンストラクタ
//		/// @detail	初期状態では、指す先も関連付けされたリストも存在しない、不正イテレータになります。
//		Iterator() : ConstIterator() {}
//
//		/// @brief			引数付きコンストラクタ
//		/// @param target	イテレータが指し示すノード
//		/// @param list		関連付けされたリストのポインタ
//		Iterator(Node* target, LinkedList* list) : ConstIterator(target, list) {}
//
//		/// @brief	ConstIteratorからのコピーコンストラクタ
//		/// @detail	ConstIteratorを使用してコピーを作成できないようにします
//		Iterator(const ConstIterator&) = delete;
//
//	public:	// 演算子オーバーロード群
//
//		/// @brief	ConstIterator用コピー代入演算子
//		/// @detail	ConstIteratorからの呼び出しを禁止しています
//		Iterator& operator=(const ConstIterator& other) = delete;
//
//		/// @brief		イテレータの指す要素を非const要素として取得する
//		/// @return		非const要素
//		/// @details	※以下の条件に当てはまる場合、Assertが発生します\n
//		///				・関連付けされたリストがない\n
//		///				・ダミーノードを指すイテレータである\n
//		///				・指す要素がない	
//		ResultData& operator*() const noexcept
//		{
//			assert(_List != nullptr);
//			assert(_Target != &_List->_EOL);
//			assert(_Target != nullptr);
//
//			return _Target->_ResultData;
//		}
//	};

//};
//









		/// @brief	デフォルトコンストラクタ
		/// @detail	初期状態では、指す先も関連付けされたリストも存在しない、不正イテレータになります。
		LinkedList::ConstIterator::ConstIterator() : _Target(nullptr), _List(nullptr) {}

		/// @brief			引数付きコンストラクタ
		/// @param target	イテレータが指し示すノード
		/// @param list		関連付けられるリストのポインタ
		ConstIterator(Node* target, const LinkedList* list) : _Target(target), _List(list) {}

		/// @brief			コピーコンストラクタ
		/// @param other	コピー元
		ConstIterator(const ConstIterator& other)
		{
			_Target = other._Target;
			_List = other._List;
		}

		/// @brief			ムーブコンストラクタ
		/// @param other	移動元
		ConstIterator(ConstIterator&& other) noexcept
		{
			_Target = other._Target;
			_List = other._List;

			other._Target = nullptr;
			other._List = nullptr;
		}

	public:	// 演算子オーバーロード群

		/// @brief			コピー代入演算子
		/// @param other	コピー元
		/// @return			コピーされた値
		ConstIterator& operator=(const ConstIterator& other) noexcept
		{
			_Target = other._Target;
			_List = other._List;
			return *this;
		}

		/// @brief			ムーブ代入演算子
		/// @param other	ムーブ元
		/// @return			ムーブされた値
		ConstIterator& operator=(ConstIterator&& other) noexcept
		{
			_Target = other._Target;
			_List = other._List;

			return *this;
		}

		/// @brief		イテレータの指す要素を取得する
		/// @return		const要素
		/// @details	※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・ダミーノードを指すイテレータである\n
		///				・指す要素がない	
		const ResultData& operator*() const noexcept
		{
			assert(_List != nullptr);
			assert(_Target != &_List->_EOL);
			assert(_Target != nullptr);

			return _Target->_ResultData;
		}

		/// @brief		前置インクリメント
		/// @return		インクリメントされた後の値
		/// @details	リストの末尾に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・ダミーノードを指すイテレータである
		ConstIterator& operator++()
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != &_List->_EOL);

			_Target = _Target->_Next;
			return *this;
		}

		/// @brief		前置デクリメント
		/// @return		デクリメントされた後の値
		/// @details	リストの先頭に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・先頭要素を指すイテレータである
		ConstIterator& operator--()
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != _List->_EOL._Next);

			_Target = _Target->_Prev;
			return *this;
		}

		/// @brief		後置インクリメント
		/// @return		インクリメントされる前の値
		/// @details	リストの末尾に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・ダミーノードを指すイテレータである
		ConstIterator operator++(int)
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != &_List->_EOL);

			ConstIterator tOld = *this;
			++(*this);
			return tOld;
		}

		/// @brief		後置デクリメント
		/// @return		デクリメントされる前の値
		/// @details	リストの先頭に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・先頭要素を指すイテレータである
		ConstIterator operator--(int)
		{
			assert(_List != nullptr);
			assert(_List->Size() != 0);
			assert(_Target != _List->_EOL._Next);

			ConstIterator tOld = *this;
			--(*this);
			return tOld;
		}

		/// @brief			等価比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			イテレータの指し示すノードと関連付けされたリストが同一か判定します
		bool operator==(const ConstIterator& other) const noexcept
		{
			return (_Target == other._Target) && (_List == other._List);
		}

		/// @brief			非等価比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			イテレータの指し示すノードと関連付けされたリストのいずれか一つ以上が異なるか判定します
		bool operator!=(const ConstIterator& other) const noexcept
		{
			return !(*this == other);
		}

	protected:
		/// @brief イテレータの指しているノード
		Node* _Target;
		/// @brief 自身と関連付けられているリストのポインタ
		const LinkedList* _List;
	};






/// @brief リスト内のデータ数を取得します
/// @return リスト内のデータ数
inline unsigned int LinkedList::Size() const noexcept { return _Size; }

/// @brief				新規要素を挿入する
/// @param inIterator	挿入する場所を示すイテレータ
/// @param inResultData 挿入する成績データ
/// @return				データの挿入に成功した場合はTRUE、失敗した場合はFALSE
/// @details			挿入先はイテレータが示す要素の直前です。\n
///						※以下の条件に当てはまる場合、挿入せずにFALSEで終了します。\n
///						・関連付けされたリストが無い\n
///						・イテレータの指す要素が無い\n
///						・新規メモリの確保に失敗
inline bool LinkedList::Insert(const LinkedList::ConstIterator& inIterator, const ResultData& inResultData)
{
	// 自身と関連の無いイテレータの場合は、何もせずに終了
	if (inIterator._List != this) { return false; }
	// イテレータが無効値を指す場合も、終了
	if (inIterator._Target == nullptr) { return false; }

	// 新規ノードを作成
	Node* tNewNode = new (std::nothrow) Node();
	if (tNewNode == nullptr)
	{	// メモリ確保に失敗

		return false;
	}

	// 挿入箇所の直前要素を取得
	Node* tPrev = inIterator._Target->_Prev;

	// 成績データを設定
	tNewNode->_ResultData = inResultData;

	// -- イテレータの指す要素の手前に、新規ノードを配置
	tNewNode->_Prev = tPrev;
	tNewNode->_Next = inIterator._Target;
	tPrev->_Next = tNewNode;
	inIterator._Target->_Prev = tNewNode;

	// 要素数を更新
	++_Size;

	return true;
}

/// @brief				要素を削除する
/// @param inIterator	削除したい要素を指すイテレータ
/// @return				削除に成功したらTRUE、失敗したらFALSE
/// @details			イテレータが指し示す要素を削除して、前後の要素をつなげます。\n
///						削除後、イテレータの指す要素は無効になります。\n
///						※以下の条件に当てはまる場合、何もせずにFALSEで終了します。\n
///						・イテレータの指す要素が無い\n
///						・イテレータがダミーノードを指している\n
///						・関連付けされたリストが無い
inline bool LinkedList::Remove(const LinkedList::ConstIterator& inIterator)
{
	// 自身と関連の無いイテレータの場合は、何もせずに終了
	if (inIterator._List != this) { return false; }

	if (inIterator._Target != nullptr && inIterator._Target != &_EOL)
	{	// イテレータの指す要素が有効値(nullでもなく、ダミーでもない)だった場合

		Node* tPrev = inIterator._Target->_Prev;
		Node* tNext = inIterator._Target->_Next;

		// 削除要素の前後をつなげる
		tPrev->_Next = tNext;
		tNext->_Prev = tPrev;

		// 削除要素のdelete
		delete inIterator._Target;

		// 要素数を更新
		--_Size;

		return true;
	}
	else
	{	// イテレータが有効値でない

		return false;
	}
}

/// @brief		リストに格納されているすべての要素を削除する
/// @return		削除に成功したらTRUE、失敗したらFALSE
///	@details	要素数が0の場合、何もせずにTRUEで終了します。\n
///				要素数以上に削除処理が発生した場合や、すべての要素が正しく開放されなかった場合、\n
///				Assertが発生します。
inline bool LinkedList::Clear()
{
	// 要素数0だったら終了
	if (!_Size) { return true; }

	// 最後尾のノードを取得
	Node* tNode = _EOL._Prev;

	// -- ダミーノードを指し示すまで繰り返し
	while (true)
	{
		// 一つ前の要素に移動
		tNode = tNode->_Prev;

		// 次の要素を削除
		delete tNode->_Next;

		// サイズを更新
		--_Size;

		// サイズが負の値になった場合、Assertを発生させる
		assert(_Size >= 0);

		// ダミーノードを指し示したら終了
		if (tNode == &_EOL) { break; }
	}
	// 想定通り全要素の削除が完了していない場合、Assertを発生させる
	assert(_Size == 0);

	// -- メンバ変数の初期化
	_EOL._Prev = &_EOL;
	_EOL._Next = &_EOL;

	return true;
}

/// @brief	先頭のイテレータを取得する
/// @return	先頭のイテレータ
/// @detail	要素が一つも存在しない場合は、ダミーノードを指すイテレータを返却します。
inline LinkedList::Iterator LinkedList::Begin() noexcept { return Iterator(_EOL._Next, this); }

/// @brief		先頭のイテレータを取得する
/// @return		先頭のイテレータ
/// @details	範囲for文に対応させるための別名関数です。Begin()と同一の動作をします。
///				要素が一つも存在しない場合は、ダミーノードを指すイテレータを返却します。
inline LinkedList::Iterator LinkedList::begin() noexcept { return Begin(); }

/// @brief	末尾のイテレータを取得する
/// @return 末尾のイテレータ
/// @detail	いかなる場合でも、常にダミーノードを指すイテレータを返却します。
inline LinkedList::Iterator LinkedList::End() noexcept { return Iterator(&_EOL, this); }

/// @brief		末尾のイテレータを取得する
/// @return		末尾のイテレータ
/// @details	範囲for文に対応させるための別名関数です。End()と同一の動作をします。
///				いかなる場合でも、常にダミーノードを指すイテレータを返却します。
inline LinkedList::Iterator LinkedList::end() noexcept { return End(); }

/// @brief	先頭のコンストイテレータを取得する
/// @return 先頭のコンストイテレータ
/// @detail	要素が一つも存在しない場合は、ダミーノードを指すコンストイテレータを返却します。
inline LinkedList::ConstIterator LinkedList::ConstBegin() const noexcept { return ConstIterator(_EOL._Next, this); }

/// @brief	末尾のコンストイテレータを取得する
/// @return 末尾のコンストイテレータ
/// @detail	いかなる場合でも、常にダミーノードを指すコンストイテレータを返却します。
inline LinkedList::ConstIterator LinkedList::ConstEnd() const noexcept { return ConstIterator(&_EOL, this); }

/// @brief		リストの先頭要素を取得する
/// @return		リストの先頭要素
/// @details	要素が一つも格納されていない場合は、Assertが発生します。\n
///				渡される値はコピーです。
inline ResultData LinkedList::Front() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Next->_ResultData;
}

/// @brief		リストの末尾要素を取得する
/// @return		リストの末尾要素
/// @details	要素が一つも格納されていない場合は、Assertが発生します。\n
///				渡される値はコピーです。
inline ResultData LinkedList::Back() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Prev->_ResultData;
}

/// @brief		ダミーノードを指すイテレータを取得する
/// @return		ダミーノードを指すイテレータ
/// @details	ダミーノードを指すイテレータを返却します。\n
///				End()で返されるイテレータと同一です。\n
///				この関数由来のもの以外で、ダミーノードを指すイテレータであることが想定される際に\n
///				同一のイテレータか確認するために使用します。
inline const LinkedList::Iterator& LinkedList::Dummy() noexcept { return _Dummy; }

/// @brief		ダミーノードを指すコンストイテレータを取得する
/// @return		ダミーノードを指すコンストイテレータ
/// @details	ダミーノードを指すコンストイテレータを返却します。\n
///				ConstEnd()で返されるコンストイテレータと同一です。\n
///				この関数由来のもの以外で、ダミーノードを指すコンストイテレータであることが想定される際に\n
///				同一のコンストイテレータか確認するために使用します。
inline const LinkedList::ConstIterator& LinkedList::ConstDummy() const noexcept { return _ConstDummy; }
