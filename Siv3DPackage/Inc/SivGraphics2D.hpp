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
		*	�f�t�H���g�̃A���t�@�u�����h
		*/
		static BlendState Default()
		{
			return NonPremultiplied();
		}

		/**
		*	�񓧉߃u�����h
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
		*	���Z�u�����h
		*/
		static BlendState Additive()
		{
			return{ true, Blend::SrcAlpha, Blend::One, BlendOp::Add };
		}

		/**
		*	���Z�u�����h
		*/
		static BlendState Subtractive()
		{
			return{ true, Blend::SrcAlpha, Blend::One, BlendOp::RevSubtract };
		}

		/**
		*	��Z�u�����h
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
		*	2D �`��̃X�P�[���ƃI�t�Z�b�g��ݒ肵�܂��B
		*	@param scale �X�P�[�����O
		*	@param offset �I�t�Z�b�g�i�s�N�Z���j
		*/
		void
			Set2DTransform(
			const Vec2& scale = { 1.0, 1.0 },
			const Vec2& offset = { 0.0, 0.0 }
			);

		/**
		*	���݂� 2D �`��̃X�P�[���ƃI�t�Z�b�g���擾���܂��B
		*	@return ���݂� 2D �`��̃X�P�[���ƃI�t�Z�b�g
		*/
		std::pair<Vec2, Vec2>
			Get2DTransform(
			);

		/**
		*	2D �`��̃u�����h�X�e�[�g��ݒ肵�܂��B
		*	@param blend �u�����h�X�e�[�g
		*/
		void
			Set2DBlendState(
			const BlendState& blend
			);

		/**
		*	���݂� 2D �`��̃u�����h�X�e�[�g���擾���܂��B
		*	@return ���݂� 2D �`��̃u�����h�X�e�[�g
		*/
		BlendState
			Get2DBlandState(
			);

		/**
		*	2D �`��̃T���v���[�X�e�[�g��ݒ肵�܂��B
		*	@param sampler �T���v���[�X�e�[�g
		*/
		void
			Set2DSamplerState(
			const SamplerState& sampler
			);

		/**
		*	2D �`��̃T���v���[�X�e�[�g���X���b�g���w�肵�Đݒ肵�܂��B
		*	@param slot �X���b�g�ԍ� [0 �܂��� 1]
		*	@param sampler �T���v���[�X�e�[�g
		*/
		void
			Set2DSamplerState(
			unsigned slot,
			const SamplerState& sampler
			);

		/**
		*	���݂� 2D �`��̃T���v���[�X�e�[�g���X���b�g���w�肵�Ď擾���܂��B
		*	@param slot �X���b�g�ԍ� [0 �܂��� 1]
		*	@return ���݂� 2D �`��̃T���v���[�X�e�[�g
		*/
		SamplerState
			Get2DSamplerState(
			unsigned slot = 0
			);

		/**
		*	2D �`��̃X�e���V���X�e�[�g��ݒ肵�܂��B
		*	@param stencil �X�e���V���X�e�[�g
		*/
		void
			Set2DStencilState(
			const StencilState& stencil
			);

		/**
		*	���݂� 2D �`��̃X�e���V���X�e�[�g���擾���܂��B
		*	@return ���݂� 2D �`��̃X�e���V���X�e�[�g
		*/
		StencilState
			Get2DStencilState(
			);

		/**
		*	2D �`��̃X�e���V���l��ݒ肵�܂��B
		*	@param value �X�e���V���l
		*/
		void
			Set2DStencilValue(
			unsigned char value
			);

		/**
		*	���݂� 2D �`��̃X�e���V���l���擾���܂��B
		*	@return ���݂� 2D �`��̃X�e���V���l
		*/
		unsigned char
			Get2DStencilValue(
			);

		/**
		*	2D �`��̐ݒ�����Z�b�g���܂��B
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
