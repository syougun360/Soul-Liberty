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
# include <vector>
# include "SivForward.hpp"
# include "SivPointVector.hpp"
# include "SivQuad.hpp"
# include "SivQuaternion.hpp"
# include "SivAlignedAllocator.hpp"

namespace s3d
{
	/**
	*	@brief
	*/
	struct ARMarkerInfo
	{
		Quaternion rotation;

		Quad quad;
		
		/**
		*
		*/
		Vec2 center;

		Vec3 pos;

		/**
		*
		*/
		double perimeter;
		
		/**
		*
		*/
		double area;
		
		/**
		*
		*/
		int id;
	};

	/**
	*	@brief
	*/
	namespace ARMarker
	{
		/**
		*
		*	@param id
		*	@param tileSize
		*	@return
		*/
		Image
			CreateMarker(
			unsigned id,
			unsigned tileSize
			);

		/**
		*
		*	@return
		*/
		bool
			Start(
			);

		/**
		*
		*/
		void
			Stop(
			);

		/**
		*
		*	@return
		*/
		bool
			IsActive(
			);

		/**
		*
		*	@return
		*/
		bool
			HasNewFrame(
			);

		/**
		*
		*	@return
		*/
		vector<ARMarkerInfo>
			GetMarkers(
			);
	}
}
