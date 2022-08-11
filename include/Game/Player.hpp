#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"

enum JumpStatus
{
    Neutral,
    FirstJump,
    SecondJump
};

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
    void initPlayer();
    void gravity();
    void updateInput();
    void handleKeyPressed(float &velocityY, sf::Vector2f &movement, float deltaTime);
    bool isOnFloor();

public:
    void handleJump();
    void update(EntityNode *platforms);
    void checkCollisionWithPlatforms(EntityNode *platforms);
    void windowsCollision();
    void checkCollisionWithObjects(EntityNode *objects);
    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
};