#ifndef DUNGEON_H
#define DUNGEON_H

#include <list>
#include "tile.h"

enum class Size {Tiny = 5,Small=10,Medium=20,Large=30};

class Dungeon{
    private:
        std::vector<std::shared_ptr<Tile> > map;
        std::string dungeon_name;
        std::vector<long> pool;
        //std::default_random_engine& gen;
        std::shared_ptr<Tile> start;
    public:
        Dungeon(Size size){
            int s = (int)size;
            for(int i = 0; i < s; i++){
                map.push_back(std::make_shared<Tile>());
                //std::cout<<i<<std::endl;
                //pool.push_back(map.back().retadj());
            }
            start = map.at(1);
        }
        /**
         * Assigns each tile a random number of rooms availible
         * 
         * 
        */
        void assign_available_rooms(){
            auto& start = map.front();
            int random = 0;
            for(int i = 0;i < map.size();i++){
                if(map.at(i) != start){
                    random = rand()%4+1;
                    map.at(i)->assign_availibility(random);
                }else{
                    random = 1;
                    map.at(i)->assign_availibility(random);
                }
                pool.push_back(i);
                //std::cout<<map.at(i)->retid()<<"'s available rooms are "<<map.at(i)->retadj()<<std::endl;
            }
        }
        /*
        *Perhaps instead of a random connection
        *we search from a pool of numbers that are a availible
        */
        void random_connection(){
            //test stop condition
            int i = 0;
            //for each tile pointer in map
            for(auto& e: map){
                //while the tile has rooms greater than 0
                //e.retadj() > 0
                while(e->retadj() > 0 && i < 30){
                    //connect the tile with map at e
                    auto pick = map.at(rooms_available());
                    connect(e,pick);
                    print_pool();
                    i++;
                }
            }
            print_pool();
            print_available_rooms();

        }
        void connect_by_pool(){
            int i = 0;
            while(!pool.empty() && i < 45){
                auto picka = map.at(rooms_available());
                if(pool.size() == 1){
                    pool.pop_back();
                    break;
                }
                auto pickb = map.at(rooms_available());
                connect(picka,pickb);
                i++;
            }
        }
        /*
        *This funciton is just for testing but it will
        *Print the ids and their next rooms
        * */
        void print_dungeon(){
            for(auto& e: map){
                std::cout<<"\nRoom Id "<<e->retid()<<std::endl;
                e->printids();
            }
        }
        /*
        *this function will be the pool that the random connection funciton will
        *select from so if 1,4,6,7 are have rooms availible they will be numbers we can select from
        *this functon will return a random available room 
        *  */
        long rooms_available(){
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            //assuming pool has the ids we can pick from
            int key = -1;
            key = find_key();
            //Pop the number that has zero rooms left 
            if(key != -1){
                remove_full_tile(key);
            }
            std::shuffle(pool.begin(),pool.end(),std::default_random_engine(seed));
            //return random number within pool
            return pool.at(rand() % pool.size());
            //return 0;//pool;
        }
        /*
        *Used in the rooms_available func this will find they tile with no adjacent rooms
        */
        long find_key(){
            int key = -1;
            for(int i = 0;i<map.size();i++){
                //if the tile has no adjacent rooms
                //lower the room count at that tile
                //so we know not to grab from it later
                if(map.at(i)->retadj() == 0){
                    key = i;
                    map.at(i)->destoryconnection();
                    //std::cout<<key<<std::endl;
                    return key;
                }
            } 
            return -1;
        }
        /**
         * used in the rooms_available func
         * removes a tile that has no more room
        */
        void remove_full_tile(int key){
            int temp = 0;
            for(int i = 0;i<pool.size();i++){
                    //if the key matches swap and pop the room
                    if(pool.at(i) == key){
                        temp = pool.at(i);
                        pool.at(i) = pool.back();
                        pool.back() = temp;
                        temp = pool.back();
                        //std::cout<<temp<<" was removed"<<std::endl;
                        pool.pop_back();
                        break;
                        //pool.at();
                    }
                }
        }
        /**
         * This function is to test the destruction of functions to see how well
         * the new avail func works
         * 
        */
        void test_destroy(){
            for(int i = 0;i < map.size();i++){
                while(map.at(i)->retadj() > 0){
                    //printa();
                    //std::cout<<avail()<<","; 
                    map.at(rooms_available())->destoryconnection();
                    //e.connect(map.at(rand() % map.size()));
                }
            }
            //std::cout<<""<<std::endl;
        }
        /*
        *func used to connect
        */
        void print_available_rooms(){
            std::cout<<"_________________________"<<std::endl;
            for(auto& e: map){
                std::cout<<e->retid()<<"'s available rooms are "<<e->retadj()<<std::endl;
            }
            
        }
        void print_pool(){
            std::cout<<"___________Pool Numbers______________"<<std::endl;
            for(int i = 0;i<pool.size();i++){
                std::cout<<pool.at(i)<<std::endl;
            }
            std::cout<<"_________________________"<<std::endl;

            
        }
        void errorchecking(){
            std::cout<<"___________Connections______________"<<std::endl;
            for(auto& e: map){
                if(e->retadj() != -1){
                    std::cout<<"\nRoom Id "<<e->retid()<<std::endl;
                    e->printids();
                }
                
            }
            std::cout<<"\n_________________________"<<std::endl;
        }
        int sumadjs(){
            int sum = 0;
            for(auto i: map){
                sum += i->retadj();
            }
            return sum;
        }
        std::shared_ptr<Tile> get_start(){
            return start;
        }
        private:
        int connect(std::shared_ptr<Tile> A, std::shared_ptr<Tile>  B){
            if(A->retid() == B->retid()){
                //perror("Error Self");
                return -1;
            }else if(A->searchadjs(*B)){
                //perror("Error Duplicate");
                return -1;
            }else if((A->retadj() <= 0 || B->retadj() <= 0)){
                //perror("Error Full");
                return -1;
            }
            A->append_room(B);
            B->append_room(A);
            //std::cout<<A->retid()<<" and "<<B->retid()<<" are connected"<<std::endl;
            //std::cout<<A->retid()<<"'s avaliblity is "<<A->retadj()<<std::endl;
            //std::cout<<B->retid()<<"'s avaliblity is"<<B->retadj()<<std::endl;
            return 0;
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
 *if the number of rooms exeeds
 *for size 10 -> 21
 *  
*/

#endif