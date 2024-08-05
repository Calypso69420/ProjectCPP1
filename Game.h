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
	static int Player1Score;
	static int Player2Score;
	static double ScoreTimer;
    
	template <typename T>									/* Template (szablon) Method that uses an input type given by the user */
	static std::vector<T*> GetAllObjectsOfType(){			/* W³asny szablon metody */
		std::vector<T*> cache;

		for (auto it = ObjectList.begin(); it != ObjectList.end(); it++){	/* Iterator */
			auto Obj = *it;
			auto x = dynamic_cast<T*>(Obj);
			if (x == nullptr) continue;
			cache.push_back(x);
		}

		return cache;
	}

	static void RespawnBall();
};

