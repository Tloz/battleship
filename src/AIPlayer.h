/* 
 * player.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on January 13 2016
 * Holds all players data
 */

#include "map.h"
#include <string>

 enum class AI
 {
    VerryDummy,
    Dummy,
    Normal,
    Clever,
    Omniscient 
 };

class AIPlayer : public Player
{

private:
    std::pair<unsigned int, unsigned int> nextMove;
    std::pair<unsigned int, unsigned int> lastMove;

public:
    AIPlayer(std::string name, AI level);
    ~AIPlayer();

    void play();
    void computeNextMove();
    bool hasNextMove();

    AI m_level;
};