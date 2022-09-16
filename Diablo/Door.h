#pragma once
#include "Room.h"
class Door
{
public: 
	Door(Room aFirstRoom = NULL, Room aSeconedRoom = NULL, bool someLocked = false, bool aPortal = false);

	//set functions
	void SetFirstRoom(Room);
	void SetSeconedRoom(Room);
	void SetLocked(bool);
	void SetPortal(bool);

	//get functions
	Room GetFirstRoom();
	Room GetSeconedRoom();
	bool GetLocked();
	bool GetPortal();

private: 
	int myFirstX;
	int myFirstY;
	int mySeconedX;
	int mySeconedY;
	bool myLocked;
	bool myPortal;
	Room myFirstRoom;
	Room mySeconedRoom;
};