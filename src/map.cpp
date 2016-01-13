/* 
 * map.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 11 2016
 * Holds all map methods
 */

#include "map.h"

 Map::Map()
{
    // Création de la map
    // On met toutes les valeurs à zéro
    for (unsigned int i = 0; i < 10; ++i)
    {
        for (unsigned int j = 0; j < 10; ++j)
        {
            m_squares[i][j] = 0;
        }
    }
}

Map::~Map()
{

}

void Map::print(bool mine)
{
    std::cout << "   A B C D E F G H I J" << std::endl;
    std::cout << "  /+++++++++++++++++++\\" << std::endl;
    for (unsigned int i = 0; i < 10; ++i)
    {
        std::cout << i << " |";
        for (unsigned int j = 0; j < 10; ++j)
        {
            if(mine)
            {
                switch(m_squares[i][j])
                {
                    case 0:
                        std::cout << " ";
                        break;

                    case 1:
                        std::cout << "x";                        
                        break;

                    case 2:
                        std::cout << "#";
                        break;

                    case 3:
                        std::cout << "O";
                        break;

                    default:
                        std::cout << "%";
                        break;
                }
            }
            else
            {
                switch(m_squares[i][j])
                {
                    case 0:
                    case 2:
                        std::cout << " ";
                        break;

                    case 1:
                        std::cout << "x";                        
                        break;

                    case 3:
                        std::cout << "O";
                        break;

                    default:
                        std::cout << "%";
                        break;
                }
            }
            if(j != 9)
            {
                std::cout << " ";   
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "  \\+++++++++++++++++++/" << std::endl;
}

/*
std::vector<Boat> Map::boats()
{
    return m_boats;
}

std::array<std::array<unsigned int> > Map::squares()
{
    return m_squares;
}

bool Map::checkDefeat()
{
    // regarde si chaque bateau est coulé
    for (auto it = m_boats.begin() ; it != m_boats.end(); ++it)
    {
        if(! *it.sunken())
        {
            return true;
        }
        return false;
    }
}

bool Map::isThereABoatHere(unsigned int x, unsigned int y)
{
    for (auto it = m_boats.begin() ; it != m_boats.end(); ++it)
    {
        if (*it.orientation()) // vertical
        {
            // On fait varier y et on regarde si on a un morceau de bateau
            return true;
        }
        else // horizontal
        {
            return false;
        }
    }
}
*/