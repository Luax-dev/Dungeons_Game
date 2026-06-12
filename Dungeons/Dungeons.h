#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "LevelLoder.h"

namespace cfg
{
	const int fps = 60;

	const int WindowWidth = 800;
	const int WindowHeight = 600;

}

namespace items
{
	struct item
	{
		std::string name;
		std::string description;
		const char* texturePath;
		float value;
		int maxStackSize = 99;
	};

	const item Items[4]
	{
		{"Healing", "Eine Healing die 10 hp wieder hetstellt", "Img\\AS\\Healing", 10},
		{"EnterHacken", "Mit einem Enter Hacken kann man sich zu wit entvernten orten zihen", "Img\\AS\\EnterHacken", 400, 1},
		{"Bombe", "Eine Beombe macht jedem gegner 50 schaden aber sie hat auch nur einen gewissen radius", "Img\\AS\\Bomb", 50},
		{"SchildTrank", "Eine Schild Trank reduzirt den schaden um 50%", "Img\\AS\\SchildTrank", 0.5}
	};

}


namespace pl
{
	struct Keys
	{
		sf::Keyboard::Key up;
		sf::Keyboard::Key down;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key jump;

		sf::Keyboard::Key open;
		sf::Keyboard::Key inventar;
	};

	struct inventar
	{
		int gold = 0;
		int healthPotions = 0;
		int keys = 0;
		
		int atackPower = 10;
		int defensePower = 5;

		items::item infPlase[9] = {};
	};

	// Deklaration: extern, die Definition erfolgt genau einmal (z.B. in GUI.cpp)
	extern inventar& inventarInfo;

}

namespace config
{

	struct config
	{
		sf::Texture backgroundTexture;

		sf::View camera;

		float cameraY;

	};
}

namespace lv
{

	extern js::LevelData LevelData;

	extern bool newLevel;
}

