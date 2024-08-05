#include "Game.h"
#include "Wall.h"
#include "Ball.h"

int Game::Player1Score = 0;
int Game::Player2Score = 0;
double Game::ScoreTimer = 0.0;
	
void Game::RespawnBall(){
	auto ball = Game::GetAllObjectsOfType<Ball>()[0];	
	// auto it = std::find(ObjectList.begin(), ObjectList.end(), [](auto x) { return x == ball; } );
	/*auto it = std::find(ObjectList.begin(), ObjectList.end(), ball);
	if (it != ObjectList.end())
		ObjectList.erase(it);*/

	delete ball;
    ObjectList.push_back(new Ball({ 630.0f, 350.0f }, 10.0f));
}