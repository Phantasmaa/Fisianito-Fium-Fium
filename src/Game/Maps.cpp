#include "Game/Maps.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Maps::Maps()
{

    initVariables();
    createPlatforms();
    createObjects();
}

void Maps::initVariables()
{
    this->baseX = 0;
    this->baseY = 150;
    this->screenWidth = 1280;
    this->heightPlatform = 30.0f;
    this->heightObject = 20.0f;
}

// Create & Render Platforms
void Maps::createPlatforms()
{
    platforms = new EntityNode();
    EntityNode *head = platforms;

    for (int i = 0; i < 4; i++)
    {
        int addY = 180 * i;
        switch (i)
        {
        case 0:
            widthPlaform = 580.0f;
            break;
        case 1:
            widthPlaform = 280.0f;
            break;
        case 2:
            widthPlaform = 500.0f;
            break;
        case 3:
            widthPlaform = 1280.0f;
            break;
        }
        for (int j = 0; j < 2; j++)
        {
            Platform platform;
            int addX = (screenWidth - widthPlaform) * j;
            platform.initAttributes(baseX + addX, baseY + addY, widthPlaform, heightPlatform);

            head->value = platform;
            head->next_node = new EntityNode();
            head = head->next_node;

            if (i == 1 && j == 1)
            {
                Platform centerPlatform;
                widthPlaform = 400.0f;
                centerPlatform.initAttributes((screenWidth - widthPlaform) / 2, baseY + 180, widthPlaform, heightPlatform + 20.0f);

                head->value = centerPlatform;
                head->next_node = new EntityNode();
                head = head->next_node;
            }
        }
    }
}

void Maps::initPlatforms()
{
    EntityNode *head = platforms;
    while (head)
    {
        head->value.initShape();
        head = head->next_node;
    }
}

void Maps::renderPlatforms(sf::RenderTarget *target)
{
    EntityNode *head = platforms;
    while (head)
    {
        head->value.renderOnGame(target);
        head = head->next_node;
    }
}

// Create & Render Objects
void Maps::createObjects()
{
    objects = new EntityNode();
    EntityNode *head = objects;
    baseX = 300.0f;
    baseY -= heightObject;

    for (int i = 0; i < 2; i++)
    {
        int addY = 360 * i;
        switch (i)
        {
        case 0:
            widthObject = 80.0f;
            break;
        case 1:
            widthObject = 60.0f;
            break;
        }
        for (int j = 0; j < 2; j++)
        {
            Entity object;
            int addX = 600 * j;
            object.initAttributes(baseX + addX, baseY + addY, widthObject, heightObject);

            head->value = object;
            head->next_node = new EntityNode();
            head = head->next_node;
        }
    }
}

void Maps::initObjects()
{
    EntityNode *head = objects;
    while (head)
    {
        head->value.initShape();
        head = head->next_node;
    }
}

void Maps::renderObjects(sf::RenderTarget *target)
{
    EntityNode *head = objects;
    while (head)
    {
        head->value.renderOnGame(target);
        head = head->next_node;
    }
}