//
// Created by igor on 21.01.2020.
//

#include <iostream>
#include "Equipment.h"
Equipment::Equipment() {}
Equipment::~Equipment() {}
void Equipment::use(std::vector<Equipment *> eqVector) {
    std::cout << "eq used" << std::endl;
}
void Equipment::use(std::vector<Equipment *> & eqPlayer, std::vector<Equipment *> & eqLoot) {
    if(std::find(eqPlayer.begin(), eqPlayer.end(), this) != eqPlayer.end()){
        if(this->isEquiped) this->isEquiped = false;
        eqLoot.push_back(this);
        eqPlayer.erase(std::find(eqPlayer.begin(), eqPlayer.end(), this));
    } else {
        eqPlayer.push_back(this);
        eqLoot.erase(std::find(eqLoot.begin(), eqLoot.end(), this));

    }
}

