#include "ChainHash.h"

#include <iostream>
#include <string>

/// @brief		テスト実行に利用するハッシュ関数
unsigned int Hash(int key)
{
	return key % 10;
}

int main()
{
	// メモリリークチェック
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// 変数宣言
	ChainHash<int, std::string, Hash, 5> chainHash;

	// -- テスト用データの挿入
	chainHash.Add(0, "A");
	chainHash.Add(1, "B");
	chainHash.Add(2, "C");
	chainHash.Add(3, "D");
	chainHash.Add(4, "E");
	chainHash.Add(5, "AA");
	chainHash.Add(6, "BB");
	chainHash.Add(7, "CC");
	chainHash.Add(8, "DD");
	chainHash.Add(9, "EE");
	chainHash.Add(10, "AAA");

	// -- 格納要素の取得
	LinkedList<ChainHash<int, std::string, Hash, 5>::Pair> list;
	chainHash.GetAllData(list);

	// -- 要素の表示
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << (*it)._Key << " : " << (*it)._Value << std::endl;
	}

	// チェインサイズの表示
	std::cout << "ChainSize : " << chainHash.ChainSize() << std::endl;

	return 0;
}