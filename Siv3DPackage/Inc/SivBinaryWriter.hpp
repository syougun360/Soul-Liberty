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
# include <array>
# include <initializer_list>
# include "SivForward.hpp"
# include "SivPropertyMacro.hpp"
# include "SivString.hpp"
# include "SivFileSystem.hpp"
# include "SivBlob.hpp"
# include "SivUtility.hpp"

namespace s3d
{
	/**
	*	@brief バイナリ書き込み
	*/
	class BinaryWriter
	{
	private:

		class CBinaryWriter;

		std::shared_ptr<CBinaryWriter> pFile;

	public:

		/**
		*
		*/
		BinaryWriter(
			);

		/**
		*
		*/
		~BinaryWriter(
			);

		/**
		*	書き込み用のバイナリファイルを開きます。
		*	@param path ファイル名
		*	@param mode オープンモード
		*/
		explicit
			BinaryWriter(
			const FilePath& path,
			OpenMode mode = OpenMode::Trunc
			);

		/**
		*	書き込み用のバイナリファイルを開きます。
		*	@param path ファイル名
		*	@param mode オープンモード
		*	@return ファイルを開けたら true, それ以外の場合は false
		*/
		bool
			open(
			const FilePath& path,
			OpenMode mode = OpenMode::Trunc
			);

		/**
		*	書き込み用のバイナリファイルを閉じます。
		*/
		void
			close(
			);

		/**
		*	ファイルが開かれているかを返します。
		*	@return ファイルが開かれていたら true, それ以外の場合は false
		*/
		bool
			isOpened(
			) const;

		/**
		*	ファイルが開かれているかを返します。
		*	@return ファイルが開かれていたら true, それ以外の場合は false
		*/
		explicit operator bool(
			) const;

		/**
		*	現在開いているファイルの内容を消去します。
		*/
		void
			clear(
			);

		/**
		*	現在開いているファイルにデータを書きこみます。
		*	@param src 書きこむデータの先頭ポインタ
		*	@param size 書きこむデータのサイズ（バイト）
		*	@return 書きこんだデータのサイズ（バイト）
		*/
		long long
			write(
			const void* src,
			long long size
			);

		/**
		*
		*	@param src
		*	@return
		*/
		long long
			write(
			const Blob& src
			)
		{
			return write(src.data(), src.size);
		}

		/**
		*
		*	@param src
		*	@param size
		*	@return
		*/
		long long
			write(
			const Blob& src,
			long long size
			)
		{
			return write(src.data(), Min<long long>(size, src.size));
		}

		/**
		*
		*	@param src
		*	@return
		*/
		template<typename Type>
		long long
			write(
			const Type& src
			)
		{
			static_assert(std::is_pod<Type>::value, "Type must be POD");
			return write(&src, sizeof(Type));
		}

		/**
		*
		*	@param src
		*	@return
		*/
		template<typename Type, size_t Size>
		long long
			write(
			const std::array<Type, Size>& src
			)
		{
			static_assert(std::is_pod<Type>::value, "Type must be POD");
			return src.empty() ? 0 : write(src.data(), Size*sizeof(Type));
		}

		/**
		*
		*	@param il
		*	@return
		*/
		template<typename Type>
		long long
			write(
			std::initializer_list<Type> il
			)
		{
			static_assert(std::is_pod<Type>::value, "Type must be POD");
			
			long long result = 0;

			for (const auto& elem : il)
			{
				result += write(elem);
			}
			
			return result;
		}

		/**
		*
		*	@param src
		*	@return
		*/
		template<typename Type>
		long long
			write(
			const std::vector<Type>& src
			)
		{
			static_assert(std::is_pod<Type>::value, "Type must be POD");
			return src.empty() ? 0 : write(src.data(), static_cast<long long>(src.size())*sizeof(Type));
		}

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
			seekEnd(
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
		Property_Get(FilePath, path) const;
	};
}
