#include "Player.h"
#include <iostream>
//#include "C:\Users\las\source\repos\Dungeons\includs\json.hpp"

Player::Player()
{


	player.setSize({ 60, 100 });
	player.setFillColor(sf::Color::White);
	player.setPosition({ 400, 0 });

	if (!playerTexture.loadFromFile("Img\\PL\\Player_0.png"))
	{
		std::cout << "\nError: Player img not found!\n" << std::endl;
		exit(-1);
	}
	player.setTexture(&playerTexture);

}

Player::~Player()
{
}


void Player::handleInput(pl::Keys& Keys)
{
	//if (sf::Keyboard::isKeyPressed(Keys.up))
	//{
	//	player.move({ 0, -5 });
	//}
	if (sf::Keyboard::isKeyPressed(Keys.down))
	{
		player.setSize({ 70, 50 });
		//player.move({ 0, 50 }); // Spieler nach unten bewegen, damit er nicht in der Luft schwebt
	}
	else
	{
		player.setSize({ 60, 100 });
	}

	if (sf::Keyboard::isKeyPressed(Keys.left))
	{
		player.move({ -5, 0 });
	}

	if (sf::Keyboard::isKeyPressed(Keys.right))
	{
		player.move({ 5, 0 });
	}

	//bool isPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && onGround)
	{
		player.move({ 0, -150 });
	}
	//wasPressed = isPressed;
}


void Player::setPositionX(float x) {
	sf::Vector2f pos = player.getPosition();
	pos.x = x;
	player.setPosition(pos);
}

void Player::setPositionY(float y) {
	sf::Vector2f pos = player.getPosition();
	pos.y = y;
	player.setPosition(pos);
}

void Player::setOnGround(bool grounded) {
	onGround = grounded;
}


void Player::falling()
{
	onGround = false; // wird jedes Frame zurückgesetzt, Border setzt es wieder auf true

	sf::Vector2f pos = player.getPosition();
	if (pos.y < 6000)
	{
		pos.y += 8;
		std::cout << "\nPlayer is falling \n";
	}

	if (pos.y >= 1000)
	{
		player.setPosition({ 0, 0 });
		std::cout << "\Player out of mapp but this is actuely not posible! If u see this its not good!\n";
	}

	player.setPosition(pos);
	std::cout << "\nNew Player pos is set!\n";
}