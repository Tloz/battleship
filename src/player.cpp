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

std::array<std::array<unsigned int, 10>, 10> Player::map()
{
    return m_map.squares();
}


bool Player::shoot(unsigned int x, unsigned int y, Player* target)
{
    std::array<std::array<unsigned int, 10>, 10> map = target->map();
    printf("Debug: Shooting on (%i, %i)\n", x, y);
    if((map[x][y] == 0) || (map[x][y] == 1)) // Si on tire sur un espace vide
    {
        map[x][y] = 1;
        return false;
    }
    else if((map[x][y] == 2) || (map[x][y] == 3)) // Si on tire sur un espace rempli
    {
        map[x][y] = 3;
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
    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            shoot(x + i, y + j, target);
        }
    }
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