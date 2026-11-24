#pragma once
#ifndef TRIANGLEPATHFINDER_H
#define TRIANGLEPATHFINDER_H



#include "Export.h"
#include <vector>
#include <queue>

#include "PathNode.h"
#include "PathFinder.h"

template class API_LIB PathNode<3>;

class API_LIB  TrianglePathFinder : public PathFinder<3>
{
	unsigned int  GetCost( int x1,  int y1,  int x2,  int y2) override;
	public:
	TrianglePathFinder();
};




#endif // !TRIANGLEPATHFINDER_H

