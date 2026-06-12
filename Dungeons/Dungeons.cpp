#include <SFML/Graphics.hpp>
#include <iostream>
#include "Border.h"
#include "Player.h"
#include "Draw.h"
#include "door.h"
#include "LevelLoder.h"
#include "Chast.h"
#include "GUI.h"

int main()
{
	// Initialisierung von config
	config::config config = bevore();
	pl::Keys Keys{ sf::Keyboard::Key::W, sf::Keyboard::Key::LControl,
					sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::Space, sf::Keyboard::Key::F,
					sf::Keyboard::Key::Tab};




	// Initialisierung von game objects
	Border BorderGround(1600, 50, 0, 513);
	Border BorderLeft(50, 600, 225, 0);
	Border BorderRight(50, 600, 1550, 0);
	Player player;
	Door exitDoor(1463, 395, 75, 117);
	Chast chast;
	GUI gui;


	// Initialisierung von graphics
	sf::Sprite background(config.backgroundTexture);
	sf::RenderWindow window(sf::VideoMode({ cfg::WindowWidth, cfg::WindowHeight }), "Dungeons");
	js::LevelData levelData = LevelLoder::load("Level\\.json");



	// last configs
	window.setFramerateLimit(cfg::fps);
	window.setKeyRepeatEnabled(false);
	// Game loop
	saveDataNewLevel(window, levelData);
	std::cout << "\nLevel Data was load but if this prits out often ist bad wary bad!\n";
	while (window.isOpen()) {

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		sf::Vector2f playerCenter = player.getCenter();

		config.camera.setCenter({ playerCenter.x, config.cameraY });
		window.setView(config.camera);
		window.clear();
		window.draw(background);

		// Zeichnen der Spielobjekte
		drawChast(window, chast, player, Keys);
		drowBorders(window,player, BorderGround, BorderLeft, BorderRight);
		drawPlayer(window, player);
		drawDoor(window, exitDoor, player, levelData);
		drawGUI(window, gui, Keys, player);

		drawAndUpdateNewLevel(window);

		

		window.display();
	}
	return 0;
}