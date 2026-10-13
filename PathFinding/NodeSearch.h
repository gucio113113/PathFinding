
#ifndef NODESEARCH_H
#define NODESEARCH_H


#include <limits>



#ifndef UDENTIFIED
#define UDENTIFIED std::numeric_limits<unsigned int>::max()
#endif
struct NodeSearch
{
	unsigned int x;
	unsigned int y;
	unsigned int ParentId;
	unsigned int CostG;
	unsigned int CostH;

	NodeSearch(unsigned int x=0, unsigned int y=0, unsigned int ParentId=UDENTIFIED,unsigned int CostG=UDENTIFIED,unsigned int CostH=UDENTIFIED);

	bool operator==(const NodeSearch& node) const;
	NodeSearch operator = (const NodeSearch& node);
	bool operator < (const NodeSearch& node) const;


};
#endif // !NODESEARCH_H