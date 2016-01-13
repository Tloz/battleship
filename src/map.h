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
    | * - 0: aucune interraction avec la case                 |
    | * - 1: on a attaqué la case                             |
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