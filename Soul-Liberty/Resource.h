
/**
*
*	@author	yamada masamitsu
*	@date	2014.09.26
*
*/
#pragma once

#include <siv3D.hpp>
#include <memory>
#include "Model.h"
#include <map>
#include <array>

class CBGMData
{
public:

	enum class BGM
	{
		Boneyard,
		Castle,
		Title,
		Boss,
		Ending,
		Prologue,

	};

	enum class State
	{
		Play,
		Fade,
		Stop,
	};

	CBGMData();
	CBGMData& operator=(const CBGMData& obj)
	{
		this->play = obj.play;
		return *this;
	};

	void Update();

	void Play(const BGM type);

	void FadeStart();

	void Stop();

private:
	const double max_volume;
	double volume;

	State state;
	std::map<BGM, FilePath> bgm;
	SoundAsset play;

};
///	リソース管理
class CResource
{
public:
	CResource();

	static CResource &GetInstance()
	{
		static CResource instance;
		return instance;
	}

	//　グラフィックの種類
	enum class GraphicType
	{
		BackGroundBoneyard,	//	背景
		BackGroundCastle,	//	背景
		Castle,
		Castle2,
		Particle,
		ParticleGauss,
		Soul,
		King,
		Smoke,
		Smoke2,
		NameInput,
		EndrollMonster,
		EndrollMonster2,
		CombineSoul,
	};

	enum class DescriptionType
	{
		Move,
		Attack,
		Jump,
		Jump2,
		Avoid,
		Summons,
		Combine,
	};

	enum class SlimeType
	{
		Red,
		Blue,
		Black,
	};

	enum class UIType
	{
		Face,
		HP,
		HPBack,
		Monster,
		Monster_LeftCircleBack,
		Monster_RightCircleBack,
		Monster_LeftCircle,
		Monster_RightCircle,
		Monster_MaxCircle,
	};

	enum class EffectType
	{
		Fire,
		Darkness,
	};
	enum class MonsterUIType
	{
		FireKnight,
		WaterShark,
		Golem,
		Spirit,
		Vampire,
	};

	enum class TitleGraphicType
	{
		BackGround,
		TitleLogo,
		StartLogo,
		HelpLogo,
	};

	enum class PrologueGraphicType
	{
		Devil,
		Devil_Magic,
		MobPeople,
		EnemyMobPeople,
	};

	enum class SE
	{
		SlimeMove,
		FirstJump,
		SecondJump,
		GaugeCharge,
		EnemyDeath,
		EnemyMagicAttack,
		Hit,
		FireKnightAttack,
		GolemAttack,
		WatarSharkAttack,
		SpiritAttack,
		Summons,
		SummonsNone,
		BoneyardFoot,
		CastleFoot,
		Decision,
		PlayerAvoid,
		PlayerDamage,
		PlayerSpecialAttack,
		ChangeScene,
		Conbine,
		FireBreath,
		DarkMagic,
		DragonFly,
	};
	enum class ModelType
	{
		Fence,
		Fence2,
		DoorL,
		DoorR,
		DoorVicinity,
		Tombstone,
		Tombstone2,
	};

	enum class FloorType
	{
		BoneyardFloor,
		CastleFloor,
	};

	void PlaySE(const SE type)const
	{
		auto play = SoundAsset(se.find(type)->second);
		play.playMulti(se_volume);
	}

	void PlayBGM(const CBGMData::BGM type)const
	{
		bgm->Play(type);
	}

	void FadeStartBGM()const
	{
		bgm->FadeStart();
	}
	void StopBGM()const
	{
		bgm->Stop();
	}

	void BGMUpdate()const
	{
		bgm->Update();
	}

	FilePath GetGraphic(const GraphicType type)const
	{
		auto it = graphic.find(type);
		return it->second;
	}

	FilePath GetDescription(const DescriptionType type)const
	{
		auto it = description.find(type);
		return it->second;
	}

	FilePath GetSlime(const SlimeType type)const
	{
		auto it = slime.find(type);
		return it->second;
	}
	FilePath GetMonsterAbsorptionUI(const MonsterUIType type)const
	{
		auto it = monster_absorption_ui.find(type);
		return it->second;
	}

	FilePath GetMonsterUI(const MonsterUIType type)const
	{
		auto it = monster_ui.find(type);
		return it->second;
	}

	FilePath GetTitleGraphic(const TitleGraphicType type)const
	{
		auto it = title_graphic.find(type);
		return it->second;
	}
	FilePath GetEffect(const EffectType type)const
	{
		auto it = effect.find(type);
		return it->second;
	}

	FilePath GetPrologue(const PrologueGraphicType type)const
	{
		auto it = prologue.find(type);
		return it->second;
	}

	FilePath GetUI(const UIType type)const
	{
		auto it = ui.find(type);
		return it->second;
	}

	FilePath GetPlayer(const int id)const
	{
		return player[id];
	}
	FilePath GetFireKnight(const int id)const
	{
		return fire_knight[id];
	}
	FilePath GetWaterShark(const int id)const
	{
		return water_shark[id];
	}
	FilePath GetGolem(const int id)const
	{
		return golem[id];
	}

	FilePath GetVampire(const int id)const
	{
		return vampire[id];
	}

	FilePath GetSpirit(const int id)const
	{
		return spirit[id];
	}

	FilePath GetBossDevil(const int id)const
	{
		return devil[id];
	}
	FilePath GetBossDragon(const int id)const
	{
		return dragon[id];
	}

	Texture* GetFireKnightBackTexture(const int id)const
	{
		return fire_knight_back[id];
	}
	Texture* GetWaterSharkBackTexture(const int id)const
	{
		return water_shark_back[id];
	}
	Texture* GetGolemBackTexture(const int id)const
	{
		return golem_back[id];
	}

	Texture* GetVampireBackTexture(const int id)const
	{
		return vampire_back[id];
	}

	Texture* GetSpiritBackTexture(const int id)const
	{
		return spirit_back[id];
	}

	Texture* GetPlayerBackTexture(const int id)const
	{
		return player_back[id];
	}


	FilePath GetSmoke(const int id)const
	{
		return smoke[id];
	}

	FilePath GetMagicEnemy(const int id)const
	{
		return magic_enemy[id];
	}

	FilePath GetWeaponEnemy(const int id)const
	{
		return weapon_enemy[id];
	}

	FilePath GetSummonsEffect(const MonsterUIType type, const int id)const
	{
		auto it = summons.find(type);
		auto graph = it->second[id];
		return graph;
	}

	FilePath GetTree(const int id)const
	{
		return tree[id];
	}

	FilePath GetMob(const int id)const
	{
		return mob[id];
	}

	std::unique_ptr<CModel> &GetModel(const ModelType type)
	{
		auto it = model.find(type);
		return it->second;
	}
	std::unique_ptr<CModel> &GetFloor(const FloorType type)
	{
		auto it = floor.find(type);
		return it->second;
	}
	
	Renderer* GetAddRenderer()const{ return add; }
	Renderer* GetAlphaRenderer()const{ return alpha; }
private:

	void PlayerGraphic();
	void Graphic();
	void TitleGraphic();
	void Model();
	void Music();
	void Monster();
	void MonsterUI();
	void Enemy();
	void Boss();
	void Description();

	void GaussCreateTexture(std::vector<Texture*>& texture, std::vector<FilePath> filepath);
	void ReadSummons(const String &file,const MonsterUIType &type);

	template<typename T>
	void MapToRead(std::map<T, FilePath> graphic);

	void VectorToRead(std::vector<FilePath> graphic);

	std::vector<FilePath> player;
	std::vector<FilePath> fire_knight;
	std::vector<FilePath> water_shark;
	std::vector<FilePath> golem;
	std::vector<FilePath> spirit;
	std::vector<FilePath> vampire;
	std::vector<FilePath> smoke;
	std::vector<FilePath> magic_enemy;
	std::vector<FilePath> weapon_enemy;
	std::vector<FilePath> tree;
	std::vector<FilePath> devil;
	std::vector<FilePath> dragon;
	std::vector<FilePath> mob;

	std::map<MonsterUIType, std::vector<FilePath>> summons;

	std::map<UIType, FilePath> ui;
	std::map<SlimeType, FilePath> slime;
	std::map<EffectType, FilePath> effect;
	std::map<GraphicType, FilePath> graphic;
	std::map<TitleGraphicType, FilePath> title_graphic;
	std::map<MonsterUIType, FilePath> monster_ui;
	std::map<MonsterUIType, FilePath> monster_absorption_ui;
	std::map<PrologueGraphicType, FilePath> prologue;
	std::map<DescriptionType, FilePath> description;

	std::vector<Texture*> fire_knight_back;
	std::vector<Texture*> water_shark_back;
	std::vector<Texture*> golem_back;
	std::vector<Texture*> spirit_back;
	std::vector<Texture*> vampire_back;
	std::vector<Texture*> player_back;

	std::map<SE, FilePath> se;
	Renderer *add;
	Renderer *alpha;
	std::map<ModelType, std::unique_ptr<CModel>> model;
	std::map<FloorType, std::unique_ptr<CModel>> floor;
	CBGMData *bgm;
	double se_volume;
};

