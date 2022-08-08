#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"


enum JumpStatus{Neutral, FirstJump, SecondJump};

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
    float jumpSpeed;
    float accelerationY;
    bool isOnPlatform;
    bool hasJumped;
    JumpStatus jumpStatus;
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
    bool isOnFloor();
    bool playerIsOnPlatform(Entity platform);
public:
    void handleJump();
    void update();
    void checkCollisionWithPlatforms(EntityNode *platforms);
    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
    Collision getCollision() { return Collision(shape); }
};