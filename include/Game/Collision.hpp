#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"
//#include <iostream>

class Collision : public Entity
{
private:
    sf::RectangleShape &shape;

public:
    // Constructor-Destructor
    Collision(sf::RectangleShape &shape);
    virtual ~Collision(){};

public:
    void initVariables();

private:
    // bool isOnPlatform;
    bool entityIsOnPlatform(Entity platform);

public:
    void windowsCollision();
    void checkCollisionWithPlatforms(EntityNode *platforms);
    void checkCollisionWithObjects(EntityNode *objects);
};