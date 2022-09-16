#pragma once
#include "Character.h"
#include "Map.h"
#include "Door.h"
#include "Enemy.h"
#include "Inventory.h"
#include "Room.h"
#include "MagicBuff.h"
#include "DiabloTools.h"
class Game
{
public: 
	static void RunGame()
	{
		StartGame();
	}
private: 
	static Character myCharacter;
	static Map mapVector;
	static Inventory myInventory;
	static std::vector<std::vector<int>> myExploredMap;
	static std::vector<Door> myDoors;
	static std::vector<Room> myRooms;

	static void DisplayMap();
	static void StartGame();
	static void CheckMovement();
	static void SetupCombat();
	static void GenerateRooms();
	static void GenerateDoors();
	static void CheckWin();
	static void CheckRoomLocation(int anXCod, int aYCord);
	static std::unique_ptr<Item> GenerateItem();
	static Chest GenerateChest();
	static MagicBuff GenerateMagic();
	static int DealDamage(int someDamage, int someDefence);
	static bool MoveCharacter(int aDoor, int anXCord, int aYCord);
};