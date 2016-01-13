/* 
 * player.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 11 2016
 * Holds all players data
 */

#include "map.h"
#include <string>

class Player
{

private:

public:
    Player(std::string name);
    ~Player();

    std::string m_name;

    int m_score;
    int m_missiles;
    int m_sonar;
    Map m_map;

    void setMap(Map m);

    std::array<std::array<unsigned int, 10>, 10> map();

    bool shoot(unsigned int x, unsigned int y, Player* target);
    bool shoot_missile(unsigned int x, unsigned int y, Player* target);
    int sonar(unsigned int x, unsigned int y, Player* target);
};