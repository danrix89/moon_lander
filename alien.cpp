/*************************************************************
* File: alien.cpp
* Author: Dan Rix
*
* Description: A representation of a moon alien.
*
*************************************************************/

#include "alien.h"
#include "lander.h"
#include "laser.h"
#include <vector>

#define ENERGY_LEVEL_FOR_SHOOTING 20

using namespace std;

// Constructors
Alien::Alien()
{
	energy = 100;
}

Alien::Alien(Point point)
{
	this->point = point;
}

// Getters
Point Alien::getPoint()
{
	return point;
}

// Setters
void Alien::setPoint(Point point)
{
	this->point = point;
}


// Others
void Alien::draw()
{
	drawAlien(point);
	drawLasers();
}

void Alien::drawLasers()
{
	for (int i = 0; i < lasers.size(); i++)
	{
		lasers.at(i).draw();
	}
}

void Alien::shootLaser(Point target)
{
	Laser laser = Laser(point, target);
	lasers.push_back(laser);
	energy = 0;
}

void Alien::advance()
{
	for (int i = 0; i < lasers.size(); i++)
	{
		lasers.at(i).advance();
	}

	if (!canShootLaser())
		increaseEnergy();
}

void Alien::increaseEnergy()
{
	energy++;
}

bool Alien::canShootLaser()
{
	if (energy >= ENERGY_LEVEL_FOR_SHOOTING)
		return true;
	else
		return false;
}

bool Alien::hasHit(Lander & lander)
{
	for (int i = 0; i < lasers.size(); i++)
	{
		if (lasers.at(i).hitObject(lander))
			return true;
	}

	return false;
}
