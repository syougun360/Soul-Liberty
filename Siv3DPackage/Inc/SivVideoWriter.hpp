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
# include <memory>
# include "SivForward.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief AVI �̈��k����
	*/
	enum class VideoCompression
	{
		/**
		*	Microsoft Video 1 | Quality 0
		*/
		MSV1_Low,

		/**
		*	Microsoft Video 1 | Quality 50
		*/
		MSV1_Medium,

		/**
		*	Microsoft Video 1 | Quality 75
		*/
		MSV1_High,

		/**
		*	Microsoft Video 1 | Quality 100
		*/
		MSV1_Ultra,

		/**
		*	Intel Indeo
		*/
		Indeo,

		/**
		*	Cinepak
		*/
		Cinepak,

		/**
		*	�񈳏k
		*/
		Uncompressed,
	};

	/**
	*	@brief ����o��
	*/
	class VideoWriter
	{
	private:

		class CVideoWriter;

		std::shared_ptr<CVideoWriter> pWriter;

	public:

		VideoWriter();

		/**
		*	������������ރt�@�C�����J���B
		*	@param path �쐬���铮��̃t�@�C���p�X
		*	@param width ����̉𑜓x X
		*	@param height ����̉𑜓x Y
		*	@param videoCompression AVI �̈��k����
		*	@param frameTime �t���[���̊Ԋu�B { a, b } �ŁA b/a[Hz]
		*/
		VideoWriter(
			const FilePath& path,
			int width,
			int height,
			VideoCompression videoCompression = VideoCompression::MSV1_High,
			const std::pair<int, int>& frameTime = { 1, 30 }
			);

		/**
		*	����̍쐬���I�����A�ۑ�����B
		*/
		~VideoWriter();

		/**
		*	������������ރt�@�C�����J���B
		*	@param path �쐬���铮��̃t�@�C���p�X
		*	@param width ����̉𑜓x X
		*	@param height ����̉𑜓x Y
		*	@param videoCompression AVI �̃t�H�[�}�b�g
		*	@param frameTime �t���[���̊Ԋu�B { a, b } �ŁA b/a[Hz]
		*	@return ���������� true, ���s������ false
		*/
		bool
		open(
			const FilePath& path,
			int width,
			int height,
			VideoCompression videoCompression = VideoCompression::MSV1_High,
			const std::pair<int, int>& frameTime = { 1, 30 }
			);

		/**
		*	������������ރt�@�C�����J����Ă��邩��Ԃ��܂��B
		*	@return �t�@�C�����J����Ă����� true, ����ȊO�̏ꍇ�� false
		*/
		bool
			isOpened(
			) const;

		/**
		*	������������ރt�@�C�����J����Ă��邩��Ԃ��܂��B
		*	@return �t�@�C�����J����Ă����� true, ����ȊO�̏ꍇ�� false
		*/
		explicit operator bool(
			) const;

		/**
		*	����Ƀt���[����ǉ�����B
		*	@param image ����Ɠ����傫���̉摜
		*	@return �t���[���̒ǉ��ɐ��������� true, ���s������ false
		*/
		bool
		write(
			const Image& image
			);

		/**
		*	����Ƀt���[����ǉ�����B
		*	@param image ����ɒǉ�����摜
		*	@param offset �摜�̃I�t�Z�b�g�A�摜���͂ݏo���ꍇ backgroundColor �œh��Ԃ����
		*	@param backgroundColor �摜���͂ݏo��������h��Ԃ��F
		*	@return �t���[���̒ǉ��ɐ��������� true, ���s������ false
		*/
		bool
		write(
			const Image& image,
			const Point& offset,
			const Color& backgroundColor = Palette::Black
			);

		/**
		*	����̍쐬���I�����A�ۑ�����B
		*	@return �t���[���̒ǉ��ɐ��������� true, ���s������ false
		*	@notice �V����������쐬����ɂ́A�ēx open() ����K�v������܂��B
		*/
		bool
		close(
			);
	};
}
