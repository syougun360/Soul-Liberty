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
		// ���� 2^11213-1, ���������� 2816B
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
	*	@brief �����̌^�Ɣ͈͂��w�肷��N���X
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
	*	[0.0-1.0] �͈̗̔͂�����Ԃ��܂��B
	*	@return [0.0-1.0] �͈̗̔͂���
	*	@note �����G���W���̃V�[�h�͋N�����邽�тɕς��܂��B
	*/
	double
		Random(
		);

	/**
	*	�w�肵���^�Ɣ͈̗͂�����Ԃ��܂��B
	*	@param min ���������������̍ŏ��l
	*	@param max ���������������̍ő�l
	*	@return �w�肵���^�Ɣ͈̗͂���
	*	@note �����G���W���̃V�[�h�͋N�����邽�тɕς��܂��B
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
	*	0 ����A�w�肵���͈͂܂ł̗�����Ԃ��܂��B
	*	@param max ���������������̍ő�l
	*	@return 0 �ȏ� max �ȉ��̗���
	*	@note �����G���W���̃V�[�h�͋N�����邽�тɕς��܂��B
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
	*	�w�肵���^�Ɣ͈̗͂�����Ԃ��܂��B
	*	@param min ���������������̍ŏ��l
	*	@param max ���������������̍ő�l
	*	@return �w�肵���^�Ɣ͈̗͂���
	*	@note �����G���W���̃V�[�h�͋N�����邽�тɕς��܂��B
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
	*	2 �l�̗�����Ԃ��܂��B
	*	@param p �m�� p ��true, �m�� (1-p) �� false �𔭐�������
	*	@return �m���Ɋ�Â� bool �l
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
