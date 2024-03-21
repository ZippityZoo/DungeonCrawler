#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include "tile.h"
#include "dungeon.h"
#include "character.h"

std::string getname();


int main(){

    Dungeon d = Dungeon(Size::Small);
    d.assign_available_rooms();
    //int sum = d.sumadjs();
    d.connect_by_pool();
    //d.print_dungeon();
    std::string name = getname();
    Character test = Character(name,d.get_start());
    test.full_movement();
    return 0;
}
std::string getname(){
    std::cout<<"\n\n######################################################\n\nWelcome to your unamed dungeon what is your name \n\n######################################################"<<std::endl;
    std::string input;
    std::cin>>input;
    std::cout<<"Grreat... it is nice to have you "<<input<<std::endl;
    return input;
}

