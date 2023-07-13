/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#include "GoldenDuck.h"

void GoldenDuck::move()
{
	setPosition(getPosition().x + 5, getPosition().y); //move 5 pixels to the right (constant speed)
}