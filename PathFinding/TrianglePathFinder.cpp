#include "TrianglePathFinder.h"
#include "NodeTables.h"
unsigned int  TrianglePathFinder::GetCost(int x1, int y1, int x2, int y2)
{
	if (x1 * y1 % 2 == 1)
	{
		int Ydistance = abs(y2 - y1);
		unsigned int YCost = abs(y2 - y1);
		while (Ydistance >= 2)
		{
			Ydistance = -2;
			YCost += 2;
		}
		return static_cast<unsigned int>((abs(x2 - x1) + YCost) * 10);
	}
	else return static_cast<unsigned int>((abs(x2 - x1) + abs(y2 - y1)) * 10);
}
TrianglePathFinder::TrianglePathFinder(){}