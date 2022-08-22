#include "Game/Bullet.hpp"
#pragma once

class BulletNode
{
public:
    Bullet value;
    BulletNode *next_node = nullptr;
};