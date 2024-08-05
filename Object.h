#pragma once

#include <SFML/Graphics.hpp>

class Object		/* Abstract class (uses pure virtual methods) */
{
public:

	virtual void Tick(float TickTime) = 0;     /* Virtual - overrideable by derivative classes; [= 0] - no starting definition, more abstractness*/

	virtual void SelfDraw(sf::RenderWindow& window) = 0;	/* Pure virtual method */

	double velocity = 0.0;
	const double accelerationRate = 0.0;
	const double maxSpeed = 0.0;

	Object();
	~Object();

	sf::Vector2<float> location;
};