//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# include "SivTime.hpp"

namespace s3d
{
	template<int resolutionMilliseconds>
	TimerBase<resolutionMilliseconds>::
		TimerBase(
		) :	m_startTimeMillisec(0),
			m_accumulationMillisec(0),
			m_isActive(false),
			m_pausing(true)
	{

	}

	template<int resolutionMilliseconds>
	void
		TimerBase<resolutionMilliseconds>::
		start(
		)
	{
		if (!m_pausing)
		{
			return;
		}

		m_startTimeMillisec = Time::GetMillisec();

		m_isActive = true;

		m_pausing = false;
	}

	template<int resolutionMilliseconds>
	unsigned
		TimerBase<resolutionMilliseconds>::
		elapsed(
		) const
	{
		if (!m_isActive)
		{
			return 0;
		}

		if (m_pausing)
		{
			return m_accumulationMillisec / resolutionMilliseconds;
		}

		return (m_accumulationMillisec + (Time::GetMillisec() - m_startTimeMillisec)) / resolutionMilliseconds;
	}

	template<int resolutionMilliseconds>
	bool
		TimerBase<resolutionMilliseconds>::
		_get_isActive(
		) const
	{
		return m_isActive;
	}

	template<int resolutionMilliseconds>
	void
		TimerBase<resolutionMilliseconds>::
		pause(
		)
	{
		m_accumulationMillisec = elapsed();

		m_pausing = true;
	}

	template<int resolutionMilliseconds>
	void
		TimerBase<resolutionMilliseconds>::
		reset(
		)
	{
		m_accumulationMillisec = 0;

		m_isActive = false;

		m_pausing = true;
	}

	template<int resolutionMilliseconds>
	void
		TimerBase<resolutionMilliseconds>::
		restart(
		)
	{
		reset();

		start();
	}

	template<int resolutionMilliseconds>
	void
		TimerBase<resolutionMilliseconds>::
		set(
		const unsigned time
		)
	{
		m_startTimeMillisec = Time::GetMillisec();

		m_accumulationMillisec = time * resolutionMilliseconds;
	}
}
