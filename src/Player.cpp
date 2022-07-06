#include "Player.hpp"

//Constructor-Destructor
Player::Player(){
    this->initVariables();
    this->initShape();
}

Player::~Player(){

}

//Private functions
void Player::initVariables(){
    this->moveSpeed = 10.f;
    this->groundHeight = 500;
    this->gravitySpeed = 10.f;
    this->isJumping = false;
}

void Player::initShape(){
    this->shape.setPosition(20,500);
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

//Functions
int Player::getY(){
    return shape.getPosition().y;
}

void Player::gravity(){
    if(this->getY() < this->groundHeight && this->isJumping == false){
        this->shape.move(0.f,this->gravitySpeed);
    }
}

void Player::updateInput(){
    //Keyboard inputs
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->shape.move(0.f, -this->moveSpeed);
        isJumping = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->shape.move(-this->moveSpeed, 0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->shape.move(this->moveSpeed, 0.f);
    }
}
void Player::update(sf::RenderTarget* target){
    //Windows collision

    this->gravity();
    this->updateInput();

}

void Player::render(sf::RenderTarget* target){
    target->draw(this->shape);
}
