#pragma once
#include "Item.h"
class Chest
{
public: 
	Chest(Item *anItem = NULL, bool someLocked = true);
	//Set functions
	void SetLocked(bool);
	void SetItem(Item*);

	//get functions
	bool GetLocked();
	Item* GetItem();

private: 
	bool myLocked;
	Item* myItem;
};