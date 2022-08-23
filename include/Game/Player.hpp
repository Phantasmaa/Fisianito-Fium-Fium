#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"
#include "Bullet.hpp"
#include "Score.hpp"
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
    int live;
    bool isAlive;
    bool isCollideWithEnemy;

private:
    // Objects
    GameTextures texture;

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

    Directions faceDirection;

public:
    // Objects
    int animationRow;
    enum animationTop
    {
        iddleRow,
        runR,
        runL,
        jumpR,
        jumpL
    };
    enum animationFrame
    {
        iddleR,
        iddleL,
        runJump,
        hitR,
        hitL
    };
    Animation *animation;
    // Animacion actual
    int currentCycle;
    // Ciclo de animaciones total
    Frame **frameCycles = new Frame *[5];
    void createAnimationCycle();

    // Métodos
private:
    void initVariables();
    void initObjects();
    void initPlayer();
    void gravity();
    void updateInput();
    void checkIfCarajitoVive();
    void handleKeyPressed(float &velocityY, sf::Vector2f &movement, float deltaTime);
    bool isOnFloor();
    void updateBullets();

public:
    void handleJump();
    void getAction();
    bool isFacingRight();
    Directions getFaceDirection();
    void update(EntityNode *platforms, float dt);
    void checkCollisionWithPlatforms(EntityNode *platforms);
    void windowsCollision();
    void checkCollisionWithObjects(EntityNode *objects);
    void changeColorWhenCollideWithEnemy();
    void checkCollisionWithTeleport(EntityNode* coins);
    void checkCollisionWithHeart(EntityNode* coins,Score* points);

    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
};