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
# include <cassert>
# include <type_traits>
# include <random>
# include <initializer_list>
# include "SivPropertyMacro.hpp"

namespace s3d
{
	class RNG
	{
	private:

		//
		// MT 11213b
		// 周期 2^11213-1, メモリ消費 2816B
		//
		typedef std::mersenne_twister_engine<unsigned, 32, 351, 175, 19, 0xccab8ee7,
			11, 0xffffffff, 7, 0x31b6ab00, 15, 0xffe50000, 17, 1812433253> mt11213b;

		mt11213b m_engine;

	public:

		typedef mt11213b::result_type result_type;

		/**
		*
		*/
		RNG(
			);

		/**
		*
		*	@param seed
		*/
		RNG(
			unsigned seed
			) : m_engine(seed) {}

		/**
		*
		*	@param seed
		*/
		void seed(unsigned seed)
		{
			m_engine.seed(seed);
		}

		/**
		*
		*	@return
		*/
		static result_type min()
		{
			return mt11213b::min();
		}

		/**
		*
		*	@return
		*/
		static result_type max()
		{
			return mt11213b::max();
		}

		/**
		*
		*	@return
		*/
		result_type operator()()
		{
			return m_engine();
		}
	};

	/**
	*	@brief 乱数の型と範囲を指定するクラス
	*/
	template<typename Type>
	class UniformDistribution
	{
	private:

		typedef typename std::conditional<std::is_floating_point<Type>::value,
			std::uniform_real_distribution<Type>, std::uniform_int_distribution<Type>>::type DistributionType;

		DistributionType distribution;

	public:

		/**
		*
		*	@param min
		*	@param max
		*/
		UniformDistribution(
			Type min,
			Type max
			)
		{
			//assert(min < max);
			distribution = DistributionType(min, max);
		}

		/**
		*
		*	@param engine
		*	@return
		*/
		Type
			operator()(
			RNG& engine
			) const
		{
			return distribution(engine);
		}

		/**
		*
		*	@param min
		*	@param max
		*/
		void
			set(
			Type min,
			Type max
			)
		{
			assert(min < max);
			distribution.param({ min, max });
		}

		/**
		*
		*/
		Property_Get(Type, min) const
		{
			return distribution.min();
		}

		/**
		*
		*/
		Property_Get(Type, max) const
		{
			return distribution.max();
		}
	};

	class NormalDistribution
	{
	private:

		std::normal_distribution<double> distribution;

	public:

		/**
		*
		*	@param mean
		*	@param sigma
		*/
		NormalDistribution(
			double mean,
			double sigma
			) : distribution(mean, sigma){}

		/**
		*
		*	@param engine
		*	@return
		*/
		double
			operator()(
			RNG& engine
			)
		{
			return distribution(engine);
		}

		/**
		*
		*	@param mean
		*	@param sigma
		*/
		void
			set(
			double mean,
			double sigma
			)
		{
			distribution.param({ mean, sigma });
		}

		/**
		*
		*/
		Property_Get(double, mean) const
		{
			return distribution.mean();
		}

		/**
		*
		*/
		Property_Get(double, sigma) const
		{
			return distribution.sigma();
		}
	};

	/**
	*
	*	@return
	*/
	RNG&
		DefaultRNG(
		);

	/**
	*
	*	@param seed
	*/
	inline
	void
		SeedDefaultRNG(
		unsigned seed
		)
	{
		DefaultRNG().seed(seed);
	}

	/**
	*	[0.0-1.0] の範囲の乱数を返します。
	*	@return [0.0-1.0] の範囲の乱数
	*	@note 乱数エンジンのシードは起動するたびに変わります。
	*/
	double
		Random(
		);

	/**
	*	指定した型と範囲の乱数を返します。
	*	@param min 生成したい乱数の最小値
	*	@param max 生成したい乱数の最大値
	*	@return 指定した型と範囲の乱数
	*	@note 乱数エンジンのシードは起動するたびに変わります。
	*/
	template<typename Type>
	inline
	Type
		Random(
		Type min,
		Type max
		)
	{
		return UniformDistribution<Type>(min, max)(DefaultRNG());
	}

	/**
	*	0 から、指定した範囲までの乱数を返します。
	*	@param max 生成したい乱数の最大値
	*	@return 0 以上 max 以下の乱数
	*	@note 乱数エンジンのシードは起動するたびに変わります。
	*/
	template<typename Type>
	inline
		Type
		Random(
		Type max
		)
	{
		return Random<Type>(0, max);
	}

	/**
	*	指定した型と範囲の乱数を返します。
	*	@param min 生成したい乱数の最小値
	*	@param max 生成したい乱数の最大値
	*	@return 指定した型と範囲の乱数
	*	@note 乱数エンジンのシードは起動するたびに変わります。
	*/
	template<>
	inline
		wchar_t
		Random<wchar_t>(
		wchar_t min,
		wchar_t max
		)
	{
		return static_cast<wchar_t>(UniformDistribution<unsigned short>(min, max)(DefaultRNG()));
	}

	/**
	*	2 値の乱数を返します。
	*	@param p 確率 p でtrue, 確率 (1-p) で false を発生させる
	*	@return 確率に基づく bool 値
	*/
	inline
	bool
		RandomBool(
		double p
		)
	{
		return std::bernoulli_distribution(p)(DefaultRNG());
	}

	/**
	*
	*	@param il
	*	@return
	*/
	template<typename Type>
	inline
	Type
		RandomSelect(
		std::initializer_list<Type> il
		)
	{
		assert(il.size() > 0);

		return *(il.begin() + (il.size() == 1 ? 0 : Random <size_t>(0, il.size() - 1)));
	}

	/**
	*
	*	@param first
	*	@param last
	*/
	template<typename RandomIt>
	inline
		void
		Shuffle(
		RandomIt first,
		RandomIt last
		)
	{
		std::shuffle(first, last, RNG());
	}

	/**
	*
	*	@param first
	*	@param last
	*	@param g
	*/
	template<typename RandomIt, typename URNG>
	inline
	void
		Shuffle(
		RandomIt first,
		RandomIt last,
		URNG && g
		)
	{
		std::shuffle(first, last, std::move(g));
	}
}
