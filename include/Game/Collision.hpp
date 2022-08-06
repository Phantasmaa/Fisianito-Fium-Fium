#pragma once

#include <SFML/Graphics.hpp>
//#include <iostream>

class Collision {
    private: 
        sf::RectangleShape& body;
    public:
        //Variables

        //Constructor-Destructor
        Collision(sf::RectangleShape& body);
        virtual ~Collision();

        //Functions
        bool checkCollision(Collision& other, float push);
        sf::Vector2f getPosition(){ return body.getPosition();}
        sf::Vector2f getHalfSize(){ return body.getSize()/2.0f;}
        void move(float dx, float dy){ body.move(dx,dy);}

};