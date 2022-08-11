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
    enum animationTop {iddleRow, runR, runL, jumpR, jumpL};
    Animation *animation;
    //Ciclo de animaciones total
    Frame *iddleR=NULL;
    Frame *iddleL=NULL;
    Frame *runAndJump=NULL;
    Frame *hitHurtR=NULL;
    Frame *hitHurtL=NULL;
    //Animacion actual
    Frame *currentCycle;

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
    void fillFrames(int numFrames,int startX, int rectWidth, Frame *frames);
    void gravity();
    void updateInput();
    void update(float dt);
    void getAction();

    // other functions
    sf::Vector2f getPosition() { return shape.getPosition(); }
    Collision getCollision() { return Collision(shape); }
};