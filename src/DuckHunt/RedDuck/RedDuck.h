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
Description: The Red duck inherits from Duck and is essentially the same as
far as the class goes. It is given its own class so that we can differentiate
the ducks since the red duck will instantly end the game unlike the base (green) duck.
************************************************************************/
class RedDuck : public Duck
{
public:
	/*************************************************************
	Function: RedDuck()
	Description: constructor
	Parameters: Red Duck Texture, starting position, starting speed
	*************************************************************/
	RedDuck(sf::Texture& image, sf::Vector2i pos, double velocity) : Duck(image, pos, velocity)
	{
	}
};