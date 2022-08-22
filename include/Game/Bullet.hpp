#pragma once
#include "Entity.hpp"
class Bullet : public Entity
{
    float directionX;
    float directionY;
    void checkCollisionWithBorders();

public:
    int damage;
    bool hasCollide;
    void setBulletDirection(Directions direction);
    void updateBullet();
    void initBullet();
    Bullet();
};