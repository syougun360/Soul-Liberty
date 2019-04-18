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
# include "SivForward.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief ドラッグ・アンド・ドロップ
	*
	*	ドラッグ・アンド・ドロップされたアイテムを管理します。
	*/
	namespace Dragdrop
	{
		/**
		*	ドラッグ・アンド・ドロップが有効かどうかを取得します。
		*	@return ドラッグ・アンド・ドロップが有効な場合 true、それ以外の場合は false
		*/
		bool
			IsEnabled(
			);

		/**
		*	ドラッグ・アンド・ドロップの ON / OFF を切り替えます。
		*	@param enable ドラッグ・アンド・ドロップを有効にする場合 true、無効にする場合は false
		*	@note 直前にドロップされたアイテムがある状態でドラッグ・アンド・ドロップを無効に設定すると、そのドロップはキャンセルされます。
		*/
		void
			SetEnabled(
			bool enable
			);

		/**
		*	ドロップされたアイテムがあるかどうかを取得します。
		*	@return ドロップされたアイテムがある場合 true、それ以外の場合は false
		*/
		bool
			HasItems(
			);

		/**
		*	ドロップされたアイテムの一覧を取得します。
		*	@return ドロップされたすべてのアイテムのファイルパスが格納された vector
		*	@note 一度この関数が返したアイテムは、ドロップされたアイテム一覧から外されます。
		*/
		std::vector<FilePath>
			GetFilePaths(
			);

		/**
		*	アイテムが最後にドロップされた画面上の座標を取得します。
		*	@return アイテムが最後にドロップされた画面上の座標
		*/
		Point
			GetPos(
			);
	}
}
