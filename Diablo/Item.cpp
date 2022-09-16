#include "Item.h"

Item::Item(ItemType* const anItemType)
	:
	myItemType(anItemType){}

void Item::SetEquipped(bool aEquipped)
{
	myEquipped = aEquipped;
}

void Item::SetEquippedOffHand(bool aEquipped)
{
	myEquippedOffHand = aEquipped;
}

int Item::GetStrength()
{
	return myItemType->GetStrength();
}

int Item::GetAgility()
{
	return myItemType->GetAgility();
}

int Item::GetVitality()
{
	return myItemType->GetVitality();
}

int Item::GetDamage()
{
	return myItemType->GetDamage();
}

int Item::GetMaxHP()
{
	return myItemType->GetMaxHP();
}

int Item::GetCarryingCapacity()
{
	return myItemType->GetCarryingCapacity();
}

int Item::GetDefence()
{
	return myItemType->GetDefence();
}

int Item::GetWight()
{
	return myItemType->GetWight();
}

ItemSlot Item::GetSlot()
{
	return myItemType->GetSlot();
}

bool Item::GetEquipped()
{
	return myEquipped;
}

bool Item::GetEquippedOffHand()
{
	return myEquippedOffHand;
}

std::string Item::GetName()
{
	return myItemType->GetName();
}





