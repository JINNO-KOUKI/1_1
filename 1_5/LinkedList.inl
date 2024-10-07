#pragma once

#include <cassert>

// ====================================================================================
//		Nodeの実装
// ====================================================================================

// ####### コンストラクタ群 ##########################

/// @brief		デフォルトコンストラクタ
/// @tparam T	格納されているデータ型
/// @detail		初期状態では、PrevもNextも自身へのポインタを持ちます
template <typename T>
inline LinkedList<T>::Node::Node() : _Data(T()), _Prev(this), _Next(this) {}

/// @brief			コピーコンストラクタ
/// @tparam T		格納されているデータ型
/// @param other	コピー元
template <typename T>
inline LinkedList<T>::Node::Node(const Node& other)
	: _Data(other._Data), _Prev(other._Prev), _Next(other._Next) {}

// ####### 演算子オーバーロード群 ##########################

/// @brief			等価比較演算子
/// @tparam T		格納されているデータ型
/// @param other	右辺要素
/// @return			比較結果
/// @detail			ノード内の各要素それぞれが、すべて同一かどうかで判断します
template <typename T>
inline bool LinkedList<T>::Node::operator==(const Node& other) const noexcept
{
	return (_Prev == other._Prev) && (_Next) == (other._Next) && (_Data) == (other._Data);
}

/// @brief			非等価比較演算子
/// @tparam T		格納されているデータ型
/// @param other	右辺要素
/// @return			比較結果
/// @detail			ノード内の各要素それぞれに対して比較を行い、一つでも異なればtrueを返します
template <typename T>
inline bool LinkedList<T>::Node::operator!=(const Node& other)
{
	return !(*this == other);
}


// ====================================================================================
//		ConstIteratorの実装
// ====================================================================================

// ####### コンストラクタ群 ##########################

/// @brief		デフォルトコンストラクタ
/// @tparam T	格納されているデータ型
/// @detail		初期状態では、指す先も関連付けされたリストも存在しない、不正イテレータになります。
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator() : _Target(nullptr), _List(nullptr) {}

/// @brief			引数付きコンストラクタ
/// @tparam T		格納されているデータ型
/// @param target	イテレータが指し示すノード
/// @param list		関連付けられるリストのポインタ
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator(Node* target, const LinkedList<T>* list) : _Target(target), _List(list) {}

/// @brief			コピーコンストラクタ
/// @tparam T		格納されているデータ型
/// @param other	コピー元
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator(const ConstIterator& other)
{
	_Target = other._Target;
	_List = other._List;
}

/// @brief			ムーブコンストラクタ
/// @tparam T		格納されているデータ型
/// @param other	移動元
template <typename T>
inline LinkedList<T>::ConstIterator::ConstIterator(ConstIterator&& other) noexcept
{
	_Target = other._Target;
	_List = other._List;

	other._Target = nullptr;
	other._List = nullptr;
}

// ####### 演算子オーバーロード群 ##########################

/// @brief			コピー代入演算子
/// @tparam T		格納されているデータ型
/// @param other	コピー元
/// @return			コピーされた値
template <typename T>
inline typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator=(const LinkedList<T>::ConstIterator& other) noexcept
{
	_Target = other._Target;
	_List = other._List;
	return *this;
}

/// @brief			ムーブ代入演算子
/// @tparam	T		格納されているデータ型
/// @param other	ムーブ元
/// @return			ムーブされた値
template <typename T>
inline typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator=(ConstIterator&& other) noexcept
{
	_Target = other._Target;
	_List = other._List;

	return *this;
}

/// @brief		イテレータの指す要素を取得する
/// @tparam T	格納されているデータ型
/// @return		const要素
/// @details	※以下の条件に当てはまる場合、Assertが発生します\n
///				・関連付けされたリストがない\n
///				・ダミーノードを指すイテレータである\n
///				・指す要素がない	
template <typename T>
inline const T& LinkedList<T>::ConstIterator::operator*() const noexcept
{
	assert(_List != nullptr);
	assert(_Target != &_List->_EOL);
	assert(_Target != nullptr);

	return _Target->_Data;
}

/// @brief		前置インクリメント
/// @tparam T	格納されているデータ型
/// @return		インクリメントされた後の値
/// @details	リストの末尾に向かって、このイテレータが指す先を一つ進めます\n
///				※以下の条件に当てはまる場合、Assertが発生します\n
///				・関連付けされたリストがない\n
///				・参照先リストが空\n
///				・ダミーノードを指すイテレータである
template <typename T>
inline typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator++()
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != &_List->_EOL);

	_Target = _Target->_Next;
	return *this;
}

/// @brief		前置デクリメント
/// @tparam T	格納されているデータ型
/// @return		デクリメントされた後の値
/// @details	リストの先頭に向かって、このイテレータが指す先を一つ進めます\n
///				※以下の条件に当てはまる場合、Assertが発生します\n
///				・関連付けされたリストがない\n
///				・参照先リストが空\n
///				・先頭要素を指すイテレータである
template <typename T>
inline typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator--()
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != _List->_EOL._Next);

	_Target = _Target->_Prev;
	return *this;
}

/// @brief		後置インクリメント
/// @tparam T	格納されているデータ型
/// @return		インクリメントされる前の値
/// @details	リストの末尾に向かって、このイテレータが指す先を一つ進めます\n
///				※以下の条件に当てはまる場合、Assertが発生します\n
///				・関連付けされたリストがない\n
///				・参照先リストが空\n
///				・ダミーノードを指すイテレータである
template <typename T>
inline typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int)
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != &_List->_EOL);

	ConstIterator tOld = *this;
	++(*this);
	return tOld;
}

/// @brief		後置デクリメント
/// @tparam T	格納されているデータ型
/// @return		デクリメントされる前の値
/// @details	リストの先頭に向かって、このイテレータが指す先を一つ進めます\n
///				※以下の条件に当てはまる場合、Assertが発生します\n
///				・関連付けされたリストがない\n
///				・参照先リストが空\n
///				・先頭要素を指すイテレータである
template <typename T>
inline typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int)
{
	assert(_List != nullptr);
	assert(_List->Size() != 0);
	assert(_Target != _List->_EOL._Next);

	ConstIterator tOld = *this;
	--(*this);
	return tOld;
}

/// @brief			等価比較演算子
/// @tparam T		格納されているデータ型
/// @param other	右辺要素
/// @return			比較結果
/// @detail			イテレータの指し示すノードと関連付けされたリストが同一か判定します
template <typename T>
inline bool LinkedList<T>::ConstIterator::operator==(const ConstIterator& other) const noexcept
{
	return (_Target == other._Target) && (_List == other._List);
}

/// @brief			非等価比較演算子
/// @tparam T		格納されているデータ型
/// @param other	右辺要素
/// @return			比較結果
/// @detail			イテレータの指し示すノードと関連付けされたリストのいずれか一つ以上が異なるか判定します
template <typename T>
inline bool LinkedList<T>::ConstIterator::operator!=(const ConstIterator& other) const noexcept
{
	return !(*this == other);
}

/// @brief			比較演算子
/// @param other	右辺要素
/// @return			比較結果
/// @detail			otherイテレータが左辺より、リストの末尾側要素を指し示していればTRUEを返します。
template <typename T>
bool LinkedList<T>::ConstIterator::operator<(const ConstIterator& other) const
{
	return (other - *this) > 0;
}

/// @brief			比較演算子
/// @param other	右辺要素
/// @return			比較結果
/// @details		otherイテレータが左辺と同一または、\n
///					左辺より、リストの末尾側要素を指し示していればTRUEを返します。
template <typename T>
bool LinkedList<T>::ConstIterator::operator<=(const ConstIterator& other) const
{
	return (other - *this) >= 0;
}

/// @brief			比較演算子
/// @param other	右辺要素
/// @return			比較結果
/// @detail			otherイテレータが左辺より、リストの先頭側要素を指し示していればTRUEを返します。
template <typename T>
bool LinkedList<T>::ConstIterator::operator>(const ConstIterator& other) const
{
	return (*this - other) > 0;
}

/// @brief			比較演算子
/// @param other	右辺要素
/// @return			比較結果
/// @details		otherイテレータが左辺と同一または、\n
///					左辺より、リストの先頭側要素を指し示していればTRUEを返します。
template <typename T>
bool LinkedList<T>::ConstIterator::operator>=(const ConstIterator& other) const
{
	return (*this - other) >= 0;
}

/// @brief			減算演算子
/// @param other	右辺要素
/// @return			イテレータ間の距離
/// @details		2つのイテレータ間の距離を求めます。
///					例 : a[0] - a[1] = -1,  a[2] - [0] = 2
template <typename T>
int LinkedList<T>::ConstIterator::operator-(const ConstIterator& other) const
{
	int tRange = 0;
	ConstIterator tEndIt = this->_List->ConstEnd();

	for (ConstIterator it = *this; it != tEndIt; ++it)
	{ 
		if (it == other) { return tRange; }
		--tRange;
	}
	if (other == tEndIt) { return tRange; }
	tRange = 0;
	for (ConstIterator it = other; it != tEndIt; ++it)
	{
		if (it == *this) { return tRange; }
		++tRange;
	}
	if (*this == tEndIt) { return tRange; }

	return 0;
}

/// @brief			intとの減算演算子
/// @param other	右辺要素(int型) オフセット
/// @return			オフセット後のコンストイテレータ
/// @details		右辺に指定された値だけ、先頭側にイテレートさせた際のコンストイテレータを返します。\n
///					もし、リストをはみ出すほどの値を指定された場合は、LinkedList<T>::ConstEnd()と同等の値が返ります。
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator-(const int& other) const
{
	if (*this - this->_List->ConstBegin() >= other)
	{
		ConstIterator tNewCIT = *this;
		for (int i = 0; i < other; ++i, --tNewCIT) {}
		return tNewCIT;
	}
	else { return this->_List->ConstEnd(); }
}

/// @brief			intとの加算演算子
/// @param other	右辺要素(int型) オフセット
/// @return			オフセット後のコンストイテレータ
/// @details		右辺に指定された値だけ、末尾側にイテレートさせた際のコンストイテレータを返します。\n
///					もし、リストをはみ出すほどの値を指定された場合は、LinkedList<T>::ConstEnd()と同等の値が返ります。
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator+(const int& other) const
{
	if (this->_List->ConstEnd() - *this > other)
	{
		ConstIterator tNewCIT = *this;
		for (int i = 0; i < other; ++i, ++tNewCIT) {}
		return tNewCIT;
	}
	else { return this->_List->ConstEnd(); }
}

// ====================================================================================
//		Iteratorの実装
// ====================================================================================

// ####### コンストラクタ群 ##########################

/// @brief		デフォルトコンストラクタ
/// @tparam T	格納されているデータ型
/// @detail		初期状態では、指す先も関連付けされたリストも存在しない、不正イテレータになります。
template <typename T>
inline LinkedList<T>::Iterator::Iterator() : LinkedList<T>::ConstIterator() {}

/// @brief			引数付きコンストラクタ
/// @tparam T		格納されているデータ型
/// @param target	イテレータが指し示すノード
/// @param list		関連付けされたリストのポインタ
template <typename T>
inline LinkedList<T>::Iterator::Iterator(Node* target, LinkedList<T>* list) : ConstIterator(target, list) {}


// ####### コンストラクタ群 ##########################

/// @brief		イテレータの指す要素を非const要素として取得する
/// @tparam T	格納されているデータ型
/// @return		非const要素
/// @details	※以下の条件に当てはまる場合、Assertが発生します\n
///				・関連付けされたリストがない\n
///				・ダミーノードを指すイテレータである\n
///				・指す要素がない
template <typename T>
inline T& LinkedList<T>::Iterator::operator*() const noexcept
{
	assert(this->_List != nullptr);
	assert(this->_Target != &this->_List->_EOL);
	assert(this->_Target != nullptr);

	return this->_Target->_Data;
}

// ====================================================================================
//		LinkedListの実装
// ====================================================================================

// ####### コンストラクタ群 ##########################

/// @brief	デフォルトコンストラクタ
/// @tparam T 格納されているデータ型
template <typename T>
inline LinkedList<T>::LinkedList() : _EOL(Node()), _Dummy(&_EOL, this), _Size(0) {}

/// @brief		デストラクタ
/// @tparam T	格納されているデータ型
template <typename T>
inline LinkedList<T>::~LinkedList() { Clear(); }

// ####### メンバ関数群 ##########################

/// @brief		リスト内のデータ数を取得します
/// @tparam T	格納されているデータ型
/// @return		リスト内のデータ数
template <typename T>
inline unsigned int LinkedList<T>::Size() const noexcept { return _Size; }

/// @brief				新規要素を挿入する
/// @tparam T			格納されているデータ型
/// @param inIterator	挿入する場所を示すイテレータ
/// @param inData		挿入する成績データ
/// @return				データの挿入に成功した場合はTRUE、失敗した場合はFALSE
/// @details			挿入先はイテレータが示す要素の直前です。\n
///						※以下の条件に当てはまる場合、挿入せずにFALSEで終了します。\n
///						・関連付けされたリストが無い\n
///						・イテレータの指す要素が無い\n
///						・新規メモリの確保に失敗
template <typename T>
inline bool LinkedList<T>::Insert(const ConstIterator& inIterator, const T& inData)
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
	tNewNode->_Data = inData;

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
/// @tparam T			格納されているデータ型
/// @param inIterator	削除したい要素を指すイテレータ
/// @return				削除に成功したらTRUE、失敗したらFALSE
/// @details			イテレータが指し示す要素を削除して、前後の要素をつなげます。\n
///						削除後、イテレータの指す要素は無効になります。\n
///						※以下の条件に当てはまる場合、何もせずにFALSEで終了します。\n
///						・イテレータの指す要素が無い\n
///						・イテレータがダミーノードを指している\n
///						・関連付けされたリストが無い
template <typename T>
inline bool LinkedList<T>::Remove(const ConstIterator& inIterator)
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
///				リストが空になるまでRemove(LinkedList::Begin())を呼び出しています。
template <typename T>
inline bool LinkedList<T>::Clear()
{
	// 要素数0になったら終了
	while (_Size > 0) { Remove(Begin()); }

	return true;
}

/// @brief			指定したキーに準じて並べ替える
/// @tparam Key		比較に使用するキーの型
/// @param inIsDesc 降順にするか(FALSE : 昇順, TRUE : 降順)
/// @param key		比較に使用するキー
/// @detail			リストに格納されている要素を、指定したキーに準じて並べ替えます。
template<typename T>
template<typename Key>

// 質問内容:	引数keyの型を「Key T::*」にすると、メンバのみに限定はできますが、nullptr指定できなくなります。
//				また、↓のように
//				「inline void LinkedList<T>::Sort(const bool& inIsDesc, Key key)」
//				とすると、すべての要素が指定できるようになってしまうため困っています。
//				SFINAE（std::enable_if）という、テンプレート引数を限定できるものが存在することを知りましたが、
//				その利用がふさわしい場面なのか分かりません。
inline void LinkedList<T>::Sort(const bool& inIsDesc, Key T::* key)
{
	// キー指定がnullptrだった場合は、何もせずに終了
	if (key == nullptr) { return; }
	// 並べ替える要素が不足している場合は、何もせずに終了
	if (_Size <= 1) { return; }

	// クイックソートによる並べ替え開始
	Iterator tBackIt = End();
	--tBackIt;
	QuickSort(Begin(), tBackIt, key);

	// 降順フラグに基づいて、逆順に並べ替え
	if (inIsDesc) { Reverse(); }
}

/// @brief	要素の格納順を逆順に並べ替える
/// @detail	リストに格納されているすべての要素を、現在の逆順に並べ替えます。
template <typename T>
inline void LinkedList<T>::Reverse()
{
	int tHalfSize = _Size / 2;
	Iterator tBeginIt = Begin();
	Iterator tEndIt = End();
	--tEndIt;

	for (int i = 0; i < tHalfSize; ++i, ++tBeginIt, --tEndIt)
	{
		Swap(tBeginIt, tEndIt);
	}
}

/// @brief		先頭のイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		先頭のイテレータ
/// @detail		要素が一つも存在しない場合は、ダミーノードを指すイテレータを返却します。
template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::Begin() noexcept { return Iterator(_EOL._Next, this); }

/// @brief		先頭のイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		先頭のイテレータ
/// @details	範囲for文に対応させるための別名関数です。Begin()と同一の動作をします。
///				要素が一つも存在しない場合は、ダミーノードを指すイテレータを返却します。
template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::begin() noexcept { return Begin(); }

/// @brief		末尾のイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		末尾のイテレータ
/// @detail		いかなる場合でも、常にダミーノードを指すイテレータを返却します。
template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::End() noexcept { return Iterator(&_EOL, this); }

/// @brief		末尾のイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		末尾のイテレータ
/// @details	範囲for文に対応させるための別名関数です。End()と同一の動作をします。
///				いかなる場合でも、常にダミーノードを指すイテレータを返却します。
template <typename T>
inline typename LinkedList<T>::Iterator LinkedList<T>::end() noexcept { return End(); }

/// @brief		先頭のコンストイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		先頭のコンストイテレータ
/// @detail		要素が一つも存在しない場合は、ダミーノードを指すコンストイテレータを返却します。
template <typename T>
inline typename LinkedList<T>::ConstIterator LinkedList<T>::ConstBegin() const noexcept { return ConstIterator(_EOL._Next, this); }

/// @brief		末尾のコンストイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		末尾のコンストイテレータ
/// @detail		いかなる場合でも、常にダミーノードを指すコンストイテレータを返却します。
template <typename T>
inline typename LinkedList<T>::ConstIterator LinkedList<T>::ConstEnd() const noexcept { return ConstIterator(const_cast<Node*>(&_EOL), this); }

/// @brief		リストの先頭要素を取得する
/// @tparam T	格納されているデータ型
/// @return		リストの先頭要素
/// @details	要素が一つも格納されていない場合は、Assertが発生します。\n
///				渡される値はコピーです。
template <typename T>
inline T LinkedList<T>::Front() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Next->_Data;
}

/// @brief		リストの末尾要素を取得する
/// @tparam T	格納されているデータ型
/// @return		リストの末尾要素
/// @details	要素が一つも格納されていない場合は、Assertが発生します。\n
///				渡される値はコピーです。
template <typename T>
inline T LinkedList<T>::Back() const noexcept
{
	assert(_EOL._Next != nullptr);
	return _EOL._Prev->_Data;
}

/// @brief		ダミーノードを指すイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		ダミーノードを指すイテレータ
/// @details	ダミーノードを指すイテレータを返却します。\n
///				End()で返されるイテレータと同一です。\n
///				この関数由来のもの以外で、ダミーノードを指すイテレータであることが想定される際に\n
///				同一のイテレータか確認するために使用します。
template <typename T>
inline const typename LinkedList<T>::Iterator& LinkedList<T>::Dummy() noexcept { return _Dummy; }

/// @brief		ダミーノードを指すコンストイテレータを取得する
/// @tparam T	格納されているデータ型
/// @return		ダミーノードを指すコンストイテレータ
/// @details	ダミーノードを指すコンストイテレータを返却します。\n
///				ConstEnd()で返されるコンストイテレータと同一です。\n
///				この関数由来のもの以外で、ダミーノードを指すコンストイテレータであることが想定される際に\n
///				同一のコンストイテレータか確認するために使用します。
template <typename T>
inline const typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstDummy() const noexcept { return _Dummy; }

/// @brief			2つの要素を入れ替える
/// @param inItA	Aイテレータ
/// @param inItB	Bイテレータ
/// @details		AとBそれぞれのイテレータが指す要素同士の、リスト内での格納位置を入れ替えます。\n
///					その際、イテレータの指す要素の内容は変わりますが、位置は変わりません。
template <typename T>
inline void LinkedList<T>::Swap(const Iterator& inItA, const Iterator& inItB) noexcept
{
	Node* tNodeA = inItA.ConstIterator::_Target;
	Node* tNodeB = inItB.ConstIterator::_Target;

	// -- ノード内データのスワップ
	T tData = tNodeA->_Data;
	tNodeA->_Data = tNodeB->_Data;
	tNodeB->_Data = tData;
}

// 参考にしたWebサイトのURL → https://webpia.jp/quick_sort/
/// @brief				クイックソート
/// @tparam Key			並べ替えに使用するキーの型
/// @param inLeftIt		並べ替える範囲の先頭イテレータ
/// @param inRightIt	並べ替える範囲の末尾イテレータ
/// @param key			並べ替えに使用するキー
/// @details			クイックソートアルゴリズムを用いて、要素を昇順に並べ替えます。\n
///						イテレータがEnd()と同一だった場合、Assertが発生します。
template <typename T>
template <typename Key>
inline void LinkedList<T>::QuickSort(const Iterator& inLeftIt, const Iterator& inRightIt, Key T::*key)
{
	// イテレータがEnd()と同一だったら例外を投げる
	assert(inLeftIt != End());
	assert(inRightIt != End());

	// 軸要素(ピボット)となる要素の、先頭からのオフセットを計算
	int tOffsetToCenter = (inRightIt - inLeftIt) / 2;

	// オフセットを先頭イテレータに適用し、ピボットのイテレータを作成
	Iterator tPivotIt = inLeftIt;
	for (int i = 0; i < tOffsetToCenter; ++i, ++tPivotIt) {}

	// ピボットイテレータの指す値を保持
	Key tPivotData = (*tPivotIt).*key;

	// 各端イテレータを一時変数にコピー(ずらしていくため。)
	Iterator tLeftIt = inLeftIt;
	Iterator tRightIt = inRightIt;

	// すべての要素を走査するまで繰り返し
	while (true)
	{
		// ピボットの値以上の要素が見つかるまで左端イテレータをずらしていく
		while ((*tLeftIt).*key < tPivotData) { ++tLeftIt; }
		// ピボットの値以下の要素が見つかるまで右端イテレータをずらしていく
		while (tPivotData < (*tRightIt).*key) { --tRightIt; }
		
		// 各端イテレータが衝突または追い越したら終了
		if (tLeftIt >= tRightIt) break;

		// イテレータの指す要素を入れ替える
		Swap(tLeftIt, tRightIt);

		// 次の要素から再度走査する
		++tLeftIt; --tRightIt;
	}

	// -- クイックソートを再帰的に呼び出す
	// ※	通常であれば次の要素にオフセットさせた上で、
	//		探索範囲が残っていれば再帰呼び出し判定を行うところだが、
	//		オフセットさせた先がダミーノードを指していた場合Assartが発生してしまうため、
	//		オフセット後の値がダミーノードで無いことを確認した上で再帰呼び出し判定を行っている。
	if(tLeftIt - 1 != ConstEnd())
	{
		--tLeftIt;
		if (inLeftIt < tLeftIt) QuickSort(inLeftIt, tLeftIt, key);
	}
	if (tRightIt + 1 != ConstEnd())
	{
		++tRightIt;
		if (inRightIt > tRightIt) QuickSort(tRightIt, inRightIt, key);
	}
	
}
