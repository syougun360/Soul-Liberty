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
	enum { NullHandleID = 0 };

	typedef unsigned HandleIDType;

	template<typename Type>
	struct Siv3DHandle
	{
	private:

		HandleIDType m_id = NullHandleID;

	public:

		Siv3DHandle() = default;

		Siv3DHandle(HandleIDType id) : m_id{ id }{}

		~Siv3DHandle();

		HandleIDType getID() const
		{
			return m_id;
		}
	};
}
