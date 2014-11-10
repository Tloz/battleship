/* 
 * interface.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Description
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "engine.h"

void ask_and_place_boats(int map[HAUTEUR][LARGEUR]);
bool ask_and_place_boat(int map[HAUTEUR][LARGEUR], int boat_size);
void print_player_map(int map[HAUTEUR][LARGEUR]);
void print_map(int map[HAUTEUR][LARGEUR]);

#endif // INTERFACE_H
