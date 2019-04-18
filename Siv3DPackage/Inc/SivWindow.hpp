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
# include "SivString.hpp"
# include "SivPointVector.hpp"
# include "SivRectangle.hpp"
# include "SivOptional.hpp"

namespace s3d
{
	/**
	*	@brief �E�B���h�E�X�^�C��
	*/
	enum class WindowStyle
	{
		/**
		*	�ʏ�̃E�B���h�E
		*/
		Fixed = 0x3,

		/**
		*	�T�C�Y���ύX�\�ȃE�B���h�E
		*/
		Sizeable = 0x7,

		/**
		*	�t���[���������E�B���h�E
		*/
		NonFrame = 0x1,
	};

	/**
	*	@brief �E�B���h�E�̏��
	*/
	struct WindowState
	{
		/**
		*	�N���C�A���g��ʁi�`��\��j�̕��ƍ���
		*/
		Point clientSize;

		/**
		*	�g�����܂߂��E�B���h�E�̕��ƍ���
		*/
		Point windowSize;

		/**
		*	�X�N���[���̕��ƍ���
		*/
		Point screenSize;

		/**
		*	�E�B���h�E�̍���̈ʒu
		*/
		Point windowPos;

		/**
		*	�E�B���h�E�̘g���̕��ƍ���
		*/
		Point frameSize;

		/**
		*	�E�B���h�E�̃^�C�g���o�[�̍���
		*/
		int titleBarHeight;

		/**
		*	�X�N���[���̃^�X�N�o�[�̋�`�͈�
		*/
		Rect taskbarRect;

		/**
		*	�X�N���[���̃^�X�N�o�[�̈ʒu�i��: 0 ��: 1 ��: 2 �E: 3)
		*/
		int taskbarPos;

		/**
		*	�E�B���h�E�^�C�v
		*/
		WindowStyle style;

		/**
		*	�t���X�N���[�����[�h��
		*/
		bool fullscreen;

		/**
		*	�V�X�e���J�[�\���̕\�����L����
		*/
		bool showCursor;

		/**
		*	�J�[�\�����N���C�A���g��ʁi�`��\��j��ɂ��邩
		*/
		bool cursorOnClient;

		/**
		*	�J�[�\�����E�B���h�E��ɂ��邩
		*/
		bool cursorOnWindow;

		/**
		*	�E�B���h�E���ŏ�������Ă��邩
		*/
		bool minimized;

		/**
		*	�E�B���h�E���ő剻����Ă��邩
		*/
		bool maximized;

		/**
		*	�E�B���h�E���A�N�e�B�u��
		*/
		bool focused;

		/**
		*	�E�B���h�E���ړ�����
		*/
		bool windowMoving;

		/**
		*	�E�B���h�E���T�C�Y�ύX����
		*/
		bool windowSizing;

		/**
		*	�E�B���h�E�̃^�C�g��
		*/
		String windowTitle;
	};

	/**
	* @brief �E�B���h�E
	*
	* �E�B���h�E�̏�Ԃ��Ǘ����܂��B
	*/
	namespace Window
	{
		/**
		*	�E�B���h�E�̏�Ԃ�Ԃ��܂��B
		*	@return ���݂̃E�B���h�E�̏����i�[���� WindowState �\���̂ւ̎Q��
		*/
		const WindowState&
			GetState(
			);

		/**
		*	�E�B���h�E�̍���̈ʒu��Ԃ��܂��B
		*	@return	 �X�N���[�����W�n�ł̃E�B���h�E�̍���̈ʒu
		*/
		Point
			GetPos(
			);

		/**
		*	�E�B���h�E���A�N�e�B�u�ł��邩�������܂��B
		*	@return�E�B���h�E���A�N�e�B�u�ȏꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			Focused(
			);

		/**
		*	�g������E�B���h�E�ł��邩�������܂��B
		*	@return �g������E�B���h�E�̏ꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			Framed(
			);

		/**
		*	�T�C�Y���ύX�ȃE�B���h�E�ł��邩�������܂��B
		*	@return �T�C�Y���ύX�ȃE�B���h�E�̏ꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			Sizeable(
			);

		/**
		*	�E�B���h�E���[�h�ł��邩�������܂��B
		*	@return �E�B���h�E���[�h�̏ꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			Windowed(
			);

		/**
		*	�t���X�N���[�����[�h�ł��邩�������܂��B
		*	@return �t���X�N���[�����[�h�̏ꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			IsFullSceen(
			);

		/**
		*	�E�B���h�E���ŏ�������Ă��邩�������܂��B
		*	@return �E�B���h�E���ŏ�������Ă���ꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			Minimized(
			);

		/**
		*	�E�B���h�E���ő剻����Ă��邩�������܂��B
		*	@return �E�B���h�E���ő剻����Ă���ꍇ true, ����ȊO�̏ꍇ�� false
		*/
		bool
			Maximized(
			);

		/**
		*	�E�B���h�E�̃^�C�g����ݒ肵�܂��B
		*	@param title �^�C�g���ɂ���e�L�X�g
		*/
		void
			SetTitle(
			const String& title
			);

		/**
		*	�E�B���h�E�̃A�C�R����ݒ肵�܂��B
		*	@param title �A�C�R���ɐݒ肷��摜
		*/
		void
			SetIcon(
			const Image& image
			);

		/**
		*	�J�[�\���̈ʒu���N���C�A���g���W��ŕύX���܂��B
		*	@param x �V�����J�[�\���� x ���W
		*	@param y �V�����J�[�\���� y ���W
		*/
		void
			SetCursorPos(
			int x,
			int y
			);

		void
			SetCursorPos(
			const Point& pos
			);

		/**
		*	�V�X�e���J�[�\���̕\�� / ��\����؂�ւ��܂��B
		*	@param show �V�X�e���J�[�\����\������ꍇ�� true, �\�����Ȃ��ꍇ�� false
		*/
		void
			ShowCursor(
			bool show
			);

		/**
		*	�J�X�^���J�[�\����ݒ肵�܂��B
		*	@param texture �J�X�^���J�[�\���ɐݒ肷��e�N�X�`���B�ݒ����������ꍇ�� none ���w�肷��
		*	@param center �e�N�X�`����̃J�[�\�����S�ʒu
		*/
		void
			SetCursorTexture(
			const optional<Texture>& texture,
			const Point& center = { 0, 0 }
		);

		/**
		*	�J�X�^���J�[�\����ݒ肵�܂��B
		*	@param texture �J�X�^���J�[�\���ɐݒ肷��e�N�X�`���B�ݒ����������ꍇ�� none ���w�肷��
		*	@param center �e�N�X�`����̃J�[�\�����S�ʒu
		*/
		void
			SetCursorTextureRegion(
			const optional<TextureRegion>& texture,
			const Point& center = { 0, 0 }
			);

		/**
		*	�E�B���h�E�̈ʒu��ύX���܂��B
		*	@param x �V�����E�B���h�E�ʒu�� x ���W
		*	@param y �V�����E�B���h�E�ʒu�� y ���W
		*/
		void
			SetPos(
			int x,
			int y
			);

		/**
		*	�E�B���h�E�̈ʒu��ύX���܂��B
		*	@param pos �V�����E�B���h�E�ʒu�̍��W
		*/
		void
			SetPos(
			const Point& pos
			);

		/**
		*	�E�B���h�E������Ɉړ����܂��B
		*/
		void
			ToUpperLeft(
			);

		/**
		*	�E�B���h�E�̃T�C�Y��ύX���܂��B
		*	@param width �V�����E�B���h�E�̃N���C�A���g�̈�̕�
		*	@param height �V�����E�B���h�E�̃N���C�A���g�̈�̍���
		*/
		void
			Resize(
			int width,
			int height
			);

		/**
		*	�E�B���h�E�̃T�C�Y��ύX���܂��B
		*	@param size �V�����E�B���h�E�̃N���C�A���g�̈�̃T�C�Y
		*/
		void
			Resize(
			const Point& size
			);

		/**
		*	�E�B���h�E���ŏ������܂��B
		*/
		void
			Minimize(
			);

		/**
		*	�ŏ����A�ő剻���ꂽ�E�B���h�E�����̑傫���ɖ߂��܂��B
		*/
		void
			Restore(
			);

		/**
		*	�E�B���h�E���ő剻���܂��B
		*/
		void
			Maximize(
			);

		/**
		*	�E�B���h�E�̃N���C�A���g�̈�̃T�C�Y��Ԃ��܂��B
		*	@return �E�B���h�E�̃N���C�A���g�̈�̃T�C�Y
		*/
		Point
			Size(
			);

		/**
		*	�E�B���h�E�̃N���C�A���g�̈�̒����̍��W��Ԃ��܂��B
		*	@return �E�B���h�E�̃N���C�A���g�̈�̒����̍��W
		*/
		Point
			Center(
			);

		/**
		*	�E�B���h�E�̃N���C�A���g�̈�̕���Ԃ��܂��B
		*	@return �E�B���h�E�̃N���C�A���g�̈�̕�
		*/
		int
			Width(
			);

		/**
		*	�E�B���h�E�̃N���C�A���g�̈�̍�����Ԃ��܂��B
		*	@return �E�B���h�E�̃N���C�A���g�̈�̍���
		*/
		int
			Height(
			);

		/**
		*	�E�B���h�E�𒆉��Ɉړ����܂��B
		*/
		void
			Centering(
			);

		/**
		*	�E�B���h�E�X�^�C����ύX���܂��B
		*	@param style �V�����E�B���h�E�X�^�C��
		*/
		void
			SetStyle(
			WindowStyle style
			);

		/**
		*	�X�N���[�����[�h��؂�ւ��܂��B
		*	@param fullscreen �t���X�N���[���̏ꍇ true, �E�B���h�E���[�h�̏ꍇ false
		*	@param size �V�����𑜓x
		*	@return �؂�ւ��ɐ��������ꍇ true�A���s�����ꍇ�� false
		*/
		bool
			SetFullscreen(
			bool fullscreen,
			const Point& size
			);
	}
}
