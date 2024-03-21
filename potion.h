#ifndef POTION_H
#define POTION_H

#include "item.h"

enum Type{Health=0,Mana=1,Poision=2};


class Potion : public Item{
    private:
    Type potion_type;
    std::string name;
    public:
    Potion(Type potion_type):potion_type{potion_type}{
        switch(potion_type){
            case Health:
                name = "Health";
                add_desc("This is a health potion use it to return 25%% of your health");
                break;
            case Mana:
                name = "Mana";
                add_desc("This is a mana potion use this to recover 25%% of your mana.\n Unless you are a wizard. DO NOT DRINK");
                break;
            case Poision:
                name = "Poision";
                add_desc("Drink Me");
                break;
        }
    };
    /**
     * dependin on the potion type the return will be an int for the effect done on 
     * health mana or mental
     * for example the health potion type will return 1.25 which is the ammount it will heal you about
    */
    int use_item(){
        switch(potion_type){
            case Health:
                return 1.25;
            case Mana:
                return 1.25;
            case Poision:
                return -10;
        }
    }
};


#endif