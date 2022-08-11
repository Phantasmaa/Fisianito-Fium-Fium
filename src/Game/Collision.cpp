#include "Game/Collision.hpp"

Collision::Collision(sf::RectangleShape &shape) : shape(shape) {}

void Collision::windowsCollision()
{
    // Left collision
    if (shape.getPosition().x < 0.0f)
        shape.setPosition(0.0f, shape.getPosition().y);
    // Top collision
    if (shape.getPosition().y < 0.0f)
        shape.setPosition(shape.getPosition().x, 0.0f);
    // RIght collision
    if (shape.getPosition().x + shape.getGlobalBounds().width > 1280.0f)
        shape.setPosition(1280.0f - shape.getGlobalBounds().width, shape.getPosition().y);
}

void Collision::checkCollisionWithObjects(EntityNode *objects)
{
    EntityNode *head = objects;
    while (head)
    {
        if (shape.getGlobalBounds().intersects(head->value.getShape().getGlobalBounds()))
        {
            shape.setFillColor(sf::Color::Red);
            return;
        }
        head = head->next_node;
    }
}

void Collision::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;
    while (head)
    {
        if (entityIsOnPlatform(head->value))
        {
            shape.setFillColor(sf::Color::Cyan);
            isOnPlatform = true;
            return;
        }
        head = head->next_node;
    }
    // std::cout<<head->value.getYCord()<<std::endl;
    isOnPlatform = false;
}

inline bool epsilonEquals(const float x, const float y, const float epsilon = 1E-5f)
{
    return abs(x - y) <= epsilon;
}

bool Collision::entityIsOnPlatform(Entity platform)
{
    /*
    Si la coordenada Y de player es platform.y - 50
    y la coordenada X de player está entre platform.X y platform.X + platform.width
    entonces player está sobre platform
    */
    int minusLimitOnX = platform.getXCord() - width;
    int superiorLimitOnX = platform.getXCord() + platform.getWitdh();
    int limitOnY = platform.getYCord() - height;

    if (posX > minusLimitOnX && posX < superiorLimitOnX && epsilonEquals(posY, limitOnY))
        return true;
    return false;
}