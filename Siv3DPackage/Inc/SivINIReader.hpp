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
# include <sstream>
# include "SivOptional.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief INI 読み込み
	*/
	class INIReader
	{
	private:

		class CINIReader;

		std::shared_ptr<CINIReader> pFile;

		void
			_keyNotFound(
			const String& key
			) const;

	public:

		/**
		*
		*/
		INIReader(
			);

		/**
		*	INI ファイルからプロパティツリーを作成します。
		*	@param path INI ファイル名
		*/
		INIReader(
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
		*
		*	@param key
		*	@param defaultValue
		*	@return
		*	@note L"PARAMETER" または L"SECTION.PARAMETER" で要素にアクセスする
		*/
		template<typename Type>
		Type
			get(
			const String& key,
			const Type& defaultValue = Type()
			) const
		{
			if (auto result = getOptional<Type>(key))
			{
				return result.get();
			}

			_keyNotFound(key);
			return defaultValue;
		}

		/**
		*
		*	@param key
		*	@return
		*/
		optional<String>
			getString(
			const String& key
			) const;

		/**
		*
		*	@param key
		*	@return
		*/
		template<typename Type>
		optional<Type>
			getOptional(
			const String& key
			) const
		{
			if (auto const item = getString(key))
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
		*	@param key
		*	@return
		*/
		template<>
		optional<bool>
			getOptional<bool>(
			const String& key
			) const
		{
			if (auto const item = getString(key))
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
		*	@param key
		*	@return
		*/
		template<>
		optional<String>
			getOptional<String>(
			const String& key
			) const
		{
			return getString(key);
		}

		/**
		*	プロパティツリーが空かどうかを返します。
		*	@return プロパティツリーが空の場合 true, それ以外は false
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*
		*/
		Property_Get(FilePath, path) const;
	};
}
