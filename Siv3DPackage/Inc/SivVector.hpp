//----------------------------------------------------------
//
//  This file is part of the Siv3D Engine
//
//  Copyright (C) 2008-2014 Reputeless,
//
//  Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

# pragma once
# include <iostream>
# include <type_traits>
# include "SivFormat.hpp"
# include "SivPropertyMacro.hpp"
# include "SivPoint.hpp"

namespace s3d
{
	/**
	*	@brief 2 次元ベクトル
	*/
	template<typename Type>
	struct Vector2D
	{
		static_assert(
			std::is_floating_point<Type>::value,
			"Vector2D Type must be floating point type."
			);

		typedef Type value_type;

		Type x, y;

		/**
		*
		*/
		Vector2D(){}
		
		/**
		*
		*	@param _x
		*	@param _y
		*/
		template<typename U, typename V>
		Vector2D(U _x, V _y) : x{ static_cast<Type>(_x) }, y{ static_cast<Type>(_y) }{}

		/**
		*
		*	@param _x
		*	@param _y
		*/
		Vector2D(Type _x, Type _y) : x{ _x }, y{ _y }{}

		/**
		*
		*	@param v
		*/
		Vector2D(const Point& v) : x{ static_cast<Type>(v.x) }, y{ static_cast<Type>(v.y) }{}

		/**
		*
		*	@param v
		*/
		template<typename U>
		Vector2D(const Vector2D<U>& v) : x{ static_cast<Type>(v.x) }, y{ static_cast<Type>(v.y) }{}

		/**
		*
		*	@return
		*/
		Vector2D operator + () const;

		/**
		*
		*	@return
		*/
		Vector2D operator - () const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D operator + (const Vector2D& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D operator - (const Vector2D& v) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vector2D operator * (Type s) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D operator * (const Vector2D& v) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vector2D operator / (Type s) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D& operator += (const Vector2D& v);

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D& operator -= (const Vector2D& v);

		/**
		*
		*	@param s
		*	@return
		*/
		Vector2D& operator *= (Type s);

		/**
		*
		*	@param s
		*	@return
		*/
		Vector2D& operator /= (Type s);

		/**
		*
		*/
		Property_Get(Vector2D, xx) const;

		/**
		*
		*/
		Property_Get(Vector2D, xy) const;

		/**
		*
		*/
		Property_Get(Vector2D, yx) const;

		/**
		*
		*/
		Property_Get(Vector2D, yy) const;

		/**
		*
		*	@return
		*/
		Point asPoint() const;

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Vector2D& set(Type _x, Type _y) { x = _x; y = _y; return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D& set(const Vector2D& v) { return *this = v; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@return
		*/
		Vector2D& moveBy(Type _x, Type _y) { x += _x; y += _y; return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Vector2D& moveBy(const Vector2D& v) { return *this += v; }

		/**
		*
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		bool intersects(const Shape& shape) const
		{
			return Geometry::Intersect(*this, shape);
		}

		/**
		*
		*/
		Property_Get(bool, isZero) const;

		/**
		*
		*	@return
		*/
		Type
			length(
			) const;

		/**
		*
		*	@return
		*/
		Type
			lengthSq(
			) const;

		/**
		*
		*	@return
		*/
		Type
			lengthInv(
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Type
			distanceFrom(
			const Vector2D& v
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Type
			distanceFromSq(
			const Vector2D& v
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Type
			dot(
			const Vector2D& v
			) const;

		/**
		*
		*	@return
		*/
		Vector2D
			normalized(
			) const;

		/**
		*
		*	@param col
		*	@return
		*/
		const Vector2D&
			draw(
			const Color& col = Palette::White
			) const;

		/**
		*	Vector2D{ 0, 0 }
		*/
		const static Vector2D Zero;

		/**
		*	Vector2D{ 1, 1 }
		*/
		const static Vector2D One;

		/**
		*	Vector2D{ 1, 0 }
		*/
		const static Vector2D UnitX;

		/**
		*	Vector2D{ 0, 1 }
		*/
		const static Vector2D UnitY;

		/**
		*	Vector2D{ -1, 0 }
		*/
		const static Vector2D Left;

		/**
		*	Vector2D{ 1, 0 }
		*/
		const static Vector2D Right;

		/**
		*	Vector2D{ 0, -1 }
		*/
		const static Vector2D Up;

		/**
		*	Vector2D{ 0, 1 }
		*/
		const static Vector2D Down;
	};

	/**
	*
	*	@param os
	*	@param v
	*	@return
	*/
	template<typename CharType, typename Type>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Vector2D<Type>& v
		)
	{
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param v
	*	@return
	*/
	template<typename CharType, typename Type>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Vector2D<Type>& v
		)
	{
		CharType unused;
		return is >> unused >> v.x >> unused >> v.y >> unused;
	}

	typedef Vector2D<float> Float2;

	typedef Vector2D<double> Vec2;

	/**
	*
	*	@param s
	*	@param v
	*	@return
	*/
	template<typename Type, typename U>
	inline Vector2D<Type> operator * (U s, const Vector2D<Type>& v)
	{
		return v*s;
	}

	/**
	*
	*	@param p
	*	@param v
	*	@return
	*/
	template<typename Type>
	inline Vector2D<Type> operator + (const Point& p, const Vector2D<Type>& v)
	{
		return v + p;
	}

	/**
	*
	*	@param p
	*	@param v
	*	@return
	*/
	template<typename Type>
	inline Vector2D<Type> operator - (const Point& p, const Vector2D<Type>& v)
	{
		return Vector2D<Type>(p)-v;
	}
}


namespace s3d
{
	/**
	*	@brief 3 次元ベクトル
	*/
	template<typename Type>
	struct Vector3D
	{
		static_assert(
			std::is_floating_point<Type>::value,
			"Vector3D Type must be floating point type."
			);

		typedef Type value_type;

		Type x, y, z;

		/**
		*
		*/
		Vector3D(){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*/
		template<typename U, typename V, typename W>
		Vector3D(U _x, V _y, W _z) : x(static_cast<Type>(_x)), y(static_cast<Type>(_y)), z(static_cast<Type>(_z)){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*/
		Vector3D(Type _x, Type _y, Type _z) : x(_x), y(_y), z(_z){}

		/**
		*
		*	@param xy
		*	@param _z
		*/
		template<typename U>
		Vector3D(const Vector2D<U>& xy, Type _z) : x(static_cast<Type>(xy.x)), y(static_cast<Type>(xy.y)), z(_z){}

		/**
		*
		*	@param _x
		*	@param yz
		*/
		template<typename U>
		Vector3D(Type _x, const Vector2D<U>& yz) : x(_x), y(static_cast<Type>(yz.x)), z(static_cast<Type>(yz.y)){}

		/**
		*
		*	@param v
		*/
		template<typename U>
		Vector3D(const Vector3D<U>& v) : x(static_cast<Type>(v.x)), y(static_cast<Type>(v.y)), z(static_cast<Type>(v.z)){}

		/**
		*
		*	@return
		*/
		Vector3D operator + () const;

		/**
		*
		*	@return
		*/
		Vector3D operator - () const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D operator + (const Vector3D& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D operator - (const Vector3D& v) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vector3D operator * (Type s) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D operator * (const Vector3D& v) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vector3D operator / (Type s) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D& operator += (const Vector3D& v);

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D& operator -= (const Vector3D& v);

		/**
		*
		*	@param s
		*	@return
		*/
		Vector3D& operator *= (Type s);

		/**
		*
		*	@param s
		*	@return
		*/
		Vector3D& operator /= (Type s);

		/**
		*
		*/
		Property_Get(Vector2D<Type>, xy) const;

		/**
		*
		*/
		Property_Get(Vector2D<Type>, xz) const;

		/**
		*
		*/
		Property_Get(Vector2D<Type>, yz) const;

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@return
		*/
		Vector3D& set(Type _x, Type _y, Type _z) { x = _x; y = _y; z = _z; return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D& set(const Vector3D& v) { return *this = v; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@return
		*/
		Vector3D& moveBy(Type _x, Type _y, Type _z) { x += _x; y += _y; z += _z; return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D& moveBy(const Vector3D& v) { return *this += v; }

		/**
		*
		*/
		Property_Get(bool, isZero) const;

		/**
		*
		*	@return
		*/
		Type
			length(
			) const;

		/**
		*
		*	@return
		*/
		Type
			lengthSq(
			) const;

		/**
		*
		*	@return
		*/
		Type
			lengthInv(
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Type
			distanceFrom(
			const Vector3D& v
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Type
			distanceFromSq(
			const Vector3D& v
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Type
			dot(
			const Vector3D& v
			) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector3D
			cross(
			const Vector3D& v
			) const;

		/**
		*
		*	@return
		*/
		Vector3D
			normalized(
			) const;

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

		/**
		*	Vector3D{ 0, 0, 0 }
		*/
		const static Vector3D Zero;

		/**
		*	Vector3D{ 1, 1, 1 }
		*/
		const static Vector3D One;

		/**
		*	Vector3D{ 1, 0, 0 }
		*/
		const static Vector3D UnitX;

		/**
		*	Vector3D{ 0, 1, 0 }
		*/
		const static Vector3D UnitY;

		/**
		*	Vector3D{ 0, 0, 1 }
		*/
		const static Vector3D UnitZ;

		/**
		*	Vector3D{ -1, 0, 0 }
		*/
		const static Vector3D Left;

		/**
		*	Vector3D{ 1, 0, 0 }
		*/
		const static Vector3D Right;

		/**
		*	Vector3D{ 0, 1, 0 }
		*/
		const static Vector3D Up;

		/**
		*	Vector3D{ 0, -1, 0 }
		*/
		const static Vector3D Down;

		/**
		*	Vector3D{ 0, 0, 1 }
		*/
		const static Vector3D Forward;

		/**
		*	Vector3D{ 0, 0, -1 }
		*/
		const static Vector3D Backward;
	};

	/**
	*
	*	@param os
	*	@param v
	*	@return
	*/
	template<typename CharType, typename Type>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Vector3D<Type>& v
		)
	{
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param v
	*	@return
	*/
	template<typename CharType, typename Type>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Vector3D<Type>& v
		)
	{
		CharType unused;
		return is >> unused >> v.x >> unused >> v.y >> unused >> v.z >> unused;
	}

	typedef Vector3D<float> Float3;

	typedef Vector3D<double> Vec3;

	/**
	*
	*	@param s
	*	@param v
	*	@return
	*/
	template<typename Type, typename U>
	inline Vector3D<Type> operator * (U s, const Vector3D<Type>& v)
	{
		return v*s;
	}
}


namespace s3d
{
	/**
	*	@brief 4 次元ベクトル
	*/
	template<typename Type>
	struct Vector4D
	{
		static_assert(
			std::is_floating_point<Type>::value,
			"Vector4D Type must be floating point type."
			);

		typedef Type value_type;

		Type x, y, z, w;

		/**
		*
		*/
		Vector4D(){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@param _w
		*/
		template<typename U, typename V, typename W, typename X>
		Vector4D(U _x, V _y, W _z, X _w) : x(static_cast<Type>(_x)), y(static_cast<Type>(_y)), z(static_cast<Type>(_z)), w(static_cast<Type>(_w)){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@param _w
		*/
		Vector4D(Type _x, Type _y, Type _z, Type _w) : x(_x), y(_y), z(_z), w(_w){}

		/**
		*
		*	@param xy
		*	@param _z
		*	@param _w
		*/
		template<typename U>
		Vector4D(const Vector2D<U>& xy, Type _z, Type _w) : x(static_cast<Type>(xy.x)), y(static_cast<Type>(xy.y)), z(_z), w(_w){}

		/**
		*
		*	@param _x
		*	@param _y
		*	@param zw
		*/
		template<typename U>
		Vector4D(Type _x, Type _y, const Vector2D<U>& zw) : x(_x), y(_y), z(static_cast<Type>(zw.x)), w(static_cast<Type>(zw.y)){}

		/**
		*
		*	@param xy
		*	@param zw
		*/
		template<typename U, typename V>
		Vector4D(const Vector2D<U>& xy, const Vector2D<V>& zw) : x(static_cast<Type>(xy.x)), y(static_cast<Type>(xy.y)), z(static_cast<Type>(zw.x)), w(static_cast<Type>(zw.y)){}

		/**
		*
		*	@param xyz
		*	@param _w
		*/
		template<typename U>
		Vector4D(const Vector3D<U>& xyz, Type _w) : x(static_cast<Type>(xyz.x)), y(static_cast<Type>(xyz.y)), z(static_cast<Type>(xyz.z)), w(_w){}

		/**
		*
		*	@param _x
		*	@param yzw
		*/
		template<typename U>
		Vector4D(Type _x, const Vector3D<U>& yzw) : x(_x), y(static_cast<Type>(yzw.y)), z(static_cast<Type>(yzw.y)), w(static_cast<Type>(yzw.z)){}

		/**
		*
		*	@param v
		*/
		template<typename U>
		Vector4D(const Vector4D<U>& v) : x(static_cast<Type>(v.x)), y(static_cast<Type>(v.y)), z(static_cast<Type>(v.z)), w(static_cast<Type>(v.w)){}

		/**
		*
		*	@return
		*/
		Vector4D operator + () const;

		/**
		*
		*	@return
		*/
		Vector4D operator - () const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector4D operator + (const Vector4D& v) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector4D operator - (const Vector4D& v) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vector4D operator * (Type s) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector4D operator * (const Vector4D& v) const;

		/**
		*
		*	@param s
		*	@return
		*/
		Vector4D operator / (Type s) const;

		/**
		*
		*	@param v
		*	@return
		*/
		Vector4D& operator += (const Vector4D& v);

		/**
		*
		*	@param v
		*	@return
		*/
		Vector4D& operator -= (const Vector4D& v);

		/**
		*
		*	@param s
		*	@return
		*/
		Vector4D& operator *= (Type s);

		/**
		*
		*	@param s
		*	@return
		*/
		Vector4D& operator /= (Type s);

		/**
		*
		*/
		Property_Get(Vector2D<Type>, xy) const;

		/**
		*
		*/
		Property_Get(Vector2D<Type>, yz) const;

		/**
		*
		*/
		Property_Get(Vector2D<Type>, zw) const;

		/**
		*
		*/
		Property_Get(Vector3D<Type>, xyz) const;

		/**
		*
		*/
		Property_Get(Vector3D<Type>, yzw) const;

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@param _w
		*	@return
		*/
		Vector4D& set(Type _x, Type _y, Type _z, Type _w) { x = _x; y = _y; z = _z; w = _w; return *this; }

		/*
		*
		*	@param v
		*	@return
		*/
		Vector4D& set(const Vector4D& v) { return *this = v; }

		/**
		*
		*	@param _x
		*	@param _y
		*	@param _z
		*	@param _w
		*	@return
		*/
		Vector4D& moveBy(Type _x, Type _y, Type _z, Type _w) { x += _x; y += _y; z += _z; w += _w; return *this; }

		/*
		*
		*	@param v
		*	@return
		*/
		Vector4D& moveBy(const Vector4D& v) { return *this += v; }

		/**
		*
		*/
		Property_Get(bool, isZero) const;

		/**
		*
		*	@return
		*/
		Type
			length(
			) const;

		/**
		*
		*	@return
		*/
		Type
			lengthSq(
			) const;

		/**
		*
		*	@return
		*/
		Type
			lengthInv(
			) const;

		/*
		*
		*	@param v
		*	@return
		*/
		Type
			distanceFrom(
			const Vector4D& v
			) const;

		/*
		*
		*	@param v
		*	@return
		*/
		Type
			distanceFromSq(
			const Vector4D& v
			) const;

		/*
		*
		*	@param v
		*	@return
		*/
		Type
			dot(
			const Vector4D& v
			) const;

		/*
		*
		*	@return
		*/
		Vector4D
			normalized(
			) const;

		/**
		*	Vector4D{ 0, 0, 0, 0 }
		*/
		const static Vector4D Zero;

		/**
		*	Vector4D{ 1, 1, 1, 1 }
		*/
		const static Vector4D One;

		/**
		*	Vector4D{ 1, 0, 0, 0 }
		*/
		const static Vector4D UnitX;

		/**
		*	Vector4D{ 0, 1, 0, 0 }
		*/
		const static Vector4D UnitY;

		/**
		*	Vector4D{ 0, 0, 1, 0 }
		*/
		const static Vector4D UnitZ;

		/**
		*	Vector4D{ 0, 0, 0, 1 }
		*/
		const static Vector4D UnitW;
	};

	/**
	*
	*	@param os
	*	@param v
	*	@return
	*/
	template<typename CharType, typename Type>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Vector4D<Type>& v
		)
	{
		return os << CharType('(') << v.x << CharType(',') << v.y << CharType(',') << v.z << CharType(',') << v.w << CharType(')');
	}

	/**
	*
	*	@param is
	*	@param v
	*	@return
	*/
	template<typename CharType, typename Type>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Vector4D<Type>& v
		)
	{
		CharType unused;
		return is >> unused >> v.x >> unused >> v.y >> unused >> v.z >> unused >> v.w >> unused;
	}

	typedef Vector4D<float> Float4;

	typedef Vector4D<double> Vec4;

	/**
	*
	*	@param s
	*	@param v
	*	@return
	*/
	template<typename Type, typename U>
	inline Vector4D<Type> operator * (U s, const Vector4D<Type>& v)
	{
		return v*s;
	}
}
