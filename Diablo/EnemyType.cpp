#include "EnemyType.h"

EnemyType::EnemyType(int someStrength, int someAgility, int someVitality, std::string aName)
{
	myStats = Stats(someStrength, someAgility, someVitality);
	myName = aName;
}

void EnemyType::SetStats(Stats someStats)
{
	myStats = someStats;
}

Stats EnemyType::GetStats()
{
	return myStats;
}

std::string EnemyType::GetName()
{
	return myName;
}
