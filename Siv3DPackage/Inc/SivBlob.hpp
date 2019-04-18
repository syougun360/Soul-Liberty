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
# include "SivPropertyMacro.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief バイナリオブジェクト
	*
	*	様々な大きさのデータを保持するバイナリオブジェクトです。
	*/
	class Blob
	{
	private:

		std::vector<unsigned char> m_data;

	public:

		/**
		*	空のバイナリオブジェクトを作成します。
		*/
		Blob(
			);

		/**
		*	指定されたバイナリオブジェクトのコピーを作成します。
		*	@param blob コピーするバイナリオブジェクト
		*/
		Blob(
			const Blob& blob
			);

		/**
		*	指定されたバイナリオブジェクトをムーブして初期化します。
		*	@param blob ムーブするバイナリオブジェクト
		*/
		Blob(
			Blob && blob
			);

		/**
		*	指定されたサイズのバイナリオブジェクトを作成します。
		*	@param size 初期サイズ（バイト）
		*	@note データはすべて 0 で初期化されます。
		*/
		explicit
			Blob(
			size_t size
			);

		/**
		*	指定されたファイルの内容をコピーしたバイナリオブジェクトを作成します。
		*	@param path ファイル名
		*/
		explicit
			Blob(
			const FilePath& path
			);

		/**
		*	指定されたポインタからデータをコピーしたバイナリオブジェクトを作成します。
		*	@param data コピーするデータの先頭ポインタ
		*	@param size コピーするサイズ（バイト）
		*/
		Blob(
			const void* const data,
			size_t size
			);

		/**
		*	指定されたデータのコピーを作成します。
		*	@param data コピーするデータ
		*/
		explicit
			Blob(
			const std::vector<unsigned char>& data
			);

		/**
		*	指定されたデータをムーブしてバイナリオブジェクトを作成します。
		*	@param data ムーブするデータ
		*/
		explicit
			Blob(
			std::vector<unsigned char> && data
			);

		/**
		*	指定されたデータで初期化します。
		*	@param blob コピーするデータ
		*	@return *this
		*/
		Blob &
			operator = (
			const Blob& blob
			);

		/**
		*	指定されたデータをムーブして初期化します。
		*	@param blob ムーブするデータ
		*	@return *this
		*/
		Blob &
			operator = (
			Blob && blob
			);

		/**
		*	保持しているデータを消去し、使用しているメモリを解放します。
		*/
		void
			free(
			);

		/**
		*	保持しているデータのサイズを変更します。
		*	@param size 新しいサイズ（バイト）
		*	@note サイズを縮小した場合、保持していた末尾のデータは失われます。
		*	サイズを拡大した場合、新しいデータは 0 で初期化されます。
		*/
		void
			resize(
			size_t size
			);

		/**
		*	データの内容を交換します。
		*	@param blob 交換する相手
		*/
		void
			swap(
			Blob && blob
			);

		/**
		*	保持しているデータのサイズを返します。
		*	@return 保持しているデータのサイズ
		*/
		Property_Get(size_t, size) const;

		/**
		*	データを保持しているかどうかを返します。
		*	@return データを保持していない場合 true, 保持している場合 false
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*	データをコピーし、新しいバイナリオブジェクトを作成します。
		*	@return 新しいコピー
		*/
		Blob
			clone(
			) const;

		/**
		*	データのポインタを返します。
		*	@return 保持しているデータの先頭ポインタ、空の場合は nullptr
		*/
		void*
			data(
			);

		/**
		*	データのポインタを返します。
		*	@return 保持しているデータの先頭ポインタ、空の場合は nullptr
		*/
		const void*
			data(
			) const;

		/**
		*	データのポインタを返します。
		*	@return 保持しているデータの先頭ポインタ、空の場合は nullptr
		*/
		unsigned char*
			dataU8(
			);

		/**
		*	データのポインタを返します。
		*	@return 保持しているデータの先頭ポインタ、空の場合は nullptr
		*/
		const unsigned char*
			dataU8(
			) const;

		/**
		*	データを保持しているかどうかを返します。
		*	@return データを保持している場合 true, 保持していない場合は false
		*/
		explicit operator bool(
			) const;

		/**
		*	データをファイルに保存します。
		*	@param path 保存するファイルの名前
		*	@return データの保存に成功した場合 true, 失敗した場合 false
		*	@note データが空の場合、サイズが 0 のファイルを作成し、true を返します。
		*/
		bool
			save(
			const FilePath& path
			) const;
	};
}
