//
// Created by igor on 20.01.2020.
//
#include "Stats.h"
#include <string>
Staticstics::Staticstics()
{
    this->level=1;
    this->expirience=0;
    this->maxLife=100;
    this->currentLife=100;
    this->strenght=1;
    this->speed=1;
    this->defence=1;
    this->freePoints=0;
    this->stamina=100;
}
int Staticstics::getExperience(){
    return this->expirience;
}
int Staticstics::getMaxLife(){
    return this->maxLife;
}
int Staticstics::getLevel(){
    return this->level;
}
void Staticstics::IncreaseStatistics(){ }
void Staticstics::increaseExperience(int gainedExpirence){
    this->expirience += gainedExpirence;
}
void Staticstics::LevelUp(){
    this->level++;
    this->freePoints++;
}