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
# include "SivPointVector.hpp"

namespace s3d
{
	/**
	*	@brief 2 次元図形の作成と幾何計算
	*/
	namespace Geometry
	{
		/**
		*	長方形の頂点配列を返します。
		*	@param w 長方形の幅
		*	@param h 長方形の高さ
		*	@param center 長方形の中心座標
		*	@return 長方形の頂点配列
		*/
		std::vector<Vec2>
			CreateRect(
			double w,
			double h,
			const Vec2& center = { 0.0, 0.0 }
			);

		/**
		*	十字形の頂点配列を返します。
		*	@param r 一番離れた辺から中心点までの距離
		*	@param width 十字形を構成する 2 線分の太さ
		*	@param center 十字形の中心座標
		*	@return 十字形の頂点配列
		*/
		std::vector<Vec2>
			CreatePlus(
			double r,
			double width,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	正五角形の頂点配列を返します。
		*	@param r 外接円の半径
		*	@param angle 時計方向への回転角度[ラジアン], 0 のとき頂点が 12 時の位置と重なる
		*	@param center 正五角形の中心座標
		*	@return 正五角形の頂点配列
		*/
		std::vector<Vec2>
			CreatePentagon(
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	正六角形の頂点配列を返します。
		*	@param r 外接円の半径
		*	@param angle 時計方向への回転角度[ラジアン], 0 のとき頂点が 12 時の位置と重なる
		*	@param center 正六角形の中心座標
		*	@return 正六角形の頂点配列
		*/
		std::vector<Vec2>
			CreateHexagon(
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	正 N 角形の頂点配列を返します。
		*	@param n 頂点の数
		*	@param r 外接円の半径
		*	@param angle 時計方向への回転角度[ラジアン], 0 のとき頂点が 12 時の位置と重なる
		*	@param center 正 N 角形の中心座標
		*	@return 正 N 角形の頂点配列、n<3 の場合は空の配列
		*/
		std::vector<Vec2>
			CreateNgon(
			int n,
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	五光星 (☆) の頂点配列を返します。
		*	http://ja.wikipedia.org/wiki/%E4%BA%94%E8%8A%92%E6%98%9F
		*	@param r 外接円の半径
		*	@param angle 時計方向への回転角度[ラジアン], 0 のとき頂点が 12 時の位置と重なる
		*	@param center 五光星の中心座標
		*	@return 五光星の頂点配列
		*/
		std::vector<Vec2>
			CreateStar(
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	星形図形の頂点配列を返します。
		*	@param n 光の数（五光星 ☆ の場合、5）
		*	@param rOuter 中心から外側の頂点までの距離
		*	@param rInner 中心から内側の頂点までの距離
		*	@param angle 時計方向への回転角度[ラジアン], 0 のとき頂点が 12 時の位置と重なる
		*	@param center 図形の中心座標
		*	@return 星形図形の頂点配列、n<2 の場合は空の配列
		*/
		std::vector<Vec2>
			CreateNStar(
			int n,
			double rOuter,
			double rInner,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);



		bool Intersect(const Point& a, const Point&		b);
		bool Intersect(const Point& a, const Rect&		b);
		bool Intersect(const Point& a, const RectF&		b);

		bool Intersect(const Vec2&  a, const Vec2&			b);
		bool Intersect(const Vec2&  a, const RectF&			b);
		bool Intersect(const Vec2&  a, const Circle&		b);
		bool Intersect(const Vec2&  a, const Ellipse&		b);
		bool Intersect(const Vec2&  a, const Line&			b);
		bool Intersect(const Vec2&  a, const Triangle&		b);
		bool Intersect(const Vec2&  a, const Quad&			b);
		bool Intersect(const Vec2&  a, const Polygon&		b);
		bool Intersect(const Vec2&  a, const LineString&	b);

		bool Intersect(const Rect& a, const Point&		b);
		bool Intersect(const Rect& a, const Rect&		b);
		bool Intersect(const Rect& a, const RectF&		b);

		bool Intersect(const RectF& a, const Point&		b);
		bool Intersect(const RectF& a, const Vec2&		b);
		bool Intersect(const RectF& a, const Rect&		b);
		bool Intersect(const RectF& a, const RectF&		b);
		bool Intersect(const RectF& a, const Circle&	b);
		//bool Intersect(const RectF& a, const Ellipse&	b);
		bool Intersect(const RectF& a, const Line&		b);
		bool Intersect(const RectF& a, const Triangle&	b);
		bool Intersect(const RectF& a, const Quad&		b);
		bool Intersect(const RectF& a, const Polygon&	b);
		//bool Intersect( const RectF& a, const LineString& b );

		bool Intersect(const Circle& a, const Vec2&				b);
		bool Intersect(const Circle& a, const RectF&			b);
		bool Intersect(const Circle& a, const Circle&			b);
		//bool Intersect(const Circle& a, const Ellipse&		b);
		bool Intersect(const Circle& a, const Line&				b);
		bool Intersect(const Circle& a, const Triangle&			b);
		bool Intersect(const Circle& a, const Quad&				b);
		bool Intersect(const Circle& a, const Polygon&			b);
		bool Intersect(const Circle& a, const LineString&		b);

		bool Intersect(const Ellipse& a, const Vec2&			b);
		//bool Intersect(const Ellipse& a, const RectF&			b);
		//bool Intersect(const Ellipse& a, const Circle&		b);
		//bool Intersect(const Ellipse& a, const Ellipse&		b);
		//bool Intersect(const Ellipse& a, const Line&			b);
		//bool Intersect(const Ellipse& a, const Triangle&		b);
		//bool Intersect(const Ellipse& a, const Quad&			b);
		//bool Intersect(const Ellipse& a, const Polygon&		b);
		//bool Intersect(const Ellipse& a, const LineString&	b);

		bool Intersect(const LineInt& a, const LineInt& b);

		bool Intersect(const Line& a, const Vec2&		b);
		bool Intersect(const Line& a, const RectF&		b);
		bool Intersect(const Line& a, const Circle&		b);
		//bool Intersect(const Line& a, const Ellipse&		b);
		bool Intersect(const Line& a, const Line&		b);
		bool Intersect(const Line& a, const Triangle&	b);
		bool Intersect(const Line& a, const Quad&		b);
		bool Intersect(const Line& a, const Polygon&	b);
		//bool Intersect( const Line& a, const LineString& b );

		bool Intersect(const Triangle& a, const Vec2&		b);
		bool Intersect(const Triangle& a, const RectF&		b);
		bool Intersect(const Triangle& a, const Circle&		b);
		//bool Intersect(const Triangle& a, const Ellipse&	b);
		bool Intersect(const Triangle& a, const Line&		b);
		bool Intersect(const Triangle& a, const Triangle&	b);
		bool Intersect(const Triangle& a, const Quad&		b);
		bool Intersect(const Triangle& a, const Polygon&	b);
		//bool Intersect(const Triangle& a, const LineString& b);

		bool Intersect(const Quad& a, const Vec2&		b);
		bool Intersect(const Quad& a, const RectF&		b);
		bool Intersect(const Quad& a, const Circle&		b);
		//bool Intersect(const Quad& a, const Ellipse&	b);
		bool Intersect(const Quad& a, const Line&		b);
		bool Intersect(const Quad& a, const Triangle&	b);
		bool Intersect(const Quad& a, const Quad&		b);
		bool Intersect(const Quad& a, const Polygon&	b);
		//bool Intersect(const Quad& a, const LineString& b);

		bool Intersect(const Polygon& a, const Vec2&		b);
		bool Intersect(const Polygon& a, const RectF&		b);
		bool Intersect(const Polygon& a, const Line&		b);
		bool Intersect(const Polygon& a, const Circle&		b);
		//bool Intersect(const Polygon& a, const Ellipse&	b);
		bool Intersect(const Polygon& a, const Triangle&	b);
		bool Intersect(const Polygon& a, const Quad&		b);
		bool Intersect(const Polygon& a, const Polygon&		b);
		//bool Intersect(const Polygon& a, const LineString& b);

		bool Intersect(const LineString& a, const Vec2&				b);
		//bool Intersect(const LineString& a, const RectF&			b);
		bool Intersect(const LineString& a, const Circle&			b);
		//bool Intersect(const LineString& a, const Ellipse&		b);
		//bool Intersect(const LineString& a, const Line&			b);
		//bool Intersect(const LineString& a, const Triangle&		b);
		//bool Intersect(const LineString& a, const Quad&			b);
		//bool Intersect(const LineString& a, const Polygon&		b);
		//bool Intersect(const LineString& a, const LineIntString&	b);
		bool Intersect(const LineString& a, const LineString&		b);


		bool Within(const Rect& a, const Rect&	b);
		bool Within(const Rect& a, const RectF&	b);

		bool Within(const RectF& a, const Rect&		b);
		bool Within(const RectF& a, const RectF&	b);
		bool Within(const RectF& a, const Circle&	b);
		bool Within( const RectF& a, const Triangle& b );
		bool Within( const RectF& a, const Quad& b );
		//bool Within( const RectF& a, const Polygon& b );

		bool Within(const Circle& a, const RectF& b);
		bool Within(const Circle& a, const Circle& b);
		bool Within(const Circle& a, const Triangle& b);
		bool Within(const Circle& a, const Quad& b);
		bool Within(const Circle& a, const Polygon& b);

		bool Within(const LineInt& a, const Rect&	b);
		bool Within(const LineInt& a, const RectF&	b);

		bool Within(const Line& a, const Rect&	b);
		bool Within(const Line& a, const RectF& b);
		bool Within(const Line& a, const Circle& b);
		bool Within(const Line& a, const Triangle& b);
		bool Within(const Line& a, const Quad& b);
		//bool Within( const Line& a, const Polygon& b );

		//bool Within( const Triangle& a, const Vec2& b );
		//bool Within( const Triangle& a, const RectF& b );
		//bool Within( const Triangle& a, const Circle& b );
		//bool Within( const Triangle& a, const Triangle& b );
		//bool Within( const Triangle& a, const Quad& b );
		//bool Within( const Triangle& a, const Polygon& b );

		//bool Within( const Quad& a, const Vec2& b );
		//bool Within( const Quad& a, const RectF& b );
		//bool Within( const Quad& a, const Circle& b );		
		//bool Within( const Quad& a, const Triangle& b );
		//bool Within( const Quad& a, const Quad& b );
		//bool Within( const Quad& a, const Polygon& b );		

		//bool Within( const Polygon& a, const Vec2& b );
		//bool Within( const Polygon& a, const RectF& b );
		//bool Within( const Polygon& a, const Circle& b );
		//bool Within( const Polygon& a, const Triangle& b );
		//bool Within( const Polygon& a, const Quad& b );
		//bool Within( const Polygon& a, const Polygon& b );

		//bool Within( const LineIntString& a, const Vec2&          b );
		//bool Within( const LineIntString& a, const RectF&         b );
		//bool Within( const LineIntString& a, const Circle&        b );
		//bool Within( const LineIntString& a, const Triangle&      b );
		//bool Within( const LineIntString& a, const Quad&          b );
		//bool Within( const LineIntString& a, const Polygon&       b );

		//bool Within( const LineString& a, const Vec2&          b );
		//bool Within( const LineString& a, const RectF&         b );
		//bool Within( const LineString& a, const Circle&        b );
		//bool Within( const LineString& a, const Triangle&      b );
		//bool Within( const LineString& a, const Quad&          b );
		//bool Within( const LineString& a, const Polygon&       b );
	}
}
