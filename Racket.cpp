#include "Racket.h"
#include <SFML/Graphics.hpp>

Racket::Racket(sf::Vector2<float> location, float sizex, float sizey, int ID) : Wall(location, sizex, sizey), PlayerID(ID){
	switch (ID){
		case 0:
			color = sf::Color(222, 56, 56);
			break;
		case 1:
			color = sf::Color(0, 200, 255);
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
		if (velocity < maxSpeed) {
			velocity += accelerationRate * TickTime;
			if (velocity > maxSpeed) {
				velocity = maxSpeed;
			}
		}
	}

}