#include <iostream>
#include "Game.hpp"

int main()
{
    // Init Game
    Game game;
    sf::Clock clock;
    // Game loop
    while (game.running())
    {
        // Update
        game.update(clock);
        // Render
        game.render();
        //Restart clock
        if(clock.getElapsedTime().asSeconds()==2.0f){
            clock.restart();
        }
    }

    return 0;
}