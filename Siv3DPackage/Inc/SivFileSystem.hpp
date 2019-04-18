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
	*	@brief �t�@�C���쐬���̃I�[�v�����[�h
	*
	*	�������ݗp�t�@�C���쐬���ɓ����̊����t�@�C��������ꍇ�̓���������܂��B
	*/
	enum class OpenMode
	{
		/**
		*	�����̃t�@�C�������݂���ꍇ�A�����j������B
		*/
		Trunc,

		/**
		*	�����̃t�@�C�������݂���ꍇ�A����ɒǉ��������݂���B
		*/
		Append,
	};

	/**
	*	@brief �e�L�X�g�t�@�C���̃G���R�[�f�B���O�`��
	*
	*	�e�L�X�g�t�@�C���������Ƃ��Ɏg�p���镶���G���R�[�f�B���O�`���������܂��B
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
		*	UTF-16 ���g���G���f�B�A��
		*/
		UTF16LE,

		/**
		*	UTF-16 �r�b�O�G���f�B�A��
		*/
		UTF16BE,

		/**
		*	�f�t�H���g [UTF-8]
		*/
		Default = UTF8,
	};

	/**
	*	@brief �t�@�C���R�s�[���̓���
	*
	*	�t�@�C�����R�s�[����ۂ̓���������܂��B
	*/
	enum class CopyOption
	{
		/**
		*	�t�@�C���������Ɏg���Ă����ꍇ�A�R�s�[�����s������B
		*/
		Fail_If_Exists,

		/**
		*	�t�@�C���������Ɏg���Ă����ꍇ�A�t�@�C�����㏑������B
		*/
		Overwrite_If_Exists,
	};

	/**
	*	@brief �t�@�C������
	*
	*	�t�@�C���𑀍삵�܂��B
	*/
	namespace FileSystem
	{
		/**
		*	�w�肵���p�X�̃t�@�C���܂��̓f�B���N�g�������݂��邩��Ԃ��܂��B
		*	@param path �p�X
		*	@return ���݂��邩�̐^�U�l
		*/
		bool
			Exists(
			const FilePath& path
			);

		/**
		*	�w�肵���p�X���f�B���N�g���ł��邩��Ԃ��܂��B
		*	@param path �p�X
		*	@return �f�B���N�g���ł��邩�̐^�U�l
		*/
		bool
			IsDirectory(
			const FilePath& path
			);

		/**
		*	�w�肵���p�X���t�@�C���ł��邩��Ԃ��܂��B
		*	@param path �p�X
		*	@return �t�@�C���ł��邩�̐^�U�l
		*/
		bool
			IsFile(
			const FilePath& path
			);

		/**
		*	�w�肵���t�@�C�����f�B���N�g������ł��邩��Ԃ��܂��B
		*	@param path �p�X
		*	@return ��ł��邩�̐^�U�l
		*/
		bool
			IsEmpty(
			const FilePath& path
			);

		/**
		*	�w�肵���t�@�C�����f�B���N�g���̃T�C�Y��Ԃ��܂��B
		*	@param path �p�X
		*	@return �T�C�Y
		*	@note �t�@�C����f�B���N�g�������݂��Ȃ�������A��ł���ꍇ�� 0 ��Ԃ��܂��B
		*/
		long long
			Size(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g���̍쐬������Ԃ��܂��B
		*	@param path �p�X
		*	@return �쐬����
		*/
		optional<Date>
			CreationTime(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g���̍X�V������Ԃ��܂��B
		*	@param path �p�X
		*	@return �X�V����
		*/
		optional<Date>
			WriteTime(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g���̃A�N�Z�X������Ԃ��܂��B
		*	@param path �p�X
		*	@return �A�N�Z�X����
		*/

		optional<Date>
			AccessTime(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g���S�̂��R�s�[���܂��B
		*	@param from �R�s�[���̃p�X
		*	@param to �R�s�[��̃p�X
		*	@param option ���O�Փˎ��̂ӂ�܂�
		*	@return �����t���O
		*/
		bool
			Copy(
			const FilePath& from,
			const FilePath& to,
			CopyOption option = CopyOption::Fail_If_Exists
			);

		/**
		*	�f�B���N�g�����쐬���܂��B
		*	@param path �p�X
		*	@return �����t���O
		*/
		bool
			CreateDirectories(
			const FilePath& path
			);

		/**
		*	�w�肵���p�X�܂ł̐e�f�B���N�g�����쐬���܂��B
		*	@param path �p�X
		*	@return �����t���O
		*/
		bool
			CreateParentDirectories(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g�����폜���܂��B
		*	@param path �p�X
		*	@return �����t���O
		*	@note �t�@�C�������݂���f�B���N�g���͍폜�ł��܂���B
		*/
		bool
			Remove(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g���S�̂��폜���܂��B
		*	@param path �p�X
		*	@return �폜���ꂽ�t�@�C���̐�
		*/
		size_t
			RemoveAll(
			const FilePath& path
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g���̖��O��ύX���܂��B
		*	@param from �ύX�O�̃p�X
		*	@param to �ύX��̃p�X
		*	@param option ���O�Փˎ��̂ӂ�܂�
		*	@return ���������ꍇ�� true, ���s�����ꍇ�� false
		*/
		bool
			Rename(
			const FilePath& from,
			const FilePath& to,
			CopyOption option = CopyOption::Fail_If_Exists
			);

		/**
		*	�t�@�C���܂��̓f�B���N�g�����ړ����܂��B
		*	���̊֐��� Rename() �Ɠ����ł��B
		*	@param from �ړ��O�̃p�X
		*	@param to �ړ���̃p�X
		*	@param option ���O�Փˎ��̂ӂ�܂�
		*	@return ���������ꍇ�� true, ���s�����ꍇ�� false
		*/
		bool
			Move(
			const FilePath& from,
			const FilePath& to,
			CopyOption option = CopyOption::Fail_If_Exists
			);

		/**
		*	�w�肵���t�@�C���� .���܂܂Ȃ��g���q���������ɂ��ĕԂ��܂��B�i��: L"png"�j
		*	@param path �p�X
		*	@return �������̊g���q�B���s�����ꍇ�͋�̕�����
		*/
		String
			Extension(
			const FilePath& path
			);

		/**
		*	�w�肵���t�@�C���́A�e�f�B���N�g�����܂܂��ɁA�g���q���܂񂾖��O��Ԃ��܂��B�i��: L"picture.png"�j
		*	@param path �p�X
		*	@return �t�@�C�����B���s�����ꍇ�͋�̕�����
		*/
		String
			FileName(
			const FilePath& path
			);

		/**
		*	�w�肵���t�@�C���́A�e�f�B���N�g���Ɗg���q���܂܂Ȃ����O��Ԃ��܂��B�i��: L"picture"�j
		*	@param path �p�X
		*	@return �t�@�C�����B���s�����ꍇ�͋�̕�����
		*/
		String
			BaseName(
			const FilePath& path
			);

		/**
		*	�w�肵���t�@�C���̐e�f�B���N�g����Ԃ��܂��B�i��: L"C:\\Users\\Siv\\Desktop"�j
		*	@param path �p�X
		*	@return �e�f�B���N�g���B���s�����ꍇ�͋�̕�����
		*/
		FilePath
			ParentPath(
			const FilePath& path
			);

		/**
		*	�w�肵���t�@�C���̐�΃p�X��Ԃ��܂��B�i��: L"C:\\Users\\Siv\\Desktop\\picture.png"�j
		*	@param path �p�X
		*	@return �t�@�C���̐�΃p�X�B���s�����ꍇ�͋�̕�����
		*/
		FilePath
			FullPath(
			const FilePath& path
			);

		/**
		*	�w�肵���f�B���N�g���ɂ���t�@�C���ƃf�B���N�g���̈ꗗ��Ԃ��܂��B
		*	@param path �p�X
		*	@return �t�@�C���ƃf�B���N�g���̈ꗗ
		*/
		std::vector<FilePath>
			DirectoryContents(
			const FilePath& path
			);

		/**
		*	�v���O�������N�������p�X��Ԃ��܂��B
		*	@return �v���O�������N�������p�X
		*/
		FilePath
			InitialPath(
			);

		/**
		*	�J�����g�p�X��Ԃ��܂��B
		*	@return �J�����g�p�X
		*/
		FilePath
			CurrentPath(
			);

		/**
		*	�ꎞ�t�@�C���p�̃f�B���N�g���̃p�X��Ԃ��܂��B�p�X�̖����ɂ� L'\\' ���t���܂��B
		*	@return �ꎞ�t�@�C���p�̃f�B���N�g���̃p�X
		*/
		FilePath
			TemporaryPath(
			);

		/**
		*	�ꎞ�t�@�C���p�̌ŗL�ȃt�@�C������Ԃ��܂��B�g���q�� L".tmp" �ł��B
		*	@return �ꎞ�t�@�C���p�̃t�@�C����
		*/
		FilePath
			UniquePath(
			);

		/**
		*	�t�@�C�����e�L�X�g�t�@�C���ł���ꍇ�A���̃G���R�[�f�B���O�`����Ԃ��܂��B
		*	@param path �p�X
		*	@return �e�L�X�g�t�@�C���̃G���R�[�f�B���O�`��
		*/
		TextEncoding
			GetEncoding(
			const FilePath& path
			);
	}
}
