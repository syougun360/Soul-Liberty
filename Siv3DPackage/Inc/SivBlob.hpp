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
# include "SivPropertyMacro.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief �o�C�i���I�u�W�F�N�g
	*
	*	�l�X�ȑ傫���̃f�[�^��ێ�����o�C�i���I�u�W�F�N�g�ł��B
	*/
	class Blob
	{
	private:

		std::vector<unsigned char> m_data;

	public:

		/**
		*	��̃o�C�i���I�u�W�F�N�g���쐬���܂��B
		*/
		Blob(
			);

		/**
		*	�w�肳�ꂽ�o�C�i���I�u�W�F�N�g�̃R�s�[���쐬���܂��B
		*	@param blob �R�s�[����o�C�i���I�u�W�F�N�g
		*/
		Blob(
			const Blob& blob
			);

		/**
		*	�w�肳�ꂽ�o�C�i���I�u�W�F�N�g�����[�u���ď��������܂��B
		*	@param blob ���[�u����o�C�i���I�u�W�F�N�g
		*/
		Blob(
			Blob && blob
			);

		/**
		*	�w�肳�ꂽ�T�C�Y�̃o�C�i���I�u�W�F�N�g���쐬���܂��B
		*	@param size �����T�C�Y�i�o�C�g�j
		*	@note �f�[�^�͂��ׂ� 0 �ŏ���������܂��B
		*/
		explicit
			Blob(
			size_t size
			);

		/**
		*	�w�肳�ꂽ�t�@�C���̓��e���R�s�[�����o�C�i���I�u�W�F�N�g���쐬���܂��B
		*	@param path �t�@�C����
		*/
		explicit
			Blob(
			const FilePath& path
			);

		/**
		*	�w�肳�ꂽ�|�C���^����f�[�^���R�s�[�����o�C�i���I�u�W�F�N�g���쐬���܂��B
		*	@param data �R�s�[����f�[�^�̐擪�|�C���^
		*	@param size �R�s�[����T�C�Y�i�o�C�g�j
		*/
		Blob(
			const void* const data,
			size_t size
			);

		/**
		*	�w�肳�ꂽ�f�[�^�̃R�s�[���쐬���܂��B
		*	@param data �R�s�[����f�[�^
		*/
		explicit
			Blob(
			const std::vector<unsigned char>& data
			);

		/**
		*	�w�肳�ꂽ�f�[�^�����[�u���ăo�C�i���I�u�W�F�N�g���쐬���܂��B
		*	@param data ���[�u����f�[�^
		*/
		explicit
			Blob(
			std::vector<unsigned char> && data
			);

		/**
		*	�w�肳�ꂽ�f�[�^�ŏ��������܂��B
		*	@param blob �R�s�[����f�[�^
		*	@return *this
		*/
		Blob &
			operator = (
			const Blob& blob
			);

		/**
		*	�w�肳�ꂽ�f�[�^�����[�u���ď��������܂��B
		*	@param blob ���[�u����f�[�^
		*	@return *this
		*/
		Blob &
			operator = (
			Blob && blob
			);

		/**
		*	�ێ����Ă���f�[�^���������A�g�p���Ă��郁������������܂��B
		*/
		void
			free(
			);

		/**
		*	�ێ����Ă���f�[�^�̃T�C�Y��ύX���܂��B
		*	@param size �V�����T�C�Y�i�o�C�g�j
		*	@note �T�C�Y���k�������ꍇ�A�ێ����Ă��������̃f�[�^�͎����܂��B
		*	�T�C�Y���g�債���ꍇ�A�V�����f�[�^�� 0 �ŏ���������܂��B
		*/
		void
			resize(
			size_t size
			);

		/**
		*	�f�[�^�̓��e���������܂��B
		*	@param blob �������鑊��
		*/
		void
			swap(
			Blob && blob
			);

		/**
		*	�ێ����Ă���f�[�^�̃T�C�Y��Ԃ��܂��B
		*	@return �ێ����Ă���f�[�^�̃T�C�Y
		*/
		Property_Get(size_t, size) const;

		/**
		*	�f�[�^��ێ����Ă��邩�ǂ�����Ԃ��܂��B
		*	@return �f�[�^��ێ����Ă��Ȃ��ꍇ true, �ێ����Ă���ꍇ false
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*	�f�[�^���R�s�[���A�V�����o�C�i���I�u�W�F�N�g���쐬���܂��B
		*	@return �V�����R�s�[
		*/
		Blob
			clone(
			) const;

		/**
		*	�f�[�^�̃|�C���^��Ԃ��܂��B
		*	@return �ێ����Ă���f�[�^�̐擪�|�C���^�A��̏ꍇ�� nullptr
		*/
		void*
			data(
			);

		/**
		*	�f�[�^�̃|�C���^��Ԃ��܂��B
		*	@return �ێ����Ă���f�[�^�̐擪�|�C���^�A��̏ꍇ�� nullptr
		*/
		const void*
			data(
			) const;

		/**
		*	�f�[�^�̃|�C���^��Ԃ��܂��B
		*	@return �ێ����Ă���f�[�^�̐擪�|�C���^�A��̏ꍇ�� nullptr
		*/
		unsigned char*
			dataU8(
			);

		/**
		*	�f�[�^�̃|�C���^��Ԃ��܂��B
		*	@return �ێ����Ă���f�[�^�̐擪�|�C���^�A��̏ꍇ�� nullptr
		*/
		const unsigned char*
			dataU8(
			) const;

		/**
		*	�f�[�^��ێ����Ă��邩�ǂ�����Ԃ��܂��B
		*	@return �f�[�^��ێ����Ă���ꍇ true, �ێ����Ă��Ȃ��ꍇ�� false
		*/
		explicit operator bool(
			) const;

		/**
		*	�f�[�^���t�@�C���ɕۑ����܂��B
		*	@param path �ۑ�����t�@�C���̖��O
		*	@return �f�[�^�̕ۑ��ɐ��������ꍇ true, ���s�����ꍇ false
		*	@note �f�[�^����̏ꍇ�A�T�C�Y�� 0 �̃t�@�C�����쐬���Atrue ��Ԃ��܂��B
		*/
		bool
			save(
			const FilePath& path
			) const;
	};
}
