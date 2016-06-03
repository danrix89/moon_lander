/*************************************************************
* File: my_math.cpp
* Author: Dan Rix
*
* Description: Contains useful math functions that I can't get
*              from the cmath library due to the lack of
*              resouces in libraries in the Linux Lab.
*
*************************************************************/

#include "my_math.h"
#include "math.h"

float MyMath::absoluteValue(float number)
{
	float absolute = pow(number, 2.0);
	absolute = sqrt(absolute);
	return absolute;
}
