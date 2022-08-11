#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"

class Enemy : public Entity
{
public:
    // Constructor-Destructor
    Enemy();
    virtual ~Enemy();
private:
    void initVariables();
    void initObjects();

public:
    // Objects
    GameTextures texture;

    // Gravity & Speed Variables
    int groundHeight;
    bool isJumping;
    float gravitySpeed;
    float moveSpeed;
    float fallSpeed;
private:
    bool playerIsOnPlatform(Entity platform);

public:
    void checkCollisionWithPlatforms(EntityNode *platforms);
    // Functions
    void initEnemy();
    void moveEnemy();
    void gravity();
    void updateInput();
    void update();
};