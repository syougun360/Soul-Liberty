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
# include "SivFileSystem.hpp"

namespace s3d
{
	/**
	*	@brief 拡張子フィルタ
	*
	*	ファイルダイアログで検索する拡張子を指定します。
	*/
	enum class ExtensionFilter
	{
		BMP,
		
		PNG,
		
		JPEG,
		
		GIF,
		
		TGA,
		
		DDS,
		
		WebP,
		
		JPEG2000,
		
		TIFF,
		
		PPM,

		/**
		*	基本的な画像形式（BMP, PNG, JPEG, GIF）
		*/
		BasicImage,
		
		/**
		*	すべての画像形式
		*/
		AllImage,

		WAVE,
		
		MP3,
		
		OggVorbis,
		
		AAC,
		
		WMA,

		/**
		*	基本的なサウンド形式（Wave, OggVorbis, MP3）
		*/
		BasicSound,

		/**
		*	すべてのサウンド形式
		*/
		AllSound,

		MIDI,

		Text,
		
		INI,
		
		XML,
		
		CSV,
		
		AVI,

		All,
	};

	struct ExtensionFilterPair
	{
		String description, pattern;

		ExtensionFilterPair(ExtensionFilter type);

		ExtensionFilterPair(const String& _description, const String& _pattern);
	};

	struct FontProperty
	{
		FontProperty(const String& _name = L"Meiryo", int _size = 16)
		: name(_name), size{ _size }{}

		String name;

		int size;
	};

	/**
	*	@brief ダイアログ
	*
	*	ファイルダイアログの機能です。
	*/
	namespace Dialog
	{
		/**
		*	指定した形式のファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param filters 検索するファイル形式のフィルタ
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択したテキストファイル名、キャンセルされたか、filter が無効の場合 none
		*	@note フィルタの例:
		*		PNG ファイルのみ		{ ExtensionFilter::PNG }
		*		PNG / JPEG ファイル	{ ExtensionFilter::PNG, ExtensionFilter::JPEG }
		*		HTML ファイル			{ { L"HTML ファイル (*.html;*.htm)", L"*.html;*.htm" } }
		*		独自の拡張子 (.aaa)	{ { L"説明 (*.aaa)", L"*.aaa" } }
		*		独自の拡張子 (.aaa) と (.bbb)	{ { L"説明 (*.aaa)", L"*.aaa" }, { L"説明 (*.bbb)", L"*.bbb" }}
		*/
		optional<FilePath>
			GetOpen(
			const std::vector<ExtensionFilterPair>& filters,
			const String& title = L"開く"
			);

		/**
		*
		*	@param filters
		*	@param title
		*	@return
		*	@note フィルタの例:
		*		PNG ファイルのみ		{ ExtensionFilter::PNG }
		*		PNG / JPEG ファイル	{ ExtensionFilter::PNG, ExtensionFilter::JPEG }
		*		HTML ファイル			{ { L"HTML ファイル (*.html;*.htm)", L"*.html;*.htm" } }
		*		独自の拡張子 (.aaa)	{ { L"説明 (*.aaa)", L"*.aaa" } }
		*		独自の拡張子 (.aaa) と (.bbb)	{ { L"説明 (*.aaa)", L"*.aaa" }, { L"説明 (*.bbb)", L"*.bbb" }}
		*/
		optional<FilePath>
			GetSave(
			const std::vector<ExtensionFilterPair>& filters,
			const String& title = L"名前をつけて保存"
			);

		/**
		*	BMP, PNG, JPEG, GIF 画像ファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択した画像ファイル名、キャンセルされた場合 none
		*/
		inline
		optional<FilePath>
			GetOpenBasicImage(
			const String& title = L"開く"
			);

		/**
		*	すべての形式の画像ファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択した画像ファイル名、キャンセルされた場合 none
		*/
		inline
		optional<FilePath>
			GetOpenImage(
			const String& title = L"開く"
			);

		/**
		*	サウンドファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択したサウンドファイル名、キャンセルされた場合 none
		*/
		inline
		optional<FilePath>
			GetOpenSound(
			const String& title = L"開く"
			);

		/**
		*	MIDI ファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択したサウンドファイル名、キャンセルされた場合 none
		*/
		inline
			optional<FilePath>
			GetOpenMidi(
			const String& title = L"開く"
			);

		/**
		*	テキストファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択したテキストファイル名、キャンセルされた場合 none
		*/
		inline
		optional<FilePath>
			GetOpenText(
			const String& title = L"開く"
			);

		/**
		*	全ての形式のファイルをオープンファイルダイアログから選択させ、そのファイル名を返します。
		*	@param title ダイアログのタイトル、デフォルトでは「開く」
		*	@return 選択したテキストファイル名、キャンセルされた場合 none
		*/
		inline
		optional<FilePath>
			GetOpenAll(
			const String& title = L"開く"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveBasicImage(
			const String& title = L"名前をつけて保存"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveImage(
			const String& title = L"名前をつけて保存"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveSound(
			const String& title = L"名前をつけて保存"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveText(
			const String& title = L"名前をつけて保存"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
			optional<FilePath>
			GetSaveVideo(
			const String& title = L"名前をつけて保存"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveAll(
			const String& title = L"名前をつけて保存"
			);

		/**
		*
		*	@return
		*/
		optional<Color>
			GetColor(
			);

		/**
		*
		*	@param defaultColor
		*	@return
		*/
		Color
			GetColor(
			const Color& defaultColor
			);

		/**
		*
		*	@param initialPath デフォルトで選択されているフォルダのパス
		*	@return
		*/
		optional<FilePath>
			GetFolder(
			const FilePath& initialPath = FileSystem::InitialPath()
			);

		/**
		*
		*	@return
		*/
		optional<FontProperty>
			GetFont(
			);

		/**
		*
		*	@param defaultFont
		*	@return
		*/
		FontProperty
			GetFont(
			const FontProperty& defaultFont
			);

		/**
		*
		* @param title
		* @return
		*/
		Image
			OpenBasicImage(
			const String& title = L"開く"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Image
			OpenImage(
			const String& title = L"開く"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Texture
			OpenBasicTexture(
			const String& title = L"開く"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Texture
			OpenTexture(
			const String& title = L"開く"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Wave
			OpenSoundAsWave(
			const String& title = L"開く"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Sound
			OpenSound(
			const String& title = L"開く"
			);
	}
}

# include "SivDialog.inl"
