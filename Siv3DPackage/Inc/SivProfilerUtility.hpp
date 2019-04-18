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
	*	@brief �~���b�v���t�@�C���[
	*
	*	�o�ߎ��Ԃ��~���b�Ōv�����܂��B
	*/
	class MillisecProfiler
	{
	private:

		unsigned m_start = Time::GetMillisec();

	public:

		/**
		*	�o�ߎ��ԁi�~���b�j
		*/
		Property_Get(unsigned, elapsed) const { return Time::GetMillisec() - m_start; }
	};

	/**
	*	@brief �}�C�N���b�v���t�@�C���[
	*
	*	�o�ߎ��Ԃ��}�C�N���b�Ōv�����܂��B
	*/
	class MicrosecProfiler
	{
	private:

		unsigned long long m_start = Time::GetMicrosec();

	public:

		/**
		*	�o�ߎ��ԁi�}�C�N���b�j
		*/
		Property_Get(unsigned long long, elapsed) const { return Time::GetMicrosec() - m_start; }
	};

	/**
	*	@brief �N���b�N�v���t�@�C���[
	*
	*	�o�ߎ��Ԃ� CPU �N���b�N���Ōv�����܂��B
	*/
	class ClockProfiler
	{
	private:

		unsigned long long m_start = ::__rdtsc();

	public:

		/**
		*	�o�ߎ��ԁiCPU �N���b�N���j
		*/
		Property_Get(unsigned long long, elapsed) const { return ::__rdtsc() - m_start; }
	};
}
