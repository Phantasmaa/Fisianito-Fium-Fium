#include <iostream>
#include "Game.hpp"

int main()
{
    // Init Game
    Game game;
    //Variables de tiempo para la animación
    sf::Clock clock;
   
    clock.restart();

    // Game loop
    while (game.running())
    {
        // Update
        game.update(clock.getElapsedTime().asMicroseconds());
        // Render
        game.render();
        //Restart clock
        clock.restart();
    }

    return 0;
}