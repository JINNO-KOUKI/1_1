//!	@file		chapter1.cpp
//!	@brief		�}���`�X���b�h�ۑ�@��1��
//! @note		Copyright (c) FromSoftware, Inc.

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <functions.h>
#include <crtdbg.h>
#include <thread>
#include <queue>
#include <mutex>
#include <iostream>

//-----------------------------------------------------------------------------
// Macro Definitions
//-----------------------------------------------------------------------------

#define N		100000
#define	MIN		1
#define	MAX		13
#define RESULT	833197		// ���̌v�Z�͂��̒l�ɂȂ�܂�

#define EXEC_TARAI_THREAD_NUM 10

//-----------------------------------------------------------------------------
// Using Namespace
//-----------------------------------------------------------------------------
using namespace ex02_MultiThread::common;

//-----------------------------------------------------------------------------
// Implements
//-----------------------------------------------------------------------------
namespace ex02_MultiThread
{
	namespace chapter2
	{
		/// @brief Tarai�֐��ɕK�v�Ȓl���܂Ƃ߂��p�����[�^�\����
		struct Param
		{
			int x, y, z;
		};

		// -- �e�X���b�h�ŕK�v�ɂȂ�ϐ�
		
		/// @brief �p�����[�^���i�[����L���[�R���e�i
		std::queue<Param> paramQueue;
		/// @brief �v�Z���ʂ�ێ�����ϐ�
		int sum = 0;
		/// @brief �f�[�^������h�����߂̃~���[�e�b�N�X
		std::mutex mutex;

		/// @brief �p�����[�^�𐶐�����X���b�h
		void TH_GenParam()
		{
			Param tNewParam;

			// -- �p�����[�^�̐��������J��Ԃ�
			for (int i = 0; i < N; ++i)
			{
				// -- �p�����[�^�̐���
				tNewParam.x = Random(MIN, MAX);
				tNewParam.y = Random(MIN, MAX);
				tNewParam.z = Random(MIN, MAX);

				// -- �p�����[�^���i�[
				mutex.lock();
				paramQueue.push(tNewParam);
				mutex.unlock();
			}
		}
		/// @brief Tarai�֐������s����X���b�h
		void TH_ExecTarai()
		{
			Param tParam;
			int tResult = 0;

			// -- ���҂��錋�ʂɂȂ�܂ŌJ��Ԃ�
			while(sum != RESULT)
			{
				// -- �L���[����p�����[�^���擾
				mutex.lock();
				if (paramQueue.empty())
				{	// �p�����[�^�����݂��Ȃ��Ȃ��

					// ���b�N��������continue
					mutex.unlock();
					continue;
				}
				else
				{	// �p�����[�^�����݂�����

					// -- �p�����[�^���擾���āA�폜
					tParam = paramQueue.front();
					paramQueue.pop();
					// ���b�N����
					mutex.unlock();

					// Tarai�֐����s
					tResult = Tarai(tParam.x, tParam.y, tParam.z);
				}

				// -- Tarai�֐��̌v�Z���I��������A�l�����Z
				mutex.lock();
				sum += tResult;
				mutex.unlock();
			}
		}

		/**************************************************************************//**
			@brief		��Ƃ��s���܂��B
			@return		��Ƃ̌���
			@todo		���̊֐����������A�������ʂ���荂���ɕԂ���悤�ɂ��Ă��������B
		*//***************************************************************************/
		int DoWork()
		{
			// Tarai�֐������s����X���b�h�̔z��
			std::thread tExecTaraiThreads[EXEC_TARAI_THREAD_NUM];

			// -- �X���b�h�̍쐬�E�J�n
			std::thread tGenParamThread(TH_GenParam);
			for (int i = 0; i < EXEC_TARAI_THREAD_NUM; ++i)
			{
				tExecTaraiThreads[i] = std::thread(TH_ExecTarai);
			}
			
			// -- �e�X���b�h�̏I���҂�
			tGenParamThread.join();
			for (int i = 0; i < EXEC_TARAI_THREAD_NUM; ++i)
			{
				tExecTaraiThreads[i].join();
			}

			return sum;
		}
	}
}
/**************************************************************************//**
	@brief		�v���O�����J�n�֐��ł��B
*//***************************************************************************/
void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	unsigned __int64 startTime = GetCPUCounter();
	int result = ex02_MultiThread::chapter2::DoWork();
	unsigned __int64 endTime = GetCPUCounter();

	printf( "time : %f\n", (double)(endTime - startTime) / (double)GetCPUFrequency() );
	printf( "result : %d\n", result );
}