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
# include <vector>
# include "SivTimer.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief �C�x���g�^�C�}�[
	*/
	template<typename Timer>
	class EventTimer : public Timer
	{
	private:

		struct Event
		{
			String name;

			unsigned time;

			enum class State { StandBy, Triggered, Sleep };
			
			State state;
		};

		std::vector<Event> m_events;

	public:

		/**
		*	�C�x���g���쐬���܂��B
		*	@param event �C�x���g��
		*	@param time �C�x���g����������^�C�}�[�o�ߎ���
		*/
		inline
		void
			setEvent(
			const String& event,
			unsigned time
			);

		/**
		*	�C�x���g�̏�Ԃ��X�V���܂��B
		*	@return �^�C�}�[�̌o�ߎ���
		*/
		inline
		unsigned
			update(
			);

		/**
		*	���O�̍X�V�ŃC�x���g�������������ǂ�����Ԃ��܂��B
		*	@param event �C�x���g��
		*	@return ���O�̍X�V�ŃC�x���g�����������Ƃ��� true, ����ȊO�̏ꍇ�� false
		*/
		inline
		bool
			onTriggered(
			const String& event
			) const;

		/**
		*	���O�̍X�V�Ŕ��������C�x���g����Ԃ��܂��B
		*	@return ���O�̍X�V�Ŕ����������C�x���g�ꗗ
		*	@note �C�x���g�͎��Ԃ̑������A�����Ēǉ��������Ƀ\�[�g����Ă��܂��B
		*/
		inline
		std::vector<String>
			getTriggeredEvents(
			) const;

		/**
		*	�C�x���g��������Ԃɖ߂��A�^�C�}�[���~���Čo�ߎ��Ԃ� 0 �Ƀ��Z�b�g���܂��B
		*	@note �C�x���g���폜����ɂ� clearEvents() ���g���܂��B
		*/
		inline
		void
			reset(
			);

		/**
		*	�C�x���g��������Ԃɖ߂��A�o�ߎ��Ԃ� 0 �Ƀ��Z�b�g���ă^�C�}�[���J�n���܂��B
		*	@note �C�x���g���폜����ɂ� clearEvents() ���g���܂��B
		*/
		inline
		void
			restart(
			);

		/**
		*	���ׂẴC�x���g���폜���܂��B
		*/
		inline
		void
			clearEvents(
			);
	};

	/**
	*	@brief 1 �~���b�P�ʂ̃C�x���g�^�C�}�[
	*/
	typedef
		EventTimer<TimerMillisec>
		EventTimerMillisec;

	/**
	*	@brief 1 �b�P�ʂ̃C�x���g�^�C�}�[
	*/
	typedef
		EventTimer<TimerSec>
		EventTimerSec;

	/**
	*	@brief 1 ���P�ʂ̃C�x���g�^�C�}�[
	*/
	typedef
		EventTimer<TimerMinute>
		EventTimerMinute;
}

# include "SivEventTimer.inl"
