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
	*	@brief イベントタイマー
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
		*	イベントを作成します。
		*	@param event イベント名
		*	@param time イベントが発生するタイマー経過時間
		*/
		inline
		void
			setEvent(
			const String& event,
			unsigned time
			);

		/**
		*	イベントの状態を更新します。
		*	@return タイマーの経過時間
		*/
		inline
		unsigned
			update(
			);

		/**
		*	直前の更新でイベントが発生したかどうかを返します。
		*	@param event イベント名
		*	@return 直前の更新でイベントが発生したときは true, それ以外の場合は false
		*/
		inline
		bool
			onTriggered(
			const String& event
			) const;

		/**
		*	直前の更新で発生したイベント名を返します。
		*	@return 直前の更新で発生したいイベント一覧
		*	@note イベントは時間の早い順、そして追加した順にソートされています。
		*/
		inline
		std::vector<String>
			getTriggeredEvents(
			) const;

		/**
		*	イベントを初期状態に戻し、タイマーを停止して経過時間を 0 にリセットします。
		*	@note イベントを削除するには clearEvents() を使います。
		*/
		inline
		void
			reset(
			);

		/**
		*	イベントを初期状態に戻し、経過時間を 0 にリセットしてタイマーを開始します。
		*	@note イベントを削除するには clearEvents() を使います。
		*/
		inline
		void
			restart(
			);

		/**
		*	すべてのイベントを削除します。
		*/
		inline
		void
			clearEvents(
			);
	};

	/**
	*	@brief 1 ミリ秒単位のイベントタイマー
	*/
	typedef
		EventTimer<TimerMillisec>
		EventTimerMillisec;

	/**
	*	@brief 1 秒単位のイベントタイマー
	*/
	typedef
		EventTimer<TimerSec>
		EventTimerSec;

	/**
	*	@brief 1 分単位のイベントタイマー
	*/
	typedef
		EventTimer<TimerMinute>
		EventTimerMinute;
}

# include "SivEventTimer.inl"
