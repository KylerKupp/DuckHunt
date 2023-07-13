/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#include <SFML/Graphics.hpp>
#include "Duck.h"

/*************************************************************************
Description: The Purple duck inherits from Duck and has overwrites Duck's
virtual function move().
************************************************************************/
class PurpleDuck : public Duck
{
public:
	/*************************************************************
	Function: PurpleDuck()
	Description: constructor
	Parameters: Purple Duck Texture, starting position, starting speed
	*************************************************************/
	PurpleDuck(sf::Texture& image, sf::Vector2i pos, double velocity) : Duck(image, pos, velocity)
	{
	}
	/*************************************************************
	Function: move()
	Description: Overwrites the Duck class' virtual move function. The horizontal movement
	remains the same, but the Y value follows a sin function.
	*************************************************************/
	void move();
};