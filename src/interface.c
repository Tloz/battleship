/* 
 * interface.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Description
 */

#include "interface.h"

#include <stdio.h>

void print_map(int map[HAUTEUR][LARGEUR])
{
    printf("\\+0|1|2|3|4|5|6|7|8|9+\n");
    for(int i = 0; i < HAUTEUR; ++i)
    {
        printf("%c|", 'A' + i);
        for(int j = 0; j < LARGEUR; ++j)
        {
            char c;
            switch(map[j][i])
            {
                case 0:
                case 1:
                    c = ' ';
                    break;
                case 2:
                    c = '.';
                    break;
                case 3:
                    c = 'X';
                    break;
                default:
                    // Erreur
                    c = '?';
                    break;
            }
            printf("%c|", c);
        }
        printf("\n");
    }
    printf("+--------------------+\n");
}

void print_player_map(int map[HAUTEUR][LARGEUR])
{
    printf("\\+0|1|2|3|4|5|6|7|8|9+\n");
    for(int i = 0; i < HAUTEUR; ++i)
    {
        printf("%c|", 'A' + i);
        for(int j = 0; j < LARGEUR; ++j)
        {
            char c;
            switch(map[j][i])
            {
                case 0:
                    c = ' ';
                    break;
                case 1:
                    c = '-';
                    break;
                case 2:
                    c = '.';
                    break;
                case 3:
                    c = 'X';
                    break;
                default:
                    // Erreur
                    c = '?';
                    break;
            }
            printf("%c|", c);
        }
        printf("\n");
    }
    printf("+--------------------+\n");
}

bool ask_and_place_boat(int map[HAUTEUR][LARGEUR], int boat_size)
{
    int x, y, z;
    printf("Placement du bateau de taille %i\n", boat_size);
    printf("Indiquez la coordonnée x: ");
    scanf("%i", &x);
    printf("Indiquez la coordonnée y: ");
    scanf("%i", &y);
    printf("Indiquez l'orientation (0->Vertical, 1->Horizontal) : ");
    scanf("%i", &z);
    switch(check_boat_placement(x, y, map, z, boat_size))
    {
        case 0:
            place_boat(x, y, map, z, boat_size);
            printf("Navire positioné\n");
            return true;
        case 1:
            printf("Erreur: Les coordonnées ne sont pas sur la carte\n");
            return false;
        case 2:
            printf("Erreur: Le navire sort de la carte\n");
            return false;
        case 3:
            printf("Erreur: Le navire en croise un autre\n");
            return false;
        default:
            printf("Erreur au point 2.\n");
            return false;
    }
}

void ask_and_place_boats(int map[HAUTEUR][LARGEUR])
{
    for(int i = 0; i < TAILLE_MAX_NAV; ++i)
    {
        for(int j = 0; j < navires[i]; ++j)
        {
            print_player_map(j1.map);
            bool state = false;
            do
                state = ask_and_place_boat(map, i + 1);
            while (!state);
        }
    }
}