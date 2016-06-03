/*************************************************************
* File: velocity.h
* Author: Dan Rix
*
* Description: Contains a description of the Velocity class.
* However, this is not an accurate representaion of true
* velocity. This class only has a direction X and direction Y
* which what direction a client of this class is going at a
* certain number of units across a cartesian plane.

*************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include "uiDraw.h"
#include "uiInteract.h"

class Velocity
{
private:
	float dx;
	float dy;

public:
	// Constructors
	Velocity();
	Velocity(float dx, float dy);

	// Getters
	float getDx() const;
	float getDy() const;

	// Setters
	void setDx(float dx);
	void setDy(float dy);

};

#endif /* VELOCITY_H */

