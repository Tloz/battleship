/* 
 * weapons.h
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Description
 */
 
#ifndef WEAPONS_H
#define WEAPONS_H

#include <stdbool.h>

#include "game.h"


bool shoot(int x, int y, int map[HAUTEUR][LARGEUR]);
void shoot_missile(int x, int y, int map[HAUTEUR][LARGEUR]);
int sonar(int x, int y, int map[HAUTEUR][LARGEUR]);

#endif // WEAPONS_H
