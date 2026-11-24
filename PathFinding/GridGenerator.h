#pragma once
#ifndef GRIDGENERATOR_H
#define GRIDGENERATOR_H

#include "Export.h"
#include "PathNode.h"
#include "Grid.h"
#include <vector>
#include "PathNodeTable.h"





class API_LIB GridGenerator : public Grid
{

	
public:
	GridGenerator();

	TriangleNodeTable GenerateTriangleGrid(std::vector<unsigned int> * TableOfCost=nullptr);
	SquareNodeTable GenerateSquareGrid(std::vector<unsigned int>* TableOfCost=nullptr);
	SquareSlantNodeTable GenerateSquareSlantGrid(std::vector<unsigned int>* TableOfCost=nullptr);
	HexagonNodeTable GenerateHexagonGrid(std::vector<unsigned int>* TableOfCost=nullptr);
};





#endif