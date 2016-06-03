#include "platform.h"



Platform::Platform()
{
}


Platform::~Platform()
{
}

Point Platform::getPoint()
{
	return point;
}

void Platform::setPoint(Point point)
{
	this->point = point;
}

void Platform::draw()
{
	Point endPoint = point;
	endPoint.addX(10);
	drawLine(point, endPoint, )
}
