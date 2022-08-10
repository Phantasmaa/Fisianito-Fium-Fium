#include "Enemy.hpp"


// Constructor-Destructor
Enemy::Enemy()
{
    this->initVariables();
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setFillColor(sf::Color::Red);
    this->initObjects();
}

Enemy::~Enemy()
{
}

// Private functions
void Enemy::initVariables()
{
    // Position
    groundHeight = 600;
    roofHeight = 600;
    // Dimensions
    this->initAttributes(400, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 0.98f;
    // Status
    isOnPlatform = false;
}

void Enemy::initObjects()
{
    this->animation = new Animation(&texture.playerTexture, sf::Vector2u(2, 5), 1.0f);
}

// Functions


void Enemy::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
    if (getYCord() > roofHeight)
    {
    }
}


void Enemy::update()
{
	float deltatime = 0.07f;
	sf::Vector2f movement(0.0f,0.0f);

	movement.x -= moveSpeed*deltatime;

    /*if(this->posX = -300){
        movement.x *=-1;
    }
    */
    if(this->getPosition().x <= -300 ){
        movement.x *= -1;
    }
    /*else if(this->getPosition().x >=300 ){
        movement.x *=1;
    }*/



    animation->update(row, deltatime, faceRight);
    shape.setTextureRect(this->animation->uvRect);
    shape.move(movement);
    updateCords();
    gravity();
}
