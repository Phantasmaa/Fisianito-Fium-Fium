

#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "Entity.hpp"
#include "DataStructures/EntityNode.hpp"
#include "DataStructures/BulletNode.hpp"

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
    // Gravity & Speed Variables
    float initPosX;
    float initPosY;
    bool isJumping;
    float moveSpeed;
    float fallSpeed;
    bool isSpawn;
    bool isAlive;
    int live;

private:
    bool playerIsOnPlatform(Entity platform);
    void checkIfIsAlive();

public:
    void checkCollisionWithPlatforms(EntityNode *platforms);
    void checkImpactWithBullets(BulletNode *bullets);
    // Functions
    void initEnemy();
    void moveEnemy();
    void updateInput();
    void update();
};