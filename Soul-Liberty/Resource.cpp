#include "Resource.h"

const String Path = L"engine\\data\\";


CResource::CResource():
se_volume(0.5),
bgm(new CBGMData())
{
	TitleGraphic();
	Graphic();
	PlayerGraphic();
	Model();
	Music();
	Monster();
	MonsterUI();
	Enemy();
	Boss();
	Description();

	RendererProperty prop = RendererProperty::Forward();
	RendererProperty prop2 = RendererProperty::Forward();
	prop.forwardBlend = BlendState::Default();
	prop.depthWriteEnable = false;
	prop2.forwardBlend = BlendState::Additive();
	prop2.rasterizer = Rasterizer::NoCull_Solid;
	add = new Renderer(prop2);
	alpha = new Renderer(prop);
}


CBGMData::CBGMData() :
max_volume(0.2),
volume(0.2),
state(State::Stop),
play(SoundAsset(L"engine/data/BGM/Title.mp3"))
{
	bgm.insert(std::make_pair(BGM::Boneyard, L"Boneyard"));
	bgm.insert(std::make_pair(BGM::Castle, L"Castle"));
	bgm.insert(std::make_pair(BGM::Title, L"Title"));
	bgm.insert(std::make_pair(BGM::Boss, L"Boss"));
	bgm.insert(std::make_pair(BGM::Ending, L"Ending"));
	bgm.insert(std::make_pair(BGM::Prologue, L"Prologue"));
	for (auto& it : bgm)
	{
		const String Folder = L"BGM\\";
		const FilePath FileName = Path + Folder + it.second + L".mp3";
		SoundAsset::Register(it.second, FileName, true);
	}
}

void CBGMData::Update()
{
	play.setVolume(volume);

	if (state != State::Fade) return;
	volume -= 0.006;
	if (volume <= 0)
	{
		volume = max_volume;
		play.stop();
		state = State::Stop;
	}
}


void CBGMData::Play(const BGM type)
{
	if (state != State::Stop) return;
	play = SoundAsset(bgm.find(type)->second);
	play.play();
	play.setVolume(volume);
	state = State::Play;
}

void CBGMData::Stop()
{
	play.stop();
	state = State::Stop;
}


void CBGMData::FadeStart()
{
	state = State::Fade;
}



template<typename T>
void CResource::MapToRead(std::map<T, String> graphic)
{
	for (auto& graph : graphic)
	{
		const String Folder = L"Graph\\";
		const FilePath FileName = Path + Folder + graph.second;
		TextureAsset::Register(graph.second, FileName);
	}
}

void CResource::VectorToRead(std::vector<String> graphic)
{
	for (auto& graph : graphic)
	{
		const String Folder = L"Graph\\";
		const FilePath FileName = Path + Folder + graph;
		TextureAsset::Register(graph, FileName);
	}
}

void CResource::GaussCreateTexture(std::vector<Texture*>& texture, std::vector<FilePath> filepath)
{
	Image imageGauss;

	for (auto& it : filepath)
	{
		Image image(L"engine/data/Graph/" + it);
		imageGauss = Imaging::Gaussian(image, 20, 20);
		texture.push_back(new Texture(imageGauss));
	}

}
void CResource::Graphic()
{
	graphic.insert(std::make_pair(GraphicType::BackGroundBoneyard, L"background_boneyard.jpg"));
	graphic.insert(std::make_pair(GraphicType::BackGroundCastle, L"background_castle.jpg"));
	graphic.insert(std::make_pair(GraphicType::Castle, L"castle.png"));
	graphic.insert(std::make_pair(GraphicType::Castle2, L"castle2.png"));
	
	graphic.insert(std::make_pair(GraphicType::Soul, L"Soul.png"));
	graphic.insert(std::make_pair(GraphicType::Smoke, L"kemuri1.png"));
	graphic.insert(std::make_pair(GraphicType::Smoke2, L"kemuri2.png"));
	
	graphic.insert(std::make_pair(GraphicType::Particle, L"Particle.png"));
	graphic.insert(std::make_pair(GraphicType::ParticleGauss, L"ParticleGauss.png"));
	graphic.insert(std::make_pair(GraphicType::King, L"Mob/King.png"));
	graphic.insert(std::make_pair(GraphicType::NameInput, L"NameInput.png"));

	graphic.insert(std::make_pair(GraphicType::EndrollMonster, L"Monster.png"));
	graphic.insert(std::make_pair(GraphicType::EndrollMonster2, L"Monster2.png"));

	graphic.insert(std::make_pair(GraphicType::CombineSoul, L"combine_soul.png"));

	effect.insert(std::make_pair(EffectType::Fire, L"Effect/Fire.png"));
	effect.insert(std::make_pair(EffectType::Darkness, L"Effect/Darkness.png"));

	prologue.insert(std::make_pair(PrologueGraphicType::Devil, L"OP/op1.png"));
	prologue.insert(std::make_pair(PrologueGraphicType::Devil_Magic, L"OP/op2.png"));
	prologue.insert(std::make_pair(PrologueGraphicType::MobPeople, L"OP/Mob.png"));
	prologue.insert(std::make_pair(PrologueGraphicType::EnemyMobPeople, L"OP/EnemyMob.png"));

	ui.insert(std::make_pair(UIType::Face, L"UI/face.png"));
	ui.insert(std::make_pair(UIType::HP, L"UI/HP.png"));
	ui.insert(std::make_pair(UIType::HPBack, L"UI/HPBack.png"));
	ui.insert(std::make_pair(UIType::Monster, L"UI/monsterframe.png"));

	ui.insert(std::make_pair(UIType::Monster_RightCircleBack, L"Circle/RightCircle.png"));
	ui.insert(std::make_pair(UIType::Monster_LeftCircleBack, L"Circle/LeftCircle.png"));
	ui.insert(std::make_pair(UIType::Monster_LeftCircle, L"Circle/LeftCircle2.png"));
	ui.insert(std::make_pair(UIType::Monster_RightCircle, L"Circle/RightCircle2.png"));
	ui.insert(std::make_pair(UIType::Monster_MaxCircle, L"Circle/MaxCircle.png"));

	smoke.push_back(L"Smoke/1.png");
	smoke.push_back(L"Smoke/2.png");
	smoke.push_back(L"Smoke/3.png");

	tree.push_back(L"Tree/1.png");
	tree.push_back(L"Tree/2.png");
	tree.push_back(L"Tree/3.png");
	tree.push_back(L"Tree/4.png");

	mob.push_back(L"Mob/1.png");
	mob.push_back(L"Mob/2.png");
	mob.push_back(L"Mob/3.png");
	mob.push_back(L"Mob/4.png");
	mob.push_back(L"Mob/5.png");
	mob.push_back(L"Mob/6.png");

	MapToRead(ui);
	MapToRead(prologue);
	MapToRead(graphic);
	MapToRead(effect);
	VectorToRead(mob);
	VectorToRead(smoke);
	VectorToRead(tree);

}

void CResource::Description()
{
	description.insert(std::make_pair(DescriptionType::Move, L"Description/move.png"));
	description.insert(std::make_pair(DescriptionType::Summons, L"Description/summons.png"));
	description.insert(std::make_pair(DescriptionType::Combine, L"Description/combine.png"));
	description.insert(std::make_pair(DescriptionType::Attack, L"Description/attack.png"));
	description.insert(std::make_pair(DescriptionType::Avoid, L"Description/avoid.png"));
	description.insert(std::make_pair(DescriptionType::Jump, L"Description/jump.png"));
	description.insert(std::make_pair(DescriptionType::Jump2, L"Description/jump2.png"));

	MapToRead(description);

}

void CResource::ReadSummons(const String &file,const MonsterUIType &type)
{
	std::vector<FilePath> graph;

	for (int i = 0; i < 6; i++)
	{
		graph.push_back(L"Player/Summons/" + file + std::to_wstring(i + 1) + L".png");
	}

	summons.insert(std::make_pair(type, graph));

	for (auto& it : summons)
	{
		for (auto& graph : it.second)
		{
			const String Folder = L"Graph\\";
			const FilePath FileName = Path + Folder + graph;
			TextureAsset::Register(graph, FileName);
		}
	}

}

void CResource::PlayerGraphic()
{
	player.push_back(L"Player/Standing/1.png");
	player.push_back(L"Player/Walk/1.png");
	player.push_back(L"Player/Walk/2.png");
	player.push_back(L"Player/Walk/3.png");
	player.push_back(L"Player/Walk/4.png");

	player.push_back(L"Player/Jump/1.png");
	player.push_back(L"Player/Jump/2.png");

	player.push_back(L"Player/Attack/1.png");
	player.push_back(L"Player/Attack/2.png");
	player.push_back(L"Player/Attack/2.5.png");
	player.push_back(L"Player/Attack/3.png");
	player.push_back(L"Player/Attack/3.5.png");
	player.push_back(L"Player/Attack/4.png");
	player.push_back(L"Player/Attack/4.5.png");
	player.push_back(L"Player/Attack/5.png");
	player.push_back(L"Player/Attack/6.png");
	player.push_back(L"Player/Attack/6.5.png");

	player.push_back(L"Player/Damage/1.png");
	player.push_back(L"Player/Summons/1.png");
	player.push_back(L"Player/Avoidance/1.png");

	ReadSummons(L"FireKnight/", MonsterUIType::FireKnight);
	ReadSummons(L"WaterShark/", MonsterUIType::WaterShark);
	ReadSummons(L"Golem/", MonsterUIType::Golem);
	ReadSummons(L"Spirit/", MonsterUIType::Spirit);
	ReadSummons(L"Vampire/", MonsterUIType::Vampire);

	VectorToRead(player);
	GaussCreateTexture(player_back, player);
}

void CResource::Monster()
{
	fire_knight.push_back(L"FireKnight/FireKnightStop.png");
	fire_knight.push_back(L"FireKnight/FireKnightMove.png");
	fire_knight.push_back(L"FireKnight/FireKnightAttack1.png");
	fire_knight.push_back(L"FireKnight/FireKnightAttack2.png");

	water_shark.push_back(L"WaterShark/WaterSharkStop.png");
	water_shark.push_back(L"WaterShark/WaterSharkMove1.png");
	water_shark.push_back(L"WaterShark/WaterSharkMove2.png");
	water_shark.push_back(L"WaterShark/WaterSharkMove3.png");
	water_shark.push_back(L"WaterShark/WaterSharkAttack.png");

	golem.push_back(L"Golem/GolemStop.png");
	golem.push_back(L"Golem/GolemMove.png");
	golem.push_back(L"Golem/GolemAttack1.png");
	golem.push_back(L"Golem/GolemAttack2.png");

	spirit.push_back(L"Spirit/Spirit.png");
	spirit.push_back(L"Spirit/SpiritAttack1.png");
	spirit.push_back(L"Spirit/SpiritAttack2.png");

	vampire.push_back(L"Vampire/Stop.png");
	vampire.push_back(L"Vampire/Attack1.png");
	vampire.push_back(L"Vampire/Attack2.png");

	VectorToRead(fire_knight);
	VectorToRead(water_shark);
	VectorToRead(golem);
	VectorToRead(spirit);
	VectorToRead(vampire);

	GaussCreateTexture(fire_knight_back, fire_knight);
	GaussCreateTexture(water_shark_back, water_shark);
	GaussCreateTexture(golem_back, golem);
	GaussCreateTexture(spirit_back, spirit);
	GaussCreateTexture(vampire_back, vampire);
}

void CResource::MonsterUI()
{
	monster_ui.insert(std::make_pair(MonsterUIType::FireKnight, L"FireKnight/FireKnightStop.png"));
	monster_ui.insert(std::make_pair(MonsterUIType::WaterShark, L"WaterShark/WaterSharkStop.png"));
	monster_ui.insert(std::make_pair(MonsterUIType::Golem, L"Golem/GolemStop.png"));
	monster_ui.insert(std::make_pair(MonsterUIType::Spirit, L"Spirit/Spirit.png"));
	monster_ui.insert(std::make_pair(MonsterUIType::Vampire, L"Vampire/Stop.png"));

	monster_absorption_ui.insert(std::make_pair(MonsterUIType::FireKnight, L"FireKnight/Absorption.png"));
	monster_absorption_ui.insert(std::make_pair(MonsterUIType::WaterShark, L"WaterShark/Absorption.png"));
	monster_absorption_ui.insert(std::make_pair(MonsterUIType::Golem, L"Golem/Absorption.png"));
	monster_absorption_ui.insert(std::make_pair(MonsterUIType::Spirit, L"Spirit/Absorption.png"));
	monster_absorption_ui.insert(std::make_pair(MonsterUIType::Vampire, L"Vampire/Absorption.png"));

	MapToRead(monster_ui);
	MapToRead(monster_absorption_ui);
	
}

void CResource::Enemy()
{
	slime.insert(std::make_pair(SlimeType::Red, L"Enemy/Red.png"));
	slime.insert(std::make_pair(SlimeType::Blue, L"Enemy/Blue.png"));
	slime.insert(std::make_pair(SlimeType::Black, L"Enemy/Black.png"));

	magic_enemy.push_back(L"Enemy/MagicStop.png");
	magic_enemy.push_back(L"Enemy/MagicAttack.png");

	weapon_enemy.push_back(L"Enemy/WeaponWalk1.png");
	weapon_enemy.push_back(L"Enemy/WeaponWalk2.png");
	weapon_enemy.push_back(L"Enemy/WeaponAttack1.png");
	weapon_enemy.push_back(L"Enemy/WeaponAttack2.png");

	MapToRead(slime);
	VectorToRead(magic_enemy);
	VectorToRead(weapon_enemy);
}

void CResource::Boss()
{
	devil.push_back(L"Boss/Stop1.png");
	devil.push_back(L"Boss/Stop2.png");
	devil.push_back(L"Boss/Attack.png");

	dragon.push_back(L"Boss/DragonStop1.png");
	dragon.push_back(L"Boss/DragonStop2.png");
	dragon.push_back(L"Boss/DragonStop3.png");
	dragon.push_back(L"Boss/DragonMove.png");
	dragon.push_back(L"Boss/DragonAttack.png");
	dragon.push_back(L"Boss/DragonDamage.png");

	VectorToRead(devil);
	VectorToRead(dragon);

}

void CResource::TitleGraphic()
{
	title_graphic.insert(std::make_pair(TitleGraphicType::BackGround, L"Title\\BackGround.png"));
	title_graphic.insert(std::make_pair(TitleGraphicType::TitleLogo, L"Title\\TitleLogo.png"));
	title_graphic.insert(std::make_pair(TitleGraphicType::HelpLogo, L"Title\\option.png"));
	title_graphic.insert(std::make_pair(TitleGraphicType::StartLogo, L"Title\\start.png"));

	MapToRead(title_graphic);

}

void CResource::Model()
{
	floor.insert(std::make_pair(FloorType::BoneyardFloor, std::make_unique<CModel>(L"engine\\data\\Model\\Floor.obj", L"engine\\data\\Model\\Floor.jpg")));
	floor.insert(std::make_pair(FloorType::CastleFloor, std::make_unique<CModel>(L"engine\\data\\Model\\Floor.obj", L"engine\\data\\Model\\CastleFloor.jpg")));
	
	model.insert(std::make_pair(ModelType::Fence,
		std::make_unique<CModel>(L"engine\\data\\Model\\Fence\\fance.obj", L"engine\\data\\Model\\Fence\\fance1.jpg")));
	model.insert(std::make_pair(ModelType::Fence2,
		std::make_unique<CModel>(L"engine\\data\\Model\\Fence\\fance.obj", L"engine\\data\\Model\\Fence\\fance2.jpg")));

	model.insert(std::make_pair(ModelType::DoorL, 
		std::make_unique<CModel>(L"engine\\data\\Model\\Door\\door_L.obj", L"engine\\data\\Model\\Door\\door.jpg")));
	model.insert(std::make_pair(ModelType::DoorR,
		std::make_unique<CModel>(L"engine\\data\\Model\\Door\\door_R.obj", L"engine\\data\\Model\\Door\\door.jpg")));
	model.insert(std::make_pair(ModelType::DoorVicinity,
		std::make_unique<CModel>(L"engine\\data\\Model\\Door\\gate.obj", L"engine\\data\\Model\\Door\\gate.jpg")));
	
	model.insert(std::make_pair(ModelType::Tombstone, 
		std::make_unique<CModel>(L"engine\\data\\Model\\Tombstone\\boseki.obj", L"engine\\data\\Model\\Tombstone\\boseki.jpg")));
	model.insert(std::make_pair(ModelType::Tombstone2, 
		std::make_unique<CModel>(L"engine\\data\\Model\\Tombstone\\boseki2.obj", L"engine\\data\\Model\\Tombstone\\boseki2.jpg")));

}



void CResource::Music()
{
	se.insert(std::make_pair(SE::SlimeMove, L"slime_move"));
	se.insert(std::make_pair(SE::FirstJump, L"first_jump"));
	se.insert(std::make_pair(SE::SecondJump, L"second_jump"));
	se.insert(std::make_pair(SE::GaugeCharge, L"gauge_charge"));
	se.insert(std::make_pair(SE::EnemyDeath, L"enemy_crush"));
	se.insert(std::make_pair(SE::Hit, L"enemy_hit"));
	se.insert(std::make_pair(SE::FireKnightAttack, L"knight_attack"));
	se.insert(std::make_pair(SE::GolemAttack, L"golem_attack"));
	se.insert(std::make_pair(SE::WatarSharkAttack, L"water_attack"));
	se.insert(std::make_pair(SE::SpiritAttack, L"light_attack"));
	se.insert(std::make_pair(SE::Summons, L"summon"));
	se.insert(std::make_pair(SE::SummonsNone, L"summon_none"));
	se.insert(std::make_pair(SE::PlayerSpecialAttack, L"player_attack"));
	se.insert(std::make_pair(SE::PlayerAvoid, L"avoid"));
	se.insert(std::make_pair(SE::PlayerDamage, L"damage"));
	se.insert(std::make_pair(SE::BoneyardFoot, L"boneyard_foot"));
	se.insert(std::make_pair(SE::CastleFoot, L"castle_foot"));
	se.insert(std::make_pair(SE::ChangeScene, L"change_scene"));
	se.insert(std::make_pair(SE::DarkMagic, L"dark"));
	se.insert(std::make_pair(SE::Conbine, L"change_scene"));
	se.insert(std::make_pair(SE::FireBreath, L"fire_breath"));
	se.insert(std::make_pair(SE::Decision, L"decision"));
	se.insert(std::make_pair(SE::EnemyMagicAttack, L"magician_attack"));
	se.insert(std::make_pair(SE::DragonFly, L"dragon_flap"));

	for (auto& it : se)
	{
		const String Folder = L"SE\\";
		const FilePath FileName = Path + Folder + it.second + L".mp3";
		SoundAsset::Register(it.second, FileName,false);
	}
}