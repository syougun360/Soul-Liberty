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
	*	@brief Midi
	*
	*	Midi �T�E���h�������܂��B
	*/
	namespace Midi
	{
		/**
		*	�V���� Midi �t�@�C����ǂݍ��݂܂��B
		*	@param path Midi �t�@�C����
		*	@return Midi �t�@�C���̓ǂݍ��݂ɐ��������ꍇ true�A����ȊO�̏ꍇ�� false
		*	@note �ȑO�ɓǂݍ��܂�Ă��� Midi �͒�~�E�j������܂��B���ʁE�Đ����x�̓��Z�b�g����܂��B
		*/
		bool
			Open(
			const FilePath& path
			);

		/**
		*	Midi::Open() �œǂݍ��� Midi ���Đ����܂��B
		*	@return Midi �̍Đ��J�n�ɐ��������ꍇ true�A����ȊO�̏ꍇ�� false
		*	@note Midi �͓����� 1 �̃t�@�C�������Đ��ł��܂���B
		*	�ق��̃A�v���P�[�V������ Midi �f�o�C�X���g�p���Ă����ꍇ�A�Đ��Ɏ��s����ꍇ������܂��B
		*/
		bool
			Play(
			);

		/**
		*	Midi::Open() �œǂݍ��� Midi �����[�v�Đ����܂��B
		*	@return Midi �̍Đ��J�n�ɐ��������ꍇ true�A����ȊO�̏ꍇ�� false
		*	@note Midi �͓����� 1 �̃t�@�C�������Đ��ł��܂���B
		*	�ق��̃A�v���P�[�V������ Midi �f�o�C�X���g�p���Ă����ꍇ�A�Đ��Ɏ��s����ꍇ������܂��B
		*/
		bool
			PlayLoop(
			);

		/**
		*	�Đ����� Midi ���ꎞ��~���܂��B
		*/
		void
			Pause(
			);

		/**
		*	�Đ����� Midi ���~���A�Đ��ʒu���Ȃ̐擪�ɖ߂��܂��B
		*/
		void
			Stop(
			);

		/**
		*	Midi ���Đ������ǂ����������܂��B
		*	@return Midi ���Đ����̏ꍇ true�A����ȊO�̏ꍇ�� false
		*/
		bool
			IsPlaying(
			);

		/**
		*	Midi �̍Đ����ʂ��w�肵�܂��B
		*	@param volume ���� (0.0 ���ŏ��A1.0 ���ő�)
		*/
		void
			SetVolume(
			double volume
			);

		/**
		*	���ݐݒ肳��Ă��� Midi �̍Đ����ʂ�Ԃ��܂��B
		*	@return ���ݐݒ肳��Ă��� Midi �̍Đ�����
		*/
		double
			GetVolume(
			);

		/**
		*	Midi �̍Đ����x��ύX���܂��B
		*	@param speed �Đ��{�� (0.1 ���ŏ��A10.0 ���ő�)
		*	@note speed �� [0.1,10.0] �͈̔͂ɃN�����v����܂��B
		*/
		void
			SetTempo(
			double speed
			);

		/**
		*	���ݐݒ肳��Ă��� Midi �̍Đ����x��Ԃ��܂��B
		*	@return ���ݐݒ肳��Ă��� Midi �̍Đ����x
		*/
		double
			GetTempo(
			);

		/**
		*	���ݓǂݍ��܂�Ă��� Midi ��ʏ푬�x�ōĐ������ꍇ�̋Ȃ̒�����b�ŕԂ��܂��B
		*	@return Midi �̒��� (�b)
		*/
		double
			GetLengthSec(
			);

		/**
		*	���ݓǂݍ��܂�Ă��� Midi �̍Đ��ʒu��b�ŕԂ��܂��B
		*	@return Midi �̍Đ��ʒu (�b)
		*/
		double
			GetPosSec(
			);

		/**
		*	Midi �̍Đ��ʒu��ύX���܂��B
		*	@param pos Midi �̍Đ��ʒu (�b)
		*	@note Midi ���Đ����̏ꍇ�́A��������Đ����ĊJ���܂��B
		*/
		void
			SetPosSec(
			double pos
			);
	}
}
