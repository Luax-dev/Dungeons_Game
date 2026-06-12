#pragma once
#include <SFML/Graphics.hpp>
#include "Dungeons.h"


class Player
{
public:
	Player();
	~Player();

	// Rückgabe als const-Referenz, vermeidet Kopien und erlaubt das Binden an const-Referenzen
	const sf::RectangleShape& getPlayer() const { return player; }

	void handleInput(pl::Keys& Keys);

	sf::Vector2f getCenter() const {
		return player.getPosition() + player.getSize() / 2.f;
	}

	void falling();


	void setPositionX(float x);
	void setPositionY(float y);
	void setOnGround(bool grounded);
	bool isOnGround() const { return onGround; }


private:
	sf::RectangleShape player;
	sf::Texture playerTexture;
	bool onGround = false;
};
