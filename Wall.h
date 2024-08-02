#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>

class Wall : public Object											/* Inheriting PUBLICLY from class Object */
{
public:
	void Tick(float TickTime) override;								/* Overriding from */
	void SelfDraw(sf::RenderWindow& window) override;

	float width;
	float height;
	sf::RectangleShape rectangle;
	sf::Color color;

	Wall();															/* Constructors */

	Wall(sf::Vector2<float> location, float sizex, float sizey);
};

