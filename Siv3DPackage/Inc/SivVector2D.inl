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
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator + () const
{
	return *this;
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator - () const
{
	return { -x, -y };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator + (const Vector2D<Type>& v) const
{
	return { x + v.x, y + v.y };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator - (const Vector2D<Type>& v) const
{
	return { x - v.x, y - v.y };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator * (Type s) const
{
	return { x*s, y*s };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator * (const Vector2D<Type>& v) const
{
	return { x*v.x, y*v.y };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::operator / (Type s) const
{
	return { x / s, y / s };
}

template<typename Type>
inline s3d::Vector2D<Type>& s3d::Vector2D<Type>::operator += (const Vector2D<Type>& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

template<typename Type>
inline s3d::Vector2D<Type>& s3d::Vector2D<Type>::operator -= (const Vector2D<Type>& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

template<typename Type>
inline s3d::Vector2D<Type>& s3d::Vector2D<Type>::operator *= (Type s)
{
	x *= s;
	y *= s;
	return *this;
}

template<typename Type>
inline s3d::Vector2D<Type>& s3d::Vector2D<Type>::operator /= (Type s)
{
	return *this *= static_cast<Type>(1.0)/s;
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::_get_xx() const
{
	return { x, x };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::_get_xy() const
{
	return *this;
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::_get_yx() const
{
	return { y, x };
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::_get_yy() const
{
	return { y, y };
}

template<typename Type>
inline s3d::Point s3d::Vector2D<Type>::asPoint() const
{
	return { static_cast<int>(x), static_cast<int>(y) };
}

template<typename Type>
inline bool s3d::Vector2D<Type>::_get_isZero() const
{
	const Type zero = static_cast<Type>(0.0);
	return x==zero && y==zero; 
}

template<typename Type>
inline Type s3d::Vector2D<Type>::length() const
{
	return ::sqrt(lengthSq());
}

template<typename Type>
inline Type s3d::Vector2D<Type>::lengthSq() const
{
	return dot(*this);
}

template<typename Type>
inline Type s3d::Vector2D<Type>::lengthInv() const
{
	return static_cast<Type>(1.0)/length();
}

template<typename Type>
inline Type s3d::Vector2D<Type>::distanceFrom(const Vector2D& v) const
{
	return (*this-v).length();
}

template<typename Type>
inline Type s3d::Vector2D<Type>::distanceFromSq(const Vector2D& v) const
{
	return (*this-v).lengthSq();
}

template<typename Type>
inline Type s3d::Vector2D<Type>::dot(const Vector2D& v) const
{
	return x*v.x + y*v.y;
}

template<typename Type>
inline s3d::Vector2D<Type> s3d::Vector2D<Type>::normalized() const
{
	return *this * lengthInv();
}
