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
	*	@brief ����
	*/
	namespace Time
	{
		/**
		*	�R���s���[�^�[���N�����Ă���̌o�ߎ��Ԃ��~���b�ŕԂ��܂��B
		*	@return �R���s���[�^�[���N�����Ă���̌o�ߎ��ԁi�~���b�j
		*/
		unsigned
			GetMillisec(
			);

		/**
		*	�R���s���[�^�[���N�����Ă���̌o�ߎ��Ԃ��}�C�N���b�ŕԂ��܂��B
		*	@return �R���s���[�^�[���N�����Ă���̌o�ߎ��ԁi�}�C�N���b�j
		*/
		unsigned long long
			GetMicrosec(
			);

		/**
		*	���萢�E�� (UTC)  1970 �N 1 �� 1 ���ߑO 0 ������̌o�ߎ��Ԃ�b�ŕԂ��܂��B
		*	@return 1970 �N 1 �� 1 ���ߑO 0 ������̌o�ߕb��
		*/
		long long
			SecSince1970(
			);

		/**
		*	���萢�E�� (UTC)  1601 �N 1 �� 1 ���ߑO 0 ������̌o�ߎ��Ԃ��~���b�ŕԂ��܂��B
		*	@return 1601 �N 1 �� 1 ���ߑO 0 ������̌o�߃~���b
		*/
		unsigned long long
			MillisecSince1601(
			);

		/**
		*	���݂̋��萢�E�� (UTC) �Ƃ̎����𕪂ŕԂ��܂��B
		*	@return ���݂̋��萢�E�� (UTC) �Ƃ̎����i���j
		*/
		int
			UtcOffsetMinutes(
			);
	}
}
