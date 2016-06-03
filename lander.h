/*************************************************************
* File: lander.cpp
* Author: Dan Rix
*
* Description: Contains a description of the lander class.
*
*************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

class Lander
{
private:
	Point	 point;
	Velocity velocity;
	int fuel;
	bool alive;
	bool landed;
	bool shotDown;

public:
	// Constructors
	Lander();

	Lander(Point point, Velocity velocity, int fuel);

	// Getters
	Point getPoint() const;
	Velocity getVelocity() const;
	int getFuel() const;
	bool isAlive() const;
	bool isLanded() const;
	bool isShotDown();

	// Setters
	void setPoint(Point point);
	void setVelocity(Velocity velocity);
	void setFuel(int fuel);
	void setAlive(bool alive);
	void setLanded(bool landed);
	void setShotDown(bool shotDown);

	// Others
	bool canThrust();
	void applyGravity(float);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void draw();
};

#endif /* LANDER_H */