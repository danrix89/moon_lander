/*************************************************************
* File: lander.cpp
* Author: Dan Rix
*
* Description: Contains a description of the lander class.
*
*************************************************************/

#ifndef PLATFORM_H
#define PLATFORM_H

#include "uiDraw.h"
#include "point.h"

class Platform
{
private:
	Point point;

public:
	Platform()
	{

	}

	// Getters
	Point getPoint();

	// Setters
	void setPoint(Point point);

	// Others
	void draw();
};

#endif /* PLATFORM_H */