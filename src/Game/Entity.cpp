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
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(width, height));
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

void Entity::renderOnGame(sf::RenderTarget *target)
{
    target->draw(shape);
}

void Entity::logEntity()
{
    std::cout << "\t\tX: " << posX << " Y: " << posY << std::endl;
}

CollisionDirection Entity::checkCollision(Entity entity)
{
    /*
Si la coordenada Y de player es platform.y - 50
y la coordenada X de player está entre platform.X y platform.X + platform.width
entonces player está sobre platform
*/
    // Limites en X
    int minusLimitOnX = entity.getXCord() - (width / 2.0f);
    int superiorLimitOnX = entity.getXCord() + entity.getWitdh();
    // Limite en Y
    float centerOfPlayer = posY + height / 2.0f;
    float centerOfPlatformOnY = entity.getYCord() + entity.getHeight() / 2.0f;
    float distanceBetweenCenters = centerOfPlatformOnY - centerOfPlayer;
    float limitOnY = (height + entity.getHeight()) / 2.0f;
    bool distanteIsCloseToLimit = fabs(distanceBetweenCenters) <= limitOnY;

    if (posX >= minusLimitOnX && posX <= superiorLimitOnX && distanteIsCloseToLimit)
    {
        if (distanceBetweenCenters > 0)
            return CollisionDirection::Top;
        else
            return CollisionDirection::Bottom;
    }
    return CollisionDirection::Null;
}