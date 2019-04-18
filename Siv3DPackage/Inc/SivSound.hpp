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
# include <memory>
# include "SivHandle.hpp"
# include "SivPropertyMacro.hpp"
# include "SivMath.hpp"

namespace s3d
{
	/**
	*	@brief
	*/
	struct LoopProperty
	{
		/**
		*
		*/
		LoopProperty()
		{
		
		}

		/**
		*
		*	@param _loop
		*	@param _loopBeginSample
		*	@param _loopEndSample
		*/
		LoopProperty(bool _loop, unsigned _loopBeginSample = 0, unsigned _loopEndSample = 0)
		: loop{ _loop },
		  loopBeginSample{ _loop ? _loopBeginSample : 0 },
		  loopEndSample{ _loop ? _loopEndSample : 0 }
		{

		}

		/**
		*
		*/
		bool loop = false;

		/**
		*
		*/
		unsigned loopBeginSample = 0;

		/**
		*
		*/
		unsigned loopEndSample = 0;
	};

	/**
	*	@brief
	*/
	class Sound
	{	
	private:

		class Handle{};

		typedef Siv3DHandle<Handle> SoundHandle;

		std::shared_ptr<SoundHandle> m_handle;

	public:

		/**
		*
		*/
		Sound();

		/**
		*
		*	@param path
		*	@param loopProperty
		*/
		explicit Sound(const FilePath& path, const LoopProperty& loopProperty = { false });

		/**
		*
		*	@param wave
		*	@param loopProperty
		*/
		explicit Sound(const Wave& wave, const LoopProperty& loopProperty = { false });

		/**
		*
		*	@param wave
		*	@param loopProperty
		*/
		explicit Sound(Wave&& wave, const LoopProperty& loopProperty = { false });

		/**
		*
		*/
		virtual ~Sound();

		/**
		*
		*/
		void release();

		/**
		*
		*	@return
		*/
		explicit operator bool() const;

		/**
		*
		*/
		Property_Get(HandleIDType, id) const;

		/**
		*
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*
		*	@param sound
		*	@return
		*/
		bool operator == (const Sound& sound) const;

		/**
		*
		*	@param sound
		*	@return
		*/
		bool operator != (const Sound& sound) const;

		/**
		*
		*	@return
		*/
		bool play() const;

		/**
		*
		*/
		void pause() const;

		/**
		*
		*/
		void stop() const;

		/**
		*
		*	@param loop
		*/
		void setLoop(bool loop) const;

		/**
		*
		*	@param loop
		*	@param loopBeginSample
		*	@param loopEndSample
		*/
		void setLoopBySample(bool loop, unsigned loopBeginSample = 0, unsigned loopEndSample = 0) const;

		/**
		*
		*	@param loop
		*	@param loopBeginSec
		*	@param loopEndSec
		*/
		void setLoopBySec(bool loop, double loopBeginSec = 0, double loopEndSec = 0) const;

		/**
		*
		*	@param sec
		*/
		void
			setPosSec(
			double sec
			) const;

		/**
		*
		*	@param posSample
		*/
		void
			setPosSample(
			unsigned posSample
			) const;

		/**
		*
		*	@param volume
		*/
		void
			setVolume(
			double volume
			) const;

		/**
		*
		*	@param left
		*	@param right
		*/
		void
			setVolume(
			double left,
			double right
			) const;

		/**
		*	ボリュームを減衰（dB）で設定します。
		*	atten.	= vol.
		*	0 dB	= 1.0
		*	-6 dB	= 0.5
		*	-12 dB	= 0.25
		*	-18 db	= 0.125
		*	...
		*	@param attenuation_dB
		*/
		void
			setAttenuation_dB(
			double attenuation_dB
			) const
		{
			setAttenuation_dB(attenuation_dB, attenuation_dB);
		}

		/**
		*
		*	@param attenuationLeft_dB
		*	@param attenuationRight_dB
		*/
		void
			setAttenuation_dB(
			double attenuationLeft_dB,
			double attenuationRight_dB
			) const
		{
			const double left = Math::Pow(10.0, attenuationLeft_dB / 20.0);
			const double right = Math::Pow(10.0, attenuationRight_dB / 20.0);
			setVolume(left, right);
		}

		/**
		*
		*/
		Property_Get(double, volume) const;

		/**
		*
		*/
		Property_Get(double, volumeLeft) const;

		/**
		*
		*/
		Property_Get(double, volumeRight) const;

		/**
		*
		*	@param speed
		*/
		void
			setSpeed(
			double speed
			) const;

		/**
		*
		*	@param semitone
		*/
		void
			setSpeedBySemitone(
			int semitone
			) const;

		/**
		*
		*/
		Property_Get(double, speed) const;

		/**
		*
		*/
		Property_Get(double, minSpeed) const;

		/**
		*
		*/
		Property_Get(double, maxSpeed) const;

		/**
		*
		*	@return
		*/
		const Wave&
			getWave(
			) const;

		/**
		*	サウンドが再生中であるかを表す
		*/
		Property_Get(bool, isPlaying) const;

		/**
		*	ループが設定されているかを表す
		*/
		Property_Get(bool, isLoop) const;

		/**
		*	ループの先頭位置（サンプル）
		*/
		Property_Get(unsigned, loopBeginSample) const;

		/**
		*	ループの終端位置（サンプル）
		*/
		Property_Get(unsigned, loopEndSample) const;

		/**
		*	再生位置（秒）
		*/
		Property_Get(double, posSec) const;

		/**
		*	再生位置（サンプル）
		*/
		Property_Get(unsigned, posSample) const;

		/**
		*	曲の長さ（秒）
		*/
		Property_Get(double, lengthSec) const;

		/**
		*	曲の長さ（サンプル）
		*/
		Property_Get(unsigned, lengthSample) const;

		/**
		*
		*/
		Property_Get(unsigned, samplingRate) const;

		/**
		*
		*	@param volume
		*	@return
		*/
		bool playMulti(double volume = 1.0) const;

		/**
		*
		*	@param volumeLeft
		*	@param volumeRight
		*	@return
		*/
		bool playMulti(double volumeLeft, double volumeRight) const;

		/**
		*
		*/
		void pauseMulti() const;

		/**
		*
		*/
		void resumeMulti() const;

		/**
		*
		*/
		void stopMulti() const;
	};

	/**
	*	@brief
	*/
	namespace MasterVoice
	{
		/**
		*
		*	@param volume
		*/
		void SetVolume(double volume);

		/**
		*
		*	@return
		*/
		double GetVolume();
	}
}
