#include "Game/Enemy.hpp"

// Constructor-Destructor
Enemy::Enemy()
{
    this->initVariables();
    this->initEnemy();
    this->initObjects();
}

Enemy::~Enemy(){}

// Private functions
void Enemy::initVariables()
{
    // Position
    groundHeight = 100.0f;
    // Speed
    moveSpeed = 50.f;
    fallSpeed = 10.0f;
    gravitySpeed = 0.98f;
}

void Enemy::initEnemy(){
    this->initAttributes(0, groundHeight, 50.f, 50.f);
    this->shape.setFillColor(sf::Color::Blue);
}

void Enemy::moveEnemy(){
    float deltatime = 0.07f;
	sf::Vector2f movement(0.0f,0.0f);

    if(shape.getPosition().x < 0 || shape.getPosition().x + shape.getGlobalBounds().width > 1280){
        moveSpeed *= -1;
    }

    if(!isOnPlatform){
        fallSpeed =getRandomNumber(5,10);
        movement.y += fallSpeed*deltatime;
    }

    if(shape.getPosition().y + shape.getGlobalBounds().height > 670){
        movement.y = 0;
    }

    movement.x += moveSpeed*deltatime;
    shape.move(movement);
    this->updateCords();
}

void Enemy::initObjects()
{
}

void Enemy::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
}

void Enemy::update()
{
    moveEnemy();
    gravity();
}

//Collision Enemy
void Enemy::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;
    while (head)
    {
        if (playerIsOnPlatform(head->value))
        {
            isOnPlatform = true;
            shape.setFillColor(sf::Color::Cyan);
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