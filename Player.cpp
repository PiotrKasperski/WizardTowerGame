//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Player.h"

Player::Player(const sf::Vector2f &position, const std::string &textureFilename, sf::IntRect textureRect) {
    Player::position = position;
    Player::texture.loadFromFile(textureFilename);
    Player::sprite.setTexture(Player::texture);
    Player::sprite.setTextureRect(textureRect);
    Player::sprite.setPosition(position.x, position.y);
    MovableObjects::moveVector = sf::Vector2f(0.0f, 0.0f);
    CollisionObject::boundingBoxes = new std::vector<sf::FloatRect *>();
    CollisionObject::boundingBoxes->push_back(new sf::FloatRect(this->sprite.getGlobalBounds()));
    Player::setDmgBox(*new sf::FloatRect(this->sprite.getGlobalBounds()));
    Player::setDefenseBox(*new sf::FloatRect(this->sprite.getGlobalBounds()));
}

void Player::move(std::vector<CollisionObject *> colObj) {


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        MovableObjects::moveVector.y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        MovableObjects::moveVector.y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        MovableObjects::moveVector.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        MovableObjects::moveVector.x += 1;
    }



    (*CollisionObject::boundingBoxes)[0]->left += MovableObjects::moveVector.x;
    if (isCollision(colObj)) {
        (*CollisionObject::boundingBoxes)[0]->left -= MovableObjects::moveVector.x;
    }

    (*CollisionObject::boundingBoxes)[0]->top += MovableObjects::moveVector.y;
    if (isCollision(colObj)) {
        (*CollisionObject::boundingBoxes)[0]->top -= MovableObjects::moveVector.y;
    }

    Player::position = sf::Vector2f((*CollisionObject::boundingBoxes)[0]->left,
                                    (*CollisionObject::boundingBoxes)[0]->top);


    MovableObjects::moveVector = sf::Vector2f(0.0f, 0.0f);
}

void Player::Update(sf::RenderWindow &window) {
    Player::sprite.setPosition(Player::position.x, Player::position.y);
    std::cout << Player::getCurrentLife() << std::endl;
}




