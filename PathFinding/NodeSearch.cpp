#include "NodeSearch.h"


NodeSearch::NodeSearch(unsigned int x, unsigned int y, unsigned int ParentId, unsigned int CostG, unsigned int CostH)
{
	this->x = x;
	this->y = y;
	this->ParentId = ParentId;
	this->CostG = CostG;
	this->CostH = CostH;
}

bool NodeSearch::operator == (const NodeSearch & node) const
{
	return (this->x == node.x && this->y == node.y);
}
NodeSearch NodeSearch::operator = (const NodeSearch & node)
{
	this->x = node.x;
	this->y = node.y;
	this->ParentId = node.ParentId;
	this->CostG = node.CostG;
	this->CostH = node.CostH;

	return *this;
}
bool NodeSearch::operator < (const NodeSearch& node) const
{
	if (this->CostG + this->CostH < node.CostG + node.CostH)
	{
		return true;
	}
	else if (this->CostG + this->CostH == node.CostG + node.CostH)
	{
		return (this->CostH < node.CostH || this->CostG < node.CostG);
	}
	else return false;
}