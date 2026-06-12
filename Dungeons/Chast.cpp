#include <iostream>
#include "Chast.h"
#include "Player.h"
#include "Dungeons.h"


void getLoot()
{

	
	srand(time(NULL));
	int lootDrop = rand() % 12 + 1;
	int lootAmount = rand() % 20 + 5;

	if (lootDrop == 1 || lootDrop == 2 || lootDrop == 3 || lootDrop == 4)
	{
		std::cout << "\nDu bekommst " << lootAmount << " Gold";
		pl::inventarInfo.gold += lootAmount;
		return;
	}
	if (lootDrop == 5 || lootDrop == 6 || lootDrop == 7)
	{
		std::cout << "\nDu bekommst 2 Heiltränke!";
		pl::inventarInfo.healthPotions += 2;
		return;
	}
	if (lootDrop == 8 || lootDrop == 9)
	{
		std::cout << "\nDu bekommst viel Gold!: Gold +" << (lootAmount + 25);
		pl::inventarInfo.gold += lootAmount + 25;
		return;
	}
	if (lootDrop == 10)
	{
		std::cout << "\nDu bekommst " << lootAmount << " Gold und 3 Heiltränke!";
		pl::inventarInfo.gold += lootAmount;
		pl::inventarInfo.healthPotions += 3;
		return;
	}
	if (lootDrop == 11 || lootDrop == 12)
	{
		std::cout << "\n Du bekommst " << lootAmount << " gold und ein heiltrank";
		pl::inventarInfo.gold += lootAmount;
		pl::inventarInfo.healthPotions += 1;
		return;
	}
}



Chast::Chast()
{

	chast.setSize({ 70.f, 48.f });
	chast.setFillColor(sf::Color::White);
	//chast.setPosition({ 1300.f, 450.f });
	chast.setPosition({ 300.f, 400.f });

	if(!chastTextureClosed.loadFromFile("img/AS/chast_closed.png"))
	{
		std::cout << "Error loading chest texture!" << std::endl;
		exit(1);
	}

	if (!chastTextureOpen.loadFromFile("img/AS/chast_open.png"))
	{
		std::cout << "Error loading chest texture!" << std::endl;
		exit(1);
	}

	chast.setTexture(&chastTextureClosed);

}

Chast::~Chast()
{
}

void Chast::openChast(sf::RectangleShape Playe, const pl::Keys& Keys)
{
	if (sf::Keyboard::isKeyPressed(Keys.open))
	{
		if (Playe.getGlobalBounds().findIntersection(chast.getGlobalBounds()))
		{
			if (!opened)
			{
				std::cout << chast.getPosition().y - 22.f << '\n';
				std::cout << "378";
				chast.setPosition({ chast.getPosition().x, chast.getPosition().y - 22.f });
				//chast.setPosition({ 300.f, 378.f });
				chast.setSize({ 70.f, 70.f });
				chast.setTexture(&chastTextureOpen, true);
				opened = true;

				getLoot();
			}



			//chast.setFillColor(sf::Color::Yellow);

		}
	}
}

