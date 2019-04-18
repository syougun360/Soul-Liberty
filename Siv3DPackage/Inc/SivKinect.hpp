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
# include "SivOptional.hpp"
# include "SivVector.hpp"
# include "SivHSV.hpp"

namespace s3d
{
	/*
	enum class ChooserMode
	{
		Default,
		Closest1,
		Closest2,
		Sticky1,
		Sticky2,
	};
	*/

	/**
	*	@brief
	*/
	struct SkeltonPosition
	{
		enum Index
		{
			/**
			*
			*/
			HipCenter,

			/**
			*
			*/
			Spine,

			/**
			*
			*/
			ShoulderCenter,

			/**
			*
			*/
			Head,

			/**
			*
			*/
			ShoulderLeft,

			/**
			*
			*/
			ElbowLeft,

			/**
			*
			*/
			WristLeft,

			/**
			*
			*/
			HandLeft,

			/**
			*
			*/
			ShoulderRight,

			/**
			*
			*/
			ElbowRight,

			/**
			*
			*/
			WristRight,

			/**
			*
			*/
			HandRight,

			/**
			*
			*/
			HipLeft,

			/**
			*
			*/
			KneeLeft,

			/**
			*
			*/
			AnkleLeft,

			/**
			*
			*/
			FootLeft,

			/**
			*
			*/
			HipRight,

			/**
			*
			*/
			KneeRight,

			/**
			*
			*/
			AnkleRight,

			/**
			*
			*/
			FootRight
		};
	};

	/**
	*	@brief
	*/
	struct Skelton
	{
		/**
		*
		*/
		Vec3 positions[20];

		/**
		*
		*/
		Vec2 screenPositions[20];

		/**
		*
		*/
		Vec3 bodyPosition;

		/**
		*
		*/
		Vec2 screenBodyPosition;

		/**
		*
		*/
		int id;
	};

	/**
	*	@brief
	*/
	enum class KinectColor
	{
		None,
		RGB_80x60,
		RGB_320x240,
		RGB_640x480,
	};

	/**
	*	@brief
	*/
	enum class KinectDepth
	{
		/**
		*
		*/
		None,

		/**
		*
		*/
		Depth_80x60,

		/**
		*
		*/
		Depth_320x240,

		/**
		*
		*/
		Depth_640x480,
	};

	/**
	*	@brief
	*/
	struct KinectProperty
	{
		/**
		*
		*	@param _colorResolution
		*	@param _depthResolution
		*	@param _skeltonTracking
		*	@param _nearMode
		*	@param _seatedMode
		*/
		KinectProperty(
			KinectColor _colorResolution = KinectColor::RGB_640x480,
			KinectDepth _depthResolution = KinectDepth::Depth_640x480,
			bool _skeltonTracking = true,
			bool _nearMode = false,
			bool _seatedMode = false
			)
			: colorResolution{ _colorResolution },
			  depthResolution{ _depthResolution },
			  skeltonTracking{ _skeltonTracking },
			  nearMode{ _nearMode },
			  seatedMode{ _seatedMode }{}

		/**
		*
		*	@return
		*/
		static KinectProperty Default()
		{
			return{ KinectColor::RGB_640x480, KinectDepth::Depth_640x480, true, false, false };
		}

		/**
		*
		*	@return
		*/
		static KinectProperty Seated()
		{
			return{ KinectColor::RGB_640x480, KinectDepth::Depth_640x480, true, true, true };
		}

		/**
		*
		*/
		KinectColor colorResolution = KinectColor::RGB_640x480;

		/**
		*
		*/
		KinectDepth depthResolution = KinectDepth::Depth_640x480;

		/**
		*
		*/
		bool skeltonTracking = true;

		/**
		*
		*/
		bool nearMode = false;

		/**
		*
		*/
		bool seatedMode = false;
	};

	/**
	*	@brief キネクト
	*/
	namespace Kinect
	{
		/**
		*
		*	@param d
		*	@return
		*/
		inline Color DefaultDepthColoring(short d)
		{
			return d != 0 ? HSV(d / 6).toColor() : Palette::Black;
		}

		/**
		*	Kinect が接続されていて利用可能かを返します。
		*	@return Kinect が利用可能なら true, それ以外は false
		*/
		bool
			IsConnected(
			);

		/**
		*
		*	@param property
		*	@return
		*/
		bool
			Start(
			const KinectProperty& property = KinectProperty::Default()
			);

		/**
		*
		*/
		void
			Stop(
			);

		/**
		*	Kinect のデプスカメラで near モードを有効にするかを設定します。
		*	@param nearMode near モードを有効にする場合は true, 無効にする場合は false. デフォルトでは false
		*/
		void
			SetNearMode(
			bool nearMode
			);

		/**
		*	Kinect のスケルトントラッキングで seated モードを有効にするかを設定します。
		*	@param seatedMode seated モードを有効にする場合は true, 無効にする場合は false. デフォルトでは false
		*/
		void
			SetSeatedMode(
			bool seatedMode
			);

		/**
		*
		*	@return
		*/
		bool
			HasNewColor(
			);

		/**
		*
		*	@return
		*/
		const Image&
			GetColorImage(
			);

		/**
		*
		*	@return
		*/
		const cv::Mat&
			GetColorCV_8UC4(
			);

		/**
		*
		*	@param texture
		*	@return
		*/
		bool
			GetColorTexture(
			DynamicTexture& texture
			);

		/**
		*
		*	@return
		*/
		bool
			HasNewDepth(
			);

		/**
		*
		*	@return
		*/
		const std::vector<short>&
			GetDepth(
			);

		/**
		*
		*	@param coloringRule
		*	@return
		*/
		const Image&
			GetDepthImage(
			std::function<Color(short)> coloringRule = DefaultDepthColoring
			);

		/**
		*
		*	@param texture
		*	@param coloringRule
		*	@return
		*/
		bool
			GetDepthTexture(
			DynamicTexture& texture,
			std::function<Color(short)> coloringRule = DefaultDepthColoring
			);

		/**
		*
		*	@return
		*/
		const cv::Mat&
			GetDepthCV_16UC1(
			);

		/**
		*	スケルトンデータを返します。
		*	index は 0 か 1 のみ有効
		*	@param index
		*	@return
		*/
		optional<Skelton>
			GetSkelton(
			unsigned index = 0
			);

		/**
		*
		*	@return
		*/
		int
			GetElevation(
			);

		/**
		*	Kinect カメラの角度を設定します。
		*	angleDegree は [-27,27] にクランプされます。
		*	@param angleDegree
		*/
		void SetElevation(
			int angleDegree
			);

		/**
		*	Kinect にかかる加速度を返します。
		*	水平に静止している場合 Vec3(0,-1,0) を返します。
		*	加速度を取得できない場合は Vec3(0,0,0) を返します。
		*	@return
		*/
		Vec3 GetAcceleration(
			);
	}
}
