#include "GridGenerator.h"

GridGenerator::GridGenerator(){}

std::vector<TriangleNode> GridGenerator::GenerateTriangleGrid(std::vector<unsigned int>* TableOfCost)
{
	std::vector<TriangleNode> grid(_width* _height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			 TriangleNode & node = grid[getIndex(x, y)];
			 if (TableOfCost != nullptr && TableOfCost->size() == grid.size())
				 node.cost = TableOfCost->at(getIndex(x,y));

				if (checkIndex(x - 1, y) == true)
				{
					node.neighbors[node.neighborcount] = getIndex(x - 1, y);
					node.neighborcount++;
				}
				if (checkIndex(x + 1, y) == true)
				{
					node.neighbors[node.neighborcount] = getIndex(x + 1, y);
					node.neighborcount++;
				}
				if (x*y % 2 == 0 && checkIndex(x, y + 1) == true)
				{
					node.neighbors[node.neighborcount] = getIndex(x, y+1);
					node.neighborcount++;
				}
				else if (checkIndex(x,y-1)==true )
				{
					node.neighbors[node.neighborcount] = getIndex(x, y - 1);
					node.neighborcount++;
				}
				
		}
	}
	return grid;
}
std::vector<SquareNode> GridGenerator::GenerateSquareGrid(std::vector<unsigned int>* TableOfCost)
{
	std::vector<SquareNode> grid(_width * _height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			SquareNode& node = grid[getIndex(x, y)];
			if (TableOfCost != nullptr && TableOfCost->size() == grid.size())
				node.cost = TableOfCost->at(getIndex(x, y));

			if (checkIndex(x, y-1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x, y - 1);
				node.neighborcount++;
			}
			if (checkIndex(x + 1, y) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x + 1, y);
				node.neighborcount++;
			}
			if (checkIndex(x, y + 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x, y + 1);
				node.neighborcount++;
			}
			if (checkIndex(x - 1, y) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x-1, y);
				node.neighborcount++;
			}

		}
	}
	return grid;
}
std::vector<SquareSlantNode> GridGenerator::GenerateSquareSlantGrid(std::vector<unsigned int>* TableOfCost)
{
	std::vector<SquareSlantNode> grid(_width * _height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			SquareSlantNode& node = grid[getIndex(x, y)];
			if (TableOfCost != nullptr && TableOfCost->size() == grid.size())
				node.cost = TableOfCost->at(getIndex(x, y));
			if (checkIndex(x, y - 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x, y - 1);
				node.neighborcount++;
			}
			if (checkIndex(x + 1, y - 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x + 1, y - 1);
				node.neighborcount++;
			}
			if (checkIndex(x + 1, y) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x + 1, y);
				node.neighborcount++;
			}
			if (checkIndex(x + 1, y + 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x + 1, y + 1);
				node.neighborcount++;
			}
			if (checkIndex(x, y + 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x, y + 1);
				node.neighborcount++;
			}
			if (checkIndex(x - 1, y + 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x - 1, y + 1);
				node.neighborcount++;
			}
			if (checkIndex(x - 1, y) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x - 1, y);
				node.neighborcount++;
			}
			if (checkIndex(x - 1, y - 1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x - 1, y -1);
				node.neighborcount++;
			}

		}
	}
	return grid;
}
std::vector<HexagonNode> GridGenerator::GenerateHexagonGrid(std::vector<unsigned int>* TableOfCost)
{
	std::vector<HexagonNode> grid(_width * _height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			HexagonNode & node = grid[getIndex(x, y)];
			if (TableOfCost != nullptr && TableOfCost->size() == grid.size())
				node.cost = TableOfCost->at(getIndex(x, y));
			if (checkIndex(x, y - 1) == true)
			{
				node.neighbors[node.neighborcount];
				node.neighborcount++;
			}
			if (checkIndex(x+1, y) == true)
			{
				node.neighbors[node.neighborcount]=getIndex(x+1,y);
				node.neighborcount++;
			}
			if (checkIndex(x+1, y+1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x+1, y+1);
				node.neighborcount++;
			}
			if (checkIndex(x, y + 1) == true)
			{
				node.neighbors[node.neighborcount]=getIndex(x,y+1);
				node.neighborcount++;
			}
			if (checkIndex(x - 1, y+1) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x - 1, y+1);
				node.neighborcount++;
			}
			if (checkIndex(x - 1, y) == true)
			{
				node.neighbors[node.neighborcount] = getIndex(x - 1, y);
				node.neighborcount++;
			}
			

		}

	}
	return grid;
}
