/* 
 * main.c
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 08 2014
 * Battleship game
 */

#include "player.h"


int main(int argc, char const *argv[])
{
    char c;
    // initialise();
    // main_test();

    //Game jeu();

    Boat b1(5);
    b1.print();
    b1.print();
    b1.print();
    Boat b2(3);
    b2.print();
    Boat b3(2);
    b3.print();
    
    Map mymap1;
    std::cout << "Placing boat 1 on (A, 0)" << std::endl;
    mymap1.placeBoat(&b1, 0, 0, true);
    std::cout << "Placing boat 2 on (A, 6)" << std::endl;
    mymap1.placeBoat(&b2, 0, 6, false);
    std::cout << "Placing boat 3 on (E, 2)" << std::endl;
    mymap1.placeBoat(&b3, 4, 2, false);
    mymap1.print(true);
    Player p1("Emeric");
    p1.setMap(mymap1);
    p1.shoot(0, 0, &p1);
    c = getchar();
    p1.shoot(1, 0, &p1);
    c = getchar();
    p1.shoot(0, 1, &p1);
    c = getchar();
    p1.shoot(1, 1, &p1);
    c = getchar();
    mymap1.print(false);
    c = getchar();
    
    mymap1.printDebug();
    mymap1.hit(0,0);
    mymap1.hit(2,2);
    mymap1.hit(3,3);
    mymap1.printDebug();
    mymap1.print(false);
    mymap1.print(true);


    return 0;
}