#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Border.h"
#include "Dungeons.h"
#include "Draw.h"
#include "door.h"
#include "LevelLoder.h"
#include "Chast.h"
#include "GUI.h"

namespace lv
{
	js::LevelData LevelData;
	bool newLevel = true;
}


void drawAndUpdateNewLevel(sf::RenderWindow& window)
{
	static Player nPlayer;

	if (lv::newLevel)
	{

		nPlayer.setPositionX(lv::LevelData.player_start[0]);
		nPlayer.setPositionY(lv::LevelData.player_start[1]);

		std::cout << "\nPlayer was set to start for first time\n";
		lv::newLevel = false;
	}
	drawPlayer(window, nPlayer);
	std::cout << "\nPlayer was Updatet and drawd\n";

}


void saveDataNewLevel(sf::RenderWindow& window, js::LevelData levelData)
{
	//window.clear();
	lv::LevelData = LevelLoder::load("Level\\.json");


	std::cout << "Lade Level..." << std::endl;
	std::cout << "Level Name: " << lv::LevelData.name << std::endl;
	std::cout << "Player Start Position: (" << lv::LevelData.player_start[0] << ", " << lv::LevelData.player_start[1] << ")" << std::endl;
	std::cout << "Background Image: " << lv::LevelData.background.image << std::endl;
	std::cout << "Borders VecSize:" << lv::LevelData.borders.size() <<std::endl;

	std::cout << "Inhalt von lv::Leveldata: " << lv::LevelData.name << std::endl;

	//std::string LevelName = LevelData.name;
	//int PlayerStartX = LevelData.player_start[0];
	//int PlayerStartY = LevelData.player_start[1];

	//std::string BackgroundImage = LevelData.background.image;

	//std::vector<js::Border> Borders = LevelData.borders;

	//std::cout << "Vector Borders groesse: " << Borders.size() << std::endl;
	//std::cout << "Border 1 Werte: X:" << Borders[0].position[0] << " Y:" << Borders[0].position[1] << " W:" << Borders[0].size[0] << " H:" << Borders[0].size[1] << std::endl;

	//Player nPlayer;
	//nPlayer.setPositionX(PlayerStartX);
	//nPlayer.setPositionY(PlayerStartY);
	
	//drawPlayer(window, nPlayer);

	////exit(0);
}



config::config bevore()
{
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("Img\\BG\\Background_0.png"))
	{
		std::cerr << "\nFehler: Konnte Hintergrundbild nicht laden!\n" << std::endl;
		exit(-1);
	}



	sf::View camera;
	camera.setSize({ 800.f, 600.f });
	camera.setCenter({ 400.f, 300.f });
	float cameraY = 300.f;



	return config::config{ backgroundTexture ,camera, cameraY };
}



void drowBorders(sf::RenderWindow& window, Player& Player, Border& BorderGround, Border& BorderLeft, Border& BorderRight)
{
	window.draw(BorderGround.getBorder());
	window.draw(BorderLeft.getBorder());
	window.draw(BorderRight.getBorder());

	BorderGround.colisionWithPlayer(Player);
	BorderLeft.colisionWithPlayer(Player);
	BorderRight.colisionWithPlayer(Player);
}

void drawPlayer(sf::RenderWindow& window, Player& Player)
{
	pl::Keys Keys{ sf::Keyboard::Key::W, sf::Keyboard::Key::LControl,
					sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::Space, sf::Keyboard::Key::F };

	Player.handleInput(Keys);
	Player.falling();           // erst Physik
	window.draw(Player.getPlayer()); // dann zeichnen
}

void drawDoor(sf::RenderWindow& window, Door& door, Player& player, js::LevelData levelData)
{
	window.draw(door.getDoor());

	door.colisionWithPlayer(player.getPlayer(), window, levelData);
}

void drawChast(sf::RenderWindow& window, Chast& chast, Player& player, pl::Keys Keys)
{
	window.draw(chast.getChast());
	chast.openChast(player.getPlayer(), Keys);
}

void drawGUI(sf::RenderWindow& window, GUI& gui, pl::Keys Keys, Player& player)
{
	window.draw(gui.getInventar());

	gui.openInventar(Keys, player.getPlayer());
	gui.getInventarInfo();
}

