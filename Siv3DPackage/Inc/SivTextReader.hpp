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
# include "SivFileSystem.hpp"

namespace s3d
{
	/**
	*	@brief テキスト読み込み
	*/
	class TextReader
	{
	private:

		class CTextReader;

		std::shared_ptr<CTextReader> pFile;

	public:

		/**
		*
		*/
		TextReader(
			);

		/**
		*
		*/
		~TextReader(
			);

		/**
		*
		*	@param path
		*	@param encoding
		*/
		explicit
			TextReader(
			const FilePath& path,
			const optional<TextEncoding>& encoding = unspecified
			);

		/**
		*
		*	@param path
		*	@param encoding
		*	@return
		*/
		bool
			open(
			const FilePath& path,
			const optional<TextEncoding>& encoding = unspecified
			);

		/**
		*
		*/
		void
			close(
			);

		/**
		*
		*	@return
		*/
		bool
			isOpened(
			) const;

		/**
		*
		*	@return
		*/
		explicit operator bool(
			) const;

		/**
		*
		*	@return
		*/
		optional<wchar_t>
			readChar(
			);

		/**
		*
		*	@return
		*/
		optional<String>
			readLine(
			);

		/**
		*
		*	@return
		*/
		String
			readContents(
			);

		/**
		*
		*	@param ch
		*	@return
		*/
		bool
			readChar(
			wchar_t& ch
			);

		/**
		*
		*	@param str
		*	@return
		*/
		bool
			readLine(
			String& str
			);

		/**
		*
		*	@param str
		*	@return
		*/
		bool
			readContents(
			String& str
			);

		/**
		*
		*/
		Property_Get(FilePath, path) const;

		/**
		*
		*/
		Property_Get(TextEncoding, encoding) const;
	};
}
