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
# include "SivHandle.hpp"
# include "SivColor.hpp"
# include "SivPointVector.hpp"
# include "SivRectangle.hpp"
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	フォントの種類
	*/
	enum class Typeface
	{
		/**
		*	標準 [UmePlus P Gothic]
		*/
		Default,

		/**
		*	とても細い [M+ 1p thin]
		*/
		Thin,

		/**
		*	細い [M+ 1p light]
		*/
		Light,

		/**
		*	普通 [M+ 1p regular]
		*/
		Regular,

		/**
		*	やや太い [M+ 1p medium]
		*/
		Medium,

		/**
		*	太い [M+ 1p bold]
		*/
		Bold,

		/**
		*	とても太い [M+ 1p heavy]
		*/
		Heavy,

		/**
		*	非常に太い [M+ 1p black]
		*/
		Black,
	};

	struct FontStyle
	{
		FontStyle(const Color& _color, double _lineHeight = 1.0) : lineHeight{ _lineHeight }, color{ _color }{}

		FontStyle(Palette _color, double _lineHeight = 1.0) : lineHeight{ _lineHeight }, color{ _color }{}

		double lineHeight = 1.0;

		Color color = Palette::White;
	};

	struct KineticTypography
	{
		KineticTypography(Vec2 _pos, Vec2 _base, unsigned _length, unsigned _index, Color _col, wchar_t _ch)
		: pos{ _pos },
		  base{ _base },
		  length{ _length },
		  index{ _index },
		  col{ _col },
		  ch{ _ch }{}

		Vec2 pos;
		
		Vec2 base;
		
		unsigned length;
		
		unsigned index;
		
		Color col;
		
		wchar_t ch;
	};

	typedef std::function<void(KineticTypography&)> KineticTypographyFunction_t;

	class Font
	{
	private:

		class Handle{};

		typedef Siv3DHandle<Handle> FontHandle;

		std::shared_ptr<FontHandle> m_handle;

	public:

		Font(
			);

		Font(
			unsigned size,
			Typeface type = Typeface::Default
			);

		Font(
			unsigned size,
			const String& name
			);

		virtual ~Font(
			);

		void
			release(
			);

		explicit operator bool() const;

		Property_Get(HandleIDType, id) const;

		Property_Get(bool, isEmpty) const;

		Property_Get(String, name) const;

		Property_Get(unsigned, size) const;

		Property_Get(int, height) const;

		bool operator == (const Font& font) const;

		bool operator != (const Font& font) const;

		Rect
			write(
			Image& image,
			const String& text,
			int x,
			int y,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			write(
			Image& image,
			const String& text,
			const Point& pos = { 0, 0 },
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			writeCenter(
			Image& image,
			const String& text,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			writeCenter(
			Image& image,
			const String& text,
			int y,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			writeCenter(
			Image& image,
			const String& text,
			const Point& pos,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			region(
			const String& text,
			double lineHeight
			) const;

		Rect
			region(
			const String& text,
			const Point& pos = { 0, 0 },
			double lineHeight = 1.0
			) const;

		Rect
			region(
			const String& text,
			int x,
			int y,
			double lineHeight = 1.0
			) const;

		RectF
			region(
			const String& text,
			double x,
			double y,
			double lineHeight = 1.0
			) const;

		RectF
			region(
			const String& text,
			const Vec2& pos,
			double lineHeight = 1.0
			) const;

		RectF
			regionCenter(
			const String& text,
			double y,
			double lineHeight = 1.0
			) const;

		RectF
			regionCenter(
			const String& text,
			const Vec2& pos,
			double lineHeight = 1.0
			) const;

		RectF
			draw(
			const String& text,
			double x,
			double y,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		RectF
			draw(
			const String& text,
			const Vec2& pos = { 0.0, 0.0 },
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		void
			drawKinetic(
			const String& text,
			double x,
			double y,
			KineticTypographyFunction_t kineticFunction,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		void
			drawKinetic(
			const String& text,
			const Vec2& pos,
			KineticTypographyFunction_t kineticFunction,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		RectF
			drawCenter(
			const String& text,
			int y,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		RectF
			drawCenter(
			const String& text,
			const Vec2& pos,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		const TextureRegion
			getTexture(
			wchar_t ch
			) const;

		DrawableString
			operator()(
			const String& text
			) const;

		template <typename ... Args>
		inline
		DrawableString
			operator()(
			const Args& ... args
			) const;
	};


	class DrawableString
	{
	private:

		Font m_font;

		String m_text;

	public:

		DrawableString() = default;

		DrawableString(const Font& font, const String& text)
			: m_font{ font }
			, m_text(text)
		{

		}

		DrawableString(const Font& font, String&& text)
			: m_font{ font }
			, m_text(std::move(text))
		{

		}

		Rect
			write(
			Image& image,
			int x,
			int y,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			write(
			Image& image,
			const Point& pos = { 0, 0 },
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			writeCenter(
			Image& image,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			writeCenter(
			Image& image,
			int y,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			writeCenter(
			Image& image,
			const Point& pos,
			const Color& color = Palette::Black,
			double lineHeight = 1.0
			) const;

		Rect
			region(
			double lineHeight
			) const;

		Rect
			region(
			const Point& pos = { 0, 0 },
			double lineHeight = 1.0
			) const;

		Rect
			region(
			int x,
			int y,
			double lineHeight = 1.0
			) const;

		RectF
			region(
			double x,
			double y,
			double lineHeight = 1.0
			) const;

		RectF
			region(
			const Vec2& pos,
			double lineHeight = 1.0
			) const;

		RectF
			regionCenter(
			double y,
			double lineHeight = 1.0
			) const;

		RectF
			regionCenter(
			const Vec2& pos,
			double lineHeight = 1.0
			) const;

		RectF
			draw(
			double x,
			double y,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		RectF
			draw(
			const Vec2& pos = { 0.0, 0.0 },
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		void
			drawKinetic(
			double x,
			double y,
			KineticTypographyFunction_t kineticFunction,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		void
			drawKinetic(
			const Vec2& pos,
			KineticTypographyFunction_t kineticFunction,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		RectF
			drawCenter(
			int y,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;

		RectF
			drawCenter(
			const Vec2& pos,
			const Color& color = Palette::White,
			double lineHeight = 1.0
			) const;
	};

	template <typename ... Args>
	inline
	DrawableString
		Font::operator()(
		const Args& ... args
		) const
	{
		return DrawableString{ *this, Format(args...) };
	}

	namespace FontManager
	{
		/**
		*	システムにフォントを一時的に登録します。
		*	@param fontFileName 登録するフォントファイル
		*	@return フォントの登録に成功した場合 true, それ以外の場合は false
		*	@note これにより、コンピュータにインストールされていないフォントが使えるようになります。
		*/
		bool
			Register(
			const FilePath& path
			);

		String
			TypefaceToFontName_(
			Typeface typeface
			);
	}
}
