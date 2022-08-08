#include "Animation.hpp"

Animation::Animation(int rectWidth,int rectHeight, int numSheet)
{
    //Rectangulo visible de Shape
    sf::IntRect area(0,0,rectWidth,rectHeight);
    this->uvRect=area;
    //Cantidad de animaciones en el SpreadSheet
    this->numSheet=numSheet;
    Frame *animacions[numSheet];

}

Animation::~Animation() {}

Animation::Frame *initFrames(Animation::Frame &ciclo, int frames,int rectWidth)
{
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
}

void Animation::update(float deltaTime, bool isMoving, bool faceRight)
{
    
    if (isMoving)
    {
    
    }
    else{
        if (faceRight)
        {
        
        }
        else
        {
            
        }
    }
}