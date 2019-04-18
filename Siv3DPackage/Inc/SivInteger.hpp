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
# include "SivPropertyMacro.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief 整数
	*
	*	整数を様々な表現に変換します。
	*/
	template <typename Type>
	struct IntegerBase
	{
		Type value;
		
		IntegerBase() {}

		/**
		*	数値を設定します。
		*	@param _value 数値
		*/
		IntegerBase(Type _value) : value(_value) {}

		/**
		*	文字列から数値に変換します。
		*	@param str 変換される文字列（例: L"12345", L"0xFF")
		*/
		IntegerBase(const String& str) : IntegerBase(str, 0) {}

		/**
		*	基数を指定して文字列から数値に変換します。
		*	@param str 変換される文字列（例: L"12345", L"0xFF")
		*	@param radix 使用する基数
		*/
		IntegerBase(
			const String& str,
			int radix
			);

		/**
		*	組み込み型に変換します。
		*	@return 組み込み型の数値
		*/
		operator Type() const { return value; }

		/**
		*	新しい数値に置き換えます。
		*	@return 新しい数値
		*/
		IntegerBase operator = (Type _value)
		{
			value = _value;
			return *this;
		}

		/**
		*	文字列で示された新しい数値に置き換えます。
		*	@param str 新しい数値を示す文字列
		*	@return 新しい数値
		*/
		IntegerBase operator = (const String& str)
		{
			return *this = IntegerBase<Type>(str);
		}

		/**
		*	数値を文字列で表します。
		*	@param radix 基数
		*	@return 変換した文字列
		*	@note 基数は [2-36] の範囲で指定します。
		*/
		String
			toString(
			int radix
			) const;

		/**
		*	数値を 10 進数の文字列で表します。
		*/
		Property_Get(String, string) const { return toString(10); }

		/**
		*	数値を 2 進数の文字列で表します。
		*/
		Property_Get(String, binary) const { return toString(2); }

		/**
		*	数値を 8 進数の文字列で表します。
		*/
		Property_Get(String, octal) const { return toString(8); }

		/**
		*	数値を 16 進数の文字列で表します。
		*/
		Property_Get(String, hex) const { return toString(16); }
	};

	typedef
		IntegerBase<char>
		Integer8;

	typedef
		IntegerBase<unsigned char>
		IntegerU8;

	typedef
		IntegerBase<short>
		Integer16;

	typedef
		IntegerBase<unsigned short>
		IntegerU16;

	typedef
		IntegerBase<int>
		Integer;

	typedef
		IntegerBase<int>
		Integer32;

	typedef
		IntegerBase<unsigned>
		IntegerU32;

	typedef
		IntegerBase<long long>
		Integer64;

	typedef
		IntegerBase<unsigned long long>
		IntegerU64;
}
