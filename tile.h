#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <random>
#include <vector>
/*
This class should deifine the tile which the player
will theoretically walk around on

A tile should have :
1.)Pointers to tile around it so it should at least point to 1 or 4
2.)A random id 

*/

class Tile{
    private:
        std::vector<std::shared_ptr <Tile> > adjacent_rooms;
        long id;
        long availibility;
    public:
        Tile(){
            id = rand();
            long availibility = 0;
        };
        /*
        Tile(long id):id{id}{
            //this.id = id;
            long availibility = 0;
        };
        */
        void printids(){
            std::cout<<"my id is "<<id<<" and my adjacent_rooms ids are:"<<std::endl;
            for(auto &e: adjacent_rooms){
                std::cout<<"->"<<e->id;
            }
        }
        std::vector<std::shared_ptr<Tile> >get_adjacent_rooms(){
            return adjacent_rooms;
        }
        /* 
        *searches our adjacent_rooms rooms for the key room
        *if the key is found return true
        */
        bool searchadjs(Tile key){
            for(auto& e: adjacent_rooms){
                if(e->id == key.id){
                    return true;
                }
            }
            return false;
        }
        std::shared_ptr<Tile> room_at(int i){
            return adjacent_rooms.at(i);
        }
        void append_room(std::shared_ptr<Tile> adj){
            adjacent_rooms.push_back(adj);
            availibility -= 1;
        }
        void assign_availibility(int adj){
            availibility = adj;
        }
        long retid(){
            return id;
        }
        long retadj(){
            return availibility;
        }
        void destoryconnection(){
            availibility--;
        }
        friend bool operator!=(const Tile& lhs,const Tile& rhs){
            return lhs.id != rhs.id;
        }
        friend bool operator==(const Tile& lhs,const Tile& rhs){
            return lhs.id == rhs.id;
        }
};
//question how should i initthe random pointers to the next room

#endif