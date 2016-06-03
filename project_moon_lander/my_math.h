/*************************************************************
* File: my_math.h
* Author: Dan Rix
*
* Description: Contains useful math functions that I can't get
*              from the cmath library due to the lack of
*              resouces in libraries in the Linux Lab.
*************************************************************/

#ifndef MYMATH_H
#define MYMATH_H

using namespace std;

class MyMath
{
public:
	/*********************************************
	* Function: ABSOLUTE VALUE
	* Description: Returns the absolute value of 
	* a 'number'.
	*********************************************/
	float absoluteValue(float number);

};

#endif /* MYMATH_H */