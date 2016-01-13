/* 
 * main.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 08 2014
 * Battleship game
 */

#include "map.h"

// #include "tests.h"

int main(int argc, char const *argv[])
{
    // initialise();
    // main_test();

    //Game jeu();

    Boat b1(5);
    b1.print();
    b1.destroy(0);
    b1.print();
    b1.destroy(2);
    b1.print();
    Boat b2(3);
    b2.print();
    Boat b3(2);
    b3.print();
    
    Map mymap1;
    mymap1.print();

    return 0;
}