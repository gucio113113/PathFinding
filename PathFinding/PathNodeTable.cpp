#include "PathNodeTable.h"
template<unsigned int MaxNeighborCount>
PathNodeTable<MaxNeighborCount>::PathNodeTable(unsigned int width, unsigned int height)
{
	this->_width = width;
	this->_height = height;
	this->table.resize(_width * _height);
}
template<unsigned int MaxNeighborCount>
void PathNodeTable<MaxNeighborCount>::SetCost(unsigned int x, unsigned int y, unsigned int cost)
{	
	if (this->table.empty() == false && checkIndex(x, y) == true)
	{
		this->table[getIndex(x, y)].cost = cost;
	}
}
template<unsigned int MaxNeighborCount>
void PathNodeTable<MaxNeighborCount>::SetUnPassable(unsigned int x, unsigned int y)
{
	SetCost(x,y,UDENTIFIED);
}
template<unsigned int MaxNeighborCount>
unsigned int PathNodeTable<MaxNeighborCount>::GetCost(unsigned int x, unsigned int y)
{
	if (this->table.empty() == false && checkIndex(x, y) == true)
	{
		return this->table[getIndex(x, y)].cost;
	}
	return UDENTIFIED;
}
template<unsigned int MaxNeighborCount>
unsigned int PathNodeTable<MaxNeighborCount>::GetNumberOfNeighbors(unsigned int x, unsigned int y)
{
	if (this->table.empty() == false && checkIndex(x, y) == true)
	{
		return this->table[getIndex(x, y)].neighborcount;
	}
	return UDENTIFIED;
}
template<unsigned int MaxNeighborCount>
NeigborId PathNodeTable<MaxNeighborCount>::GetNeighbor(unsigned int x, unsigned int y, unsigned int neighbor)
{
	if (this->table.empty() == false && checkIndex(x, y) == true && this->table[getIndex(x, y)].neighborcount < neighbor)
	{
		return this->table[getIndex(x, y)].neighbors[neighbor];
	}
	else return UDENTIFIED;
}
template<unsigned int MaxNeighborCount>
PathNode<MaxNeighborCount> PathNodeTable<MaxNeighborCount>::GetPathNode(unsigned int x, unsigned int y)
{
	if (this->table.empty()==false && checkIndex(x, y) == true)
	{
		return this->table[getIndex(x, y)];
	}
	else return PathNode<MaxNeighborCount>();
}
template<unsigned int MaxNeighborCount>
PathNode<MaxNeighborCount> PathNodeTable<MaxNeighborCount>::GetPathNode(unsigned int index)
	{
		return GetPathNode(getX(index), getY(index));
	}
template<unsigned int MaxNeighborCount>
PathNodeTable<MaxNeighborCount> PathNodeTable<MaxNeighborCount>::operator= (PathNodeTable<MaxNeighborCount>& table)
{
	this->SetWidth(table.GetWidth());
	this->SetHeight(table.GetHeight());


	this->table.reserve(table.table.size());
	this->table.assign(table.table.begin(),table.table.end());
	this->table.shrink_to_fit();

	return *this;
}
#ifdef DEBUG
template<unsigned int MaxNeighborCount>
void PathNodeTable<MaxNeighborCount>::ShowCost()
{
	std::cout << "PathNodeTable Cost :\n";
	for (unsigned int y = 0; y < _height; y++)
	{
		std::cout << "\t";
		for (unsigned int x = 0; x < _width; x++)
		{
			std::string s(4, '-');
			std::string convert = std::to_string(table[getIndex(x, y)].cost);
			if (table[getIndex(x, y)].cost == UDENTIFIED) convert = "INFI";
			s.replace(0, convert.length(), convert);
			std::cout << s << " ";
		}
		std::cout << "\n";

	}

}
template<unsigned int MaxNeighborCount>
void PathNodeTable<MaxNeighborCount>::ShowNumberNeigbors()
{
	std::cout << "PathNodeTable Neighbors :\n";
	for (unsigned int y = 0; y < _height; y++)
	{
		std::cout << "\t";
		for (unsigned int x = 0; x < _width; x++)
		{
			std::string s(4, '-');
			std::string convert = std::to_string(table[getIndex(x, y)].neighborcount);
			s.replace(0, convert.length(), convert);
			std::cout << s << " ";
		}
		std::cout << "\n";

	}

}
#endif // DEBUG


#ifdef EXPORT_H

template class API_LIB PathNodeTable<3>;
template class API_LIB PathNodeTable<4>;
template class API_LIB PathNodeTable<6>;
template class API_LIB PathNodeTable<8>;

#endif // EXPORT_H