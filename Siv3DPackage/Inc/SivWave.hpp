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
# include <vector>
# include "SivForward.hpp"
# include "SivPropertyMacro.hpp"
# include "SivOptional.hpp"
# include "SivWaveSample.hpp"
# include "SivMath.hpp"
# include "SivMathConstants.hpp"

namespace s3d
{
	/**
	*	@brief オーディオファイルのフォーマット
	*/
	enum class AudioFormat
	{
		/**
		*
		*/
		Unknown,

		/**
		*
		*/
		WAV,

		/**
		*
		*/
		OggVorbis,

		/**
		*
		*/
		MP3,

		/**
		*
		*/
		AAC,

		/**
		*
		*/
		WMA,

		/**
		*
		*/
		Unspecified = Unknown,
	};

	/**
	*	@brief オーディオの情報
	*/
	struct AudioProperty
	{
		/**
		*
		*/
		AudioFormat format;

		/**
		*
		*/
		unsigned durationSec;

		/**
		*
		*/
		unsigned encodingBitrateBPS;

		/**
		*
		*/
		String title;
	};

	/**
	*	@brief AAC オーディオの圧縮品質
	*/
	enum class AACQuality
	{
		/**
		*
		*/
		Low,

		/**
		*
		*/
		Medium,

		/**
		*
		*/
		High,

		/**
		*
		*/
		Default = Medium,
	};

	/**
	*	brief 波形
	*/
	class Wave
	{
	private:

		std::vector<WaveSample> m_data;

		unsigned m_samplingRate = DefaultSamplingRate;

	public:

		enum
		{
			/**
			*
			*/
			MinSamlingRate = 4000,

			/**
			*
			*/
			DefaultSamplingRate = 44100,

			/**
			*
			*/
			MaxSamplingRate = 192000,
		};

		/**
		*
		*/
		Wave();

		/**
		*
		*/
		~Wave();

		/**
		*
		*	@param sample
		*/
		explicit Wave(unsigned sample);

		/**
		*
		*	@param sample
		*	@param rate
		*/
		Wave(unsigned sample, unsigned rate);

		/**
		*
		*	@param sample
		*	@param rate
		*	@param hz
		*/
		Wave(unsigned sample, unsigned rate, double hz);

		/**
		*
		*	@param path
		*/
		explicit Wave(const FilePath& path);

		/**
		*
		*	@param wave
		*/
		Wave(const Wave& wave);

		/**
		*
		*	@param wave
		*/
		Wave(Wave && wave);

		/**
		*
		*	@param wave
		*	@return
		*/
		Wave& operator =(const Wave& wave);

		/**
		*
		*	@param wave
		*	@return
		*/
		Wave& operator =(Wave && wave);

		/**
		*
		*/
		void clear();

		/**
		*
		*/
		void fillZero();

		/**
		*
		*	@param samplingRate
		*	@return
		*/
		unsigned setSamplingRate(unsigned samplingRate);

		/**
		*
		*	@return
		*/
		explicit operator bool() const;

		/**
		*
		*	@param sample
		*/
		void resize(unsigned sample);

		/**
		*
		*	@param pos
		*	@return
		*/
		WaveSample& at(unsigned pos);

		/**
		*
		*	@param pos
		*	@return
		*/
		const WaveSample& at(unsigned pos) const;

		/**
		*
		*	@param pos
		*	@return
		*/
		WaveSample& operator [](unsigned pos)
		{
			return m_data[pos];
		}

		/**
		*
		*	@param pos
		*	@return
		*/
		const WaveSample& operator [](unsigned pos) const
		{
			return m_data[pos];
		}

		/**
		*
		*	@return
		*/
		void* data();

		/**
		*
		*	@return
		*/
		const void* data() const;

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::iterator begin();

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::const_iterator begin() const;

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::iterator end();

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::const_iterator end() const;

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::reverse_iterator rbegin();

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::const_reverse_iterator rbegin() const;

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::reverse_iterator rend();

		/**
		*
		*	@return
		*/
		std::vector<WaveSample>::const_reverse_iterator rend() const;

		/**
		*
		*	@param wav
		*/
		void swap(Wave& wav);

		/**
		*
		*	@return
		*/
		Wave clone() const;

		/*
		*
		*/
		Property_Get(double, lengthSec) const;

		/*
		*
		*/
		Property_Get(unsigned, lengthSample) const;

		/*
		*
		*/
		Property_Get(unsigned, samplingRate) const;

		/*
		*
		*/
		Property_Get(unsigned, dataSize) const;

		/*
		*
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*
		*	@param path
		*	@param format
		*	@return
		*/
		bool save(const FilePath& path, AudioFormat format = AudioFormat::Unspecified) const;

		/**
		*
		*	@param path
		*	@param quality
		*	@return
		*/
		bool saveOggVorbis(const FilePath& path, int quality = 80) const;

		/**
		*
		*	@param path
		*	@param quality
		*	@return
		*/
		bool saveAAC(const FilePath& path, AACQuality quality = AACQuality::Default) const;

		/**
		*
		*	@return
		*/
		Wave& swapChannel();

		/**
		*
		*	@return
		*/
		Wave& reverse();
	};

	/**
	*	@brief
	*/
	namespace Audio
	{
		/**
		*
		*	@param path
		*	@return
		*/
		AudioFormat GetFormat(const FilePath& path);

		/**
		*
		*	@param path
		*	@return
		*/
		s3d::optional<AudioProperty> GetProperty(const FilePath& path);

		/**
		*
		*	@return
		*/
		bool AACEncoderEnable();

		/**
		*
		*	@return
		*/
		bool WMAEncoderEnable();

		/**
		*
		*	@return
		*/
		bool MP3EncoderEnable();
	}

	/**
	*	@brief
	*/
	namespace Waving
	{
		/**
		*	テンポを変更した Wave を返します。
		*	@param wave 元の Wave
		*	@param tempo 1.0 を基準としたテンポ。小さいと遅く、大きいと速くなる
		*	@param quickSeek 品質を少し落として処理を高速化するかのフラグ
		*	@return テンポを変更した Wave
		*/
		Wave ChangeTempo(const Wave& wave, double tempo, bool quickSeek = false);

		/**
		*	ピッチを変更した Wave を返します。
		*	@param wave 元の Wave
		*	@param pitchSemitones ピッチの変更 (半音上げる場合は 1.0, 1 オクターブ上げる場合は 12.0, 半音下げる場合は -1.0)
		*	@param quickSeek 品質を少し落として処理を高速化するかのフラグ
		*	@return ピッチを変更した Wave
		*/
		Wave ChangePitchSemitones(const Wave& wave, double pitchSemitones, bool quickSeek = false);

		/**
		*	サンプリングレートを変更した Wave を返します。
		*	@param wave 元の Wave
		*	@param samplingRate サンプリングレート
		*	@param quickSeek 品質を少し落として処理を高速化するかのフラグ
		*	@return サンプリングレートを変更した Wave
		*/
		Wave ChangeSamplingRate(const Wave& wave, unsigned samplingRate, bool quickSeek = false);

		/**
		*
		*	@param mono
		*	@return
		*/
		WaveSample DoubleToSample(double mono);

		/**
		*
		*	@param left
		*	@param right
		*	@return
		*/
		WaveSample DoubleToSample(double left, double right);

		/**
		*
		*	@param wave
		*	@return
		*/
		Wave SwapChannel(const Wave& wave);

		/**
		*
		*	@param wave
		*	@return
		*/
		Wave Reverse(const Wave& wave);

		/**
		*
		*	@param t
		*	@return
		*/
		inline double SinWave440Hz(double t)
		{
			return Math::Sin(t*440.0*Math::Pi*2.0);
		}

		/**
		*
		*	@param lengthSec
		*	@param function
		*	@param rate
		*	@return
		*/
		Wave Synthesize(double lengthSec, std::function<double(double)> function = SinWave440Hz, unsigned rate = Wave::DefaultSamplingRate);
	}
}
