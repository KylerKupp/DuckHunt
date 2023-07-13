/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>

/*************************************************************************
Description: The Duck is the base class for all ducks in the game. It is also
instantiated as the green duck.
************************************************************************/
class Duck : public sf::Sprite
{
public:
	/*************************************************************
	Function: Duck()
	Description: constructor
	Parameters: Green Duck Texture, starting position, starting speed
	*************************************************************/
	Duck(sf::Texture& image, sf::Vector2i pos, double velocity) : sf::Sprite(image)
	{
		speed = velocity;
		setPosition(pos.x,pos.y);
	}
	/*************************************************************
	Function: move()
	Description: The move() function is virutal and provides a standard
	horizontal movement based on the duck's speed. This is utilized by the
	Green and Red ducks, and the function is overwritten for ducks with unusual movement.
	*************************************************************/
	virtual void move()
	{
		setPosition(getPosition().x + getSpeed(), getPosition().y);
	}
	void setSpeed(double velocity);
	double getSpeed();
protected:
	double speed; //speed is the amount of pixels the duck moves horizontally per unit. Begins at 1 and increases overtime for this duck.
};