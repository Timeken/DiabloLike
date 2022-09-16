#include "Room.h"

std::vector<Item*> Room::myNoItems;
Chest Room::myNoChest;
MagicBuff Room::myNoMagic;

Room::Room(int aXCord, int aYCord, Chest aChest, std::vector<Item*> someItems, MagicBuff someMagic, std::string aName)
{
	SetRoomX(aXCord);
	SetRoomY(aYCord);
	SetChest(aChest);
	SetItem(someItems);
	SetMagic(someMagic);
	SetName(aName);
}

void Room::SetRoomX(int aXCord)
{
	myXCord = aXCord;
}

void Room::SetRoomY(int aYCord)
{
	myYCord = aYCord;
}

void Room::SetChest(Chest aChest)
{
	myChest = aChest;
}

void Room::SetItem(std::vector<Item*> someItems)
{
	myItems = someItems;
}

void Room::SetMagic(MagicBuff someMagic)
{
	myMagic = someMagic;
}

void Room::SetName(std::string aName)
{
	myName = aName;
}

int Room::GetRoomX()
{
	return myXCord;
}

int Room::GetRoomY()
{
	return myYCord;
}

Chest Room::GetChest()
{
	return myChest;
}

std::vector<Item*> Room::GetItems()
{
	return myItems;
}

MagicBuff Room::GetMagic()
{
	return myMagic;
}

std::string Room::GetName()
{
	return myName;
}
