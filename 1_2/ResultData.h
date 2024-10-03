#pragma once

#include <string>

/// @brief ���уf�[�^
struct ResultData
{
	/// @brief �X�R�A
	int _Score;
	/// @brief ���[�U�[��
	std::string _Name;

	/// @brief �R���X�g���N�^
	ResultData() : _Score(0), _Name("") {}

	/// @brief �����t���R���X�g���N�^
	/// @param inScore �ݒ肷��X�R�A
	/// @param inName �ݒ肷�郆�[�U�[��
	ResultData(const int& inScore, const std::string& inName)
		: _Score(inScore), _Name(inName) {}

	/// @brief			������r���Z�q�I�[�o�[���[�h
	/// @detail			�\���̓��̊e�v�f�ɑ΂��ē�����r���s���A���ׂĈ�v���邩�ǂ����Ŕ��f���܂��B
	/// @param other	�E�ӗv�f
	/// @return			��r����
	bool operator==(const ResultData& other) const noexcept
	{
		//if (other == nullptr) { return false; }
		return (_Score == other._Score) && (_Name == other._Name);
	}
};