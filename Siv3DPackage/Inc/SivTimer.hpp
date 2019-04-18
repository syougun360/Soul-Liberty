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
	*	@brief �^�C�}�[
	*
	*	TimerMillisec, TimerSec, TimerMinute ���g�p���܂��B
	*/
	template <int resolutionMilliseconds>
	class TimerBase
	{
	public:

		TimerBase(
			);

		/**
		*	�^�C�}�[���J�n�E�ĊJ���܂��B
		*/
		void
			start(
			);

		/**
		*	�^�C�}�[�̌o�ߎ��Ԃ�Ԃ��܂��B
		*	@return �^�C�}�[�̌o�ߎ���
		*/
		unsigned
			elapsed(
			) const;

		/**
		*	�^�C�}�[�����쒆�ł��邩�������܂��B
		*	@return �^�C�}�[���J�n����Ă���A�܂��͊J�n��ꎞ��~���ł���ꍇ true,
		*			����ȊO�̏ꍇ false
		*/
		Property_Get(bool, isActive) const;

		/**
		*	�^�C�}�[���ꎞ��~���܂��B
		*/
		void
			pause(
			);

		/**
		*	�^�C�}�[���~���A�o�ߎ��Ԃ� 0 �Ƀ��Z�b�g���܂��B
		*/
		void
			reset(
			);

		/**
		*	�o�ߎ��Ԃ� 0 �Ƀ��Z�b�g���āA�^�C�}�[���J�n���܂��B
		*/
		void
			restart(
			);

		/**
		*	�^�C�}�[�̌o�ߎ��Ԃ�ύX���܂��B
		*	@param time �V�����ݒ肷��o�ߎ���
		*/
		void
			set(
			unsigned time
			);

	private:

		unsigned m_startTimeMillisec;

		unsigned m_accumulationMillisec;

		bool m_isActive;

		bool m_pausing;
	};

	/**
	*	@brief 1 �~���b�P�ʂ̃^�C�}�[
	*/
	typedef
		TimerBase<1>
		TimerMillisec;

	/**
	*	@brief 1 �b�P�ʂ̃^�C�}�[
	*/
	typedef
		TimerBase<1000>
		TimerSec;

	/**
	*	@brief 1 ���P�ʂ̃^�C�}�[
	*/
	typedef
		TimerBase<1000 * 60>
		TimerMinute;
}

# include "SivTimer.inl"
