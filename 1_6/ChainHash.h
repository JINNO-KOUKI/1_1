#pragma once

#include "LinkedList.h"

/// @brief				ハッシュチェイン法を用いたデータコンテナクラス
/// @tparam Key			要素に紐づけるキーの型
/// @tparam Value		格納したい要素の型
/// @tparam Func		ハッシュ値を求める関数(ハッシュ関数)
/// @tparam BucketSize	バケットサイズ(ハッシュ値の最大種類数)
template <typename Key, typename Value, unsigned int (*Func)(Key), unsigned int BucketSize>
class ChainHash
{
	/// @brief ハッシュ値の型
	using Hash = unsigned int;

public:
	/// @brief キーと要素をセットで格納するためのペア構造体
	struct Pair
	{
		/// @brief 要素に紐づけるキー
		Key		_Key;
		/// @brief 実際に格納する要素
		Value	_Value;

		/// @brief デフォルトコンストラクタ
		Pair() : _Key(Key()), _Value(Value()) {}

		/// @brief			引数付きコンストラクタ
		/// @param key		キー情報
		/// @param value	格納要素
		Pair(Key key, Value value) : _Key(key), _Value(value) {}

		/// @brief				等価比較演算子
		/// @param other		右辺要素
		/// @return				比較結果
		/// @detail				キーと要素それぞれが、すべて同一かどうかで判断します
		bool operator==(const Pair& other) const noexcept;
	};

public:
	/// @brief				ハッシュテーブルに、新規要素を追加する
	/// @tparam Key			キーとして利用するデータの型
	/// @tparam Value		格納する要素のデータ型
	/// @param inKey		格納する要素のキー(一意)
	/// @param inValue		格納する要素
	/// @return				正常終了 : TRUE  異常終了 : FALSE
	/// @details			キーを元に、新規要素を追加します。\n
	///						登録するキーは、このハッシュテーブルの中で一意なものである必要があります。\n
	///						重複するキーが既に格納されている場合、FALSEで終了します。
	bool Add(const Key& inKey, const Value& inValue);

	/// @brief				ハッシュテーブルから、要素を削除する
	/// @tparam Key			キーとして利用するデータの型
	/// @param inKey		削除する要素に割り当てられているキー
	/// @return				正常終了 : TRUE  異常終了 : FALSE
	/// @details			指定されたキーに該当する要素を、このテーブルから削除します。\n
	///						キーに該当する要素が格納されていない場合、FALSEで終了します。
	bool Remove(const Key& inKey);

	/// @brief				ハッシュテーブルから、要素を検索する
	/// @tparam Key			キーとして利用するデータの型
	/// @tparam Value		格納する要素のデータ型
	/// @param inKey		検索に使用するキー
	/// @param outValue		検索結果要素を格納する変数
	/// @return				要素が見つかる : TRUE  要素が見つからない or 異常終了 : FALSE
	/// @details			指定されたキーが割り当てられている要素を、このテーブルから検索します。\n
	///						見つからなかった場合、FALSEで終了します。
	bool Find(const Key& inKey, Value& outValue) const;

	/// @brief				ハッシュ値から、該当チェインを取得する
	/// @param inHash		取得したいチェインのハッシュ値
	/// @param outList		取得したチェインを格納するリスト変数
	/// @return				正常終了 : TRUE  異常終了 : FALSE
	/// @details			与えられたハッシュ値と、一致するキーが格納されているチェインリストを取得します。\n
	///						該当のチェインが存在しない又は一つも要素が格納されていない場合、FALSEで終了します。\n
	///						格納先リスト変数に既にデータが格納されている又はリストのコピーが失敗した場合にも、FALSEで終了します。
	bool GetChainByHash(const unsigned int& inHash, LinkedList<Pair>& outList) const;

	/// @brief				格納されている全ての要素を取得する
	/// @param outList		取得した要素を格納するリスト変数
	/// @return				正常終了 : TRUE  異常終了 : FALSE
	/// @details			このハッシュテーブルに格納されているすべての要素を取得します。\n
	///						格納先リスト変数に既に要素が格納されている場合、FALSEで終了します。\n
	///						リストのコピーに失敗した場合、Assertが発生します。
	bool GetAllData(LinkedList<Pair>& outList) const;

	/// @brief				格納されている要素数を取得する
	/// @return				格納されている要素数
	/// @details			このハッシュテーブルに格納されている要素数を取得します。
	unsigned int Size() const noexcept;

	/// @brief				使用中のチェインの数を取得する
	/// @return				使用中のチェインの数
	/// @details			一つでも要素が格納されているチェインの数を取得します。\n
	///						チェインの数はハッシュ値の数に等しいため、正常にハッシュ別で振り分けられているかを確認できます。\n
	unsigned int ChainSize() const noexcept;

private:
	/// @brief 各ハッシュ値別に要素を管理するためのチェイン(双方向リスト)
	LinkedList<Pair> _List[BucketSize];
};

#include "ChainHash.inl"