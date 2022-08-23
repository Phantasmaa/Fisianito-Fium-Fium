#include "Game/EnemyManager.hpp"
#include <iostream>
EnemyManager::EnemyManager()
{ 
    initVariables();
}

void EnemyManager::initVariables()
{
    spawnTimerMax = 500.0f;
    spawnTimer = spawnTimerMax;
    maxEnemies = 10;
}

void EnemyManager::updateManager(BulletNode *bullets)
{

    if (spawnTimer < spawnTimerMax)
        spawnTimer += 1.0f;
    else
    {
        if (enemies.size() < maxEnemies)
        {
            enemies.push_back(Enemy());
            spawnTimer = 0.0f;
        }
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].update();
        enemies[i].checkCollisionWithPlatforms(map.platforms);
        enemies[i].checkImpactWithBullets(bullets);
    }
}

void EnemyManager::initEnemies()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].initEnemy();
        enemies[i].initShape();
        enemies[i].initTexture(texture.ghostTexture);
    }
}

void EnemyManager::renderEnemies(sf::RenderTarget *target)
{
    for (auto i : enemies)
    {
        i.renderOnGame(target);
    }
}

void EnemyManager::removeDeadEnemies(Score *points)
{
    std::vector<int> indexToRemove;
    for (int i = 0; i < enemies.size(); i++)
    {
        if (!enemies[i].isAlive)
        {
            std::cout << "balaceao" << std::endl;
            indexToRemove.push_back(i);
        }
    }
    for (int index : indexToRemove)
    {
        std::cout << "Borrando enemigo" << std::endl;
        enemies.erase(enemies.begin() + index);
        points->enemyScore();
    }
}

void EnemyManager::checkCollisionWithPlayer(Player &player){
    for(int i=0; i<enemies.size(); i++){
        if(player.getBounds().intersects(enemies[i].getBounds())){
            //player.getShape().setFillColor(sf::Color::Red);
            std::cout<<"me tan balaceando"<<std::endl;
            player.live -=1;
            player.isCollideWithEnemy = true;
            return;
        }
        player.isCollideWithEnemy = false;
    }
}
