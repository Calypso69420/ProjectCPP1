#include "Ball.h"
#include <iostream>
#include <random>
#include <cassert>
#include <ranges>
#include <math.h>
#include "Racket.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "DisplayUI.h"

void Ball::Tick(float TickTime) {
    rainbow += TickTime;
    timer += TickTime;
    if (timer < 5) return;

    location += (float)velocity * direction * TickTime;
    velocity += accelerationRate * TickTime;
    if (accelerationRate > 0) accelerationRate -= 0.5 * TickTime;

    if ((location.y > 630.0f || location.y < 70.0f) &&
        (location.x > 50.0f && location.x < 1150.0f)) {
        direction.y *= -1;
        if (location.y > 625.0f) location.y = 630.0f;
        if (location.y < 75.0f) location.y = 70.0f;
    }

    auto Rackets = Game::GetAllObjectsOfType<Racket>();

    auto LeftRacket = Rackets[0];
    auto RightRacket = Rackets[1];

    if ((location.x < 110.0f && location.x > 100.0f) && (location.y > (LeftRacket->location.y - 10.0f) &&
        location.y < (LeftRacket->location.y + 150.0f))) {
        direction.x *= -1;                                               /* Left Racket bounce */
        location.x = 110.0f;
    }

    if ((location.x > 1150.0f && location.x < 1160.0f) && (location.y > (RightRacket->location.y - 10.0f) &&
        location.y < (RightRacket->location.y + 150.0f))) {
        direction.x *= -1;                                               /* Right Racket bounce */
        location.x = 1150.0f;
    }

    if (location.x > 1300.0f || location.x < -20.0f) {
        if (location.x > 1300.0f) {
            Game::Player1Score++;
            Game::GetAllObjectsOfType<DisplayUI>()[0]->ScoreMessage.setFillColor({ 0, 200, 255 });
            Game::GetAllObjectsOfType<DisplayUI>()[0]->ScoreMessage.setString("Player 1 scored!");
        }
        if (location.x < -20.0f) {
            Game::Player2Score++;
            Game::GetAllObjectsOfType<DisplayUI>()[0]->ScoreMessage.setFillColor({ 222, 56, 56 });
            Game::GetAllObjectsOfType<DisplayUI>()[0]->ScoreMessage.setString("Player 2 scored!");
        }
        Game::ScoreTimer = 4.0f;
        Game::RespawnBall();
    }
}

void Ball::SelfDraw(sf::RenderWindow& window) {
    circle.setPosition(location);
    circle.setFillColor(rainbow);
    window.draw(circle);
}

Ball::Ball(sf::Vector2<float> location, float radius) : radius(radius) { /* Initialization after : */
    circle = sf::CircleShape(radius);
    circle.setPosition(location);
    color = sf::Color(230, 230, 230);
    circle.setFillColor(color);

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> distrib(0.5, 1);
    std::uniform_int_distribution<> distrib2(0, 3);
    float xcord = distrib(gen);
    float ycord = sqrt(1 - xcord * xcord);

    int Directions = distrib2(gen);
    xcord *= -1 * (Directions & 1 ? 1 : -1);
    ycord *= -1 * (Directions & 2 ? 1 : -1);

    direction = {xcord, ycord};
    assert(abs(xcord * xcord + ycord * ycord - 1.0) < 0.001);

    this->location = location;				/* Location initialization */
}