#include "Player.hpp"

//Constructor-Destructor
Player::Player(){
    this->initVariables();
    this->initShape();
    this->initObjects();
}

Player::~Player(){

}

//Private functions
void Player::initVariables(){
    //Gravity
    this->groundHeight = 700;
    this->roofHeight = 300;
    this->gravitySpeed = 10.f;
    this->isJumping = false;
    //Animation
    this->moveSpeed = 50.f;
    this->faceRight = true;
    this->row = 0;
}

void Player::initShape(){
    this->body.setOrigin(body.getSize()/2.0f);
    this->body.setPosition(20,this->groundHeight);
    this->body.setSize(sf::Vector2f(100.f,100.f));
    this->body.setTexture(&texture.playerTexture);
}

void Player::initObjects(){
    this->animation = new Animation(&texture.playerTexture, sf::Vector2u(2,5), 1.0f);
}

//Functions
int Player::getY(){
    return body.getPosition().y;
}

void Player::gravity(){
    if(this->getY() < this->groundHeight && this->isJumping == false){
        this->body.move(0.f,this->gravitySpeed);
    }

    if(this->getY() > this->roofHeight){
        
    }
}

void Player::updateInput(float deltaTime){
    sf::Vector2f movement(0.0f,0.0f);
    //Keyboard inputs
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        movement.y -= moveSpeed * deltaTime;
        isJumping = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        movement.x -= moveSpeed * deltaTime;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        movement.x += moveSpeed * deltaTime;
    }

    if(movement.x == 0.0f){
        row = 0;
    }
    else{
        row = 1;
        if(movement.x > 0.0f){
            faceRight = true;
        }
        else{
            faceRight = false;
        }
    }
    animation->update(row,deltaTime,faceRight);
    this->body.setTextureRect(this->animation->uvRect);
    body.move(movement);
}
void Player::update(){
    this->gravity();
    this->updateInput(0.07f);

}

void Player::render(sf::RenderTarget* target){
    target->draw(this->body);
}
