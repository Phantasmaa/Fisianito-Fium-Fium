#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include <vector>

class EnemyManager
{
    private:
        /* data */
    public:
        EnemyManager();
    private:
        std::vector<Enemy> enemies;
        float spawnTimerMax;
        float spawnTimer;
        float maxEnemies;
    private:
        void initVariables();
    public:
        void initEnemies();
        void updateManager();
        void renderEnemies(sf::RenderTarget *target);
};
