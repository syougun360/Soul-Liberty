//----------------------------------------------------------
//
//  This file is part of the Siv3D Engine
//
//  Copyright (C) 2008-2014 Reputeless,
//
//  Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator + () const
{
	return *this;
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator - () const
{
	return { -x, -y, -z, -w };
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator + (const Vector4D<Type>& v) const
{
	return { x + v.x, y + v.y, z + v.z, w + v.w };
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator - (const Vector4D<Type>& v) const
{
	return { x - v.x, y - v.y, z - v.z, w - v.w };
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator * (Type s) const
{
	return { x*s, y*s, z*s, w*s };
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator * (const Vector4D<Type>& v) const
{
	return { x*v.x, y*v.y, z*v.z, w*v.w };
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::operator / (Type s) const
{
	return { x/s, y/s, z/s, w/s };
}

template<typename Type>
inline s3d::Vector4D<Type>& s3d::Vector4D<Type>::operator += (const Vector4D<Type>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

template<typename Type>
inline s3d::Vector4D<Type>& s3d::Vector4D<Type>::operator -= (const Vector4D<Type>& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

template<typename Type>
inline s3d::Vector4D<Type>& s3d::Vector4D<Type>::operator *= (Type s)
{
	x *= s;
	y *= s;
	z *= s;
	w *= s;
	return *this;
}

template<typename Type>
inline s3d::Vector4D<Type>& s3d::Vector4D<Type>::operator /= (Type s)
{
	return *this *= static_cast<Type>(1.0)/s;
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector4D<Type>::_get_xy() const
{
	return { x, y };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector4D<Type>::_get_yz() const
{
	return { y, z };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector4D<Type>::_get_zw() const
{
	return { z, w };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector4D<Type>::_get_xyz() const
{
	return { x, y, z };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector4D<Type>::_get_yzw() const
{
	return { y, z, w };
}

template<typename Type>
inline bool s3d::Vector4D<Type>::_get_isZero() const
{
	const Type zero = static_cast<Type>(0.0);
	return x==zero && y==zero && z==zero && w==zero; 
}

template<typename Type>
inline Type s3d::Vector4D<Type>::length() const
{
	return ::sqrt(lengthSq());
}

template<typename Type>
inline Type s3d::Vector4D<Type>::lengthSq() const
{
	return dot(*this);
}

template<typename Type>
inline Type s3d::Vector4D<Type>::lengthInv() const
{
	return static_cast<Type>(1.0)/length();
}

template<typename Type>
inline Type s3d::Vector4D<Type>::distanceFrom(const Vector4D& v) const
{
	return (*this-v).length();
}

template<typename Type>
inline Type s3d::Vector4D<Type>::distanceFromSq(const Vector4D& v) const
{
	return (*this-v).lengthSq();
}

template<typename Type>
inline Type s3d::Vector4D<Type>::dot(const Vector4D& v) const
{
	return x*v.x + y*v.y + z*v.z + w*v.w;
}

template<typename Type>
inline s3d::Vector4D<Type> s3d::Vector4D<Type>::normalized() const
{
	return *this * lengthInv();
}
