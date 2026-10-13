#pragma once

#ifndef PATHNODE_H

#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif // DEBUG


typedef unsigned int NeigborId;


template<unsigned int MaxNeighborCount>
struct PathNode
{
	NeigborId neighbors[MaxNeighborCount];
	unsigned int neighborcount;
	unsigned int cost;
	
	PathNode(unsigned int cost=1)
	{
		this->cost=cost;
		this->neighborcount = 0;
	}
};

typedef PathNode<6> HexagonNode;
typedef PathNode<3> TriangleNode;
typedef PathNode<4> SquareNode;
typedef PathNode<8> SquareSlantNode;


#endif // PATHNODE_H