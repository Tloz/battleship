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

Map Player::map()
{
    return m_map;
}


bool Player::shoot(unsigned int x, unsigned int y, Player* target)
{
    Map map = target->map();
    std::array<std::array<unsigned int, 10>, 10> squares = map.squares();
    std::cout << "Debug: Shooting on ("<< (char) ('A' + x) << ", " << y << ")" << std::endl;
    map.hit(x, y);

    if((squares[x][y] == 0) || (squares[x][y] == 1)) // Si on tire sur un espace vide
    {
        std::cout << "Nothing on (" << (char) ('A' + x) << ", " << y << ")" << std::endl;
        return false;
    }
    else if((squares[x][y] == 2) || (squares[x][y] == 3)) // Si on tire sur un espace rempli
    {
        std::cout << "Hit something on (" << (char) ('A' + x) << ", " << y << ")" << std::endl;
        // Pour les squares, on ajoute 1, pour le bateau, on passe à true
        if(map.getBoatHere(x, y) != NULL)
        {

        }
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
    Map map = target->map();
    std::array<std::array<unsigned int, 10>, 10> squares = map.squares();
    int count = 0;

    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if((squares[x + i][y + j] == 1) || (squares[x + i][y + j] == 3))
                ++count;
        }
    }
    return count;
}

void Player::setMap(Map m)
{
    m_map = m;
}