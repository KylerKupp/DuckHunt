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
Description: The Golden duck class inherits from Duck. The reason it requires its
own class is its difference in movement. The Golden duck moves at a constant speed,
unlike the other ducks that gradually get faster. For this reason, Duck's virtual function
move() is overwritten
************************************************************************/
class GoldenDuck : public Duck
{
public:
	/*************************************************************
	Function: GoldenDuck()
	Description: constructor
	Parameters: Golden Duck Texture, starting position, starting speed
	*************************************************************/
	GoldenDuck(sf::Texture& image, sf::Vector2i pos, double velocity) : Duck(image, pos, velocity)
	{
	}
	/*************************************************************
	Function: move()
	Description: Overwrites the Duck class' virtual move function. Instead of accelerating
	based on speed, it moves at a constant speed.
	*************************************************************/
	void move();
};