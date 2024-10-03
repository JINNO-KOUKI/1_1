#pragma once

/// @brief 自作の双方向リストクラス
/// @tparam T 格納するクラス
template <class T>
class MyList
{
	/// @brief リスト内の一要素を表す構造体
	struct ElemData
	{
		/// @brief 格納要素
		T _Elem;
		/// @brief 一つ前の要素へのポインタ
		ElemData* _Prev;
		/// @brief 一つ後の要素へのポインタ
		ElemData* _Next;

		/// @brief デフォルトコンストラクタ
		ElemData() : _Elem(T()), _Prev(nullptr), _Next(nullptr) {}

		/// @brief 引数付きコンストラクタ(前後要素へのポインタはnullptr)
		/// @param inNewElem 格納する要素
		ElemData(T inNewElem) : _Elem(inNewElem), _Prev(nullptr), _Next(nullptr) {}

		/// @brief 引数付きコンストラクタ
		/// @param inNewElem 格納する要素
		/// @param inPrev 前の要素へのポインタ
		/// @param inNext 後の要素へのポインタ
		ElemData(T inNewElem, ElemData* inPrev, ElemData* inNext)
			: _Elem(inNewElem), _Prev(inPrev), _Next(inNext) {}
	};

public:
	/// @brief デフォルトコンストラクタ
	MyList() : _Front(nullptr), _Back(nullptr), _Size(0) {}
	/// @brief デフォルトデストラクタ
	~MyList() { Clear(); }

	/// @brief 最後尾に新規要素を追加する
	/// @param inNewElem 追加要素
	inline void push_back(T inNewElem)
	{
		// 新規要素の作成
		ElemData* tElemData = new ElemData(inNewElem);

		if (!_Size)
		{	// 一つも要素が格納されていない

			// --新規要素を先頭要素・最後尾要素に登録
			_Front = tElemData;
			_Back = tElemData;
		}
		else
		{
			// 新規要素を現在の最後尾要素の一つ後には位置
			_Back->_Next = tElemData;
			// 新規要素の前に現在の最後尾要素を登録
			tElemData->_Prev = _Back;
			// 最後尾要素を新規要素に更新
			_Back = tElemData;
		}

		// サイズの更新
		++_Size;
	}

	/// @brief 先頭に新規要素を追加する
	/// @param inNewElem 追加要素
	inline void push_front(T inNewElem)
	{
		// 新規要素の作成
		ElemData* tElemData = new ElemData(inNewElem);

		if (!_Size)
		{	// 一つも要素が格納されていない

			// -- 新規要素を先頭要素・最後尾要素に登録
			_Front = tElemData;
			_Back = tElemData;
		}
		else
		{
			// 新規要素を現在の先頭要素の一つ前に配置
			_Front->_Prev = tElemData;
			// 新規要素の次に現在の先頭要素を登録
			tElemData->_Next = _Front;
			// 先頭要素を新規要素に更新
			_Front = tElemData;
		}

		// サイズの更新
		++_Size;
	}

	/// @brief 最後尾要素をリストから削除する
	inline void pop_back()
	{
		// 要素が一つもなかったら処理しない
		if (!_Size) { return; }

		// 現在の最後尾要素を取得
		ElemData* tElemData = _Back;

		// 最後の一つ手前の要素を最後尾要素に登録
		_Back = _Back->_Prev;
		// 新規最後尾要素のNextをnullptrに更新
		_Back->_Next = nullptr;

		// 元の最後尾要素を解放
		delete tElemData;

		// サイズの更新
		--_Size;
	}

	/// @brief 先頭要素をリストから削除する
	inline void pop_front()
	{
		// 要素が一つもなかったら処理しない
		if (!_Size) { return; }

		// 現在の先頭要素を取得
		ElemData* tElemData = _Front;

		// 最初の一つ後の要素を先頭要素に登録
		_Front = _Front->_Next;
		// 新規先頭要素のPrevをnullptrに更新
		_Front->_Prev = nullptr;

		// 元の先頭要素を解放
		delete tElemData;

		// サイズの更新
		--_Size;
	}

	/// @brief リスト内のすべての要素を削除する
	inline void Clear()
	{
		// 要素数0だったら終了
		if (!_Size) { return; }

		// 最後尾の要素を取得
		ElemData* tElemData = _Back;

		// -- 前の要素が見つからなくなるまで繰り返し
		while (tElemData = tElemData->_Prev)
		{
			// 次の要素を削除
			delete tElemData->_Next;
		}
		// 先頭要素を削除
		delete _Front;

		// -- メンバ変数の初期化
		_Front = nullptr;
		_Back = nullptr;
		_Size = 0;
	}

	/// @brief リストの先頭要素を取得する
	/// @return 先頭要素
	inline T Front() const { return _Front->_Elem; }
	/// @brief リストの最後尾要素を取得する
	/// @return 最後尾要素
	inline T Back() const { return _Back->_Elem; }
	/// @brief リストに格納されている要素数を取得する
	/// @return 要素数
	inline constexpr unsigned int Size() const { return _Size; }

	/// @brief MyListクラスのイテレータ
	class Iterator
	{
	public:
		/// @brief デフォルトコンストラクタ
		Iterator() : _Elem(nullptr) {}
		/// @brief 引数付きコンストラクタ
		/// @param inElem 起点となるリスト要素
		Iterator(ElemData* inElem) : _Elem(inElem) {}

	public:	// 演算子オーバーロード群
		T& operator*() const noexcept
		{
			return _Elem->_Elem;
		}
		T* operator->()
		{
			return &(_Elem->_Elem);
		}
		Iterator operator++(int)
		{
			_Elem = _Elem->_Next;
			return this;
		}
		Iterator operator--(int)
		{
			_Elem = _Elem->_Prev;
			return this;
		}
		Iterator& operator++()
		{
			_Elem = _Elem->_Next;			
			return *this;
		}
		Iterator& operator--()
		{
			_Elem = _Elem->_Prev;
			return *this;
		}
		friend bool operator==(const Iterator& e1, const Iterator& e2)
		{ 
			return e1._Elem == e2._Elem;
		}
		friend bool operator!=(const Iterator& e1, const Iterator& e2)
		{
			return e1._Elem != e2._Elem;
		}

	private:
		/// @brief 現在指し示しているリスト要素
		ElemData* _Elem;
	};

	/// @brief リストの先頭要素のイテレータを取得する
	/// @return 先頭要素のイテレータ
	inline constexpr MyList::Iterator Begin() const { return Iterator(_Front); }
	/// @brief リストの最後尾要素のイテレータを取得する
	/// @return 最後尾要素のイテレータ
	inline constexpr MyList::Iterator End() const { return Iterator(nullptr); }

private:
	/// @brief 先頭要素
	ElemData* _Front	= nullptr;
	/// @brief 最後尾要素
	ElemData* _Back		= nullptr;
	/// @brief 要素数
	unsigned int _Size	= 0;
};