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
		*	�w�肵���T���v�����O�����Ř^�����ł��邩��Ԃ��܂��B
		*	@param samplingRate �T���v�����O����
		*	@return
		*/
		bool
			GetCaps(
			RecorerSamplingRate samplingRate = RecorerSamplingRate::Default
			);

		/**
		*	�^���p�̃o�b�t�@�̃T�C�Y���T���v�����Őݒ肵�܂��B
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
		*	�^���p�̃o�b�t�@�̃T�C�Y��b�Őݒ肵�܂��B
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
		*	�^�����J�n���܂��B
		*	@return
		*/
		bool
			Start(
			);

		/**
		*	�^�����I�����܂��B
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
		*	�^�����Ă��鉹���̒��߂̍ő�U����Ԃ��܂��B
		*	@param timeSec
		*	@return
		*/
		double
			GetMaxAmplitude(
			double sec = 0.02
			);

		/**
		*	�^�����Ă��鉹���̒��߂̕��ϐU����Ԃ��܂��B
		*	@param timeSec
		*	@return
		*/
		double
			GetAverageAmplitude(
			double sec = 0.02
			);
	}
}
