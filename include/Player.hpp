#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"

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
    int animationRow;
    Animation *animation;
    //Ciclo de animaciones
    Frame *iddleR;
    Frame *iddleL;
    Frame *runR;
    Frame *runL;

    GameTextures texture;

    // Gravity Variables
    int groundHeight;
    int roofHeight;
    float gravitySpeed;
    bool isJumping;
    bool isOnPlatform;

    // Animation variables
    float moveSpeed;
    bool faceRight;
    bool isMoving;

    // Constructor-Destructor
    Player();
    virtual ~Player();

    // Functions
    void gravity();
    void updateInput();
    void update(float dt);

    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
    Collision getCollision() { return Collision(shape); }
};