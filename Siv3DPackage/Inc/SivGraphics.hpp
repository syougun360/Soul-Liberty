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
# include "SivPointVector.hpp"

namespace s3d
{
	namespace Graphics
	{
		/**
		*	背景色を設定します。
		*	@param color 背景色
		*/
		void
			SetBackground(
			const Color& color
			);

		/**
		*	draw された 2D アイテムを画面に書き込みます。
		*	通常は 3D レンダリングの後に 2D アイテムが自動でレンダリングされます。その順番を変える必要がある場合に使用してください。
		*/
		void
			Render2DBackground(
			);

		/**
		*	フルスクリーンモードにすることができる解像度の一覧を返します。
		*	これ以外の解像度を Window::SetFullscreen() に渡すと失敗します。
		*	@return フルスクリーンモードにすることができる解像度の一覧
		*/
		std::vector<Point>
			GetFullScreenSize(
			);

		/**
		*	現在のフレームのスクリーンショットを保存します。
		*	@note 実行ファイル/Screenshot/ フォルダに保存されます。
		*	撮影されたスクリーンショットは次のフレームで Graphics::ReceiveScreenCapture() を通して取得できます。
		*/
		void
			SaveScreenshot(
			);

		/**
		*	現在のフレームのスクリーンショットを保存します。
		*	@param path 保存するパス
		*	撮影されたスクリーンショットは次のフレームで Graphics::ReceiveScreenCapture() を通して取得できます。
		*/
		void
			SaveScreenshot(
			const FilePath& path
			);

		/**
		*	このフレームが終了したらスクリーンショットを撮影し、メモリ上に保存します。
		*	撮影されたスクリーンショットは次のフレームで Graphics::ReceiveScreenCapture() を通して取得できます。
		*/
		void
			RequestScreenCapture(
			);

		/**
		*	メモリ上に保存されたスクリーンショットを Image 形式で取得します。
		*	以前のフレームで Graphics::ReceiveScreenCapture()　が呼ばれていないといけません。
		*	@return 保存されているスクリーンショット、もしスクリーンショットが保存されていない場合は空のイメージ
		*/
		const s3d::Image&
			ReceiveScreenCapture(
			);
	}
}
