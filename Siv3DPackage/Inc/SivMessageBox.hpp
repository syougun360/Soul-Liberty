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
# ifdef	MessageBox
#  undef MessageBox
# endif
# include "SivForward.hpp"
# include "SivOptional.hpp"

namespace s3d
{
	enum class MessageBoxStyle
	{
		Ok,

		OkCancel,

		YesNo,

		YesNoCancel,

		RetryCancel,

		CancelRetryContinue,
	};

	enum class MessageBoxCommand
	{
		Ok,

		Cancel,

		Yes,

		No,

		Continue,

		Retry,
	};

	namespace MessageBox
	{
		MessageBoxCommand
			Show(
			const String& title,
			const String& text,
			MessageBoxStyle style = MessageBoxStyle::Ok,
			int defaultButton = 0
			);
	}
}
