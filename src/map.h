/* 
 * map.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 11 2016
 * Holds all map data
 */

#include "boat.h"
#include <vector>
#include <array>
#include <iostream>

class Map
{
private:
    std::vector<Boat> m_boats;
    std::array<std::array<unsigned int, 10>, 10> m_squares;
    /*********************************************************\
    | *  Valeurs possibles sur les cases:                     |
    |   * - 0: la case est vide                               |
    |   * - 1: la case est vide et attaquée                   |
    |   * - 2: la case est remplie                            |
    |   * - 3: la case est remplie et attaquée                |
    \*********************************************************/

public:
    Map();
    ~Map();

    void print(bool mine);

    bool isThereABoatHere(unsigned int x, unsigned int y);
    std::vector<Boat> boats();
    std::array<std::array<unsigned int, 10>, 10> squares();
    bool checkDefeat();
};