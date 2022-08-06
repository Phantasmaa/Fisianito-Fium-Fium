#include <iostream>
#include "Game/Game.hpp"

int main()
{
    // Init Game
    Game game;

    // Game loop
    while (game.running())
    {
        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}