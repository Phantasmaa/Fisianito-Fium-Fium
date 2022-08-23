#include "Game/Entity.hpp"
#include <iostream>
#include <math.h>

void Entity::initAttributes(int posX, int posY, float width, float height)
{
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    this->movementDirection = Directions::Static;
}

void Entity::initShape()
{
    shape.setPosition(posX, posY);
    shape.setFillColor(sf::Color::White);
    shape.setSize(sf::Vector2f(width, height));
}

void Entity::initTexture(sf::Texture &texture){
    shape.setTexture(&texture);
}

float Entity::getXCord()
{
    return shape.getPosition().x;
}

float Entity::getYCord()
{
    return shape.getPosition().y;
}

float Entity::getWitdh()
{
    return width;
}

float Entity::getHeight()
{
    return height;
}

sf::RectangleShape Entity::getShape() { 
    return this->shape; 
}

const sf::FloatRect Entity::getBounds() const{
    return shape.getGlobalBounds();
}

void Entity::updateCords()
{
    posX = shape.getPosition().x;
    posY = shape.getPosition().y;
}

void Entity::moveEntity(float x_movement, float y_movement)
{
    shape.move(x_movement, y_movement);
    updateCords();
}
//mover moneda
void Entity::moveHeart() {
    shape.move(5000, 3);
}
void Entity::renderOnGame(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

void Entity::logEntity()
{
    std::cout << "\t\tX: " << posX << " Y: " << posY << std::endl;
}

CollisionDirection Entity::checkCollision(Entity entity)
{
    float distanceBetweenEntitys = posY - entity.getYCord();
    if (shape.getGlobalBounds().intersects(entity.getShape().getGlobalBounds()))
    {
        float offset = entity.getYCord() - posY + height;
        if (distanceBetweenEntitys < 0)
        {
            shape.setPosition(posX, entity.getYCord() - height);
            updateCords();
            return CollisionDirection::Top;
        }
        else
        {
            shape.setPosition(posX, entity.getYCord() + height);
            updateCords();

            return CollisionDirection::Bottom;
        }
    }
    return CollisionDirection::Null;
}

int Entity::getRandomNumber(int a, int b)
{
    // srand(time(NULL));
    int num;
    num = a + rand() % (b + 1 - a);
    return num;
}
