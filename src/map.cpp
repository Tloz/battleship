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

void Map::printDebug()
{
    std::cout << "   A B C D E F G H I J" << std::endl;
    std::cout << "  /+++++++++++++++++++\\" << std::endl;
    for (unsigned int i = 0; i < 10; ++i)
    {
        std::cout << i << " |";
        for (unsigned int j = 0; j < 10; ++j)
        {
            std::cout << m_squares[j][i];
            if(j != 9)
            {
                std::cout << " ";   
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "  \\+++++++++++++++++++/" << std::endl;
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
                switch(m_squares[j][i])
                {
                    case 0:
                        std::cout << " ";
                        break;

                    case 1:
                        std::cout << "x";                        
                        break;

                    case 2:
                        std::cout << "O";
                        break;

                    case 3:
                        std::cout << "#";
                        break;

                    default:
                        std::cout << "%";
                        break;
                }
            }
            else
            {
                switch(m_squares[j][i])
                {
                    case 0:
                    case 2:
                        std::cout << " ";
                        break;

                    case 1:
                        std::cout << "x";                        
                        break;

                    case 3:
                        std::cout << "#";
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

bool Map::check_boat_placement(Boat* b, unsigned int x, unsigned int y, bool dir)
{
    /* on vérifie pour chaque partie du bateau à placer si:
     * - on ne rencontre pas un autre bateau
     * - on reste dans les limites de la carte
     */
    for(unsigned int i = 0; i < b->size(); ++i)
    {
        if( ((x >= 0) && (x <= 9) ) && ((x >= 0) && (x <= 9)) ) // Si x et y sont compris entre 0 et 9
        {
            if( (m_squares[x][y]) == 2 || (m_squares[x][y]) == 3 )
            {
                return false;
            }
            if(dir)
            {
                y++;
            }
            else
            {
                x++;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}

void Map::placeBoat(Boat* b, unsigned int x, unsigned int y, bool dir)
{
    if(check_boat_placement(b, x, y, dir))
    {
        // On modifie les valeurs dans la carte
        for(unsigned int i = 0; i < b->size(); ++i)
        {
            if(b->squares()[i])
            {
                m_squares[x][y] = 3;
            }
            else
            {
                m_squares[x][y] = 2;
            }
            if(dir)
            {
                y++;
            }
            else
            {
                x++;
            }
        }

        // On modifie les valeurs dans le bateau
        b->setCoordinates(x, y);
        b->setOrientation(dir);

        // On ajoute le bateau à la liste des bateaux de la carte
        m_boats.push_back(*b);
    }
    else
    {
        // Raise an exception
        std::cout << "Error placing boat" << std::endl;
    }
}

std::vector<Boat> Map::boats()
{
    return m_boats;
}

std::array<std::array<unsigned int, 10>, 10 > Map::squares()
{
    return m_squares;
}

bool Map::checkDefeat()
{
    // regarde si chaque bateau est coulé
    for (auto it = m_boats.begin() ; it != m_boats.end(); ++it)
    {
        // si le bateau a coulé
        if(!it->sunken())
        {
            return true;
        }
    }
    return false;
}

/*
bool Map::isThereABoatHere(unsigned int x, unsigned int y)
{
    for (auto it = m_boats.begin() ; it != m_boats.end(); ++it)
    {
        if (it->orientation()) // vertical
        {
            // On fait varier y et on regarde si on a un morceau de bateau
            return ;
        }
        else // horizontal
        {
            return ;
        }
    }
}
*/