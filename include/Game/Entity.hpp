#include <SFML/Graphics.hpp>
#pragma once
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
    // Metodos
public:
    // Init attributes & shapes
    void initAttributes(int posX = 0, int posY = 0, float width = 0.0, float height = 0.0);
    void initShape();
    //Movement
    void moveEntity(float x_movement, float y_movement);
    // Devolver datos
    int getYCord();
    int getXCord();
    float getWitdh();
    float getHeight();
    sf::RectangleShape getShape(){ return this->shape;}

protected:
    void updateCords();

public:
    //Render
    void renderOnGame(sf::RenderTarget *target);
    void logEntity();
};