#include "Door.h"
Door::Door(Room someFirstRoom, Room someSeconedRoom, bool aLocked, bool aPortal)
{
	SetFirstRoom(someFirstRoom);
	SetSeconedRoom(someSeconedRoom);
	SetLocked(aLocked);
	SetPortal(aPortal);
}
void Door::SetFirstRoom(Room someFirstRoom)
{
	myFirstRoom = someFirstRoom;
}
void Door::SetSeconedRoom(Room someSeconedRoom)
{
	mySeconedRoom = someSeconedRoom;
}
void Door::SetLocked(bool aLocked)
{
	myLocked = aLocked;
}
void Door::SetPortal(bool aPortal)
{
	myPortal = aPortal;
}
Room Door::GetFirstRoom()
{
	return myFirstRoom;
}
Room Door::GetSeconedRoom()
{
	return mySeconedRoom;
}
bool Door::GetLocked()
{
	return myLocked;
}
bool Door::GetPortal()
{
	return myPortal;
}