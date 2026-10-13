#ifndef PATHFINDER_H
#define PATHFINDER_H


#include "Debug.h"
#include "NodeSearch.h"
#include "PathNode.h"
#include "Grid.h"
#include <queue>
#include <stack>
#include "NodeTables.h"

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
class PathFinder : public Grid
{
protected:
	std::vector<PathNode<MaxNeighborCount>> Table;

	virtual unsigned int GetCost(int x1, int y1, int x2, int y2)
	{
		return 0;
	}
	bool  Passable(unsigned int index)
	{
		return (this->checkIndex(getX(index), getY(index)) == true && Table[index].cost != UDENTIFIED);
	}
	bool Passable(unsigned int x, unsigned int y)
	{
		return (this->checkIndex(x, y) == true && Table[getIndex(x, y)].cost != UDENTIFIED);
	}

	bool SearchforPath(int xbegin, int ybegin, int xend, int yend, std::vector<NodeSearch>& searchedNodes)
	{
		if (Passable(xbegin, ybegin) == false || Passable(xend, yend) == false) return false;
		else
		{
			//Current Triangle
			PathNode<MaxNeighborCount> CurrentPathNode;
			//Current Mod
			NodeSearch CurrentNode;
			CurrentNode.x = xbegin;
			CurrentNode.y = ybegin;
			CurrentNode.CostH = 0;
			CurrentNode.CostG = GetCost(xbegin, ybegin, xend, yend);
			CurrentNode.ParentId = UDENTIFIED;

			bool Pathfinded = false;
			NodeTables nodetables;

			nodetables.AddOpen(CurrentNode);

			while (nodetables.IfStillOpenNodes() == true && Pathfinded == false)
			{
				if (nodetables.IfStillOpenNodes() == true)
					nodetables.GetMinimumCost(CurrentNode);
				if(Passable(CurrentNode.x,CurrentNode.y)==true)
				CurrentPathNode = Table[getIndex(CurrentNode.x, CurrentNode.y)];
				for (unsigned int index = 0; index < CurrentPathNode.neighborcount; index++)
				{
					NodeSearch NewNode;
					unsigned int IndexInTable = CurrentPathNode.neighbors[index];
					PathNode<MaxNeighborCount> NewPathNode = this->Table[IndexInTable];

					

					if (Passable(IndexInTable) == true && nodetables.CheckIfClosed(getX(IndexInTable), getY(IndexInTable)) == false)
					{

						NewNode.ParentId = getIndex(CurrentNode.x, CurrentNode.y);
						NewNode.x = getX(IndexInTable);
						NewNode.y = getY(IndexInTable);
						NewNode.CostG = GetCost(NewNode.x, NewNode.y, xend, yend);
						NewNode.CostH = (GetCost(CurrentNode.x, CurrentNode.y, NewNode.x, NewNode.y) * NewPathNode.cost) + CurrentNode.CostH;
						nodetables.AddOpen(NewNode);
					}
					else if (checkIndex(getX(IndexInTable), getY(IndexInTable)) == true && nodetables.CheckIfClosed(getX(IndexInTable), getY(IndexInTable)) == false)
					{
						NewNode.ParentId = getIndex(CurrentNode.x, CurrentNode.y);
						NewNode.x = getX(IndexInTable);
						NewNode.y = getY(IndexInTable);
						NewNode.CostG = GetCost(NewNode.x, NewNode.y, xend, yend);
						NewNode.CostH = (GetCost(CurrentNode.x, CurrentNode.y, NewNode.x, NewNode.y) * NewPathNode.cost) +CurrentNode.CostH;
						nodetables.AddToClosed(NewNode);
					}
					if (NewNode.x == xend && NewNode.y == yend)
					{
						Pathfinded = true;
						break;
					}

				}
				nodetables.DeleteFromOpenAddToClosed(CurrentNode.x, CurrentNode.y);
				if (Pathfinded == true) break;
			}
			if (Pathfinded == true)
				searchedNodes = nodetables.GetAllNodes();
			nodetables.ShowCostTable(_width, _height);
			nodetables.ShowParentTable(_width, _height);

			return Pathfinded;
		}
	}

public:
	PathFinder(){}
	bool SetNodeTable(std::vector<PathNode<MaxNeighborCount>>& tablenodes)
	{
		if (this->_height * this->_width == tablenodes.size())
		{
			this->Table = tablenodes;
			return true;
		}
		else return false;
	}





	std::stack<Vector2i> GetPath(int xbeign, int ybegin, int xend, int yend)
	{
		std::vector<NodeSearch> searchNodes;
		


		auto FindParentNode = [&](NodeSearch& node)
			{
				

				auto lambda = [&](const NodeSearch& n)->bool
					{
						return (getX(node.ParentId) == n.x && getY(node.ParentId) == n.y);
					};


				auto iterator = std::find_if(searchNodes.begin(), searchNodes.end(), lambda);
				
				if (iterator != searchNodes.end())
					node = *iterator;
				
			};
		auto FindEnd = [&](NodeSearch& node)->bool
			{
				auto lambda= [&](const NodeSearch& n)->bool
					{
						return (xend == n.x && yend == n.y);
					};


				auto iterator = std::find_if(searchNodes.begin(), searchNodes.end(), lambda);
				
				if (iterator != searchNodes.end())
				{
					node = *iterator;
					return true;
				}
				else return false;
			};

		

		if (SearchforPath(xbeign, ybegin, xend, yend, searchNodes) == true)
		{
			NodeSearch node;
			FindEnd(node);
			std::cout << node.x << ".x " << node.y << " .y\n";
			std::stack<Vector2i> Path;
			
			while (node.ParentId!=UDENTIFIED)
			{
				
#ifdef DEBUG
				std::cout << "Vector : " << node.x << ".x " << node.y << ".y \n";
#endif // DEBUG
				Path.push({ static_cast<int>(node.x),static_cast<int>(node.y) });
				FindParentNode(node);
			}
			if (node.ParentId == UDENTIFIED)
			{
				Path.push({ static_cast<int>(node.x),static_cast<int>(node.y) });
			}
			
			return Path;
		}
		return {};
	}
	#ifdef DEBUG
	void ShowPath(std::stack<Vector2i> Path)
	{
		std::vector<Vector2i> Table;
		Table.reserve(Path.size());
		while (Path.empty()==false )
		{
			Table.push_back(Path.top());
			Path.pop();
		}



		auto FindPath = [&](unsigned int x,unsigned int y)->bool
			{

				auto Searching = [&](const Vector2i v)->bool
					{
						return (v.x == x && v.y == y);
					};
				return ( std::find_if(Table.begin(), Table.end(), Searching)!=Table.end());
		
			};



		for (unsigned int y = 0; y < _height; y++)
		{
			for (unsigned int x = 0; x < _width; x++)
			{
				if (FindPath(x, y) == true)
					std::cout << "\033[34mP \033[0m";
				else std::cout << "-";
			}
			std::cout << "\n";
		}
	}
	#endif // DEBUG








};






#endif // !PATHFINDER_H