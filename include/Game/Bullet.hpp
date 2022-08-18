#include "Entity.hpp"

class Bullet : public Entity
{
    int damage;
    bool hasCollide;
    float directionX;
    float directionY;

    void checkCollisionWithBorders();

public:
    void updateBullet();

    Bullet(float initialX, float initialY, Directions direction);
};