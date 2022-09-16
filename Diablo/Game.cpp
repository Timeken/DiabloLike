#include "Game.h"
#include "EnemyFactory.h"
#include "ItemFactory.h"
#include <iostream>
#include <list>

ItemFactory myItemFactory;
EnemyFactory myEnemyFactory;
Character Game::myCharacter;
Map Game::mapVector;
Inventory Game::myInventory;
std::vector<std::vector<int>> Game::myExploredMap;
std::vector<Door> Game::myDoors;
std::vector<Room> Game::myRooms;
std::vector< std::vector<std::string>> roomNames = { 
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",},
    {"","","","","","","","","","",}, };
std::vector<std::string> roomNamesToSort = {
    {"Hallway","Storage","Coridor","Bed room","Kitchen","Keeping Room","Living Room","Formal Parlor","Reception","Pantry",
    "Dining Room","Library","Bathroom","Master Bedroom","Guest Room","Music Room","Wine Storage","Bed Chamber","Solar","Larder",
    "Buttery","Great Hall","Chapel","Storeroom","Place of Arms","Barraks","Study","Games Room","Large Kitchen","Small Bed Room",
    "Hall","Magic Study","Small Library","Brewery","Drawing Room","Cell","Armory","Assembly room","Backroom","Ballroom",
    "Boardroom","Boiler Room","Breakfast Room","Chamber","Conservatory","Clean room","Common room","Cloakroom","Darkroom","Dormitory",
    "Family Room","Formal Dining Room","Laundry Room","Lobby","Lounge","Lunchroom","Mailroom","Recovery Room","Sick Room","Staff Room",
    "Sitting Room","Studio","Wine Cellar","Workroom","Theatre","Long Corridor","Narrow Corridor","Small Corridor","Collapsed Room","Collapsed Hallway",
    "Short Hallway","Long Hallway","Narrow Hallway","Big Hallway","Small Hallway","Small Dining Room","Small Armory","Auditorium","Plant Room","Empty Room",
    "Glass Room","Cafeteria","Coal Room","Old Dining Room","Billiard room","Closet","Crypt","Root Cellar","Lumber Room","Torture Chamber",
    "Still Room","Secret Passage","Long Gallery","Assembly Hall","Dungeon","Big Room","Small Storeroom","Big Storeroom","Narrow Storeroom","Alchemy Room"}
};
int killCount = 0;
int currentRoom = 0;

void Game::DisplayMap()
{
    //Print map.
    for (int i = 0; i < myExploredMap.size(); i++)
    {
        for (int j = 0; j < myExploredMap[i].size(); j++)
        {
            std::cout << myExploredMap[i][j];
        }
        std::cout << std::endl;
    }
}
void Game::StartGame()
{
    myInventory.SetCharacter(&myCharacter);
    myExploredMap.resize(mapVector.GetMap().size(), std::vector<int>(mapVector.GetMap().size()));
    GenerateRooms();
    //place character on the map represented by a 2;
    bool endLoop = false;
    for (int i = 0; i < mapVector.GetMap().size(); i++)
    {
        for (int j = 0; j < mapVector.GetMap().size(); j++)
        {
            if (mapVector.GetMap()[i][j] == 1)
            {
                myExploredMap[i][j] = 2;
                endLoop = true;
                break;
            }
        }
        if (endLoop)
        {
            break;
        }
    }
    //randomize room names
    std::random_device random;
    std::default_random_engine rng(random());
    std::shuffle(std::begin(roomNamesToSort), std::end(roomNamesToSort), rng);
    int counter = 0;
    //add the random names to the room list
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            roomNames[i][j] = roomNamesToSort[counter];
            counter++;
        }
    }
    while (true)
    {
        CheckWin();
        DiabloTools::DisplayStats(&myCharacter);
        CheckMovement();
        myCharacter.DecreeseBuffs();
    }
}
void Game::CheckWin() 
{
    int killsToWin = 15;
    if (killCount >= killsToWin)
    {
        std::cout << "----------------" << std::endl;
        std::cout << "You win the game" << std::endl;
        std::cout << "----------------" << std::endl;
        system("pause");
        exit(0);
    }
    else
    {
        std::cout << "You need to kill "<< killsToWin - killCount <<" more monsters to win" << std::endl;
    }
}
void Game::CheckMovement()
{
    bool moved = false;    
    while (!moved)
    {
        DisplayMap();
        bool endLoop = false;
        int xCord = 0;
        int yCord = 0;
        for (int i = 0; i < myExploredMap.size(); i++)
        {
            for (int j = 0; j < myExploredMap.size(); j++)
            {
                if (myExploredMap[i][j] == 2)
                {
                    xCord = i;
                    yCord = j;
                    endLoop = true;
                    //display the room you are in
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == xCord && myRooms[y].GetRoomY() == yCord)
                        {
                            std::cout << "You are in the " << roomNames[xCord][yCord] << std::endl;
                        }
                    }
                    break;
                }
            }
            if (endLoop)
            {
                break;
            }
        }
        int counter = 0, door1 = -1, door2 = -1, door3 = -1, door4 = -1;
        for (int i = 0; i < myDoors.size(); i++)
        {
            if (myDoors[i].GetFirstRoom().GetRoomX() == xCord && myDoors[i].GetFirstRoom().GetRoomY() == yCord)
            {
                std::cout << "[" << counter + 1 << "] ";
                if (myDoors[i].GetPortal())
                {
                    std::cout << "Portal";
                }
                else if (myDoors[i].GetSeconedRoom().GetRoomX() > xCord)
                {
                    std::cout << "Door south";
                }
                else if (myDoors[i].GetSeconedRoom().GetRoomX() < xCord)
                {
                    std::cout << "Door north";
                }
                else if (myDoors[i].GetSeconedRoom().GetRoomY() > yCord)
                {
                    std::cout << "Door east";
                }
                else if(myDoors[i].GetSeconedRoom().GetRoomY() < yCord)
                {
                    std::cout << "Door west";
                }
                if (myDoors[i].GetLocked())
                {
                    std::cout << " Locked" << std::endl;
                }
                else
                {
                    std::cout << std::endl;
                }

                if (counter == 0)
                {
                    door1 = i;
                }
                else if (counter == 1)
                {
                    door2 = i;
                }
                else if (counter == 2)
                {
                    door3 = i;
                }
                else
                {
                    door4 = i;
                }
                counter++;
            }
            else if (myDoors[i].GetSeconedRoom().GetRoomX() == xCord && myDoors[i].GetSeconedRoom().GetRoomY() == yCord)
            {
                std::cout << "[" << counter + 1 << "] ";
                if (myDoors[i].GetPortal())
                {
                    std::cout << "Portal";
                }
                else if (myDoors[i].GetFirstRoom().GetRoomX() > xCord)
                {
                    std::cout << "Door south";
                }
                else if (myDoors[i].GetFirstRoom().GetRoomX() < xCord)
                {
                    std::cout << "Door north";
                }
                else if (myDoors[i].GetFirstRoom().GetRoomY() > yCord)
                {
                    std::cout << "Door east";
                }
                else if (myDoors[i].GetFirstRoom().GetRoomY() < yCord)
                {
                    std::cout << "Door west";
                }
                if (myDoors[i].GetLocked())
                {
                    std::cout << " Locked" << std::endl;
                }
                else
                {
                    std::cout << std::endl;
                }
     
                if (counter == 0)
                {
                    door1 = i;
                }
                else if (counter == 1)
                {
                    door2 = i;
                }
                else if (counter == 2)
                {
                    door3 = i;
                }
                else
                {
                    door4 = i;
                }
                counter++;
            }
        }
        std::cout << "[5] Inventory" << std::endl;
        for (int i = 0; i < myRooms.size(); i++)
        {
            if (myRooms[i].GetRoomX() == xCord && myRooms[i].GetRoomY() == yCord)
            {
                currentRoom = i;
                if (myRooms[i].GetChest().GetItem() != NULL)
                {
                    std::cout << "[6] Chest";
                    if (myRooms[i].GetChest().GetLocked())
                    {
                        std::cout << " locked" << std::endl;
                    }
                    else
                    {
                        std::cout << std::endl;
                    }
                }
                if (myRooms[i].GetMagic().GetTimer() > 0)
                {
                    std::cout << "[7] Magic" << std::endl;
                }
                if (myRooms[i].GetItems().size() > 0)
                {
                    std::cout << "[8] Items" << std::endl;
                }
            }
        }
        DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
        switch (input)
        {
        case DiabloTools::Choice::Choice1:
        {
            moved = MoveCharacter(door1, xCord, yCord);
            break;
        }
        case DiabloTools::Choice::Choice2:
        {
            moved = MoveCharacter(door2, xCord, yCord);
            break;
        }
        case DiabloTools::Choice::Choice3:
        {
            moved = MoveCharacter(door3, xCord, yCord);
            break;
        }
        case DiabloTools::Choice::Choice4:
        {
            moved = MoveCharacter(door4, xCord, yCord);
            break;
        }
        case DiabloTools::Choice::Choice5:
        {
            myInventory.InventoryMenu(&myRooms[currentRoom]);
            DiabloTools::DisplayStats(&myCharacter);
            break;
        }
        case DiabloTools::Choice::Choice6:
        {
            if(myRooms[currentRoom].GetChest().GetLocked())
            {
                std::cout << "Do you want to open the chest?" << std::endl;
                std::cout << "[1] Yes [2] No" << std::endl;
                DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
                if ((int)input == 1)
                {
                    Chest myTempChest = myRooms[currentRoom].GetChest();
                    myTempChest.SetLocked(false);
                    myRooms[currentRoom].SetChest(myTempChest);
                }
                else
                {
                    std::cout << "You leave the chest locked" << std::endl;
                }
            }
            if (!myRooms[currentRoom].GetChest().GetLocked())
            {
                std::cout << "The chest contans " << myRooms[currentRoom].GetChest().GetItem()->GetName() << std::endl;
                std::cout << "Do you want to pick it up?" << std::endl;
                std::cout << "[1] Yes [2] No" << std::endl;
                DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
                if ((int)input == 1)
                {          
                    if (myInventory.AddItem(myRooms[currentRoom].GetChest().GetItem()))
                    {
                        myRooms[currentRoom].SetChest(Chest());
                    }
                }
                else
                {
                    std::cout << "You leave the item" << std::endl;
                }
            }
            break;
        }
        case DiabloTools::Choice::Choice7:
        {
            std::cout << "Do you want pickup the magic?" << std::endl;
            std::cout << "[1] Yes [2] No" << std::endl;
            DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
            if ((int)input == 1)
            {
                //myCharacter.addBuff(myRooms[currentRoom].getMagic());
                myInventory.AddMagic(myRooms[currentRoom].GetMagic());
                myRooms[currentRoom].SetMagic(MagicBuff());
            }
            else
            {
                std::cout << "You leave the magic" << std::endl;
            }
            break;
        }
        case DiabloTools::Choice::Choice8:
        {
            std::vector<Item*> myRoomItems = myRooms[currentRoom].GetItems();
            for (int i = 0; i < myRoomItems.size(); i++)
            {
                std::cout << "[" << i + 1 << "] " << myRooms[currentRoom].GetItems()[i]->GetName();
                DiabloTools::DisplayItemStats(myRoomItems[i]);
                std::cout << std::endl;
            }
            std::cout << "[" << myRoomItems.size() + 1 << "] leave items" << std::endl;
            int input = DiabloTools::CheckInput();
            if (input <= myRoomItems.size() && input > 0)
            {
                for (int i = 0; i < myRoomItems.size(); i++)
                {
                    if (input == i + 1 && myInventory.AddItem(myRoomItems[i]))
                    {
                        myRoomItems.erase(myRoomItems.begin() + i);
                        myRooms[currentRoom].SetItem(myRoomItems);
                    }
                }
            }
            else
            {
                std::cout << "You leave the items" << std::endl;
            }
            break;
        }
        default:
        {
            std::cout << "Not an option" << std::endl;
            break;
        }
        }
    }
}

bool Game::MoveCharacter(int aDoor, int anXCord, int anYCord)
{
    bool haveMoved = false;
    bool roomEnterd = false;
    if (aDoor >= 0)
    {
        if (myDoors[aDoor].GetLocked())
        {
            std::cout << "Do you want to open the locked door?" << std::endl;
            std::cout << "Yes [1], No [2]" << std::endl;
            DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
            switch (input)
            {
            case DiabloTools::Choice::Choice1:
            {
                std::cout << "You open the locked door" << std::endl;
                break;
            }
            case DiabloTools::Choice::Choice2:
            {
                std::cout << "You leave the door locked" << std::endl;
                return false;
                break;
            }
            default:
            {
                std::cout << "Not an option" << std::endl;
                return false;
                break;
            }
            }
            myDoors[aDoor].SetLocked(false);
        }
        if (myDoors[aDoor].GetFirstRoom().GetRoomX() == anXCord && myDoors[aDoor].GetFirstRoom().GetRoomY() == anYCord)
        {
            if (myExploredMap[myDoors[aDoor].GetSeconedRoom().GetRoomX()][myDoors[aDoor].GetSeconedRoom().GetRoomY()] != 1)
            {
                roomEnterd = true;
                //set currentRoom to new room
                CheckRoomLocation(myDoors[aDoor].GetSeconedRoom().GetRoomX(), myDoors[aDoor].GetSeconedRoom().GetRoomY());
            }

            myExploredMap[anXCord][anYCord] = 1;
            myExploredMap[myDoors[aDoor].GetSeconedRoom().GetRoomX()][myDoors[aDoor].GetSeconedRoom().GetRoomY()] = 2;
            haveMoved = true;
        }
        else
        {
            if (myExploredMap[myDoors[aDoor].GetFirstRoom().GetRoomX()][myDoors[aDoor].GetFirstRoom().GetRoomY()] != 1)
            {
                roomEnterd = true;
                //set currentRoom to new room
                CheckRoomLocation(myDoors[aDoor].GetFirstRoom().GetRoomX(), myDoors[aDoor].GetFirstRoom().GetRoomY());
            }

            myExploredMap[anXCord][anYCord] = 1;
            myExploredMap[myDoors[aDoor].GetFirstRoom().GetRoomX()][myDoors[aDoor].GetFirstRoom().GetRoomY()] = 2;
            haveMoved = true;
        }
    }
    else
    {
        std::cout << "Not an option" << std::endl;
    }

    if (roomEnterd)
    {
        SetupCombat();
    }

    return haveMoved;
}
void Game::CheckRoomLocation(int anXCod, int aYCord)
{
    for (int i = 0; i < myRooms.size(); i++)
    {
        if (anXCod == myRooms[i].GetRoomX() && aYCord == myRooms[i].GetRoomY())
        {
            currentRoom = i;
            break;
        }
    }
}
void Game::SetupCombat()
{
    int minEnemies = 0, maxEnemies = 3, min = 1, max = 3;
    int numEnemies = DiabloTools::RandomNum(minEnemies, maxEnemies);  
    std::vector<Enemy*> myEnemies;
     for(int i = 0; i < numEnemies; i++)
     {
        myEnemies.push_back(myEnemyFactory.CreateEnemy((EnemyTypeIndex)DiabloTools::RandomNum(min, max)).release());
     }
    std::cout << "The enemy number " << myEnemies.size() << " in this room." << std::endl;
    while (myEnemies.size() > 0)
    {
        DiabloTools::DisplayStats(&myCharacter);
        //sort combat order based on agility
        sort(myEnemies.begin(), myEnemies.end(), [](Enemy* x, Enemy* y) { return x->GetStats().GetAgility() < y->GetStats().GetAgility(); });
        //display enemy health and damage 
        for (int i = 0; i < myEnemies.size(); i++)
        {
            std::cout << myEnemies[i]->GetName()<<" [" << i+1 <<"] HP:" << myEnemies[i]->GetHealth() << " dmg:" << myEnemies[i]->GetStats().GetDamage() << ", ";
        }
        std::cout << std::endl;
        bool characterAttaced = false;
        for (int i = 0; i < myEnemies.size(); i++)
        {
            //Check if character attacks first
            if (myCharacter.GetCharacter().GetAgility() >= myEnemies[i]->GetStats().GetAgility() && !characterAttaced)
            {
                while(!characterAttaced)
                {
                    DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
                    if((int)input >= 1 && (int)input <= myEnemies.size())
                    {
                        if ((myCharacter.GetCharacter().GetDamage() - myEnemies[(int)input - 1]->GetStats().GetDefence()) > 0)
                        {             
                            myEnemies[(int)input - 1]->SetHealth(DealDamage(myCharacter.GetCharacter().GetDamage(), myEnemies[(int)input - 1]->GetStats().GetDefence()));
                            std::cout << "You deal " << DealDamage(myCharacter.GetCharacter().GetDamage(), myEnemies[(int)input - 1]->GetStats().GetDefence()) << " damage" << std::endl;
                            if (myEnemies[(int)input - 1]->GetHealth() <= 0)
                            {
                                myEnemies.erase(myEnemies.begin() + ((int)input - 1));
                                int min = 0, max = 1;
                                if (DiabloTools::RandomNum(min, max) == 0)
                                {                      
                                    std::vector<Item*> myRoomItems = myRooms[currentRoom].GetItems();
                                    myRoomItems.push_back(GenerateItem().release());
                                    myRooms[currentRoom].SetItem(myRoomItems);
                                    std::cout << "The enemy dropped an item" << std::endl;
                                }
                                killCount++;
                            }
                            characterAttaced = true;
                        }
                        else
                        {
                            std::cout << "You deal no damage" << std::endl;
                        }
                        
                    }
                    else
                    {
                        std::cout << "No option" << std::endl;
                    }
                }             
            }
            if (myEnemies.size() != 0)
            {
                if (-myEnemies[i]->GetStats().GetDamage() + myCharacter.GetCharacter().GetDefence() < 0)
                {
                    Stats tempStats = myCharacter.GetCharacter();
                    tempStats.SetCurrentHP(DealDamage(myEnemies[i]->GetStats().GetDamage(), myCharacter.GetCharacter().GetDefence()));
                    myCharacter.SetCharacter(tempStats);
                    std::cout << "The enemy deal " << DealDamage(myEnemies[i]->GetStats().GetDamage(), myCharacter.GetCharacter().GetDefence()) << " damage" << std::endl;
                    if (myCharacter.GetCharacter().GetCurrentHP() <= 0)
                    {
                        std::cout << "----------------" << std::endl;
                        std::cout << " You have died" << std::endl;
                        std::cout << "----------------" << std::endl;
                        system("pause");
                        exit(0);
                    }
                }
                else
                {
                    std::cout << "The enemy deal no damage" << std::endl;
                }
            }
        }
        std::cout << "The enemy number " << myEnemies.size() << " in this room." << std::endl;
    }
}

void Game::GenerateRooms()
{
    int min = 0, max = 10;
    for (int i = 0; i < mapVector.GetMap().size(); i++)
    {
        for (int j = 0; j < mapVector.GetMap().size(); j++)
        {
            if (mapVector.GetMap()[i][j] == 1)
            {                
                std::vector<Item*> roomItem;
                Chest myChestToGenerated;
                MagicBuff myMagicGenerated;
                if (DiabloTools::RandomNum(min, max) == 0)
                {
                    myChestToGenerated = GenerateChest();
                }
                if (DiabloTools::RandomNum(min, max) == 0)
                {
                    roomItem.push_back(GenerateItem().release());
                }
                if (DiabloTools::RandomNum(min, max) == 0)
                {
                    myMagicGenerated = GenerateMagic();
                }

                myRooms.push_back(Room(i,j, myChestToGenerated, roomItem, myMagicGenerated, roomNames[i][j]));
            }
        }
    }
    GenerateDoors();
}

int Game::DealDamage(int someDamage, int someDefence) 
{
    someDamage -= someDefence;
    return -someDamage;
}

void Game::GenerateDoors()
{
    Door myDoorToGenerate;
    int counter = 0, portal = 0, doorsToNextPortal = 10, min = 0, max = 10;
    bool portalGenerated = false;
    for (int i = 0; i < mapVector.GetMap().size(); i++)
    {
        for (int j = 0; j < mapVector.GetMap().size(); j++)
        {
            if (mapVector.GetMap()[i][j] == 1)
            {              
                if (i + 1 <= 9 && mapVector.GetMap()[i + 1][j] == 1)
                {
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == i && myRooms[y].GetRoomY() == j)
                        {
                            myDoorToGenerate.SetFirstRoom(myRooms[y]);
                        }
                    }
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == i + 1 && myRooms[y].GetRoomY() == j)
                        {
                            myDoorToGenerate.SetSeconedRoom(myRooms[y]);
                        }
                    }
                    if (DiabloTools::RandomNum(min, max) == 0)
                    {
                        myDoorToGenerate.SetLocked(true);
                    }
                    else
                    {
                        myDoorToGenerate.SetLocked(false);
                    }
                    myDoors.push_back(myDoorToGenerate);
                    counter++;
                }
                else if (i + 1 <= 9 && mapVector.GetMap()[i + 1][j] == 0 && !portalGenerated)
                {           
                    //generate portal part entry
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == i && myRooms[y].GetRoomY() == j)
                        {
                            myDoorToGenerate.SetFirstRoom(myRooms[y]);
                        }
                    }
                    myDoorToGenerate.SetPortal(true);
                    myDoors.push_back(myDoorToGenerate);
                    myDoorToGenerate.SetPortal(false);
                    portal = counter;
                    counter++;
                    portalGenerated = true;
                }
                if (j + 1 <= 9 && mapVector.GetMap()[i][j + 1] == 1)
                {
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == i && myRooms[y].GetRoomY() == j)
                        {
                            myDoorToGenerate.SetFirstRoom(myRooms[y]);
                        }
                    }
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == i && myRooms[y].GetRoomY() == j + 1)
                        {
                            myDoorToGenerate.SetSeconedRoom(myRooms[y]);
                        }
                    }
                    if (DiabloTools::RandomNum(min, max) == 0)
                    {
                        myDoorToGenerate.SetLocked(true);
                    }
                    else
                    {
                        myDoorToGenerate.SetLocked(false);
                    }
                    myDoors.push_back(myDoorToGenerate);
                    counter++;
                }
                else if (j + 1 <= 9 && mapVector.GetMap()[i][j + 1] == 0 && portalGenerated && portal + doorsToNextPortal > counter)
                {
                    //generate portal part exit
                    for (int y = 0; y < myRooms.size(); y++)
                    {
                        if (myRooms[y].GetRoomX() == i && myRooms[y].GetRoomY() == j && myDoors[portal].GetFirstRoom().GetRoomX() -i > myDoors[portal].GetFirstRoom().GetRoomX()-1)
                        {
                            myDoors[portal].SetSeconedRoom(myRooms[y]);
                        }
                    }
                    portalGenerated = false;
                }
            }
        }
    }
    //if the second portal did not generat force it to generate.
    if (portalGenerated)
    {
        myDoors.at(portal).SetSeconedRoom(myRooms[myRooms.size()-1]);
    }
}
std::unique_ptr<Item> Game::GenerateItem()
{
    int min = 1, max = 7;
    return myItemFactory.CreateItem((ItemTypeIndex)DiabloTools::RandomNum(min, max));
}

MagicBuff Game::GenerateMagic()
{
    int min = 0, max = 1, timeMin = 2, timeMax = 6;
    return MagicBuff(DiabloTools::RandomNum(min, max), DiabloTools::RandomNum(min, max), DiabloTools::RandomNum(min, max), DiabloTools::RandomNum(timeMin, timeMax));
}

Chest Game::GenerateChest()
{
    int min = 0, max = 10;
    bool locked = true;
    if (DiabloTools::RandomNum(min, max) == 0)
    {
        locked = false;
    }
    return Chest(GenerateItem().release(), locked);
}
