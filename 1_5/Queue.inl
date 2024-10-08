#pragma once

/// @brief			キューにデータを追加する
/// @tparam T		格納されているデータ型
/// @param inData	追加するデータ
/// @return			正常終了 : TRUE, 異常終了 : FALSE
/// @details		キューの末尾にデータをプッシュします。\n
///					新規メモリの確保に失敗した際に、Assertが発生します。
template <typename T>
inline bool Queue<T>::Push(const T& inData)
{
	return _List.Insert(_List.ConstEnd(), inData);
}

/// @brief			キューのデータを取り出す
/// @tparam T		格納されているデータ型
/// @param outData	取り出すデータの格納先
/// @return			正常終了 : TRUE, 異常終了 : FALSE
/// @detail			キューの先頭からデータをポップします。\n
template <typename T>
inline bool Queue<T>::Pop(T& outData)
{
	// 要素数が0ならば、何もせずに終了
	if (_List.Size() == 0) { return false; }

	// 先頭要素のイテレータを準備
	LinkedList<T>::ConstIterator it = _List.ConstBegin();

	// 格納先変数に、先頭要素を代入
	outData = *it;

	// リストから、先頭要素を削除
	return _List.Remove(it);
}

/// @brief		格納されているデータ数を取得する
/// @tparam T	格納されているデータ型
/// @return		データ数
/// @detail		現在、スタックに格納されているデータ数を取得します。
template <typename T>
inline unsigned int Queue<T>::Size() const noexcept
{
	return _List.Size();
}