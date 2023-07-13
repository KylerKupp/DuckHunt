/*************************************************************************
Programmers: Kyler Kupp, Connor Clouse, George Sammour, Prinon (INSERT LAST NAME HERE)
Class: CptS 122
Programming Assignment: PA 9
Date: 4/29/22
Description: This program is a custom version of the classic game "Duck Hunt"
************************************************************************/
#include "Menu.h"
#include <time.h>
#include <string>

void Menu::initMenu()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "DuckHunt"); //setup window
	window.setFramerateLimit(200u); //determines speed of game

	sf::Texture menuImage; //the entire menu is just an image
	menuImage.loadFromFile("mainMenu.png");
	sf::Sprite menuScreen(menuImage); //make the menu a sprite so it can be drawn

	while (window.isOpen())
	{
		window.clear();
		window.draw(menuScreen);
		window.display();

		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) { //if user chooses to close window
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) //if user left clicked
			{
				if (sf::Mouse::getPosition(window).x > 440 && sf::Mouse::getPosition(window).x < 840) //Since all buttons are in a perfect column, they will all be in this x range
				{
					if (sf::Mouse::getPosition(window).y > 230 && sf::Mouse::getPosition(window).y < 300) //if cursor is in y range for play button
					{
						playGame(window);
					}
					else if (sf::Mouse::getPosition(window).y > 330 && sf::Mouse::getPosition(window).y < 400) //if cursor is in y range for 'how to play' button
					{
						showRules(window);
					}
					else if (sf::Mouse::getPosition(window).y > 430 && sf::Mouse::getPosition(window).y < 500) //if cursor is in y range for exit button
					{
						window.close();
						break;
					}
				}
			}
		}
	}
}
void Menu::showRules(sf::RenderWindow& window)
{
	sf::Texture ruleScreen;
	ruleScreen.loadFromFile("rules.png");
	sf::Sprite ruleScreenSprite(ruleScreen); //make the rules a sprite so it can be drawn

	while (window.isOpen()) 
	{
		window.clear();
		window.draw(ruleScreenSprite);
		window.display();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { //close window if they choose to
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)//if user left clicked
			{
				if (sf::Mouse::getPosition(window).x > 1053 && sf::Mouse::getPosition(window).x < 1262 && sf::Mouse::getPosition(window).y > 635 && sf::Mouse::getPosition(window).y < 705) //if cursor is in x and y range for return button
				{
					return; //go back to main menu
				}
			}
		}
	}
}
void Menu::playGame(sf::RenderWindow& window)
{
	sf::Texture backgroundImage; //background
	backgroundImage.loadFromFile("background.png");
	sf::Sprite background(backgroundImage); 

	sf::Texture endScreenImage; //endscreen which has return button
	endScreenImage.loadFromFile("endScreen.png");
	sf::Sprite endScreen(endScreenImage);

	sf::Texture duckText; //standard green duck texture
	duckText.loadFromFile("duck.png");
	
	sf::Texture blueDuckText; //blue duck texture
	blueDuckText.loadFromFile("blueDuck.png");

	sf::Texture purpleDuckText; //purple duck texture
	purpleDuckText.loadFromFile("purpleDuck.png");

	sf::Texture redDuckText; //red duck texture
	redDuckText.loadFromFile("redDuck.png");

	sf::Texture goldenDuckText; //golden duck texture
	goldenDuckText.loadFromFile("goldenDuck.png");

	sf::Font font;
	if (!font.loadFromFile("phenomicon.ttf"))
	{
		std::cout << "font error";
	}

	sf::Text scoreText; //appropriate setup for score text which will be displayed in bottom-left corner
	scoreText.setFont(font);
	scoreText.setString(std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(20, 650);

	srand(time(NULL)); //set seed for rand()

	//All ducks are loaded in with their appropriate textures, random starting positions, and a speed of 1
	//their x positions are staggered to keep them from all flooding in at once
	Duck duck1(duckText, sf::Vector2i(-96, randomStartY()), 1);
	BlueDuck duck2(blueDuckText, sf::Vector2i(-352, randomStartY()), 1);
	PurpleDuck duck3(purpleDuckText, sf::Vector2i(-608, randomStartY()), 1);
	RedDuck duck4(redDuckText, sf::Vector2i(-864, randomStartY()), 1);
	GoldenDuck duck5(goldenDuckText, sf::Vector2i(-1120, randomStartY()), 1);

	sf::Texture heartText; //heart texture to represent lives
	heartText.loadFromFile("heart.png");

	sf::Sprite heart1(heartText); //position at (0, 0)
	sf::Sprite heart2(heartText);
	heart2.setPosition(50, 0);
	sf::Sprite heart3(heartText);
	heart3.setPosition(100, 0);

	while (window.isOpen())
	{
		window.clear();
		window.draw(background);

		duck1.move(); //begin duck motion
		duck2.move();
		duck3.move();
		duck4.move();
		duck5.move();

		window.draw(duck1); 
		window.draw(duck2);
		window.draw(duck3);
		window.draw(duck4);
		window.draw(duck5);

		scoreText.setString(std::to_string(score)); //convert score value from int to string to be displayed
		window.draw(scoreText);

		if (lives == 3) //only display the amount of hearts that correspond to the player's lives
		{
			window.draw(heart3);
		}
		if (lives > 1)
		{
			window.draw(heart2);
		}
		if (lives > 0)
		{
			window.draw(heart1);
		}

		window.display();

		isDuckFree(&duck1); //check if ducks have escaped
		isDuckFree(&duck2);
		isDuckFree(&duck3);
		isDuckFree(&duck4);
		isDuckFree(&duck5);

		sf::Event event;

		if (isGameOver()) //if no lives are left
		{
			sf::Text finalScore; //to be displayed on endscreen
			finalScore.setFont(font);
			finalScore.setString("Score: " + std::to_string(score));
			finalScore.setCharacterSize(100);
			finalScore.setFillColor(sf::Color::White);
			finalScore.setPosition(500, 200);

			while (window.isOpen())
			{
				window.clear();
				window.draw(endScreen);
				window.draw(finalScore);
				window.display();

				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed) { //close window if they choose to
						window.close();
					}

					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) //if user left clicked
					{
						if (sf::Mouse::getPosition(window).x > 440 && sf::Mouse::getPosition(window).x < 840) //if user clicked in x range for return button
						{
							if (sf::Mouse::getPosition(window).y > 460 && sf::Mouse::getPosition(window).y < 530) //if user clicked in y range for return button
							{
								lives = 3; //reset lives
								score = 0; //reset score
								return; //return to main menu
							}
						}
					}
				}
			}
		}

		while (window.pollEvent(event))
		{
			isDuckShot(&duck1, event, window); //check to see if ducks were shot
			isDuckShot(&duck2, event, window);
			isDuckShot(&duck3, event, window);
			isDuckShot(&duck4, event, window);
			isDuckShot(&duck5, event, window);

			if (event.type == sf::Event::Closed) {  //if user chose to close window
				window.close();
			}
		}
	}
}
int Menu::randomStartY()
{
	return rand() % 500;
}
template <class T>
bool Menu::isDuckShot(T* duck, sf::Event event, sf::RenderWindow& window) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) //if mouse was left clicked
	{
		if (sf::Mouse::getPosition(window).y > duck->getPosition().y && sf::Mouse::getPosition(window).y < duck->getPosition().y + 72) //if cursor was in y range of ducks texture
		{
			if (sf::Mouse::getPosition(window).x > duck->getPosition().x && sf::Mouse::getPosition(window).x < duck->getPosition().x + 96) //if cursor was in x range of ducks texture
			{
				score++;
				duck->setPosition(-96, randomStartY()); //set just offscreen
				duck->setSpeed(duck->getSpeed() + 0.1); //increase speed
				return true;
			}
		}
	}
	return false;
}
bool Menu::isDuckShot(GoldenDuck* duck, sf::Event event, sf::RenderWindow& window) 
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) //if mouse was left clicked
	{
		if (sf::Mouse::getPosition(window).y > duck->getPosition().y && sf::Mouse::getPosition(window).y < duck->getPosition().y + 72) //if cursor was in y range of ducks texture
		{
			if (sf::Mouse::getPosition(window).x > duck->getPosition().x && sf::Mouse::getPosition(window).x < duck->getPosition().x + 96) //if cursor was in x range of ducks texture
			{
				score+=3;//bonus points
				duck->setPosition(-10000, randomStartY()); //set far away so it is rare
				return true;
			}
		}
	}
	return false;

}
template <class T>
bool Menu::isDuckFree(T* duck) {
	if (duck->getPosition().x > 1280) //if duck made it offscreen
	{
		duck->setPosition(-96, randomStartY()); //set in starting offscreen position
		lives--; //remove life
		return true;
	}
	return false;
}
bool Menu::isDuckFree(RedDuck* duck) {
	if (duck->getPosition().x > 1280) //if duck made it offscreen
	{
		duck->setPosition(-96, randomStartY()); //set in starting offscreen position
		lives=0; //lives instantly go to zero because red duck ends game
		return true;
	}
	return false;
}
bool Menu::isDuckFree(GoldenDuck* duck) {
	if (duck->getPosition().x > 1280) //if duck made it offscreen
	{
		duck->setPosition(-10000, randomStartY()); //set in starting offscreen position (far because golden duck is fast and supposed to appear rarely)
		// lives not changed
		return true;
	}
	return false;
}
bool Menu::isGameOver()
{
	if (lives < 1)
	{
		return true;
	}
	return false;
}
