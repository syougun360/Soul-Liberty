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
# include <string>
# include "SivForward.hpp"

namespace s3d
{
	/**
	*	@brief Base64 エンコード/デコード
	*
	*	Base64 方式でのエンコード/デコードのための機能です。
	*/
	namespace Base64
	{
		/**
		*	データバイナリオブジェクトを Base64 エンコードします。
		*	@param blob エンコードするデータ
		*	@return エンコードされたテキストデータ
		*/
		String
			Encode(
			const Blob& blob
			);

		/**
		*	データを Base64 エンコードします。
		*	@param data エンコードするデータの先頭ポインタ
		*	@param size エンコードするデータのサイズ（バイト）
		*	@return エンコードされたテキストデータ
		*/
		String
			Encode(
			const void* const data,
			size_t size
			);

		/**
		*	テキストを Base64 でデコードします。
		*	@param src デコードするテキスト
		*	@return デコードされたバイナリオブジェクト
		*/
		Blob
			Decode(
			const String& src
			);

		/**
		*	テキストを Base64 でデコードします。
		*	@param src デコードするテキスト
		*	@return デコードされたバイナリオブジェクト
		*/
		Blob
			Decode(
			const std::string& src
			);
	};
}
