#include <iostream>
#include <fstream>
using namespace std;

#include "LinkedList.h"

namespace
{
	/// @brief 開くファイルパス
	const string kFileName = "Scores.txt";

	struct StudentData
	{
		int _Score = 0;
		string _Name = "";
	};
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

	LinkedList<StudentData> tResultList;	// 格納先リストの定義

	auto test = (&StudentData::_Name);

	// -- ファイルの終端まで読み込み
	while (true)
	{
		StudentData tResultData;

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