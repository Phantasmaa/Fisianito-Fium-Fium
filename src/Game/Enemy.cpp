#include "Game/Enemy.hpp"
#include <iostream>
// Constructor-Destructor
Enemy::Enemy()
{
    isSpawn = true;
    live = 30;
    isAlive = true;

    // this->initVariables();
    // this->initEnemy();
}

Enemy::~Enemy() {}

// Private functions
void Enemy::initVariables()
{
    // Position
    initPosX = getRandomNumber(0, 1230);
    initPosY = 0 - shape.getGlobalBounds().height;
    // Speed
    moveSpeed = 50.f;
    // Spawn condition
    isSpawn = false;
}

void Enemy::initEnemy()
{
    if (isSpawn)
    {
        initVariables();
        this->initAttributes(initPosX, initPosY, 50.f, 50.f);
    }
}

void Enemy::moveEnemy()
{
    float deltatime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);

    if (shape.getPosition().x < 0 || shape.getPosition().x + shape.getGlobalBounds().width > 1280)
    {
        moveSpeed *= -1;
    }

    // Fall logic
    if (!isOnPlatform)
    {
        fallSpeed = getRandomNumber(5, 10);
        movement.y += fallSpeed * deltatime;
    }

    // Horizontal movement
    movement.x += moveSpeed * deltatime;

    moveEntity(movement.x, movement.y);
}

void Enemy::update()
{
    moveEnemy();
}

void Enemy::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;
    while (head)
    {
        if (playerIsOnPlatform(head->value))
        {
            isOnPlatform = true;
            return;
        }
        head = head->next_node;
    }
    isOnPlatform = false;
}

inline bool epsilonEquals(const float x, const float y, const float epsilon = 1E-5f)
{
    return abs(x - y) <= epsilon;
}

bool Enemy::playerIsOnPlatform(Entity platform)
{
    /*
    Si la coordenada Y de player es platform.y - 50
    y la coordenada X de player está entre platform.X y platform.X + platform.width
    entonces player está sobre platform
    */
    int minusLimitOnX = platform.getXCord() - width;
    int superiorLimitOnX = platform.getXCord() + platform.getWitdh();
    int limitOnY = platform.getYCord() - this->height;

    if (posX > minusLimitOnX && posX < superiorLimitOnX && epsilonEquals(posY, limitOnY))
        return true;
    return false;
}

void Enemy::checkImpactWithBullets(BulletNode *bullets)
{
    BulletNode *head = bullets;
    while (head)
    {
        if (shape.getGlobalBounds().intersects(head->value.getShape().getGlobalBounds()))
        {
            std::cout << "Balaceado por los municipales" << std::endl;
            head->value.hasCollide = true;
            live -= head->value.damage;
            std::cout << "Live of enemy: " << live << std::endl;
            checkIfIsAlive();
        }
        head = head->next_node;
    }
}

void Enemy::checkIfIsAlive()
{
    if (live <= 0)
        isAlive = false;
}