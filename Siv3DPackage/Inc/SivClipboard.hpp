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

namespace s3d
{
	/**
	*	@brief �N���b�v�{�[�h�̃f�[�^�̎��
	*/
	enum class ClipboardItemType
	{
		/**
		*	�����R�s�[����Ă��Ȃ�
		*/
		None,

		/**
		*	�e�L�X�g
		*/
		Text,

		/**
		*	�摜
		*/
		Image,

		/**
		*	1 �ȏ�̃t�@�C���p�X
		*/
		FilePath
	};

	/**
	* @brief �N���b�v�{�[�h
	*
	* �N���b�v�{�[�h�̓��e���Ǘ����܂��B
	*/
	namespace Clipboard
	{
		/**
		*	�N���b�v�{�[�h�ɃR�s�[����Ă���f�[�^�̎�ނ�Ԃ��܂��B
		*	@return �N���b�v�{�[�h�ɃR�s�[����Ă���f�[�^�̎��
		*/
		ClipboardItemType
			GetType(
			);

		/**
		*	�N���b�v�{�[�h�ɃR�s�[����Ă���e�L�X�g��Ԃ��܂��B
		*	@return �N���b�v�{�[�h�ɃR�s�[����Ă��镶����A�N���b�v�{�[�h�ɕ����񂪂Ȃ��ꍇ��̕�����
		*/
		String
			GetText(
			);

		/**
		*	�N���b�v�{�[�h�ɃR�s�[����Ă���摜��Ԃ��܂��B
		*	@return �N���b�v�{�[�h�ɃR�s�[����Ă���摜�A�N���b�v�{�[�h�ɉ摜���Ȃ��ꍇ��̉摜
		*/
		Image
			GetImage(
			);

		/**
		*	�N���b�v�{�[�h�ɃR�s�[����Ă���t�@�C���p�X�̈ꗗ��Ԃ��܂��B
		*	@return �N���b�v�{�[�h�ɃR�s�[����Ă���t�@�C���p�X�̈ꗗ
		*/
		std::vector<FilePath>
			GetFilePaths(
			);

		/**
		*	�e�L�X�g���N���b�v�{�[�h�ɃR�s�[���܂��B
		*	@param str �N���b�v�{�[�h�ɃR�s�[����e�L�X�g
		*/
		void
			SetText(
			const String& str
			);

		/**
		*	�摜���N���b�v�{�[�h�ɃR�s�[���܂��B
		*	@param img �N���b�v�{�[�h�ɃR�s�[����摜
		*/
		void
			SetImage(
			const Image& image
			);

		/**
		*	�N���b�v�{�[�h�̒��g����ɂ��܂��B
		*/
		void
			Clear(
			);
	}
}
