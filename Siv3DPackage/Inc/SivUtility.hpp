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
	*	渡された 2 つの値のうち大きい方の値を返します。
	*	@param a 比較する値
	*	@param b 比較する値
	*	@return 2 つの値のうち大きい方の値
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
	*	渡された初期化リストの中で最大の値を返します。
	*	@param ilist 比較する値の初期化リスト
	*	@return 初期化リストの中で最大の値
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
	*	渡された 2 つの値のうち小さい方の値を返します。
	*	@param a 比較する値
	*	@param b 比較する値
	*	@return 2 つの値のうち小さい方の値
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
	*	渡された初期化リストの中で最小の値を返します。
	*	@param ilist 比較する値の初期化リスト
	*	@return 初期化リストの中で最小の値
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
	*	最小値と最大値の範囲にクランプした値を返します。
	*	@param x クランプする値
	*	@param min 範囲の最小値
	*	@param max 範囲の最大値
	*	@return x をクランプした値
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
	*	コンテナから条件を満たす要素を削除します。
	*	@param c コンテナ 
	*	@param pred 条件
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
	*	コンテナのすべての要素が条件を満たすかを返します。
	*	@param c コンテナ
	*	@param pred 条件
	*	@return すべての要素が条件を満たす場合 true, それ以外の場合は false
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
	*	コンテナのいずれかの要素が条件を満たすかを返します。
	*	@param c コンテナ
	*	@param pred 条件
	*	@return いずれかの要素が条件を満たす場合 true, それ以外の場合は false
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
	*	コンテナのすべての要素が条件を満たさないかを返します。
	*	@param c コンテナ
	*	@param pred 条件
	*	@return すべての要素が条件を満たさない場合 true, それ以外の場合は false
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
