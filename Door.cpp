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

std::istream &operator>>(std::istream &in, Door &door) {
    in >> door.door.width;
    in >> door.door.height;
    in >> door.door.left;
    in >> door.door.top;
    in >> door.doorTo;
    in >> door.positionBehindDoor.x;
    in >> door.positionBehindDoor.y;
    door.door.left *= 32;
    door.door.top *= 32;
    door.positionBehindDoor.x *= 32;
    door.positionBehindDoor.y *= 32;
    return in;
}

Door::Door() {}
