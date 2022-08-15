#pragma once
#include "GameTextures.hpp"
#include "Entity.hpp"
#include "Enemy.hpp"
#include "DataStructures/EnemyNode.hpp"

class EnemyEngine
{
public:
    // Constructor-Destructor
    EnemyEngine();
    virtual ~EnemyEngine();

private:
    void initVariables();
    void initObjects();

public:
    //Nodes
    // Objects
    //GameTextures texture;

public:
    //void checkCollisionWithPlatforms(EntityNode *platforms);
    //Nodes
    EnemyNode *enemies;
    sf::RectangleShape shape;
    float fallSpeed;
    float moveSpeed;
    float deltatime;
    bool isOnPlatform;
    float gravitySpeed;
    int getRandomNumber(int a, int b);
    void initAttributes();
    void initEnemies();
    void moveUpdate();
    void update();
    void createEnemies();
    void updateEnemies();
    void renderEnemies(sf::RenderTarget *target);
    void checkCollisionWithPlatforms(EntityNode *platforms);
    bool playerIsOnPlatform(Entity platform);
};