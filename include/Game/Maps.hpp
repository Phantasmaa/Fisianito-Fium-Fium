#pragma once

#include "Platform.hpp"
#include "DataStructures/EntityNode.hpp"

class Maps : public Entity{
    //Constructor
    public:
        Maps();
    
    private:
        //Variables platform
        int baseX;
        int baseY;
        int screenWidth;
        float heightPlatform;
        float widthPlaform;

        //Movement variables
        float velocityX;

        //Init functions
        void initVariables();
        //Platform functions
        void createPlatforms();

    public:
        //Platform attributes & functions
        EntityNode *platforms;
        Entity animate_platform;
        void initPlatforms();
        void renderPlatforms(sf::RenderTarget *target);
};