// ------------------------------------------
//		ƒ‚ƒfƒ‹ˆ—
//				code by yamada masamitsu
// -------------------------------------------
#include "Model.h"
#include "Resource.h"

CModel::CModel(const String modelfile, const String texfile)
{
	model = new Model(modelfile);
	texture = new Texture(texfile, Texture::Mipped);
}

void CModel::Draw(const Float3 pos, const Float3 size, const Float3 rota, Mode mode, double alpha)
{
	for (auto& node : model->nodes)
	{
		if (mode == Mode::TextureAlpha)
			node.mesh.scale(size).rotate(rota).translate(pos).draw(*texture,ColorF(1, 1, 1, alpha), *CResource::GetInstance().GetAlphaRenderer());

		else if (mode == Mode::TextureNormal)
			node.mesh.scale(size).rotate(rota).translate(pos).draw(*texture,ColorF(1,1,1,alpha));

		else if (mode == Mode::Material)
			node.mesh.scale(size).rotate(rota).translate(pos).draw(node.material.diffuse.col);
	}
}