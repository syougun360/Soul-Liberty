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
	*	@brief �~
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
		*	�~�����������܂��B
		*	@param _r ���a
		*/
		explicit Circle(double _r) : x(0), y(0), r(_r){}

		/**
		*	�~�����������܂��B
		*	@param _x x ���W
		*	@param _y y ���W
		*	@param _r ���a
		*/
		Circle(double _x, double _y, double _r) : x(_x), y(_y), r(_r){}

		/**
		*	�~�����������܂��B
		*	@param p ���W
		*/
		explicit Circle(const Vec2& p) : center(p), r(0.0){}

		/**
		*	�~�����������܂��B
		*	@param p ���W
		*	@param _r ���a
		*/
		Circle(const Vec2& p, double _r) : center(p), r(_r){}

		/**
		*	�~�̍��W��ݒ肵�܂��B
		*	@param _x x ���W
		*	@param _y y ���W
		*	@return *this
		*/
		Circle& setPos(double _x, double _y) { x = _x; y = _y; return *this; }

		/**
		*	�~�̍��W��ݒ肵�܂��B
		*	@param _pos ���W
		*	@return *this
		*/
		Circle& setPos(const Vec2& _pos) { center = _pos; return *this; }

		/**
		*	�~�̔��a��ݒ肵�܂��B
		*	@param _r ���a
		*	@return *this
		*/
		Circle& setSize(double _r) { r = _r; return *this; }

		/**
		*	�~���ړ����܂��B
		*	@param _x ���� x ���W
		*	@param _y ���� y ���W
		*	@return *this
		*/
		Circle& moveBy(double _x, double _y) { center.moveBy(_x, _y); return *this; }

		/**
		*	�~���ړ����܂��B
		*	@param v ���΍��W
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
		*	�~�̖ʐς����߂܂��B
		*	@return �ʐ�
		*/
		double area() const;

		/**
		*
		*	@return
		*/
		double perimeter() const;

		/**
		*	���̐}�`�Ƃ̐ڐG������s���܂��B
		*	@param shape �ڐG������s���}�`
		*	@return �ڐG���Ă���ꍇ�� true, ����ȊO�� false
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
		*	���N���b�N���ꂽ����Ԃ��܂��B
		*/
		Property_Get(bool, leftClicked) const;

		/**
		*	���N���b�N����Ă��邩��Ԃ��܂��B
		*/
		Property_Get(bool, leftPressed) const;

		/**
		*	���N���b�N�������ꂽ����Ԃ��܂��B
		*/
		Property_Get(bool, leftReleased) const;

		/**
		*	�E�N���b�N���ꂽ����Ԃ��܂��B
		*/
		Property_Get(bool, rightClicked) const;

		/**
		*	�E�N���b�N����Ă��邩��Ԃ��܂��B
		*/
		Property_Get(bool, rightPressed) const;

		/**
		*	�E�N���b�N�������ꂽ����Ԃ��܂��B
		*/
		Property_Get(bool, rightReleased) const;

		/**
		*	�}�E�X�J�[�\�����}�`��ɂ��邩��Ԃ��܂��B
		*/
		Property_Get(bool, mouseOver) const;

		/**
		*	�C���[�W�ɉ~��`�悵�܂��B
		*	@param image �`���̃C���[�W
		*	@param color �`��F
		*/
		void write(Image& image, const Color& color = Palette::Black) const;

		/**
		*	�C���[�W�ɐ�`��`�悵�܂��B
		*	@param image �`���̃C���[�W
		*	@param startAngle �p�x�̃I�t�Z�b�g
		*	@param angle �`�悷��p�x
		*	@param color �`��F
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
	*	�o�̓X�g���[���ɉ~�̏���n���܂��B
	*	@param os �o�̓X�g���[��
	*	@param c �~
	*	@return �o�̓X�g���[��
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
	*	���̓X�g���[���ɉ~�̏���n���܂��B
	*	@param is ���̓X�g���[��
	*	@param c �~
	*	@return ���̓X�g���[��
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
