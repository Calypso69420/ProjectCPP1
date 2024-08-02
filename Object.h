#pragma once

#include <SFML/Graphics.hpp>

class Object
{
public:

	virtual void Tick(float TickTime) = 0;     /* Virtual - overrideable by derivative classes; [= 0] - no starting definition, more abstractness*/

	virtual void SelfDraw(sf::RenderWindow& window) = 0;

	double velocity;
	double accelerationRate;
	double maxSpeed;

	sf::Vector2<float> location;
};