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

namespace s3d
{
	/**
	*	@brief ���O�t�@�C���̏ڍדx
	*/
	enum class LogLevel
	{
		/**
		*	��
		*/
		Less,

		/**
		*	�ʏ�
		*/
		Normal,

		/**
		*	��
		*/
		More,
	};

	namespace Logger
	{
		/**
		*	���O�t�@�C���̏ڍדx��ݒ肵�܂��B
		*	@param level �ڍדx
		*	@note �ڍדx�������ݒ肷��ƁA��葽���̃��b�Z�[�W���o�͂���܂��B
		*		  �f�t�H���g�̐ݒ�́ADebug �r���h���� More, Release �r���h���� Normal �ł��B
		*/
		void
			SetLevel(
			LogLevel level
			);

		/**
		*	���O�t�@�C���ɉ摜�ƃe�L�X�g���o�͂��܂��B
		*	@param image �摜
		*	@param str �e�L�X�g
		*	@note �傫���摜�� Logger::SetImageSize() �Ŏw�肵���T�C�Y��
		*	Logger::SetImageQuality() �Ŏw�肵���i���܂ň��k����܂��B
		*/
		void
			Write(
			const Image& image,
			const String& str = L""
			);

		/**
		*	���O�t�@�C���ɏo�͂���摜�̏c���̍ő�T�C�Y��ݒ肵�܂��B
		*	@param maxSize �摜�̂P�ӂ̍ő�s�N�Z�����B�f�t�H���g�ł� 128
		*	@note ���̃T�C�Y������摜�͏k������ďo�͂���܂��BmaxSize �� [1-Image::MaxSize] �͈̔͂ɃN�����v����܂��B
		*/
		void
			SetImageSize(
			unsigned maxSize
			);

		/**
		*	���O�t�@�C���ɏo�͂���摜�̈��k�i����[0-100] �͈̔͂Ŏw�肵�܂��B
		*	@param quality �摜�̈��k�i���B[0-99] �̏ꍇ JPEG, 100 �̏ꍇ PNG ���k����܂��B
		*	@note quality �� [0-100] �͈̔͂ɃN�����v����܂��B
		*/
		void
			SetImageQuality(
			unsigned quality
			);
	}
}

# include "SivFormat.hpp"
# include "SivLogger.inl"

# if defined(_DEBUG) || defined(S3D_LOG_DEBUG)
#  define LOG(...)			s3d::OutputLog(s3d::LogDescription::App,__VA_ARGS__)
#  define LOG_DEBUG(...)	s3d::OutputLog(s3d::LogDescription::Debug,__VA_ARGS__)
#  define LOG_ERROR(...)	s3d::OutputLog(s3d::LogDescription::Error,__VA_ARGS__)
#  define LOG_ONCE(...)		s3d::OutputLogOnce(s3d::LogDescription::App,__COUNTER__,__VA_ARGS__)
# else
#  define LOG(...)			s3d::OutputLog(s3d::LogDescription::App,__VA_ARGS__)
#  define LOG_DEBUG(...)	((void)0)
#  define LOG_ERROR(...)	s3d::OutputLog(s3d::LogDescription::Error,__VA_ARGS__)
#  define LOG_ONCE(...)		s3d::OutputLogOnce(s3d::LogDescription::App,__COUNTER__,__VA_ARGS__)
# endif
