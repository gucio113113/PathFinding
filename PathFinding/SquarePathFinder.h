#pragma once
#ifndef SQUAREPATHFINDER_H
#define SQUAREPATHFINDER_H

#include "Export.h"
#include "PathFinder.h"
template class API_LIB PathNode<4>;

class API_LIB SquarePathFinder : public PathFinder<4>
{
	unsigned int GetCost(int x1, int y1, int x2, int y2) override;
	public:
	SquarePathFinder();
};

#endif // !SQUAREPATHFINDER_H

