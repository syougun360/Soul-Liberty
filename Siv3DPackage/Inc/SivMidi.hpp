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
	*	@brief Midi
	*
	*	Midi サウンドを扱います。
	*/
	namespace Midi
	{
		/**
		*	新しい Midi ファイルを読み込みます。
		*	@param path Midi ファイル名
		*	@return Midi ファイルの読み込みに成功した場合 true、それ以外の場合は false
		*	@note 以前に読み込まれていた Midi は停止・破棄されます。音量・再生速度はリセットされます。
		*/
		bool
			Open(
			const FilePath& path
			);

		/**
		*	Midi::Open() で読み込んだ Midi を再生します。
		*	@return Midi の再生開始に成功した場合 true、それ以外の場合は false
		*	@note Midi は同時に 1 つのファイルしか再生できません。
		*	ほかのアプリケーションが Midi デバイスを使用していた場合、再生に失敗する場合があります。
		*/
		bool
			Play(
			);

		/**
		*	Midi::Open() で読み込んだ Midi をループ再生します。
		*	@return Midi の再生開始に成功した場合 true、それ以外の場合は false
		*	@note Midi は同時に 1 つのファイルしか再生できません。
		*	ほかのアプリケーションが Midi デバイスを使用していた場合、再生に失敗する場合があります。
		*/
		bool
			PlayLoop(
			);

		/**
		*	再生中の Midi を一時停止します。
		*/
		void
			Pause(
			);

		/**
		*	再生中の Midi を停止し、再生位置を曲の先頭に戻します。
		*/
		void
			Stop(
			);

		/**
		*	Midi が再生中かどうかを示します。
		*	@return Midi が再生中の場合 true、それ以外の場合は false
		*/
		bool
			IsPlaying(
			);

		/**
		*	Midi の再生音量を指定します。
		*	@param volume 音量 (0.0 が最小、1.0 が最大)
		*/
		void
			SetVolume(
			double volume
			);

		/**
		*	現在設定されている Midi の再生音量を返します。
		*	@return 現在設定されている Midi の再生音量
		*/
		double
			GetVolume(
			);

		/**
		*	Midi の再生速度を変更します。
		*	@param speed 再生倍率 (0.1 が最小、10.0 が最大)
		*	@note speed は [0.1,10.0] の範囲にクランプされます。
		*/
		void
			SetTempo(
			double speed
			);

		/**
		*	現在設定されている Midi の再生速度を返します。
		*	@return 現在設定されている Midi の再生速度
		*/
		double
			GetTempo(
			);

		/**
		*	現在読み込まれている Midi を通常速度で再生した場合の曲の長さを秒で返します。
		*	@return Midi の長さ (秒)
		*/
		double
			GetLengthSec(
			);

		/**
		*	現在読み込まれている Midi の再生位置を秒で返します。
		*	@return Midi の再生位置 (秒)
		*/
		double
			GetPosSec(
			);

		/**
		*	Midi の再生位置を変更します。
		*	@param pos Midi の再生位置 (秒)
		*	@note Midi が再生中の場合は、そこから再生を再開します。
		*/
		void
			SetPosSec(
			double pos
			);
	}
}
