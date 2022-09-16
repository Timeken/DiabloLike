#pragma once
class MagicBuff
{
public: 
	MagicBuff(int someStrength = 0, int someAgility = 0, int someVitality = 0, int aTimer = 0);

	void SetStrength(int);
	void SetAgility(int);
	void SetVitality(int);
	void SetTimer(int);

	int GetStrength();
	int GetAgility();
	int GetVitality();
	int GetTimer();

private: 
	int myStrength;
	int myAgility;
	int myVitality;
	int myTimer;
};