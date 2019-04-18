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
	*	@brief 2 �����}�`�̍쐬�Ɗ􉽌v�Z
	*/
	namespace Geometry
	{
		/**
		*	�����`�̒��_�z���Ԃ��܂��B
		*	@param w �����`�̕�
		*	@param h �����`�̍���
		*	@param center �����`�̒��S���W
		*	@return �����`�̒��_�z��
		*/
		std::vector<Vec2>
			CreateRect(
			double w,
			double h,
			const Vec2& center = { 0.0, 0.0 }
			);

		/**
		*	�\���`�̒��_�z���Ԃ��܂��B
		*	@param r ��ԗ��ꂽ�ӂ��璆�S�_�܂ł̋���
		*	@param width �\���`���\������ 2 �����̑���
		*	@param center �\���`�̒��S���W
		*	@return �\���`�̒��_�z��
		*/
		std::vector<Vec2>
			CreatePlus(
			double r,
			double width,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	���܊p�`�̒��_�z���Ԃ��܂��B
		*	@param r �O�ډ~�̔��a
		*	@param angle ���v�����ւ̉�]�p�x[���W�A��], 0 �̂Ƃ����_�� 12 ���̈ʒu�Əd�Ȃ�
		*	@param center ���܊p�`�̒��S���W
		*	@return ���܊p�`�̒��_�z��
		*/
		std::vector<Vec2>
			CreatePentagon(
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	���Z�p�`�̒��_�z���Ԃ��܂��B
		*	@param r �O�ډ~�̔��a
		*	@param angle ���v�����ւ̉�]�p�x[���W�A��], 0 �̂Ƃ����_�� 12 ���̈ʒu�Əd�Ȃ�
		*	@param center ���Z�p�`�̒��S���W
		*	@return ���Z�p�`�̒��_�z��
		*/
		std::vector<Vec2>
			CreateHexagon(
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	�� N �p�`�̒��_�z���Ԃ��܂��B
		*	@param n ���_�̐�
		*	@param r �O�ډ~�̔��a
		*	@param angle ���v�����ւ̉�]�p�x[���W�A��], 0 �̂Ƃ����_�� 12 ���̈ʒu�Əd�Ȃ�
		*	@param center �� N �p�`�̒��S���W
		*	@return �� N �p�`�̒��_�z��An<3 �̏ꍇ�͋�̔z��
		*/
		std::vector<Vec2>
			CreateNgon(
			int n,
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	�܌��� (��) �̒��_�z���Ԃ��܂��B
		*	http://ja.wikipedia.org/wiki/%E4%BA%94%E8%8A%92%E6%98%9F
		*	@param r �O�ډ~�̔��a
		*	@param angle ���v�����ւ̉�]�p�x[���W�A��], 0 �̂Ƃ����_�� 12 ���̈ʒu�Əd�Ȃ�
		*	@param center �܌����̒��S���W
		*	@return �܌����̒��_�z��
		*/
		std::vector<Vec2>
			CreateStar(
			double r,
			double angle = 0.0,
			const Vec2& center = { 0.0, 0.0 }
		);

		/**
		*	���`�}�`�̒��_�z���Ԃ��܂��B
		*	@param n ���̐��i�܌��� �� �̏ꍇ�A5�j
		*	@param rOuter ���S����O���̒��_�܂ł̋���
		*	@param rInner ���S��������̒��_�܂ł̋���
		*	@param angle ���v�����ւ̉�]�p�x[���W�A��], 0 �̂Ƃ����_�� 12 ���̈ʒu�Əd�Ȃ�
		*	@param center �}�`�̒��S���W
		*	@return ���`�}�`�̒��_�z��An<2 �̏ꍇ�͋�̔z��
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
