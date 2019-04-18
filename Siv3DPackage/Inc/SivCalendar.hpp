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
	*	@brief ���t
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
		*	���O�t���̗j���̒l
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
		*	�j����Ԃ��܂��B
		*/
		Property_Get(int, dayOfWeek) const;

		/**
		*	�j������{��ŕԂ��܂��B
		*/
		Property_Get(String, dayOfWeekJP) const;

		/**
		*	�j�����p��ŕԂ��܂��B
		*/
		Property_Get(String, dayOfWeekEN) const;

		/**
		*	���݂̃��[�J���̔N�����ƈ�v���邩�������܂��B
		*/
		Property_Get(bool, isToday) const;

		/**
		*	���邤�N�ł��邩�������܂��B
		*/
		Property_Get(bool, isLeapYear) const;

		/**
		*	���̓�����Ԃ��܂��B
		*/
		Property_Get(int, daysInMonth) const;

		/**
		*	1 �N�̓�����Ԃ��܂��B
		*/
		Property_Get(int, daysInYear) const;

		/**
		*	���t�̑Ó�����Ԃ��܂��B
		*	@return ���t���������͈͂̒l�ł���� true, �����łȂ���� false
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
		*	���t�Ǝ������w�肵���t�H�[�}�b�g�̕�����ŕԂ��܂��B
		*	�t�H�[�}�b�g�w��̃p�^�[���͈ȉ��̒ʂ�ł��B
		*
		*	yyyy	4 ���̔N (0001-)
		*	yy		2 ���̔N (00-99)
		*	y		�N (1-)
		*	MMMM	�p��̌� (January-December)
		*	MMM		�p��̌��̗��� (Jan-Dec)
		*	MM		2 ���̌� (01-12)
		*	M		1-2 ���̌� (1-12)
		*	dd		2 ���̓� (01-31)
		*	d		1-2 ���̓� (1-31)
		*	EEEE	�p��̗j�� (Sunday-Saturday)
		*	EEE		�p��̗j���̗��� (Sun-Sat)
		*	E		���{��̗j�� (��-�y)
		*
		*	���p���ň͂܂�Ă��Ȃ��A���t�@�x�b�g�̓p�^�[�������Ƃ��ĉ��߂���܂��B
		*	'' �͒P����p����\���܂��B
		*
		*	@param format
		*	@return �t�H�[�}�b�g���ꂽ���t�Ǝ���
		*/
		String
			format(
			const String& format = L"yyyy/M/d"
			) const;

		/**
		*	����̃��[�J���̓��t��Ԃ��܂��B
		*	@return ���݂̃��[�J���̓��t
		*/
		static
			Calendar
			Yesterday(
			);

		/**
		*	���݂̃��[�J���̓��t��Ԃ��܂��B
		*	@return ���݂̃��[�J���̓��t
		*/
		static
		Calendar
			Today(
			);

		/**
		*	�����̃��[�J���̓��t��Ԃ��܂��B
		*	@return ���݂̃��[�J���̓��t
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
