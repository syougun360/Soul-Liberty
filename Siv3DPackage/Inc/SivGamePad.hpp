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
# include "SivPropertyMacro.hpp"

namespace s3d
{
	/**
	*	@brief
	*/
	class GamePadButton
	{
	private:

		unsigned m_userIndex = 0;
		
		unsigned m_buttonCode = 0;
		
		GamePadButton(unsigned userIndex, unsigned buttonCode);
		
		friend class XInput;
		
		friend class Joypad;

	public:

		/**
		*
		*/
		GamePadButton(){}

		/**
		*
		*/
		Property_Get(bool, clicked) const;

		/**
		*
		*/
		Property_Get(bool, pressed) const;

		/**
		*
		*/
		Property_Get(bool, released) const;
	};
}

# include "SivXInput.hpp"
# include "SivJoypad.hpp"
