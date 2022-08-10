#include "Game.hpp"

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
    videoMode.width = 1600;
    videoMode.height = 800;
    deltaTime = 0.0f;
    initObjects();
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(true);
    this->window->setFramerateLimit(60);
}

void Game::initObjects()
{
    platform1.initAttributes(-100, 500, 100, 400);
    platform2.initAttributes(800, 500, 100, 400);
    platform3.initAttributes(-100, 670, 1000, 50);
}

void Game::initEntitys()
{
    player.initShape();
    enemy.initShape();
    //platform1.initShape();
    //platform2.initShape();
    platform3.initShape();
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
    player.update();
    enemy.update();
    //platform1.getCollision().checkCollision(c, 1.0f);
    //platform2.getCollision().checkCollision(c, 1.0f);
    platform3.getCollision().checkCollision(c, 1.0f);
}

void Game::render()
{
    window->clear();
    window->setView(this->view);
    view.setCenter(player.getPosition());
    // Draw game objects
    player.renderOnGame(this->window);
    enemy.renderOnGame(this->window);
    platform1.renderOnGame(this->window);
    platform2.renderOnGame(this->window);
    platform3.renderOnGame(this->window);
    window->display();
}
