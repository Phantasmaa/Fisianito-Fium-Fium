#include "Game.hpp"

//Constructor-Destructor
Game::Game(){
    initVariables();
    initEntitys();
    initWindow();
}

Game::~Game(){
    delete window;
}

//Private Functions
void Game::initVariables(){
    window = nullptr;
    videoMode.width = 640;
    videoMode.height = 480;
    platform.initAttributes(100, 200, 200.0, 50.0);    
    platform_2.initAttributes(350, 200, 200.0, 50.0);    

}


void Game::initEntitys(){
    player.initShape();
    platform.initShape();
    platform_2.initShape();

}


void Game::initWindow(){
    window = new sf::RenderWindow(videoMode, "GAME TESTING", sf::Style::Titlebar | sf::Style::Close);
    window->setKeyRepeatEnabled(true);
    window->setFramerateLimit(60);
}

//Access
const bool Game::running() const{
    return window->isOpen();
}

//Functions
void Game::pollEvents(){
    while (window->pollEvent(ev)){
        switch (ev.type){
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window->close();
                break;

            case sf::Event::KeyReleased:
                player.isJumping = false;
                break;
        }
    }
}

void Game::update(){
    pollEvents();
    player.checkIfIsOnPlatform(platform);
    player.update(platform);
}

void Game::render(){
    window->clear();
    //Draw game objects 
    player.renderOnGame(window);
    platform.renderOnGame(window);
    platform_2.renderOnGame(window);

    window->display();
}
