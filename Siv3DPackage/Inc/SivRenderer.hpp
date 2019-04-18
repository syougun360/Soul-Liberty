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
# include <memory>
# include "SivHandle.hpp"
# include "SivGraphics2D.hpp"

namespace s3d
{
	enum class Shading
	{
		Forward,

		Deferred,
	};

	enum class Rasterizer
	{
		NoCull_Solid = 1,

		Cull_Solid = 2,

		NoCull_Wireframe = 3,

		Cull_Wireframe = 4,
	};

	struct RendererProperty
	{
		RendererProperty(
			Shading _shading = Shading::Deferred,
			Rasterizer _rasterizer = Rasterizer::Cull_Solid,
			BlendState _forwardBlend = BlendState::Default(),
			SamplerState _sampler = SamplerState::Default3D(),
			bool _depthEnable = true,
			bool _depthWriteEnable = true,
			bool _forwardFogEnable = true
			)
			:shading{ _shading },
			  rasterizer{ _rasterizer },
			  forwardBlend{ _forwardBlend },
			  sampler{ _sampler },
			  depthEnable{ _depthEnable },
			  depthWriteEnable{ _depthWriteEnable },
			  forwardFogEnable{ _forwardFogEnable } {}

		Shading shading = Shading::Deferred;

		Rasterizer rasterizer = Rasterizer::Cull_Solid;

		BlendState forwardBlend = BlendState::Default();

		SamplerState sampler = { TextureFilter::Anisotropic, TextureAddressMode::Wrap };

		bool depthEnable = true;

		bool depthWriteEnable = true;

		bool forwardFogEnable = true;

		static RendererProperty Default()
		{
			return{};
		}

		static RendererProperty Forward()
		{
			return{ Shading::Forward };
		}
	};


	class Renderer
	{
	private:

		class Handle{};

		typedef Siv3DHandle<Handle> RendererHandle;

		std::shared_ptr<RendererHandle> m_handle;

	public:

		Renderer(
			);

		explicit Renderer(
			const RendererProperty& rendererProperty
			);

		virtual ~Renderer(
			);

		void
			release(
			);

		explicit operator bool() const;

		Property_Get(HandleIDType, id) const;

		Property_Get(bool, isEmpty) const;

		bool operator == (const Renderer& renderer) const;

		bool operator != (const Renderer& renderer) const;

		Property_Get(const RendererProperty, rendererProperty) const;
	};
}
