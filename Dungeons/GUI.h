#pragma once
#include <SFML/Graphics.hpp>
#include "Dungeons.h"

class GUI
{
public:
	GUI();
	~GUI();

	sf::RectangleShape getInventar() const { return inventar; }

	void openInventar(const pl::Keys& keys, sf::RectangleShape player);

	void getInventarInfo();

	

private:
	sf::RectangleShape inventar;
	
	sf::Texture inventarTexture;

	bool inventarOpen = false;
	bool inventarKeyPressed = false;
};


