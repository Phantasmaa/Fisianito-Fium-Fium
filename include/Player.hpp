#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Player : public Entity {

    // Constructor - Destructor
    public:
        Player();
        virtual ~Player();
    // Atributos
    private:
        float moveSpeed;
    public:
        //Gravity Variables
        int groundHeight;
        int roofHeight;
        float gravitySpeed;
        bool isJumping;
        bool isOnPlatform;

    // Metodos
    private:
        void initVariables();
    public:
        void gravity();
        void updateInput();
        void update(Entity platform);
        void checkIfIsOnPlatform(Entity platform);
};