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
# include "SivForward.hpp"
# include "SivStringRef.hpp"

namespace s3d
{
	/**
	*	@brief 文字セット
	*
	*	文字セットを変換する機能。
	*/
	namespace CharacterSet
	{
		/**
		*	マルチバイト ASCII 文字列をワイド文字列に変換します。
		*	@param asciiStr ASCII 文字で構成されたマルチバイト文字列
		*	@return 変換されたワイド文字列
		*	@note Widen() 関数より高速に動作します。
		*/
		String
			WidenAscii(
			const boost::string_ref& asciiStr
			);

		/**
		*	ワイド ASCII 文字列をマルチバイト文字列に変換します。
		*	@param asciiStr ASCII 文字で構成されたワイド文字列
		*	@return 変換されたマルチバイト文字列
		*	@note Narrow() 関数より高速に動作します。
		*/
		std::string
			NarrowAscii(
			const StringRef& asciiStr
			);

		/**
		*	マルチバイト文字列をワイド文字列に変換します。
		*	@param str マルチバイト文字列
		*	@return 変換されたワイド文字列
		*/
		String
			Widen(
			const boost::string_ref& str
			);

		/**
		*	ワイド文字列をマルチバイト文字列に変換します。
		*	@param str ワイド文字列
		*	@return 変換されたマルチバイト文字列
		*/
		std::string
			Narrow(
			const StringRef& str
			);

		/**
		*	ワイド文字列を UTF-8 文字列に変換します。
		*	@param str ワイド文字列
		*	@return 変換された UTF-8 文字列
		*/
		std::string
			ToUTF8(
			const StringRef& str
			);

		/**
		*	UTF-8 文字列をワイド文字列に変換します。
		*	@param str UTF-8 文字列
		*	@return 変換されたワイド文字列
		*/
		String
			FromUTF8(
			const boost::string_ref& str
			);
	}

# ifndef NO_CHARACTERSET_USING
	using CharacterSet::WidenAscii;
	using CharacterSet::NarrowAscii;
	using CharacterSet::Widen;
	using CharacterSet::Narrow;
	using CharacterSet::ToUTF8;
	using CharacterSet::FromUTF8;
# endif

}
