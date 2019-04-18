//-------------------------------------------------------------------------------
//
//	Copyright (C) 2008-2014 Reputeless
//
//	Licensed under the Apache License, Version 2.0 (the "License");
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
//
//	http ://www.apache.org/licenses/LICENSE-2.0
//
//	Unless required by applicable law or agreed to in writing, software
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	See the License for the specific language governing permissions and
//	limitations under the License.
//
//--------------------------------------------------------------------------------

# include <unordered_map>
# define FBXSDK_SHARED
# include <fbxsdk.h>
# ifdef _DEBUG
# pragma comment (lib ,"debug/libfbxsdk" )
# else
# pragma comment (lib ,"release/libfbxsdk" )
# endif

namespace s3d
{
	// 参考: https://github.com/shaderjp/FBXLoader
	namespace FBX
	{
		// UVSet名, 頂点内のUVセット順序
		typedef std::unordered_map<String, int> UVsetID;

		// UVSet名, テクスチャパス名(１つのUVSetに複数のテクスチャがぶら下がってることがある)
		typedef std::unordered_map<String, std::vector<FilePath>> TextureSet;

		// メッシュ構成要素
		struct MeshProperty
		{
			unsigned numPosition = 0;     // 頂点座標のセットをいくつ持つか
			unsigned numNormal = 0;  //
			unsigned numUVSet = 0;   // UVセット数
		};

		//
		struct MeshNode
		{
			// ノード名
			String name;

			// 親ノード名(親がいないなら"null"という名称が入る.rootノードの対応)
			String parentName;

			// メッシュが保持するデータ構造
			MeshProperty elements;

			// マテリアル
			std::vector<MaterialNode> m_materialNodes;

			UVsetID uvsetID;

			std::vector<unsigned> indices;

			std::vector<FbxVector4> positions;

			std::vector<Float3> normals;

			std::vector<Float2> texcoords;

			float matrix[16];

			~MeshNode()
			{
				release();
			}

			void release()
			{
				texcoords.clear();
				normals.clear();
				positions.clear();
				indices.clear();

				uvsetID.clear();
				m_materialNodes.clear();
			}
		};

		class FBXLoader
		{
		private:

			FbxManager* m_sdkManager = nullptr;

			FbxScene* m_scene = nullptr;

			FbxImporter* m_importer = nullptr;

			FbxAnimLayer* m_currentAnimLayer = nullptr;

			std::vector<MeshNode> m_meshNodes;

			bool initSdkObjects()
			{
				m_sdkManager = FbxManager::Create();

				if (!m_sdkManager)
				{
					LOG(L"Error: FbxManager::Create()\n");

					return false;
				}

				FbxIOSettings* ios = FbxIOSettings::Create(m_sdkManager, IOSROOT);
				m_sdkManager->SetIOSettings(ios);

				m_sdkManager->LoadPluginsDirectory(FbxGetApplicationDirectory().Buffer());

				m_scene = FbxScene::Create(m_sdkManager, "My Scene");

				if (!m_scene)
				{
					LOG(L"Error: FbxScene::Create()\n");

					return false;
				}

				return true;
			}

			void triangulateRecursive(FbxNode* pNode)
			{
				FbxNodeAttribute* lNodeAttribute = pNode->GetNodeAttribute();

				if (lNodeAttribute)
				{
					if (lNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh ||
						lNodeAttribute->GetAttributeType() == FbxNodeAttribute::eNurbs ||
						lNodeAttribute->GetAttributeType() == FbxNodeAttribute::eNurbsSurface ||
						lNodeAttribute->GetAttributeType() == FbxNodeAttribute::ePatch)
					{
						FbxGeometryConverter lConverter(pNode->GetFbxManager());

						lConverter.Triangulate(m_scene, true);
					}
				}

				const int lChildCount = pNode->GetChildCount();

				for (int lChildIndex = 0; lChildIndex<lChildCount; ++lChildIndex)
				{
					triangulateRecursive(pNode->GetChild(lChildIndex));
				}
			}

			void setupNode(FbxNode* pNode, const String& parentName)
			{
				if (!pNode)
				{
					return;
				}

				MeshNode meshNode;
				meshNode.name = Widen(pNode->GetName());
				meshNode.parentName = parentName;

				const FbxMesh* lMesh = pNode->GetMesh();

				if (lMesh && lMesh->GetControlPointsCount() > 0)
				{
					copyVertexData(*lMesh, &meshNode);
				}

				const int lMaterialCount = pNode->GetMaterialCount();

				for (int i = 0; i < lMaterialCount; ++i)
				{
					const FbxSurfaceMaterial* material = pNode->GetMaterial(i);

					if (!material)
					{
						continue;
					}

					MaterialNode destMat;
					copyMatrialData(*material, &destMat);

					meshNode.m_materialNodes.push_back(destMat);
				}

				computeNodeMatrix(pNode, &meshNode);

				m_meshNodes.push_back(meshNode);

				const int lCount = pNode->GetChildCount();

				for (int i = 0; i < lCount; ++i)
				{
					setupNode(pNode->GetChild(i), meshNode.name);
				}
			}

			void setup()
			{
				if (m_scene->GetRootNode())
				{
					setupNode(m_scene->GetRootNode(), L"null");
				}
			}

			void copyVertexData(const FbxMesh& mesh, MeshNode* meshNode)
			{
				const int lPolygonCount = mesh.GetPolygonCount();

				meshNode->elements.numPosition = 1;
				meshNode->elements.numNormal = 1;

				unsigned indx = 0;

				for (int i = 0; i<lPolygonCount; ++i)
				{
					const int lPolygonsize = mesh.GetPolygonSize(i);

					for (int pol = 0; pol<lPolygonsize; ++pol)
					{
						meshNode->indices.push_back(indx);

						FbxVector4 nor;

						mesh.GetPolygonVertexNormal(i, pol, nor);

						meshNode->positions.push_back(mesh.GetControlPointAt(mesh.GetPolygonVertex(i, pol)));
						meshNode->normals.emplace_back(static_cast<float>(nor[0]), static_cast<float>(nor[1]), static_cast<float>(nor[2]));

						++indx;
					}
				}

				// UV処理(UVは2つ以上ある場合があるので別処理)
				FbxStringList uvsetName;
				mesh.GetUVSetNames(uvsetName);

				const int numUVSet = uvsetName.GetCount();
				meshNode->elements.numUVSet = numUVSet;

				bool unmapped = false;

				for (int uv = 0; uv<numUVSet; ++uv)
				{
					meshNode->uvsetID[Widen(uvsetName.GetStringAt(uv))] = uv;

					for (int i = 0; i<lPolygonCount; ++i)
					{
						const int lPolygonsize = mesh.GetPolygonSize(i);

						for (int pol = 0; pol < lPolygonsize; ++pol)
						{
							const FbxString name = uvsetName.GetStringAt(uv);
							FbxVector2 texCoord;
							mesh.GetPolygonVertexUV(i, pol, name, texCoord, unmapped);
							meshNode->texcoords.emplace_back(static_cast<float>(texCoord[0]), static_cast<float>(texCoord[1]));
						}
					}
				}
			}

			void copyMatrialData(const FbxSurfaceMaterial& material, MaterialNode* destMat)
			{
				if (material.GetClassId().Is(FbxSurfaceLambert::ClassId))
				{
					destMat->type = MaterialNode::MaterialType::Lambert;
				}
				else if (material.GetClassId().Is(FbxSurfacePhong::ClassId))
				{
					destMat->type = MaterialNode::MaterialType::Phong;
				}

				const FbxDouble3 lEmissive = getMaterialProperty(&material,
					FbxSurfaceMaterial::sEmissive, FbxSurfaceMaterial::sEmissiveFactor, &destMat->emmisive);
				setFbxColor(destMat->emmisive, lEmissive);

				const FbxDouble3 lAmbient = getMaterialProperty(&material,
					FbxSurfaceMaterial::sAmbient, FbxSurfaceMaterial::sAmbientFactor, &destMat->ambient);
				setFbxColor(destMat->ambient, lAmbient);

				const FbxDouble3 lDiffuse = getMaterialProperty(&material,
					FbxSurfaceMaterial::sDiffuse, FbxSurfaceMaterial::sDiffuseFactor, &destMat->diffuse);
				setFbxColor(destMat->diffuse, lDiffuse);

				const FbxDouble3 lSpecular = getMaterialProperty(&material,
					FbxSurfaceMaterial::sSpecular, FbxSurfaceMaterial::sSpecularFactor, &destMat->specular);
				setFbxColor(destMat->specular, lSpecular);

				//
				FbxProperty lTransparencyFactorProperty = material.FindProperty(FbxSurfaceMaterial::sTransparencyFactor);
				if (lTransparencyFactorProperty.IsValid())
				{
					double lTransparencyFactor = lTransparencyFactorProperty.Get<FbxDouble >();
					destMat->TransparencyFactor = static_cast<float>(lTransparencyFactor);
				}

				// Specular Power
				FbxProperty lShininessProperty = material.FindProperty(FbxSurfaceMaterial::sShininess);
				if (lShininessProperty.IsValid())
				{
					double lShininess = lShininessProperty.Get<FbxDouble >();
					destMat->shininess = static_cast<float>(lShininess);
				}
			}

			void computeNodeMatrix(FbxNode* pNode, MeshNode* meshNode)
			{
				if (!pNode || !meshNode)
				{
					return;
				}

				FbxAnimEvaluator* lEvaluator = m_scene->GetAnimationEvaluator();
				FbxMatrix lGlobal;
				lGlobal.SetIdentity();

				if (pNode != m_scene->GetRootNode())
				{
					lGlobal = lEvaluator->GetNodeGlobalTransform(pNode);

					FBXMatrixToFloat16(&lGlobal, meshNode->matrix);
				}
				else
				{
					FBXMatrixToFloat16(&lGlobal, meshNode->matrix);
				}
			}

			void setFbxColor(MaterialElement& destColor, const FbxDouble3 srcColor)
			{
				destColor.a = 1.0f;
				destColor.r = static_cast<float>(srcColor[0]);
				destColor.g = static_cast<float>(srcColor[1]);
				destColor.b = static_cast<float>(srcColor[2]);
			}

			FbxDouble3 getMaterialProperty(
				const FbxSurfaceMaterial * pMaterial,
				const char * pPropertyName,
				const char * pFactorPropertyName,
				MaterialElement* pElement)
			{
				pElement->type = MaterialElement::ElementType::None;

				FbxDouble3 lResult(0, 0, 0);
				const FbxProperty lProperty = pMaterial->FindProperty(pPropertyName);
				const FbxProperty lFactorProperty = pMaterial->FindProperty(pFactorPropertyName);
				if (lProperty.IsValid() && lFactorProperty.IsValid())
				{
					lResult = lProperty.Get< FbxDouble3>();
					double lFactor = lFactorProperty.Get<FbxDouble >();
					if (lFactor != 1)
					{
						lResult[0] *= lFactor;
						lResult[1] *= lFactor;
						lResult[2] *= lFactor;
					}

					pElement->type = MaterialElement::ElementType::Color;
				}

				if (lProperty.IsValid())
				{
					int existTextureCount = 0;
					const int lTextureCount = lProperty.GetSrcObjectCount<FbxFileTexture >();

					for (int i = 0; i < lTextureCount; i++)
					{
						FbxFileTexture* lFileTexture = lProperty.GetSrcObject<FbxFileTexture >(i);
						if (!lFileTexture)
							continue;

						FbxString uvsetName = lFileTexture->UVSet.Get();
						const String uvSetString = Widen(uvsetName.Buffer());
						const FilePath filePath = Widen(lFileTexture->GetFileName());

						pElement->textureSetArray[uvSetString].push_back(filePath);
						existTextureCount++;
					}

					const int lLayeredTextureCount = lProperty.GetSrcObjectCount<FbxLayeredTexture >();

					for (int i = 0; i < lLayeredTextureCount; i++)
					{
						FbxLayeredTexture* lLayeredTexture = lProperty.GetSrcObject<FbxLayeredTexture >(i);

						const int lTextureFileCount = lLayeredTexture->GetSrcObjectCount<FbxFileTexture >();

						for (int j = 0; j < lTextureFileCount; j++)
						{
							FbxFileTexture* lFileTexture = lLayeredTexture->GetSrcObject<FbxFileTexture >(j);
							if (!lFileTexture)
								continue;

							FbxString uvsetName = lFileTexture->UVSet.Get();
							const String uvSetString = Widen(uvsetName.Buffer());
							const FilePath filePath = Widen(lFileTexture->GetFileName());

							pElement->textureSetArray[uvSetString].push_back(filePath);
							existTextureCount++;
						}
					}

					if (existTextureCount > 0)
					{
						if (pElement->type == MaterialElement::ElementType::Color)
							pElement->type = MaterialElement::ElementType::Both;
						else
							pElement->type = MaterialElement::ElementType::Texture;
					}
				}

				return lResult;
			}

			static void FBXMatrixToFloat16(FbxMatrix* src, float dest[16])
			{
				unsigned int nn = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						dest[nn] = static_cast<float>(src->Get(i, j));
						nn++;
					}
				}
			}

		public:

			FBXLoader() = default;

			~FBXLoader()
			{
				release();
			}

			void release()
			{
				m_meshNodes.clear();

				if (m_importer)
				{
					m_importer->Destroy();
					m_importer = nullptr;
				}

				if (m_scene)
				{
					m_scene->Destroy();
					m_scene = nullptr;
				}

				if (m_sdkManager)
				{
					m_sdkManager->Destroy();
					m_sdkManager = nullptr;
				}
			}

			bool loadFBX(const FilePath& path)
			{
				if (path.isEmpty)
				{
					return false;
				}

				if (!initSdkObjects())
				{
					return false;
				}

				int lFileFormat = -1;

				m_importer = FbxImporter::Create(m_sdkManager, "");

				if (!m_sdkManager->GetIOPluginRegistry()->DetectReaderFileFormat(path.narrow().c_str(), lFileFormat))
				{
					lFileFormat = m_sdkManager->GetIOPluginRegistry()->FindReaderIDByDescription("FBX binary (*.fbx)");;
				}

				if (!m_importer || m_importer->Initialize(path.narrow().c_str(), lFileFormat) == false)
				{
					return false;
				}

				if (!m_importer || m_importer->Import(m_scene) == false)
				{
					return false;
				}

				int up, front, coor;
				int x1 = m_scene->GetGlobalSettings().GetAxisSystem().GetUpVector(up);
				int x2 = m_scene->GetGlobalSettings().GetAxisSystem().GetFrontVector(front);
				int x3 = m_scene->GetGlobalSettings().GetAxisSystem().GetCoorSystem();
				Println(x1, L'/', x2, L'/', x3);
				Println(up, L'/', front);
				///*
				if (m_scene->GetGlobalSettings().GetAxisSystem() != FbxAxisSystem::DirectX)
				{
					FbxAxisSystem::DirectX.ConvertScene(m_scene);
				}
				//*/
				x1 = m_scene->GetGlobalSettings().GetAxisSystem().GetUpVector(up);
				x2 = m_scene->GetGlobalSettings().GetAxisSystem().GetFrontVector(front);
				x3 = m_scene->GetGlobalSettings().GetAxisSystem().GetCoorSystem();
				Println(x1, L'/', x2, L'/', x3);
				Println(up, L'/', front);


				/*
				FbxAxisSystem directXAxisSys(FbxAxisSystem::EUpVector::eYAxis,
					FbxAxisSystem::EFrontVector::eParityEven,
					FbxAxisSystem::eRightHanded);
				directXAxisSys.ConvertScene(m_scene);
				//*/

				triangulateRecursive(m_scene->GetRootNode());

				setup();

				return true;
			}

			const FbxNode& getRootNode() const
			{
				return *m_scene->GetRootNode();
			}

			size_t getNodesCount() const
			{
				return m_meshNodes.size();
			};

			const MeshNode& getNode(size_t index) const
			{
				return m_meshNodes[index];
			}
		};

		Model LoadFBX(const FilePath& path)
		{
			FBX::FBXLoader loader;

			if (!loader.loadFBX(path))
			{
				return{};
			}

			size_t nodeCount = loader.getNodesCount();

			Model model;

			for (size_t i = 0; i < nodeCount; ++i)
			{
				const FBX::MeshNode& fbxNode = loader.getNode(static_cast<unsigned int>(i));

				if (fbxNode.indices.empty())
				{
					continue;
				}

				const unsigned vertexSize = fbxNode.positions.size();
				const unsigned texcoordSize = fbxNode.texcoords.size();
				const unsigned indexSize = fbxNode.indices.size();

				assert(vertexSize == fbxNode.normals.size());

				MeshObject meshObject;
				meshObject.vertices.resize(vertexSize);
				meshObject.indices.resize(indexSize);

				const DirectX::XMMATRIX matrix(fbxNode.matrix);

				for (size_t k = 0; k<vertexSize; ++k)
				{
					const auto& fPos = fbxNode.positions[k];
					const auto pos = DirectX::XMVector3Transform(Vec3ToVector({ fPos[0], fPos[1], fPos[2] }, 1.0f), matrix);

					meshObject.vertices[k].position.set({ pos.m128_f32[0], pos.m128_f32[1], pos.m128_f32[2] });
					meshObject.vertices[k].normal.set(fbxNode.normals[k]);
				}

				if (!fbxNode.texcoords.empty())
				{
					for (size_t k = 0; k < vertexSize; ++k)
					{
						meshObject.vertices[k].texcoord.set(fbxNode.texcoords[k]);
					}
				}

				meshObject.indices = fbxNode.indices;

				Material material;

				if (!fbxNode.m_materialNodes.empty())
				{
					const auto& m = fbxNode.m_materialNodes.front();

					material.ambient.set(m.ambient.r, m.ambient.g, m.ambient.b, m.ambient.a);
					material.diffuse.set(m.diffuse.r, m.diffuse.g, m.diffuse.b, m.diffuse.a);
					material.specular.set(m.specular.r, m.specular.g, m.specular.b, m.specular.a);
					material.emission.set(m.emmisive.r, m.emmisive.g, m.emmisive.b, m.emmisive.a);
					material.shininess = m.shininess;
				}

				model.nodes.emplace_back(fbxNode.name, Mesh{ meshObject }, material);
			}

			return model;
		}
	}
}
