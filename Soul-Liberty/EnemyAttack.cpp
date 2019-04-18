#include "EnemyAttack.h"

CEnemyAttack::CEnemyAttack(const int power, const float jumpforce, const float mass, const float speed) :
power(power), mass(mass), 
speed(speed), jumpforce(jumpforce), 
state(State::Appearance),
count(0)
{
}
