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
# include "SivPointVector.hpp"

namespace s3d
{
	//
	// http://msdn.microsoft.com/ja-jp/library/ee416042%28v=vs.85%29.aspx
	//
	enum class Blend
	{
		Zero			= 1,
		One				= 2,
		SrcColor		= 3,
		InvSrcColor		= 4,
		SrcAlpha		= 5,
		InvSrcAlpha		= 6,
		DestAlpha		= 7,
		InvDestAlpha	= 8,
		DestColor		= 9,
		InvDestColor	= 10,
		SrcAlphaSat		= 11,
		BlendFactor		= 14,
		InvBlendFactor	= 15,
		Src1Color		= 16,
		InvSrc1Color	= 17,
		Src1Alpha		= 18,
		InvSrc1Alpha	= 19
	};

	//
	// http://msdn.microsoft.com/ja-jp/library/ee416044(v=vs.85).aspx
	//
	enum class BlendOp
	{
		Add			= 1,
		Subtract	= 2,
		RevSubtract	= 3,
		Min			= 4,
		Max			= 5
	};

	struct BlendState
	{
		bool enable = true;

		Blend src = Blend::SrcAlpha;

		Blend dest = Blend::InvSrcAlpha;

		BlendOp op = BlendOp::Add;

		BlendState(bool _enable = true, Blend _src = Blend::SrcAlpha, Blend _dest = Blend::InvSrcAlpha, BlendOp _op = BlendOp::Add)
			: enable{ _enable }, src{ _src }, dest{ _dest }, op{ _op }{}

		/**
		*	デフォルトのアルファブレンド
		*/
		static BlendState Default()
		{
			return NonPremultiplied();
		}

		/**
		*	非透過ブレンド
		*/
		static BlendState Opaque()
		{
			return{ false };
		}

		static BlendState NonPremultiplied()
		{
			return{};
		}

		/**
		*	加算ブレンド
		*/
		static BlendState Additive()
		{
			return{ true, Blend::SrcAlpha, Blend::One, BlendOp::Add };
		}

		/**
		*	減算ブレンド
		*/
		static BlendState Subtractive()
		{
			return{ true, Blend::SrcAlpha, Blend::One, BlendOp::RevSubtract };
		}

		/**
		*	乗算ブレンド
		*/
		static BlendState Multiplicative()
		{
			return{ true, Blend::Zero, Blend::SrcColor, BlendOp::Add };
		}
	};

	enum class TextureFilter
	{
       MinMagMipPoint				= 0,
       MinMagPointMipLinear			= 0x1,
       MinPointMagLinearMipPoint	= 0x4,
       MinPointMagMipLinear			= 0x5,
       MinLinearMagMipPoint			= 0x10,
       MinLinearMagPointMipLinear	= 0x11,
       MinMagLinearMipPoint			= 0x14,
       MinMagMipLinear				= 0x15,
       Anisotropic					= 0x55,   
	};

	enum class TextureAddressMode
	{
        Wrap		= 1,
        Mirror		= 2,
        Clamp		= 3,
        Border		= 4,
        MirrorOnce	= 5
	};

	struct SamplerState
	{
		SamplerState(TextureFilter _filter = TextureFilter::MinMagMipLinear, TextureAddressMode _adderssMode = TextureAddressMode::Wrap)
		: filter{ _filter }, addressMode{ _adderssMode }{}

		TextureFilter filter = TextureFilter::MinMagMipLinear;

		TextureAddressMode addressMode = TextureAddressMode::Wrap;

		static SamplerState Default()
		{
			return{};
		}

		static SamplerState Default3D()
		{
			return{ TextureFilter::Anisotropic, TextureAddressMode::Wrap };
		}

		static SamplerState Clamp()
		{
			return{ TextureFilter::MinMagMipLinear, TextureAddressMode::Clamp };
		}

		static SamplerState Clamp3D()
		{
			return{ TextureFilter::Anisotropic, TextureAddressMode::Clamp };
		}
	};

	enum class StencilOp
	{
		Keep		= 1,
		Zero		= 2,
		Replace		= 3,
		IncrSat		= 4,
		DecrSat		= 5,
		Invert		= 6,
		Incr		= 7,
		Decr		= 8
	};

	enum class StencilFunc
	{
        Never			= 1,
        Less			= 2,
        Equal			= 3,
        LessEqual		= 4,
        Greater			= 5,
        NotEqual		= 6,
        GreaterEqual	= 7,
        Always			= 8
	};

	struct StencilState
	{
		StencilState(bool _enable = false, bool _writeEnable = false, StencilOp _op = StencilOp::Keep, StencilFunc _func = StencilFunc::Always)
		: enable{ _enable }, writeEnable{ _writeEnable }, op{ _op }, func{ _func }{}

		bool enable = false;

		bool writeEnable = false;

		StencilOp op = StencilOp::Keep;
		
		StencilFunc func = StencilFunc::Always;

		static StencilState Default()
		{
			return None();
		}

		static StencilState None()
		{
			return{ false, false, StencilOp::Keep, StencilFunc::Always };
		}

		static StencilState Write(StencilOp _op = StencilOp::Replace, StencilFunc _func = StencilFunc::Always)
		{
			return{ true, true, _op, _func };
		}

		static StencilState Test(StencilFunc _func = StencilFunc::Always)
		{
			return{ true, false, StencilOp::Keep, _func };
		}
	};

	namespace Graphics
	{
		/**
		*	2D 描画のスケールとオフセットを設定します。
		*	@param scale スケーリング
		*	@param offset オフセット（ピクセル）
		*/
		void
			Set2DTransform(
			const Vec2& scale = { 1.0, 1.0 },
			const Vec2& offset = { 0.0, 0.0 }
			);

		/**
		*	現在の 2D 描画のスケールとオフセットを取得します。
		*	@return 現在の 2D 描画のスケールとオフセット
		*/
		std::pair<Vec2, Vec2>
			Get2DTransform(
			);

		/**
		*	2D 描画のブレンドステートを設定します。
		*	@param blend ブレンドステート
		*/
		void
			Set2DBlendState(
			const BlendState& blend
			);

		/**
		*	現在の 2D 描画のブレンドステートを取得します。
		*	@return 現在の 2D 描画のブレンドステート
		*/
		BlendState
			Get2DBlandState(
			);

		/**
		*	2D 描画のサンプラーステートを設定します。
		*	@param sampler サンプラーステート
		*/
		void
			Set2DSamplerState(
			const SamplerState& sampler
			);

		/**
		*	2D 描画のサンプラーステートをスロットを指定して設定します。
		*	@param slot スロット番号 [0 または 1]
		*	@param sampler サンプラーステート
		*/
		void
			Set2DSamplerState(
			unsigned slot,
			const SamplerState& sampler
			);

		/**
		*	現在の 2D 描画のサンプラーステートをスロットを指定して取得します。
		*	@param slot スロット番号 [0 または 1]
		*	@return 現在の 2D 描画のサンプラーステート
		*/
		SamplerState
			Get2DSamplerState(
			unsigned slot = 0
			);

		/**
		*	2D 描画のステンシルステートを設定します。
		*	@param stencil ステンシルステート
		*/
		void
			Set2DStencilState(
			const StencilState& stencil
			);

		/**
		*	現在の 2D 描画のステンシルステートを取得します。
		*	@return 現在の 2D 描画のステンシルステート
		*/
		StencilState
			Get2DStencilState(
			);

		/**
		*	2D 描画のステンシル値を設定します。
		*	@param value ステンシル値
		*/
		void
			Set2DStencilValue(
			unsigned char value
			);

		/**
		*	現在の 2D 描画のステンシル値を取得します。
		*	@return 現在の 2D 描画のステンシル値
		*/
		unsigned char
			Get2DStencilValue(
			);

		/**
		*	2D 描画の設定をリセットします。
		*/
		inline
		void
			Reset2DState(
			)
		{
			Set2DTransform();

			Set2DBlendState(BlendState::Default());

			Set2DSamplerState(0, SamplerState::Default());

			Set2DSamplerState(1, SamplerState::Default());

			Set2DStencilState(StencilState::Default());

			Set2DStencilValue(0);
		}
	}
}
