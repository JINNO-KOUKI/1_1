#pragma once

/// @brief			スタックにデータを追加する
/// @tparam T		格納されているデータ型
/// @param inData	追加するデータ
/// @return			正常終了 : TRUE, 異常終了 : FALSE
/// @details		スタックの末尾にデータをプッシュします。\n
///					新規メモリの確保に失敗した際に、Assertが発生します。\n
///					※ 内部のデータ的には、リストの先頭に挿入しています。\n
///					   取り出す際も先頭から取り出しているため、差支えありません。
template <typename T>
inline bool Stack<T>::Push(const T& inData)
{
	return _List.Insert(_List.ConstBegin(), inData);
}

/// @brief			スタックのデータを取り出す
/// @tparam T		格納されているデータ型
/// @param outData	取り出すデータの格納先
/// @return			正常終了 : TRUE, 異常終了 : FALSE
/// @details		スタックの末尾からデータをポップします。\n
///					※ 内部のデータ的には、リストの先頭から取り出しています。\n
///					   データの挿入時も先頭に挿入しているので、差支えありません。
template <typename T>
inline bool Stack<T>::Pop(T& outData)
{
	// 要素数が0ならば、何もせずに終了
	if (_List.Size() == 0) { return false; }

	// 先頭要素のイテレータを準備
	LinkedList<T>::ConstIterator it = _List.ConstBegin();

	// 格納先変数に、末尾要素を代入
	outData = *it;

	// リストから、先頭要素を削除
	return _List.Remove(it);
}

/// @brief		格納されているデータ数を取得する
/// @tparam T	格納されているデータ型
/// @return		データ数
/// @detail		現在、スタックに格納されているデータ数を取得します。
template <typename T>
inline unsigned int Stack<T>::Size() const noexcept
{
	return _List.Size();
}
