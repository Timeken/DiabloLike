#pragma once
#include <string>

enum class ItemSlot
{
	SLOT_Head = 1,  SLOT_Hands = 2, SLOT_Body = 3, SLOT_Legs = 4, SLOT_Weapon_One = 5, SLOT_Weapon_Two = 6, SLOT_Feet = 7
};

class ItemType
{
public:
	ItemType(int someStrength = 0, int someAgility = 0, int someVitality = 0, int someDamage = 0, int someMaxHP = 0, int someCarryingCapacity = 0, int someDefence = 0, int someWight = 1, ItemSlot someSlot = ItemSlot::SLOT_Head, std::string aName = "no name");
	~ItemType() = default;
	ItemType(const ItemType& aRhs) = delete;

	ItemType& operator=(const ItemType& aRhs) = delete;

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
	std::string GetName();

private: 
	int myStrength;
	int myAgility;
	int myVitality;
	int myDamage;
	int myMaxHP;
	int myCarryingCapacity;
	int myDefence;
	int myWight;
	ItemSlot mySlot;
	std::string myName;
};