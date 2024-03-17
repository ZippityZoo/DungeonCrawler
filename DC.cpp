#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "tile.h"
#include "dungeon.h"


int main(){

    //std::cout<<"Welcome to DC"<<std::endl;
    //std::string s;
    /*Tile t = Tile();
    Tile b = Tile();
    Tile c = Tile();
    t.connect(b);
    t.printids();
    t.connect(c);
    t.printids();
    c.printids();
    */
   Dungeon d = Dungeon(Size::Small);
   d.assignAvail();
   /*
   Keeping for testing purposes
   long a = d.avail(); 
   long b = d.avail();
   std::cout<<a<<"and"<<b<<std::endl;
   d.printp();
   d.testdestroy();
   d.printp();
   d.printa();
   */

   //TODO FIX random connection
   d.random_connection();
   d.PD();


    return 0;
}
