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
# include <cfloat>
# include <emmintrin.h>
# include "SivPointVector.hpp"
# include "SivQuad.hpp"
# include "SivUtility.hpp"

# define MATH_FUNCTION1_VECTOR(F)\
	inline float F(float v)\
	{\
	return static_cast<float>(F(static_cast<double>(v))); \
	}\
	\
	template<typename Type>\
	inline Vector2D<Type> F(const Vector2D<Type>& v)\
	{\
	return Vector2D<Type>(F(v.x), F(v.y)); \
	}\
	\
	template<typename Type>\
	inline Vector3D<Type> F(const Vector3D<Type>& v)\
	{\
	return Vector3D<Type>(F(v.x), F(v.y), F(v.z)); \
	}\
	\
	template<typename Type>\
	inline Vector4D<Type> F(const Vector4D<Type>& v)\
	{\
	return Vector4D<Type>(F(v.x), F(v.y), F(v.z), F(v.w)); \
	}

# define MATH_FUNCTION2_VECTOR(F)\
	inline float F(float v0, float v1)\
	{\
	return static_cast<float>(F(static_cast<double>(v0), static_cast<double>(v1))); \
	}\
	\
	template<typename Type>\
	inline Vector2D<Type> F(const Vector2D<Type>& v0, const Vector2D<Type>& v1)\
	{\
	return Vector2D<Type>(F(v0.x, v1.x), F(v0.y, v1.y)); \
	}\
	\
	template<typename Type>\
	inline Vector3D<Type> F(const Vector3D<Type>& v0, const Vector3D<Type>& v1)\
	{\
	return Vector3D<Type>(F(v0.x, v1.x), F(v0.y, v1.y), F(v0.z, v1.z)); \
	}\
	\
	template<typename Type>\
	inline Vector4D<Type> F(const Vector4D<Type>& v0, const Vector4D<Type>& v1)\
	{\
	return Vector4D<Type>(F(v0.x, v1.x), F(v0.y, v1.y), F(v0.z, v1.z), F(v0.w, v1.w)); \
	}

# define MATH_FUNCTION2R_VECTOR(F)\
	inline float F(float v0, float& v1)\
	{\
	double tmp; \
	float result = static_cast<float>(F(static_cast<double>(v0), tmp)); \
	v1 = static_cast<float>(tmp); \
	return result; \
	}\
	\
	template<typename Type>\
	inline Vector2D<Type> F(const Vector2D<Type>& v0, Vector2D<Type>& v1)\
	{\
	return Vector2D<Type>(F(v0.x, v1.x), F(v0.y, v1.y)); \
	}\
	\
	template<typename Type>\
	inline Vector3D<Type> F(const Vector3D<Type>& v0, Vector3D<Type>& v1)\
	{\
	return Vector3D<Type>(F(v0.x, v1.x), F(v0.y, v1.y), F(v0.z, v1.z)); \
	}\
	\
	template<typename Type>\
	inline Vector4D<Type> F(const Vector4D<Type>& v0, Vector4D<Type>& v1)\
	{\
	return Vector4D<Type>(F(v0.x, v1.x), F(v0.y, v1.y), F(v0.z, v1.z), F(v0.w, v1.w)); \
	}

# define MATH_FUNCTION3VSS_VECTOR(F)\
	template<typename Type>\
	inline Vector2D<Type> F(const Vector2D<Type>& v, Type a, Type b)\
	{\
	return Vector2D<Type>(F(v.x, a, b), F(v.y, a, b)); \
	}\
	\
	template<typename Type>\
	inline Vector3D<Type> F(const Vector3D<Type>& v, Type a, Type b)\
	{\
	return Vector3D<Type>(F(v.x, a, b), F(v.y, a, b), F(v.z, a, b)); \
	}\
	\
	template<typename Type>\
	inline Vector4D<Type> F(const Vector4D<Type>& v, Type a, Type b)\
	{\
	return Vector3D<Type>(F(v.x, a, b), F(v.y, a, b), F(v.z, a, b), F(v.w, a, b)); \
	}

# define RADIANS    (0.01745329251994329577)
# define DEGREES    (57.2957795130823208768)
const __m128d  m128dD0 = _mm_set1_pd(0.0);
const __m128d  m128dD05 = _mm_set1_pd(0.5);
const __m128d  m128dD1 = _mm_set1_pd(1.0);
const __m128d  m128dD3 = _mm_set1_pd(3.0);

namespace s3d
{
	namespace Math
	{
		/**
		*	剰余を取得
		*	@param x
		*	@param y
		*	@return
		*/
		inline double Fmod(double x, double y)
		{
			return ::fmod(x, y);
		}

		/**
		*	小数部分 [0.0,1.0) を返す
		*	@param x
		*	@return
		*/
		inline double Fraction(double x)
		{
			return (x - ::floor(x));
		}

		/**
		*	仮数部と指数部の取得
		*	@param x
		*	@param exp
		*	@return
		*/
		inline double Frexp(double x, double& exp)
		{
			int e;
			const double tmp = ::frexp(x, &e);
			exp = static_cast<double>(e);
			return tmp;
		}

		/**
		*	v * 2^_exp を取得
		*	@param x
		*	@param exp
		*	@return
		*/
		inline double Ldexp(double x, double exp)
		{
			return x * ::pow(2.0, exp);
		}

		/**
		*	e を底とする対数を取得
		*	@param x
		*	@return
		*/
		inline double Log(double x)
		{
			return ::log(x);
		}

		/**
		*	2 を底とする対数を取得
		*	@param x
		*	@return
		*/
		inline double Log2(double x)
		{
			return ::log2(x);
		}

		/**
		*	10 を底とする対数を取得
		*	@param x
		*	@return
		*/
		inline double Log10(double x)
		{
			return ::log10(x);
		}

		/**
		*	小数部と整数部に分割
		*	@param x
		*	@param i
		*	@return
		*/
		inline double Modf(double x, double& i)
		{
			return ::modf(x, &i);
		}

		/**
		*	べき乗を計算
		*	@param x
		*	@param y
		*	@return
		*/
		inline double Pow(double x, double y)
		{
			return ::pow(x, y);
		}

		/**
		*	符号を示す値を取得
		*	@param x
		*	@return
		*/
		inline double Sign(double x)
		{
			if (x <0.0)
			{
				return -1.0;
			}
			else if (x > 0.0)
			{
				return 1.0;
			}
			else
			{
				return 0.0;
			}
		}

		/**
		*	度数からラジアンに変換
		*	@param x
		*	@return
		*/
		inline double Radians(double x)
		{
			return x * RADIANS;
		}

		/**
		*
		*	@param x
		*	@return
		*/
		inline double Radians(int x)
		{
			return x * RADIANS;
		}

		/**
		*	ラジアンから度数に変換
		*	@param x
		*	@return
		*/
		inline double Degrees(double x)
		{
			return x * DEGREES;
		}

		/**
		*	v が有限なら 1
		*	@param x
		*	@return
		*/
		inline bool Isfinite(double x)
		{
			return !!(::_finite(x));
		}

		/**
		*	v が +INF または -INF なら 1
		*	@param x
		*	@return
		*/
		inline bool Isinf(double x)
		{
			const int cl = ::_fpclass(x);
			return cl == _FPCLASS_PINF || cl == _FPCLASS_NINF;
		}

		/**
		*	v が NaN または QNaN なら 1
		*	@param x
		*	@return
		*/
		inline bool Isnan(double x)
		{
			return !!(::_isnan(x));
		}

		/**
		*	絶対値
		*	@param x
		*	@return
		*/
		template<typename Type>
		inline Type Abs(Type x)
		{
			return abs(x);
		}

		/**
		*	e を底とする指数
		*	@param x
		*	@return
		*/
		inline double Exp(double x)
		{
			return ::exp(x);
		}

		/**
		*	2 を底とする指数
		*	@param x
		*	@return
		*/
		inline double Exp2(double x)
		{
			return ::pow(2.0, x);
		}

		/**
		*	平方根の逆数
		*	@param x
		*	@return
		*/
		inline double Rsqrt(double x)
		{
			const float fx = static_cast<float>(x);
			const __m128d xx = _mm_load_sd(&x);
			__m128d xr = _mm_cvtss_sd(xx, _mm_rsqrt_ss(_mm_load_ss(&fx)));
			__m128d xt;

			xt = _mm_mul_sd(xr, xr);
			xt = _mm_mul_sd(xt, xx);
			xt = _mm_sub_sd(m128dD3, xt);
			xt = _mm_mul_sd(xt, m128dD05);
			xr = _mm_mul_sd(xr, xt);
			_mm_store_sd(&x, xr);

			return x;
		}

		/**
		*	平方根
		*	@param x
		*	@return
		*/
		inline double Sqrt(double x)
		{
			return ::sqrt(x);
		}

		/**
		*
		*	@param v
		*	@return
		*/
		inline Vec2 Sqrt(const Vec2& v)
		{
			Vec2 t(v);
			_mm_storeu_pd(&t.x, _mm_sqrt_pd(_mm_set_pd(t.y, t.x)));
			return t;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		inline Vec3 Sqrt(const Vec3& v)
		{
			Vec3 t(v);
			_mm_storeu_pd(&t.x, _mm_sqrt_pd(_mm_set_pd(t.y, t.x)));
			t.z = ::sqrt(t.z);
			return t;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		inline Vec4 Sqrt(const Vec4& v)
		{
			Vec4 t(v);
			_mm_storeu_pd(&t.x, _mm_sqrt_pd(_mm_set_pd(t.y, t.x)));
			_mm_storeu_pd(&t.z, _mm_sqrt_pd(_mm_set_pd(t.w, t.z)));
			return t;
		}

		/**
		*	x 以上の最小の整数
		*	@param x
		*	@return
		*/
		inline double Ceil(double x)
		{
			return ::ceil(x);
		}

		/**
		*	x 以下の最大の整数
		*	@param x
		*	@return
		*/
		inline double Floor(double x)
		{
			return ::floor(x);
		}

		/**
		*	四捨五入
		*	@param x
		*	@return
		*/
		inline double Round(double x)
		{
			return round(x);
		}

		/**
		*	成分を [_min,_max] に制限
		*	@param v
		*	@param _min
		*	@param _max
		*	@return
		*/
		inline Float2 Clamp(const Float2& v, float _min, float _max)
		{
			return{ s3d::Clamp(v.x, _min, _max), s3d::Clamp(v.y, _min, _max) };
		}

		/**
		*	成分を [_min,_max] に制限
		*	@param v
		*	@param _min
		*	@param _max
		*	@return
		*/
		inline Float3 Clamp(const Float3& v, float _min, float _max)
		{
			return{ s3d::Clamp(v.x, _min, _max), s3d::Clamp(v.y, _min, _max), s3d::Clamp(v.z, _min, _max) };
		}

		/**
		*	成分を [_min,_max] に制限
		*	@param v
		*	@param _min
		*	@param _max
		*	@return
		*/
		inline Float4 Clamp(const Float4& v, float _min, float _max)
		{
			return{ s3d::Clamp(v.x, _min, _max), s3d::Clamp(v.y, _min, _max), s3d::Clamp(v.z, _min, _max), s3d::Clamp(v.w, _min, _max) };
		}

		/**
		*	成分を [_min,_max] に制限
		*	@param v
		*	@param _min
		*	@param _max
		*	@return
		*/
		inline Vec2 Clamp(const Vec2& v, double _min, double _max)
		{
			const __m128d x0 = _mm_loadu_pd(&v.x);
			const __m128d xmin = _mm_set1_pd(_min);
			const __m128d xmax = _mm_set1_pd(_max);
			Vec2 t;
			_mm_storeu_pd(&t.x, _mm_min_pd(_mm_max_pd(xmin, x0), xmax));
			return t;
		}

		/**
		*
		*	@param v
		*	@param _min
		*	@param _max
		*	@return
		*/
		inline Vec3 Clamp(const Vec3& v, double _min, double _max)
		{
			const __m128d x0 = _mm_loadu_pd(&v.x);
			const __m128d x1 = _mm_set_sd(v.z);
			const __m128d xmin = _mm_set1_pd(_min);
			const __m128d xmax = _mm_set1_pd(_max);
			Vec3 t;
			_mm_storeu_pd(&t.x, _mm_min_pd(_mm_max_pd(xmin, x0), xmax));
			_mm_store_sd(&t.z, _mm_min_sd(_mm_max_sd(xmin, x1), xmax));
			return t;
		}

		/**
		*
		*	@param v
		*	@param _min
		*	@param _max
		*	@return
		*/
		inline Vec4 Clamp(const Vec4& v, double _min, double _max)
		{
			const __m128d x0 = _mm_loadu_pd(&v.x);
			const __m128d x1 = _mm_loadu_pd(&v.z);
			const __m128d xmin = _mm_set1_pd(_min);
			const __m128d xmax = _mm_set1_pd(_max);
			Vec4 t;
			_mm_storeu_pd(&t.x, _mm_min_pd(_mm_max_pd(xmin, x0), xmax));
			_mm_storeu_pd(&t.z, _mm_min_pd(_mm_max_pd(xmin, x1), xmax));
			return t;
		}

		/**
		*	成分を [0,1] に制限
		*	@param x
		*	@return
		*/
		inline double Saturate(double x)
		{
			return	1.0 < x ? 1.0 : x < 0.0 ? 0.0 : x;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		inline Vec2 Saturate(const Vec2& v)
		{
			const __m128d x0 = _mm_loadu_pd(&v.x);
			Vec2 t;
			_mm_storeu_pd(&t.x, _mm_min_pd(_mm_max_pd(m128dD0, x0), m128dD1));
			return t;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		inline Vec3 Saturate(const Vec3& v)
		{
			const __m128d x0 = _mm_loadu_pd(&v.x);
			const __m128d x1 = _mm_set_sd(v.z);
			Vec3 t;
			_mm_storeu_pd(&t.x, _mm_min_pd(_mm_max_pd(m128dD0, x0), m128dD1));
			_mm_store_sd(&t.z, _mm_min_sd(_mm_max_sd(m128dD0, x1), m128dD1));
			return t;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		inline Vec4 Saturate(const Vec4& v)
		{
			const __m128d x0 = _mm_loadu_pd(&v.x);
			const __m128d x1 = _mm_loadu_pd(&v.z);
			Vec4 t;
			_mm_storeu_pd(&t.x, _mm_min_pd(_mm_max_pd(m128dD0, x0), m128dD1));
			_mm_storeu_pd(&t.z, _mm_min_pd(_mm_max_pd(m128dD0, x1), m128dD1));
			return v;
		}

		/**
		*	アークコサイン
		*	@param x
		*	@return
		*/
		inline double Acos(double x)
		{
			return ::acos(x);
		}

		/**
		*	アークサイン
		*	@param x
		*	@return
		*/
		inline double Asin(double x)
		{
			return ::asin(x);
		}

		/**
		*	アークタンジェント
		*	@param x
		*	@return
		*/
		inline double Atan(double x)
		{
			return ::atan(x);
		}

		/**
		*	vy/vx のアークタンジェント
		*	@param vy
		*	@param vx
		*	@return
		*/
		inline double Atan2(double vy, double vx)
		{
			return ::atan2(vy, vx);
		}

		/**
		*	コサイン
		*	@param x
		*	@return
		*/
		inline double Cos(double x)
		{
			return ::cos(x);
		}

		/**
		*	ハイパボリックコサイン
		*	@param x
		*	@return
		*/
		inline double Cosh(double x)
		{
			return ::cosh(x);
		}

		/**
		*	サイン
		*	@param x
		*	@return
		*/
		inline double Sin(double x)
		{
			return ::sin(x);
		}

		/**
		*	ハイパボリックサイン
		*	@param x
		*	@return
		*/
		inline double Sinh(double x)
		{
			return ::sinh(x);
		}

		/**
		*	タンジェント
		*	@param x
		*	@return
		*/
		inline double Tan(double x)
		{
			return ::tan(x);
		}

		/**
		*	ハイパボリックタンジェント
		*	@param x
		*	@return
		*/
		inline double Tanh(double x)
		{
			return ::tanh(x);
		}

		/**
		*	正規化
		*	@param x
		*	@return
		*/
		inline double Normalize(double x)
		{
			return x ? 1.0 : 0.0;
		}

		/**
		*
		*	@param v
		*	@return
		*/
		template<typename Type>
		inline Vector2D<Type> Normalize(const Vector2D<Type>& v)
		{
			return v * v.lengthInv();
		}

		/**
		*
		*	@param v
		*	@return
		*/
		template<typename Type>
		inline Vector3D<Type> Normalize(const Vector3D<Type>& v)
		{
			return v * v.lengthInv();
		}

		/**
		*
		*	@param v
		*	@return
		*/
		template<typename Type>
		inline Vector4D<Type> Normalize(const Vector4D<Type>& v)
		{
			return v * v.lengthInv();
		}

		/**
		*	線形補間
		*	@param v1
		*	@param v2
		*	@param f
		*	@return
		*/
		inline float Lerp(float v1, float v2, float f)
		{
			return v1 + (v2 - v1)*f;
		}

		/**
		*
		*	@param v1
		*	@param v2
		*	@param f
		*	@return
		*/
		inline double Lerp(double v1, double v2, double f)
		{
			return v1 + (v2 - v1)*f;
		}

		/**
		*
		*	@param v1
		*	@param v2
		*	@param f
		*	@return
		*/
		template<typename Type>
		inline Vector2D<Type> Lerp(const Vector2D<Type>& v1, const Vector2D<Type>& v2, Type f)
		{
			return v1 + (v2 - v1)*f;
		}

		/**
		*
		*	@param v1
		*	@param v2
		*	@param f
		*	@return
		*/
		template<typename Type>
		inline Vector3D<Type> Lerp(const Vector3D<Type>& v1, const Vector3D<Type>& v2, Type f)
		{
			return v1 + (v2 - v1)*f;
		}

		/**
		*
		*	@param v1
		*	@param v2
		*	@param f
		*	@return
		*/
		template<typename Type>
		inline Vector4D<Type> Lerp(const Vector4D<Type>& v1, const Vector4D<Type>& v2, Type f)
		{
			return v1 + (v2 - v1)*f;
		}

		/**
		*
		*	@param min
		*	@param max
		*	@param x
		*	@return
		*/
		inline float Smoothstep(float min, float max, float x)
		{
			if (x <= min)
			{
				return 0.0f;
			}
			else if (max <= x)
			{
				return 1.0f;
			}

			x = (x - min) / (max - min);

			return x*x*(3.0f - 2.0f*x);
		}

		/**
		*
		*	@param min
		*	@param max
		*	@param x
		*	@return
		*/
		inline double Smoothstep(double min, double max, double x)
		{
			if (x <= min)
			{
				return 0.0;
			}
			else if (max <= x)
			{
				return 1.0;
			}

			x = (x - min) / (max - min);

			return x*x*(3.0 - 2.0*x);
		}

		/**
		*
		*	@param min
		*	@param max
		*	@param x
		*	@return
		*/
		inline float Smoothstep(float x)
		{
			if (x <= 0.0f)
			{
				return 0.0f;
			}
			else if (1.0f <= x)
			{
				return 1.0f;
			}

			return x*x*(3.0f - 2.0f*x);
		}

		/**
		*
		*	@param min
		*	@param max
		*	@param x
		*	@return
		*/
		inline double Smoothstep(double x)
		{
			if (x <= 0.0)
			{
				return 0.0;
			}
			else if (1.0 <= x)
			{
				return 1.0;
			}

			return x*x*(3.0 - 2.0*x);
		}


		MATH_FUNCTION2_VECTOR(Fmod);
		MATH_FUNCTION1_VECTOR(Fraction);
		MATH_FUNCTION2R_VECTOR(Frexp);
		MATH_FUNCTION2_VECTOR(Ldexp);
		MATH_FUNCTION1_VECTOR(Log);
		MATH_FUNCTION1_VECTOR(Log2);
		MATH_FUNCTION1_VECTOR(Log10);
		MATH_FUNCTION2R_VECTOR(Modf);
		MATH_FUNCTION2_VECTOR(Pow);
		MATH_FUNCTION1_VECTOR(Sign);
		MATH_FUNCTION1_VECTOR(Radians);
		MATH_FUNCTION1_VECTOR(Degrees);
		MATH_FUNCTION1_VECTOR(Abs);
		MATH_FUNCTION1_VECTOR(Exp);
		MATH_FUNCTION1_VECTOR(Exp2);
		MATH_FUNCTION1_VECTOR(Rsqrt);
		MATH_FUNCTION1_VECTOR(Sqrt);
		MATH_FUNCTION1_VECTOR(Ceil);
		MATH_FUNCTION1_VECTOR(Floor);
		MATH_FUNCTION1_VECTOR(Round);
		MATH_FUNCTION1_VECTOR(Saturate);
		MATH_FUNCTION1_VECTOR(Acos);
		MATH_FUNCTION1_VECTOR(Asin);
		MATH_FUNCTION1_VECTOR(Atan);
		MATH_FUNCTION2_VECTOR(Atan2);
		MATH_FUNCTION1_VECTOR(Cos);
		MATH_FUNCTION1_VECTOR(Cosh);
		MATH_FUNCTION1_VECTOR(Sin);
		MATH_FUNCTION1_VECTOR(Sinh);
		MATH_FUNCTION1_VECTOR(Tan);
		MATH_FUNCTION1_VECTOR(Tanh);
	}

	struct FloatRect
	{
		float left, top, right, bottom;
		
		/**
		*
		*/
		FloatRect(){}

		/**
		*
		*	@param l
		*	@param t
		*	@param r
		*	@param b
		*/
		FloatRect(float l, float t, float r, float b) : left(l), top(t), right(r), bottom(b){}

		/**
		*
		*	@param l
		*	@param t
		*	@param r
		*	@param b
		*/
		FloatRect(int l, int t, int r, int b) : left(static_cast<float>(l)), top(static_cast<float>(t)), right(static_cast<float>(r)), bottom(static_cast<float>(b)){}

		/**
		*
		*	@param l
		*	@param t
		*	@param r
		*	@param b
		*/
		FloatRect(double l, double t, double r, double b) : left(static_cast<float>(l)), top(static_cast<float>(t)), right(static_cast<float>(r)), bottom(static_cast<float>(b)){}
	};

	struct FloatQuad
	{
		Float2 tl, tr, br, bl;

		/**
		*
		*/
		FloatQuad(){}

		/**
		*
		*	@param _tl
		*	@param _tr
		*	@param _br
		*	@param _bl
		*/
		FloatQuad(const Vec2& _tl, const Vec2& _tr, const Vec2& _br, const Vec2& _bl) : tl(_tl), tr(_tr), br(_br), bl(_bl){}

		/**
		*
		*	@param q
		*/
		FloatQuad(const Quad& q) : tl(q.tl), tr(q.tr), br(q.br), bl(q.bl){}
	};
}

# undef RADIANS
# undef DEGREES
# undef M_LOG2E
# undef MATH_FUNCTION1_VECTOR
# undef MATH_FUNCTION2_VECTOR
# undef MATH_FUNCTION2R_VECTOR
# undef MATH_FUNCTION3VSS_VECTOR
