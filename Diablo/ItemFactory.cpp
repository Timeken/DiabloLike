#include "ItemFactory.h"
#include "Item.h"
ItemFactory::ItemFactory()
	:
	mySword(1, 0, 0, 0, 0, 0, 0, 1, ItemSlot::SLOT_Weapon_One,"Sword"),
	myHelmet(0, 1, 0, 0, 2, 0, 1, 1, ItemSlot::SLOT_Head, "Helmet"),
	myGloves(0, 0, 0, 2, 0, 0, 1, 1, ItemSlot::SLOT_Hands,"Gloves"),
	myStaff(0, 1, 0, 0, 0, 0, 0, 1, ItemSlot::SLOT_Weapon_Two,"Staff"),
	myLegings(0, 0, 1, 0, 0, 0, 1, 2, ItemSlot::SLOT_Legs, "Leggings"),
	myChestplate(1,0,1,0,0,0,2,3,ItemSlot::SLOT_Body,"Chestplate"),
	myBoots(0, 2, 0, 0, 0, 0, 0, 1, ItemSlot::SLOT_Feet, "Boots"){}

std::unique_ptr<Item> ItemFactory::CreateItem(const ItemTypeIndex anItemType)
{
	std::unique_ptr<Item> item
	{
		nullptr
	};

	switch (anItemType)
	{
	case ItemTypeIndex::ITEM_Sword:
	{
		auto item = std::make_unique<Item>(&mySword);
		return item;
		break;
	}
	case ItemTypeIndex::ITEM_Helmet:
	{
		auto item = std::make_unique<Item>(&myHelmet);
		return item;
		break;
	}
	case ItemTypeIndex::ITEM_Gloves:
	{
		auto item = std::make_unique<Item>(&myGloves);
		return item;
		break;
	}
	case ItemTypeIndex::ITEM_Staff:
	{
		auto item = std::make_unique<Item>(&myStaff);
		return item;
		break;
	}
	case ItemTypeIndex::ITEM_Chestplate:
	{
		auto item = std::make_unique<Item>(&myChestplate);
		return item;
		break;
	}
	case ItemTypeIndex::ITEM_Legings:
	{
		auto item = std::make_unique<Item>(&myLegings);
		return item;
		break;
	}
	case ItemTypeIndex::ITEM_Boots:
	{
		auto item = std::make_unique<Item>(&myBoots);
		return item;
		break;
	}
	default:
	{
		assert(false);
		return item;
	}
	}
}