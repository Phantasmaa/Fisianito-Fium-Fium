#include "Game.hpp"

//Constructor-Destructor
Game::Game():
    view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1600.0f,800.0f))    
{
    this->initVariables();
    this->initWindow();
    this->initObjects();
}

Game::~Game(){
    delete this->window;
}

//Private Functions
void Game::initVariables(){
    this->window = nullptr;
    this->videoMode.width = 1600;
    this->videoMode.height = 800;
    this->deltaTime = 0.0f;
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(this->videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(true);
    this->window->setFramerateLimit(60);
}

void Game::initObjects(){
    this->platform1 = new Platform(500.f,600.f);
    this->platform2 = new Platform(800.f,500.f);
}

//Access
const bool Game::running() const{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents(){
    this->deltaTime = this->clock.restart().asSeconds();
    while (this->window->pollEvent(this->ev)){
        switch (this->ev.type){
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;

            case sf::Event::KeyReleased:
                this->player.isJumping = false;
                break;
        }
    }
}

void Game::update(){
    this->pollEvents();
    this->player.update();
    this->platform1->getCollision().checkCollision(c, 1.0f);
    this->platform2->getCollision().checkCollision(c, 1.0f);
}

void Game::render(){
    this->window->clear();
    this->window->setView(this->view);
    this->view.setCenter(player.getPosition());
    //Draw game objects 
    this->player.render(this->window);
    this->platform1->render(this->window);
    this->platform2->render(this->window);
    this->window->display();
}
