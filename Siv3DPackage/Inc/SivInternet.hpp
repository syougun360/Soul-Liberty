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
# include "SivOptional.hpp"

namespace s3d
{
	/**
	*	@brief �C���^�[�l�b�g
	*
	*	�C���^�[�l�b�g��̃f�[�^�ɃA�N�Z�X���܂��B
	*/
	namespace Internet
	{
		/**
		*	�R���s���[�^�[���C���^�[�l�b�g�ɐڑ�����Ă��邩��Ԃ��܂��B
		*	@return �ڑ�����Ă���� true, ����Ă��Ȃ���� false
		*/
		bool IsConnected();

		/**
		*	�w�肵�� URL �̃t�@�C���ɐڑ����܂��B
		*	@param url http:// �������� https:// �Ŏn�܂� URL
		*	@return �ڑ��ł���� true, ���s�����ꍇ false
		*/
		bool Connect(const FilePath& url);

		/**
		*	�w�肵�� URL �̃t�@�C���ɐڑ����A�t�@�C���̃T�C�Y���擾���܂��B
		*	@param url http:// �������� https:// �Ŏn�܂� URL
		*	@param fileSize �T�C�Y���i�[����ϐ�
		*	@return �����t���O
		*/
		bool Connect(const FilePath& url, long long& fileSize);

		/**
		*	�ڑ����� URL �̃t�@�C�����_�E�����[�h���܂��B
		*	@param output �ۑ�����t�@�C����
		*	@return �_�E�����[�h���J�n������
		*	@note ���̊֐��́A�_�E�����[�h���������邩�A�r���ŃG���[����������܂Ő����Ԃ��܂���B
		*/
		bool DownloadTo(const FilePath& output);

		/**
		*	�ڑ����� URL �̃t�@�C���̃_�E�����[�h���J�n���܂��B
		*	@param output �ۑ�����t�@�C����
		*	@return �_�E�����[�h�J�n�ɐ��������ꍇ true, ���s�����ꍇ false
		*/
		bool BeginDownloadTo(const FilePath& output);

		/**
		*	�_�E�����[�h�̐i�s�󋵂� [0,100] �̒l�ŕԂ��܂��B
		*	@return �_�E�����[�h�̐i�s��
		*	@note �_�E�����[�h���̏ꍇ�͂��̐i�x�� [0,99] �ŁA����������A����ȊO�̏ꍇ�� 100 ��Ԃ��܂��B
		*/
		int GetDownloadProgress();

		/**
		*	�_�E�����[�h�𒆎~���܂��B
		*/
		void CancelDownload();

		/**
		*	�w�肵�� URL �� Internet Explorer �ŊJ���܂��B
		*	@param url http:// �������� https:// �Ŏn�܂� URL
		*	@return ���������ꍇ true, ���s�����ꍇ false
		*/
		bool LaunchIE(const FilePath& url);

		/**
		*	�w�肵�� URL �����[�U�̊���̃u���E�U�ŊJ���܂��B
		*	@param url http:// �������� https:// �Ŏn�܂� URL
		*	@return ���������ꍇ true, ���s�����ꍇ false
		*/
		bool LaunchWebBrowser(const FilePath& url);
	}
}
