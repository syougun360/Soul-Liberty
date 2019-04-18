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
# include "SivPointVector.hpp"

namespace s3d
{
	namespace Graphics
	{
		/**
		*	�w�i�F��ݒ肵�܂��B
		*	@param color �w�i�F
		*/
		void
			SetBackground(
			const Color& color
			);

		/**
		*	draw ���ꂽ 2D �A�C�e������ʂɏ������݂܂��B
		*	�ʏ�� 3D �����_�����O�̌�� 2D �A�C�e���������Ń����_�����O����܂��B���̏��Ԃ�ς���K�v������ꍇ�Ɏg�p���Ă��������B
		*/
		void
			Render2DBackground(
			);

		/**
		*	�t���X�N���[�����[�h�ɂ��邱�Ƃ��ł���𑜓x�̈ꗗ��Ԃ��܂��B
		*	����ȊO�̉𑜓x�� Window::SetFullscreen() �ɓn���Ǝ��s���܂��B
		*	@return �t���X�N���[�����[�h�ɂ��邱�Ƃ��ł���𑜓x�̈ꗗ
		*/
		std::vector<Point>
			GetFullScreenSize(
			);

		/**
		*	���݂̃t���[���̃X�N���[���V���b�g��ۑ����܂��B
		*	@note ���s�t�@�C��/Screenshot/ �t�H���_�ɕۑ�����܂��B
		*	�B�e���ꂽ�X�N���[���V���b�g�͎��̃t���[���� Graphics::ReceiveScreenCapture() ��ʂ��Ď擾�ł��܂��B
		*/
		void
			SaveScreenshot(
			);

		/**
		*	���݂̃t���[���̃X�N���[���V���b�g��ۑ����܂��B
		*	@param path �ۑ�����p�X
		*	�B�e���ꂽ�X�N���[���V���b�g�͎��̃t���[���� Graphics::ReceiveScreenCapture() ��ʂ��Ď擾�ł��܂��B
		*/
		void
			SaveScreenshot(
			const FilePath& path
			);

		/**
		*	���̃t���[�����I��������X�N���[���V���b�g���B�e���A��������ɕۑ����܂��B
		*	�B�e���ꂽ�X�N���[���V���b�g�͎��̃t���[���� Graphics::ReceiveScreenCapture() ��ʂ��Ď擾�ł��܂��B
		*/
		void
			RequestScreenCapture(
			);

		/**
		*	��������ɕۑ����ꂽ�X�N���[���V���b�g�� Image �`���Ŏ擾���܂��B
		*	�ȑO�̃t���[���� Graphics::ReceiveScreenCapture()�@���Ă΂�Ă��Ȃ��Ƃ����܂���B
		*	@return �ۑ�����Ă���X�N���[���V���b�g�A�����X�N���[���V���b�g���ۑ�����Ă��Ȃ��ꍇ�͋�̃C���[�W
		*/
		const s3d::Image&
			ReceiveScreenCapture(
			);
	}
}
