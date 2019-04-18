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
# include <utility>
# include <array>
# include "SivForward.hpp"
# include "SivString.hpp"

namespace s3d
{
	struct FormatData
	{
		FormatData() : decimalPlace({ 5 }){}
		String str;

		struct DecimalPlace
		{
			int value;
		} decimalPlace;
	};

	inline String Format(const FormatData& formatData)
	{
		return formatData.str;
	}

	template <typename Type, typename ... Args>
	inline
		String
		Format(
		FormatData& formatData,
		const Type& value,
		const Args& ... args
		)
	{
		Formatter(formatData, value);
		return Format(formatData, args...);
	}

	/**
	*	一連の引数を文字列に変換します。
	*	@param args 変換する値
	*	@return 引数を文字列に変換して連結した文字列
	*/
	template <typename ... Args>
	inline String Format(const Args& ... args)
	{
		FormatData formatData;
		return Format(formatData, args...);
	}

	inline String Format() = delete;

	inline String Format(wchar_t ch)
	{
		return String(1, ch);
	}

	inline String Format(const wchar_t* const str)
	{
		return { str };
	}

	inline String Format(const String& str)
	{
		return str;
	}

	/**
	*	値を指定したフィールド幅をもつ文字列に変換します。
	*	@param value 変換するデータ
	*	@param padding フィールド幅と詰め文字のペア
	*	@return フィールド幅に従って詰め文字を追加した文字列
	*/
	template<typename Type>
	inline
		String
		Pad(
		const Type& value,
		const std::pair<int,wchar_t>& padding
		)
	{
		return Format(value).padLeft(padding.first, padding.second);
	}

	/**
	*	小数点以下桁数の情報
	*	@param width 小数点以下の桁数
	*	@return Format に渡す小数点以下桁数の情報
	*/
	inline
	FormatData::DecimalPlace
		DecimalPlace(
		int width
		)
	{
		return { width };
	}

	void Formatter(FormatData& formatData, bool value);
	void Formatter(FormatData& formatData, signed char value);
	void Formatter(FormatData& formatData, unsigned char value);
	void Formatter(FormatData& formatData, char value);
	void Formatter(FormatData& formatData, short value);
	void Formatter(FormatData& formatData, unsigned short value);
	void Formatter(FormatData& formatData, wchar_t value);
	void Formatter(FormatData& formatData, int value);
	void Formatter(FormatData& formatData, unsigned value);
	void Formatter(FormatData& formatData, long value);
	void Formatter(FormatData& formatData, unsigned long value);
	void Formatter(FormatData& formatData, long long value);
	void Formatter(FormatData& formatData, unsigned long long value);
	void Formatter(FormatData& formatData, float value);
	void Formatter(FormatData& formatData, double value);
	void Formatter(FormatData& formatData, const void* value);
	void Formatter(FormatData& formatData, const wchar_t* const str);
	void Formatter(FormatData& formatData, const String& str);
	void Formatter(FormatData& formatData, const char* const str) = delete;

	void Formatter(FormatData& formatData, const Float2& value);
	void Formatter(FormatData& formatData, const Float3& value);
	void Formatter(FormatData& formatData, const Float4& value);
	void Formatter(FormatData& formatData, const Vec2& value);
	void Formatter(FormatData& formatData, const Vec3& value);
	void Formatter(FormatData& formatData, const Vec4& value);
	void Formatter(FormatData& formatData, const __m128& value);
	void Formatter(FormatData& formatData, const Quaternion& value);
	void Formatter(FormatData& formatData, const Mat4x4& value);

	template <typename Type, size_t N>
	inline
	void
		Formatter(
		FormatData& formatData,
		const Type(&values)[N]
		)
	{
		formatData.str.push_back(L'{');

		for (size_t i = 0; i < N; ++i)
		{
			Formatter(formatData, values[i]);

			if (i + 1 != N)
			{
				formatData.str.push_back(L',');
			}
		}

		formatData.str.push_back(L'}');
	}

	template <typename Type, size_t N>
	inline
	void
		Formatter(
		FormatData& formatData,
		const std::array<Type, N>& v
		)
	{
		formatData.str.push_back(L'{');

		const size_t N = v.size();

		for (size_t i = 0; i < N; ++i)
		{
			Formatter(formatData, v[i]);

			if (i + 1 != N)
			{
				formatData.str.push_back(L',');
			}
		}

		formatData.str.push_back(L'}');
	}

	template <typename Type>
	inline
	void
		Formatter(
		FormatData& formatData,
		const std::vector<Type>& v
		)
	{
		formatData.str.push_back(L'{');

		const size_t N = v.size();

		for (size_t i = 0; i < N; ++i)
		{
			Formatter(formatData, v[i]);

			if (i + 1 != N)
			{
				formatData.str.push_back(L',');
			}
		}

		formatData.str.push_back(L'}');
	}

	template <typename Type>
	inline
	void
		Formatter(
		FormatData& formatData,
		const Type& value
		)
	{
		std::wostringstream wos;

		wos << value;

		formatData.str.append(wos.str());
	}

	void Formatter(FormatData& formatData, const FormatData::DecimalPlace& decimalPlace);
}
