#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"
class Player : public Entity
{

// Constructor-Destructor
public:
    Player();
    virtual ~Player();
// Atributos
public:
    bool isJumping;
private:
    // Objects
    GameTextures texture;
    Animation *animation;
    // Gravity Variables
    int groundHeight;
    int roofHeight;
    float gravitySpeed;
    bool isOnPlatform;
    // Animation variables
    unsigned int row;
    float moveSpeed;
    bool faceRight;

// Métodos
private:
    void initVariables();
    void initObjects();
    void gravity();
    void updateInput();
    void windowsCollision();
    bool playerIsOnPlatform(Entity platform);
public:
    void update();
    void checkCollisionWithPlatforms(EntityNode *platforms);
    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
    Collision getCollision() { return Collision(shape); }
};