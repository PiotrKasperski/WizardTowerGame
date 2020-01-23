//
// Created by klonek on 23.01.20.
//

#include "Door.h"

Door::Door(const sf::FloatRect &door, const std::string &doorTo, const sf::Vector2f &positionBehindDoor) : door(door),
                                                                                                           doorTo(doorTo),
                                                                                                           positionBehindDoor(
                                                                                                                   positionBehindDoor) {}

const sf::FloatRect &Door::getDoor() const {
    return door;
}

const std::string &Door::getDoorTo() const {
    return doorTo;
}

const sf::Vector2f &Door::getPositionBehindDoor() const {
    return positionBehindDoor;
}
