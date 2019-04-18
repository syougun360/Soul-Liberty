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
# include "SivQuaternion.hpp"

namespace s3d
{
	struct Mat4x4 : Matrix
	{
		Mat4x4(){}

		Mat4x4(const Matrix& mat)
			: Matrix(mat){}

		static Mat4x4 Identity()
		{
			return DirectX::XMMatrixIdentity();
		}

		static Mat4x4 Translate(double x, double y, double z)
		{
			return DirectX::XMMatrixTranslation(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
		}

		static Mat4x4 Translate(const Vec3& pos)
		{
			return DirectX::XMMatrixTranslation(static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(pos.z));
		}


		static Mat4x4 Scale(double scale)
		{
			return DirectX::XMMatrixScaling(static_cast<float>(scale), static_cast<float>(scale), static_cast<float>(scale));
		}

		static Mat4x4 Scale(double xs, double ys, double zs)
		{
			return DirectX::XMMatrixScaling(static_cast<float>(xs), static_cast<float>(ys), static_cast<float>(zs));
		}

		static Mat4x4 Scale(const Vec3& scale)
		{
			return DirectX::XMMatrixScaling(static_cast<float>(scale.x), static_cast<float>(scale.y), static_cast<float>(scale.z));
		}


		static Mat4x4 Rotate(double pitch, double yaw, double roll)
		{
			return DirectX::XMMatrixRotationRollPitchYaw(static_cast<float>(pitch), static_cast<float>(yaw), static_cast<float>(roll));
		}

		static Mat4x4 Rotate(const Vec3& pitchYawRoll)
		{
			return DirectX::XMMatrixRotationRollPitchYaw(static_cast<float>(pitchYawRoll.x), static_cast<float>(pitchYawRoll.y), static_cast<float>(pitchYawRoll.z));
		}

		static Mat4x4 Rotate(const Quaternion& quaternion)
		{
			return quaternion.toMatrix();
		}

		static Mat4x4 AffineTransform(const Vec3& scaling, const Vec3& rotation, const Vec3& translation)
		{
			const DirectX::XMVECTOR scale = Vec3ToVector(scaling, 1.0f);
			const DirectX::XMVECTOR rotationOrigin = DirectX::g_XMZero;
			const DirectX::XMVECTOR rotate = DirectX::XMQuaternionRotationRollPitchYaw(
				static_cast<float>(rotation.x),
				static_cast<float>(rotation.y),
				static_cast<float>(rotation.z));
			const DirectX::XMVECTOR translate = Vec3ToVector(translation, 0.0f);

			return DirectX::XMMatrixAffineTransformation(scale, rotationOrigin, rotate, translate);
		}

		static Mat4x4 AffineTransform(const Vec3& scaling, const Quaternion& rotation, const Vec3& translation)
		{
			const DirectX::XMVECTOR scale = Vec3ToVector(scaling, 1.0f);
			const DirectX::XMVECTOR rotationOrigin = DirectX::g_XMZero;
			const DirectX::XMVECTOR translate = Vec3ToVector(translation, 0.0f);

			return DirectX::XMMatrixAffineTransformation(scale, rotationOrigin, rotation.component.v, translate);
		}

		static Mat4x4 AffineTransform(double scaling, const Quaternion& rotation, const Vec3& translation)
		{
			const float sf = static_cast<float>(scaling);
			const DirectX::XMVECTOR scale = DirectX::XMVectorSet(sf, sf, sf, 0.0f);
			const DirectX::XMVECTOR rotationOrigin = DirectX::g_XMZero;
			const DirectX::XMVECTOR translate = Vec3ToVector(translation, 0.0f);

			return DirectX::XMMatrixAffineTransformation(scale, rotationOrigin, rotation.component.v, translate);
		}

		Mat4x4 translate(double x, double y, double z) const
		{
			return *this * DirectX::XMMatrixTranslation(static_cast<float>(x), static_cast<float>(y), static_cast<float>(z));
		}

		Mat4x4 translate(const Vec3& pos) const
		{
			return *this * DirectX::XMMatrixTranslation(static_cast<float>(pos.x), static_cast<float>(pos.y), static_cast<float>(pos.z));
		}


		Mat4x4 scale(double scale) const
		{
			return *this * DirectX::XMMatrixScaling(static_cast<float>(scale), static_cast<float>(scale), static_cast<float>(scale));
		}

		Mat4x4 scale(double xs, double ys, double zs) const
		{
			return *this * DirectX::XMMatrixScaling(static_cast<float>(xs), static_cast<float>(ys), static_cast<float>(zs));
		}

		Mat4x4 scale(const Vec3& scale) const
		{
			return *this * DirectX::XMMatrixScaling(static_cast<float>(scale.x), static_cast<float>(scale.y), static_cast<float>(scale.z));
		}


		Mat4x4 rotate(double pitch, double yaw, double roll) const
		{
			return *this * DirectX::XMMatrixRotationRollPitchYaw(static_cast<float>(pitch), static_cast<float>(yaw), static_cast<float>(roll));
		}

		Mat4x4 rotate(const Vec3& pitchYawRoll) const
		{
			return *this * DirectX::XMMatrixRotationRollPitchYaw(static_cast<float>(pitchYawRoll.x), static_cast<float>(pitchYawRoll.y), static_cast<float>(pitchYawRoll.z));
		}

		Mat4x4 rotate(const Quaternion& quaternion) const
		{
			return *this * quaternion.toMatrix();
		}
	};

	/**
	*
	*	@param os
	*	@param color
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Mat4x4& mat
		)
	{
		return os << CharType('(')
			<< mat.r[0] << CharType(',')
			<< mat.r[1] << CharType(',')
			<< mat.r[2] << CharType(',')
			<< mat.r[3] << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param color
	*	@return
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		const Mat4x4& mat
		)
	{
		CharType unused;

		return	is >> unused
			>> mat.r[0] >> unused
			>> mat.r[1] >> unused
			>> mat.r[2] >> unused
			>> mat.r[3] >> unused;
	}
}
