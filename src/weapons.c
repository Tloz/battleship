/* 
 * weapons.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Description
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "weapons.h"

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
