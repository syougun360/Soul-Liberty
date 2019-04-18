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
# include "SivOptional.hpp"
# include "SivString.hpp"
# include "SivDate.hpp"

namespace s3d
{
	/**
	*	@brief ファイル作成時のオープンモード
	*
	*	書き込み用ファイル作成時に同名の既存ファイルがある場合の動作を示します。
	*/
	enum class OpenMode
	{
		/**
		*	同名のファイルが存在する場合、それを破棄する。
		*/
		Trunc,

		/**
		*	同名のファイルが存在する場合、それに追加書き込みする。
		*/
		Append,
	};

	/**
	*	@brief テキストファイルのエンコーディング形式
	*
	*	テキストファイルを扱うときに使用する文字エンコーディング形式を示します。
	*/
	enum class TextEncoding
	{
		/**
		*	ANSI
		*/
		ANSI,

		/**
		*	UTF-8
		*/
		UTF8,

		/**
		*	UTF-16 リトルエンディアン
		*/
		UTF16LE,

		/**
		*	UTF-16 ビッグエンディアン
		*/
		UTF16BE,

		/**
		*	デフォルト [UTF-8]
		*/
		Default = UTF8,
	};

	/**
	*	@brief ファイルコピー時の動作
	*
	*	ファイルをコピーする際の動作を示します。
	*/
	enum class CopyOption
	{
		/**
		*	ファイル名が既に使われていた場合、コピーを失敗させる。
		*/
		Fail_If_Exists,

		/**
		*	ファイル名が既に使われていた場合、ファイルを上書きする。
		*/
		Overwrite_If_Exists,
	};

	/**
	*	@brief ファイル操作
	*
	*	ファイルを操作します。
	*/
	namespace FileSystem
	{
		/**
		*	指定したパスのファイルまたはディレクトリが存在するかを返します。
		*	@param path パス
		*	@return 存在するかの真偽値
		*/
		bool
			Exists(
			const FilePath& path
			);

		/**
		*	指定したパスがディレクトリであるかを返します。
		*	@param path パス
		*	@return ディレクトリであるかの真偽値
		*/
		bool
			IsDirectory(
			const FilePath& path
			);

		/**
		*	指定したパスがファイルであるかを返します。
		*	@param path パス
		*	@return ファイルであるかの真偽値
		*/
		bool
			IsFile(
			const FilePath& path
			);

		/**
		*	指定したファイルかディレクトリが空であるかを返します。
		*	@param path パス
		*	@return 空であるかの真偽値
		*/
		bool
			IsEmpty(
			const FilePath& path
			);

		/**
		*	指定したファイルかディレクトリのサイズを返します。
		*	@param path パス
		*	@return サイズ
		*	@note ファイルやディレクトリが存在しなかったり、空である場合は 0 を返します。
		*/
		long long
			Size(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリの作成日時を返します。
		*	@param path パス
		*	@return 作成日時
		*/
		optional<Date>
			CreationTime(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリの更新日時を返します。
		*	@param path パス
		*	@return 更新日時
		*/
		optional<Date>
			WriteTime(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリのアクセス日時を返します。
		*	@param path パス
		*	@return アクセス日時
		*/

		optional<Date>
			AccessTime(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリ全体をコピーします。
		*	@param from コピー元のパス
		*	@param to コピー先のパス
		*	@param option 名前衝突時のふるまい
		*	@return 成功フラグ
		*/
		bool
			Copy(
			const FilePath& from,
			const FilePath& to,
			CopyOption option = CopyOption::Fail_If_Exists
			);

		/**
		*	ディレクトリを作成します。
		*	@param path パス
		*	@return 成功フラグ
		*/
		bool
			CreateDirectories(
			const FilePath& path
			);

		/**
		*	指定したパスまでの親ディレクトリを作成します。
		*	@param path パス
		*	@return 成功フラグ
		*/
		bool
			CreateParentDirectories(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリを削除します。
		*	@param path パス
		*	@return 成功フラグ
		*	@note ファイルが存在するディレクトリは削除できません。
		*/
		bool
			Remove(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリ全体を削除します。
		*	@param path パス
		*	@return 削除されたファイルの数
		*/
		size_t
			RemoveAll(
			const FilePath& path
			);

		/**
		*	ファイルまたはディレクトリの名前を変更します。
		*	@param from 変更前のパス
		*	@param to 変更後のパス
		*	@param option 名前衝突時のふるまい
		*	@return 成功した場合は true, 失敗した場合は false
		*/
		bool
			Rename(
			const FilePath& from,
			const FilePath& to,
			CopyOption option = CopyOption::Fail_If_Exists
			);

		/**
		*	ファイルまたはディレクトリを移動します。
		*	この関数は Rename() と同じです。
		*	@param from 移動前のパス
		*	@param to 移動後のパス
		*	@param option 名前衝突時のふるまい
		*	@return 成功した場合は true, 失敗した場合は false
		*/
		bool
			Move(
			const FilePath& from,
			const FilePath& to,
			CopyOption option = CopyOption::Fail_If_Exists
			);

		/**
		*	指定したファイルの .を含まない拡張子を小文字にして返します。（例: L"png"）
		*	@param path パス
		*	@return 小文字の拡張子。失敗した場合は空の文字列
		*/
		String
			Extension(
			const FilePath& path
			);

		/**
		*	指定したファイルの、親ディレクトリを含まずに、拡張子を含んだ名前を返します。（例: L"picture.png"）
		*	@param path パス
		*	@return ファイル名。失敗した場合は空の文字列
		*/
		String
			FileName(
			const FilePath& path
			);

		/**
		*	指定したファイルの、親ディレクトリと拡張子を含まない名前を返します。（例: L"picture"）
		*	@param path パス
		*	@return ファイル名。失敗した場合は空の文字列
		*/
		String
			BaseName(
			const FilePath& path
			);

		/**
		*	指定したファイルの親ディレクトリを返します。（例: L"C:\\Users\\Siv\\Desktop"）
		*	@param path パス
		*	@return 親ディレクトリ。失敗した場合は空の文字列
		*/
		FilePath
			ParentPath(
			const FilePath& path
			);

		/**
		*	指定したファイルの絶対パスを返します。（例: L"C:\\Users\\Siv\\Desktop\\picture.png"）
		*	@param path パス
		*	@return ファイルの絶対パス。失敗した場合は空の文字列
		*/
		FilePath
			FullPath(
			const FilePath& path
			);

		/**
		*	指定したディレクトリにあるファイルとディレクトリの一覧を返します。
		*	@param path パス
		*	@return ファイルとディレクトリの一覧
		*/
		std::vector<FilePath>
			DirectoryContents(
			const FilePath& path
			);

		/**
		*	プログラムが起動したパスを返します。
		*	@return プログラムが起動したパス
		*/
		FilePath
			InitialPath(
			);

		/**
		*	カレントパスを返します。
		*	@return カレントパス
		*/
		FilePath
			CurrentPath(
			);

		/**
		*	一時ファイル用のディレクトリのパスを返します。パスの末尾には L'\\' が付きます。
		*	@return 一時ファイル用のディレクトリのパス
		*/
		FilePath
			TemporaryPath(
			);

		/**
		*	一時ファイル用の固有なファイル名を返します。拡張子は L".tmp" です。
		*	@return 一時ファイル用のファイル名
		*/
		FilePath
			UniquePath(
			);

		/**
		*	ファイルがテキストファイルである場合、そのエンコーディング形式を返します。
		*	@param path パス
		*	@return テキストファイルのエンコーディング形式
		*/
		TextEncoding
			GetEncoding(
			const FilePath& path
			);
	}
}
