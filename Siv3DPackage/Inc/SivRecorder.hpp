//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# pragma once
# include "SivForward.hpp"

namespace s3d
{
	enum class RecorerSamplingRate
	{
		S11025 = 0x008,
		S22050 = 0x080,
		S44100 = 0x800,
		Default = S44100,
	};

	namespace Recorder
	{
		/**
		*	指定したサンプリング方式で録音ができるかを返します。
		*	@param samplingRate サンプリング方式
		*	@return
		*/
		bool
			GetCaps(
			RecorerSamplingRate samplingRate = RecorerSamplingRate::Default
			);

		/**
		*	録音用のバッファのサイズをサンプル数で設定します。
		*	@param samplingRate
		*	@param sample
		*	@return
		*/
		bool
			SetBufferLengthBySample(
			RecorerSamplingRate samplingRate,
			unsigned sample
			);

		/**
		*	録音用のバッファのサイズを秒で設定します。
		*	@param samplingRate
		*	@param timeSec
		*	@return
		*/
		bool
			SetBufferLengthBySec(
			RecorerSamplingRate samplingRate,
			double timeSec
			);

		/**
		*	録音を開始します。
		*	@return
		*/
		bool
			Start(
			);

		/**
		*	録音を終了します。
		*/
		void
			Stop(
			);

		/**
		*
		*	@return
		*/
		unsigned
			GetPos(
			);

		/**
		*
		*	@return
		*/
		const s3d::Wave&
			GetWave(
			);

		/**
		*
		*/
		bool
			IsEnd(
			);

		/**
		*
		*/
		bool
			Restart(
			);

		/**
		*	録音している音声の直近の最大振幅を返します。
		*	@param timeSec
		*	@return
		*/
		double
			GetMaxAmplitude(
			double sec = 0.02
			);

		/**
		*	録音している音声の直近の平均振幅を返します。
		*	@param timeSec
		*	@return
		*/
		double
			GetAverageAmplitude(
			double sec = 0.02
			);
	}
}
