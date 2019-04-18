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
	*	@brief 浮動小数点数
	*
	*	浮動小数点数を様々な表現に変換します。
	*/
	template <typename Type, typename BitsType>
	struct FloatBase
	{
		static_assert(
			sizeof(Type) == sizeof(BitsType),
			"error: sizeof(Type)!=sizeof(BitsType)"
			);

		union { Type value; BitsType bits; };

		FloatBase() {}

		/**
		*	数値を設定します。
		*	@param _value 数値
		*/
		FloatBase(Type _value) : value(_value) {}

		/**
		*	文字列から数値に変換します。
		*	@param str 変換される文字列（例: L"123.45")
		*/
		FloatBase(const String& str);

		/**
		*	組み込み型に変換します。
		*	@return 組み込み型の数値
		*/
		operator Type() const { return value; }

		/**
		*	新しい数値に置き換えます。
		*	@return 新しい数値
		*/
		FloatBase operator = (Type _value)
		{
			value = _value;
			return *this;
		}

		/**
		*	文字列で示された新しい数値に置き換えます。
		*	@param str 新しい数値を示す文字列
		*	@return 新しい数値
		*/
		FloatBase operator = (const String& str)
		{
			return *this = FloatBase<Type, BitsType>(str);
		}

		/**
		*	数値を文字列で表します。
		*	@param decimalPlace 小数点以下の桁数
		*	@return 変換した文字列
		*/
		String toString(int decimalPlace) const;

		/**
		*	数値を文字列で表します。
		*/
		Property_Get(String, string) const { return toString(3); }

		/**
		*	ビット表現を 2 進数の文字列で表します。
		*/
		Property_Get(String, binary) const;

		/**
		*	ビット表現を 8 進数の文字列で表します。
		*/
		Property_Get(String, octal) const;

		/**
		*	ビット表現を 16 進数の文字列で表します。
		*/
		Property_Get(String, hex) const;
	};

	typedef
		FloatBase<float, unsigned>
		Float;

	typedef
		FloatBase<double, unsigned long long>
		Double;
}
