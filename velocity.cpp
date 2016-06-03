#include "velocity.h"


// Constructors
Velocity::Velocity()
{
}

Velocity::Velocity(float dx, float dy)
{
	setDx(dx);
	setDy(dy);
}

// Getters
float Velocity::getDx() const
{
	return dx;
}

float Velocity::getDy() const
{
	return dy;
}

// Setters
void Velocity::setDx(float dx)
{
	this->dx = dx;
}

void Velocity::setDy(float dy)
{
	this->dy = dy;
}

// Others
