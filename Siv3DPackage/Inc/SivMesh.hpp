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
# include <vector>
# include "SivHandle.hpp"
# include "SivForward.hpp"
# include "SivPointVector.hpp"
# include "SivString.hpp"
# include "SivOptional.hpp"
# include "SivRenderer.hpp"
# include "SivMatrix.hpp"

namespace s3d
{
	struct Vertex
	{
		Float3 position;
		
		Float3 normal;
		
		Float2 texcoord;
	};

	struct MeshObject
	{
		std::vector<Vertex> vertices;

		std::vector<unsigned> indices;
	};

	class Mesh
	{
	protected:

		class Handle{};

		typedef Siv3DHandle<Handle> MeshHandle;

		std::shared_ptr<MeshHandle> m_handle;

		struct _dyanmic{};

		explicit Mesh(
			const MeshObject& meshObject,
			const _dyanmic&
			);

	public:

		Mesh(
			);

		explicit Mesh(
			const MeshObject& meshObject
			);

		virtual ~Mesh(
			);

		void
			release(
			);

		explicit operator bool() const;

		Property_Get(HandleIDType, id) const;

		Property_Get(bool, isEmpty) const;

		bool operator == (const Mesh& mesh) const;

		bool operator != (const Mesh& mesh) const;

		Property_Get(unsigned, vertexSize) const;

		Property_Get(unsigned, indexSize) const;

		void draw(const optional<Renderer>& renderer) const;
		
		void draw(const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;
	
		void draw(const Texture& texture, const optional<Renderer>& renderer) const;
	
		void draw(const Texture& texture, const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;
			
		TransformedMesh translate(const Vec3& translation) const;

		TransformedMesh scale(double scaling) const;

		TransformedMesh scale(const Vec3& scaling) const;

		TransformedMesh rotate(const Vec3& rotation) const;

		TransformedMesh rotate(const Quaternion& rotation) const;

		TransformedMesh transform(const Vec3& rotation, const Vec3& translation) const;

		TransformedMesh transform(const Quaternion& rotation, const Vec3& translation) const;

		TransformedMesh transform(double scaling, const Vec3& rotation, const Vec3& translation) const;

		TransformedMesh transform(double scaling, const Quaternion& rotation, const Vec3& translation) const;

		TransformedMesh transform(const Vec3& scaling, const Vec3& rotation, const Vec3& translation) const;

		TransformedMesh transform(const Vec3& scaling, const Quaternion& rotation, const Vec3& translation) const;
	};

	struct TransformedMesh
	{
		Mat4x4 matrix;

		Mesh mesh;

		TransformedMesh(){}

		TransformedMesh(const Mat4x4& _matrix, const Mesh& _mesh)
			: matrix{ _matrix }
			, mesh{ _mesh } {}

		void draw(const optional<Renderer>& renderer) const;

		void draw(const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;

		void draw(const Texture& texture, const optional<Renderer>& renderer) const;

		void draw(const Texture& texture, const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;

		TransformedMesh translate(const Vec3& translation) const;

		TransformedMesh scale(const Vec3& scaling) const;

		TransformedMesh rotate(const Vec3& rotation) const;

		TransformedMesh rotate(const Quaternion& rotation) const;
	};


	/**
	*	@brief 動的メッシュ
	*
	*	中身を更新可能なメッシュです。
	*	Mesh と異なり、メモリを再確保することなくメッシュデータを更新できます。
	*/
	class DynamicMesh : public Mesh
	{
	public:

		/**
		*
		*/
		DynamicMesh(
			);

		/**
		*
		*/
		DynamicMesh(
			const MeshObject& meshObject
			);

		bool
			fill(
			const MeshObject& meshObject
			);

		bool
			fillVertices(
			const std::vector<Vertex>& vertices
			);

		bool
			fillIndices(
			const std::vector<unsigned>& indices
			);

		bool
			tryFillVertices(
			const std::vector<Vertex>& vertices
			);

		bool
			tryFillIndices(
			const std::vector<unsigned>& indices
			);
	};


	struct Billboard
	{
		Float3 scaling;

		Float3 pos;

		Billboard(double _scaling = 1.0, const Vec3& _pos = { 0.0, 0.0, 0.0 })
			: scaling{ _scaling, _scaling, _scaling }
			, pos{ _pos }{}

		Billboard(const Vec3& _scaling, const Vec3& _pos = { 0.0, 0.0, 0.0 })
			: scaling{ _scaling }
			, pos{ _pos }{}

		void draw(const optional<Renderer>& renderer) const;

		void draw(const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;

		void draw(const Texture& texture, const optional<Renderer>& renderer) const;

		void draw(const Texture& texture, const ColorF& color = Palette::White, const optional<Renderer>& renderer = unspecified) const;
	};
}
