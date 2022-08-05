#pragma once

#include "Player.hpp"
#include "Platform.hpp"

/*Game engine class*/

class Game {
    private:
        //Variables
        //Window
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event ev;
        //View
        sf::View view;
        //Time
        float deltaTime;
        sf::Clock clock;

        //Game objects
        Player player;
        Platform* platform1;
        Platform* platform2;
        Collision c = player.getCollision();

        //Private functions
        void initVariables();
        void initWindow();
        void initObjects();
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