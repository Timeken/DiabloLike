#pragma once
#include <random>
#include <iostream>
#include "Item.h"
#include "Character.h"
class DiabloTools
{
	public: enum class Choice { Choice1 = 1, Choice2 = 2, Choice3 = 3, Choice4 = 4, Choice5 = 5, Choice6 = 6, Choice7 = 7, Choice8 = 8, Choice9 = 9, Choice10 = 10, Choice11 = 11 };

	public:static int RandomNum(int aMin, int aMax)
	{
		std::uniform_int_distribution<int> randNum(aMin, aMax);
		std::random_device random;

		return randNum(random);
	};

	public: static int CheckInput()
	{
		float checkInput;
		while (!(std::cin >> checkInput))
		{
			//clear bad input flag and discard input
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			std::cout << "invalid input" << std::endl;
		}
		int myCheckedInput = (int)checkInput;
		return myCheckedInput;
	};

	public: static void DisplayItemStats(Item* aItem)
	{
		if (aItem->GetStrength() > 0)
		{
			std::cout << " STR:" << aItem->GetStrength();
		}
		if (aItem->GetAgility() > 0)
		{
			std::cout << " AGI:" << aItem->GetAgility();
		}
		if (aItem->GetVitality() > 0)
		{
			std::cout << " VIT:" << aItem->GetVitality();
		}
		if (aItem->GetMaxHP() > 0)
		{
			std::cout << " HP:" << aItem->GetMaxHP();
		}
		if (aItem->GetDamage() > 0)
		{
			std::cout << " DMG:" << aItem->GetDamage();
		}
		if (aItem->GetCarryingCapacity() > 0)
		{
			std::cout << " CAR:" << aItem->GetCarryingCapacity();
		}
		if (aItem->GetDefence() > 0)
		{
			std::cout << " DEF:" << aItem->GetDefence();
		}
		std::cout << " | Weight:" << aItem->GetWight();
	};

	public: static void DisplayStats(Character *someCharacter)
	{
		//Print stats
		std::cout << "------------------------------------" << std::endl;
		std::cout << "STR: [" << someCharacter->GetCharacter().GetStrength() << "] AGI: [" << someCharacter->GetCharacter().GetAgility() << "] VIT: [" << someCharacter->GetCharacter().GetVitality() << "]" << std::endl;
		std::cout << "HP: [" << someCharacter->GetCharacter().GetCurrentHP() << "/" << someCharacter->GetCharacter().GetMaxHP() << "]" << std::endl;
		std::cout << "DMG: [" << someCharacter->GetCharacter().GetDamage() << "] CAR: [" << someCharacter->GetCharacter().GetCarryingCapacity() << "] DEF: [" << someCharacter->GetCharacter().GetDefence() << "]" << std::endl;
		std::cout << "------------------------------------" << std::endl;
	};
};