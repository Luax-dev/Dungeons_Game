#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Border
{
public:
	Border(float size_W, float size_H, float x, float y);
	~Border();

	sf::RectangleShape getBorder() const { return border; }

	void colisionWithPlayer(Player& player);
private:
	sf::RectangleShape border;
};




