// PathFinding.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#ifndef EXPORT_H

#include "Export.h"




#include <iostream>
#include "GridGenerator.h"
#include "SquareSlantPathFinder.h"

int main()
{
    GridGenerator generator;
    generator.SetWidth(10);
    generator.SetHeight(10);

    SquareSlantPathFinder pathfinder;

    pathfinder.SetHeight(10);
    pathfinder.SetWidth(10);


    std::vector<PathNode<8>>   grid = generator.GenerateSquareSlantGrid();

    pathfinder.SetNodeTable(grid);

    ShowNodeConnections(grid, 10, 10);

    pathfinder.SetNodeTable(grid);

    std::stack<Vector2i> Path= pathfinder.GetPath(1, 1, 1, 7);
    pathfinder.ShowPath(Path);
    
}
#endif // EXPORT_DECL
