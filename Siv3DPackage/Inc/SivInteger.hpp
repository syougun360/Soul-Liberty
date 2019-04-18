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
# include "SivPropertyMacro.hpp"
# include "SivString.hpp"

namespace s3d
{
	/**
	*	@brief ����
	*
	*	������l�X�ȕ\���ɕϊ����܂��B
	*/
	template <typename Type>
	struct IntegerBase
	{
		Type value;
		
		IntegerBase() {}

		/**
		*	���l��ݒ肵�܂��B
		*	@param _value ���l
		*/
		IntegerBase(Type _value) : value(_value) {}

		/**
		*	�����񂩂琔�l�ɕϊ����܂��B
		*	@param str �ϊ�����镶����i��: L"12345", L"0xFF")
		*/
		IntegerBase(const String& str) : IntegerBase(str, 0) {}

		/**
		*	����w�肵�ĕ����񂩂琔�l�ɕϊ����܂��B
		*	@param str �ϊ�����镶����i��: L"12345", L"0xFF")
		*	@param radix �g�p����
		*/
		IntegerBase(
			const String& str,
			int radix
			);

		/**
		*	�g�ݍ��݌^�ɕϊ����܂��B
		*	@return �g�ݍ��݌^�̐��l
		*/
		operator Type() const { return value; }

		/**
		*	�V�������l�ɒu�������܂��B
		*	@return �V�������l
		*/
		IntegerBase operator = (Type _value)
		{
			value = _value;
			return *this;
		}

		/**
		*	������Ŏ����ꂽ�V�������l�ɒu�������܂��B
		*	@param str �V�������l������������
		*	@return �V�������l
		*/
		IntegerBase operator = (const String& str)
		{
			return *this = IntegerBase<Type>(str);
		}

		/**
		*	���l�𕶎���ŕ\���܂��B
		*	@param radix �
		*	@return �ϊ�����������
		*	@note ��� [2-36] �͈̔͂Ŏw�肵�܂��B
		*/
		String
			toString(
			int radix
			) const;

		/**
		*	���l�� 10 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, string) const { return toString(10); }

		/**
		*	���l�� 2 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, binary) const { return toString(2); }

		/**
		*	���l�� 8 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, octal) const { return toString(8); }

		/**
		*	���l�� 16 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, hex) const { return toString(16); }
	};

	typedef
		IntegerBase<char>
		Integer8;

	typedef
		IntegerBase<unsigned char>
		IntegerU8;

	typedef
		IntegerBase<short>
		Integer16;

	typedef
		IntegerBase<unsigned short>
		IntegerU16;

	typedef
		IntegerBase<int>
		Integer;

	typedef
		IntegerBase<int>
		Integer32;

	typedef
		IntegerBase<unsigned>
		IntegerU32;

	typedef
		IntegerBase<long long>
		Integer64;

	typedef
		IntegerBase<unsigned long long>
		IntegerU64;
}
