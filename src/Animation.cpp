#include "Animation.hpp"

Animation::Animation(int rectWidth,int rectHeight, int numSheet,double switchTime)
{
    //Rectangulo visible de Shape
    sf::IntRect area(0,0,rectWidth,rectHeight);
    this->uvRect=area;
    //Cantidad de animaciones en el SpreadSheet
    this->numSheet=numSheet;
    //Frame *animacions[numSheet];
    //time para la animacion
    this->totalTime=0;
    this->switchTime=switchTime;

}

Animation::~Animation() {}

//Frame *initFrames(Animation::Frame &ciclo, int frames,int rectWidth)
//{
    /*TRABAJANDO EN LAS LINEAS
    Animation::Frame headFrames=ciclo;

    for (int i=0; i < frames; i++)
    {
        if (&ciclo==NULL){
            ciclo.&leftX=0;
        }
        else{
            while(headFrames.&nextFrame!=NULL){
                headFrames=*headFrames.nextFrame;
            }
        headFrames.nextFrame=i*rectWidth; 
        }
        
    }
    
    return 
    */
//}

void Animation::update(bool isMoving, bool faceRight,bool isJumping, float deltaTime)
{   
    totalTime += deltaTime;
    if (totalTime>=switchTime){
        totalTime=0;
        if (isMoving)
        {
            if (faceRight){
                this->uvRect.top=50;
                if (uvRect.left == 300)
                    this->uvRect.left = 0;
                else
                    this->uvRect.left += 50;
            }
            else //faceLeft
            {
                this->uvRect.top=100;
                if (uvRect.left == 300)
                    this->uvRect.left = 150;
                else
                    this->uvRect.left += 50;
            }
        }
        else if (isJumping)
        {
            if (faceRight){
                this->uvRect.top=150;
                if (uvRect.left == 300)
                    this->uvRect.left = 0;
                else
                    this->uvRect.left += 50;
            }
            else //faceLeft
            {
                this->uvRect.top=200;
                if (uvRect.left == 300)
                    this->uvRect.left = 150;
                else
                    this->uvRect.left += 50;
            }
        }
        else{
            this->uvRect.top=0;
        
            if (faceRight){
            
                if (uvRect.left == 100)
                    this->uvRect.left = 0;
                else
                    this->uvRect.left += 50;
            }
            else //faseLeft
            {
                if (uvRect.left == 250)
                    this->uvRect.left = 150;
                else
                    this->uvRect.left += 50;
            }
       }
    }
}