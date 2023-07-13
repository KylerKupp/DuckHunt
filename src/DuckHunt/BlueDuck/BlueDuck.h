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
Description: The blue duck inherits from the duck class and differs in its movement.
The virtual function from "Duck" is overwritten in this class.
************************************************************************/
class BlueDuck : public Duck
{
public:
	/*************************************************************
	Function: BlueDuck()
	Description: constructor
	Parameters: Blue Duck Texture, starting position, starting speed
	*************************************************************/
	BlueDuck(sf::Texture& image, sf::Vector2i pos, double velocity) : Duck(image, pos, velocity)
	{
		heightTracker = 0;
	}
	/*************************************************************
	Function: move()
	Description: Overwrites the Duck class' virtual move function. The horizontal movement
	is not changed, but the Y value bounces from the top of the window to the floor.
	*************************************************************/
	void move();
protected:
	int heightTracker; // 1 indicates that it most recently hit the ceiling and 0 indicates that it most recently hit the floor
};