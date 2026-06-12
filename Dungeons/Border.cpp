#include "Border.h"
#include "Player.h"
#include <iostream>

Border::Border(float size_W, float size_H, float x, float y)
{
	border.setSize({ size_W, size_H });
	border.setFillColor(sf::Color::Red);
	border.setPosition({ x, y });
}

Border::~Border()
{
}

void Border::colisionWithPlayer(Player& player)
{
    sf::RectangleShape playerShape = player.getPlayer();

    auto intersection = border.getGlobalBounds().findIntersection(playerShape.getGlobalBounds());

    if (!intersection)
    {
        return; // Keine Kollision
    }

    sf::FloatRect inter = intersection.value();

    // Bestimme ob Kollision von oben oder von der Seite kommt
    // Wenn die Überschneidung breiter als hoch ist → Spieler kommt von oben/unten
    // Wenn die Überschneidung höher als breit ist → Spieler kommt von der Seite

    sf::Vector2f playerPos = playerShape.getPosition();
    sf::Vector2f borderPos = border.getPosition();

    if (inter.size.x > inter.size.y)
    {
        // Vertikale Kollision (oben/unten)
        float playerBottom = playerPos.y + playerShape.getSize().y;
        float borderTop = borderPos.y;

        if (playerBottom <= borderTop + inter.size.y + 1)
        {
            // Spieler kommt von oben → auf Border stellen
            player.setPositionY(borderTop - playerShape.getSize().y);
            player.setOnGround(true);
        }
        // von unten: nichts tun (oder Decke einbauen)
    }
    else
    {
        // Horizontale Kollision (Seite)
        float playerRight = playerPos.x + playerShape.getSize().x;
        float borderLeft = borderPos.x;

        if (playerRight <= borderLeft + inter.size.x + 1)
        {
            // Spieler kommt von links
            player.setPositionX(borderLeft - playerShape.getSize().x);
        }
        else
        {
            // Spieler kommt von rechts
            player.setPositionX(borderPos.x + border.getSize().x);
        }
    }
}
