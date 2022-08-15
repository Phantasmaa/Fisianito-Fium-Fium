#pragma once
#include "Game/Enemy.hpp"

class EnemyNode {
    public:
        //Enemy value;
        sf::RectangleShape s;
        float posx, posy;
        EnemyNode *next = nullptr;
        EnemyNode *prev = nullptr;
    
};