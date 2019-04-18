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
# include <memory>
# include "SivForward.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief AVI の圧縮方式
	*/
	enum class VideoCompression
	{
		/**
		*	Microsoft Video 1 | Quality 0
		*/
		MSV1_Low,

		/**
		*	Microsoft Video 1 | Quality 50
		*/
		MSV1_Medium,

		/**
		*	Microsoft Video 1 | Quality 75
		*/
		MSV1_High,

		/**
		*	Microsoft Video 1 | Quality 100
		*/
		MSV1_Ultra,

		/**
		*	Intel Indeo
		*/
		Indeo,

		/**
		*	Cinepak
		*/
		Cinepak,

		/**
		*	非圧縮
		*/
		Uncompressed,
	};

	/**
	*	@brief 動画出力
	*/
	class VideoWriter
	{
	private:

		class CVideoWriter;

		std::shared_ptr<CVideoWriter> pWriter;

	public:

		VideoWriter();

		/**
		*	動画を書き込むファイルを開く。
		*	@param path 作成する動画のファイルパス
		*	@param width 動画の解像度 X
		*	@param height 動画の解像度 Y
		*	@param videoCompression AVI の圧縮方式
		*	@param frameTime フレームの間隔。 { a, b } で、 b/a[Hz]
		*/
		VideoWriter(
			const FilePath& path,
			int width,
			int height,
			VideoCompression videoCompression = VideoCompression::MSV1_High,
			const std::pair<int, int>& frameTime = { 1, 30 }
			);

		/**
		*	動画の作成を終了し、保存する。
		*/
		~VideoWriter();

		/**
		*	動画を書き込むファイルを開く。
		*	@param path 作成する動画のファイルパス
		*	@param width 動画の解像度 X
		*	@param height 動画の解像度 Y
		*	@param videoCompression AVI のフォーマット
		*	@param frameTime フレームの間隔。 { a, b } で、 b/a[Hz]
		*	@return 成功したら true, 失敗したら false
		*/
		bool
		open(
			const FilePath& path,
			int width,
			int height,
			VideoCompression videoCompression = VideoCompression::MSV1_High,
			const std::pair<int, int>& frameTime = { 1, 30 }
			);

		/**
		*	動画を書き込むファイルが開かれているかを返します。
		*	@return ファイルが開かれていたら true, それ以外の場合は false
		*/
		bool
			isOpened(
			) const;

		/**
		*	動画を書き込むファイルが開かれているかを返します。
		*	@return ファイルが開かれていたら true, それ以外の場合は false
		*/
		explicit operator bool(
			) const;

		/**
		*	動画にフレームを追加する。
		*	@param image 動画と同じ大きさの画像
		*	@return フレームの追加に成功したら true, 失敗したら false
		*/
		bool
		write(
			const Image& image
			);

		/**
		*	動画にフレームを追加する。
		*	@param image 動画に追加する画像
		*	@param offset 画像のオフセット、画像をはみ出た場合 backgroundColor で塗りつぶされる
		*	@param backgroundColor 画像をはみ出た部分を塗りつぶす色
		*	@return フレームの追加に成功したら true, 失敗したら false
		*/
		bool
		write(
			const Image& image,
			const Point& offset,
			const Color& backgroundColor = Palette::Black
			);

		/**
		*	動画の作成を終了し、保存する。
		*	@return フレームの追加に成功したら true, 失敗したら false
		*	@notice 新しい動画を作成するには、再度 open() する必要があります。
		*/
		bool
		close(
			);
	};
}
