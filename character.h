#ifndef CHARACTER_H
#define CHARACTER_H


#include <list>
#include "tile.h"
#include "item.h"

class Character{
    private:
        std::string name;
        double attack_power;
        double health;
        std::shared_ptr<Tile> current_room;
        std::vector<std::shared_ptr<Item>> inventory;
};

#endif