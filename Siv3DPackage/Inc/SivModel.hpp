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
# include <unordered_map>
# include "SivString.hpp"
# include "SivMesh.hpp"

namespace s3d
{
	struct MaterialElement
	{
		enum class ElementType
		{
			None,
			Color,
			Texture,
			Both,
		};

		float r, g, b, a;

		ElementType type;

		std::unordered_map<String, std::vector<FilePath>> textureSetArray;

		MaterialElement() = default;

		~MaterialElement()
		{
			release();
		}

		void release()
		{
			textureSetArray.clear();
		}
	};

	struct MaterialNode
	{
		enum class MaterialType
		{
			Lambert,
			Phong,
		};

		MaterialElement ambient;
		MaterialElement diffuse;
		MaterialElement emmisive;
		MaterialElement specular;
		MaterialType type;

		float shininess;
		float TransparencyFactor;   // “§‰ß“x
	};

	struct Material
	{
		String name;

		ColorF ambient;

		ColorF diffuse;

		ColorF specular;

		ColorF transmittance;

		ColorF emission;

		float shininess;

		String ambientTextureName;

		String diffuseaTextureName;

		String specularTextureName;

		String normalTextureName;
	};

	struct ModelNode
	{
		ModelNode() = default;

		ModelNode(const String& _name, const Mesh& _mesh, const Material& _material)
			: name(_name)
			, mesh{ _mesh }
			, material(_material)
		{

		}

		String name;

		Mesh mesh;

		Material material;
	};

	class Model
	{
	public:

		Model() = default;

		// OBJ Œ`Ž®‚Ì‚Ý
		Model(const FilePath& path);

		std::vector<ModelNode> nodes;
	};
}
