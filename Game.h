#pragma once

#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Object.h"
#include <vector>

// https://stackoverflow.com/a/3627979
extern std::vector<Object*> ObjectList;

class Game
{
public:
    // static sf::RenderWindow* window2;
	// static std::vector<Object*> ObjectList;
	static void TickGame();
	static void StartGame();
};

