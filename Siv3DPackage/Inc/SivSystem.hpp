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

namespace s3d
{
	/**
	*	@brief �C�x���g�t���O
	*/
	struct WindowEvent
	{
		enum Flag
		{
			/**
			*	�E�B���h�E�� [x] �{�^�����������
			*/
			CloseButton = 0x01,

			/**
			*	�G�X�P�[�v�L�[���������
			*/
			EscapeKey = 0x02,

			/**
			*	�}�E�X�̍��N���b�N
			*/
			LeftClick = 0x04,

			/**
			*	�}�E�X�̉E�N���b�N
			*/
			RightClick = 0x08,

			/**
			*	�E�B���h�E�̃t�H�[�J�X���O���
			*/
			Unfocus = 0x10,

			/**
			*	���炩�̃L�[���������
			*/
			AnyKey = 0x20,

			/**
			*	�f�t�H���g�i�E�B���h�E�� [x] �{�^����������邩�A�G�X�P�[�v�L�[���������j
			*/
			Default = CloseButton | EscapeKey,

			/**
			*	�ݒ肵�Ȃ�
			*	�K�� System::Exit() �����s���ďI������K�v������܂��B
			*/
			Manual = 0x00,
		};
	};

	namespace System
	{
		/**
		*	�O���t�B�b�N�X�Ɠ��͂��X�V���܂��B�܂��t���[���̍X�V�� 60fps �ȉ��ɂȂ�悤���Ԃ𒲐����܂��B
		*	�I���C�x���g�����������ꍇ��A�G���W���̓����ŃG���[�����������ꍇ false ��Ԃ��܂��B
		*	@return �A�v���P�[�V���������s�ł���ꍇ true, �A�v���P�[�V�������I������ꍇ false
		*/
		bool
			Update(
			);

		/**
		*	�A�v���P�[�V�����̏I�����G���W���ɓ`���܂��B
		*	���� System::Update() �͕K�� false ��Ԃ��܂��B
		*/
		void
			Exit(
			);

		/**
		*	�I���C�x���g��ݒ肵�܂��B
		*	@param windowEventFlag �C�x���g�t���O WindowEvent::Flag �̑g�ݍ��킹
		*/
		void
			SetExitEvent(
			int windowEventFlag
			);

		/**
		*	���O�̃t���[���Ŕ��������C�x���g��Ԃ��܂��B
		*	@return �C�x���g�t���O WindowEvent::Flag �̑g�ݍ��킹
		*/
		int
			GetPreviousEvent(
			);

		/**
		*	�w�肵���~���b�����������~���܂��B
		*	@param milliseconds �������~���鎞�ԁi�~���b�j
		*	@note 20 �~���b�ȏ�� Win32 API �� Sleep ���A����ȉ��� PAUSE ���߂̃X�s���E���[�v���g�p���܂��B
		*/
		void
			Sleep(
			double milliseconds
			);

		/**
		*	System::Update() ���Ă΂ꂽ�񐔁i���X�V�����t���[�����j��Ԃ��܂��B
		*	@return System::Update() ���Ă΂ꂽ��
		*/
		unsigned
			FrameCount(
			);
	}
}
