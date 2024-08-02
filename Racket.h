#pragma once
#include "Wall.h"
#include <exception>
#include <stdexcept>
class Racket : public Wall
{
	void Tick(float TickTime) override;
	void SelfDraw(sf::RenderWindow& window) override;

	int PlayerID;

	Racket(sf::Vector2<float> location, float sizex, float sizey, int ID);
};

