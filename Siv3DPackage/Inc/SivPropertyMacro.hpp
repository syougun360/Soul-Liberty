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

/**
*	@brief プロパティ用マクロ
*/
# define Property_Get(type,name)	__declspec(property(get=_get_##name))type name;\
									type _get_##name()
