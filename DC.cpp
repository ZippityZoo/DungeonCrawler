#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "tile.h"
#include "dungeon.h"


int main(){

    Dungeon d = Dungeon(Size::Small);
    d.assign_available_rooms();
    int sum = d.sumadjs();
    d.connect_by_pool();
    d.print_dungeon();


    return 0;
}
