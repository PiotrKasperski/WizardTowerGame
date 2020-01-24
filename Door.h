//
// Created by klonek on 23.01.20.
//

#ifndef WIZARDTOWERGAME_DOOR_H
#define WIZARDTOWERGAME_DOOR_H


#include <SFML/Graphics/Rect.hpp>
#include <iostream>

class Door {
    sf::FloatRect door;
    std::string doorTo;
    sf::Vector2f positionBehindDoor;

public:
    Door();

    friend std::istream &operator>>(std::istream &in, Door &door);

    const sf::FloatRect &getDoor() const;

    const std::string &getDoorTo() const;

    const sf::Vector2f &getPositionBehindDoor() const;

    Door(const sf::FloatRect &door, const std::string &doorTo, const sf::Vector2f &positionBehindDoor);
};


#endif //WIZARDTOWERGAME_DOOR_H
