#ifndef CHARACTER_H
#define CHARACTER_H


#include <list>
#include "dungeon.h"
#include "item.h"

enum Class{Warrior,Wizard,Healer,Thief};

/**
 * The generic character 
 * a character should be able to 
 * move from room to room
 * talk to "things"
 * attack things
 * check inventory
 * run away
 * invesigate things
 * things can range from enimies to npcs 
*/
class Character{
    private:
        std::string name;
        Class class_type;
        double attack_power;
        double mana;
        double max_mana;
        double max_health;
        double health;
        std::shared_ptr<Tile> current_room;
        std::shared_ptr<Tile> previous_room;
        std::vector<std::shared_ptr<Item> > inventory;
    public:
        /**
         * Class Type,
        */
        Character( std::string name, std::shared_ptr<Tile> current_room): name(name), current_room(current_room){}
        /**
         * move_choice func this should allow the player to move from one room to the next
         * the idea behind this is the player will be prompted of which rooms are availible/adjacent 
         * and choose which one to move to
        */
        void full_movement(){
            while(true){
                move_choice();
            }
        }
        private:
        void move_choice(){
            auto rooms = current_room->get_adjacent_rooms();
            int input = 0;            
            std::cout<<"Which way ?"<<std::endl;
            std::cout<<"___________"<<std::endl;
            for(int i = 0; i < rooms.size(); i++){
                if(rooms.at(i) == previous_room){
                    std::cout<<"Back"<<std::endl;
                    std::cout<<"~~~~~~~~~~~~~"<<std::endl;
                    continue;
                }
                if(rooms.size() > 1 && i == rooms.size()-1){
                    std::cout<<"or"<<std::endl;
                }
                std::cout<<"Path "<<i+1<<std::endl;
                std::cout<<"~~~~~~~~~~~~~"<<std::endl;
            }
            do{
                std::cin>>input;  
                if(input < 1 || input > rooms.size()){
                    std::cout<<"You run into a wall"<<std::endl;
                    continue;
                }
                //std::cout<<"you move through the "<<input<<"st path"<<std::endl;
                //while the input is not vaild
            }while(input < 1 || input > rooms.size());
            move(input-1);
        }
        /**
         * Actuall moving of the char through Tiles
        */
        void move(int choice){
            previous_room = current_room;
            if(choice+1%10 == 1 && choice+1 != 11){
                std::cout<<"you move through the "<<choice+1<<"st path"<<std::endl;
            }else if(choice+1%10 == 2 && choice+1 != 12){
                std::cout<<"you move through the "<<choice+1<<"nd path"<<std::endl;
            }else if(choice+1%10 == 3 && choice+1 != 13){
                std::cout<<"you move through the "<<choice+1<<"rd path"<<std::endl;
            }else{
                std::cout<<"you move through the "<<choice+1<<"th path"<<std::endl;
            }
            std::cout<<"You are in room"<<current_room->retid()<<std::endl;

            current_room = current_room->get_adjacent_rooms().at(choice);

        }
};

#endif