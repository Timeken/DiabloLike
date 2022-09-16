#include "MagicBuff.h"

MagicBuff::MagicBuff(int someStrength, int someAgility, int someVitality, int aTimer)
{
	SetStrength(someStrength);
	SetAgility(someAgility);
	SetVitality(someVitality);
	SetTimer(aTimer);
}

void MagicBuff::SetStrength(int someStrength)
{
	someStrength = someStrength;
}

void MagicBuff::SetAgility(int someAgility)
{
	myAgility = someAgility;
}

void MagicBuff::SetVitality(int someVitality)
{
	myVitality = someVitality;
}

void MagicBuff::SetTimer(int aTimer)
{
	myTimer = aTimer;
}

int MagicBuff::GetStrength()
{
	return myStrength;
}

int MagicBuff::GetAgility()
{
	return myAgility;
}

int MagicBuff::GetVitality()
{
	return myVitality;
}

int MagicBuff::GetTimer()
{
	return myTimer;
}


