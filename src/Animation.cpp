#include "Animation.hpp"

Animation::Animation(int rectWidth,int rectHeight, int numSheet,float switchTime)
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


void Animation::update(int animationRow, Frame *&frameCycle, float deltaTime)
{   
    totalTime += deltaTime;
    if (totalTime>=switchTime){
        totalTime-=switchTime;
        this->uvRect.top=animationRow*50;
        frameCycle=frameCycle->nextFrame;
        this->uvRect.left=frameCycle->leftX;
    }
}