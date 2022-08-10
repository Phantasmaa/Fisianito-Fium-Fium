#include "Game/Game.hpp"

// Constructor-Destructor
Game::Game()
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
    //initObjects();
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(true);
    this->window->setFramerateLimit(60);
}

void Game::initObjects()
{
}

void Game::initEntitys()
{
    player.initShape();
    map.initPlatforms();
    map.initObjects();
    this->ground.initAttributes(0,670,1280.0f,100.0f);
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
    this->deltaTime = this->clock.restart().asSeconds();
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;

        case sf::Event::KeyReleased:
            player.isJumping = false;
            break;
        }
    }
}

void Game::update()
{
    pollEvents();
    player.checkCollisionWithPlatforms(map.platforms);
    player.checkCollisionWithObjects(map.objects);
    player.update();
}

void Game::render()
{
    window->clear();
    // Draw game objects
    player.renderOnGame(this->window);
    ground.renderOnGame(this->window);
    map.renderPlatforms(this->window);
    map.renderObjects(this->window);
    window->display();
}
