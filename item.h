#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    private:
        std::string name;
        std::string item_description;
    protected:
        /**
         * create item with a name
        */
        Item(){

        };
        Item(std::string name):name(name){}
        std::string read_name(){
            return name;
        }
        /**
         * add the item descripion
         * args item description
        */
        void add_desc(std::string desc){
            item_description = desc;
        }
        /**
         * read the item description
        */
        std::string read_desc(){
            return item_description;
        }
        /**
         * Use the item 
        */
        virtual int use_item(){
            return 0;
        };
};

#endif