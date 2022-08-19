#include "Player.hpp"
#include <iostream>

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
    this->createAnimationCycle();


}

// Functions

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
        isJumping =false;
    }
    getAction();
    shape.move(movement);
    updateCords();
    
}

void Player:: getAction()
{
    if(isMoving){

        if(faceRight){
            animationRow=runR;
        }
        else animationRow=runL;
        currentCycle=runJump;
    }

    else if(isJumping){

        if(faceRight){
            animationRow=jumpR;
        }
        else animationRow=jumpL;

        currentCycle=runJump;
    }

    else{
        if(faceRight){
            currentCycle=iddleR;
        }
        else currentCycle=iddleL;

        animationRow=iddleRow;
    }
}

void Player::update(float dt)
{
    gravity();
    updateInput();
    
    //Animacion
    //std::cout<<"\nEje X:"<<this->animation->uvRect.width;
    animation->update(animationRow,frameCycles[currentCycle],dt);
    shape.setTextureRect(this->animation->uvRect);
}


//INCERTAR EN LISTA CIRCULARES
void Player::createAnimationCycle()
{
    int numFrames;
    int startX;

    for(int frameCount=0; frameCount<5;frameCount++){

        if(frameCount!=2){
            numFrames=3;
        }
        else numFrames=7;

        if(frameCount==1 || frameCount==4)startX=150;
        else startX=0;

        // Crea la lista circular a utilizar
        // Primer frame
        frameCycles[frameCount] = new Frame();
        frameCycles[frameCount]->leftX = startX;
        frameCycles[frameCount]->nextFrame=frameCycles[frameCount];

        // Copias para recorrer... por donde recorres? ლ(ಠ_ಠ ლ)
        Frame *head=frameCycles[frameCount]; // Cabeza del ciclo
        
        // Llenando los frames segun numFrames
        for (int j = 1; j < numFrames; j++)
        {
            head = frameCycles[frameCount];
            head = head->nextFrame;
            Frame *temp = new Frame();
            temp->leftX = j*50 + startX;        // se coloca el valor
            temp->nextFrame=head->nextFrame;    //iguala al siguiente de la lista
            head->nextFrame=temp;               //se incerta el nuevo en la cabecera

            frameCycles[frameCount]=head;
            
        
        }

    }
}

/*void Player::createAnimationCycle(){
    int numFrames;
    int startX;
    for(int i=0; i<5;i++){

        if(i!=2){
            numFrames=3;
        }
        else numFrames=7;

        if(i==1 || i==4) startX=150;
        else startX=0;

        //Crea la lista circular a utilizar
        frameCycles[i]=NULL;
        Frame *head=new Frame();
        //head->nextFrame=head;

        for(int j=0;j<numFrames;j++){
            head->leftX=j*50 +startX;//se designa las coordenadas
            frameCycles[i]=head;
            
            frameCycles[i]=frameCycles[i]->nextFrame;
            
            if(head->nextFrame!=NULL)
            {
                head->nextFrame=head;
                head=head->nextFrame;
            }
        }
        head->nextFrame=frameCycles[i];
        frameCycles[i]->nextFrame=head;
        //VERIFICANDO
        std::cout<<"\nCiclo"<<i<<": "<<frameCycles[i]->leftX;
        std::cout<<"\nCiclo"<<i<<": "<<frameCycles[i]->nextFrame->leftX;
        std::cout<<"\nCiclo"<<i<<": "<<frameCycles[i]->nextFrame->nextFrame->leftX;
        std::cout<<"\nCiclo"<<i<<": "<<frameCycles[i]->nextFrame->nextFrame->nextFrame->leftX;
    }
}*/
