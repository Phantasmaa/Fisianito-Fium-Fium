#pragma once

#include "Player.hpp"
#include "Platform.hpp"
#include "Enemy.hpp"
#include "Maps.hpp"
#include "DataStructures/EntityNode.hpp"
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
    EntityNode *platforms;
    Enemy enemy;
    Platform ground;
    Maps map;

    // Private functions
    void initVariables();
    void initWindow();
    void initEntitys();
    void initObjects();

    // Platforms
    void createPlatforms();
    void initPlatforms();
    void renderPlatforms();

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