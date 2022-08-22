#include "Game/Bullet.hpp"

Bullet::Bullet()
{
    damage = 10;
    hasCollide = false;
}

void Bullet::setBulletDirection(Directions direction)
{
    switch (direction)
    {
    case Directions::Left:
    {
        directionX = -5.0f;
        break;
    }
    case Directions::Right:
    {
        directionX = 5.0f;

        break;
    }

    default:
        break;
    }
    directionY = 0.0f;
}
void Bullet::checkCollisionWithBorders()
{ // Left collision
    if (shape.getPosition().x < 0.0f || shape.getPosition().y < 0.0f || shape.getPosition().x + shape.getGlobalBounds().width > 1280.0f)
        hasCollide = true;
}

void Bullet::updateBullet()
{
    checkCollisionWithBorders();
    if (!hasCollide)
    {
        shape.move(directionX, directionY);
    }
}

void Bullet::initBullet()
{
    this->shape.setFillColor(sf::Color::Yellow);
}
