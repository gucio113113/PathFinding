#include "SquareSlantPathFinder.h"
#include "NodeTables.h"
unsigned int SquareSlantPathFinder::GetCost(int x1, int y1, int x2, int y2)
{
	unsigned int xdistance = static_cast<unsigned int>(abs(x2 - x1));
	unsigned int ydistance = static_cast<unsigned int>(abs(y2 - y1));

	if (xdistance == 0)
		return (ydistance * 10);
	else if (ydistance == 0)
		return (xdistance * 10);
	else if (xdistance > ydistance)
		return ((xdistance % ydistance) * 10) + (ydistance * 14);
	else if (xdistance < ydistance)
		return ((ydistance % xdistance) * 10) + (xdistance * 14);
	else
		return (xdistance * 14);
}
SquareSlantPathFinder::SquareSlantPathFinder(){}
