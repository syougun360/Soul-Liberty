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
# include "SivDirectXMathUtility.hpp"
# include "SivPointVector.hpp"

namespace s3d
{
	struct Quaternion
	{
		union Component
		{
			Vector v;

			float fa[4];

			struct { float x, y, z, w; } fv;
		} component;

		Quaternion() = default;

		Quaternion(float x, float y, float z, float w)
		{
			component.v = DirectX::XMVectorSet(x, y, z, w);
		}

		Quaternion(const Vec3& normalizedAxis, double angle)
		{
			component.v = DirectX::XMQuaternionRotationNormal(Vec3ToVector(normalizedAxis, 0.0f), static_cast<float>(angle));
		}

		Quaternion(__m128 v)
		{
			component.v = v;
		}

		Quaternion __vectorcall operator * (const Quaternion& q) const
		{
			return DirectX::XMQuaternionMultiply(component.v, q.component.v);
		}

		Quaternion&  operator *= (const Quaternion& q)
		{
			component.v = DirectX::XMQuaternionMultiply(component.v, q.component.v);

			return *this;
		}

		Vec3 operator * (const Vec3& v) const
		{
			const Vector result = DirectX::XMVector3Rotate(Vec3ToVector(v, 0.0f), component.v);

			return{ result.m128_f32[0], result.m128_f32[1], result.m128_f32[2] };
		}

		static Quaternion Identity()
		{
			return DirectX::XMQuaternionIdentity();
		}

		static Quaternion RotateRoll(double angle)
		{
			return DirectX::XMQuaternionRotationRollPitchYaw(0.0f, 0.0f, static_cast<float>(angle));
		}

		static Quaternion RotatePitch(double angle)
		{
			return DirectX::XMQuaternionRotationRollPitchYaw(static_cast<float>(angle), 0.0f, 0.0f);
		}

		static Quaternion RotateYaw(double angle)
		{
			return DirectX::XMQuaternionRotationRollPitchYaw(0.0f, static_cast<float>(angle), 0.0f);
		}

		static Quaternion RollPitchYaw(double roll, double pitch, double yaw)
		{
			return DirectX::XMQuaternionRotationRollPitchYaw(static_cast<float>(pitch), static_cast<float>(yaw), static_cast<float>(roll));
		}

		static Quaternion RotationArc(const Vec3& v1, const Vec3& v2, const Vec3& fallbackAxis = Vec3::Zero);

		Quaternion& rotateRoll(double angle);

		Quaternion& rotatePitch(double angle);

		Quaternion& rotateYaw(double angle);

		Quaternion& rotateRollPitchYaw(double roll, double pitch, double yaw);

		Quaternion __vectorcall normalized() const
		{
			return DirectX::XMQuaternionNormalize(component.v);
		}

		Mat4x4 __vectorcall toMatrix() const;

		Property_Get(bool, isIdentity) const
		{
			return DirectX::XMQuaternionIsIdentity(component.v);
		}
	};

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
		const Quaternion& q
		)
	{
		return os << q.component.v;
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
		Quaternion& q
		)
	{
		return is >> q.component.v;
	}

	namespace Math
	{
		/**
		*
		*	@param v1
		*	@param v2
		*	@param f
		*	@return
		*/
		inline
		Quaternion 
			Slerp(
			const Quaternion& q1,
			const Quaternion& q2,
			double f
			)
		{
			return DirectX::XMQuaternionSlerp(q1.component.v, q2.component.v, static_cast<float>(f));
		}
	}
}
