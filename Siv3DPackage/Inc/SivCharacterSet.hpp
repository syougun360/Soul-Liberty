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
# include "SivStringRef.hpp"

namespace s3d
{
	/**
	*	@brief �����Z�b�g
	*
	*	�����Z�b�g��ϊ�����@�\�B
	*/
	namespace CharacterSet
	{
		/**
		*	�}���`�o�C�g ASCII ����������C�h������ɕϊ����܂��B
		*	@param asciiStr ASCII �����ō\�����ꂽ�}���`�o�C�g������
		*	@return �ϊ����ꂽ���C�h������
		*	@note Widen() �֐���荂���ɓ��삵�܂��B
		*/
		String
			WidenAscii(
			const boost::string_ref& asciiStr
			);

		/**
		*	���C�h ASCII ��������}���`�o�C�g������ɕϊ����܂��B
		*	@param asciiStr ASCII �����ō\�����ꂽ���C�h������
		*	@return �ϊ����ꂽ�}���`�o�C�g������
		*	@note Narrow() �֐���荂���ɓ��삵�܂��B
		*/
		std::string
			NarrowAscii(
			const StringRef& asciiStr
			);

		/**
		*	�}���`�o�C�g����������C�h������ɕϊ����܂��B
		*	@param str �}���`�o�C�g������
		*	@return �ϊ����ꂽ���C�h������
		*/
		String
			Widen(
			const boost::string_ref& str
			);

		/**
		*	���C�h��������}���`�o�C�g������ɕϊ����܂��B
		*	@param str ���C�h������
		*	@return �ϊ����ꂽ�}���`�o�C�g������
		*/
		std::string
			Narrow(
			const StringRef& str
			);

		/**
		*	���C�h������� UTF-8 ������ɕϊ����܂��B
		*	@param str ���C�h������
		*	@return �ϊ����ꂽ UTF-8 ������
		*/
		std::string
			ToUTF8(
			const StringRef& str
			);

		/**
		*	UTF-8 ����������C�h������ɕϊ����܂��B
		*	@param str UTF-8 ������
		*	@return �ϊ����ꂽ���C�h������
		*/
		String
			FromUTF8(
			const boost::string_ref& str
			);
	}

# ifndef NO_CHARACTERSET_USING
	using CharacterSet::WidenAscii;
	using CharacterSet::NarrowAscii;
	using CharacterSet::Widen;
	using CharacterSet::Narrow;
	using CharacterSet::ToUTF8;
	using CharacterSet::FromUTF8;
# endif

}
