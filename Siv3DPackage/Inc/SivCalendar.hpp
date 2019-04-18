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
# include "SivString.hpp"
# include "SivDuration.hpp"

namespace s3d
{
	/**
	*	@brief 日付
	*/
	struct Calendar
	{
		/**
		*
		*/
		int year;

		/**
		*
		*/
		int month;

		/**
		*
		*/
		int day;

		/**
		*	名前付きの曜日の値
		*/
		enum DayOfWeek : int
		{
			/**
			*
			*/
			Sunday,

			/**
			*
			*/
			Monday,

			/**
			*
			*/
			Tuesday,

			/**
			*
			*/
			Wednesday,

			/**
			*
			*/
			Thursday,

			/**
			*
			*/
			Friday,

			/**
			*
			*/
			Saturday
		};

		/**
		*	曜日を返します。
		*/
		Property_Get(int, dayOfWeek) const;

		/**
		*	曜日を日本語で返します。
		*/
		Property_Get(String, dayOfWeekJP) const;

		/**
		*	曜日を英語で返します。
		*/
		Property_Get(String, dayOfWeekEN) const;

		/**
		*	現在のローカルの年月日と一致するかを示します。
		*/
		Property_Get(bool, isToday) const;

		/**
		*	うるう年であるかを示します。
		*/
		Property_Get(bool, isLeapYear) const;

		/**
		*	月の日数を返します。
		*/
		Property_Get(int, daysInMonth) const;

		/**
		*	1 年の日数を返します。
		*/
		Property_Get(int, daysInYear) const;

		/**
		*	日付の妥当性を返します。
		*	@return 日付が正しい範囲の値であれば true, そうでなければ false
		*/
		Property_Get(bool, isValid) const;

		/**
		*
		*/
		Calendar() {}

		/**
		*
		*	@param _year
		*	@param _month
		*	@param _day
		*/
		explicit Calendar(
			int _year,
			int _month = 1,
			int _day = 1
			) : year(_year),
			month(_month),
			day(_day) {}

		/**
		*	日付と時刻を指定したフォーマットの文字列で返します。
		*	フォーマット指定のパターンは以下の通りです。
		*
		*	yyyy	4 桁の年 (0001-)
		*	yy		2 桁の年 (00-99)
		*	y		年 (1-)
		*	MMMM	英語の月 (January-December)
		*	MMM		英語の月の略称 (Jan-Dec)
		*	MM		2 桁の月 (01-12)
		*	M		1-2 桁の月 (1-12)
		*	dd		2 桁の日 (01-31)
		*	d		1-2 桁の日 (1-31)
		*	EEEE	英語の曜日 (Sunday-Saturday)
		*	EEE		英語の曜日の略称 (Sun-Sat)
		*	E		日本語の曜日 (日-土)
		*
		*	引用符で囲まれていないアルファベットはパターン文字として解釈されます。
		*	'' は単一引用符を表します。
		*
		*	@param format
		*	@return フォーマットされた日付と時刻
		*/
		String
			format(
			const String& format = L"yyyy/M/d"
			) const;

		/**
		*	昨日のローカルの日付を返します。
		*	@return 現在のローカルの日付
		*/
		static
			Calendar
			Yesterday(
			);

		/**
		*	現在のローカルの日付を返します。
		*	@return 現在のローカルの日付
		*/
		static
		Calendar
			Today(
			);

		/**
		*	明日のローカルの日付を返します。
		*	@return 現在のローカルの日付
		*/
		static
			Calendar
			Tomorrow(
			);

		/**
		*
		*	@param days
		*	@return
		*/
		Calendar& operator += (const Days& days);

		/**
		*
		*	@param days
		*	@return
		*/
		Calendar& operator -= (const Days& days);
	};

	/**
	*
	*	@param os
	*	@param calendar
	*	@return
	*/
	inline
		std::wostream &
		operator << (
		std::wostream& os,
		const Calendar& calendar
		)
	{
		return os << calendar.format();
	}

	/**
	*
	*	@param calendar
	*	@param days
	*	@return
	*/
	Calendar
		operator + (
		const Calendar& calendar,
		const Days& days
		);

	/**
	*
	*	@param calendar
	*	@param days
	*	@return
	*/
	Calendar
		operator - (
		const Calendar& calendar,
		const Days& days
		);

	/**
	*
	*	@param to
	*	@param from
	*	@return
	*/
	Days
		operator - (
		const Calendar& to,
		const Calendar& from
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator == (
		const Calendar& a,
		const Calendar& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator != (
		const Calendar& a,
		const Calendar& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator < (
		const Calendar& a,
		const Calendar& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator > (
		const Calendar& a,
		const Calendar& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator <= (
		const Calendar& a,
		const Calendar& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator >= (
		const Calendar& a,
		const Calendar& b
		);
}
