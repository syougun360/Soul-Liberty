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

namespace s3d
{
	/**
	*	@brief 文字
	*/
	struct Char
	{
		wchar_t ch;

		Char(){}

		/**
		*	文字を初期化します。
		*	@param _ch 文字
		*/
		Char(wchar_t _ch) : ch{ _ch }{}

		/**
		*	文字を wchar_t 型に変換します。
		*	@return wchar_t 型の文字
		*/
		operator wchar_t() const { return ch; }

		/**
		*	10 進数の数字であるかを示します。
		*/
		Property_Get(bool, isDigit) const;

		/**
		*	アルファベットの小文字であるかを示します。
		*/
		Property_Get(bool, isLower) const;

		/**
		*	アルファベットの大文字であるかを示します。
		*/
		Property_Get(bool, isUpper) const;

		/**
		*	アルファベットであるかを示します。
		*/
		Property_Get(bool, isAlpha) const;

		/**
		*	アルファベットもしくは数字であるかを示します。
		*/
		Property_Get(bool, isAlnum) const;

		/**
		*	16 進数の数字であるかを示します。
		*/
		Property_Get(bool, isXdigit) const;

		/**
		*	制御文字であるかを示します。
		*/
		Property_Get(bool, isControl) const;

		/**
		*	空白文字であるかを示します。
		*	@note L' ', L'\t', L'　' が該当します。
		*/
		Property_Get(bool, isBlank) const;

		/**
		*	空白類文字であるかを示します。
		*	@note L' ', L'\t', L'\n', L'\v', L'\f', L'\t', L'　' が該当します。
		*/
		Property_Get(bool, isSpace) const;

		/**
		*	印字可能文字であるかを示します。
		*/
		Property_Get(bool, isPrint) const;
	};
}
