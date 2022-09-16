#pragma once
#include "ItemType.h"
#include <string>
#include <cassert>

class ItemType;

class Item
{
public:
	Item(ItemType* const anItemType);
	~Item() = default;
	Item(const Item& aRhs) = default;

	Item& operator=(const Item& aRhs) = default;

	//set functions
	void SetEquipped(bool);
	void SetEquippedOffHand(bool);

	//get functions
	int GetStrength();
	int GetAgility();
	int GetVitality();
	int GetDamage();
	int GetMaxHP();
	int GetCarryingCapacity();
	int GetDefence();
	int GetWight();
	ItemSlot GetSlot();
	bool GetEquipped();
	bool GetEquippedOffHand();
	std::string GetName();

private:
	bool myEquipped = false;
	bool myEquippedOffHand = false;
	int myStrength;
	int myAgility;
	int myVitality;
	int myDamage;
	int myMaxHP;
	int myCarryingCapacity;
	int myDefence;
	int myWight;
	std::string myName;
	ItemSlot mySlot;
	ItemType* myItemType;
};



