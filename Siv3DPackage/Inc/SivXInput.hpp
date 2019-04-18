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
	*	@brief XInput ëŒâûÉRÉìÉgÉçÅ[Éâ
	*/
	class XInput
	{
	private:

		unsigned m_userIndex;

	public:

		/**
		*
		*	@param userIndex
		*/
		XInput(unsigned userIndex);

		/**
		*
		*/
		Property_Get(bool, connected) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonUp) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonDown) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonLeft) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonRight) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonStart) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonBack) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonLThumb) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonRThumb) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonLB) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonRB) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonA) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonB) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonX) const;

		/**
		*
		*/
		Property_Get(GamePadButton, buttonY) const;

		/**
		*
		*/
		Property_Get(unsigned char, leftTrigger) const;

		/**
		*
		*/
		Property_Get(unsigned char, rightTrigger) const;

		/**
		*
		*/
		Property_Get(short, thumbLX) const;

		/**
		*
		*/
		Property_Get(short, thumbLY) const;

		/**
		*
		*/
		Property_Get(short, thumbRX) const;

		/**
		*
		*/
		Property_Get(short, thumbRY) const;

		/**
		*
		*	@param leftMotorSpeed
		*	@param rightMotorSpeed
		*/
		void
			setVibration(
			unsigned short leftMotorSpeed,
			unsigned short rightMotorSpeed
			) const;

		/**
		*
		*/
		void
			stopVibration(
			) const;
	};
}
