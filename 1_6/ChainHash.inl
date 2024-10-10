#pragma once


/// @brief				等価比較演算子
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @param other		右辺要素
/// @return				比較結果
/// @detail				キーと要素それぞれが、すべて同一かどうかで判断します
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Pair::operator==(const Pair& other) const noexcept
{
	return (_Key == other._Key) && (_Value == other._Value);
}

/// @brief				ハッシュテーブルに、新規要素を追加する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @param inKey		格納する要素のキー(一意)
/// @param inValue		格納する要素
/// @return				正常終了 : TRUE  異常終了 : FALSE
/// @details			キーを元に、新規要素を追加します。\n
///						登録するキーは、このハッシュテーブルの中で一意なものである必要があります。\n
///						重複するキーが既に格納されている場合、FALSEで終了します。\n
///						ハッシュ値がバケットサイズを超過する場合もFALSEで終了します。
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Add(const Key& inKey, const Value& inValue)
{
	// 同一キーが格納されていないかチェック
	Value tValue;
	if (Find(inKey, tValue))
	{	// 格納されていたら

		// 即時終了
		return false;
	}
	else
	{	// 格納されていなかったら

		// ハッシュ値を求める
		Hash tHash = Func(inKey);
		// 対象チェインの先頭に追加
		_List[tHash].Insert(_List[tHash].Begin(), Pair(inKey, inValue));
	}
	
	// 正常終了
	return true;
}

/// @brief				ハッシュテーブルから、要素を削除する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @param inKey		削除する要素に割り当てられているキー
/// @return				正常終了 : TRUE  異常終了 : FALSE
/// @details			指定されたキーに該当する要素を、このテーブルから削除します。\n
///						キーに該当する要素が格納されていない場合、FALSEで終了します。\n
///						ハッシュ値がバケットサイズを超過する場合もFALSEで終了します。
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Remove(const Key& inKey)
{
	// -- 対象キーの要素が格納されているか確認
	Value tValue;
	if (Find(inKey, tValue))
	{	// 格納されていたら

		// ハッシュ値を求める
		Hash tHash = Func(inKey);
		
		// -- 該当要素までイテレータをシークして削除
		for (auto it = _List[tHash].Begin(); it != _List[tHash].End(); ++it)
		{
			// 削除対象が見つかったら
			if ((*it)._Key == inKey)
			{
				// 該当要素をチェインから削除して終了
				_List[tHash].Remove(it);
				return true;
			}
		}
	}
	else
	{	// 格納されていなかったら

		// 即時終了
		return false;
	}

	// 正常であればここには来ない
	// Find()によって要素が見つかっているのに、削除できなかった
	return false;
}

/// @brief				ハッシュテーブルから、要素を検索する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @param inKey		検索に使用するキー
/// @param outValue		検索結果要素を格納する変数
/// @return				要素が見つかる : TRUE  要素が見つからない or 異常終了 : FALSE
/// @details			指定されたキーが割り当てられている要素を、このテーブルから検索します。\n
///						見つからなかった場合、FALSEで終了します。\n
///						ハッシュ値がバケットサイズを超過する場合もFALSEで終了します。
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::Find(const Key& inKey, Value& outValue) const
{
	// ハッシュ値を計算
	Hash tHash = Func(inKey);

	// ハッシュ値がバケットサイズを超えていたら、即時終了
	if (tHash >= BucketSize) { return false; }

	// -- 対象のチェイン内を線形探索
	for (auto it = _List[tHash].ConstBegin(); it != _List[tHash].ConstEnd(); ++it)
	{
		// -- 探索キーと同一のキーが見つかったら
		if ((*it)._Key == inKey)
		{
			// -- 出力用変数に要素を代入して終了
			outValue = (*it)._Value;
			return true;
		}
	}

	// 見つからなかったので、falseで終了
	return false;
}

/// @brief				ハッシュ値から、該当チェインを取得する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @param inHash		取得したいチェインのハッシュ値
/// @param outList		取得したチェインを格納するリスト変数
/// @return				正常終了 : TRUE  異常終了 : FALSE
/// @details			与えられたハッシュ値と、一致するキーが格納されているチェインリストを取得します。\n
///						該当のチェインが存在しない又は一つも要素が格納されていない場合、FALSEで終了します。\n
///						格納先リスト変数に既にデータが格納されている又はリストのコピーが失敗した場合にも、FALSEで終了します。
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::GetChainByHash(const unsigned int& inHash, LinkedList<Pair>& outList)
{
	// 指定されたハッシュ値がバケットサイズを超えていたら、即時終了
	if (inHash >= BucketSize) { return false; }
	// 該当チェインに要素が存在しない場合も、即時終了
	if (_List[inHash].Size() == 0) { return false; }

	// リストをコピー
	if (!_List[inHash].Copy(outList))
	{	// コピーに失敗したら
		
		// 即時終了
		return false;
	}

	// 正常終了
	return true;
}

/// @brief				格納されている全ての要素を取得する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @param outList		取得した要素を格納するリスト変数
/// @return				正常終了 : TRUE  異常終了 : FALSE
/// @details			このハッシュテーブルに格納されているすべての要素を取得します。\n
///						格納先リスト変数に既に要素が格納されている場合、FALSEで終了します。\n
///						リストのコピーに失敗した場合、Assertが発生します。
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline bool ChainHash<Key, Value, Func, BucketSize>::GetAllData(LinkedList<Pair>& outList)
{
	// 格納先リストにすでにデータが存在したら、何もせずに終了
	if (outList.Size() > 0) { return false; }

	for (unsigned int i = 0; i < BucketSize; ++i)
	{
		// 各チェインリストを結合していく
		if (!outList.Append(_List[i]))
		{	// 結合に失敗したら

			// AppendがAssert以外で異常終了することは無いので、
			// もしここに来たら致命的なエラーの可能性があるためAssertを発生させる
			assert(false);
		}
	}

	// 正常終了
	return true;
}

/// @brief				格納されている要素数を取得する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @return				格納されている要素数
/// @details			このハッシュテーブルに格納されている要素数を取得します。
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline unsigned int ChainHash<Key, Value, Func, BucketSize>::Size() const noexcept
{
	unsigned int tSize = 0;

	// -- すべてのチェインを走査
	for (int i = 0; i < BucketSize; ++i)
	{
		// 各チェインのサイズを加算
		tSize += _List[i].Size();
	}

	// 各チェインのサイズの合計値を返す
	return tSize;
}

/// @brief				使用中のチェインの数を取得する
/// @tparam Key			キーとして利用するデータの型
/// @tparam Value		格納する要素のデータ型
/// @tparam Func		ハッシュ関数
/// @tparam BucketSize	バケットサイズ
/// @return				使用中のチェインの数
/// @details			一つでも要素が格納されているチェインの数を取得します。\n
///						チェインの数はハッシュ値の数に等しいため、正常にハッシュ別で振り分けられているかを確認できます。\n
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
inline unsigned int ChainHash<Key, Value, Func, BucketSize>::ChainSize() const noexcept
{
	unsigned int tSize = 0;

	// -- すべてのチェインを走査
	for (int i = 0; i < BucketSize; ++i)
	{
		// 一つでもチェインに要素があればインクリメント
		if (_List[i].Size()) { ++tSize; }
	}

	// 要素が含まれているチェインの数を返す
	return tSize;
}