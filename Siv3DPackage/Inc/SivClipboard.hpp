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
	*	@brief クリップボードのデータの種類
	*/
	enum class ClipboardItemType
	{
		/**
		*	何もコピーされていない
		*/
		None,

		/**
		*	テキスト
		*/
		Text,

		/**
		*	画像
		*/
		Image,

		/**
		*	1 つ以上のファイルパス
		*/
		FilePath
	};

	/**
	* @brief クリップボード
	*
	* クリップボードの内容を管理します。
	*/
	namespace Clipboard
	{
		/**
		*	クリップボードにコピーされているデータの種類を返します。
		*	@return クリップボードにコピーされているデータの種類
		*/
		ClipboardItemType
			GetType(
			);

		/**
		*	クリップボードにコピーされているテキストを返します。
		*	@return クリップボードにコピーされている文字列、クリップボードに文字列がない場合空の文字列
		*/
		String
			GetText(
			);

		/**
		*	クリップボードにコピーされている画像を返します。
		*	@return クリップボードにコピーされている画像、クリップボードに画像がない場合空の画像
		*/
		Image
			GetImage(
			);

		/**
		*	クリップボードにコピーされているファイルパスの一覧を返します。
		*	@return クリップボードにコピーされているファイルパスの一覧
		*/
		std::vector<FilePath>
			GetFilePaths(
			);

		/**
		*	テキストをクリップボードにコピーします。
		*	@param str クリップボードにコピーするテキスト
		*/
		void
			SetText(
			const String& str
			);

		/**
		*	画像をクリップボードにコピーします。
		*	@param img クリップボードにコピーする画像
		*/
		void
			SetImage(
			const Image& image
			);

		/**
		*	クリップボードの中身を空にします。
		*/
		void
			Clear(
			);
	}
}
