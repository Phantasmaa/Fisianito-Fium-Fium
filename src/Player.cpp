#include "Player.hpp"

// Constructor-Destructor
Player::Player()
{
    this->initVariables();
    this->shape.setOrigin(shape.getSize() / 2.0f);
    this->shape.setTexture(&texture.playerTexture);
    this->initObjects();
}

Player::~Player()
{
}

// Private functions
void Player::initVariables()
{
    // Position
    groundHeight = 600;
    roofHeight = 300;
    // Dimensions
    this->initAttributes(20, groundHeight, 50.f, 50.f);
    // Speed
    moveSpeed = 80.f;
    gravitySpeed = 0.98f;
    // Status
    isJumping = false;
    isOnPlatform = false;
    isMoving=false;
    

}

void Player::initObjects()
{  
    //Animacion general inicio
    this->animation = new Animation(getWitdh(),getHeight(),4,1.5);
    shape.setTextureRect(this->animation->uvRect);
    
    //creando ciclos de animacion
    this->fillFrames(3,getWitdh(),0,iddleL);
    /*this->fillFrames(3,getWitdh(),150,iddleR);
    this->fillFrames(7,getWitdh(),0,runAndJump);
    this->fillFrames(2,getWitdh(),0,hitHurtR);
    this->fillFrames(2,getWitdh(),100,hitHurtL);*/
    

}

// Functions
void Player::fillFrames(int numFrames,int startX, int rectWidth, Frame *frames)
{
    Frame *head=frames;
    //Iteración para hacer una lista segun la longitud de la animacion de cada ciclo
    for (int i=0; i < numFrames; i++)
    {
        Frame *newFrame=NULL;
        newFrame->leftX=i*rectWidth + startX;

        //Insertado al Final
        if(frames==NULL){
            frames=newFrame;
            newFrame->nextFrame=frames;
        }
        while(head->nextFrame !=NULL){
            head=head->nextFrame;
        }
        head->nextFrame=newFrame;
        newFrame->nextFrame=frames;
    }
}


void Player::gravity()
{
    if (getYCord() < groundHeight && !isJumping && !isOnPlatform)
    {
        moveEntity(0.f, gravitySpeed);
    }
    if (getYCord() > roofHeight)
    {
    }
}

void Player::updateInput()
{
    float deltaTime = 0.07f;
    sf::Vector2f movement(0.0f, 0.0f);
    // Keyboard inputs
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        movement.y -= moveSpeed * deltaTime;
        isJumping = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= moveSpeed * deltaTime;
        faceRight=false;
        isMoving=true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += moveSpeed * deltaTime;
        faceRight=true;
        isMoving=true;
    }
    else{
        isMoving=false;
    }
    
    shape.move(movement);
    updateCords();
    
}

void Player::update(float dt)
{
    gravity();
    updateInput();

    //Animacion
    animation->update(animationRow,currentCycle,dt);
    shape.setTextureRect(this->animation->uvRect);
}

void Player:: getAction()
{
    if(isMoving){

        if(faceRight){
            animationRow=runR;
        }
        else animationRow=runL;
        currentCycle=runAndJump;
    }

    else if(isJumping){

        if(faceRight){
            animationRow=jumpR;
        }
        else animationRow=jumpL;

        currentCycle=runAndJump;
    }

    else{
        animationRow=iddleRow;
        if(faceRight){
            currentCycle=iddleR;
        }
        else currentCycle=iddleL;
    }
}
