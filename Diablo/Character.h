#pragma once
#include "Stats.h"
#include "MagicBuff.h"
#include <vector>
#include <iostream>
class Character
{
public: 
	Character();
	void AddBuff(MagicBuff);
	void DecreeseBuffs();
	//set functions
	void SetCharacter(Stats);

	//get functions
	Stats GetCharacter();

private: 
	static Stats myStats;
	static std::vector<MagicBuff> myBuffs;
};