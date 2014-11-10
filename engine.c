/* 
 * engine.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Description
 */

#include "engine.h"

#include <stdio.h>

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

    switch(vertical) // Si le bateau sort de la carte ou en rencontre un autre
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

bool shoot(int x, int y, int map[HAUTEUR][LARGEUR])
{
    printf("Debug: Shooting on (%i, %i)\n", x, y);
    if((map[x][y] == 0) || (map[x][y] == 2)) // Si on tire sur un espace vide
    {
        map[x][y] = 2;
        return false;
    }
    else if((map[x][y] == 1) || (map[x][y] == 3)) // Si on tire sur un espace rempli
    {
        map[x][y] = 3;
        return true;
    }
    else // erreur
    {
        printf("/!\\ Wut? Never supposed to get to point 1... Problem with the data in the map /!\\\n");
        return false;
    }
}

void shoot_missile(int x, int y, int map[HAUTEUR][LARGEUR])
{
    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            shoot(x + i, y + j, map);
        }
    }
}

int sonar(int x, int y, int map[HAUTEUR][LARGEUR])
{
    int count = 0;

    for(int i = -1; i <= 1; ++i)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if((map[x + i][y + j] == 1) || (map[x + i][y + j] == 3))
                ++count;
        }
    }
    return count;
}

void initialise()
{
    navires[0] = 0;
    navires[1] = 1;
    navires[2] = 1;
    navires[3] = 1;
    navires[4] = 1;

    for(int i = 0; i < HAUTEUR; ++i)
    {
        for(int j = 0; j < LARGEUR; ++j)
        {
            j1.map[i][j] = 0;
            computer.map[i][j] = 0;
        }
    }
}