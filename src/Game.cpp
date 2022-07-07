#include "Game.hpp"

//Constructor-Destructor
Game::Game(){
    this->initVariables();
    this->initWindow();
}

Game::~Game(){
    delete this->window;
}

//Private Functions
void Game::initVariables(){
    this->window = nullptr;
    this->videoMode.width = 1600;
    this->videoMode.height = 800;
}

void Game::initWindow(){
    this->window = new sf::RenderWindow(this->videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    this->window->setKeyRepeatEnabled(true);
    this->window->setFramerateLimit(60);
}

//Access
const bool Game::running() const{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents(){
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
    this->player.update(this->window);
}

void Game::render(){
    this->window->clear();
    //Draw game objects 
    this->player.render(this->window);
    this->window->display();
}
