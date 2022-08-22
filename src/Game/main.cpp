#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{
    // Init Game

    srand(time(NULL));
    Game game;
    sf::Clock clock;
    float accumulator = 0;
    const float timestep = 1.0f / 60.0f; // 60hz update frequency
    // Game loop
    while (game.running())
    {
        // Update
        accumulator += clock.restart().asSeconds();
        while (accumulator >= timestep)
        {
            accumulator -= timestep;
            game.update(clock.getElapsedTime().asMicroseconds());
        }

        // Render
        game.render();
    }

    return 0;
}