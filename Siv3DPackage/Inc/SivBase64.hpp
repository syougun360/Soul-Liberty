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
# include <string>
# include "SivForward.hpp"

namespace s3d
{
	/**
	*	@brief Base64 �G���R�[�h/�f�R�[�h
	*
	*	Base64 �����ł̃G���R�[�h/�f�R�[�h�̂��߂̋@�\�ł��B
	*/
	namespace Base64
	{
		/**
		*	�f�[�^�o�C�i���I�u�W�F�N�g�� Base64 �G���R�[�h���܂��B
		*	@param blob �G���R�[�h����f�[�^
		*	@return �G���R�[�h���ꂽ�e�L�X�g�f�[�^
		*/
		String
			Encode(
			const Blob& blob
			);

		/**
		*	�f�[�^�� Base64 �G���R�[�h���܂��B
		*	@param data �G���R�[�h����f�[�^�̐擪�|�C���^
		*	@param size �G���R�[�h����f�[�^�̃T�C�Y�i�o�C�g�j
		*	@return �G���R�[�h���ꂽ�e�L�X�g�f�[�^
		*/
		String
			Encode(
			const void* const data,
			size_t size
			);

		/**
		*	�e�L�X�g�� Base64 �Ńf�R�[�h���܂��B
		*	@param src �f�R�[�h����e�L�X�g
		*	@return �f�R�[�h���ꂽ�o�C�i���I�u�W�F�N�g
		*/
		Blob
			Decode(
			const String& src
			);

		/**
		*	�e�L�X�g�� Base64 �Ńf�R�[�h���܂��B
		*	@param src �f�R�[�h����e�L�X�g
		*	@return �f�R�[�h���ꂽ�o�C�i���I�u�W�F�N�g
		*/
		Blob
			Decode(
			const std::string& src
			);
	};
}
