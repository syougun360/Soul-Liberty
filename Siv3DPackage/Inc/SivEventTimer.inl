//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

namespace s3d
{
	template<typename Timer>
	inline
	void
		EventTimer<Timer>::
		setEvent(
		const String& event,
		const unsigned time
		)
	{
		m_events.push_back({ event, time, Event::State::StandBy });

		std::stable_sort(m_events.begin(), m_events.end(),
			[](const Event& a, const Event& b)
			{
				return a.time < b.time;
			});
	}

	template<typename Timer>
	inline
		unsigned
		EventTimer<Timer>::
		update(
		)
	{
		const unsigned time = elapsed();

		for (auto& event : m_events)
		{
			if (event.state == Event::State::StandBy && time >= event.time)
			{
				event.state = Event::State::Triggered;
			}
			else if (event.state == Event::State::Triggered)
			{
				event.state = Event::State::Sleep;
			}
		}

		return time;
	}

	template<typename Timer>
	inline
		bool
		EventTimer<Timer>::
		onTriggered(
		const String& _event
		) const
	{
		for (const auto& event : m_events)
		{
			if (event.state == Event::State::Triggered)
			{
				if (event.name == _event)
				{
					return true;
				}
			}
		}

		return false;
	}

	template<typename Timer>
	inline
		std::vector<String>
		EventTimer<Timer>::
		getTriggeredEvents(
		) const
	{
		std::vector<String> events;

		for (const auto& event : m_events)
		{
			if (event.state == Event::State::Triggered)
			{
				events.push_back(event.name);
			}
		}

		return events;
	}

	template<typename Timer>
	inline
		void
		EventTimer<Timer>::
		reset(
		)
	{
		Timer::reset();

		for (auto& event : m_events)
		{
			event.state = Event::State::StandBy;
		}
	}

	template<typename Timer>
	inline
		void
		EventTimer<Timer>::
		restart(
		)
	{
		reset();

		start();
	}

	template<typename Timer>
	inline
		void
		EventTimer<Timer>::
		clearEvents(
		)
	{
		m_events.clear();
	}
}
