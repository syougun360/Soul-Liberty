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

namespace s3d
{
	/**
	*	@brief イベントフラグ
	*/
	struct WindowEvent
	{
		enum Flag
		{
			/**
			*	ウィンドウの [x] ボタンが押される
			*/
			CloseButton = 0x01,

			/**
			*	エスケープキーが押される
			*/
			EscapeKey = 0x02,

			/**
			*	マウスの左クリック
			*/
			LeftClick = 0x04,

			/**
			*	マウスの右クリック
			*/
			RightClick = 0x08,

			/**
			*	ウィンドウのフォーカスが外れる
			*/
			Unfocus = 0x10,

			/**
			*	何らかのキーが押される
			*/
			AnyKey = 0x20,

			/**
			*	デフォルト（ウィンドウの [x] ボタンが押されるか、エスケープキーが押される）
			*/
			Default = CloseButton | EscapeKey,

			/**
			*	設定しない
			*	必ず System::Exit() を実行して終了する必要があります。
			*/
			Manual = 0x00,
		};
	};

	namespace System
	{
		/**
		*	グラフィックスと入力を更新します。またフレームの更新が 60fps 以下になるよう時間を調整します。
		*	終了イベントが発生した場合や、エンジンの内部でエラーが発生した場合 false を返します。
		*	@return アプリケーションが続行できる場合 true, アプリケーションを終了する場合 false
		*/
		bool
			Update(
			);

		/**
		*	アプリケーションの終了をエンジンに伝えます。
		*	次の System::Update() は必ず false を返します。
		*/
		void
			Exit(
			);

		/**
		*	終了イベントを設定します。
		*	@param windowEventFlag イベントフラグ WindowEvent::Flag の組み合わせ
		*/
		void
			SetExitEvent(
			int windowEventFlag
			);

		/**
		*	直前のフレームで発生したイベントを返します。
		*	@return イベントフラグ WindowEvent::Flag の組み合わせ
		*/
		int
			GetPreviousEvent(
			);

		/**
		*	指定したミリ秒だけ処理を停止します。
		*	@param milliseconds 処理を停止する時間（ミリ秒）
		*	@note 20 ミリ秒以上は Win32 API の Sleep を、それ以下は PAUSE 命令のスピン・ループを使用します。
		*/
		void
			Sleep(
			double milliseconds
			);

		/**
		*	System::Update() が呼ばれた回数（＝更新したフレーム数）を返します。
		*	@return System::Update() が呼ばれた回数
		*/
		unsigned
			FrameCount(
			);
	}
}
