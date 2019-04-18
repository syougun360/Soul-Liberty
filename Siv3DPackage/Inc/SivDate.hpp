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
# include "SivCalendar.hpp"

namespace s3d
{
	/**
	*	@brief 日付と時刻
	*/
	struct Date : Calendar
	{
		/**
		*	時 [0-23]
		*/
		int hour;

		/**
		*	分 [0-59]
		*/
		int minute;

		/**
		*	秒 [0-59]
		*/
		int second;

		/**
		*	ミリ秒 [0-999]
		*/
		int milliseconds;

		/**
		*	日付と時刻の妥当性を返します。
		*	@return 日付と時刻が正しい範囲の値であれば true, そうでなければ false
		*/
		Property_Get(bool, isValid) const;

		/**
		*
		*/
		Date() {}

		/**
		*	指定した日付と時刻を生成します。
		*	@param _year 年
		*	@param _month 月 [1-12]
		*	@param _day 日 [1-31]
		*	@param _hour 時 [0-23]、デフォルトでは 0
		*	@param _minute 分 [0-59]、デフォルトでは 0
		*	@param _second 秒 [0-59]、デフォルトでは 0
		*	@param _milliseconds ミリ秒 [0-999]、デフォルトでは 0
		*	@note 指定された時刻や日付が存在するかはチェックされません。
		*/
		Date(
			int _year,
			int _month,
			int _day,
			int _hour = 0,
			int _minute = 0,
			int _second = 0,
			int _milliseconds = 0
			);

		/**
		*	指定した日付と時刻を生成します。
		*	@param calendar 年月日
		*	@param _hour 時 [0-23]、デフォルトでは 0
		*	@param _minute 分 [0-59]、デフォルトでは 0
		*	@param _second 秒 [0-59]、デフォルトでは 0
		*	@param _milliseconds ミリ秒 [0-999]、デフォルトでは 0
		*	@note 指定された時刻や日付が存在するかはチェックされません。
		*/
		Date(
			const Calendar& calendar,
			int _hour = 0,
			int _minute = 0,
			int _second = 0,
			int _milliseconds = 0
			);

		/**
		*	現在のローカルの日付と時刻を返します。
		*	@return 現在のローカルの日付と時刻
		*/
		static
			Date
			Now(
			);

		/**
		*	現在の協定世界時刻 (UTC) の日付と時刻を返します。
		*	@return 現在の協定世界時刻 (UTC) の日付と時刻
		*/
		static
			Date
			NowUTC(
			);

		/**
		*	昨日 0:00 のローカルの日付と時刻を返します。
		*	@return 昨日 0:00 のローカルの日付と時刻
		*/
		static
			Date
			Yesterday(
			);

		/**
		*	今日 0:00 のローカルの日付と時刻を返します。
		*	@return 今日 0:00 のローカルの日付と時刻
		*/
		static
			Date
			Today(
			);

		/**
		*	明日 0:00 のローカルの日付と時刻を返します。
		*	@return 明日 0:00 のローカルの日付と時刻
		*/
		static
			Date
			Tomorrow(
			);

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
		*	a		午前/午後 (AM/PM)
		*	HH		24 時間表記の 2 桁の時 (00-23)
		*	H		24 時間表記の時 (0-23)
		*	hh		12 時間表記の 2 桁の時 (00-11)
		*	h		12 時間表記の時 (0-11)
		*	mm		2 桁の分 (00-59)
		*	ss		2 桁の秒 (00-59)
		*	S		小数点以下 1 桁の秒 (0-9)
		*	SS		小数点以下 2 桁の秒 (00-99)
		*	SSS		小数点以下 3 桁の秒 (000-999)
		*
		*	引用符で囲まれていないアルファベットはパターン文字として解釈されます。
		*	'' は単一引用符を表します。
		*
		*	@return フォーマットされた日付と時刻
		*/
		String
			format(
			const String& pattern = L"yyyy/M/d HH:mm:ss"
			) const;

		/**
		*
		*	@param days
		*	@return
		*/
		Date& operator += (const Days& days);

		/**
		*
		*	@param days
		*	@return
		*/
		Date& operator -= (const Days& days);

		/**
		*
		*	@param _milliseconds
		*	@return
		*/
		Date& operator += (const Milliseconds& _milliseconds);

		/**
		*
		*	@param _milliseconds
		*	@return
		*/
		Date& operator -= (const Milliseconds& _milliseconds);
	};

	/**
	*
	*	@param os
	*	@param date
	*	@return
	*/
	inline
		std::wostream &
		operator << (
		std::wostream& os,
		const Date& date
		)
	{
		return os << date.format();
	}

	/**
	*
	*	@param date
	*	@param days
	*	@return
	*/
	Date operator + (const Date& date, const Days& days);

	/**
	*
	*	@param date
	*	@param days
	*	@return
	*/
	Date operator - (const Date& date, const Days& days);

	/**
	*
	*	@param date
	*	@param milliseconds
	*	@return
	*/
	Date operator + (const Date& date, const Milliseconds& milliseconds);

	/**
	*
	*	@param date
	*	@param milliseconds
	*	@return
	*/
	Date operator - (const Date& date, const Milliseconds& milliseconds);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	Milliseconds operator - (const Date& a, const Date& b);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator == (
		const Date& a,
		const Date& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator != (
		const Date& a,
		const Date& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator < (
		const Date& a,
		const Date& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator > (
		const Date& a,
		const Date& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator <= (
		const Date& a,
		const Date& b
		);

	/**
	*
	*	@param a
	*	@param b
	*	@return
	*/
	bool
		operator >= (
		const Date& a,
		const Date& b
		);
}