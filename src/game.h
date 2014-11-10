/* 
 * game.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Holds all initiayion functions and main routine to play
 */

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define HAUTEUR 10
#define LARGEUR 10
#define TAILLE_MAX_NAV 5

typedef struct 
{
    /*
     * Valeurs possibles sur les cases:
     * - 0: aucune interraction avec la case, elle est vide
     * - 1: aucune interraction avec la case, elle est occupée
     * - 2: on a attaqué la case, elle est vide
     * - 3: On a attaqué la case, elle est occupée
     */
    char *name;
    int score;
    int missiles;
    int sonar;
    int map[HAUTEUR][LARGEUR];
} joueur;

joueur j1, computer;

int navires[TAILLE_MAX_NAV]; // Tableau de 5 cases, on y stocke le nombre de bateau de taille index + 1
int parts; // Total number of squares occupied by boats

joueur players[2]; 

void play(joueur player);
void place_boat(int x, int y, int map[HAUTEUR][LARGEUR], bool vertical, int boat_size);
int check_boat_placement(int x, int y, int map[HAUTEUR][LARGEUR], bool vertical, int boat_size);
void initialise();


#endif // GAME_H
