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
# include "SivOptional.hpp"
# include "SivPointVector.hpp"
# include "SivQuaternion.hpp"

namespace s3d
{
	struct Box
	{
	private:

		const Mesh& getMesh() const;

	public:

#pragma warning(disable:4201)
		union
		{
			struct { Vec3 center; };
			struct { double x, y, z; };
		};

		union
		{
			struct { Vec3 size; };
			struct { double w, h, d; };
		};
#pragma warning(default:4201)

		Quaternion rotation;

		Box() = default;

		explicit Box(double _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ 0, 0, 0 }
			, size{ _size, _size, _size }
			, rotation{ _rotation }
		{

		}

		Box(double _x, double _y, double _z, double _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ _x, _y, _z }
			, size{ _size, _size, _size }
			, rotation{ _rotation }
		{

		}

		Box(const Vec3& pos, double _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, size{ _size, _size, _size }
			, rotation{ _rotation }
		{

		}

		Box(double _x, double _y, double _z, double _w, double _h, double _d, const Quaternion& _rotation = Quaternion::Identity())
			: center{ _x, _y, _z }
			, size{ _w, _h, _d }
			, rotation{ _rotation }
		{

		}

		Box(const Vec3& pos, double _w, double _h, double _d, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, size{ _w, _h, _d }
			, rotation{ _rotation }
		{

		}

		Box(double _x, double _y, double _z, const Vec3& _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ _x, _y, _z }
			, size{ _size }
			, rotation{ _rotation }
		{

		}

		Box(const Vec3& pos, const Vec3& _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, size{ _size }
			, rotation{ _rotation }
		{

		}

		/**
		*
		*	@param s
		*	@return
		*/
		Box stretched(double s) const { return{ center, size + Vec3{s, s, s}, rotation }; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@return
		*/
		Box stretched(double _x, double _y, double _z) const { return{ center, size + Vec3{ _x, _y, _z }, rotation }; }

		Mat4x4 getMatrix() const;

		/**
		*
		*	@param primitive
		*	@return
		*/
		template<typename Primitive>
		bool intersects(const Primitive& primitive) const
		{
			return Geometry3D::Intersect(*this, primitive);
		}

		void draw(const optional<Renderer>& renderer) const;

		void draw(const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;

		void draw(const Texture& texture, const optional<Renderer>& renderer) const;

		void draw(const Texture& texture, const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;

		TransformedMesh translate(const Vec3& translation) const;

		TransformedMesh scale(double scaling) const;

		TransformedMesh scale(const Vec3& scaling) const;

		TransformedMesh rotate(const Vec3& rotation) const;

		TransformedMesh rotate(const Quaternion& rotation) const;
	};
}
