#pragma once
#include "Game/Bullet.hpp"
#include "Game/Player.hpp"
#include "Game/GameTextures.hpp"
#include "DataStructures/BulletNode.hpp"
class Bullets
{
public:
    BulletNode *bulletsList = nullptr;
    GameTextures texture;
    // Bullet
    void renderBullets(sf::RenderTarget *target);
    void shotBullet(Player player);
    void updateBullets();
    void deleteBulletsFromList();
};
