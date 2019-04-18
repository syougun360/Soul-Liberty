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
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator + () const
{
	return *this;
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator - () const
{
	return { -x, -y, -z };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator + (const Vector3D<Type>& v) const
{
	return { x + v.x, y + v.y, z + v.z };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator - (const Vector3D<Type>& v) const
{
	return { x - v.x, y - v.y, z - v.z };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator * (Type s) const
{
	return { x*s, y*s, z*s };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator * (const Vector3D<Type>& v) const
{
	return { x*v.x, y*v.y, z*v.z };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::operator / (Type s) const
{
	return { x / s, y / s, z / s };
}

template<typename Type>
inline s3d::Vector3D<Type>& s3d::Vector3D<Type>::operator += (const Vector3D<Type>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

template<typename Type>
inline s3d::Vector3D<Type>& s3d::Vector3D<Type>::operator -= (const Vector3D<Type>& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

template<typename Type>
inline s3d::Vector3D<Type>& s3d::Vector3D<Type>::operator *= (Type s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

template<typename Type>
inline s3d::Vector3D<Type>& s3d::Vector3D<Type>::operator /= (Type s)
{
	return *this *= static_cast<Type>(1.0)/s;
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector3D<Type>::_get_xy() const
{
	return { x, y };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector3D<Type>::_get_xz() const
{
	return { x, z };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector3D<Type>::_get_yz() const
{
	return { y, z };
}

template<typename Type>
inline bool s3d::Vector3D<Type>::_get_isZero() const
{
	const Type zero = static_cast<Type>(0.0);
	return x==zero && y==zero && z==zero; 
}

template<typename Type>
inline Type s3d::Vector3D<Type>::length() const
{
	return ::sqrt(lengthSq());
}

template<typename Type>
inline Type s3d::Vector3D<Type>::lengthSq() const
{
	return dot(*this);
}

template<typename Type>
inline Type s3d::Vector3D<Type>::lengthInv() const
{
	return static_cast<Type>(1.0)/length();
}

template<typename Type>
inline Type s3d::Vector3D<Type>::distanceFrom(const Vector3D& v) const
{
	return (*this-v).length();
}

template<typename Type>
inline Type s3d::Vector3D<Type>::distanceFromSq(const Vector3D& v) const
{
	return (*this-v).lengthSq();
}

template<typename Type>
inline Type s3d::Vector3D<Type>::dot(const Vector3D& v) const
{
	return x*v.x + y*v.y + z*v.z;
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::cross(const Vector3D& v) const
{
	return { y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x };
}

template<typename Type>
inline s3d::Vector3D<Type> s3d::Vector3D<Type>::normalized() const
{
	return *this * lengthInv();
}
