#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "GameTextures.hpp"
#include "Maps.hpp"
#include <vector>
#include "Player.hpp"
#include "Score.hpp"

class EnemyManager
{
private:
    /* data */
public:
    EnemyManager();

private:
    std::vector<Enemy> enemies;
    Maps map;
    //Player player;
    float spawnTimerMax;
    float spawnTimer;
    float maxEnemies;

private:
    void initVariables();

public:
    GameTextures texture;
    void checkCollisionWithPlayer(Player &player);
    void initEnemies();
    void updateManager(BulletNode *bullets);
    void removeDeadEnemies(Score *points);
    void renderEnemies(sf::RenderTarget *target);
};