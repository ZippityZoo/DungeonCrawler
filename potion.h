#ifndef POTION_H
#define POTION_H

#include "item.h"

enum class Type{Health,Mana,Poision};

class Potion : public Item{
    Type potion_type;

};


#endif