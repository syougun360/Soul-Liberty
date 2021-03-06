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
	*	optional 型
	*/
	using boost::optional;

	/**
	*	
	*/
	using boost::make_optional;

	/**
	*	optional 型の無効値
	*/
	const boost::none_t none = (static_cast<boost::none_t>(0));

	/**
	*	特に指定しないことを表す none の同値
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
