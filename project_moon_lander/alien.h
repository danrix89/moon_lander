/*************************************************************
* File: alien.cpp
* Author: Dan Rix
*
* Description: Contains a description of the alien class.
*
*************************************************************/

#ifndef ALIEN_H
#define ALIEN_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "laser.h"
#include "lander.h"
#include "my_math.h"
#include <vector>

using namespace std;

class Alien
{
private:
	Point origin;				// The original point of Alien
	Point point;				// The current location or point of Alien
	vector<Laser> lasers;		// The array of lasers that Alien has shot
	int energy;					// The energy level which determines if Alien can shoot its laser
	MyMath myMath;				// Access to needed match function
	int velocity;				// velocity of current (not to be confused with the Velocity class.

public:
	// Constructors
	Alien();

	Alien(Point point);

	// Getters
	Point			getPoint();
	vector<Laser>	getLasers();

	// Setters
	void setOrigin(Point point);
	void setPoint(Point point);

	// Others
	void draw();
	void drawLasers();
	void shootLaser(Point target);
	void advance(float minX, float maxX);
	void increaseEnergy();
	bool canShootLaser();
};

#endif /* ALIEN_H */