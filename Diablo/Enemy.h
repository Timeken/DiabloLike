#pragma once
#include "Stats.h"
#include "EnemyType.h"
#include <cassert>

class EnemyType;

class Enemy
{
public:
	Enemy(EnemyType* const anEnemyType);
	~Enemy() = default;
	Enemy(const Enemy& aRhs) = default;

	Enemy& operator=(const Enemy& aRhs) = default;
	
	void SetStats(Stats);
	void SetHealth(int);

	int GetHealth();
	Stats GetStats();
	std::string GetName();

private:
	int myHealth;
	EnemyType* myEnemyType;
};