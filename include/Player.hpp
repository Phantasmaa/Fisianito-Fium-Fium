#pragma once

#include <SFML/Graphics.hpp>

class Player {
    private:
        //Variables
        sf::RectangleShape shape;
        float moveSpeed;
        //Private functions
        void initVariables();
        void initShape();
        
    public:
        //Gravity Variables
        int groundHeight;
        int roofHeight;
        float gravitySpeed;
        bool isJumping;

        //Constructor-Destructor
        Player();
        virtual ~Player();

        //Functions
        int getY();
        void gravity();
        void updateInput();
        void update(sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
};