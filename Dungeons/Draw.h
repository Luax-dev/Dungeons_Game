#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Border.h"
#include "Dungeons.h"
#include "door.h"
#include "LevelLoder.h"
#include "Chast.h"
#include "GUI.h"

config::config bevore();
void drowBorders(sf::RenderWindow& window, Player& Player, Border& BorderGround, Border& BorderLeft, Border& BorderRight);
void drawPlayer(sf::RenderWindow& window, Player& Player);
void drawDoor(sf::RenderWindow& window, Door& door, Player& player, js::LevelData levelData);
void drawChast(sf::RenderWindow& window, Chast& chast, Player& player, pl::Keys Keys);
void drawGUI(sf::RenderWindow& window, GUI& gui, pl::Keys Keys, Player& player);

void saveDataNewLevel(sf::RenderWindow& window, js::LevelData levelData);
void drawAndUpdateNewLevel(sf::RenderWindow& window);