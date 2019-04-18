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
	*	@brief ���������_��
	*
	*	���������_����l�X�ȕ\���ɕϊ����܂��B
	*/
	template <typename Type, typename BitsType>
	struct FloatBase
	{
		static_assert(
			sizeof(Type) == sizeof(BitsType),
			"error: sizeof(Type)!=sizeof(BitsType)"
			);

		union { Type value; BitsType bits; };

		FloatBase() {}

		/**
		*	���l��ݒ肵�܂��B
		*	@param _value ���l
		*/
		FloatBase(Type _value) : value(_value) {}

		/**
		*	�����񂩂琔�l�ɕϊ����܂��B
		*	@param str �ϊ�����镶����i��: L"123.45")
		*/
		FloatBase(const String& str);

		/**
		*	�g�ݍ��݌^�ɕϊ����܂��B
		*	@return �g�ݍ��݌^�̐��l
		*/
		operator Type() const { return value; }

		/**
		*	�V�������l�ɒu�������܂��B
		*	@return �V�������l
		*/
		FloatBase operator = (Type _value)
		{
			value = _value;
			return *this;
		}

		/**
		*	������Ŏ����ꂽ�V�������l�ɒu�������܂��B
		*	@param str �V�������l������������
		*	@return �V�������l
		*/
		FloatBase operator = (const String& str)
		{
			return *this = FloatBase<Type, BitsType>(str);
		}

		/**
		*	���l�𕶎���ŕ\���܂��B
		*	@param decimalPlace �����_�ȉ��̌���
		*	@return �ϊ�����������
		*/
		String toString(int decimalPlace) const;

		/**
		*	���l�𕶎���ŕ\���܂��B
		*/
		Property_Get(String, string) const { return toString(3); }

		/**
		*	�r�b�g�\���� 2 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, binary) const;

		/**
		*	�r�b�g�\���� 8 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, octal) const;

		/**
		*	�r�b�g�\���� 16 �i���̕�����ŕ\���܂��B
		*/
		Property_Get(String, hex) const;
	};

	typedef
		FloatBase<float, unsigned>
		Float;

	typedef
		FloatBase<double, unsigned long long>
		Double;
}
