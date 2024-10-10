//!	@file		chapter1.cpp
//!	@brief		マルチスレッド課題　第1章
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
#define RESULT	833197		// この計算はこの値になります

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
		/// @brief Tarai関数に必要な値をまとめたパラメータ構造体
		struct Param
		{
			int x, y, z;
		};

		// -- 各スレッドで必要になる変数
		
		/// @brief パラメータを格納するキューコンテナ
		std::queue<Param> paramQueue;
		/// @brief 計算結果を保持する変数
		int sum = 0;
		/// @brief データ競合を防ぐためのミューテックス
		std::mutex mutex;

		/// @brief パラメータを生成するスレッド
		void TH_GenParam()
		{
			Param tNewParam;

			// -- パラメータの生成数分繰り返し
			for (int i = 0; i < N; ++i)
			{
				// -- パラメータの生成
				tNewParam.x = Random(MIN, MAX);
				tNewParam.y = Random(MIN, MAX);
				tNewParam.z = Random(MIN, MAX);

				// -- パラメータを格納
				mutex.lock();
				paramQueue.push(tNewParam);
				mutex.unlock();
			}
		}
		/// @brief Tarai関数を実行するスレッド
		void TH_ExecTarai()
		{
			Param tParam;
			int tResult = 0;

			// -- 期待する結果になるまで繰り返し
			while(sum != RESULT)
			{
				// -- キューからパラメータを取得
				mutex.lock();
				if (paramQueue.empty())
				{	// パラメータが存在しないならば

					// ロック解除してcontinue
					mutex.unlock();
					continue;
				}
				else
				{	// パラメータが存在したら

					// -- パラメータを取得して、削除
					tParam = paramQueue.front();
					paramQueue.pop();
					// ロック解除
					mutex.unlock();

					// Tarai関数実行
					tResult = Tarai(tParam.x, tParam.y, tParam.z);
				}

				// -- Tarai関数の計算が終了したら、値を加算
				mutex.lock();
				sum += tResult;
				mutex.unlock();
			}
		}

		/**************************************************************************//**
			@brief		作業を行います。
			@return		作業の結果
			@todo		この関数を改造し、同じ結果をより高速に返せるようにしてください。
		*//***************************************************************************/
		int DoWork()
		{
			// Tarai関数を実行するスレッドの配列
			std::thread tExecTaraiThreads[EXEC_TARAI_THREAD_NUM];

			// -- スレッドの作成・開始
			std::thread tGenParamThread(TH_GenParam);
			for (int i = 0; i < EXEC_TARAI_THREAD_NUM; ++i)
			{
				tExecTaraiThreads[i] = std::thread(TH_ExecTarai);
			}
			
			// -- 各スレッドの終了待ち
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
	@brief		プログラム開始関数です。
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