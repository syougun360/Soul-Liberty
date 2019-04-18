/**
*
*	@author	yamada masamitsu
*	@date	2014.10.14
*
*/
#pragma once
#include <memory>
class CPlayerAttack;
class CPlayer;

class CPlayerSpecialAttack
{
public:
	CPlayerSpecialAttack();

	void Start(std::shared_ptr<CPlayer> player);
	void Create();
	void Update(CPlayerAttack *attack);

	enum class State
	{
		None,
		Live,
	};

	State GetState()const{ return state; }
private:
	std::shared_ptr<CPlayer> player;
	State state;
	int special_count;	///<	“ÁŽêUŒ‚‚ÌƒJƒEƒ“ƒg
};

