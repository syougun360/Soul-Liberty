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
	/**
	*	@brief
	*/
	namespace Waving
	{
		/**
		*	FFT �T���v����
		*/
		enum class SampleLength
		{
			/**
			*	256 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 172Hz
			*/
			SL256,
			
			/**
			*	512 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 86.1Hz
			*/
			SL512,

			/**
			*	1024 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 43.1Hz
			*/
			SL1K,

			/**
			*	2048 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 21.5Hz
			*/
			SL2K,

			/**
			*	4096 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 10.8Hz
			*/
			SL4K,

			/**
			*	8192 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 5.38Hz
			*/
			SL8K,

			/**
			*	16384 �T���v��
			*	@note 44.1kHz �̃T�E���h�ɑ΂��Ď��g������\ 2.69Hz
			*/
			SL16K,

			/**
			*	�f�t�H���g (8192 �T���v��)
			*/
			Default = SL8K
		};

		/**
		*
		*	@param sound
		*	@param sampleLength FFT �T���v����
		*/
		void FFT(const Sound& sound, SampleLength sampleLength = SampleLength::Default);

		/**
		*
		*	@param wave
		*	@param pos
		*	@param sampleLength FFT �T���v����
		*/
		void FFT(const Wave& wave, unsigned pos, SampleLength sampleLength = SampleLength::Default);

		/**
		*
		*	@param data
		*	@param length
		*	@param sampleLength FFT �T���v����
		*/
		void FFT(const float* data, unsigned length, SampleLength sampleLength = SampleLength::Default);

		/**
		*	FFT �̌��ʂ̃o�b�t�@ 1 �v�f������̎��g���̕ψ�(���g������\)��Ԃ��܂��B
		*	@param samplingRate �I���W�i���̔g�`�̃T���v�����O���[�g
		*	@param sampleLength FFT �T���v����
		*	@return FFT �̌��ʂ̃o�b�t�@ 1 �v�f������̎��g���̕ψ�
		*	@note (���g������\) = (�g�`�̃T���v�����O���[�g/FFT �T���v����)
		*/
		double FFTResolution(unsigned samplingRate, SampleLength sampleLength = SampleLength::Default);

		/**
		*	FFT �̌��ʂ��i�[�����o�b�t�@�̐擪�|�C���^��Ԃ��܂��B
		*	@return�@FFT �̌��ʂ��i�[�����o�b�t�@�̐擪�|�C���^
		*	@note	�L���ȃo�b�t�@�̃T�C�Y�� (sampleLength/2) �ł��B
		*			FFT() �֐������s���邽�тɓ��e���ω����܂��B
		*/
		const float* FFTBuffer();
	}
}
