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
# include <DirectXMath.h>
# include "SivPointVector.hpp"

namespace s3d
{
	typedef DirectX::XMVECTOR Vector;
	typedef DirectX::XMMATRIX Matrix;

	inline Vector _vectorcall Float4ToVector(const Float4& v)
	{
		return DirectX::XMVectorSet(v.x, v.y, v.z, v.w);
	}

	inline Vector _vectorcall Vec3ToVector(const Vec3& xyz, float w)
	{
		return DirectX::XMVectorSet(
			static_cast<float>(xyz.x),
			static_cast<float>(xyz.y),
			static_cast<float>(xyz.z),
			w
			);
	}

	inline Vector _vectorcall Vec4ToVector(const Vec4& v)
	{
		return DirectX::XMVectorSet(
			static_cast<float>(v.x),
			static_cast<float>(v.y),
			static_cast<float>(v.z),
			static_cast<float>(v.w)
			);
	}

	inline Vector _vectorcall ColorFToVector(const ColorF& c)
	{
		return DirectX::XMVectorSet(
			static_cast<float>(c.r),
			static_cast<float>(c.g),
			static_cast<float>(c.b),
			static_cast<float>(c.a)
			);
	}

	/**
	*
	*	@param os
	*	@param v
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Vector& v
		)
	{
		return os << CharType('(') << v.m128_f32[0] << CharType(',') << v.m128_f32[1] << CharType(',') << v.m128_f32[2] << CharType(',') << v.m128_f32[3] << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param v
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Vector& v
		)
	{
		CharType unused;
		return is >> unused >> v.m128_f32[0] >> unused >> v.m128_f32[1] >> unused >> v.m128_f32[2] >> unused >> v.m128_f32[3] >> unused;
	}
}
