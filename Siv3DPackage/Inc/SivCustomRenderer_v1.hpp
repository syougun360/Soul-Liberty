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
# include <functional>
struct ID3D11DeviceContext;

namespace s3d
{
	typedef std::function<bool(void *userdata)> customRendererCallback;

	namespace CustomRenderer
	{
		ID3D11DeviceContext* GetDeviceContext();

		// while(System::Update())
		// {
		//		main loop
		//		-> draw 2D-Background
		// }
		//
		// in System::Update()
		// [
		// -> draw Deferred
		// -> [DeferredCallback]
		// -> Light Accumulation
		// -> Finalize
		// -> draw Forward
		// -> [ForwardCallback]
		// -> FXAA
		// -> [PostProcessCallback]
		// -> draw 2D
		// -> [2DCallback]
		// -> present
		// -> clear
		// ]

		// RT0: G-Buffer.Albedo, RT1: G-Buffer.Depth, RT2: G-Buffer.Normal, DS: G-Buffer
		void SetDeferredCallback(customRendererCallback callback, void* userData = nullptr);

		// RT0: Finalized, RT1: (none), RT2: (none), DS: G-Buffer
		void SetForwardCallback(customRendererCallback callback, void* userData = nullptr);

		// RT0: Main, RT1: (none), RT2: (none), DS: (none)
		void SetPostProcessCallback(customRendererCallback callback, void* userData = nullptr);

		// RT0: Main, RT1: (none), RT2: (none), DS: Main
		void Set2DCallback(customRendererCallback callback, void* userData = nullptr);
	}

	// TODO: hasDeferred, hasDeferred change
}
