
/*************************************************************
* File: velocity.h
* Author: Dan Rix
*
* Description: Contains a description of the Velocity class.
*
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

	// Others

};

#endif /* VELOCITY_H */

