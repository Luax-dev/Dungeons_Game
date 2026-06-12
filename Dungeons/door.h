#pragma once
#include <SFML/Graphics.hpp>
#include "LevelLoder.h"

class Door
{
public:
	Door(float W, float H, float X, float Y);
	~Door();

	sf::RectangleShape getDoor() const { return door; }

	void colisionWithPlayer(const sf::RectangleShape& Player, sf::RenderWindow& window, js::LevelData levelData);

private:
	sf::RectangleShape door;
};
