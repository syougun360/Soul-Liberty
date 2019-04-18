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
# include <sstream>

namespace s3d
{
	template <typename Type>
	inline
	Type
		Parse(
		const String& str
		)
	{
		Type to;

		if (std::wistringstream{ str.str() } >> to)
		{
			return to;
		}

		return to;
	}

	template <>
	inline
	bool
		Parse<bool>(
		const String& str
		)
	{
		return str.lower() == L"true";
	}

	/**
	*	文字列をデータ型に変換します。
	*	@param str 文字列
	*	@param defaultValue 変換に失敗したときに返す値
	*	@return 文字列から変換されたデータ。変換し失敗した場合は defaultValue
	*/
	template <typename Type>
	inline
	Type
		ParseOr(
		const String& str,
		const Type& defaultValue
		)
	{
		Type to;

		if (std::wistringstream{ str.str() } >> to)
		{
			return to;
		}

		return defaultValue;
	}

	template <>
	inline
	bool
		ParseOr<bool>(
		const String& str,
		const bool& defaultValue
		)
	{
		const String lower = str.lower();

		if (lower == L"true")
		{
			return true;
		}
		else if (lower == L"false")
		{
			return false;
		}

		return defaultValue;
	}

	template <typename Type>
	inline
	optional<Type>
		ParseOpt(
		const String& str
		)
	{
		Type to;

		if (std::wistringstream{ str.str() } >> to)
		{
			return to;
		}

		return none;
	}

	template <>
	inline
	optional<bool>
		ParseOpt<bool>(
		const String& str
		)
	{
		const String lower = str.lower();

		if (lower == L"true")
		{
			return true;
		}
		else if (lower == L"false")
		{
			return false;
		}

		return none;
	}
}
