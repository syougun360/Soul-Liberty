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
# include "SivForward.hpp"

namespace s3d
{
	/**
	*	@brief Web カメラ
	*
	*	Web カメラを扱います。
	*/
	namespace Webcam
	{
		/**
		*	Web カメラによる撮影を開始します。
		*	@return Web カメラの起動に成功した場合 true、それ以外の場合は false
		*/
		bool
			Start(
			);

		/**
		*	Web カメラによる撮影を終了します。
		*/
		void
			Stop(
			);

		/**
		*	Web カメラがアクティブかどうかを示します。
		*	@return Web カメラが撮影中である場合 true、それ以外の場合は false
		*/
		bool
			IsActive(
			);

		/**
		*	Web カメラがフレームを更新したかどうかを示します。
		*	@return 新しいフレームがある場合 true、それ以外の場合は false
		*	@note GetFrame() すると、最新のフレームがコピーされ、
		*	次に新しい画像が撮影されるまで HasNewFrame() は false を返します。
		*/
		bool
			HasNewFrame(
			);

		/**
		*	Web カメラの最新のフレームを取得します。
		*	@param image 読み込み先の画像への参照
		*	@return 画像の取得に成功した場合 true、それ以外の場合は false
		*/
		bool
			GetFrame(
			Image& image
			);

		/**
		*	Web カメラの最新のフレームを取得します。
		*	@param tex 読み込み先のテクスチャへの参照
		*	@return テクスチャの取得に成功した場合 true、それ以外の場合は false
		*/
		bool
			GetFrame(
			DynamicTexture& tex
			);
	}
}