//----------------------------------------------------------
//
//	This file is part of the Siv3D Engine
//
//	Copyright (C) 2008-2014 Reputeless,
//
//	Waseda Computer Entertainment. All rights reserved.
//
//----------------------------------------------------------

namespace s3d
{
	enum class LogDescription
	{
		Error,		// Less
		Fail,		// Less
		Warning,	// Less
		Script,		// Less
		App,		// Normal
		Info,		// Normal
		Debug,		// More
		NumberOfDesc,
	};

	void OutputLog(LogDescription desc, const String& str);

	template <typename ... Args>
	inline void OutputLog(const LogDescription desc, const Args& ... args)
	{
		OutputLog(desc, Format(args...));
	}

	void OutputLogOnce(LogDescription desc, int id, const String& str);

	template <typename ... Args>
	inline void OutputLogOnce(LogDescription desc, const int id, const Args& ... args)
	{
		OutputLogOnce(desc, id, Format(args...));
	}
}
