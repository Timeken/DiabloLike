#include "Enemy.h"
#include "EnemyType.h"
Enemy::Enemy(EnemyType* const anEnemyType)
	:
	myEnemyType(anEnemyType)
{
	myHealth = myEnemyType->GetStats().GetMaxHP();
}

void Enemy::SetStats(Stats someStats)
{
	myEnemyType->SetStats(someStats);
}

void Enemy::SetHealth(int someHealth)
{
	myHealth += someHealth;
}

int Enemy::GetHealth()
{
	return myHealth;
}
Stats Enemy::GetStats()
{
	return myEnemyType->GetStats();
}

std::string Enemy::GetName()
{
	return myEnemyType->GetName();
}
