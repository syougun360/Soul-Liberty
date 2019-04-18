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
# include "SivForward.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief �h���b�O�E�A���h�E�h���b�v
	*
	*	�h���b�O�E�A���h�E�h���b�v���ꂽ�A�C�e�����Ǘ����܂��B
	*/
	namespace Dragdrop
	{
		/**
		*	�h���b�O�E�A���h�E�h���b�v���L�����ǂ������擾���܂��B
		*	@return �h���b�O�E�A���h�E�h���b�v���L���ȏꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			IsEnabled(
			);

		/**
		*	�h���b�O�E�A���h�E�h���b�v�� ON / OFF ��؂�ւ��܂��B
		*	@param enable �h���b�O�E�A���h�E�h���b�v��L���ɂ���ꍇ true�A�����ɂ���ꍇ�� false
		*	@note ���O�Ƀh���b�v���ꂽ�A�C�e���������ԂŃh���b�O�E�A���h�E�h���b�v�𖳌��ɐݒ肷��ƁA���̃h���b�v�̓L�����Z������܂��B
		*/
		void
			SetEnabled(
			bool enable
			);

		/**
		*	�h���b�v���ꂽ�A�C�e�������邩�ǂ������擾���܂��B
		*	@return �h���b�v���ꂽ�A�C�e��������ꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			HasItems(
			);

		/**
		*	�h���b�v���ꂽ�A�C�e���̈ꗗ���擾���܂��B
		*	@return �h���b�v���ꂽ���ׂẴA�C�e���̃t�@�C���p�X���i�[���ꂽ vector
		*	@note ��x���̊֐����Ԃ����A�C�e���́A�h���b�v���ꂽ�A�C�e���ꗗ����O����܂��B
		*/
		std::vector<FilePath>
			GetFilePaths(
			);

		/**
		*	�A�C�e�����Ō�Ƀh���b�v���ꂽ��ʏ�̍��W���擾���܂��B
		*	@return �A�C�e�����Ō�Ƀh���b�v���ꂽ��ʏ�̍��W
		*/
		Point
			GetPos(
			);
	}
}
