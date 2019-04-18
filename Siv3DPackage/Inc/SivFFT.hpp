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
		*	FFT サンプル数
		*/
		enum class SampleLength
		{
			/**
			*	256 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 172Hz
			*/
			SL256,
			
			/**
			*	512 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 86.1Hz
			*/
			SL512,

			/**
			*	1024 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 43.1Hz
			*/
			SL1K,

			/**
			*	2048 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 21.5Hz
			*/
			SL2K,

			/**
			*	4096 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 10.8Hz
			*/
			SL4K,

			/**
			*	8192 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 5.38Hz
			*/
			SL8K,

			/**
			*	16384 サンプル
			*	@note 44.1kHz のサウンドに対して周波数分解能 2.69Hz
			*/
			SL16K,

			/**
			*	デフォルト (8192 サンプル)
			*/
			Default = SL8K
		};

		/**
		*
		*	@param sound
		*	@param sampleLength FFT サンプル数
		*/
		void FFT(const Sound& sound, SampleLength sampleLength = SampleLength::Default);

		/**
		*
		*	@param wave
		*	@param pos
		*	@param sampleLength FFT サンプル数
		*/
		void FFT(const Wave& wave, unsigned pos, SampleLength sampleLength = SampleLength::Default);

		/**
		*
		*	@param data
		*	@param length
		*	@param sampleLength FFT サンプル数
		*/
		void FFT(const float* data, unsigned length, SampleLength sampleLength = SampleLength::Default);

		/**
		*	FFT の結果のバッファ 1 要素あたりの周波数の変位(周波数分解能)を返します。
		*	@param samplingRate オリジナルの波形のサンプリングレート
		*	@param sampleLength FFT サンプル数
		*	@return FFT の結果のバッファ 1 要素あたりの周波数の変位
		*	@note (周波数分解能) = (波形のサンプリングレート/FFT サンプル数)
		*/
		double FFTResolution(unsigned samplingRate, SampleLength sampleLength = SampleLength::Default);

		/**
		*	FFT の結果を格納したバッファの先頭ポインタを返します。
		*	@return　FFT の結果を格納したバッファの先頭ポインタ
		*	@note	有効なバッファのサイズは (sampleLength/2) です。
		*			FFT() 関数を実行するたびに内容が変化します。
		*/
		const float* FFTBuffer();
	}
}
