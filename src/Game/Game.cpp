#include "Game/Game.hpp"

// Constructor-Destructor
Game::Game() : view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1600.0f, 800.0f))
{
    initVariables();
    createPlatforms();
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
    videoMode.width = 640;
    videoMode.height = 480;
    deltaTime = 0.0f;
    // initObjects();
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
    initPlatforms();
}

void Game::createPlatforms()
{
    platforms = new EntityNode();
    int baseX = 500, baseY = 550;
    EntityNode *head = platforms;
    for (int i = 0; i < 1; i++)
    {
        Platform platform;
        int addX = 300 * i;
        int addY = 100 * i;
        platform.initAttributes(baseX + addX, baseY - addY, 400.0f, 50.0f);
        head->value = platform;
        head->next_node = new EntityNode();
        head = head->next_node;
    }
}

void Game::initPlatforms()
{
    EntityNode *head = platforms;
    while (head)
    {
        head->value.initShape();
        head = head->next_node;
    }
}

void Game::renderPlatforms()
{
    EntityNode *head = platforms;
    while (head)
    {
        head->value.renderOnGame(this->window);
        head = head->next_node;
    }
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
            player.isJumping = false;

            break;
        }
        }
    }
}

void Game::update()
{
    pollEvents();
    player.checkCollisionWithPlatforms(platforms);
    player.update();
}

void Game::render()
{
    window->clear();
    window->setView(this->view);
    view.setCenter(player.getPosition());
    // Draw game objects
    player.renderOnGame(this->window);
    renderPlatforms();
    window->display();
}
