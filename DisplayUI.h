#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>

class DisplayUI : public Object
{
public:
	virtual void Tick(float TickTime) override;  
	virtual void SelfDraw(sf::RenderWindow& window) override;

	sf::Text ScoreCounter;
	sf::Font font;
	sf::Text ScoreMessage;
	sf::Text FPSCounter;

	DisplayUI();
};