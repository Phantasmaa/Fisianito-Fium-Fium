#include "Game/Entity.hpp"
#pragma once

class EntityNode
{
public:
    Entity value;
    EntityNode *next_node = nullptr;
};