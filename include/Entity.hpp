#include <SFML/Graphics.hpp>
#pragma once
class Entity{
    // Constructores
    public:
        Entity(){};
    protected:
    // Atributos
        int posX;
        int posY;
        float width;
        float height;
        sf::RectangleShape shape;
    // Metodos
    public:
    // Inicializar variables
        void initAttributes(int posX, int posY, float width, float height);
        void initShape();
    // Devolver datos
        int getYCord();
        int getXCord();
        float getWitdh();
        float getHeight();
    protected:
        void updateCords();
    // Metodos de movimiento
        void moveEntity(float x_movement, float y_movement);
    // Render
    public:
        void renderOnGame(sf::RenderTarget* target);

};