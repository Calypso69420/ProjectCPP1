#include "DisplayUI.h"
#include "Game.h"
#include <exception>
#include <format>
#include <SFML/Graphics.hpp>

DisplayUI::DisplayUI(){
	font = sf::Font();
	if (!font.loadFromFile("ARLRDBD.ttf"))
	{
	    throw std::exception("Font file not found");		/* Wyj¹tek/Exception */
	}

	for (auto x : std::vector<sf::Text*> { &ScoreCounter, &ScoreMessage, &FPSCounter } ){
		*x = sf::Text();
		x->setFont(font);
		x->setCharacterSize(32);
		x->setStyle(sf::Text::Bold);
	}
	ScoreCounter.setPosition({606.0f, 4.0f});
	FPSCounter.setPosition({4.0f, 4.0f});
	ScoreMessage.setCharacterSize(64);
	ScoreMessage.setPosition({383.0f, 220.0f});
}

void DisplayUI::Tick(float TickTime){
	ScoreCounter.setString(std::format("{} - {}", Game::Player1Score, Game::Player2Score));
	if (Game::ScoreTimer > 0.0) {
		Game::ScoreTimer -= TickTime;
	}
}

void DisplayUI::SelfDraw(sf::RenderWindow& window){
	window.draw(ScoreCounter);
	window.draw(FPSCounter);
	if (Game::ScoreTimer > 0.0) {
		window.draw(ScoreMessage);
	}
}