#include "Animation.hpp"

Animation::Animation(int rectWidth,int rectHeight, int numSheet)
{
    //Rectangulo visible de Shape
    sf::IntRect area(0,0,rectWidth,rectHeight);
    this->uvRect=area;
    //Cantidad de animaciones en el SpreadSheet
    this->numSheet=numSheet;
    //Frame *animacions[numSheet];

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

void Animation::update(bool isMoving, bool faceRight,sf::Clock clock)
{
    if (clock.getElapsedTime().asSeconds() >=2.0f){
        /*if (isMoving)
        {
            
        }
        else{
            //if (faceRight)
            //{*/
                if (uvRect.left == 100)
                    this->uvRect.left = 0;
                else
                    this->uvRect.left += 50;
            /*}
            else
            {
                
            }*/
       // }
    }
}