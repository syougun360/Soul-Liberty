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
# include <initializer_list>

namespace s3d
{
	/**
	*	�n���ꂽ 2 �̒l�̂����傫�����̒l��Ԃ��܂��B
	*	@param a ��r����l
	*	@param b ��r����l
	*	@return 2 �̒l�̂����傫�����̒l
	*/
	template <typename Type>
	inline
	const Type&
		Max(
		const Type& a,
		const Type& b
		)
	{
		return (a < b) ? b : a;
	}

	/**
	*	�n���ꂽ���������X�g�̒��ōő�̒l��Ԃ��܂��B
	*	@param ilist ��r����l�̏��������X�g
	*	@return ���������X�g�̒��ōő�̒l
	*/
	template <typename Type>
	inline
	Type
		Max(
		std::initializer_list<Type> il
		)
	{
		return *std::max_element(il.begin(), il.end());
	}

	/**
	*	�n���ꂽ 2 �̒l�̂������������̒l��Ԃ��܂��B
	*	@param a ��r����l
	*	@param b ��r����l
	*	@return 2 �̒l�̂������������̒l
	*/
	template <typename Type>
	inline
	const Type&
		Min(
		const Type& a,
		const Type& b
		)
	{
		return (a < b) ? a : b;
	}

	/**
	*	�n���ꂽ���������X�g�̒��ōŏ��̒l��Ԃ��܂��B
	*	@param ilist ��r����l�̏��������X�g
	*	@return ���������X�g�̒��ōŏ��̒l
	*/
	template <typename Type>
	inline
	Type
		Min(
		std::initializer_list<Type> il
		)
	{
		return *std::min_element(il.begin(), il.end());
	}

	/**
	*	�ŏ��l�ƍő�l�͈̔͂ɃN�����v�����l��Ԃ��܂��B
	*	@param x �N�����v����l
	*	@param min �͈͂̍ŏ��l
	*	@param max �͈͂̍ő�l
	*	@return x ���N�����v�����l
	*/
	template <typename Type>
	inline
	const Type&
		Clamp(
		const Type& x,
		const Type& min,
		const Type& max
		)
	{
		return (x < min) ? min : ((max < x) ? max : x);
	}

	/**
	*	�R���e�i��������𖞂����v�f���폜���܂��B
	*	@param c �R���e�i 
	*	@param pred ����
	*/
	template <typename Container, typename Pred>
	inline
	void
	Erase_if(
		Container& c, Pred pred
		)
	{
		c.erase(std::remove_if(c.begin(), c.end(), pred), c.end());
	}

	/**
	*	�R���e�i�̂��ׂĂ̗v�f�������𖞂�������Ԃ��܂��B
	*	@param c �R���e�i
	*	@param pred ����
	*	@return ���ׂĂ̗v�f�������𖞂����ꍇ true, ����ȊO�̏ꍇ�� false
	*/
	template <typename Container, typename Pred>
	inline
	bool
		AllOf(
		Container& c, Pred pred
		)
	{
		return std::all_of(c.begin(), c.end(), pred);
	}

	/**
	*	�R���e�i�̂����ꂩ�̗v�f�������𖞂�������Ԃ��܂��B
	*	@param c �R���e�i
	*	@param pred ����
	*	@return �����ꂩ�̗v�f�������𖞂����ꍇ true, ����ȊO�̏ꍇ�� false
	*/
	template <typename Container, typename Pred>
	inline
		bool
		AnyOf(
		Container& c, Pred pred
		)
	{
		return std::any_of(c.begin(), c.end(), pred);
	}

	/**
	*	�R���e�i�̂��ׂĂ̗v�f�������𖞂����Ȃ�����Ԃ��܂��B
	*	@param c �R���e�i
	*	@param pred ����
	*	@return ���ׂĂ̗v�f�������𖞂����Ȃ��ꍇ true, ����ȊO�̏ꍇ�� false
	*/
	template <typename Container, typename Pred>
	inline
		bool
		NoneOf(
		Container& c, Pred pred
		)
	{
		return std::none_of(c.begin(), c.end(), pred);
	}
}
