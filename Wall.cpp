#include "Wall.h"
#include <SFML/Graphics.hpp>
#include <Utility>

void Wall::Tick(float TickTime) {
	 return;
}

void Wall::SelfDraw(sf::RenderWindow& window) {
	 window.draw(rectangle);
}

Wall::Wall(){}

Wall::Wall(sf::Vector2<float> location, float sizex, float sizey) : width(sizex), height(sizey) { /* Initialization after : */
	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setPosition(location);
	color = sf::Color(230, 230, 230);
	rectangle.setFillColor(color);
	this->location = location;				/* Location initialization */
}