#pragma once

#include <cassert>

/// @brief		自作の双方向リストクラス
/// @tparam T	格納するデータ型
/// @details	ダミーノードを起点に、要素が循環するように配置されています。\n
///				ダミーノードの_Nextは先頭要素、_Prevは末尾要素になります。
template <typename T>
class LinkedList
{
public:
	/// @brief デフォルトコンストラクタ
	LinkedList();

	/// @brief デストラクタ
	~LinkedList();

private:
	/// @brief		リスト内の一要素を表す構造体
	/// @details	MyListクラス内部でのみ使用するため、アクセスはprivateです
	struct Node
	{
		/// @brief		格納データ
		/// @tparam T	格納されているデータ型
		T _Data;
		/// @brief 前のノードへのポインタ
		Node* _Prev;
		/// @brief 次のノードへのポインタ
		Node* _Next;

		/// @brief	デフォルトコンストラクタ
		/// @detail	初期状態では、PrevもNextも自身へのポインタを持ちます
		Node();

		/// @brief			コピーコンストラクタ
		/// @param other	コピー元
		Node(const Node& other);

		/// @brief			等価比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			ノード内の各要素それぞれが、すべて同一かどうかで判断します
		bool operator==(const Node& other) const noexcept;

		/// @brief			非等価比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			ノード内の各要素それぞれに対して比較を行い、一つでも異なればtrueを返します
		bool operator!=(const Node& other);

	};

public:
	/// @brief LinkedListのコンストイテレータ
	class ConstIterator
	{
		/// @brief		LinkedListへのフレンド属性定義
		/// @tparam T	格納されているデータ型
		friend LinkedList<T>;	// メンバ変数へのアクセスは、サブクラスとLinkedListクラスからのみ可能としています

	public:	// コンストラクタ群

		/// @brief	デフォルトコンストラクタ
		/// @detail	初期状態では、指す先も関連付けされたリストも存在しない、不正イテレータになります。
		ConstIterator();

		/// @brief			引数付きコンストラクタ
		/// @tparam T		格納されているデータ型
		/// @param target	イテレータが指し示すノード
		/// @param list		関連付けられるリストのポインタ
		ConstIterator(Node* target, const LinkedList<T>* list);

		/// @brief			コピーコンストラクタ
		/// @param other	コピー元
		ConstIterator(const ConstIterator& other);

		/// @brief			ムーブコンストラクタ
		/// @param other	移動元
		ConstIterator(ConstIterator&& other) noexcept;

	public:	// 演算子オーバーロード群

		/// @brief			コピー代入演算子
		/// @param other	コピー元
		/// @return			コピーされた値
		ConstIterator& operator=(const ConstIterator& other) noexcept;

		/// @brief			ムーブ代入演算子
		/// @param other	ムーブ元
		/// @return			ムーブされた値
		ConstIterator& operator=(ConstIterator&& other) noexcept;

		/// @brief		イテレータの指す要素を取得する
		/// @tparam T	格納されているデータ型
		/// @return		const要素
		/// @details	※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・ダミーノードを指すイテレータである\n
		///				・指す要素がない
		const T& operator*() const noexcept;

		/// @brief		前置インクリメント
		/// @return		インクリメントされた後の値
		/// @details	リストの末尾に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・ダミーノードを指すイテレータである
		ConstIterator& operator++();

		/// @brief		前置デクリメント
		/// @return		デクリメントされた後の値
		/// @details	リストの先頭に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・先頭要素を指すイテレータである
		ConstIterator& operator--();

		/// @brief		後置インクリメント
		/// @return		インクリメントされる前の値
		/// @details	リストの末尾に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・ダミーノードを指すイテレータである
		ConstIterator operator++(int);

		/// @brief		後置デクリメント
		/// @return		デクリメントされる前の値
		/// @details	リストの先頭に向かって、このイテレータが指す先を一つ進めます\n
		///				※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・参照先リストが空\n
		///				・先頭要素を指すイテレータである
		ConstIterator operator--(int);

		/// @brief			等価比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			イテレータの指し示すノードと関連付けされたリストが同一か判定します
		bool operator==(const ConstIterator& other) const noexcept;

		/// @brief			非等価比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			イテレータの指し示すノードと関連付けされたリストのいずれか一つ以上が異なるか判定します
		bool operator!=(const ConstIterator& other) const noexcept;

		/// @brief			比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			otherイテレータが左辺より、リストの末尾側要素を指し示していればTRUEを返します。
		bool operator<(const ConstIterator& other) const;

		/// @brief			比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @details		otherイテレータが左辺と同一または、\n
		///					左辺より、リストの末尾側要素を指し示していればTRUEを返します。
		bool operator<=(const ConstIterator& other) const;

		/// @brief			比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @detail			otherイテレータが左辺より、リストの先頭側要素を指し示していればTRUEを返します。
		bool operator>(const ConstIterator& other) const;

		/// @brief			比較演算子
		/// @param other	右辺要素
		/// @return			比較結果
		/// @details		otherイテレータが左辺と同一または、\n
		///					左辺より、リストの先頭側要素を指し示していればTRUEを返します。
		bool operator>=(const ConstIterator& other) const;

		/// @brief			減算演算子
		/// @param other	右辺要素
		/// @return			イテレータ間の距離
		/// @details		2つのイテレータ間の距離を求めます。
		///					例 : a[0] - a[1] = -1,  a[2] - [0] = 2
		int operator-(const ConstIterator& other) const;

		/// @brief			intとの減算演算子
		/// @param other	右辺要素(int型) オフセット
		/// @return			オフセット後のコンストイテレータ
		/// @details		右辺に指定された値だけ、先頭側にイテレートさせた際のコンストイテレータを返します。\n
		///					もし、リストをはみ出すほどの値を指定された場合は、LinkedList<T>::ConstEnd()と同等の値が返ります。
		ConstIterator operator-(const int& other) const;

		/// @brief			intとの加算演算子
		/// @param other	右辺要素(int型) オフセット
		/// @return			オフセット後のコンストイテレータ
		/// @details		右辺に指定された値だけ、末尾側にイテレートさせた際のコンストイテレータを返します。\n
		///					もし、リストをはみ出すほどの値を指定された場合は、LinkedList<T>::ConstEnd()と同等の値が返ります。
		ConstIterator operator+(const int& other) const;

	protected:
		/// @brief イテレータの指しているノード
		Node* _Target;
		/// @brief		自身と関連付けられているリストのポインタ
		/// @tparam T	格納されているデータ型
		const LinkedList<T>* _List;
	};

	/// @brief LinkedListのイテレータ
	class Iterator : public ConstIterator
	{
	public:	// コンストラクタ群

		/// @brief	デフォルトコンストラクタ
		/// @detail	初期状態では、指す先も関連付けされたリストも存在しない、不正イテレータになります。
		Iterator();

		/// @brief			引数付きコンストラクタ
		/// @tparam T		格納されているデータ型
		/// @param target	イテレータが指し示すノード
		/// @param list		関連付けされたリストのポインタ
		Iterator(Node* target, LinkedList<T>* list);

		/// @brief	ConstIteratorからのコピーコンストラクタ
		/// @detail	ConstIteratorを使用してコピーを作成できないようにします
		Iterator(const ConstIterator&) = delete;

	public:	// 演算子オーバーロード群

		/// @brief	ConstIterator用コピー代入演算子
		/// @detail	ConstIteratorからの呼び出しを禁止しています
		Iterator& operator=(const ConstIterator& other) = delete;

		/// @brief		イテレータの指す要素を非const要素として取得する
		/// @tparam T	格納されているデータ型
		/// @return		非const要素
		/// @details	※以下の条件に当てはまる場合、Assertが発生します\n
		///				・関連付けされたリストがない\n
		///				・ダミーノードを指すイテレータである\n
		///				・指す要素がない
		T& operator*() const noexcept;
	};

	/// @brief リスト内のデータ数を取得します
	/// @return リスト内のデータ数
	inline unsigned int Size() const noexcept;

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
	inline bool Insert(const ConstIterator& inIterator, const T& inData);

	/// @brief				要素を削除する
	/// @param inIterator	削除したい要素を指すイテレータ
	/// @return				削除に成功したらTRUE、失敗したらFALSE
	/// @details			イテレータが指し示す要素を削除して、前後の要素をつなげます。\n
	///						削除後、イテレータの指す要素は無効になります。\n
	///						※以下の条件に当てはまる場合、何もせずにFALSEで終了します。\n
	///						・イテレータの指す要素が無い\n
	///						・イテレータがダミーノードを指している\n
	///						・関連付けされたリストが無い
	inline bool Remove(const ConstIterator& inIterator);

	/// @brief		リストに格納されているすべての要素を削除する
	/// @return		削除に成功したらTRUE、失敗したらFALSE
	///	@details	要素数が0の場合、何もせずにTRUEで終了します。\n
	///				リストが空になるまでRemove(LinkedList::Begin())を呼び出しています。
	inline bool Clear();

	/// @brief			指定した比較関数に準じて並べ替える
	/// @tparam T		格納されているデータの型
	/// @param inComp	比較に使用する関数
	/// @details		リストに格納されている要素を、指定した比較関数の結果に準じて並べ替えます。\n
	///					比較関数を渡さない場合、何もせずに終了します。
	inline void Sort(bool (*inComp)(const T&, const T&));

	/// @brief	要素の格納順を逆順に並べ替える
	/// @detail	リストに格納されているすべての要素を、現在の逆順に並べ替えます。
	inline void Reverse();

	/// @brief	先頭のイテレータを取得する
	/// @return	先頭のイテレータ
	/// @detail	要素が一つも存在しない場合は、ダミーノードを指すイテレータを返却します。
	inline Iterator Begin() noexcept;

	/// @brief		先頭のイテレータを取得する
	/// @return		先頭のイテレータ
	/// @details	範囲for文に対応させるための別名関数です。Begin()と同一の動作をします。
	///				要素が一つも存在しない場合は、ダミーノードを指すイテレータを返却します。
	inline Iterator begin() noexcept;

	/// @brief	末尾のイテレータを取得する
	/// @return 末尾のイテレータ
	/// @detail	いかなる場合でも、常にダミーノードを指すイテレータを返却します。
	inline Iterator End() noexcept;

	/// @brief		末尾のイテレータを取得する
	/// @return		末尾のイテレータ
	/// @details	範囲for文に対応させるための別名関数です。End()と同一の動作をします。
	///				いかなる場合でも、常にダミーノードを指すイテレータを返却します。
	inline Iterator end() noexcept;

	/// @brief	先頭のコンストイテレータを取得する
	/// @return 先頭のコンストイテレータ
	/// @detail	要素が一つも存在しない場合は、ダミーノードを指すコンストイテレータを返却します。
	inline ConstIterator ConstBegin() const noexcept;

	/// @brief	末尾のコンストイテレータを取得する
	/// @return 末尾のコンストイテレータ
	/// @detail	いかなる場合でも、常にダミーノードを指すコンストイテレータを返却します。
	inline ConstIterator ConstEnd() const noexcept;

	/// @brief		リストの先頭要素を取得する
	/// @tparam T	格納されているデータ型
	/// @return		リストの先頭要素
	/// @details	要素が一つも格納されていない場合は、Assertが発生します。\n
	///				渡される値はコピーです。
	inline T Front() const noexcept;

	/// @brief		リストの末尾要素を取得する
	/// @tparam T	格納されているデータ型
	/// @return		リストの末尾要素
	/// @details	要素が一つも格納されていない場合は、Assertが発生します。\n
	///				渡される値はコピーです。
	inline T Back() const noexcept;

	/// @brief		ダミーノードを指すイテレータを取得する
	/// @return		ダミーノードを指すイテレータ
	/// @details	ダミーノードを指すイテレータを返却します。\n
	///				End()で返されるイテレータと同一です。\n
	///				この関数由来のもの以外で、ダミーノードを指すイテレータであることが想定される際に\n
	///				同一のイテレータか確認するために使用します。
	inline const Iterator& Dummy() noexcept;

	/// @brief		ダミーノードを指すコンストイテレータを取得する
	/// @return		ダミーノードを指すコンストイテレータ
	/// @details	ダミーノードを指すコンストイテレータを返却します。\n
	///				ConstEnd()で返されるコンストイテレータと同一です。\n
	///				この関数由来のもの以外で、ダミーノードを指すコンストイテレータであることが想定される際に\n
	///				同一のコンストイテレータか確認するために使用します。
	inline const ConstIterator& ConstDummy() const noexcept;

private:
	/// @brief			2つの要素を入れ替える
	/// @param refItA	Aイテレータ
	/// @param refItB	Bイテレータ
	/// @details		AとBそれぞれのイテレータが指す要素同士の、リスト内での格納位置を入れ替えます。\n
	///					その際、イテレータの指す要素の内容は変わりますが、位置は変わりません。
	inline void Swap(Iterator& refItA, Iterator& refItB) noexcept;

	/// @brief				クイックソート
	/// @tparam T			格納されているデータの型
	/// @param inLeftIt		並べ替える範囲の先頭イテレータ
	/// @param inRightIt	並べ替える範囲の末尾イテレータ
	/// @param inLeftidx	先頭要素の添字番号
	/// @param inRightidx	末尾要素の添字番号
	/// @param inComp		並べ替えに使用する関数
	/// @details			クイックソートアルゴリズムを用いて、要素を昇順に並べ替えます。\n
	///						イテレータがEnd()と同一だった場合、Assertが発生します。
	inline void QuickSort(const Iterator& inLeftIt, const Iterator& inRightIt, const int& inLeftIdx, const int& inRightIdx, bool (*inComp)(const T& a, const T& b));

private:
	/// @brief リストの終端を表すノード
	Node _EOL;

	/// @brief 格納されているデータ数
	unsigned int _Size;

	/// @brief		ダミーノードを指すイテレータ
	/// @details	イテレータの指す要素がダミーノードだと想定される際の比較のために使用します。\n
	///				初期状態から変更されることはありません。
	const Iterator _Dummy;
};

#include "LinkedList.inl"