#include <crtdbg.h>
#include <iostream>
#include <fstream>

#include "MyList.h"
#include "UserData.h"

using namespace std;

namespace
{
	/// @brief 開くファイルパス
	const string kFileName = "Scores.txt";
}

int main()
{
	// メモリリークチェック
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// -- ファイルを開く
	ifstream ifs(kFileName);
	if (!ifs)
	{
		cerr << "Error: ファイルを開けませんでした。" << endl;
	}

	MyList<UserData> tScoreList;	// 格納先リストの定義

	// -- ファイルの終端まで読み込み
	while (true)
	{
		UserData tUserData;

		// データの読み取り
		ifs >> tUserData._Score >> tUserData._Name;

		// 終端検知で終了
		if (ifs.eof()) { break; }

		// リストに格納
		tScoreList.push_back(tUserData);
	}

	// -- リスト内要素の描画
	for (auto itr = tScoreList.Begin(); itr != tScoreList.End(); ++itr)
	{
		cout << itr->_Score << " " << itr->_Name << endl;
	}

	// 入力待ち
	cin.get();

	return 0;
}