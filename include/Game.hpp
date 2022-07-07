#pragma once

#include "Player.hpp"

/*Game engine class*/

class Game {
    private:
        //Variables
        //Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;

        //Game objects
        Player player;

        //Private functions
        void initVariables();
        void initWindow();
    public:
        //Constructor-Destructor
        Game();
        virtual ~Game();

        //Access
        const bool running() const;

        //Functions
        void pollEvents();
        void update();
        void render();

};