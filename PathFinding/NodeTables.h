#pragma once

#include <vector>
#include <algorithm>
#include "NodeSearch.h"


#ifdef DEBUG
#include <iostream>
#include <string>
#endif // DEBUG


class NodeTables
{
	std::vector<NodeSearch> Open;
	std::vector<NodeSearch> Closed;

		
public:

	inline bool IfStillOpenNodes() { return !Open.empty(); }

	//void Reserve();
	void AddOpen(NodeSearch node);
	void AddToClosed(NodeSearch node);
	void DeleteFromOpenAddToClosed(unsigned int x,unsigned int y);
	bool CheckIfClosed(unsigned int x,unsigned int y);
	void GetMinimumCost(NodeSearch &node);

#ifdef DEBUG

	void ShowNumberOfOpen();
	void ShowNumberOfClosed();

	void ShowCostTable(unsigned int width, unsigned int height);
	void ShowParentTable(unsigned int width, unsigned int height);
#endif // DEBUG
	std::vector<NodeSearch> GetAllNodes();









};

