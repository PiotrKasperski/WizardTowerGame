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
Weapon::Weapon(std::string name, bool isEquiped, int AP, int defense) {
    this->isEquiped = isEquiped;
    this->name  = name;
    this->AttackPower = AP;
    this->defense = defense;
}
Weapon::~Weapon() {}
void Weapon::use(std::vector<Equipment *> eqVector) {
    // player handling
    if(this->isEquiped){
        this->isEquiped = false;
    } else {
        for(auto &eq : eqVector){
            if(eq->isEquiped && dynamic_cast<Weapon*>(eq) != nullptr) eq->isEquiped = false;
            this->isEquiped = true;
        }
    }
    // loot handling

}

Armor::Armor(std::string name, bool isEquiped, int DR, int defense) {
    this->isEquiped = isEquiped;
    this->name  = name;
    this->damageReduction = DR;
    this->defense = defense;
}
void Armor::use(std::vector<Equipment *> eqVector) {
    // player handling
    if(this->isEquiped){
        this->isEquiped = false;
    } else {
        for(auto &eq : eqVector){
            if(eq->isEquiped && dynamic_cast<Armor*>(eq) != nullptr) eq->isEquiped = false;
            this->isEquiped = true;
        }
    }
    // loot handling


}
Armor::~Armor() {}