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
# include "SivMath.hpp"

namespace s3d
{
	struct Camera
	{
		Vec3 pos = { 0.0, 4.0, -16.0 };

		Vec3 lookat = { 0.0, 1.0, 0.0 };

		Vec3 up = { 0.0, 1.0, 0.0 };

		double fovDegree = 45.0;

		double nearclip = 0.1;

		double farclip = 2000.0;

		Camera() {}

		Camera(
			const Vec3& _pos,
			const Vec3& _lookat, 
			const Vec3& _up,
			double _fovDegree,
			double _nearclip,
			double _farclip
			)
			: pos{ _pos }
			, lookat{ _lookat }
			, up{ _up }
			, fovDegree{ _fovDegree }
			, nearclip{ _nearclip }
			, farclip{ _farclip } {}

		double fovRadian() const
		{
			return Math::Radians(fovDegree);
		}
	};

	struct Light
	{
		ColorF diffuse = { 0.0, 0.0 };
		
		Vec3 attenuaion = { 0.0, 0.0, 0.0 };
		
		Vec3 direction = { 0.0, 0.0, 0.0 };
		
		Vec3 position = { 0.0, 0.0, 0.0 };

		enum class Type
		{
			Off,
			Directional,
			Point,
		} type = Type::Off;

		Light() {}

		Light(
			const ColorF& _diffuse,
			const Vec3& _attenuaion,
			const Vec3& _direction,
			const Vec3& _position,
			Type _type
			)
			: diffuse{ _diffuse }
			, attenuaion{ _attenuaion }
			, direction{ _direction }
			, position{ _position }
			, type{ _type } {}

		static Light Off()
		{
			return{};
		}

		static Light Directional(const Vec3& _direction, const ColorF& _diffuse = { 1.0, 1.0, 1.0 })
		{
			return{ _diffuse, { 0.0, 0.0, 0.0 }, _direction, { 0.0, 0.0, 0.0 }, Type::Directional };
		}

		static Light Point(const Vec3& _position, double r, const ColorF& _diffuse = { 1.0, 1.0, 1.0 })
		{
			return{ _diffuse, { 1.0, 2.0 / r, 1.0 / (r*r) }, { 0.0, 0.0, 0.0 }, _position, Type::Point };
		}
	};

	struct Fog
	{
		ColorF color = { 0.0, 0.0 };
		
		double begin = 0.0;
		
		double end = 1.0;
		
		double heightScale = 0.0;
		
		double heightInfluence = 0.0;
		
		double density = 0.0;
		
		enum class Type
		{
			None,
			Linear,
			SquareExponential,
		} type = Type::None;

		Fog(){}

		Fog(
			const ColorF& _color,
			double _begin,
			double _end,
			double _heightScale,
			double _heightInfluence,
			double _density,
			Type _type
			)
			: color{ _color }
			, begin{ _begin }
			, end{ _end }
			, heightScale{ _heightScale }
			, heightInfluence{ _heightInfluence }
			, density{ _density }
			, type{ _type } {}

		static Fog Off()
		{
			return{};
		}

		static Fog Linear(const ColorF& _color, double _begin, double _end)
		{
			return{ _color, _begin, _end, 0.0, 0.0, 0.0, Type::Linear };
		}

		static Fog SquareExponential(const ColorF& _color, double _density, double _heightScale = 0.0, double _heightInfluence = 0.5)
		{
			return{ _color, 0.0, 0.0, _heightScale, _heightInfluence, _density, Type::SquareExponential };
		}
	};

	enum class AntiAliasing
	{
		None,
		
		Low,
		
		Medium,
		
		High,

		Default = Low
	};

	namespace Graphics
	{
		////////////////////////////////////////////////////////////////
		//
		//		�J����
		//
		////////////////////////////////////////////////////////////////

		void
			SetCamera(
			const Camera& state
			);

		const Camera&
			GetCamera(
			);

		void
			FreeCamera(
			double speed = 0.1
			);

		Vec3
			GetScreenPos(
			const Vec3& worldPos
			);

		Vec3
			GetWorldPos(
			const Vec2& screenPos,
			double depth
			);

		Ray
			GetRayFromScreenPos(
			const Vec2& screenPos
			);

		////////////////////////////////////////////////////////////////
		//
		//		���C�e�B���O
		//
		////////////////////////////////////////////////////////////////

		enum
		{
			MaxLightIndex	= 127,
			
			MaxLight		= 128
		};

		void
			SetAmbient(
			const ColorF& color
			);

		const ColorF&
			GetAmbient(
			);

		void
			SetLight(
			unsigned index,	// [0-127]
			const Light& light
			);

		const Light&
			GetLight(
			unsigned index	// [0-127]
			);

		////////////////////////////////////////////////////////////////
		//
		//		�t�H�O
		//
		////////////////////////////////////////////////////////////////

		void
			SetFog(
			const Fog& fog
			);

		const s3d::Fog&
			GetFog(
			);

		////////////////////////////////////////////////////////////////
		//
		//		�掿�ƃp�t�H�[�}���X
		//
		////////////////////////////////////////////////////////////////

		/**
		*	�A���`�G�C���A�V���O�̕i����ݒ肵�܂��B
		*	@param antiAliasing
		*/
		void
			SetAntiAliasing(
			AntiAliasing antiAliasing
			);

		/**
		*	���C�g�o�b�t�@�̕i����ύX���܂��B
		*	�f�t�H���g�ł� 100 �ŁA�i��������������ƕ��G�ȃV�[���ł̉掿���ቺ���܂����A
		*	���C�e�B���O�ɂ�����R�X�g�͐��l�ɔ�Ⴕ�Č������܂��B
		*	@param quality ���C�g�o�b�t�@�̕i���B [1-100] �͈̔͂Ŏw�肵�܂�
		*	@note quality �� 1 ���� 100 �͈̔͂ɃN�����v����܂�
		*	@return ����ɕύX�ł����ꍇ true, �������s���Ȃǂ̃G���[�����������ꍇ false
		*/
		bool
			SetLightBufferQuality(
			unsigned quality = 100
			);

		/**
		*	3D �`��̐ݒ�����Z�b�g���܂��B
		*/
		inline
			void
			Reset3DState(
			)
		{
			SetAmbient({ 0.0, 0.0, 0.0 });

			for (int i = 0; i <= MaxLightIndex; ++i)
			{
				SetLight(i, Light::Off());
			}

			SetFog(Fog::Off());

			SetCamera(Camera());

			SetAntiAliasing(AntiAliasing::Default);

			SetLightBufferQuality(100);
		}
	}
}
