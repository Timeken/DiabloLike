#pragma once

class Stats
{
public: 
	Stats(int someStrength = 0, int someAgility = 0, int someVitality = 0);

	//set functions
	void SetStrength(int); 
	void SetAgility(int); 
	void SetVitality(int); 
	void SetDamage(int);
	void SetMaxHP(int);
	void SetCurrentHP(int);
	void SetCarryingCapacity(int);
	void SetDefence(int);
	void SetDamageMod(int);
	void SetMaxHPMod(int);
	void SetCarryingCapacityMod(int);
	void SetDefenceMod(int);

	//get functions
	int GetStrength();
	int GetAgility();
	int GetVitality();
	int GetDamage();
	int GetMaxHP();
	int GetCurrentHP();
	int GetCarryingCapacity();
	int GetDefence();

private: 
	int myStrength = 0;
	int myAgility = 0;
	int myVitality = 0;
	int myDamage = 0;
	int myMaxHP = 0;
	int myCurrentHP = 0;
	int myCarryingCapacity = 0;
	int myDefence = 0;
};