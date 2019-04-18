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
# include <boost/optional.hpp>
# include <iostream>

namespace s3d
{
	/**
	*	optional Œ^
	*/
	using boost::optional;

	/**
	*	
	*/
	using boost::make_optional;

	/**
	*	optional Œ^‚Ì–³Œø’l
	*/
	const boost::none_t none = (static_cast<boost::none_t>(0));

	/**
	*	“Á‚ÉŽw’è‚µ‚È‚¢‚±‚Æ‚ð•\‚· none ‚Ì“¯’l
	*/
	const decltype(none) unspecified = none;

	template<typename Type>
	inline
		std::wostream &
		operator << (
		std::wostream& os,
		const optional<Type>& opt
		)
	{
		if (opt)
		{
			return os << L"optional " << opt.get();
		}
		else
		{
			return os << L"none";
		}
	}

	inline
		std::wostream &
		operator << (
		std::wostream& os,
		const decltype(none)&
		)
	{
		return os << L"none";
	}
}
