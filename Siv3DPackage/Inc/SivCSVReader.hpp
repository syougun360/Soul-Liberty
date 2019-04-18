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
# include <sstream>
# include <memory>
# include "SivForward.hpp"
# include "SivOptional.hpp"
# include "SivString.hpp"
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	@brief CSV �ǂݍ���
	*/
	class CSVReader
	{
	private:

		class CCSVReader;

		std::shared_ptr<CCSVReader> pFile;

		void
			_keyNotFound(
			unsigned r,
			unsigned c
			) const;

	public:

		/**
		*
		*/
		CSVReader(
			);

		/**
		*
		*/
		~CSVReader(
			);

		/**
		*
		*	@param path
		*/
		explicit
			CSVReader(
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
		bool
			hasChanged(
			) const;

		/**
		*
		*	@return
		*/
		bool
			reload(
			);

		/**
		*
		*	@return
		*/
		explicit operator bool(
			) const;

		/**
		*	�w�肵���s�̗񐔂�Ԃ��܂��B
		*	@param row �s
		*	@return �w�肵���s�̗�
		*/
		unsigned
			columns(
			unsigned row
			) const;

		/**
		*
		*	@param row
		*	@param column
		*	@param defaultValue
		*	@return
		*/
		template<typename Type>
		Type
			get(
			unsigned row,
			unsigned column,
			const Type& defaultValue = Type()
			) const
		{
			if (auto result = getOptional<Type>(row, column))
			{
				return result.get();
			}

			_keyNotFound(row, column);
			return defaultValue;
		}

		/**
		*
		*	@param row
		*	@param column
		*	@return
		*/
		optional<String>
			getString(
			unsigned row,
			unsigned column
			) const;

		/**
		*
		*	@param row
		*	@param column
		*	@return
		*/
		template<typename Type>
		optional<Type>
			getOptional(
			unsigned row,
			unsigned column
			) const
		{
			if (auto const item = getString(row, column))
			{
				Type to;

				if (std::wistringstream(item.get().str()) >> to)
				{
					return to;
				}
			}

			return none;
		}

		/**
		*
		*	@param row
		*	@param column
		*	@return
		*/
		template<>
		optional<bool>
			getOptional<bool>(
			unsigned row,
			unsigned column
			) const
		{
			if (auto const item = getString(row, column))
			{
				const String str = item.get().lower();

				if (str == L"true")
				{
					return true;
				}
				else if (str == L"false")
				{
					return false;
				}
			}

			return none;
		}

		/**
		*
		*	@param row
		*	@param column
		*	@return
		*/
		template<>
		optional<String>
			getOptional<String>(
			unsigned row,
			unsigned column
			) const
		{
			return getString(row, column);
		}

		/**
		*	CSV ���󂩂ǂ�����Ԃ��܂��B
		*	@return CSV ����̏ꍇ true, ����ȊO�� false
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*	�s����Ԃ��܂��B
		*	@return �s��
		*/
		Property_Get(unsigned, rows) const;

		/**
		*
		*/
		Property_Get(FilePath, path) const;
	};
}
