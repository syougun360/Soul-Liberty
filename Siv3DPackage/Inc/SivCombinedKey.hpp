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
# include "SivInput.hpp"

namespace s3d
{
	/**
	*	@brief
	*/
	class PlusCombinedKeys
	{
	private:

		Key m_key1, m_key2;

	public:

		/**
		*
		*/
		PlusCombinedKeys(){}

		/**
		*
		*	@param key1
		*	@param key2
		*/
		PlusCombinedKeys(Key key1, Key key2) : m_key1{ key1 }, m_key2{ key2 }{}

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

	/**
	*	@brief
	*/
	class OrCombinedKeys
	{
	private:

		Key m_key1, m_key2;

	public:

		/**
		*
		*/
		OrCombinedKeys(){}

		/**
		*
		*	@param key1
		*	@param key2
		*/
		OrCombinedKeys(Key key1, Key key2) : m_key1(key1), m_key2(key2){}

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

	/**
	*
	*	@param key1
	*	@param key2
	*	@return
	*/
	PlusCombinedKeys operator + (Key key1, Key key2);

	/**
	*
	*	@param key1
	*	@param key2
	*	@return
	*/
	OrCombinedKeys operator | (Key key1, Key key2);
}
