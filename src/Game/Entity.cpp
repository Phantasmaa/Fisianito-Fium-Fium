#include "Game/Entity.hpp"

void Entity::initAttributes(int posX, int posY, float width, float height)
{
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
}

void Entity::initShape()
{
    shape.setPosition(posX, posY);
    shape.setSize(sf::Vector2f(width, height));
    isOnPlatform = false;
}

int Entity::getXCord()
{
    return posX;
}

int Entity::getYCord()
{
    return posY;
}

float Entity::getWitdh()
{
    return width;
}

float Entity::getHeight()
{
    return height;
}

void Entity::updateCords()
{
    posX = shape.getPosition().x;
    posY = shape.getPosition().y;
}

void Entity::moveEntity(float x_movement, float y_movement)
{   
    shape.move(x_movement, y_movement);
}

void Entity::renderOnGame(sf::RenderTarget *target)
{
    target->draw(shape);
}

int Entity::getRandomNumber(int a, int b){
    std::srand(static_cast<unsigned>(time(NULL)));
    int num;
    num = a+rand() % static_cast<int> (b+1-a);
    return num;
}


void Entity::logEntity(){
    std::cout<<"\t\tX: "<<posX <<" Y: "<<posY<<std::endl;
}
