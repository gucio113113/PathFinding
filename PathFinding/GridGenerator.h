#pragma once
#ifndef GRIDGENERATOR_H
#define GRIDGENERATOR_H

#include "Export.h"
#include "PathNode.h"
#include "Grid.h"
#include <vector>





class API_LIB GridGenerator : public Grid
{

	
public:
	GridGenerator();

	std::vector<TriangleNode> GenerateTriangleGrid(std::vector<unsigned int> * TableOfCost=nullptr);
	std::vector<SquareNode> GenerateSquareGrid(std::vector<unsigned int>* TableOfCost=nullptr);
	std::vector<SquareSlantNode> GenerateSquareSlantGrid(std::vector<unsigned int>* TableOfCost=nullptr);
	std::vector<HexagonNode> GenerateHexagonGrid(std::vector<unsigned int>* TableOfCost=nullptr);
};

#ifdef DEBUG
template<unsigned int MaxNeighborCount>
void ShowNodeConnections(std::vector<PathNode<MaxNeighborCount>>& Nodes, unsigned int width, unsigned int height)
{
	for (unsigned int y = 0; y < height; y++)
	{

		for (unsigned int x = 0; x < width; x++)
		{
			std::cout << "\033[31m" << Nodes[x + (y * width)].neighborcount << "\033[0m ";
		}
		std::cout << "\n";
	}
}
#endif // DEBUG




#endif // !GRIDGENERATOR_H




