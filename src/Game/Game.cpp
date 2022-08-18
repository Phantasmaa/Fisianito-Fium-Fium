#include "Game/Game.hpp"

// Constructor-Destructor
Game::Game() : view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1600.0f, 800.0f))
{
    initVariables();
    initEntitys();
    initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    videoMode.width = 1280;
    videoMode.height = 720;
    deltaTime = 0.0f;
    // initObjects();
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(true);
    this->window->setFramerateLimit(60);
}

void Game::initEntitys()
{
    player.initShape();
    // initPlatforms();
    map.initPlatforms();
    map.initObjects();
    this->ground.initAttributes(0, 670, 1280.0f, 100.0f);
    this->ground.initShape();
}

// Access
const bool Game::running() const
{
    return this->window->isOpen();
}

// Functions
void Game::pollEvents()
{
    deltaTime = clock.restart().asSeconds();
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                window->close();
            break;

        case sf::Event::KeyReleased:
        {
            if (ev.key.code == sf::Keyboard::F)
                player.shotBullet();
            player.movementDirection = Directions::Down;
            player.isJumping = false;
            break;
        }
        }
    }
}

void Game::update()
{
    pollEvents();
    player.update(map.platforms);
    enemy.checkCollisionWithPlatforms(map.platforms);
    player.checkCollisionWithObjects(map.objects);
    enemy.update();
}

void Game::render()
{
    window->clear();
    //   Draw game objects
    player.renderOnGame(this->window);
    player.renderBullets(this->window);
    ground.renderOnGame(this->window);
    map.renderPlatforms(this->window);
    map.renderObjects(this->window);
    enemy.renderOnGame(this->window);
    // renderPlatforms();
    window->display();
}
