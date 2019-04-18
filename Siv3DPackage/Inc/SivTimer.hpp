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
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	@brief タイマー
	*
	*	TimerMillisec, TimerSec, TimerMinute が使用します。
	*/
	template <int resolutionMilliseconds>
	class TimerBase
	{
	public:

		TimerBase(
			);

		/**
		*	タイマーを開始・再開します。
		*/
		void
			start(
			);

		/**
		*	タイマーの経過時間を返します。
		*	@return タイマーの経過時間
		*/
		unsigned
			elapsed(
			) const;

		/**
		*	タイマーが動作中であるかを示します。
		*	@return タイマーが開始されている、または開始後一時停止中である場合 true,
		*			それ以外の場合 false
		*/
		Property_Get(bool, isActive) const;

		/**
		*	タイマーを一時停止します。
		*/
		void
			pause(
			);

		/**
		*	タイマーを停止し、経過時間を 0 にリセットします。
		*/
		void
			reset(
			);

		/**
		*	経過時間を 0 にリセットして、タイマーを開始します。
		*/
		void
			restart(
			);

		/**
		*	タイマーの経過時間を変更します。
		*	@param time 新しく設定する経過時間
		*/
		void
			set(
			unsigned time
			);

	private:

		unsigned m_startTimeMillisec;

		unsigned m_accumulationMillisec;

		bool m_isActive;

		bool m_pausing;
	};

	/**
	*	@brief 1 ミリ秒単位のタイマー
	*/
	typedef
		TimerBase<1>
		TimerMillisec;

	/**
	*	@brief 1 秒単位のタイマー
	*/
	typedef
		TimerBase<1000>
		TimerSec;

	/**
	*	@brief 1 分単位のタイマー
	*/
	typedef
		TimerBase<1000 * 60>
		TimerMinute;
}

# include "SivTimer.inl"
