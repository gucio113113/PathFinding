#include "Grid.h"
unsigned int Grid::getIndex(unsigned int x, unsigned int y)
{
	return x + (y * _width);
}
unsigned int Grid::getX(unsigned int index)
{
	return index % _width;
}
unsigned int Grid::getY(unsigned int index)
{
	return index / _width;
}
bool Grid::checkIndex(int x, int y)
{
	return (x >= 0 && y >= 0 && x < _width && y < _height);
}
void Grid::SetWidth(unsigned int width)
{
	this->_width = width;
}
void Grid::SetHeight(unsigned int height)
{
	this->_height = height;
}
unsigned int Grid::GetWidth()
{
	return _width;
}
unsigned int Grid::GetHeight()
{
	return _height;
}
