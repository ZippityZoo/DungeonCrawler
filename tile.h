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
        std::vector<std::shared_ptr<Tile>> adjacent;
        long id;
        long adjrooms;
    public:
        Tile(){
            id = rand();
            long adjrooms = 0;
        }
        Tile(long id):id{id}{
            //this.id = id;
            long adjrooms = 0;
        }
        /*
        Create a two way connection so both tiles
        know they are connected
        fix two problems
        1.)check for both to see if they can connect if not 
        find some wat to connect them some other way to connect them
        2.)cant connect to self
        3.)
        */
        /*void connect(Tile adj){
            if(*this == adj){
                std::cout<<"Error Self\n";
                //perror("ERROR SELF");
            }
            else if(searchadjs(adj)){
                std::cout<<"Error Duplicate\n";
            }
            else if((adjrooms > 0 && adj.retadj() > 0)){
                adjacent.push_back(&adj);
                adj.adjacent.push_back(this); 
                adjrooms -= 1;
                adj.adjrooms -= 1;
            }else{
                std::cout<<"Error Full\n";
            }
            
            //std::cout<<"connected "<<id<<"and"<<adj.id<<std::endl;
        }
        */
        void printids(){
            std::cout<<"my id is "<<id<<" and my adjacent ids are:"<<std::endl;
            for(auto &e: adjacent){
                std::cout<<"->"<<e->id;
            }
        }
        /* 
        *searches our adjacent rooms for the key room
        *if the key is found return true
        */
        bool searchadjs(Tile key){
            for(auto& e: adjacent){
                if(e->id == key.id){
                    return true;
                }
            }
            return false;
        }
        void append_room(std::shared_ptr<Tile> adj){
            adjacent.push_back(adj);
            adjrooms -= 1;
        }
        friend bool operator!=(const Tile& lhs,const Tile& rhs){
            return lhs.id != rhs.id;
        }
        friend bool operator==(const Tile& lhs,const Tile& rhs){
            return lhs.id == rhs.id;
        }
        void assnadjs(int adj){
            adjrooms = adj;
        }
        long retid(){
            return id;
        }
        long retadj(){
            return adjrooms;
        }
        void destoryconnection(){
            adjrooms--;
        }

};
//question how should i initthe random pointers to the next room

#endif