/*************************************************************
* File: laser.cpp
* Author: Dan Rix
*
* Description: Contains a description of the laser class.

*************************************************************/

#ifndef LASER_H
#define LASER_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "lander.h"
#include "my_math.h"

class Laser
{
private:
	Point    point;					// The Location point of the Laser
	Point	 start;					// The original point or start of the Laser
	Point	 target;				// The direction or target that Laser is moving toward
	float	 distanceFromStart;     // The current distance of the Laser from 'start'
	bool hasHitObject;				// Has the Laser hit an object?
	MyMath myMath;					// Access to needed match function


public:
	// Constructors
	Laser();
	Laser(Point start, Point target);

	// Getters
	Point getPoint();
	bool getHasHitObject();

	// Setters
	void setPoint(Point point);
	void setHasHitObject(bool hit);

	// Others
	/*********************************************
	* Function: DRAW
	* Description: Draws the Laser on the screen.
	*********************************************/
	void draw();

	/*********************************************
	* Function:
	* Description: Advances the Laser's position.
	*********************************************/
	void advance();

	/*********************************************
	* Function:
	* Description: Returns the next location on
	* the x-axis that laser will 'advance' to.
	*********************************************/
	float nextX();

	/*********************************************
	* Function:
	* Description: Returns the next location on
	* the y-axis that laser will 'advance' to.
	*********************************************/
	float nextY();

	/*********************************************
	* Function: 
	* Description: Returns the forecasted
	* percentage of distance travelled of the
	* total distance (e.g. if travelled 5 units
	* out of 10, then the Laser has travelled 50%
	* of the total distance).
	*********************************************/
	float nextPercentageTravelled();

	/*********************************************
	* Function:
	* Description: Returns the current
	* percentage of distance travelled of the
	* total distance (e.g. if travelled 5 units
	* out of 10, then the Laser has travelled 50%
	* of the total distance).
	*********************************************/
	float currentPercentageTravelled();

	/*********************************************
	* Function:
	* Description: Returns the distance between
	* to points.
	*********************************************/
	float distance(Point a, Point b);

	/*********************************************
	* Function:
	* Description: Returns the rise or distance 
	* between two y-axis points (i.e. y2 - y1).
	*********************************************/
	float rise(float yOne, float yTwo);

	/*********************************************
	* Function:
	* Description: Returns the rise or distance
	* between two x-axis points (i.e. x2 - x1).
	*********************************************/
	float run(float xOne, float xTwo);
};

#endif /* LASER_H */