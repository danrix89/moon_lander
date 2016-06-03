/*************************************************************
* File: laser.cpp
* Author: Dan Rix
*
* Description: A representation of a moon alien's laser which
*              can follow a target.
*
*************************************************************/

#include "laser.h"
#include "lander.h"
#include "my_math.h"

#define LASER_SPEED 20
#define LASER_TOLERANCE 10

using namespace std;

// Constructors
Laser::Laser()
{
}

Laser::Laser(Point start, Point target)
{
	this->start = start;
	this->target = target;
	setPoint(start);
	hasHitObject = false;
}

// Getters
Point Laser::getPoint()
{
	return point;
}

bool Laser::getHasHitObject()
{
	return hasHitObject;
}

// Setters
void Laser::setPoint(Point point)
{
	this->point = point;
}

void Laser::setHasHitObject(bool hit)
{
	this->hasHitObject = hit;
}

// Others
/***************************************
* LASER :: DRAW
* Draws a dot to represent the Laser.
***************************************/
void Laser::draw()
{
	if (!hasHitObject)
	{
		drawLaser(point);
	}
}

/***************************************
* LASER :: ADVANCE
* Advances the Laser to it's next position.
***************************************/
void Laser::advance()
{
	point.setX(nextX());
	point.setY(nextY());
}

/***************************************
* LASER :: NEXT X
* Gets the next x value that the laser
* is expected to be at.
***************************************/
float Laser::nextX()
{
	return start.getX() + (nextPercentageTravelled() * run(start.getX(), target.getX()));
}

/***************************************
* LASER :: NEXT Y
* Gets the next y value that the laser
* is expected to be at.
***************************************/
float Laser::nextY()
{
	return start.getY() + (nextPercentageTravelled() * rise(start.getY(), target.getY()));
}

/***************************************
* LASER :: NEXT PERCENTAGE TRAVELLED
* The expected percentage of the distance
* traveled from the 'start' point to the
* 'target' point.
* Simply increments the current distance
* by one unit.
***************************************/
float Laser::nextPercentageTravelled()
{
	return (distance(start, point) + LASER_SPEED) / distance(start, target);
}

/***************************************
* LASER :: CURRENT PERCENTAGE TRAVELLED
* The percentage of the distance traveled
* from the 'start' point to the 'target'
* point.
***************************************/
float Laser::currentPercentageTravelled()
{
	return distance(start, point) / distance(start, target);
}

/***************************************
* LASER :: DISTANCE
* Returns the distance between two
* points using the pythagorean theorem:
* c^2 = a^2 + b^2
***************************************/
float Laser::distance(Point a, Point b)
{
	float distanceRun = run(b.getX(), a.getX());
	float distanceRise = rise(b.getY(), a.getY());
	float aSquared = pow(distanceRun, 2);
	float bSquared = pow(distanceRise, 2);
	float cSquared = aSquared + bSquared;
	return sqrt(cSquared);
}

/***************************************
* LASER :: RISE
* Returns the difference between two 
* points on the y axis.
***************************************/
float Laser::rise(float yOne, float yTwo)
{
	return yTwo - yOne;
}

/***************************************
* LASER :: RUN
* Returns the difference between two 
* points on the x axis.
***************************************/
float Laser::run(float xOne, float xTwo)
{
	return xTwo - xOne;
}
