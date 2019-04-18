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
	struct Cone
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
#pragma warning(default:4201)

		double r, h;

		Quaternion rotation;

		Cone() = default;

		explicit Cone(double _r, double _h, const Quaternion& _rotation = Quaternion::Identity())
			: center{ 0, 0, 0 }
			, r{ _r }
			, h{ _h }
			, rotation{ _rotation }
		{

		}

		Cone(double x, double y, double z, double _r, double _h, const Quaternion& _rotation = Quaternion::Identity())
			: center{ x, y, z }
			, r{ _r }
			, h{ _h }
			, rotation{ _rotation }
		{

		}

		Cone(const Vec3& pos, double _r, double _h, const Quaternion& _rotation = Quaternion::Identity())
			: center{ pos }
			, r{ _r }
			, h{ _h }
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
