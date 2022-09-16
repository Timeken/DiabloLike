#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Chest.h"
#include "MagicBuff.h"
class Room
{
public: 
	Room(int someXCord = 0, int someYCord = 0, Chest someChest = myNoChest, std::vector<Item*> someItems = myNoItems, MagicBuff someMagic = myNoMagic, std::string aName = "no name");
	//set functions
	void SetRoomX(int);
	void SetRoomY(int);
	void SetMagic(MagicBuff);
	void SetChest(Chest);
	void SetItem(std::vector<Item*>);
	void SetName(std::string);

	//get functions
	int GetRoomX();
	int GetRoomY();
	MagicBuff GetMagic();
	Chest GetChest();
	std::vector<Item*> GetItems();
	std::string GetName();

private: 
	int myXCord;
	int myYCord;
	std::string myName;
	Chest myChest;
	MagicBuff myMagic;
	std::vector<Item*> myItems;
	//needed for defult constructor
	static std::vector<Item*> myNoItems;
	static Chest myNoChest;
	static MagicBuff myNoMagic;
};