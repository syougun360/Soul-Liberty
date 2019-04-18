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
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief メッセージダイジェスト 
	*
	*	データから暗号学的ハッシュ値を返す機能です。
	*/
	namespace MessageDigest
	{
		/**
		*
		*	@param blob
		*	@return
		*/
		String
			MD5(
			const Blob& blob
			);

		/**
		*
		*	@param data
		*	@param size
		*	@return
		*/
		String
			MD5(
			const void* const data,
			size_t size
			);

		/**
		*
		*	@param str
		*	@return
		*/
		String
			MD5FromString(
			const StringRef& str
			);

		/**
		*
		*	@param path
		*	@return
		*/
		String
			MD5FromFile(
			const FilePath& path
			);
	};
}
