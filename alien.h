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
#include <vector>

using namespace std;

class Alien
{
private:
	Point point;
	vector<Laser> lasers;
	int energy;

public:
	Alien();

	Alien(Point point);

	// Getters
	Point    getPoint();

	// Setters
	void setPoint(Point point);

	// Others
	void draw();
	void drawLasers();
	void shootLaser(Point target);
	void advance();
	void increaseEnergy();
	bool canShootLaser();
	bool hasHit(Lander & lander);
};

#endif /* ALIEN_H */