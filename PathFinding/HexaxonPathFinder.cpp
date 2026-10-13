#include "HexaxonPathFinder.h"
#include "NodeTables.h"


unsigned int  HexaxonPathFinder::GetCost(int x1, int y1, int x2, int y2)
{
	unsigned int xdistance = static_cast<unsigned int>(abs(x2 - x1));
	unsigned int ydistance = static_cast<unsigned int>(abs(y2 - y1));
	if (xdistance > ydistance)
		return ((xdistance % ydistance) * 10) + (ydistance * 10);
	else if (xdistance < ydistance)
		return ((ydistance % xdistance) * 10) + (xdistance * 10);
	else
		return (xdistance * 10);
}
HexaxonPathFinder::HexaxonPathFinder(){}