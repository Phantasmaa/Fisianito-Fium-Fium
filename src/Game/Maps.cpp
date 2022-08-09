#include "Game/Maps.hpp"
#include <iostream>

Maps::Maps(){

    initVariables();
    createPlatforms();
}

void Maps::initVariables(){
    this->baseX = 0;
    this->baseY = 150;
    this->screenWidth = 1280;
    this->heightPlatform = 30.0f;
    this->velocityX = 100.0f;
}

void Maps::createPlatforms(){
    platforms = new EntityNode();
    EntityNode *head = platforms;

    for(int i = 0; i < 3; i ++){
        int addY = 180*i;
        switch(i){
            case 0: widthPlaform = 580.0f; break;
            case 1: widthPlaform = 280.0f; break;
            case 2: widthPlaform = 500.0f; break;
        }
        for(int j=0; j<2; j++){
            Platform platform;
            int addX = (screenWidth-widthPlaform) * j;
            platform.initAttributes(baseX + addX, baseY + addY, widthPlaform, heightPlatform);
        
            head->value = platform;
            head->next_node = new EntityNode();
            head = head->next_node;
            
            if(i==1 && j==1){
                widthPlaform = 400.0f;
                animate_platform.initAttributes((screenWidth-widthPlaform)/2,baseY+180,widthPlaform,heightPlatform+20.0f);

                head->value = animate_platform;
                head->next_node = new EntityNode();
                head = head->next_node;
            }
        
        }
    }
}

void Maps::initPlatforms(){
    EntityNode *head = platforms;
    while(head){
        head->value.initShape();
        head = head->next_node;
    }
}

void Maps::renderPlatforms(sf::RenderTarget *target){
    EntityNode *head = platforms;
    while(head){
        head->value.renderOnGame(target);
        head = head->next_node;
    }
}