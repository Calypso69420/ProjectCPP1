#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "Object.h"
#include "Game.h"
#include "Racket.h"
#include <vector>
#include <chrono>
#include "Ball.h"
#include "DisplayUI.h"
#include <format>

std::vector<Object*> ObjectList;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Ping-pong Game!");

	ObjectList.push_back(new Wall({ 90.0f, 50.0f }, 1100.0f, 20.0f));        /* Top Wall cords */
    ObjectList.push_back(new Wall({ 90.0f, 650.0f }, 1100.0f, 20.0f));    /* Bottom Wall cords */
    ObjectList.push_back(new Racket({ 90.0f, 285.0f }, 20.0f, 150.0f, 0));    /* First/Left Racket cords */
    ObjectList.push_back(new Racket({ 1170.0f, 285.0f }, 20.0f, 150.0f, 1));    /* Second/Right Racket cords */
    ObjectList.push_back(new Ball({ 630.0f, 350.0f }, 10.0f));    /* Ball cords */
    ObjectList.push_back(new DisplayUI());          /* Polimorphism (list containing diverse objects that inherit from one class) */
          
    auto LastTime = std::chrono::high_resolution_clock::now();
    float TickTime = 0;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Game::GetAllObjectsOfType<DisplayUI>()[0]->FPSCounter.setString(std::format("{} FPS", (int)(1 / TickTime)));

        for (auto x : ObjectList) {         /* Range-based for loop */
            x->SelfDraw(window);            /* Polimorphism list usage */
            x->Tick(TickTime);
        }

        window.display();

		auto CurrentTime = std::chrono::high_resolution_clock::now();
		TickTime = (double)(std::chrono::duration_cast<std::chrono::microseconds>(CurrentTime - LastTime).count()) / 1'000'000; /* Measuring seconds */
        LastTime = CurrentTime;
    }

    return 0;
}