#include "GameManager.h"


void GameManager::Dropping()
{
    ob1.drop_obstacle();

}


void GameManager::Draw()
{
    this->g1.draw_grid();
    this->ob1.draw_obstacle(ORANGE);
    this->ob1.movement();

}

bool GameManager::approve()
{
    return this->ob1.get_placementState();
}

void GameManager::check_placement()
{
    
}