//
// Created by krzysztof on 01.02.2020.
//

#include <fstream>
#include "Saveloader.h"

Saveloader::Ustaw_staty(){
    std::fstream plik( "statistics.txt", std::ios::in );
    std::string stats;
    getline( plik, stats );
    statystyki.setLevel() = stats;
    getline( plik, stats );
    statystyki.setExpirience() = stats;
    getline( plik, stats );
    statystyki.setMaxLife() = stats;
    getline( plik, stats );
    statystyki.setCurrentLife() = stats;
    getline( plik, stats );
    statystyki.setStrenght() = stats;
    getline( plik, stats );
    statystyki.setSpeed() = stats;
    getline( plik, stats );
    statystyki.setDefence() = stats;
    getline( plik, stats );
    statystyki.setFreePoints() = stats;
    getline( plik, stats );
    statystyki.setStamina() = stats;



}
