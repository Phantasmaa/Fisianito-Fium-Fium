#include "Game/Bullet.hpp"

Bullet::Bullet(float initialX, float initialY, Directions direction)
{
    this->initAttributes(initialX, initialY, 50.0f, 50.0f);
    this->shape.setPosition(sf::Vector2f(initialX, initialY));
    this->initShape();
    hasCollide = false;
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