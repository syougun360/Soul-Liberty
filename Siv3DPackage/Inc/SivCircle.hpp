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
# include "SivPropertyMacro.hpp"
# include "SivPointVector.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief 円
	*/
	struct Circle
	{
#pragma warning(disable:4201)
		union
		{
			struct { Vec2 center; double r; };
			struct { double x, y, r; };
		};
#pragma warning(default:4201)

		/**
		*
		*/
		Circle(){}

		/**
		*	円を初期化します。
		*	@param _r 半径
		*/
		explicit Circle(double _r) : x(0), y(0), r(_r){}

		/**
		*	円を初期化します。
		*	@param _x x 座標
		*	@param _y y 座標
		*	@param _r 半径
		*/
		Circle(double _x, double _y, double _r) : x(_x), y(_y), r(_r){}

		/**
		*	円を初期化します。
		*	@param p 座標
		*/
		explicit Circle(const Vec2& p) : center(p), r(0.0){}

		/**
		*	円を初期化します。
		*	@param p 座標
		*	@param _r 半径
		*/
		Circle(const Vec2& p, double _r) : center(p), r(_r){}

		/**
		*	円の座標を設定します。
		*	@param _x x 座標
		*	@param _y y 座標
		*	@return *this
		*/
		Circle& setPos(double _x, double _y) { x = _x; y = _y; return *this; }

		/**
		*	円の座標を設定します。
		*	@param _pos 座標
		*	@return *this
		*/
		Circle& setPos(const Vec2& _pos) { center = _pos; return *this; }

		/**
		*	円の半径を設定します。
		*	@param _r 半径
		*	@return *this
		*/
		Circle& setSize(double _r) { r = _r; return *this; }

		/**
		*	円を移動します。
		*	@param _x 相対 x 座標
		*	@param _y 相対 y 座標
		*	@return *this
		*/
		Circle& moveBy(double _x, double _y) { center.moveBy(_x, _y); return *this; }

		/**
		*	円を移動します。
		*	@param v 相対座標
		*	@return *this
		*/
		Circle& moveBy(const Vec2& v) { center.moveBy(v); return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Circle operator + (const Vec2& v) const { return { center + v, r }; }

		/**
		*
		*	@param v
		*	@return
		*/
		Circle operator - (const Vec2& v) const { return { center - v, r }; }

		/**
		*
		*	@param s
		*	@return
		*/
		Circle stretched(double s) const { return { center, r + s }; }

		/**
		*	円の面積を求めます。
		*	@return 面積
		*/
		double area() const;

		/**
		*
		*	@return
		*/
		double perimeter() const;

		/**
		*	他の図形との接触判定を行います。
		*	@param shape 接触判定を行う図形
		*	@return 接触している場合は true, それ以外は false
		*/
		template<typename Shape>
		bool intersects(const Shape& shape) const
		{
			return Geometry::Intersect(*this, shape);
		}

		/**
		*
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		__declspec(deprecated("** Circle::within(SHAPE) is deprecated; use SHAPE::contains(circle) instead **"))
		bool within(const Shape& shape) const
		{
			return Geometry::Within(*this, shape);
		}

		/**
		*
		*	@param shape
		*	@return
		*/
		template<typename Shape>
		bool contains(const Shape& shape) const
		{
			return Geometry::Within(shape, *this);
		}

		/**
		*	左クリックされたかを返します。
		*/
		Property_Get(bool, leftClicked) const;

		/**
		*	左クリックされているかを返します。
		*/
		Property_Get(bool, leftPressed) const;

		/**
		*	左クリックが離されたかを返します。
		*/
		Property_Get(bool, leftReleased) const;

		/**
		*	右クリックされたかを返します。
		*/
		Property_Get(bool, rightClicked) const;

		/**
		*	右クリックされているかを返します。
		*/
		Property_Get(bool, rightPressed) const;

		/**
		*	右クリックが離されたかを返します。
		*/
		Property_Get(bool, rightReleased) const;

		/**
		*	マウスカーソルが図形上にあるかを返します。
		*/
		Property_Get(bool, mouseOver) const;

		/**
		*	イメージに円を描画します。
		*	@param image 描画先のイメージ
		*	@param color 描画色
		*/
		void write(Image& image, const Color& color = Palette::Black) const;

		/**
		*	イメージに扇形を描画します。
		*	@param image 描画先のイメージ
		*	@param startAngle 角度のオフセット
		*	@param angle 描画する角度
		*	@param color 描画色
		*/
		void writePie(Image& image, double startAngle, double angle, const Color& color = Palette::Black) const;

		/**
		*
		*	@param color
		*	@return
		*/
		const Circle& draw(const Color& color = Palette::White) const;

		/**
		*
		*	@param innerThickness
		*	@param outerThickness
		*	@param color
		*	@return
		*/
		const Circle& drawFrame(double innerThickness = 1.0, double outerThickness = 0.0, const Color& color = Palette::White) const;

		/**
		*
		*	@param startAngle
		*	@param angle
		*	@param color
		*/
		void drawPie(double startAngle, double angle, const Color& color = Palette::White) const;

		/**
		*
		*	@param startAngle
		*	@param angle
		*	@param innerThickness
		*	@param outerThickness
		*	@param color
		*/
		void drawArc(double startAngle, double angle, double innerThickness = 1.0, double outerThickness = 0.0, const Color& color = Palette::White) const;
	};

	/**
	*	出力ストリームに円の情報を渡します。
	*	@param os 出力ストリーム
	*	@param c 円
	*	@return 出力ストリーム
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Circle& c
		)
	{
		return os << CharType('(') << c.x << CharType(',') << c.y << CharType(',') << c.r << CharType(')');
	}

	/**
	*	入力ストリームに円の情報を渡します。
	*	@param is 入力ストリーム
	*	@param c 円
	*	@return 入力ストリーム
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Circle& c
		)
	{
		CharType unused;
		return is >> unused >> c.x >> unused >> c.y >> unused >> c.r >> unused;
	}
}
