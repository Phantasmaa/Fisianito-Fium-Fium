#pragma once

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "Collision.hpp"
#include "GameTextures.hpp"

class Player {
    private:
        //Variables
        sf::RectangleShape body;
        //Private functions
        void initVariables();
        void initShape();
        void initObjects();
        
    public:
        //Objects
        GameTextures texture;
        Animation* animation;

        //Gravity Variables
        int groundHeight;
        int roofHeight;
        float gravitySpeed;
        bool isJumping;

        //Animation variables
        unsigned int row;
        float moveSpeed;
        bool faceRight;

        //Constructor-Destructor
        Player();
        virtual ~Player();

        //Functions
        int getY();
        void gravity();
        void updateInput(float deltaTime);
        void update();
        void render(sf::RenderTarget* target);

        //other functions
        sf::Vector2f getPosition(){ return body.getPosition();}
        Collision getCollision(){ return Collision(body);}
};