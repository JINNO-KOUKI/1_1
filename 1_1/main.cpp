#include <crtdbg.h>
#include <iostream>
#include <fstream>

#include "MyList.h"
#include "UserData.h"

using namespace std;

namespace
{
	/// @brief �J���t�@�C���p�X
	const string kFileName = "Scores.txt";
}

int main()
{
	// ���������[�N�`�F�b�N
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// -- �t�@�C�����J��
	ifstream ifs(kFileName);
	if (!ifs)
	{
		cerr << "Error: �t�@�C�����J���܂���ł����B" << endl;
	}

	MyList<UserData> tScoreList;	// �i�[�惊�X�g�̒�`

	// -- �t�@�C���̏I�[�܂œǂݍ���
	while (true)
	{
		UserData tUserData;

		// �f�[�^�̓ǂݎ��
		ifs >> tUserData._Score >> tUserData._Name;

		// �I�[���m�ŏI��
		if (ifs.eof()) { break; }

		// ���X�g�Ɋi�[
		tScoreList.push_back(tUserData);
	}

	// -- ���X�g���v�f�̕`��
	for (auto itr = tScoreList.Begin(); itr != tScoreList.End(); ++itr)
	{
		cout << itr->_Score << " " << itr->_Name << endl;
	}

	// ���͑҂�
	cin.get();

	return 0;
}