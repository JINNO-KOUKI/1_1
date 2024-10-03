#include <iostream>
#include <fstream>
using namespace std;

#include "LinkedList.h"

namespace
{
	/// @brief 開くファイルパス
	const string kFileName = "Scores.txt";
}

int main()
{
	// メモリリークチェック
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LinkedList list;
	// -- ファイルを開く
	ifstream ifs(kFileName);
	if (!ifs)
	{
		cerr << "Error: ファイルを開けませんでした。" << endl;
	}

	LinkedList tResultList;	// 格納先リストの定義

	// -- ファイルの終端まで読み込み
	while (true)
	{
		ResultData tResultData;

		// データの読み取り
		ifs >> tResultData._Score >> tResultData._Name;

		// 終端検知で終了
		if (ifs.eof()) { break; }

		// リストに格納
		tResultList.Insert(tResultList.End(), tResultData);
	}

	// ファイルを閉じる
	ifs.close();

	// -- リスト内要素の描画
	for (auto itr = tResultList.Begin(); itr != tResultList.End(); ++itr)
	{
		cout << (*itr)._Score << " " << (*itr)._Name << endl;
	}

	cin.get();

	return 0;
}