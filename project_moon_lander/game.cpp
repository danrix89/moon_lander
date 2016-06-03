/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"
#include "alien.h"
#include "my_math.h"
#include <vector>

#define LASER_TOLERANCE 10
#define WELCOME_STATE 1
#define PLAY_STATE 2

 /******************************************
 * GAME :: HAS LASER HIT LANDER
 * Did the lander get hit by an Alien laser?
 ******************************************/
bool Game::hasLaserHitLander()
{
	bool result = false;
	float landerX = lander.getPoint().getX();
	float landerY = lander.getPoint().getY();
	for (int i = 0; i < alien.getLasers().size(); i++)
	{
		Laser * laser = new Laser();
		*laser = alien.getLasers().at(i);
		float laserX = laser->getPoint().getX();
		float laserY = laser->getPoint().getY();
		float laserProximityX = myMath.absoluteValue(landerX - laserX);
		float laserProximityY = myMath.absoluteValue(landerY - laserY);
		if ((laserProximityX <= LASER_TOLERANCE) && (laserProximityY <= LASER_TOLERANCE))
		{
			laser->setHasHitObject(true);
			result = true;
		}
	}
	return result;
}

/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
	switch (state)
	{
		case WELCOME_STATE:
			break;
		case PLAY_STATE:
		{
			if (lander.isAlive() && !lander.isLanded())
			{
				// advance the lander & alien
				lander.applyGravity(GRAVITY_AMOUNT);
				lander.advance();
				alien.advance(topLeft.getX(), bottomRight.getX());

				if (alien.canShootLaser())
				{
					alien.shootLaser(lander.getPoint());
				}
				// check for crash
				if (!ground.isAboveGround(lander.getPoint()))
				{
					lander.setAlive(false);
				}

				if (hasLaserHitLander() && !lander.isShotDown())
				{
					lander.setShotDown(true);
				}

				// check for just landed
				if (justLanded())
				{
					lander.setLanded(true);
				}
			}
			break;
		}
	}

}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
	switch (state)
	{
		case WELCOME_STATE:
			if (ui.isSpace())
			{
				state = PLAY_STATE;
			}
		case PLAY_STATE:
		{
			if (lander.isAlive() && !lander.isLanded())
			{

				if (ui.isDown())
				{
					lander.applyThrustBottom();
				}

				if (ui.isLeft())
				{
					lander.applyThrustLeft();
				}

				if (ui.isRight())
				{
					lander.applyThrustRight();
				}
			}
			break;
		}
	}
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
	switch (state)
	{
		case WELCOME_STATE:
			drawText(Point(), "Welcome to Moon Lander!");
		case PLAY_STATE:
		{
			lander.draw();
			alien.draw();

			if (lander.isLanded() && !lander.isShotDown())
			{
				drawText(Point(), "You have successfully landed!");
			}

			if (!lander.isAlive())
			{
				drawText(Point(), "You have crashed!");
			}

			if (lander.isShotDown() && lander.isAlive())
			{
				drawText(Point(0.0, -10.0), "You've been Shot! You're going down!");
			}

			Point fuelLocation;
			fuelLocation.setX(topLeft.getX() + 5);
			fuelLocation.setY(topLeft.getY() - 5);
			drawNumber(fuelLocation, lander.getFuel());

			// draw ground
			ground.draw();
			break;
		}
	}
}

