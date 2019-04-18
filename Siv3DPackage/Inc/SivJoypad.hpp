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
# include "SivGamePad.hpp"

namespace s3d
{
	/**
	*	@brief ジョイスパッド
	*/
	class Joypad
	{
	private:

		unsigned m_userIndex;

	public:

		/**
		*
		*	@param userIndex
		*/
		Joypad(unsigned userIndex);

		/**
		*
		*/
		Property_Get(bool, connected) const;

		/**
		*
		*/
		Property_Get(bool, hasZ) const;
		
		/**
		*
		*/
		Property_Get(bool, hasR) const;
		
		/**
		*
		*/
		Property_Get(bool, hasU) const;

		/**
		*
		*/
		Property_Get(bool, hasV) const;

		/**
		*
		*/
		Property_Get(unsigned, xMin) const;

		/**
		*
		*/
		Property_Get(unsigned, xMax) const;

		/**
		*
		*/
		Property_Get(unsigned, yMin) const;

		/**
		*
		*/
		Property_Get(unsigned, yMax) const;

		/**
		*
		*/
		Property_Get(unsigned, zMin) const;

		/**
		*
		*/
		Property_Get(unsigned, zMax) const;

		/**
		*
		*/
		Property_Get(unsigned, rMin) const;

		/**
		*
		*/
		Property_Get(unsigned, rMax) const;

		/**
		*
		*/
		Property_Get(unsigned, uMin) const;

		/**
		*
		*/
		Property_Get(unsigned, uMax) const;

		/**
		*
		*/
		Property_Get(unsigned, vMin) const;

		/**
		*
		*/
		Property_Get(unsigned, vMax) const;

		/**
		*
		*/
		Property_Get(unsigned, xPos) const;

		/**
		*
		*/
		Property_Get(unsigned, yPos) const;

		/**
		*
		*/
		Property_Get(unsigned, zPos) const;

		/**
		*
		*/
		Property_Get(unsigned, rPos) const;

		/**
		*
		*/
		Property_Get(unsigned, uPos) const;

		/**
		*
		*/
		Property_Get(unsigned, vPos) const;

		/**
		*
		*/
		Property_Get(unsigned, numButtons) const;

		/**
		*
		*	@param number
		*	@return
		*/
		GamePadButton button(unsigned number) const;
	};
}
