#pragma once
#include "Stats.h"
#include <string>
class EnemyType
{
public: 
	EnemyType(int someStrength = 1, int someAgility = 1, int someVitality = 1, std::string  aName = "");

	void SetStats(Stats);

	Stats GetStats();
	std::string GetName();

private: 
	Stats myStats;
	std::string myName;
};