#pragma once
#include "Object.h"
#include "Rainbow.h"

class Ball :
    public Object
{
public:
	void Tick(float TickTime) override;								/* Overriding from */
	void SelfDraw(sf::RenderWindow& window) override;

	float radius;
	sf::Vector2<float> direction;
	sf::CircleShape circle;
	sf::Color color;
	double velocity = 0.0;
	double accelerationRate = 25.0;
	const double maxSpeed = 200.0;
	double timer = 0.0;
	Rainbow rainbow;

	Ball(sf::Vector2<float> location, float radius);

};

