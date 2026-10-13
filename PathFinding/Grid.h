#pragma once
#ifndef GRID_H
#define GRID_H



class Grid
{
protected:
	unsigned int _width;
	unsigned int _height;


	unsigned int getIndex(unsigned int x, unsigned int y);

	unsigned int getX(unsigned int index);
	unsigned int getY(unsigned int index);

	bool checkIndex(int x, int y);
public:
	void SetWidth(unsigned int width);
	void SetHeight(unsigned int height);


};
#endif // GRID_H

