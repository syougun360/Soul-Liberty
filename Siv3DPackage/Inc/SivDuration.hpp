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
# include <chrono>

namespace s3d
{
	typedef std::chrono::duration<int, std::ratio<86400>> Days;

	typedef std::chrono::hours Hours;

	typedef std::chrono::minutes Minutes;

	typedef std::chrono::seconds Seconds;

	typedef std::chrono::milliseconds Milliseconds;

	template<typename DurationTo, typename DurationFrom>
	inline
		DurationTo
		DurationCast(
		const DurationFrom& duration
		)
	{
		return std::chrono::duration_cast<DurationTo>(duration);
	}
}
