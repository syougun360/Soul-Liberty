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
# include <memory>
# include "SivForward.hpp"
# include "SivHandle.hpp"
# include "SivPropertyMacro.hpp"
# include "SivMath.hpp"
# include "SivColor.hpp"

namespace s3d
{
	/**
	*	@brief
	*/
	enum class TextureFormat
	{
		/**
		*
		*/
		R8G8B8A8	= 28,

		/**
		*
		*/
		A8			= 65,
	};

	/**
	*	@brief
	*/
	class Texture
	{
	protected:

		class Handle{};

		typedef Siv3DHandle<Handle> TextureHandle;

		std::shared_ptr<TextureHandle> m_handle;

		struct _modeDyanmic{};

		Texture(
			unsigned width,
			unsigned height,
			TextureFormat format,
			const _modeDyanmic&
			);

		Texture(
			unsigned width,
			unsigned height,
			const Color& color,
			const _modeDyanmic&
			);

		Texture(
			const Image& image,
			const _modeDyanmic&
			);

	public:

		/**
		*
		*/
		const static bool Unmipped = false;

		/**
		*
		*/
		const static bool Mipped = true;

		/**
		*
		*/
		Texture();

		/**
		*	�C���[�W����e�N�X�`�����쐬���܂�
		*	@param image �C���[�W
		*	@param mipped �~�b�v�}�b�v���쐬���邩
		*	@note �C���[�W����̏ꍇ�A��̃e�N�X�`�����쐬���܂��B
		*/
		explicit Texture(
			const Image& image,
			bool mipped = Unmipped
			);

		/**
		*	�摜�t�@�C������e�N�X�`�����쐬���܂�
		*	@param path �摜�t�@�C���̃p�X
		*	@param mipped �~�b�v�}�b�v���쐬���邩
		*	@note �摜�t�@�C���̓ǂݍ��݂Ɏ��s�����ꍇ�A��̃e�N�X�`�����쐬���܂��B
		*/
		explicit Texture(
			const FilePath& path,
			bool mipped = Unmipped
			);

		/**
		*	2 �̉摜�t�@�C������e�N�X�`�����쐬���܂�
		*	@param rgb RGB ��ǂݍ��މ摜�t�@�C���̃p�X
		*	@param alpha �A���t�@�l ��ǂݍ��މ摜�t�@�C���̃p�X
		*	@param mipped �~�b�v�}�b�v���쐬���邩
		*	@note alphaFileName �̉摜�� R �������A�e�N�X�`���̃A���t�@�l�ɐݒ肵�܂��B
		*/
		Texture(
			const FilePath& rgb,
			const FilePath& alpha,
			bool mipped = Unmipped
			);

		/**
		*
		*	@param rgb
		*	@param alpha
		*	@param mipped
		*/
		Texture(
			const Color& rgb,
			const FilePath& alpha,
			bool mipped = Unmipped
			);

		/**
		*
		*/
		virtual ~Texture();

		/**
		*	�e�N�X�`�����������A��̃e�N�X�`���ɂȂ�܂��B
		*	�v���O�����̂ق��̏ꏊ�œ����e�N�X�`�����g���Ă��Ȃ��ꍇ�A�e�N�X�`���̃��������J�����܂��B
		*/
		void release();

		/**
		*	�e�N�X�`������łȂ�����Ԃ��܂��B
		*	@return �e�N�X�`������łȂ��ꍇ true, ��̏ꍇ false
		*/
		explicit operator bool() const;

		/**
		*
		*/
		Property_Get(HandleIDType, id) const;

		/**
		*	�e�N�X�`�����󂩂ǂ�����Ԃ��܂��B
		*	@return �e�N�X�`������̏ꍇ true, ��łȂ��ꍇ false
		*/
		Property_Get(bool, isEmpty) const;

		/**
		*
		*	@param texture
		*	@return
		*/
		bool operator == (const Texture& texture) const;

		/**
		*
		*	@param texture
		*	@return
		*/
		bool operator != (const Texture& texture) const;

		/**
		*	�e�N�X�`���̕��i�s�N�Z���j
		*/
		Property_Get(int, width) const;

		/**
		*	�e�N�X�`���̍����i�s�N�Z���j
		*/
		Property_Get(int, height) const;

		/**
		*
		*/
		Property_Get(bool, mipped) const;

		/**
		*
		*/
		Property_Get(TextureFormat, format) const;

		/**
		*
		*	@param diffuse
		*	@return
		*/
		const RectF draw(const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param diffuse
		*	@return
		*/
		const RectF draw(double x, double y, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param diffuse
		*	@return
		*/
		const RectF draw(const Vec2& pos, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param diffuse
		*	@return
		*/
		const RectF drawAt(double x, double y, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param diffuse
		*	@return
		*/
		const RectF drawAt(const Vec2& pos, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param w
		*	@param h
		*	@return
		*/
		const TextureRegion operator ()(double x, double y, double w, double h) const;

		/**
		*
		*	@param rect
		*	@return
		*/
		const TextureRegion operator ()(const RectF& rect) const;

		/**
		*
		*	@param u
		*	@param v
		*	@param w
		*	@param h
		*	@return
		*/
		const TextureRegion uv(double u, double v, double w, double h) const;

		/**
		*
		*	@param rect
		*	@return
		*/
		const TextureRegion uv(const RectF& rect) const;

		/**
		*
		*	@return
		*/
		const TextureRegion mirror() const;

		/**
		*
		*	@return
		*/
		const TextureRegion flip() const;

		/**
		*
		*	@param scaling
		*	@return
		*/
		const TextureRegion scale(double scaling) const;

		/**
		*
		*	@param xScaling
		*	@param yScaling
		*	@return
		*/
		const TextureRegion scale(double xScaling, double yScaling) const;

		/**
		*
		*	@param scaling
		*	@return
		*/
		const TextureRegion scale(const Vec2& scaling) const;

		/**
		*
		*	@param width
		*	@param height
		*	@return
		*/
		const TextureRegion resize(double width, double height) const;

		/**
		*
		*	@param size
		*	@return
		*/
		const TextureRegion resize(const Vec2& size) const;

		/**
		*
		*	@param xRepeat
		*	@param yRepeat
		*	@return
		*/
		const TextureRegion repeat(double xRepeat, double yRepeat) const;

		/**
		*
		*	@param repeat
		*	@return
		*/
		const TextureRegion repeat(const Vec2& repeat) const;

		/**
		*
		*	@param width
		*	@param height
		*	@return
		*/
		const TextureRegion map(double width, double height) const;

		/**
		*
		*	@param size
		*	@return
		*/
		const TextureRegion map(const Vec2& size) const;

		/**
		*
		*	@param radian
		*	@return
		*/
		const TexturedQuad rotate(double radian) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param radian
		*	@return
		*/
		const TexturedQuad rotateAt(double x, double y, double radian) const;

		/**
		*
		*	@param pos
		*	@param radian
		*	@return
		*/
		const TexturedQuad rotateAt(const Vec2& pos, double radian) const;
	};


	/**
	*	@brief ���I�e�N�X�`��
	*
	*	�`��\�ȃC���[�W�ł��B
	*	Texture �ƈقȂ�A���������Ċm�ۂ��邱�ƂȂ��C���[�W�f�[�^���X�V�ł��܂��B
	*/
	class DynamicTexture : public Texture
	{
	public:

		/**
		*
		*/
		DynamicTexture(
			);

		/**
		*
		*	@param width
		*	@param height
		*	@param format
		*/
		DynamicTexture(
			unsigned width,
			unsigned height,
			TextureFormat format = TextureFormat::R8G8B8A8
			);

		/**
		*
		*	@param width
		*	@param height
		*	@param color
		*/
		DynamicTexture(
			unsigned width,
			unsigned height,
			const Color& color
			);

		/**
		*
		*	@param image
		*/
		DynamicTexture(
			const Image& image
			);

		/**
		*
		*	@param color
		*	@return
		*/
		bool
			fill(
			const Color& color
			);

		/**
		*
		*	@param color
		*	@param rect
		*	@return
		*/
		bool
			fill(
			const Color& color,
			const Rect& rect
			);

		/**
		*	���I�e�N�X�`���̒��g�𓯂��傫���̃C���[�W�ōX�V
		*	���I�e�N�X�`������̏ꍇ�͐V�������I�e�N�X�`�����C���[�W����쐬����
		*	@param image
		*	@return ���I�e�N�X�`���̍X�V���쐬�ɐ��������� true, ���s������ false
		*/
		bool
			fill(
			const Image& image
			);

		/**
		*
		*	@param image
		*	@param rect
		*	@return
		*/
		bool
			fill(
			const Image& image,
			const Rect& rect
			);

		/**
		*
		*	@param color
		*	@return
		*/
		bool
			tryFill(
			const Color& color
			);

		/**
		*
		*	@param color
		*	@param rect
		*	@return
		*/
		bool
			tryFill(
			const Color& color,
			const Rect& rect
			);

		/**
		*
		*	@param image
		*	@return
		*/
		bool
			tryFill(
			const Image& image
			);

		/**
		*
		*	@param image
		*	@param rect
		*	@return
		*/
		bool
			tryFill(
			const Image& image,
			const Rect& rect
			);
	};


	/**
	*	@brief
	*/
	struct TextureRegion
	{
		/**
		*
		*/
		TextureRegion(){}

		/**
		*
		*	@param tex
		*/
		TextureRegion(const Texture& tex) : texture{ tex }, uvRect{ 0.0f, 0.0f, 1.0f, 1.0f }, size{ tex.width, tex.height }{}

		/**
		*
		*	@param tex
		*	@param l
		*	@param t
		*	@param r
		*	@param b
		*	@param sx
		*	@param sy
		*/
		TextureRegion(const Texture& tex, float l, float t, float r, float b, double sx, double sy) : texture{ tex }, uvRect{ l, t, r, b }, size{ sx, sy }{}

		/**
		*
		*	@param tex
		*	@param l
		*	@param t
		*	@param r
		*	@param b
		*	@param s
		*/
		TextureRegion(const Texture& tex, float l, float t, float r, float b, const Vec2& s) : texture{ tex }, uvRect{ l, t, r, b }, size{ s }{}

		/**
		*
		*	@param tex
		*	@param uv
		*	@param s
		*/
		TextureRegion(const Texture& tex, const FloatRect& uv, const Vec2& s) : texture{ tex }, uvRect{ uv }, size{ s }{}

		/**
		*
		*/
		Texture texture;

		/**
		*
		*/
		FloatRect uvRect;

		/**
		*
		*/
		Vec2 size;

		/**
		*
		*	@param diffuse
		*	@return
		*/
		const RectF draw(const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param diffuse
		*	@return
		*/
		const RectF draw(double x, double y, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param diffuse
		*	@return
		*/
		const RectF draw(const Vec2& pos, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param diffuse
		*	@return
		*/
		const RectF drawAt(double x, double y, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param diffuse
		*	@return
		*/
		const RectF drawAt(const Vec2& pos, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@return
		*/
		const TextureRegion mirror() const;

		/**
		*
		*	@return
		*/
		const TextureRegion flip() const;

		/**
		*
		*	@param scaling
		*	@return
		*/
		const TextureRegion scale(double scaling) const;

		/**
		*
		*	@param xScaling
		*	@param yScaling
		*	@return
		*/
		const TextureRegion scale(double xScaling, double yScaling) const;

		/**
		*
		*	@param scaling
		*	@return
		*/
		const TextureRegion scale(const Vec2& scaling) const;

		/**
		*
		*	@param width
		*	@param height
		*	@return
		*/
		const TextureRegion resize(double width, double height) const;

		/**
		*
		*	@param size
		*	@return
		*/
		const TextureRegion resize(const Vec2& size) const;

		/**
		*
		*	@param radian
		*	@return
		*/
		const TexturedQuad rotate(double radian) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param radian
		*	@return
		*/
		const TexturedQuad rotateAt(double x, double y, double radian) const;

		/**
		*
		*	@param pos
		*	@param radian
		*	@return
		*/
		const TexturedQuad rotateAt(const Vec2& pos, double radian) const;
	};

	/**
	*	@brief
	*/
	struct TexturedQuad
	{
		/**
		*
		*	@param tex
		*	@param l
		*	@param t
		*	@param r
		*	@param b
		*	@param q
		*	@param c
		*	@return
		*/
		TexturedQuad(const Texture& tex, float l, float t, float r, float b, const Quad& q, const Vec2& c)
		: texture{ tex }, uvRect{ l, t, r, b }, quad{ q }, center{ c }{}

		/**
		*
		*	@param tex
		*	@param uv
		*	@param q
		*	@param c
		*	@return
		*/
		TexturedQuad(const Texture& tex, const FloatRect& uv, const Quad& q, const Vec2& c)
			: texture{ tex }, uvRect{ uv }, quad{ q }, center{ c }{}

		/**
		*
		*/
		Texture texture;

		/**
		*
		*/
		FloatRect uvRect;

		/**
		*
		*/
		Quad quad;

		/**
		*
		*/
		Vec2 center;

		/**
		*
		*	@param diffuse
		*	@return
		*/
		const Quad& draw(const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param diffuse
		*	@return
		*/
		const Quad draw(double x, double y, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param diffuse
		*	@return
		*/
		const Quad draw(const Vec2& pos, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param diffuse
		*	@return
		*/
		const Quad drawAt(const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param x
		*	@param y
		*	@param diffuse
		*	@return
		*/
		const Quad drawAt(double x, double y, const Color& diffuse = Palette::White) const;

		/**
		*
		*	@param pos
		*	@param diffuse
		*	@return
		*/
		const Quad drawAt(const Vec2& pos, const Color& diffuse = Palette::White) const;
	};
}
