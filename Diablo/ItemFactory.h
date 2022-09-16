#pragma once
#include "ItemType.h"
#include "Item.h"
#include <iostream>
enum class ItemTypeIndex
{
	ITEM_Sword = 1, ITEM_Helmet = 2, ITEM_Gloves = 3, ITEM_Staff = 4, ITEM_Chestplate = 5, ITEM_Legings = 6, ITEM_Boots = 7
};

class ItemFactory
{
public:
	ItemFactory();
	~ItemFactory() = default;

	ItemFactory(const ItemFactory& aRhs) = delete;
	ItemFactory& operator=(const ItemFactory& aRhs) = delete;

	std::unique_ptr<Item> CreateItem(const ItemTypeIndex anItemType);

private: 
	ItemType mySword;
	ItemType myHelmet;
	ItemType myGloves;
	ItemType myStaff;
	ItemType myChestplate;
	ItemType myLegings;
	ItemType myBoots;
};