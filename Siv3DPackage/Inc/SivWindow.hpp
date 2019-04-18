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
# include "SivString.hpp"
# include "SivPointVector.hpp"
# include "SivRectangle.hpp"
# include "SivOptional.hpp"

namespace s3d
{
	/**
	*	@brief ウィンドウスタイル
	*/
	enum class WindowStyle
	{
		/**
		*	通常のウィンドウ
		*/
		Fixed = 0x3,

		/**
		*	サイズが変更可能なウィンドウ
		*/
		Sizeable = 0x7,

		/**
		*	フレームが無いウィンドウ
		*/
		NonFrame = 0x1,
	};

	/**
	*	@brief ウィンドウの状態
	*/
	struct WindowState
	{
		/**
		*	クライアント画面（描画可能域）の幅と高さ
		*/
		Point clientSize;

		/**
		*	枠線を含めたウィンドウの幅と高さ
		*/
		Point windowSize;

		/**
		*	スクリーンの幅と高さ
		*/
		Point screenSize;

		/**
		*	ウィンドウの左上の位置
		*/
		Point windowPos;

		/**
		*	ウィンドウの枠線の幅と高さ
		*/
		Point frameSize;

		/**
		*	ウィンドウのタイトルバーの高さ
		*/
		int titleBarHeight;

		/**
		*	スクリーンのタスクバーの矩形範囲
		*/
		Rect taskbarRect;

		/**
		*	スクリーンのタスクバーの位置（下: 0 左: 1 上: 2 右: 3)
		*/
		int taskbarPos;

		/**
		*	ウィンドウタイプ
		*/
		WindowStyle style;

		/**
		*	フルスクリーンモードか
		*/
		bool fullscreen;

		/**
		*	システムカーソルの表示が有効か
		*/
		bool showCursor;

		/**
		*	カーソルがクライアント画面（描画可能域）上にあるか
		*/
		bool cursorOnClient;

		/**
		*	カーソルがウィンドウ上にあるか
		*/
		bool cursorOnWindow;

		/**
		*	ウィンドウが最小化されているか
		*/
		bool minimized;

		/**
		*	ウィンドウが最大化されているか
		*/
		bool maximized;

		/**
		*	ウィンドウがアクティブか
		*/
		bool focused;

		/**
		*	ウィンドウが移動中か
		*/
		bool windowMoving;

		/**
		*	ウィンドウがサイズ変更中か
		*/
		bool windowSizing;

		/**
		*	ウィンドウのタイトル
		*/
		String windowTitle;
	};

	/**
	* @brief ウィンドウ
	*
	* ウィンドウの状態を管理します。
	*/
	namespace Window
	{
		/**
		*	ウィンドウの状態を返します。
		*	@return 現在のウィンドウの情報を格納した WindowState 構造体への参照
		*/
		const WindowState&
			GetState(
			);

		/**
		*	ウィンドウの左上の位置を返します。
		*	@return	 スクリーン座標系でのウィンドウの左上の位置
		*/
		Point
			GetPos(
			);

		/**
		*	ウィンドウがアクティブであるかを示します。
		*	@returnウィンドウがアクティブな場合 true, それ以外の場合は false
		*/
		bool
			Focused(
			);

		/**
		*	枠があるウィンドウであるかを示します。
		*	@return 枠があるウィンドウの場合 true, それ以外の場合は false
		*/
		bool
			Framed(
			);

		/**
		*	サイズが変更なウィンドウであるかを示します。
		*	@return サイズが変更なウィンドウの場合 true, それ以外の場合は false
		*/
		bool
			Sizeable(
			);

		/**
		*	ウィンドウモードであるかを示します。
		*	@return ウィンドウモードの場合 true, それ以外の場合は false
		*/
		bool
			Windowed(
			);

		/**
		*	フルスクリーンモードであるかを示します。
		*	@return フルスクリーンモードの場合 true, それ以外の場合は false
		*/
		bool
			IsFullSceen(
			);

		/**
		*	ウィンドウが最小化されているかを示します。
		*	@return ウィンドウが最小化されている場合 true, それ以外の場合は false
		*/
		bool
			Minimized(
			);

		/**
		*	ウィンドウが最大化されているかを示します。
		*	@return ウィンドウが最大化されている場合 true, それ以外の場合は false
		*/
		bool
			Maximized(
			);

		/**
		*	ウィンドウのタイトルを設定します。
		*	@param title タイトルにするテキスト
		*/
		void
			SetTitle(
			const String& title
			);

		/**
		*	ウィンドウのアイコンを設定します。
		*	@param title アイコンに設定する画像
		*/
		void
			SetIcon(
			const Image& image
			);

		/**
		*	カーソルの位置をクライアント座標上で変更します。
		*	@param x 新しいカーソルの x 座標
		*	@param y 新しいカーソルの y 座標
		*/
		void
			SetCursorPos(
			int x,
			int y
			);

		void
			SetCursorPos(
			const Point& pos
			);

		/**
		*	システムカーソルの表示 / 非表示を切り替えます。
		*	@param show システムカーソルを表示する場合は true, 表示しない場合は false
		*/
		void
			ShowCursor(
			bool show
			);

		/**
		*	カスタムカーソルを設定します。
		*	@param texture カスタムカーソルに設定するテクスチャ。設定を解除する場合は none を指定する
		*	@param center テクスチャ上のカーソル中心位置
		*/
		void
			SetCursorTexture(
			const optional<Texture>& texture,
			const Point& center = { 0, 0 }
		);

		/**
		*	カスタムカーソルを設定します。
		*	@param texture カスタムカーソルに設定するテクスチャ。設定を解除する場合は none を指定する
		*	@param center テクスチャ上のカーソル中心位置
		*/
		void
			SetCursorTextureRegion(
			const optional<TextureRegion>& texture,
			const Point& center = { 0, 0 }
			);

		/**
		*	ウィンドウの位置を変更します。
		*	@param x 新しいウィンドウ位置の x 座標
		*	@param y 新しいウィンドウ位置の y 座標
		*/
		void
			SetPos(
			int x,
			int y
			);

		/**
		*	ウィンドウの位置を変更します。
		*	@param pos 新しいウィンドウ位置の座標
		*/
		void
			SetPos(
			const Point& pos
			);

		/**
		*	ウィンドウを左上に移動します。
		*/
		void
			ToUpperLeft(
			);

		/**
		*	ウィンドウのサイズを変更します。
		*	@param width 新しいウィンドウのクライアント領域の幅
		*	@param height 新しいウィンドウのクライアント領域の高さ
		*/
		void
			Resize(
			int width,
			int height
			);

		/**
		*	ウィンドウのサイズを変更します。
		*	@param size 新しいウィンドウのクライアント領域のサイズ
		*/
		void
			Resize(
			const Point& size
			);

		/**
		*	ウィンドウを最小化します。
		*/
		void
			Minimize(
			);

		/**
		*	最小化、最大化されたウィンドウを元の大きさに戻します。
		*/
		void
			Restore(
			);

		/**
		*	ウィンドウを最大化します。
		*/
		void
			Maximize(
			);

		/**
		*	ウィンドウのクライアント領域のサイズを返します。
		*	@return ウィンドウのクライアント領域のサイズ
		*/
		Point
			Size(
			);

		/**
		*	ウィンドウのクライアント領域の中央の座標を返します。
		*	@return ウィンドウのクライアント領域の中央の座標
		*/
		Point
			Center(
			);

		/**
		*	ウィンドウのクライアント領域の幅を返します。
		*	@return ウィンドウのクライアント領域の幅
		*/
		int
			Width(
			);

		/**
		*	ウィンドウのクライアント領域の高さを返します。
		*	@return ウィンドウのクライアント領域の高さ
		*/
		int
			Height(
			);

		/**
		*	ウィンドウを中央に移動します。
		*/
		void
			Centering(
			);

		/**
		*	ウィンドウスタイルを変更します。
		*	@param style 新しいウィンドウスタイル
		*/
		void
			SetStyle(
			WindowStyle style
			);

		/**
		*	スクリーンモードを切り替えます。
		*	@param fullscreen フルスクリーンの場合 true, ウィンドウモードの場合 false
		*	@param size 新しい解像度
		*	@return 切り替えに成功した場合 true、失敗した場合は false
		*/
		bool
			SetFullscreen(
			bool fullscreen,
			const Point& size
			);
	}
}
