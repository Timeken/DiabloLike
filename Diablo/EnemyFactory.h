#pragma once
#include <iostream>
#include "Enemy.h"
#include "EnemyType.h"
enum class EnemyTypeIndex
{
	ENEMY_Skeleton = 1, ENEMY_Zombie = 2, ENEMY_Rat = 3
};

class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory() = default;

	EnemyFactory(const EnemyFactory& aRhs) = delete;
	EnemyFactory& operator=(const EnemyFactory& aRhs) = delete;

	std::unique_ptr<Enemy> CreateEnemy(const EnemyTypeIndex anEnemyType);
private:
	EnemyType mySkeleton;
	EnemyType myZombie;
	EnemyType myRat;
};