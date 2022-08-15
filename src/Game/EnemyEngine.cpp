#include "Game/EnemyEngine.hpp"

// Constructor-Destructor
EnemyEngine::EnemyEngine()
{
    //this->createEnemies();
    this->initVariables();
    this->initAttributes();
}

EnemyEngine::~EnemyEngine() {}

int EnemyEngine::getRandomNumber(int a, int b)
{
    srand(time(NULL));
    int num;
    num = a + rand() % (b + 1 - a);
    return num;
}

// Private functions
void EnemyEngine::initVariables()
{
    fallSpeed = 10.0f;
    moveSpeed = 50.f;
    deltatime = 0.07f;
    gravitySpeed = 0.98f;
    isOnPlatform = false;
}

void EnemyEngine::initAttributes(){
    shape.setPosition(0,100.0f);
    shape.setSize(sf::Vector2f(50.0f,50.0f));
    shape.setFillColor(sf::Color::Magenta);
}

void EnemyEngine::createEnemies(){
    enemies = new EnemyNode();
    EnemyNode *head = enemies;
    head->s = shape;
    head->posx = shape.getPosition().x;
    head->posy = shape.getPosition().y;
    head->next = nullptr;
}

void EnemyEngine::initEnemies(){
    enemies = new EnemyNode();
    EnemyNode *head = enemies;

    while(head){
        head->s = shape;
        head = head->next;
    }
}

void EnemyEngine::renderEnemies(sf::RenderTarget *target){
    EnemyNode *head = enemies;
    while(head){
        target->draw(head->s);
        head = head->next;
    }
}

void EnemyEngine::moveUpdate(){
    EnemyNode *head = enemies;
    sf::Vector2f movement(0.0f, 0.0f);

    if (head->posx < 0 || head->posx + head->s.getGlobalBounds().width > 1280)
    {
        moveSpeed *= -1;
    }

    if (!isOnPlatform)
    {
        fallSpeed = getRandomNumber(5, 10);
        movement.y += fallSpeed * deltatime;
    }

    movement.x += moveSpeed * deltatime;
    head->s.move(movement);
    head->posx = head->s.getPosition().x;
    head->posy = head->s.getPosition().y;
}

void EnemyEngine::update(){
    moveUpdate();
}


// Collision EnemyEngine
void EnemyEngine::checkCollisionWithPlatforms(EntityNode *platforms)
{
    EntityNode *head = platforms;
    while (head)
    {
        if (playerIsOnPlatform(head->value))
        {
            isOnPlatform = true;
            return;
        }
        head = head->next_node;
    }
    isOnPlatform = false;
}

inline bool epsilonEquals(const float x, const float y, const float epsilon = 1E-5f)
{
    return abs(x - y) <= epsilon;
}

bool EnemyEngine::playerIsOnPlatform(Entity platform)
{
    EnemyNode *head = enemies;
    /*
    Si la coordenada Y de player es platform.y - 50
    y la coordenada X de player está entre platform.X y platform.X + platform.width
    entonces player está sobre platform
    */
    int minusLimitOnX = platform.getXCord() - head->s.getGlobalBounds().width;
    int superiorLimitOnX = platform.getXCord() + platform.getWitdh();
    int limitOnY = platform.getYCord() - head->s.getGlobalBounds().height;

    if (head->posx > minusLimitOnX && head->posx < superiorLimitOnX && epsilonEquals(head->posy, limitOnY))
        return true;
    return false;
}

