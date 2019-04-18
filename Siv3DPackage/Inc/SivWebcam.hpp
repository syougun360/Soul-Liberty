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
	*	@brief Web �J����
	*
	*	Web �J�����������܂��B
	*/
	namespace Webcam
	{
		/**
		*	Web �J�����ɂ��B�e���J�n���܂��B
		*	@return Web �J�����̋N���ɐ��������ꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			Start(
			);

		/**
		*	Web �J�����ɂ��B�e���I�����܂��B
		*/
		void
			Stop(
			);

		/**
		*	Web �J�������A�N�e�B�u���ǂ����������܂��B
		*	@return Web �J�������B�e���ł���ꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			IsActive(
			);

		/**
		*	Web �J�������t���[�����X�V�������ǂ����������܂��B
		*	@return �V�����t���[��������ꍇ true�A����ȊO�̏ꍇ�� false
		*	@note GetFrame() ����ƁA�ŐV�̃t���[�����R�s�[����A
		*	���ɐV�����摜���B�e�����܂� HasNewFrame() �� false ��Ԃ��܂��B
		*/
		bool
			HasNewFrame(
			);

		/**
		*	Web �J�����̍ŐV�̃t���[�����擾���܂��B
		*	@param image �ǂݍ��ݐ�̉摜�ւ̎Q��
		*	@return �摜�̎擾�ɐ��������ꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			GetFrame(
			Image& image
			);

		/**
		*	Web �J�����̍ŐV�̃t���[�����擾���܂��B
		*	@param tex �ǂݍ��ݐ�̃e�N�X�`���ւ̎Q��
		*	@return �e�N�X�`���̎擾�ɐ��������ꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			GetFrame(
			DynamicTexture& tex
			);
	}
}