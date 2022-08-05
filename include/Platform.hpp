#pragma once

#include <SFML/Graphics.hpp>
#include "Collision.hpp"

class Platform {
    private:
        sf::RectangleShape shape;
        void initShape();
        void initVariables();
    public:
        //Variables
        sf::Texture texture;
        sf::Vector2f size;
        sf::Vector2f position;
        //Constructor-Destructor
        Platform(float posX, float posY);
        virtual ~Platform();

        //Functions
        void update();
        void render(sf::RenderTarget* target);

        //Collision functions
        Collision getCollision(){return Collision(shape);}


};