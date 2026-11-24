#ifndef PATHFINDER_H
#define PATHFINDER_H



#include "NodeSearch.h"
#include "PathNode.h"
#include "Grid.h"
#include <queue>
#include <stack>
#include "NodeTables.h"
#include "PathNodeTable.h"

#ifdef DEBUG
#include <cstdlib>
#include <stdio.h>
#endif // DEBUG



struct Vector2i
{
	int x;
	int y;
	Vector2i(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};






template<unsigned int MaxNeighborCount>
class API_LIB PathFinder : public Grid
{
protected:
	PathNodeTable<MaxNeighborCount> * Table=nullptr;

	virtual unsigned int GetCost(int x1, int y1, int x2, int y2);
	
	bool Passable(unsigned int index);
	
	bool Passable(unsigned int x, unsigned int y);
	

	bool SearchforPath(int xbegin, int ybegin, int xend, int yend, std::vector<NodeSearch>& searchedNodes);
	

public:
	PathFinder();
	bool SetNodeTable(PathNodeTable<MaxNeighborCount> * tablenodes);
	
	std::stack<Vector2i> GetPath(int xbeign, int ybegin, int xend, int yend);
#ifdef DEBUG
	void ShowPath(std::stack<Vector2i> Path);
#endif // DEBUG

	};

#endif // !PATHFINDER_H