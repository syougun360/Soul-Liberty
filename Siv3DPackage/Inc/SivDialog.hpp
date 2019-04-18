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
	*	@brief �g���q�t�B���^
	*
	*	�t�@�C���_�C�A���O�Ō�������g���q���w�肵�܂��B
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
		*	��{�I�ȉ摜�`���iBMP, PNG, JPEG, GIF�j
		*/
		BasicImage,
		
		/**
		*	���ׂẲ摜�`��
		*/
		AllImage,

		WAVE,
		
		MP3,
		
		OggVorbis,
		
		AAC,
		
		WMA,

		/**
		*	��{�I�ȃT�E���h�`���iWave, OggVorbis, MP3�j
		*/
		BasicSound,

		/**
		*	���ׂẴT�E���h�`��
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
	*	@brief �_�C�A���O
	*
	*	�t�@�C���_�C�A���O�̋@�\�ł��B
	*/
	namespace Dialog
	{
		/**
		*	�w�肵���`���̃t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param filters ��������t�@�C���`���̃t�B���^
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������e�L�X�g�t�@�C�����A�L�����Z�����ꂽ���Afilter �������̏ꍇ none
		*	@note �t�B���^�̗�:
		*		PNG �t�@�C���̂�		{ ExtensionFilter::PNG }
		*		PNG / JPEG �t�@�C��	{ ExtensionFilter::PNG, ExtensionFilter::JPEG }
		*		HTML �t�@�C��			{ { L"HTML �t�@�C�� (*.html;*.htm)", L"*.html;*.htm" } }
		*		�Ǝ��̊g���q (.aaa)	{ { L"���� (*.aaa)", L"*.aaa" } }
		*		�Ǝ��̊g���q (.aaa) �� (.bbb)	{ { L"���� (*.aaa)", L"*.aaa" }, { L"���� (*.bbb)", L"*.bbb" }}
		*/
		optional<FilePath>
			GetOpen(
			const std::vector<ExtensionFilterPair>& filters,
			const String& title = L"�J��"
			);

		/**
		*
		*	@param filters
		*	@param title
		*	@return
		*	@note �t�B���^�̗�:
		*		PNG �t�@�C���̂�		{ ExtensionFilter::PNG }
		*		PNG / JPEG �t�@�C��	{ ExtensionFilter::PNG, ExtensionFilter::JPEG }
		*		HTML �t�@�C��			{ { L"HTML �t�@�C�� (*.html;*.htm)", L"*.html;*.htm" } }
		*		�Ǝ��̊g���q (.aaa)	{ { L"���� (*.aaa)", L"*.aaa" } }
		*		�Ǝ��̊g���q (.aaa) �� (.bbb)	{ { L"���� (*.aaa)", L"*.aaa" }, { L"���� (*.bbb)", L"*.bbb" }}
		*/
		optional<FilePath>
			GetSave(
			const std::vector<ExtensionFilterPair>& filters,
			const String& title = L"���O�����ĕۑ�"
			);

		/**
		*	BMP, PNG, JPEG, GIF �摜�t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������摜�t�@�C�����A�L�����Z�����ꂽ�ꍇ none
		*/
		inline
		optional<FilePath>
			GetOpenBasicImage(
			const String& title = L"�J��"
			);

		/**
		*	���ׂĂ̌`���̉摜�t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������摜�t�@�C�����A�L�����Z�����ꂽ�ꍇ none
		*/
		inline
		optional<FilePath>
			GetOpenImage(
			const String& title = L"�J��"
			);

		/**
		*	�T�E���h�t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������T�E���h�t�@�C�����A�L�����Z�����ꂽ�ꍇ none
		*/
		inline
		optional<FilePath>
			GetOpenSound(
			const String& title = L"�J��"
			);

		/**
		*	MIDI �t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������T�E���h�t�@�C�����A�L�����Z�����ꂽ�ꍇ none
		*/
		inline
			optional<FilePath>
			GetOpenMidi(
			const String& title = L"�J��"
			);

		/**
		*	�e�L�X�g�t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������e�L�X�g�t�@�C�����A�L�����Z�����ꂽ�ꍇ none
		*/
		inline
		optional<FilePath>
			GetOpenText(
			const String& title = L"�J��"
			);

		/**
		*	�S�Ă̌`���̃t�@�C�����I�[�v���t�@�C���_�C�A���O����I�������A���̃t�@�C������Ԃ��܂��B
		*	@param title �_�C�A���O�̃^�C�g���A�f�t�H���g�ł́u�J���v
		*	@return �I�������e�L�X�g�t�@�C�����A�L�����Z�����ꂽ�ꍇ none
		*/
		inline
		optional<FilePath>
			GetOpenAll(
			const String& title = L"�J��"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveBasicImage(
			const String& title = L"���O�����ĕۑ�"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveImage(
			const String& title = L"���O�����ĕۑ�"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveSound(
			const String& title = L"���O�����ĕۑ�"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveText(
			const String& title = L"���O�����ĕۑ�"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
			optional<FilePath>
			GetSaveVideo(
			const String& title = L"���O�����ĕۑ�"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		inline
		optional<FilePath>
			GetSaveAll(
			const String& title = L"���O�����ĕۑ�"
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
		*	@param initialPath �f�t�H���g�őI������Ă���t�H���_�̃p�X
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
			const String& title = L"�J��"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Image
			OpenImage(
			const String& title = L"�J��"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Texture
			OpenBasicTexture(
			const String& title = L"�J��"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Texture
			OpenTexture(
			const String& title = L"�J��"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Wave
			OpenSoundAsWave(
			const String& title = L"�J��"
			);

		/**
		*
		*	@param title
		*	@return
		*/
		Sound
			OpenSound(
			const String& title = L"�J��"
			);
	}
}

# include "SivDialog.inl"
