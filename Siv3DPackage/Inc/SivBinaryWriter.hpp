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
	*	@brief �o�C�i����������
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
		*	�������ݗp�̃o�C�i���t�@�C�����J���܂��B
		*	@param path �t�@�C����
		*	@param mode �I�[�v�����[�h
		*/
		explicit
			BinaryWriter(
			const FilePath& path,
			OpenMode mode = OpenMode::Trunc
			);

		/**
		*	�������ݗp�̃o�C�i���t�@�C�����J���܂��B
		*	@param path �t�@�C����
		*	@param mode �I�[�v�����[�h
		*	@return �t�@�C�����J������ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			open(
			const FilePath& path,
			OpenMode mode = OpenMode::Trunc
			);

		/**
		*	�������ݗp�̃o�C�i���t�@�C������܂��B
		*/
		void
			close(
			);

		/**
		*	�t�@�C�����J����Ă��邩��Ԃ��܂��B
		*	@return �t�@�C�����J����Ă����� true, ����ȊO�̏ꍇ�� false
		*/
		bool
			isOpened(
			) const;

		/**
		*	�t�@�C�����J����Ă��邩��Ԃ��܂��B
		*	@return �t�@�C�����J����Ă����� true, ����ȊO�̏ꍇ�� false
		*/
		explicit operator bool(
			) const;

		/**
		*	���݊J���Ă���t�@�C���̓��e���������܂��B
		*/
		void
			clear(
			);

		/**
		*	���݊J���Ă���t�@�C���Ƀf�[�^���������݂܂��B
		*	@param src �������ރf�[�^�̐擪�|�C���^
		*	@param size �������ރf�[�^�̃T�C�Y�i�o�C�g�j
		*	@return �������񂾃f�[�^�̃T�C�Y�i�o�C�g�j
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
