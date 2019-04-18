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
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	@brief ����
	*/
	struct Char
	{
		wchar_t ch;

		Char(){}

		/**
		*	���������������܂��B
		*	@param _ch ����
		*/
		Char(wchar_t _ch) : ch{ _ch }{}

		/**
		*	������ wchar_t �^�ɕϊ����܂��B
		*	@return wchar_t �^�̕���
		*/
		operator wchar_t() const { return ch; }

		/**
		*	10 �i���̐����ł��邩�������܂��B
		*/
		Property_Get(bool, isDigit) const;

		/**
		*	�A���t�@�x�b�g�̏������ł��邩�������܂��B
		*/
		Property_Get(bool, isLower) const;

		/**
		*	�A���t�@�x�b�g�̑啶���ł��邩�������܂��B
		*/
		Property_Get(bool, isUpper) const;

		/**
		*	�A���t�@�x�b�g�ł��邩�������܂��B
		*/
		Property_Get(bool, isAlpha) const;

		/**
		*	�A���t�@�x�b�g�������͐����ł��邩�������܂��B
		*/
		Property_Get(bool, isAlnum) const;

		/**
		*	16 �i���̐����ł��邩�������܂��B
		*/
		Property_Get(bool, isXdigit) const;

		/**
		*	���䕶���ł��邩�������܂��B
		*/
		Property_Get(bool, isControl) const;

		/**
		*	�󔒕����ł��邩�������܂��B
		*	@note L' ', L'\t', L'�@' ���Y�����܂��B
		*/
		Property_Get(bool, isBlank) const;

		/**
		*	�󔒗ޕ����ł��邩�������܂��B
		*	@note L' ', L'\t', L'\n', L'\v', L'\f', L'\t', L'�@' ���Y�����܂��B
		*/
		Property_Get(bool, isSpace) const;

		/**
		*	�󎚉\�����ł��邩�������܂��B
		*/
		Property_Get(bool, isPrint) const;
	};
}
