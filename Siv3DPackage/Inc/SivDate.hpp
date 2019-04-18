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
	*	@brief ���t�Ǝ���
	*/
	struct Date : Calendar
	{
		/**
		*	�� [0-23]
		*/
		int hour;

		/**
		*	�� [0-59]
		*/
		int minute;

		/**
		*	�b [0-59]
		*/
		int second;

		/**
		*	�~���b [0-999]
		*/
		int milliseconds;

		/**
		*	���t�Ǝ����̑Ó�����Ԃ��܂��B
		*	@return ���t�Ǝ������������͈͂̒l�ł���� true, �����łȂ���� false
		*/
		Property_Get(bool, isValid) const;

		/**
		*
		*/
		Date() {}

		/**
		*	�w�肵�����t�Ǝ����𐶐����܂��B
		*	@param _year �N
		*	@param _month �� [1-12]
		*	@param _day �� [1-31]
		*	@param _hour �� [0-23]�A�f�t�H���g�ł� 0
		*	@param _minute �� [0-59]�A�f�t�H���g�ł� 0
		*	@param _second �b [0-59]�A�f�t�H���g�ł� 0
		*	@param _milliseconds �~���b [0-999]�A�f�t�H���g�ł� 0
		*	@note �w�肳�ꂽ��������t�����݂��邩�̓`�F�b�N����܂���B
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
		*	�w�肵�����t�Ǝ����𐶐����܂��B
		*	@param calendar �N����
		*	@param _hour �� [0-23]�A�f�t�H���g�ł� 0
		*	@param _minute �� [0-59]�A�f�t�H���g�ł� 0
		*	@param _second �b [0-59]�A�f�t�H���g�ł� 0
		*	@param _milliseconds �~���b [0-999]�A�f�t�H���g�ł� 0
		*	@note �w�肳�ꂽ��������t�����݂��邩�̓`�F�b�N����܂���B
		*/
		Date(
			const Calendar& calendar,
			int _hour = 0,
			int _minute = 0,
			int _second = 0,
			int _milliseconds = 0
			);

		/**
		*	���݂̃��[�J���̓��t�Ǝ�����Ԃ��܂��B
		*	@return ���݂̃��[�J���̓��t�Ǝ���
		*/
		static
			Date
			Now(
			);

		/**
		*	���݂̋��萢�E���� (UTC) �̓��t�Ǝ�����Ԃ��܂��B
		*	@return ���݂̋��萢�E���� (UTC) �̓��t�Ǝ���
		*/
		static
			Date
			NowUTC(
			);

		/**
		*	��� 0:00 �̃��[�J���̓��t�Ǝ�����Ԃ��܂��B
		*	@return ��� 0:00 �̃��[�J���̓��t�Ǝ���
		*/
		static
			Date
			Yesterday(
			);

		/**
		*	���� 0:00 �̃��[�J���̓��t�Ǝ�����Ԃ��܂��B
		*	@return ���� 0:00 �̃��[�J���̓��t�Ǝ���
		*/
		static
			Date
			Today(
			);

		/**
		*	���� 0:00 �̃��[�J���̓��t�Ǝ�����Ԃ��܂��B
		*	@return ���� 0:00 �̃��[�J���̓��t�Ǝ���
		*/
		static
			Date
			Tomorrow(
			);

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
		*	a		�ߑO/�ߌ� (AM/PM)
		*	HH		24 ���ԕ\�L�� 2 ���̎� (00-23)
		*	H		24 ���ԕ\�L�̎� (0-23)
		*	hh		12 ���ԕ\�L�� 2 ���̎� (00-11)
		*	h		12 ���ԕ\�L�̎� (0-11)
		*	mm		2 ���̕� (00-59)
		*	ss		2 ���̕b (00-59)
		*	S		�����_�ȉ� 1 ���̕b (0-9)
		*	SS		�����_�ȉ� 2 ���̕b (00-99)
		*	SSS		�����_�ȉ� 3 ���̕b (000-999)
		*
		*	���p���ň͂܂�Ă��Ȃ��A���t�@�x�b�g�̓p�^�[�������Ƃ��ĉ��߂���܂��B
		*	'' �͒P����p����\���܂��B
		*
		*	@return �t�H�[�}�b�g���ꂽ���t�Ǝ���
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