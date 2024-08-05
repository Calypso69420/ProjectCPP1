#include "Racket.h"
#include <SFML/Graphics.hpp>

Racket::Racket(sf::Vector2<float> location, float sizex, float sizey, int ID) : Wall(location, sizex, sizey), PlayerID(ID){		/* Constructor */
	switch (ID){
		case 0:
			color = sf::Color(0, 200, 255);
			rectangle.setFillColor(color);
			break;
		case 1:
			color = sf::Color(222, 56, 56);
			rectangle.setFillColor(color);
			break;
		default:
			throw std::invalid_argument("Passed PlayerID is invalid!");
	}
}

void Racket::Tick(float TickTime){
	auto keyUp = PlayerID == 0 ? sf::Keyboard::W : sf::Keyboard::Up;
	auto keyDown = PlayerID == 0 ? sf::Keyboard::S : sf::Keyboard::Down;
	sf::Vector2<float> MoveDelta;

	if (sf::Keyboard::isKeyPressed(keyUp)){
		location.y -= velocity * TickTime;
		velocity += accelerationRate * TickTime;
		if (velocity > maxSpeed) {
			velocity = maxSpeed;
		}
	}
	
	else if (sf::Keyboard::isKeyPressed(keyDown)){
		location.y += velocity * TickTime;
		velocity += accelerationRate * TickTime;
		if (velocity > maxSpeed) {
			velocity = maxSpeed;
		}
	}

	else {
		velocity += -accelerationRate * 5 * TickTime;
		if (velocity < 0)
			velocity = 0;
	}

	if (location.y < 70.0) {
		location.y = 70.0;
	}
	
	if (location.y > (650.0 - height)) {
		location.y = (650.0 - height);
	}

}