#include "Map.h"
#include "DiabloTools.h"
Map::Map(int aMapSize)
{
	SetMap(aMapSize);
}

void Map::SetMap(int aMapSize)
{
	myMapSize = aMapSize;
	myMapVector.resize(myMapSize, std::vector<int>(myMapSize));
	bool myGenVertical = true;
	bool myGenHorizontal = true;
	//generate map
	do
	{
		for (int i = 0; i < myMapSize; i++)
		{
			for (int j = 0; j < myMapSize; j++)
			{
				if (DiabloTools::RandomNum(0, 1) == 0 && myMapVector[i][j] == 0)
				{
					for (int y = 0; y < myMapSize; y++)
					{
						if (i % 2 == 0 && j % 2 != 0)
						{
							myMapVector[y][j] = 1;
							if (y + 1 < myMapSize && myMapVector[y + 1][j] == 1)
							{
								myGenVertical = false;
								break;
							}
						}
					}
					for (int y = myMapSize-1; y > 0; y--)
					{
						if (i % 2 == 0 && j % 2 != 0)
						{
							myMapVector[y][j] = 1;
							if (y - 1 < myMapSize && myMapVector[i][y - 1] == 1)
							{
								break;
							}
						}
					}
					for (int y = 0; y < myMapSize; y++)
					{
						if (j % 2 == 0 && i % 2 != 0)
						{
							myMapVector[i][y] = 1;
							if (y + 1 < myMapSize && myMapVector[i][y + 1] == 1)
							{
								myGenHorizontal = false;
								break;
							}
						}
					}
					for (int y = myMapSize - 1; y > 0; y--)
					{
						if (i % 2 == 0 && j % 2 != 0)
						{
							myMapVector[j][y] = 1;
							if (y - 1 < myMapSize && myMapVector[i][y - 1] == 1)
							{
								break;
							}
						}
					}
				}
			}
		}
	}
	while (myGenVertical && myGenHorizontal);
}
std::vector<std::vector<int>> Map::GetMap()
{
	return myMapVector;
}