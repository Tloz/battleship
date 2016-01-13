/* 
 * player.cpp
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 11 2016
 * Holds all player data
 */

#include "player.h"

Player::Player(std::string name) : m_name(name)
{
    m_map = Map();
    m_score = 0;
    m_missiles = 0;
    m_sonar = 0;
}

Player::~Player()
{

}

std::array<std::array<unsigned int, 10>, 10> Player::map()
{
    return m_map.squares();
}


bool Player::shoot(unsigned int x, unsigned int y, Player* target)
{
    std::array<std::array<unsigned int, 10>, 10> map = target->map();
    printf("Debug: Shooting on (%i, %i)\n", x, y);
    if((map[y][x] == 0) || (map[y][x] == 1)) // Si on tire sur un espace vide
    {
        std::cout << "Nothing on (" << (char) ('A' + x) << ", " << y << ")" << std::endl;
        map[y][x] = 1;
        return false;
    }
    else if((map[y][x] == 2) || (map[y][x] == 3)) // Si on tire sur un espace rempli
    {
        std::cout << "Hit something on (" << (char) ('A' + x) << ", " << y << ")" << std::endl;
        map[y][x] = 3;
        return true;
    }
    else // erreur
    {
        printf("/!\\ Wut? Never supposed to get to point 1... Problem with the data in the map /!\\\n");
        return false;
    }
}

bool Player::shoot_missile(unsigned int x, unsigned int y, Player* target)
{
    bool res = false;
    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if(shoot(x + i, y + j, target))
            {
                res = true;
            }
        }
    }
    return res;
}

int Player::sonar(unsigned int x, unsigned int y, Player* target)
{
    std::array<std::array<unsigned int, 10>, 10> map = target->map();
    int count = 0;

    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if((map[x + i][y + j] == 1) || (map[x + i][y + j] == 3))
                ++count;
        }
    }
    return count;
}

void Player::setMap(Map m)
{
    m_map = m;
}