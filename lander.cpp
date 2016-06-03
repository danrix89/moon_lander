#include "lander.h"
/*************************************************************
* File: lander.cpp
* Author: Dan Rix
*
* Description: A representation of a very basic moon lander
*              and it's properties.
*
*************************************************************/


// Constructors
Lander::Lander()
{
	setAlive(true);
	setLanded(false);
	velocity.setDx(0.0);
	velocity.setDy(0.0);
}

Lander::Lander(Point point, Velocity velocity, int fuel)
{
	setPoint(point);
	setVelocity(velocity);
	setFuel(fuel);
	setAlive(true);
	setLanded(false);
}

// Getters

Point Lander::getPoint() const
{
	return point;
}

Velocity Lander::getVelocity() const
{
	return velocity;
}

int Lander::getFuel() const
{
	return fuel;
}

bool Lander::isAlive() const
{
	return alive;
}

bool Lander::isLanded() const
{
	return landed;
}

bool Lander::isShotDown()
{
	return shotDown;
}

// Setters

void Lander::setPoint(Point point)
{
	this->point = point;
}

void Lander::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

void Lander::setFuel(int fuel)
{
	this->fuel = fuel;
}

void Lander::setAlive(bool alive)
{
	this->alive = alive;
}

void Lander::setLanded(bool landed)
{
	this->landed = landed;
}

void Lander::setShotDown(bool shotDown)
{
	this->shotDown = shotDown;
	setFuel(0);
}

// Others

/***************************************
* LANDER :: CAN THRUST	
* Can the ship apply thrust (does it 
* have fuel and is still alive)?
***************************************/
bool Lander::canThrust()
{
	return true;
}

/***************************************
* LANDER :: APPLY GRAVITY 
* Applies gravitational force on the
* ship, pulling it downward.
***************************************/
void Lander::applyGravity(float)
{
	velocity.setDy(velocity.getDy() - 0.1);
}

/***************************************
* LANDER :: APPLY THRUST LEFT
* Applies thrust on the left of the
* ship to propel it to the right.
***************************************/
void Lander::applyThrustLeft()
{
	if (fuel > 0)
	{
		velocity.setDx(velocity.getDx() + 0.1);
		setFuel(fuel - 1);
		drawLanderFlames(point, false, true, false);
	}
}

/***************************************
* LANDER :: APPLY THRUST RIGHT
* Applies thrust on the right of the
* ship to propel it to the left.
***************************************/
void Lander::applyThrustRight()
{
	if (fuel > 0)
	{
		velocity.setDx(velocity.getDx() - 0.1);
		setFuel(fuel - 1);
		drawLanderFlames(point, false, false, true);
	}
}

/***************************************
* LANDER :: APPLY THRUST BOTTOM
* Applies thrust on the bottom of the 
* ship to propel it upward.
***************************************/
void Lander::applyThrustBottom()
{
	if (fuel >= 3)
	{
		velocity.setDy(velocity.getDy() + 0.3);
		setFuel(fuel - 3);
		drawLanderFlames(point, true, false, false);
	}
}

/***************************************
* LANDER :: ADVANCE
* Advances the LANDERs movement in a
* given direction.
***************************************/
void Lander::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}

/***************************************
* LANDER :: DRAW
* Draws the ships body to the interface.
***************************************/
void Lander::draw()
{
	drawLander(point, isShotDown());
	if (isShotDown())
	{
		drawLanderFlames(point, true, true, true);
	}
}