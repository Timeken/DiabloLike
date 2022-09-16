#include "ItemType.h"

ItemType::ItemType(int someStrength, int someAgility, int someVitality, int someDamage, int someMaxHP, int someCarryingCapacity, int someDefence, int someWight, ItemSlot someSlot, std::string aName)
	:
	myStrength(someStrength), 
	myAgility(someAgility),
	myVitality(someVitality), 
	myDamage(someDamage), 
	myMaxHP(someMaxHP), 
	myCarryingCapacity(someCarryingCapacity),
	myDefence(someDefence),
	myWight(someWight),
	mySlot(someSlot),
	myName(aName){}


int ItemType::GetStrength()
{
	return myStrength;
}

int ItemType::GetAgility()
{
	return myAgility;
}

int ItemType::GetVitality()
{
	return myVitality;
}

int ItemType::GetDamage()
{
	return myDamage;
}

int ItemType::GetMaxHP()
{
	return myMaxHP;
}

int ItemType::GetCarryingCapacity()
{
	return myCarryingCapacity;
}

int ItemType::GetDefence()
{
	return myDefence;
}

int ItemType::GetWight()
{
	return myWight;
}

ItemSlot ItemType::GetSlot()
{
	return mySlot;
}

std::string ItemType::GetName()
{
	return myName;
}