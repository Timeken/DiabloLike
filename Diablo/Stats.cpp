#include "Stats.h"

const int vitallityHPMod = 4, strengthHPMod = 6, agilityHPMod = 3, agilityCarryMod = 3;

Stats::Stats(int someStrength, int someAgility, int someVitality) 
{
	SetStrength(someStrength);
	SetAgility(someAgility);
	SetVitality(someVitality); 
	SetCurrentHP(0);
}

void Stats::SetStrength(int someStrength)
{
	int diff = 0;
	if (someStrength < 0)
	{
		diff = someStrength;
	}

	myStrength += someStrength;
	SetDamage(myAgility * diff);
	SetMaxHP(strengthHPMod * diff);
	SetCarryingCapacity(diff);
	SetDefence(diff);
}
void Stats::SetAgility(int someAgility)
{
	int diff = 0;
	if (someAgility < 0)
	{
		diff = someAgility;
	}

	myAgility += someAgility;
	SetDamage(myStrength * diff);
	SetMaxHP(agilityHPMod * diff);
	SetCarryingCapacity(diff / agilityCarryMod);
	SetDefence(diff);
}
void Stats::SetVitality(int someVitality)
{
	int diff = 0;
	if (someVitality < 0)
	{
		diff = someVitality;
	}

	myVitality += someVitality;
	SetMaxHP(vitallityHPMod * diff);
}
void Stats::SetDamage(int aChange)
{
	int diff = myDamage - (myStrength * myAgility);
	if (diff < 0)
	{
		diff = 0;
	}
	myDamage = (myStrength * myAgility) + aChange + diff;
}
void Stats::SetDamageMod(int aChange)
{
	myDamage += aChange;
}
void Stats::SetMaxHP(int aChange)
{
	int diff = myMaxHP - (myVitality * vitallityHPMod + myStrength * strengthHPMod + myAgility * agilityHPMod);
	if (diff < 0)
	{
		diff = 0;
	}
	myMaxHP = (myVitality * vitallityHPMod + myStrength * strengthHPMod + myAgility * agilityHPMod) + aChange + diff;
}
void Stats::SetMaxHPMod(int aChange)
{
	myMaxHP += aChange;
}
void Stats::SetCurrentHP(int aChange)
{
	//set current HP if it has not been set
	if (myCurrentHP <= 0 && aChange == 0 || myCurrentHP > 10000 && aChange == 0)
	{
		myCurrentHP = myMaxHP;
	}
	else
	{
		myCurrentHP += aChange;
	}
}
void Stats::SetCarryingCapacity(int aChange)
{
	int diff = myCarryingCapacity - (myStrength + myAgility / agilityCarryMod);
	if (diff < 0)
	{
		diff = 0;
	}
	myCarryingCapacity = (myStrength + myAgility / agilityCarryMod) + aChange + diff;
}
void Stats::SetCarryingCapacityMod(int aChange)
{
	myCarryingCapacity += aChange;
}
void Stats::SetDefence(int aChange)
{
	int diff = myDefence - (myStrength + myAgility);
	if (diff < 0)
	{
		diff = 0;
	}
	myDefence = (myStrength + myAgility) + aChange + diff;
}
void Stats::SetDefenceMod(int aChange)
{
	myDefence += aChange;
}
int Stats::GetStrength() 
{
	return myStrength;
}
int Stats::GetAgility()
{
	return myAgility;
}
int Stats::GetVitality()
{
	return myVitality;
}
int Stats::GetDamage()
{
	return myDamage;
}
int Stats::GetMaxHP()
{
	return myMaxHP;
}
int Stats::GetCurrentHP()
{
	return myCurrentHP;
}
int Stats::GetCarryingCapacity()
{
	return myCarryingCapacity;
}
int Stats::GetDefence()
{
	return myDefence;
}