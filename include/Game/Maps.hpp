#pragma once

#include "Platform.hpp"
#include "GameTextures.hpp"
#include "DataStructures/EntityNode.hpp"

class Maps : public Entity
{
    // Constructor
public:
    Maps();

private:
    // Variables platform
    int baseX;
    int baseY;
    int screenWidth;
    float heightPlatform;
    float widthPlaform;

    // Variables object
    float heightObject;
    float widthObject;

    // Init functions
    void initVariables();
    // Platform functions
    void createPlatforms();
    // Objects
    void createObjects();
    //coins
    void createCoins();
    //teleports
    void createTeleport();
public:
    // Platform attributes & functions
    EntityNode *platforms;
    EntityNode *objects;
    EntityNode* coins;
    EntityNode* teleport;
    GameTextures texture;
    sf::Texture background;
    sf::Sprite sp_background;
    void initBackground();
    void renderBackground(sf::RenderTarget *target);
    void initObjects();
    void renderObjects(sf::RenderTarget *target);
    void initPlatforms();
    void renderPlatforms(sf::RenderTarget *target);
    void initCoins();
    void renderCoins(sf::RenderTarget* target);
    void initTeleport();
    void renderTeleport(sf::RenderTarget* target);
};