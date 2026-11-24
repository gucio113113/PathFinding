#pragma once
#ifndef SQUARESLANTPATHFINDER_H
#define SQUARESLANTPATHFINDER_H

#include "Export.h"
#include "PathFinder.h"

template class API_LIB PathNode<8>;

class API_LIB  SquareSlantPathFinder : public PathFinder<8>
{
	unsigned int GetCost(int x1, int y1, int x2, int y2) override;
	public:
	SquareSlantPathFinder();
};
#endif // !SQUARESLANTPATHFINDER_H
