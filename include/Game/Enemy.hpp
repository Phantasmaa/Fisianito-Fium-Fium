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
    // Variables
    // sf::RectangleShape body;
    // Private functions
    void initVariables();
    void initObjects();

public:
    // Objects
    GameTextures texture;
    Animation *animation;

    // Gravity Variables
    int groundHeight;
    int roofHeight;
    float gravitySpeed;
    bool isJumping;

    // Animation variables
    float moveSpeed;
    float fallSpeed;
    unsigned int row;
    bool faceRight;

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