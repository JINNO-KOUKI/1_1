#include <iostream>
#include <fstream>
using namespace std;

#include "MyList.h"

namespace
{
	/// @brief �J���t�@�C���p�X
	const string kFileName = "Scores.txt";
}

int main()
{
	// ���������[�N�`�F�b�N
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MyList list;
	// -- �t�@�C�����J��
	ifstream ifs(kFileName);
	if (!ifs)
	{
		cerr << "Error: �t�@�C�����J���܂���ł����B" << endl;
	}

	MyList tResultList;	// �i�[�惊�X�g�̒�`

	// -- �t�@�C���̏I�[�܂œǂݍ���
	while (true)
	{
		ResultData tResultData;

		// �f�[�^�̓ǂݎ��
		ifs >> tResultData._Score >> tResultData._Name;

		// �I�[���m�ŏI��
		if (ifs.eof()) { break; }

		// ���X�g�Ɋi�[
		tResultList.Insert(tResultList.End(), tResultData);
	}

	// �t�@�C�������
	ifs.close();

	// -- ���X�g���v�f�̕`��
	for (auto itr = tResultList.Begin(); itr != tResultList.End(); ++itr)
	{
		cout << (*itr)._Score << " " << (*itr)._Name << endl;
	}

	cin.get();

	return 0;
}