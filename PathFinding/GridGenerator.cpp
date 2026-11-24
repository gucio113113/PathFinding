#include "GridGenerator.h"

GridGenerator::GridGenerator(){}

TriangleNodeTable GridGenerator::GenerateTriangleGrid(std::vector<unsigned int>* TableOfCost)
{
	TriangleNodeTable grid(_width,_height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			 TriangleNode & node = grid.table[getIndex(x, y)];
			 if (TableOfCost != nullptr && TableOfCost->size() == grid.table.size())
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
SquareNodeTable GridGenerator::GenerateSquareGrid(std::vector<unsigned int>* TableOfCost)
{
	SquareNodeTable grid(_width,_height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			SquareNode& node = grid.table[getIndex(x, y)];
			if (TableOfCost != nullptr && TableOfCost->size() == grid.table.size())
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
SquareSlantNodeTable GridGenerator::GenerateSquareSlantGrid(std::vector<unsigned int>* TableOfCost)
{
	SquareSlantNodeTable grid(_width, _height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			SquareSlantNode& node = grid.table[getIndex(x, y)];
			if (TableOfCost != nullptr && TableOfCost->size() == grid.table.size())
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
HexagonNodeTable GridGenerator::GenerateHexagonGrid(std::vector<unsigned int>* TableOfCost)
{
	HexagonNodeTable grid(_width , _height);
	for (unsigned int y = 0; y < _height; y++)
	{
		for (unsigned int x = 0; x < _width; x++)
		{
			HexagonNode & node = grid.table[getIndex(x, y)];
			if (TableOfCost != nullptr && TableOfCost->size() == grid.table.size())
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
