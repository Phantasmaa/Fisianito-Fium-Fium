#pragma once

#include "Player.hpp"
#include "Platform.hpp"
#include "Enemy.hpp"

/*Game engine class*/

class Game
{
private:
    // Variables
    // Window
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;
    // View
    sf::View view;
    // Time
    float deltaTime;
    sf::Clock clock;

    // Game objects
    Player player;
    Enemy enemy;
    Platform platform1;
    Platform platform2;
    Platform platform3;
    Collision c = player.getCollision();

    // Private functions
    void initVariables();
    void initWindow();
    void initEntitys();
    void initObjects();

public:
    // Constructor-Destructor
    Game();
    virtual ~Game();

    // Access
    const bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};