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
# include "SivTime.hpp"

namespace s3d
{
	/**
	*	@brief ミリ秒プロファイラー
	*
	*	経過時間をミリ秒で計測します。
	*/
	class MillisecProfiler
	{
	private:

		unsigned m_start = Time::GetMillisec();

	public:

		/**
		*	経過時間（ミリ秒）
		*/
		Property_Get(unsigned, elapsed) const { return Time::GetMillisec() - m_start; }
	};

	/**
	*	@brief マイクロ秒プロファイラー
	*
	*	経過時間をマイクロ秒で計測します。
	*/
	class MicrosecProfiler
	{
	private:

		unsigned long long m_start = Time::GetMicrosec();

	public:

		/**
		*	経過時間（マイクロ秒）
		*/
		Property_Get(unsigned long long, elapsed) const { return Time::GetMicrosec() - m_start; }
	};

	/**
	*	@brief クロックプロファイラー
	*
	*	経過時間を CPU クロック数で計測します。
	*/
	class ClockProfiler
	{
	private:

		unsigned long long m_start = ::__rdtsc();

	public:

		/**
		*	経過時間（CPU クロック数）
		*/
		Property_Get(unsigned long long, elapsed) const { return ::__rdtsc() - m_start; }
	};
}
