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
# include "SivFormat.hpp"

namespace s3d
{
	/**
	*	@brief テキスト書き込み
	*/
	class TextWriter
	{
	private:

		class CTextWriter;

		std::shared_ptr<CTextWriter> pFile;

	public:

		/**
		*
		*/
		TextWriter(
			);

		/**
		*
		*/
		~TextWriter(
			);

		/**
		*
		*	@param path
		*	@param encoding
		*/
		TextWriter(
			const FilePath& path,
			TextEncoding encoding
			);

		/**
		*
		*	@param path
		*	@param openMode
		*	@param encoding
		*/
		explicit
			TextWriter(
			const FilePath& path,
			OpenMode openMode = OpenMode::Trunc,
			TextEncoding encoding = TextEncoding::Default
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
			TextEncoding encoding
			);

		/**
		*
		*	@param path
		*	@param openMode
		*	@param encoding
		*	@return
		*/
		bool
			open(
			const FilePath& path,
			OpenMode openMode = OpenMode::Trunc,
			TextEncoding encoding = TextEncoding::Default
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
		*/
		void
			clear(
			);

		/**
		*
		*	@param ch
		*/
		void
			write(
			wchar_t ch
			);

		/**
		*
		*	@param ch
		*/
		void
			write(
			char ch
			) = delete;

		/**
		*
		*	@param str
		*/
		void
			write(
			const String& str
			);

		/**
		*
		*	@param str
		*/
		void
			write(
			const wchar_t* str
			);

		/**
		*
		*	@param args
		*/
		template<typename ... Args>
		void
			write(
			const Args& ... args
			)
		{
			write(Format(args...));
		}

		/**
		*
		*	@param il
		*/
		template<typename Type>
		void
			write(
			std::initializer_list<Type> il
			)
		{
			for (const auto& elem : il)
			{
				write(Format(elem));
			}
		}

		/**
		*
		*	@param ch
		*/
		void
			writeln(
			wchar_t ch
			);

		/**
		*
		*	@param ch
		*/
		void
			writeln(
			char ch
			) = delete;

		/**
		*
		*	@param str
		*/
		void
			writeln(
			const String& str
			);

		/**
		*
		*	@param str
		*/
		void
			writeln(
			const wchar_t* const str
			);

		/**
		*
		*	@param args
		*/
		template<typename ... Args>
		void
			writeln(
			const Args& ... args
			)
		{
			writeln(Format(args...));
		}

		/**
		*
		*	@param il
		*/
		template<typename Type>
		void
			writeln(
			std::initializer_list<Type> il
			)
		{
			for (const auto& elem : il)
			{
				writeln(Format(elem));
			}
		}

		/**
		*
		*/
		Property_Get(FilePath, path) const;
	};
}
