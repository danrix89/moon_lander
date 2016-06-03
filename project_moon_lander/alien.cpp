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

#define ENERGY_LEVEL_FOR_SHOOTING 30

using namespace std;

// Constructors
Alien::Alien()
{
	energy = 100;
	velocity = 5;
}

Alien::Alien(Point point)
{
	setOrigin(point);
	energy = 100;
	velocity = 5;
}

// Getters
Point Alien::getPoint()
{
	return point;
}

vector<Laser> Alien::getLasers()
{
	return lasers;
}

// Setters
void Alien::setOrigin(Point point)
{
	this->origin = point;
	this->point = point;
}

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

void Alien::advance(float minX, float maxX)
{
	// Adnvace Alien
	point.setX(point.getX() + velocity);
	if (point.getX() > (maxX - 50) || point.getX() < (minX + 50))
		velocity = velocity * -1.0;


	// Advance Lasers
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
