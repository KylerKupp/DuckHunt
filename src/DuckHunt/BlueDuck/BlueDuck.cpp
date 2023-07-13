/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#include "BlueDuck.h"

void BlueDuck::move()
{
	if (getPosition().y == 0)
	{
		heightTracker = 1; //if duck reaches roof, keep track of this with height tracker
	}
	else if (getPosition().y == 500)
	{
		heightTracker = 0; //if duck reaches floor, keep track of this with height tracker
	}

	if (heightTracker == 0) //if duck most recently hit floor
	{
		setPosition(getPosition().x + getSpeed(), getPosition().y - 1); // subtract Y value (move duck upward 1 pixel)
	}
	else //if duck most recently hit roof
	{
		setPosition(getPosition().x + getSpeed(), getPosition().y + 1); // add Y value (move duck downward 1 pixel)
	}
}