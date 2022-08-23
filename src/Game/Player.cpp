
#include "Game/Player.hpp"
#include <iostream>
#include <math.h>

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    this->initPlayer();
    this->initObjects();
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 620;
    roofHeight = 300;
    // Dimensions
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 90.f;
    gravitySpeed = 1.0f;
    jumpSpeed = 20.0f;
    accelerationY = 0.0f;
    live = 100;
    isAlive = true;
    jumpStatus = Neutral;
    isCollideWithEnemy = false;
    // Status
    isJumping = false;
    isOnPlatform = false;
    // Bullets
    faceDirection = Directions::Static;
}

void Player::initPlayer()
{
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    this->shape.setOrigin(shape.getSize() / 2.0f);
    // this->shape.setFillColor(sf::Color::Green);
    // this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setTexture(&texture.playerTexture);
}

void Player::initObjects()
{
    // Animacion general inicio
    this->animation = new Animation(getWitdh(), getHeight(), 4, 3);
    shape.setTextureRect(this->animation->uvRect);

    // creando ciclos de animacion
    this->createAnimationCycle();
}

// Functions

void Player::gravity()
{

    if (isOnFloor() || isOnPlatform && !isJumping)
    {
        accelerationY = 0.0;
        movementDirection = Directions::Static;
    }
    else
    {
        if (accelerationY + posY < groundHeight)
            accelerationY += gravitySpeed;
        else
            accelerationY = 0.0;
    }
}

void Player::updateInput()
{
    float deltaTime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);
    float velocityY = 0.0f;

    // Keyboard inputs
    handleKeyPressed(velocityY, movement, deltaTime);
    velocityY = fabs(velocityY);

    if (movementDirection == Directions::Up)
        velocityY *= -1.0f;

    velocityY += accelerationY;
    movement.y = velocityY;

    getAction();
    shape.move(movement);
    updateCords();
}

void Player::handleKeyPressed(float &velocityY, sf::Vector2f &movement, float deltaTime)
{
    bool playerMoved = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && movementDirection != Directions::Down)
    {
        // salta carajito
        velocityY -= jumpSpeed;
        movementDirection = Directions::Up;
        isJumping = true;
        playerMoved = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        faceDirection = Directions::Left;
        movement.x -= moveSpeed * deltaTime;
        faceRight = false;
        playerMoved = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        faceDirection = Directions::Right;
        movement.x += moveSpeed * deltaTime;
        playerMoved = true;
        faceRight = true;
    }
    if (!playerMoved)
        faceDirection = Directions::Static;
}

void Player::update(EntityNode *platforms, float dt)
{
    updateInput();
    checkCollisionWithPlatforms(platforms);
    gravity();
    windowsCollision();
    std::cout << "Vida del carajito: " << live << std::endl;
    checkIfCarajitoVive();
    // Animacion
    // std::cout<<"\nEje X:"<<this->animation->uvRect.width;
    animation->update(animationRow, frameCycles[currentCycle], dt);
    shape.setTextureRect(this->animation->uvRect);
}

// Collision Player
void Player::windowsCollision()
{
    // Left collision
    if (shape.getPosition().x < 0.0f)
        shape.setPosition(0.0f, shape.getPosition().y);
    // Top collision
    if (shape.getPosition().y < 0.0f)
        shape.setPosition(shape.getPosition().x, 0.0f);
    // RIght collision
    if (shape.getPosition().x + shape.getGlobalBounds().width > 1280.0f)
        shape.setPosition(1280.0f - shape.getGlobalBounds().width, shape.getPosition().y);
}

void Player::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;

    while (head->next_node)
    {

        Entity platform = head->value;
        switch (this->checkCollision(platform))
        {
        case CollisionDirection::Top:
        {
            isOnPlatform = true;
            isJumping = false;
            movementDirection = Directions::Static;
            return;
        }
        /* code */
        case CollisionDirection::Bottom:
        {

            accelerationY *= 1.0f;
            isJumping = false;
            movementDirection = Directions::Down;
            return;
        }
        case CollisionDirection::Null:
            isOnPlatform = false;
            break;
        default:
            break;
        }

        head = head->next_node;
    }
}



void Player::checkCollisionWithObjects(EntityNode *objects)
{
    EntityNode *head = objects;
    while (head)
    {
        if (shape.getGlobalBounds().intersects(head->value.getShape().getGlobalBounds()))
        {
            shape.setFillColor(sf::Color::Red);
            //std::cout << "muere" << std::endl;
            live -= 1;
            return;
        }
        // shape.setFillColor(sf::Color::Green);
        shape.setFillColor(sf::Color::White);
        head = head->next_node;
    }
}

void Player::changeColorWhenCollideWithEnemy(){
    if(isCollideWithEnemy){
        shape.setFillColor(sf::Color::Red);
    }
}

bool Player::isOnFloor()
{
    return getYCord() == groundHeight;
}

Directions Player::getFaceDirection()
{
    return faceDirection;
}

// INCERTAR EN LISTA CIRCULARES
void Player::createAnimationCycle()
{
    int numFrames = 0;
    int startX;

    for (int frameCount = 0; frameCount < 5; frameCount++)
    {

        if (frameCount != 2)
        {
            numFrames = 3;
        }
        else
            numFrames = 7;

        if (frameCount == 1 || frameCount == 4)
            startX = 150;
        else
            startX = 0;

        // Crea la lista circular a utilizar
        // Primer frame
        frameCycles[frameCount] = new Frame();
        frameCycles[frameCount]->leftX = startX;
        frameCycles[frameCount]->nextFrame = frameCycles[frameCount];

        // Copias para recorrer... por donde recorres? ლ(ಠ_ಠ ლ)
        Frame *head = frameCycles[frameCount]; // Cabeza del ciclo

        // Llenando los frames segun numFrames
        for (int j = 1; j < numFrames; j++)
        {

            Frame *temp = new Frame();
            temp->leftX = j * 50 + startX; // se coloca el valor

            temp->nextFrame = frameCycles[frameCount]; // iguala al siguiente de la lista
            head->nextFrame = temp;
            head = head->nextFrame;
            // frameCycles[frameCount]=temp;                       //se incerta el nuevo en la cabecera
        }
    }
}

void Player::getAction()
{
    if (faceDirection != Directions::Static)
    {

        if (faceRight)
        {
            animationRow = runR;
        }
        else
            animationRow = runL;
        currentCycle = runJump;
    }

    else if (isJumping)
    {

        if (faceRight)
        {
            animationRow = jumpR;
        }
        else
            animationRow = jumpL;

        currentCycle = runJump;
    }

    else
    {
        if (faceRight)
        {
            currentCycle = iddleR;
        }
        else
            currentCycle = iddleL;

        animationRow = iddleRow;
    }
}

bool Player::isFacingRight()
{
    return faceRight;
}

void Player::checkIfCarajitoVive()
{
    if (live <= 0)
        isAlive = false;
}
void Player::checkCollisionWithHeart(EntityNode* heart,Score* points)
{
    EntityNode* head = heart;
    while (head)
    {
        if (shape.getGlobalBounds().intersects(head->value.getShape().getGlobalBounds()))
        {
            head->value.moveHeart();
            if(live>75) live=100;
            else live+=25;
            return;
        }
        head = head->next_node;
    }
}
