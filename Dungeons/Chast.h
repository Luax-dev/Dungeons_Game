#pragma once

#include <SFML/Graphics.hpp>
#include "Dungeons.h"

class Chast
{
public:
	Chast();
	~Chast();

	sf::RectangleShape getChast() const { return chast; }

	void openChast(sf::RectangleShape Playe, const pl::Keys& Keys);

private:
	sf::RectangleShape chast;

	sf::Texture chastTextureClosed;
	sf::Texture chastTextureOpen;

	bool opened = false;
};
