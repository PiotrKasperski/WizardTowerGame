//
// Created by igor on 20.01.2020.
//
#include "Staticstics.h"
#include <string>
Staticstics::Staticstics()
{
    this->level=1;
    this->experience = 0;
    this->maxLife=100;
    this->currentLife=100;
    this->strenght=1;
    this->speed=1;
    this->defence=1;
    this->freePoints=0;
    this->stamina=100;
}
int Staticstics::getExperience(){
    return this->experience;
}
int Staticstics::getMaxLife(){
    return this->maxLife;
}
int Staticstics::getLevel(){
    return this->level;
}
void Staticstics::IncreaseStatistics(){ }
void Staticstics::increaseExperience(int gainedExpirence){
    this->experience += gainedExpirence;
}
void Staticstics::LevelUp(){
    Staticstics::level++;
    Staticstics::freePoints++;
}

void Staticstics::setLevel(int level) {
    Staticstics::level = level;
}

int Staticstics::getExpirience() const {
    return experience;
}

void Staticstics::setExpirience(int expirience) {
    Staticstics::experience = expirience;
}

void Staticstics::setMaxLife(int maxLife) {
    Staticstics::maxLife = maxLife;
}

int Staticstics::getCurrentLife() const {
    return currentLife;
}

void Staticstics::setCurrentLife(int currentLife) {
    Staticstics::currentLife = currentLife;
}

int Staticstics::getStrenght() const {
    return strenght;
}

void Staticstics::setStrenght(int strenght) {
    Staticstics::strenght = strenght;
}

float Staticstics::getSpeed() const {
    return speed;
}

void Staticstics::setSpeed(float speed) {
    Staticstics::speed = speed;
}

int Staticstics::getDefence() const {
    return defence;
}

void Staticstics::setDefence(int defence) {
    Staticstics::defence = defence;
}

int Staticstics::getFreePoints() const {
    return freePoints;
}

void Staticstics::setFreePoints(int freePoints) {
    Staticstics::freePoints = freePoints;
}

int Staticstics::getStamina() const {
    return stamina;
}

void Staticstics::setStamina(int stamina) {
    Staticstics::stamina = stamina;
}

const std::string &Staticstics::getName() const {
    return name;
}

void Staticstics::setName(const std::string &name) {
    Staticstics::name = name;
}

bool Staticstics::operator==(const Staticstics &rhs) const {
    return level == rhs.level &&
           experience == rhs.experience &&
           maxLife == rhs.maxLife &&
           currentLife == rhs.currentLife &&
           strenght == rhs.strenght &&
           speed == rhs.speed &&
           defence == rhs.defence &&
           freePoints == rhs.freePoints &&
           stamina == rhs.stamina &&
           name == rhs.name;
}

bool Staticstics::operator!=(const Staticstics &rhs) const {
    return !(rhs == *this);
}
