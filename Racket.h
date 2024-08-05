#pragma once
#include "Wall.h"
#include <exception>
#include <stdexcept>
class Racket : public Wall /* Inheritance */
{
public:
	void Tick(float TickTime) override;

	int PlayerID;
	const double maxSpeed = 250.0;
	double velocity = 0.0;
	const double accelerationRate = 900.0;

	Racket(sf::Vector2<float> location, float sizex, float sizey, int ID);
};

