/* 
 * game.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Holds all initiayion functions and main routine to play
 */

#include "game.h"

 void place_boat(int x, int y, int map[HAUTEUR][LARGEUR], bool vertical, int boat_size)
{
    if(vertical)
    {
        for(int i = 0; i < boat_size; ++i)
        {
            map[x + i][y] = 1;
        }
    }
    else
    {
        for(int i = 0; i < boat_size; ++i)
        {
            map[x][y + i] = 1;
        }
    }
}

int check_boat_placement(int x, int y, int map[HAUTEUR][LARGEUR], bool vertical, int boat_size)
{
    /*
     * Vérifie si
     * - Les coordonnées de départ sont bien dans la carte (renvoie 1)
     * - Si le bateau ne sortira pas de la carte une fois placé (renvoie 2)
     * - Si le bateau n'en croisera pas un autre (renvoie 3)
     */

    if(!((x >= 0) && (x <= LARGEUR - 1) && (x >= 0) && (y <= HAUTEUR - 1))) // Les coordonnées de base sont hors de la carte
    {
        return 1;
    }

    switch(vertical)
    {
        case true:
            if(y + boat_size > HAUTEUR) // On vérifie que le bateau ne sort pas des limites de la carte
                return 2;
            for(int i = 0; i < boat_size; ++i)
            {
                if(map[x][y + i] == 1) // On vérifie qu'il n'en rencontre pas un autre
                    return 3;
            }
            break;
        case false:
            if(y + boat_size > LARGEUR) // On vérifie que le bateau ne sort pas des limites de la carte
                return 2;
            for(int i = 0; i < boat_size; ++i)
            {
                if(map[x + i][y] == 1) // On vérifie qu'il n'en rencontre pas un autre
                    return 3;
            }
            break;
    }

    return 0; // no problem
}

void initialise()
{
    navires[0] = 0;
    navires[1] = 1;
    navires[2] = 1;
    navires[3] = 1;
    navires[4] = 1;

    for(int i = 0; i < TAILLE_MAX_NAV; ++i)
    {
        parts += (i + 1) * navires[i];
    }

    for(int i = 0; i < HAUTEUR; ++i)
    {
        for(int j = 0; j < LARGEUR; ++j)
        {
            j1.map[i][j] = 0;
            computer.map[i][j] = 0;
        }
    }
}