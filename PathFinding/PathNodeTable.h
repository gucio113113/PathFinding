#pragma once

#ifndef PATHNODETABLE_H
#define PATHNODETABLE_H

#include "PathNode.h"
#include <vector>
#include "Grid.h"

#ifdef DEBUG
#include <string>
#endif // DEBUG



#ifndef UDENTIFIED
#define UDENTIFIED std::numeric_limits<unsigned int>::max()
#endif


template<unsigned int MaxNeighborCount>
class PathNodeTable :  public Grid
{
	std::vector<PathNode<MaxNeighborCount>> table;
public:
	friend class GridGenerator;

	PathNodeTable(unsigned int width=0, unsigned int height=0);
	void SetCost(unsigned int x,unsigned int y,unsigned int cost);

	void SetUnPassable(unsigned int x, unsigned int y);

	unsigned int GetCost(unsigned int x, unsigned int y);
	unsigned int GetNumberOfNeighbors(unsigned int x, unsigned int y);
	NeigborId GetNeighbor(unsigned int x, unsigned int y,unsigned int neighbor);
	
	PathNode<MaxNeighborCount> GetPathNode(unsigned int x,unsigned int y);
	PathNode<MaxNeighborCount> GetPathNode(unsigned int index);


	using Grid::SetHeight;
	using Grid::SetWidth;
 
	PathNodeTable<MaxNeighborCount> operator= (PathNodeTable<MaxNeighborCount> &table);

#ifdef DEBUG


	void ShowCost();
	void ShowNumberNeigbors();
#endif // DEBUG


};


typedef PathNodeTable<3> TriangleNodeTable;
typedef PathNodeTable<4> SquareNodeTable;
typedef PathNodeTable<6> HexagonNodeTable;
typedef PathNodeTable<8> SquareSlantNodeTable;

#endif // PATHNODETABLE_H

