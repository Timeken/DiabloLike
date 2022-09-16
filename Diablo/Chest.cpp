#include "Chest.h"

Chest::Chest(Item *anItem, bool aLocked)
{
	SetLocked(aLocked);
	SetItem(anItem);
}

void Chest::SetLocked(bool aLocked)
{
	myLocked = aLocked;
}

void Chest::SetItem(Item *anItem)
{
	myItem = anItem;
}

bool Chest::GetLocked()
{
	return myLocked;
}

Item* Chest::GetItem()
{
	return myItem;
}
