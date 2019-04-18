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

namespace s3d
{
	namespace Twitter
	{
		/**
		*	Twitter への投稿ページをユーザの既定のブラウザで開く
		*	@param text 投稿するテキスト
		*	@return ブラウザを起動できたら true, それ以外の場合は false
		*/
		bool OpenTweetWindow(const String& text);
	}
}
