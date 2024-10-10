#include "ChainHash.h"

#include <iostream>
#include <string>

/// @brief		�e�X�g���s�ɗ��p����n�b�V���֐�
unsigned int Hash(int key)
{
	return key % 10;
}

int main()
{
	// ���������[�N�`�F�b�N
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �ϐ��錾
	ChainHash<int, std::string, Hash, 5> chainHash;

	// -- �e�X�g�p�f�[�^�̑}��
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

	// -- �i�[�v�f�̎擾
	LinkedList<ChainHash<int, std::string, Hash, 5>::Pair> list;
	chainHash.GetAllData(list);

	// -- �v�f�̕\��
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << (*it)._Key << " : " << (*it)._Value << std::endl;
	}

	// �`�F�C���T�C�Y�̕\��
	std::cout << "ChainSize : " << chainHash.ChainSize() << std::endl;

	return 0;
}