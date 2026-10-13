#include "NodeTables.h"

void NodeTables::AddOpen(NodeSearch node)
{
	auto iterator = std::find(Open.begin(), Open.end(), node);
	if (iterator == Open.end())
		Open.push_back(node);
	else if(node < *iterator )
		*iterator = node;
}
void NodeTables::AddToClosed(NodeSearch node)
{
	auto iterator = std::find(Closed.begin(), Closed.end(), node);
	if (iterator == Closed.end())
		Closed.push_back(node);
	else if (node < *iterator)
		*iterator = node;
	
}
void NodeTables::DeleteFromOpenAddToClosed(unsigned int x, unsigned int y)
{
	auto SearchInNode = [&](const NodeSearch& node)->bool {
		return (node.x == x && node.y == y);
		};
	auto OpenIterator=std::find_if(Open.begin(), Open.end(), SearchInNode);
	NodeSearch node;
	if (OpenIterator != Open.end())
	{
		node = *OpenIterator;
		*OpenIterator = Open.back();
		Open.pop_back();
	}
	AddToClosed(node);
}
bool NodeTables::CheckIfClosed(unsigned int x, unsigned int y)
{
	auto iterator = std::find_if(Closed.begin(), Closed.end(), [&](const NodeSearch& node)->bool {return x == node.x && y == node.y; });
	if (iterator != Closed.end()) return true;
	else return false;
}
void NodeTables::GetMinimumCost(NodeSearch& node)
{
	node = Open[0];
	for (NodeSearch iterated : Open)
	{
		if (iterated < node)
			node = iterated;
	}
}
#ifdef DEBUG


void NodeTables::ShowCostTable(unsigned int width,unsigned int height)
{
	std::cout << "Number of Open :" << Open.size()<<"\n";
	std::cout << "Number of Closed :" << Closed.size()<<"\n";

	for (unsigned int y = 0; y < height; y++)
	{
	
		for (unsigned int x = 0; x < width; x++)
		{
			std::string s(4,'-');
		

			auto iteratorClosed = std::find_if(Closed.begin(), Closed.end(), [&](const NodeSearch& node)->bool {return (node.x == x && node.y == y); });
			auto iteratorOpen = std::find_if(Open.begin(), Open.end(), [&](const NodeSearch& node)->bool {return (node.x == x && node.y == y); });
			if (iteratorClosed != Closed.end())
			{
				std::string s1 = std::to_string(iteratorClosed->CostG + iteratorClosed->CostH);
				s.replace(0, s1.length(), s1);
				std::cout << "\033[31m" << s << "\033[0m ";
			}
			else if (iteratorOpen != Open.end())
			{
				std::string s1 = std::to_string(iteratorOpen->CostG + iteratorOpen->CostH);
				s.replace(0, s1.length(), s1);
				std::cout << "\033[32m" << s << "\033[0m ";
			}
			else
			{
				std::cout << s<<" ";
			}
		}
		std::cout << "\n";

	}

}
void  NodeTables::ShowParentTable(unsigned int width, unsigned int height)
{
	for (unsigned int y = 0; y < height; y++)
	{

		for (unsigned int x = 0; x < width; x++)
		{
			std::string s(4, '-');

			
			auto iteratorClosed = std::find_if(Closed.begin(), Closed.end(), [&](const NodeSearch& node)->bool {return (node.x == x && node.y == y); });
			auto iteratorOpen = std::find_if(Open.begin(), Open.end(), [&](const NodeSearch& node)->bool {return (node.x == x && node.y == y); });
			
			if ( iteratorClosed != Closed.end())
			{
				std::string s1 = std::to_string(iteratorOpen->ParentId);
				if (s1.length() >= 4)
					s.replace(0, 4, s1);
				else s.replace(0, s1.length(), s1);
				std::cout << "\033[31m" << s << "\033[0m ";
			}
			else if ( iteratorOpen != Open.end())
			{
				std::string s1 = std::to_string(iteratorOpen->ParentId);
				if (s1.length() >= 4)
					s.replace(0, 4, s1);
				else s.replace(0, s1.length(), s1);
				std::cout << "\033[32m" << s << "\033[0m ";
			}
			else
			{
				std::cout << s << " ";
			}
		}
		std::cout << "\n";

	}
}


#endif // DEBUG


std::vector<NodeSearch> NodeTables::GetAllNodes()
{
	std::vector<NodeSearch> nodes;
	nodes.reserve(Open.size() + Closed.size());
	nodes = Open;
	for (NodeSearch& closed : Closed)
	{
		auto iterator = std::find(Open.begin(), Open.end(), closed);
		if (iterator == Open.end())
			nodes.push_back(closed);
		else if (closed < *iterator)
			*iterator = closed;

	}
	return nodes;
}