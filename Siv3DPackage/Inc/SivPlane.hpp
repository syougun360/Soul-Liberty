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
	struct Plane
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
			struct { Vec2 size; };
			struct { double w, h; };
		};
#pragma warning(default:4201)

		Quaternion rotation;

		Plane() = default;

		explicit Plane(double _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ 0, 0, 0 }
			, size{ _size, _size }
			, rotation{ _rotation }
		{

		}

		Plane(double _x, double _y, double _z, double _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ _x, _y, _z }
			, size{ _size, _size }
			, rotation{ _rotation }
		{

		}

		Plane(const Vec3& pos, double _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, size{ _size, _size }
			, rotation{ _rotation }
		{

		}

		Plane(double _x, double _y, double _z, double _w, double _h, const Quaternion& _rotation = Quaternion::Identity())
			: center{ _x, _y, _z }
			, size{ _w, _h }
			, rotation{ _rotation }
		{

		}

		Plane(const Vec3& pos, double _w, double _h, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, size{ _w, _h }
			, rotation{ _rotation }
		{

		}

		Plane(double _x, double _y, double _z, const Vec2& _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ _x, _y, _z }
			, size{ _size }
			, rotation{ _rotation }
		{

		}

		Plane(const Vec3& pos, const Vec2& _size, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, size{ _size }
			, rotation{ _rotation }
		{

		}

		Mat4x4 getMatrix() const;

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
