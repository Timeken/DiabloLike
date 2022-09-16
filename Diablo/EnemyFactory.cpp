#include "EnemyFactory.h"
#include "Enemy.h"
EnemyFactory::EnemyFactory()
	:
	mySkeleton(5, 4, 4, "Skeleton"),
	myZombie(4, 1, 7, "Zombie"),
	myRat(3, 5, 2, "Rat"){}

std::unique_ptr<Enemy> EnemyFactory::CreateEnemy(const EnemyTypeIndex anEnemyType)
{
	std::unique_ptr<Enemy> enemy
	{
		nullptr
	};

	switch (anEnemyType)
	{
	case EnemyTypeIndex::ENEMY_Skeleton:
	{
		auto enemy = std::make_unique<Enemy>(&mySkeleton);
		return enemy;
		break;
	}
	case EnemyTypeIndex::ENEMY_Zombie:
	{
		auto enemy = std::make_unique<Enemy>(&myZombie);
		return enemy;
		break;
	}
	case EnemyTypeIndex::ENEMY_Rat:
	{
		auto enemy = std::make_unique<Enemy>(&myRat);
		return enemy;
		break;
	}
	default:
	{
		assert(false);
		return enemy;
	}
	}
}