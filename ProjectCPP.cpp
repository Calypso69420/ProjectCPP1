#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Object.h"
#include "Game.h"
#include <vector>

std::vector<Object*> ObjectList;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping-pong Game!");
    // Game::window2 = &window;


	ObjectList.push_back(new Wall({ 90.0f, 50.0f }, 1100.0f, 20.0f));        /* Top Wall cords */
    ObjectList.push_back(new Wall({ 90.0f, 650.0f }, 1100.0f, 20.0f));    /* Bottom Wall cords */
    // Wall TOPWall({ 90.0f, 50.0f }, 1100.0f, 20.0f);        /* Top Wall cords */
    // Wall BOTTOMWall({ 90.0f, 650.0f }, 1100.0f, 20.0f);    /* Bottom Wall cords */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto x : ObjectList) {
            x->SelfDraw(window);
        }

        window.display();
    }

    return 0;
}