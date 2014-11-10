/* 
 * main.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 08 2014
 * Description
 */

#include <stdio.h>
#include <stdbool.h>
#include "interface.h"
#include "engine.h"

int main(int argc, char const *argv[])
{
    initialise();
    // ask_and_place_boats(j1.map);
    print_player_map(j1.map);
    shoot(3, 4, j1.map);
    print_player_map(j1.map);
    shoot(4, 5, j1.map);
    print_player_map(j1.map);
    shoot(2, 3, j1.map);
    print_player_map(j1.map);
    shoot_missile(7, 2, j1.map);
    print_player_map(j1.map);

    return 0;
}