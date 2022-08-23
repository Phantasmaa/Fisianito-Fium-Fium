#pragma once
#include <SFML/Graphics.hpp>
#include "Game/GameTextures.hpp"
enum CollisionDirection
{
    Top,
    Bottom,
    Null
};
enum Directions
{
    Up,
    Down,
    Left,
    Right,
    Static
};
class Entity
{
    // Constructores
public:
    Entity(){};

protected:
    // Atributos
    float posX;
    float posY;
    float width;
    float height;
    sf::RectangleShape shape;

public:
    Directions movementDirection;
    // Platform
    bool isOnPlatform;

    // Metodos
public:
    // Inicializar variables
    void initAttributes(int posX = 0, int posY = 0, float width = 0.0, float height = 0.0);
    void initShape();
    void initTexture(sf::Texture &texture);
    // Devolver datos
    float getYCord();
    float getXCord();
    float getWitdh();
    float getHeight();

protected:
    void updateCords();
    // Metodos de movimiento
    void moveEntity(float x_movement, float y_movement);
    CollisionDirection checkCollision(Entity entity);

    // Render
public:
    void renderOnGame(sf::RenderTarget *target);
    int getRandomNumber(int a, int b);
    sf::RectangleShape getShape();
    const sf::FloatRect getBounds() const;
    void logEntity();
    //monedaa
    void moveHeart();
};