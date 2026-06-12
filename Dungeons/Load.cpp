#include <SFML/Graphics.hpp>
#include "Dungeons.h"

#include <iostream>

sf::Texture loadingScreenTexture;


void LoadingScreen()
{

	if (!loadingScreenTexture.loadFromFile("Img\\BG\\LoadingScreen.png"))
	{
		std::cout << "Fehler: Konnte Ladebildschirm nicht laden!" << std::endl;
		exit(-1);
	}

	sf::Sprite LoadingScreen(loadingScreenTexture);

}