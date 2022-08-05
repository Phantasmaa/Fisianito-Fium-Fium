#include "Platform.hpp"

Platform::Platform(float posX, float posY){
    this->initVariables();
    this->initShape();
    this->shape.setPosition(posX,posY);
}

Platform::~Platform(){

}

void Platform::initVariables(){
    this->size = sf::Vector2f(400.0f, 50.0f);
}

void Platform::initShape(){
    this->shape.setSize(size);
    this->shape.setOrigin(size/2.0f);
    this->shape.setFillColor(sf::Color::White);
}


void Platform::update(){
    //Windows collision

}

void Platform::render(sf::RenderTarget* target){
    target->draw(this->shape);
}