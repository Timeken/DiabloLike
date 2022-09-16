#include "Inventory.h"
#include "ItemType.h"

std::vector<Item*> Inventory::myItems;
std::vector<MagicBuff> Inventory::myMagic;
Character Inventory::*myCharacter;

bool Inventory::AddItem(Item* aItem)
{
	bool canPickUp = false;

	if (GetItemWights() < myCharacter->GetCharacter().GetCarryingCapacity())
	{
		if (myItems.size() != 0)
		{
			for (int i = 0; i < myItems.size(); i++)
			{
				if (myItems[i]->GetSlot() == aItem->GetSlot() && myItems[i]->GetEquipped() || myItems[i]->GetSlot() == ItemSlot::SLOT_Weapon_Two && aItem->GetSlot() == ItemSlot::SLOT_Weapon_One && myItems[i]->GetEquipped() ||
					myItems[i]->GetSlot() == ItemSlot::SLOT_Weapon_One && aItem->GetSlot() == ItemSlot::SLOT_Weapon_Two && myItems[i]->GetEquipped())
				{
					break;
				}
				if (myItems.size() == i + 1)
				{
					aItem->SetEquipped(!aItem->GetEquipped());
					ApplyItem(aItem);
				}
			}			
		}
		else
		{
			aItem->SetEquipped(!aItem->GetEquipped());
			ApplyItem(aItem);
		}
		myItems.push_back(aItem);
		canPickUp = true;
	}
	else
	{
		std::cout << "You can't carry anymore" << std::endl;
	}

	return canPickUp;
}

void Inventory::AddMagic(MagicBuff someMagic)
{
	myMagic.push_back(someMagic);
}

void Inventory::SetCharacter(Character* aCharacter)
{
	myCharacter = aCharacter;
}

void Inventory::ApplyItem(Item* aItem)
{
	Stats myStats = myCharacter->GetCharacter();
	std::cout << myCharacter->GetCharacter().GetAgility()<< std::endl;
	myStats.SetAgility(aItem->GetAgility());
	myStats.SetStrength(aItem->GetStrength());
	myStats.SetVitality(aItem->GetVitality());
	myStats.SetDamageMod(aItem->GetDamage());
	myStats.SetMaxHPMod(aItem->GetMaxHP());
	myStats.SetCarryingCapacityMod(aItem->GetCarryingCapacity());
	myStats.SetDefenceMod(aItem->GetDefence());
	myCharacter->SetCharacter(myStats);
}
void Inventory::UnapplyItem(Item* aItem)
{
	Stats myStats = myCharacter->GetCharacter();
	myStats.SetAgility(-aItem->GetAgility());
	myStats.SetStrength(-aItem->GetStrength());
	myStats.SetVitality(-aItem->GetVitality());
	myStats.SetDamageMod(-aItem->GetDamage());
	myStats.SetMaxHPMod(-aItem->GetMaxHP());
	myStats.SetCarryingCapacityMod(-aItem->GetCarryingCapacity());
	myStats.SetDefenceMod(-aItem->GetDefence());
	myCharacter->SetCharacter(myStats);
}

void Inventory::SpellList()
{
	for (int i = 0; i < myMagic.size(); i++)
	{
		std::cout << "["<< i+1 <<"]" << " AGI:" << myMagic[i].GetAgility() << " STR: " << myMagic[i].GetStrength() << " VIT: " << myMagic[i].GetVitality() << " time: " << myMagic[i].GetTimer() << std::endl;
	}
	std::cout << "[" << myMagic.size() + 1 << "] Exit" << std::endl;
	DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
	if (myMagic.size() > 0 && myMagic.size() >= (int)input && (int)input > 0)
	{
		myCharacter->AddBuff(myMagic[(int)input-1]);
		myMagic.erase(myMagic.begin() + (int)input - 1);
	}
	else
	{

	}
}

void Inventory::InventoryMenu(Room *aRoom)
{
	while (true)
	{
		bool mainHand = false, head = false, legs = false, hands = false, body = false, feet = false, twoHand = false, offHand = false;
		DiabloTools::DisplayStats(myCharacter);
		ItemSlot mySlot;
		for (int i = 0; i < 7; i++)
		{
			//7 is the number of slots that exists
			for (int j = 0; j < myItems.size(); j++)
			{
				mySlot = (ItemSlot)(1+i);

				switch (mySlot)
				{
				case ItemSlot::SLOT_Head : 
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Head: " << myItems[j]->GetName() << std::endl;
						head = true;
					}
					else if(j == myItems.size()-1 && !head)
					{
						std::cout << "Head: -" << std::endl;
					}
					break;
				}
				case ItemSlot::SLOT_Hands:
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Hands: " << myItems[j]->GetName() << std::endl;
						hands = true;
					}
					else if (j == myItems.size()-1 && !hands)
					{
						std::cout << "Hands: -" << std::endl;
					}
					break;
				}
				case ItemSlot::SLOT_Body:
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Body: " << myItems[j]->GetName() << std::endl;
						body = true;
					}
					else if (j == myItems.size()-1 && !body)
					{
						std::cout << "Body: -" << std::endl;
					}
					break;
				}
				case ItemSlot::SLOT_Legs:
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Legs: " << myItems[j]->GetName() << std::endl;
						legs = true;
					}
					else if (j == myItems.size()-1 && !legs)
					{
						std::cout << "Legs: -" << std::endl;
					}
					break;
				}
				case ItemSlot::SLOT_Weapon_One:
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetEquippedOffHand() == false && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Main hand: " << myItems[j]->GetName() << std::endl;
						mainHand = true;
					}
					else if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Off hand: " << myItems[j]->GetName() << std::endl;
						offHand = true;
					}
					break;
				}
				case ItemSlot::SLOT_Weapon_Two:
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot && !mainHand)
					{
						std::cout << "Main hand: " << myItems[j]->GetName() << std::endl;
						std::cout << "Off hand: " << myItems[j]->GetName() << std::endl;
						twoHand = true;
					}
					else if (j == myItems.size()-1 && !twoHand)
					{
						if (!mainHand) 
						{
							std::cout << "Main hand: -" << std::endl;
						}
						if (!offHand) 
						{
							std::cout << "Off hand: -" << std::endl;
						}
					}
					break;
				}
				case ItemSlot::SLOT_Feet:
				{
					if (myItems[j]->GetEquipped() == true && myItems[j]->GetSlot() == mySlot)
					{
						std::cout << "Feet: " << myItems[j]->GetName() << std::endl;
						feet = true;
					}
					else if (j == myItems.size()-1 && !feet)
					{
						std::cout << "Feet: -" << std::endl;
					}
					break;
				}
				default:
					break;
				}
			}
		}		
		std::cout << "Your inventory is at [" << GetItemWights() <<"/"<< myCharacter->GetCharacter().GetCarryingCapacity() << "] capacity" << std::endl;
		if (myItems.size() > 0)
		{
			for (int i = 0; i < myItems.size(); i++)
			{
				std::cout << "[" << i + 1 << "] " << myItems[i]->GetName();
				DiabloTools::DisplayItemStats(myItems[i]);
				if (myItems[i]->GetEquipped())
				{
					std::cout << " (Equipped)";
				}
				std::cout << std::endl;
			}
		}
		else
		{
			std::cout << "Your inventory is empty"<< std::endl;
		}
		std::cout << "[" << myItems.size() + 1 << "] Spell list" << std::endl;
		std::cout << "[" << myItems.size() + 2 << "] Exit inventory" << std::endl;
		DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
		if (myItems.size() > 0 && myItems.size() >= (int)input)
		{
			for (int i = 0; i < myItems.size(); i++)
			{
				if ((int)input == i + 1)
				{
					if (myItems[i]->GetEquipped())
					{
						std::cout << "[1] Unequip" << std::endl;
					}
					else
					{
						std::cout << "[1] Equip" << std::endl;
						std::cout << "[2] Drop" << std::endl;
					}
					DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
					switch (input)
					{
					case DiabloTools::Choice::Choice1:
					{
						if (myItems[i]->GetEquipped())
						{
							UnapplyItem(myItems[i]);
							myItems[i]->SetEquipped(!myItems[i]->GetEquipped());
							myItems[i]->SetEquippedOffHand(false);
						}
						else if (myItems[i]->GetSlot() == ItemSlot::SLOT_Body && !body || myItems[i]->GetSlot() == ItemSlot::SLOT_Feet && !feet || myItems[i]->GetSlot() == ItemSlot::SLOT_Hands && !hands ||
							myItems[i]->GetSlot() == ItemSlot::SLOT_Head && !head || myItems[i]->GetSlot() == ItemSlot::SLOT_Legs && !legs  || myItems[i]->GetSlot() == ItemSlot::SLOT_Weapon_Two && !twoHand && !mainHand && !offHand)
						{
							ApplyItem(myItems[i]);
							myItems[i]->SetEquipped(!myItems[i]->GetEquipped());
						}
						else if (myItems[i]->GetSlot() == ItemSlot::SLOT_Weapon_One && !offHand && !twoHand || myItems[i]->GetSlot() == ItemSlot::SLOT_Weapon_One && !mainHand && !twoHand)
						{
							bool choseing = true;
							while (choseing)
							{
								if (!mainHand)
								{
									std::cout << "[1] Main hand" << std::endl;
								}
								if (!offHand)
								{
									std::cout << "[2] Off hand" << std::endl;
								}
								DiabloTools::Choice input = DiabloTools::Choice(DiabloTools::CheckInput());
								switch (input)
								{
								case DiabloTools::Choice::Choice1: 
								{
									ApplyItem(myItems[i]);
									myItems[i]->SetEquipped(!myItems[i]->GetEquipped());
									choseing = false;
									break;
								}
								case DiabloTools::Choice::Choice2:
								{
									ApplyItem(myItems[i]);
									myItems[i]->SetEquipped(!myItems[i]->GetEquipped());
									myItems[i]->SetEquippedOffHand(true);
									choseing = false;
									break;
								}
								default:
									std::cout << "Not an option" << std::endl;
									break;
								}
							}
							
						}
						else
						{
							std::cout << "You can't equip more of those" << std::endl;
						}
						break;
					}
					case DiabloTools::Choice::Choice2:
					{
						if (!myItems[i]->GetEquipped())
						{
							//get the items in the room and add the dropped item
							std::vector<Item*> myRoomItems = aRoom->GetItems();
							myRoomItems.push_back(myItems[i]);
							aRoom->SetItem(myRoomItems);
							myItems.erase(myItems.begin() + i);
						}
						else
						{
							std::cout << "Not an option" << std::endl;
						}
						break;
					}
					default:
						std::cout << "Not an option" << std::endl;
						break;
					}
				}
			}
		}
		else if ((int)input == myItems.size() + 1)
		{
			SpellList();
		}
		else if ((int)input == myItems.size() + 2)
		{
			break;
		}
		else
		{
			std::cout << "Not an option" << std::endl;
		}
	}
}

std::vector<Item*> Inventory::GetItems()
{
	return myItems;
}

int Inventory::GetItemWights()
{
	int itemsWight = 0;

	for (int i = 0; i < myItems.size(); i++)
	{
		itemsWight += myItems[i]->GetWight();
	}

	return itemsWight;
}
