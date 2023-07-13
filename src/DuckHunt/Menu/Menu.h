/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BlueDuck.h"
#include "PurpleDuck.h"
#include "RedDuck.h"
#include "GoldenDuck.h"

/*************************************************************************
Description: The Menu class is where the majority of the game takes place, starting
with the menu. This keeps main() tidy.
************************************************************************/
class Menu {
public:
	/*************************************************************
	Function: Menu()
	Description: constructor
	*************************************************************/
	Menu()
	{
		score = 0;
		lives = 3;
	}
	/*************************************************************
	Function: initMenu()
	Description: Initializes the menu and allows users to either call
	showRules(), playGame(), or simply exit the window.
	*************************************************************/
	void initMenu();
	/*************************************************************
	Function: showRules()
	Description: Shows the user a screen that explains how to play.
	Allows the user to return to the menu afterward.
	Parameters: game window
	Preconditions: window is already open
	*************************************************************/
	void showRules(sf::RenderWindow& window);
	/*************************************************************
	Function: playGame()
	Description: takes the user through actual gameplay. Afterward, the user
	has the option to return to the main menu.
	Parameters: game window
	Preconditions: window is already open
	*************************************************************/
	void playGame(sf::RenderWindow& window);
	/*************************************************************
	Function: randomStartY()
	Description: Determines a randomized Y value for the duck to start out at.
	returns: randomized Y level
	*************************************************************/
	int randomStartY();
	/*************************************************************
	Function: isDuckShot(T)
	Description: Function Template that adjusts the score, duck speed, and duck position
	if the duck is shot. This template is used for ducks with standard death behavior, meaning
	that they increase the score by one, and their speed is modified.
	Parameters: address of duck in question, event polled, open window
	*************************************************************/
	template <class T>
	bool isDuckShot(T* duck, sf::Event event, sf::RenderWindow& window);
	/*************************************************************
	Function: isDuckShot(GoldeDuck)
	Description: Overloaded function for the golden duck that is required since
	the golden duck gives 3 score instead of 1. It also does not change in speed
	and its position is set much farther back than other ducks to make it more rare.
	Parameters: address of duck in question, event polled, open window
	*************************************************************/
	bool isDuckShot(GoldenDuck* duck, sf::Event event, sf::RenderWindow& window);
	/*************************************************************
	Function: isDuckFree(T)
	Description: Function Template that determines if a duck has escaped the window
	and punishes the player. The template is for all ducks with standard end behavior,
	meaning that they remove 1 life and return to their starting position when escaping.
	Parameters: address of duck in question
	*************************************************************/
	template <class T>
	bool isDuckFree(T* duck);
	/*************************************************************
	Function: isDuckFree(RedDuck)
	Description: Overloaded function for the Red duck since the Red duck
	removes all 3 lives upon escaping.
	Parameters: address of duck in question
	*************************************************************/
	bool isDuckFree(RedDuck* duck);
	/*************************************************************
	Function: isDuckFree(GoldenDuck)
	Description: Overloaded function for the Golden duck since it does
	not remove any lives when escaping. It also must be set back to a farther
	position after escaping to ensure its rarity.
	Parameters: address of duck in question
	*************************************************************/
	bool isDuckFree(GoldenDuck* duck);
	/*************************************************************
	Function: isGameOver()
	Description: returns true if the player has less than 1 life
	Returns: true if game is over, false if game is still going
	*************************************************************/
	bool isGameOver();
private:
	int score;
	int lives;
};

