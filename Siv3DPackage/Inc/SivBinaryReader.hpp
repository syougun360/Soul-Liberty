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
# include "SivPropertyMacro.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief ÉoÉCÉiÉäì«Ç›çûÇ›
	*/
	class BinaryReader
	{
	private:

		class CBinaryReader;

		std::shared_ptr<CBinaryReader> pFile;

	public:

		/**
		*
		*/
		BinaryReader(
			);

		/**
		*
		*/
		~BinaryReader(
			);

		/**
		*
		*	@param path
		*/
		explicit
			BinaryReader(
			const FilePath& path
			);

		/**
		*
		*	@param path
		*	@return
		*/
		bool
			open(
			const FilePath& path
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
		*	@param dst
		*	@param size
		*	@return
		*/
		long long
			read(
			void* dst,
			long long size
			);

		/**
		*
		*	@return
		*/
		Blob
			read(
			);

		/**
		*
		*	@param size
		*	@return
		*/
		Blob
			read(
			size_t size
			);

		/**
		*
		*	@param pos
		*	@return
		*/
		long long
			setPos(
			long long pos
			);

		/**
		*
		*	@return
		*/
		long long
			getPos(
			);

		/**
		*
		*/
		Property_Get(long long, size) const;

		/**
		*
		*/
		Property_Get(FilePath, path) const;
	};
}
