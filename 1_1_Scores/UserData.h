#pragma once

#include <string>

/// @brief ���[�U�[�����܂Ƃ߂ĊǗ�����\����
struct UserData
{
	/// @brief �X�R�A
	int _Score;
	/// @brief ���[�U�[��
	std::string _Name;

	/// @brief �R���X�g���N�^
	UserData() : _Score(0), _Name("null") {}
};