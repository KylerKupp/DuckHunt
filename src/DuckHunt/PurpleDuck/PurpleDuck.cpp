/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#include "PurpleDuck.h"
#include <math.h>

void PurpleDuck::move()
{
	int ranConstY;
	if (getPosition().x == -96) //if duck is in starting position offscreen
	{
		ranConstY = rand() % 400 + 65; //get random y constant. We cannot use the position it is set to after death since it follows a sin pattern and may go offscreen too much.
	}
	setPosition(getPosition().x + getSpeed(), ranConstY + 75 * sin(getPosition().x / 50)); //x moves and accelerates normally. 
	//Y value is a sin function with amplitude 75 and the /50 decreases the period. ranConstY is the constant where the sin function begins on the y axis.
}