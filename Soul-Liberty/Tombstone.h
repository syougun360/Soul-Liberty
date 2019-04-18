
/**
*
*	@author	yamada masamitsu
*	@date	2014.10.01
*
*/
#pragma once
#include "Actor.h"
#include "Resource.h"

class CTombstone :public CActor
{
public:
	enum class ScaleType
	{
		Normal = 1,
		Huge = 2,
	};
	CTombstone(std::shared_ptr<CTask> task, Float3 pos, ScaleType scale_type);

	void Draw();
	

private:
	CResource::ModelType model;
};

