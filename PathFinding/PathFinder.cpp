#ifdef EXPORT_H
#include "PathFinder.h"
#include "Export.h"
template<unsigned int MaxNeighborCount>
 unsigned int PathFinder<MaxNeighborCount>::GetCost(int x1, int y1, int x2, int y2)
{
	return 0;
}
 template<unsigned int MaxNeighborCount>
bool  PathFinder<MaxNeighborCount>::Passable(unsigned int index)
{
	return (this->checkIndex(getX(index), getY(index)) == true && Table->GetCost(getX(index),getY(index)) != UDENTIFIED);
}
template<unsigned int MaxNeighborCount>
bool PathFinder<MaxNeighborCount>::Passable(unsigned int x, unsigned int y)
{
	return (this->checkIndex(x, y) == true && Table->GetCost(x,y) != UDENTIFIED);
}
template<unsigned int MaxNeighborCount>
bool PathFinder<MaxNeighborCount>::SearchforPath(int xbegin, int ybegin, int xend, int yend, std::vector<NodeSearch>& searchedNodes)
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
			//Bellow is code for NodeSearch
			//It Gets Minum Cost Node From Open Nodes
			if (nodetables.IfStillOpenNodes() == true)
				nodetables.GetMinimumCost(CurrentNode);

			//When Minimum Cost was selected then set new Current Pathnode
			//which then every avaliable neigbors was cchecked if it can be moved
			// then CurrentNode was mark as Closed and everty avaliable neigbor aas Open
			//

			if (Passable(CurrentNode.x, CurrentNode.y) == true)
				CurrentPathNode = this->Table->GetPathNode(CurrentNode.x,CurrentNode.y);
			for (unsigned int index = 0; index < CurrentPathNode.neighborcount; index++)
			{
				NodeSearch NewNode;
				unsigned int IndexInTable = CurrentPathNode.neighbors[index];
				PathNode<MaxNeighborCount> NewPathNode = this->Table->GetPathNode(index);

				// New Nodes is checked and values of cost assign to then then they are Added to List of OpenNodes

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
					NewNode.CostH = (GetCost(CurrentNode.x, CurrentNode.y, NewNode.x, NewNode.y) * NewPathNode.cost) + CurrentNode.CostH;
					nodetables.AddToClosed(NewNode);
				}
				if (NewNode.x == xend && NewNode.y == yend)
				{
					Pathfinded = true;
					break;
				}

			}
			nodetables.DeleteFromOpenAddToClosed(CurrentNode.x, CurrentNode.y);
			// if one of the newly added Open Nodes was a destination then first part of algorythm is ended
			if (Pathfinded == true) break;
		}
		if (Pathfinded == true)
			searchedNodes = nodetables.GetAllNodes();
#ifdef DEBUG
		nodetables.ShowCostTable(_width, _height);
		nodetables.ShowParentTable(_width, _height);
#endif // DEBUG

		// Return the status if the algorythm reached to their destination
		return Pathfinded;
	}
}

template<unsigned int MaxNeighborCount>
	PathFinder<MaxNeighborCount>::PathFinder() {}
template<unsigned int MaxNeighborCount>
	bool PathFinder<MaxNeighborCount>::SetNodeTable(PathNodeTable<MaxNeighborCount>* tablenodes)
	{
		if (tablenodes != nullptr)
		{
			this->Table = tablenodes;
			this->_width = tablenodes->GetWidth();
			this->_height = tablenodes->GetHeight();
			return true;
		}
		else return false;
		{
#ifdef DEBUG
			std::cout << "Node table can't be initialized \n";
	#endif // DEBUG



			return false;
		}
	}




template<unsigned int MaxNeighborCount>
	std::stack<Vector2i> PathFinder<MaxNeighborCount>::GetPath(int xbeign, int ybegin, int xend, int yend)
	{
		if (this->Table == nullptr)
		{
#ifdef DEBUG
			std::cout << "Path can't be find because Nodes is not initialized \n ";
#endif // DEBUG


			return {};
		}
		std::vector<NodeSearch> searchNodes;


		// Get a node from ParentId
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
		//Selects first node
		auto FindEnd = [&](NodeSearch& node)->bool
			{
				auto lambda = [&](const NodeSearch& n)->bool
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
			std::stack<Vector2i> Path;

			while (node.ParentId != UDENTIFIED)
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
			ShowPath(Path);

			return Path;
		}
		return {};
	}
#ifdef DEBUG
template<unsigned int MaxNeighborCount>
	void PathFinder<MaxNeighborCount>::ShowPath(std::stack<Vector2i> Path)
	{
		std::vector<Vector2i> Table;
		Table.reserve(Path.size());
		while (Path.empty() == false)
		{
			Table.push_back(Path.top());
			Path.pop();
		}



		auto FindPath = [&](unsigned int x, unsigned int y)->bool
			{

				auto Searching = [&](const Vector2i v)->bool
					{
						return (v.x == x && v.y == y);
					};
				return (std::find_if(Table.begin(), Table.end(), Searching) != Table.end());

			};



		for (unsigned int y = 0; y < _height; y++)
		{
			for (unsigned int x = 0; x < _width; x++)
			{
				if (FindPath(x, y) == true)
					std::cout << "\033[34mP\033[0m";
				else std::cout << "-";
			}
			std::cout << "\n";
		}
	}
#endif // DEBUG

template class API_LIB PathFinder<4>;
template class API_LIB PathFinder<3>;
template class API_LIB PathFinder<6>;
template class API_LIB PathFinder<8>;
#endif // EXPORT_H

