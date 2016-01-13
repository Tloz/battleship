/* 
 * boat.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 11 2016
 * Holds all boats data
 */

#include <vector>
#include <string>
#include <iostream>

class Boat
{
private:
    /* First square coordinates */
       unsigned int m_baseX;
       unsigned int m_baseY;
    /****************************/

    unsigned int m_size; // self-explanatory, from 1 to 5
    bool m_orientation; // true if vertical, false otherwise
    bool m_sunken; // true if destroyed
    std::vector<bool> m_squares; // each part is true if touched

public:
    Boat(unsigned int size);
    ~Boat();

    void setOrientation(bool dir);
    void repair(unsigned int where);
    void destroy(unsigned int where);
    void sunk();
    void setCoordinates(unsigned int x, unsigned int y);
    void print();

    unsigned int size();
    unsigned int x();
    unsigned int y();
    bool orientation();
    bool sunken();
    std::vector<bool> squares();   
};