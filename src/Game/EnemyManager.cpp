#include "Game/EnemyManager.hpp"

EnemyManager::EnemyManager(){
    initVariables();    
}

void EnemyManager::initVariables(){
    spawnTimerMax = 10.0f;
    spawnTimer = spawnTimerMax;
    maxEnemies = 20;
}

void EnemyManager::updateManager(){
    if(spawnTimer < spawnTimerMax)
        spawnTimer += 1.0f;
    else{
        if(enemies.size() < maxEnemies){
            enemies.push_back(Enemy());
            spawnTimer = 0.0f;
        }
    }
}

void EnemyManager::initEnemies(){
    for(auto i: enemies){
        i.initShape();
    }
}

void EnemyManager::renderEnemies(sf::RenderTarget *target){
    for(auto i: enemies){
        i.renderOnGame(target);
    }
}