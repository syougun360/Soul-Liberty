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
	*	@brief スプライト頂点
	*/
	struct SpriteVertex
	{
		SpriteVertex() = default;

		SpriteVertex(float x, float y, float u, float v, const Color& _color = Palette::White)
			: pos{ x, y }
			, tex{ u, v }
			, color{ _color }{}

		SpriteVertex(const Float2& _pos, const Float2& _tex, const Color& _color = Palette::White)
			: pos{ _pos }
			, tex{ _tex }
			, color{ _color }{}

		Float2 pos;

		Float2 tex;

		Color color;
	};

	/**
	*	@brief スプライト
	*/
	class Sprite
	{
	public:

		std::vector<SpriteVertex> vertices;

		std::vector<unsigned short> indices;

		Sprite() = default;

		Sprite(unsigned vertexSize, unsigned indexSize)
			: vertices(vertexSize)
			, indices(indexSize)
		{

		}

		/**
		*	スプライトに適切なインデックス値が設定されているかを返します。
		*	@return
		*/
		bool isValid() const;

		/**
		*
		*/
		void draw() const;

		/**
		*
		*/
		void draw(const Color& color) const;

		/**
		*
		*/
		void draw(double x, double y) const;

		/**
		*
		*/
		void draw(const Vec2& pos) const;

		/**
		*
		*/
		void draw(double x, double y, const Color& color) const;

		/**
		*
		*/
		void draw(const Vec2& pos, const Color& color) const;

		/**
		*
		*/
		void draw(const Texture& texture) const;

		/**
		*
		*/
		void draw(const Texture& texture, const Color& color) const;

		/**
		*
		*/
		void draw(const Texture& texture, double x, double y) const;

		/**
		*
		*/
		void draw(const Texture& texture, const Vec2& pos) const;

		/**
		*
		*/
		void draw(const Texture& texture, double x, double y, const Color& color) const;

		/**
		*
		*/
		void draw(const Texture& texture, const Vec2& pos, const Color& color) const;
	};
}
