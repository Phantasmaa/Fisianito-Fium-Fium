#include "Game/GameTextures.hpp"

GameTextures::GameTextures()
{
    // ASSETS DEBEN ESTAR EN MISMA CARPETA QUE EJECUTABLE
    playerTexture.loadFromFile("assets/img/spritePlayer1.png");
    trampTexture.loadFromFile("assets/img/tramp.png");
    bulletTexture.loadFromFile("assets/img/bullet.png");
    ghostTexture.loadFromFile("assets/img/ghost.png");
    bgTexture.loadFromFile("assets/img/bgTexture.png");
    //Platforms
    platformTexture.loadFromFile("assets/img/plataformTexture.png");
    platformTexture.setRepeated(true);
}
