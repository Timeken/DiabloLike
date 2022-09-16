#include "Character.h"

Stats Character::myStats;
std::vector<MagicBuff> Character::myBuffs;

Character::Character()
{
	int myStartStats = 7;
	//Set stats for Character
	myStats.SetAgility(myStartStats);
	myStats.SetStrength(myStartStats);
	myStats.SetVitality(myStartStats);
	myStats.SetDamage(0);
	myStats.SetMaxHP(0);
	myStats.SetCurrentHP(0);
	myStats.SetCarryingCapacity(0);
	myStats.SetDefence(0);

	SetCharacter(myStats);
}

void Character::AddBuff(MagicBuff someBuff)
{
	myStats.SetAgility(someBuff.GetAgility());
	myStats.SetStrength(someBuff.GetStrength());
	myStats.SetVitality(someBuff.GetVitality());
	std::cout << "The magic buff gives you";
	if (someBuff.GetStrength() > 0)
	{
		std::cout << " STR:" << someBuff.GetStrength();
	}
	if (someBuff.GetAgility() > 0)
	{
		std::cout << " AGI:" << someBuff.GetAgility();
	}
	if (someBuff.GetVitality() > 0)
	{
		std::cout << " VIT:" << someBuff.GetVitality();
	}
	std::cout << " for " << someBuff.GetTimer()<<" rooms"<< std::endl;
	myBuffs.push_back(someBuff);
}

void Character::DecreeseBuffs()
{
	if (myBuffs.size() > 0)
	{
		for (int i = 0; i < myBuffs.size(); i++)
		{
			myBuffs[i].SetTimer(myBuffs[i].GetTimer() - 1);
			if (myBuffs[i].GetTimer() <= 0)
			{
				myStats.SetAgility(-myBuffs[i].GetAgility());
				myStats.SetStrength(-myBuffs[i].GetStrength());
				myStats.SetVitality(-myBuffs[i].GetVitality());
				myBuffs.erase(myBuffs.begin() + i);
			}
		}
	}
}

void Character::SetCharacter(Stats someStats)
{
	myStats = someStats;
}

Stats Character::GetCharacter()
{
	return myStats;
}