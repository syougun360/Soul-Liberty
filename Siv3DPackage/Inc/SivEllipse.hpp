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
	*	@brief 楕円
	*/
	struct Ellipse
	{
#pragma warning(disable:4201)
		union
		{
			struct { Vec2 center; Vec2 axis; };
			struct { double x, y, a, b; };
		};
#pragma warning(default:4201)

		/**
		*
		*/
		Ellipse(){}

		explicit Ellipse(double _r) : Ellipse{ 0, 0, _r, _r } {}

		Ellipse(double _a, double _b) : Ellipse{ 0, 0, _a, _b } {}

		Ellipse(double _x, double _y, double _r) : Ellipse{ _x, _y, _r, _r } {}

		Ellipse(double _x, double _y, double _a, double _b) : x{ _x }, y{ _y }, a{ _a }, b{ _b } {}

		explicit Ellipse(const Vec2& p) : Ellipse{ p, { 0, 0 } } {}

		Ellipse(const Vec2& p, double _r) : Ellipse{ p, { _r, _r } } {}

		Ellipse(const Vec2& p, double _a, double _b) : Ellipse{ p, { _a, _b } } {}

		Ellipse(double _x, double _y, const Vec2& _axis) : Ellipse{ { _x, _y }, _axis } {}

		Ellipse(const Vec2& p, const Vec2& _axis) : center{ p }, axis{ _axis } {}

		/**
		*	円の座標を設定します。
		*	@param _x x 座標
		*	@param _y y 座標
		*	@return *this
		*/
		Ellipse& setPos(double _x, double _y) { x = _x; y = _y; return *this; }

		/**
		*	楕円の座標を設定します。
		*	@param _pos 座標
		*	@return *this
		*/
		Ellipse& setPos(const Vec2& _pos) { center = _pos; return *this; }

		/**
		*	楕円の半径を設定します。
		*	@param _a
		*	@param _b
		*	@return *this
		*/
		Ellipse& setSize(double _a, double _b) { a = _a; b = _b; return *this; }

		/**
		*	楕円を移動します。
		*	@param _x 相対 x 座標
		*	@param _y 相対 y 座標
		*	@return *this
		*/
		Ellipse& moveBy(double _x, double _y) { center.moveBy(_x, _y); return *this; }

		/**
		*	楕円を移動します。
		*	@param v 相対座標
		*	@return *this
		*/
		Ellipse& moveBy(const Vec2& v) { center.moveBy(v); return *this; }

		/**
		*
		*	@param v
		*	@return
		*/
		Ellipse operator + (const Vec2& v) const { return { center + v, a, b }; }

		/**
		*
		*	@param v
		*	@return
		*/
		Ellipse operator - (const Vec2& v) const { return { center - v, a, b }; }

		/**
		*
		*	@param s
		*	@return
		*/
		Ellipse stretched(double s) const { return { center, a + s, b + s }; }

		/**
		*	楕円の面積を求めます。
		*	@return 面積
		*/
		double area() const;

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
		*	イメージに楕円を描画します。
		*	@param image 描画先のイメージ
		*	@param color 描画色
		*/
		void write(Image& image, const Color& color = Palette::Black) const;

		/**
		*
		*	@param color
		*	@return
		*/
		const Ellipse& draw(const Color& color = Palette::White) const;

		/**
		*
		*	@param innerThickness
		*	@param outerThickness
		*	@param color
		*	@return
		*/
		const Ellipse& drawFrame(double innerThickness = 1.0, double outerThickness = 0.0, const Color& color = Palette::White) const;
	};

	/**
	*	出力ストリームに楕円の情報を渡します。
	*	@param os 出力ストリーム
	*	@param c 楕円
	*	@return 出力ストリーム
	*/
	template<typename CharType>
	inline
		std::basic_ostream<CharType>&
		operator << (
		std::basic_ostream<CharType>& os,
		const Ellipse& c
		)
	{
		return os << CharType('(') << c.x << CharType(',') << c.y << CharType(',') << c.a << CharType(',') << c.b << CharType(')');
	}

	/**
	*	入力ストリームに楕円の情報を渡します。
	*	@param is 入力ストリーム
	*	@param c 楕円
	*	@return 入力ストリーム
	*/
	template<typename CharType>
	inline
		std::basic_istream<CharType>&
		operator >> (
		std::basic_istream<CharType>& is,
		Ellipse& c
		)
	{
		CharType unused;
		return is >> unused >> c.x >> unused >> c.y >> unused >> c.a >> unused >> c.b >> unused;
	}
}
