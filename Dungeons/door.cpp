#include "door.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "LevelLoder.h"

Door::Door( float X, float Y, float W = 75, float H = 117)
{
	door.setSize({ W, H });
	door.setFillColor(sf::Color::Blue);
	door.setPosition({ X, Y });
}

Door::~Door()
{
}


void Door::colisionWithPlayer(const sf::RectangleShape& Player, sf::RenderWindow& window, js::LevelData levelData)
{
	if (door.getGlobalBounds().findIntersection((Player.getGlobalBounds())))
	{
		// Kollision erkannt, hier kannst du die gewünschte Aktion ausführen
		std::cout << "Kollision mit Tür erkannt!" << std::endl;
		saveDataNewLevel(window, levelData);
	}
}

