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

namespace s3d
{
	/**
	*	@brief 時間
	*/
	namespace Time
	{
		/**
		*	コンピューターが起動してからの経過時間をミリ秒で返します。
		*	@return コンピューターが起動してからの経過時間（ミリ秒）
		*/
		unsigned
			GetMillisec(
			);

		/**
		*	コンピューターが起動してからの経過時間をマイクロ秒で返します。
		*	@return コンピューターが起動してからの経過時間（マイクロ秒）
		*/
		unsigned long long
			GetMicrosec(
			);

		/**
		*	協定世界時 (UTC)  1970 年 1 月 1 日午前 0 時からの経過時間を秒で返します。
		*	@return 1970 年 1 月 1 日午前 0 時からの経過秒数
		*/
		long long
			SecSince1970(
			);

		/**
		*	協定世界時 (UTC)  1601 年 1 月 1 日午前 0 時からの経過時間をミリ秒で返します。
		*	@return 1601 年 1 月 1 日午前 0 時からの経過ミリ秒
		*/
		unsigned long long
			MillisecSince1601(
			);

		/**
		*	現在の協定世界時 (UTC) との時差を分で返します。
		*	@return 現在の協定世界時 (UTC) との時差（分）
		*/
		int
			UtcOffsetMinutes(
			);
	}
}
