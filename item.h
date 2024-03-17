#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
    private:
        std::string name;
        std::string item_description;
    public:
        /**
         * create item with a name
        */
        Item(std::string name):name{name}{
            
        };
        /**
         * add the item descripion
         * args item description
        */
        void add_desc(std::string desc){
            item_description = desc;
        }
        /**
         * Use the item 
        */
        virtual void use_item(){};
};

#endif