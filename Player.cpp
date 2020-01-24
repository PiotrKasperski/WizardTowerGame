//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <sstream>
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
    Player::setDmgBox(sf::FloatRect(
            sf::Vector2f(this->sprite.getGlobalBounds().left - 32, this->sprite.getGlobalBounds().top - 32),
            sf::Vector2f(96.0f, 96.0f)));
    Player::setDefenseBox(this->sprite.getGlobalBounds());
    this->strenght = 20;
    this->defence = 20;
}

void Player::move(std::vector<CollisionObject *> colObj) {


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        MovableObjects::moveVector.y -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        MovableObjects::moveVector.y += 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        MovableObjects::moveVector.x -= 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        MovableObjects::moveVector.x += 5;
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

std::vector <std::string> Player::getStats()
{
    std::vector <std::string> v;
    std::ostringstream ss;

    std::string statystic;
    statystic="Level: ";
    ss << this->getLevel();
    statystic+=ss.str();
    v.push_back(statystic);

    statystic="Exp: ";
    ss.str(std::string());
    ss<< this->getExperience();
    statystic+=ss.str();
    statystic+="/";
    ss.str(std::string());
    ss<< this->getExperience();
    statystic+=ss.str();
    v.push_back(statystic);

    statystic="Life: ";
    ss.str(std::string());
    ss << this->getCurrentLife();
    statystic+=ss.str();
    statystic+="/";
    ss.str(std::string());
    ss << this->getMaxLife();
    statystic+=ss.str();
    v.push_back(statystic);

    statystic="Strenght: ";
    ss.str(std::string());
    ss << this->getStrenght();
    statystic+=ss.str();
    v.push_back(statystic);

    statystic="Defense: ";
    ss.str(std::string());
    ss << this->getDefence();
    statystic+=ss.str();
    v.push_back(statystic);

    statystic="Speed: ";
    ss.str(std::string());
    ss << this->getSpeed();
    statystic+=ss.str();
    v.push_back(statystic);


    return v;
}

void Player::Update(sf::RenderWindow &window) {
    FightingObject::Update(window);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
        this->LevelUp();
    }
    Player::sprite.setPosition(Player::position.x, Player::position.y);
}

void Player::Fight(std::vector<FightingObject *> vector) {
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::A))) {
        Player::MakeDamage(vector);
    }
}

void Player::TakeDamage(int gainedDmg, FightingObject &object) {
    FightingObject::TakeDamage(gainedDmg, object);
}




