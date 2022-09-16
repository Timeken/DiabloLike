#pragma once
#include <vector>
class Map
{
public: 
	Map(int someMapSize = 10);

	//set functions
	void SetMap(int);

	//get functions
	std::vector<std::vector<int>> GetMap();

private: 
	int myMapSize;
	std::vector<std::vector<int>> myMapVector;
};