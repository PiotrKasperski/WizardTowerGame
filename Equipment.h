//
// Created by igor on 21.01.2020.
//

#ifndef WIZARDTOWERGAME_EQUIPMENT_H
#define WIZARDTOWERGAME_EQUIPMENT_H


class Equipment {
    enum EqType {Common, Rare, Legendary, Mystic};
    int durability; // mozona zaimplementowac funkcje ze przedmiotu nie mozna uzyc gdy dura < 1
    int defense; // ile dmg jest redukowane (bron rowniez sluzy do obrony wiec wspolne)
    void use(); //
};
class Weapon: public Equipment {
    int AttackPower;
};
class Armor: public Equipment {
    enum ArmorType {Leg,Chest,Helmet};
    int additionalVitality; // dodatkowe vitality
    int additionalMaxHp; // armor zwieksza twoje zycie;
    int damangeReduction; // dodatkowy atrybut zmniejszajacy obrazenia;
};


#endif //WIZARDTOWERGAME_EQUIPMENT_H
