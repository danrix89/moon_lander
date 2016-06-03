/*************************************************************
* File: laser.cpp
* Author: Dan Rix
*
* Description: Contains a description of the laser class.
*
*************************************************************/

#ifndef LASER_H
#define LASER_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "lander.h"

class Laser
{
private:
	Point    point;
	Point	 start;
	Point	 target;
	Velocity velocity;
	float	 distanceFromStart;
	bool hasHitObject;

public:
	// Constructors
	Laser();
	Laser(Point start, Point target);

	// Getters
	Point getPoint();
	Velocity getVelocity();
	bool getHasHitObject();

	// Setters
	void setPoint(Point point);
	void setVelocity(Velocity velocity);
	void setHasHitObject(bool hit);

	// Others
	void draw();
	void advance();
	float nextX();
	float nextY();
	float nextPercentageTravelled();
	float currentPercentageTravelled();
	float distance(Point a, Point b);
	float rise(float yOne, float yTwo);
	float run(float xOne, float xTwo);
	bool  hitObject(Lander & lander);
	float absoluteValue(float number);
};

#endif /* LASER_H */