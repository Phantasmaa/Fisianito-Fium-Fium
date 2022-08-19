#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

class Player : public Entity
{
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
    bool isOnPlatform;
    bool isFiring;

    // Animation variables
    unsigned int row;
    float moveSpeed;
    bool faceRight;

    // Constructor-Destructor
    Player();
    virtual ~Player();

    // Functions
    void gravity();
    void updateInput();
    void update();

    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
    Collision getCollision() { return Collision(shape); }
};