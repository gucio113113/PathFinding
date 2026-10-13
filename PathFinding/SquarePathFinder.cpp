#include "SquarePathFinder.h"
#include "NodeTables.h"
unsigned int SquarePathFinder::GetCost(int x1, int y1, int x2, int y2)
{
	return static_cast<unsigned int>(abs(x2 - x1) + abs(y2 - y1));
}
SquarePathFinder::SquarePathFinder(){}
