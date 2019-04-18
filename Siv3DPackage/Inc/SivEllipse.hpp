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
	*	@brief �ȉ~
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
		*	�~�̍��W��ݒ肵�܂��B
		*	@param _x x ���W
		*	@param _y y ���W
		*	@return *this
		*/
		Ellipse& setPos(double _x, double _y) { x = _x; y = _y; return *this; }

		/**
		*	�ȉ~�̍��W��ݒ肵�܂��B
		*	@param _pos ���W
		*	@return *this
		*/
		Ellipse& setPos(const Vec2& _pos) { center = _pos; return *this; }

		/**
		*	�ȉ~�̔��a��ݒ肵�܂��B
		*	@param _a
		*	@param _b
		*	@return *this
		*/
		Ellipse& setSize(double _a, double _b) { a = _a; b = _b; return *this; }

		/**
		*	�ȉ~���ړ����܂��B
		*	@param _x ���� x ���W
		*	@param _y ���� y ���W
		*	@return *this
		*/
		Ellipse& moveBy(double _x, double _y) { center.moveBy(_x, _y); return *this; }

		/**
		*	�ȉ~���ړ����܂��B
		*	@param v ���΍��W
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
		*	�ȉ~�̖ʐς����߂܂��B
		*	@return �ʐ�
		*/
		double area() const;

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
		*	�C���[�W�ɑȉ~��`�悵�܂��B
		*	@param image �`���̃C���[�W
		*	@param color �`��F
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
	*	�o�̓X�g���[���ɑȉ~�̏���n���܂��B
	*	@param os �o�̓X�g���[��
	*	@param c �ȉ~
	*	@return �o�̓X�g���[��
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
	*	���̓X�g���[���ɑȉ~�̏���n���܂��B
	*	@param is ���̓X�g���[��
	*	@param c �ȉ~
	*	@return ���̓X�g���[��
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
