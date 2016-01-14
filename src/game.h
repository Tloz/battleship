/* 
 * game.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Holds all initiayion functions and main routine to play
 */

#include "player.h"


#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Player m_p1;
    Player m_p2;
    unsigned int m_time_counter;
    unsigned int m_turn_counter;
    unsigned int m_firstToPlay;

public:
    Game(Player p1, p2);
    ~Game();

    bool someoneLoose();
    unsigned int getNextPlayer();
    void play();
};


// void play(joueur player);
// void place_boat(int x, int y, int map[HAUTEUR][LARGEUR], bool vertical, int boat_size);
// int check_boat_placement(int x, int y, int map[HAUTEUR][LARGEUR], bool vertical, int boat_size);
// void initialise();


#endif // GAME_H
