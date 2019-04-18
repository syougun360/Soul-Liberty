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
# include "SivFormat.hpp"

namespace s3d
{
	void
		Print(
		const String& text
		);

	void
		Println(
		const String& text
		);

	template <typename ... Args>
	inline
	void
		Print(
		const Args& ... args
		)
	{
		Print(Format(args...));
	}

	template <typename ... Args>
	inline
	void
		Println(
		const Args& ... args
		)
	{
		Println(Format(args...));
	}

	void
		ClearPrint(
		);

	/**
	*	���炩�̃L�[�����͂����܂ŉ�ʂ�\�������܂ܑҋ@���܂��B
	*	@note System::Update() �Ƃ͕��p�ł��܂���B
	*/
	void
		WaitKey(
		);
}
