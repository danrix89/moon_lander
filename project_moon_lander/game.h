/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: Contains the definition of the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#ifndef GAME_H
#define GAME_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"
#include "alien.h"
#include "my_math.h"
#include <vector>

#define FUEL        500    // initial fuel for the game
#define MIN_SPEED   3.0    // minimal landing speed
#define FALL_HEIGHT 4.0    // greatest height we can fall from

#define GRAVITY_AMOUNT 0.1
#define WELCOME_STATE 1
#define PLAY_STATE 2

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br) : topLeft(tl), bottomRight(br), ground(Ground(topLeft, bottomRight))
   {
      // Set up the initial conditions of the game
	   state = WELCOME_STATE;
	   Point startingPoint = tl;

	   // Setting up Lander and its fuel
	   startingPoint.setY(startingPoint.getY() - 20);
	   startingPoint.setX(random(topLeft.getX() + 30.0, bottomRight.getX() - 30.0));
	   lander.setPoint(startingPoint);
	   lander.setFuel(FUEL);

	   // Setting up Alien
	   startingPoint.setY(startingPoint.getY() - 30);
	   if ((startingPoint.getX() + bottomRight.getX() - 50) < bottomRight.getX())
		   startingPoint.setX(startingPoint.getX() + bottomRight.getX() - 50);
	   else
		   startingPoint.setX(startingPoint.getX() - bottomRight.getX() - 50);
	   alien.setOrigin(startingPoint);
   }
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
private:
	/*********************************************
	* Function: hasLaserHitLander
	* Description: Returns true if the lander has
	*  been hit by an Alien's laser.
	*********************************************/
	bool hasLaserHitLander();
	
	/*********************************************
    * Function: justLanded
    * Description: Returns true if the lander has
    *  just successfully landed.
    *********************************************/
	bool justLanded() const;
   
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   
   Ground ground;
   Lander lander;
   Alien  alien;
   MyMath myMath;
   int	  state;
};

#endif /* GAME_H */
