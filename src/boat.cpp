/* 
 * boat.cpp
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 11 2016
 * Holds all boats data
 */

#include "boat.h"


Boat::Boat(unsigned int size) : m_size(size), m_baseX(0), m_baseY(0), m_orientation(true), m_sunken(false), m_squares(std::vector<bool>(size, false))
{
    
}

Boat::~Boat()
{

}

void Boat::setOrientation(bool dir)
{
    m_orientation = dir;
}

void Boat::repair(unsigned int where)
{
    // Might raise an exception if where is higer than size
    m_squares[where] = false;
}

void Boat::destroy(unsigned int where)
{
    // Might raise an exception if where is higer than size
    m_squares[where] = true;
}

void Boat::sunk()
{
    m_sunken = true;
}

void Boat::setCoordinates(unsigned int x, unsigned int y)
{
    m_baseX = x;
    m_baseY = y;
}


unsigned int Boat::x()
{
    return m_baseX;
}

unsigned int Boat::y()
{
    return m_baseY;
}

unsigned int Boat::size()
{
    return m_size;
}

bool Boat::orientation()
{
    return m_orientation;
}

bool Boat::sunken()
{
    return m_sunken;
}

std::vector<bool> Boat::squares()  
{
    return m_squares;
}

void Boat::print()
{
    std::cout << "Boat size: " << m_size << std::endl;

    std::cout << "Coordinates: X= " << m_baseX << ", Y=" << m_baseY << std::endl;

    std::cout << "Orientation: ";
    if(m_orientation)
    {
        std::cout << "vertical";
    }
    else
    {
        std::cout << "horizontal";
    }
    std::cout << std::endl;

    std::cout << "<";
    for (std::vector<bool>::iterator it = m_squares.begin() ; it != m_squares.end(); ++it)
    {
        if(*it)
        {
            std::cout << "X";
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << ">" << std::endl;
}
