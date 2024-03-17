#ifndef DUNGEON_H
#define DUNGEON_H

#include <list>
#include "tile.h"

enum class Size {Small=10,Medium=20,Large=30};

class Dungeon{
    private:
        std::vector<Tile> map;
        std::string dungeon_name;
        std::vector<long> pool;
        //std::default_random_engine& gen;
        //std::unique_ptr<Tile> end;
    public:
        Dungeon(Size size){
            int s = (int)size;
            for(int i = 0; i < s; i++){
                map.push_back(Tile(i));
                //std::cout<<i<<std::endl;
                //pool.push_back(map.back().retadj());
            }
        }
        /**
         * Assigns each tile a random number of rooms availible
         * 
         * 
        */
        void assignAvail(){
            auto& start = map.front();
            int random = 0;
            for(int i = 0;i < map.size();i++){
                if(map.at(i) != start){
                    random = rand()%4+1;
                    map.at(i).assnadjs(random);
                }else{
                    random = 1;
                    map.at(i).assnadjs(random);
                }
                pool.push_back(i);
                std::cout<<map.at(i).retid()<<"'s available rooms are "<<map.at(i).retadj()<<std::endl;
            }
        }
        /*
        *Perhaps instead of a random connection
        *we search from a pool of numbers that are a availible
        */
        void random_connection(){
            //for each tile pointer in map
            for(auto& e: map){
                //while the tile has rooms greater than 0
                //e.retadj() > 0
                while(e.retadj() > 0){
                    //connect the tile with map at e
                    auto pick = map.at(avail());
                    connect(e,pick);
                }
            }

        }
        /*
        *This funciton is just for testing but it will
        *Print the ids and their next rooms
        * */
        void PD(){
            for(auto& e: map){
                std::cout<<"\nRoom Id "<<e.retid()<<std::endl;
                e.printids();
            }
        }
        /*
        *this function will be the pool that the random connection funciton will
        *select from so if 1,4,6,7 are have rooms availible they will be numbers we can select from
        *this functon will return a random available room 
        *  */
        long avail(){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            //assuming pool has the ids we can pick from
            int key = -1;
            for(int i = 0;i<map.size();i++){
                //if the tile has no adjacent rooms
                //lower the room count at that tile
                if(map.at(i).retadj() == 0){
                    key = i;
                    map.at(i).destoryconnection();
                    std::cout<<key<<std::endl;
                    break;
                }
            }
            int temp = 0;
            /*
            *Pop the number that has zero rooms left 
            */
            if(key != -1){
                for(int i = 0;i<pool.size();i++){
                    //if the key matches swap and pop the room
                    if(pool.at(i) == key){
                        temp = pool.at(i);
                        pool.at(i) = pool.back();
                        pool.back() = temp;
                        temp = pool.back();
                        std::cout<<temp<<" was removed"<<std::endl;
                        pool.pop_back();
                        break;
                        //pool.at();
                    }
                }
            }
            std::shuffle(pool.begin(),pool.end(),std::default_random_engine(seed));
            //return random number within pool
            return pool.at(rand() % pool.size());
            //return 0;//pool;
        }
        /**
         * This function is to test the destruction of functions to see how well
         * the new avail func works
         * 
        */
        void testdestroy(){
            for(int i = 0;i < map.size();i++){
                while(map.at(i).retadj() > 0){
                    //printa();
                    //std::cout<<avail()<<","; 
                    map.at(avail()).destoryconnection();
                    //e.connect(map.at(rand() % map.size()));
                }
            }
            //std::cout<<""<<std::endl;
        }
        /*
        *func used to connect
        */
        void printa(){
            std::cout<<"_________________________"<<std::endl;
            for(auto& e: map){
                std::cout<<e.retid()<<"'s available rooms are "<<e.retadj()<<std::endl;
            }
            
        }
        void printp(){
            std::cout<<"___________Pool Numbers______________"<<std::endl;
            for(int i = 0;i<pool.size();i++){
                std::cout<<pool.at(i)<<std::endl;
            }
            std::cout<<"_________________________"<<std::endl;

            
        }
        void connect(Tile A, Tile B){
            if(A.retid() == B.retid()){
                perror("Error Self");
            }else if(A.searchadjs(B)){
                perror("Error Duplicate");
            }else if((A.retadj() <= 0 || B.retadj() <= 0)){
                perror("Error Full");
            }
            A.append_room(&B);
            B.append_room(&A);
            std::cout<<A.retid()<<" and "<<B.retid()<<" are connected"<<std::endl;
        }

};
/*
*Need to connect randomly
*each room has a number of connections
*connect each room upon initilization
*then each room gets a random number of rooms it can connect to
*1 to 4
*there must be tow rooms with 1 the start and end
*so first select the start and end rooms
*/

/**
 *The rooms available to connect to should be in the pool
 *
 *  
*/

#endif