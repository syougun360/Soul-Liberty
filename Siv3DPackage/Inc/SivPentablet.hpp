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

namespace s3d
{
	/**
	*	@brief ペンタブレット
	*/
	namespace Pentablet
	{
		/**
		*
		*	@return
		*/
		bool
			IsEnable(
			);

		/**
		*
		*	@return
		*/
		bool
			SupportsPressure(
			);

		/**
		*
		*	@return
		*/
		double
			Pressure(
			);

		/**
		*
		*	@return
		*/
		int
			DegreeXZ(
			);

		/**
		*
		*	@return
		*/
		int
			DegreeY(
			);
	}
}
