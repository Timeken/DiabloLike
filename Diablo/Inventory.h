#pragma once
#include "Character.h"
#include "Room.h"
#include "DiabloTools.h"
#include <vector>
#include <iostream>
class Inventory
{
public: 
	void InventoryMenu(Room*);
	bool AddItem(Item*);
	void AddMagic(MagicBuff);
	//set functions
	void SetCharacter(Character*);

	//get functions
	std::vector<Item*> GetItems();
	int GetItemWights();

private: 
	void ApplyItem(Item*);
	void UnapplyItem(Item*);
	void SpellList();
	static std::vector<Item*> myItems;
	static std::vector<MagicBuff> myMagic;
	Character* myCharacter;
};