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

namespace s3d
{
# pragma warning ( disable: 4201 )
	/**
	*	@brief 波形のサンプルデータ
	*/
	union WaveSample
	{
		unsigned s;
		struct
		{
			int left : 16;
			int right : 16;
		};

		/**
		*
		*/
		WaveSample(){}

		/**
		*
		*	@param mono
		*/
		WaveSample(int mono) : WaveSample(mono, mono){}

		/**
		*
		*	@param _left
		*	@param _right
		*/
		WaveSample(int _left, int _right) : left(_left & 0xffFF), right(_right & 0xffFF){}

		/**
		*
		*	@param sample
		*/
		WaveSample(const WaveSample& sample) : s(sample.s){}

		/**
		*
		*	@param sample
		*	@return
		*/
		WaveSample& operator = (const WaveSample& sample)
		{
			s = sample.s;
			return *this;
		}

		/**
		*
		*	@param mono
		*	@return
		*/
		WaveSample& operator = (int mono)
		{
			left = right = mono;
			return *this;
		}

		/**
		*
		*/
		void swapChannel()
		{
			int tmp = left;
			left = right;
			right = tmp;
		}
	};
# pragma warning ( default: 4201 )
}
