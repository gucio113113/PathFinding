
#ifndef HEXAGONPATHFINDER_H
#define HEXAGONPATHFINDER_H

#include "Export.h"
#include "PathFinder.h"

template class API_LIB PathNode<6>;


class API_LIB HexaxonPathFinder : public PathFinder<6>
{
	unsigned int  GetCost(int x1, int y1, int x2, int y2) override;
	public:
	HexaxonPathFinder();
		

};

#endif // !HEXAGONPATHFINDER_H

