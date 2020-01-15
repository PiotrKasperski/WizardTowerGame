//
// Created by klonek on 09.01.20.
//

#include <SFML/Window/Keyboard.hpp>
#include "Player.h"

Player::Player(const sf::Vector2i &position, const std::string textureFilename, sf::IntRect textureRect) {
    Player::position = position;
    Player::texture.loadFromFile(textureFilename);
    Player::sprite.setTexture(Player::texture);
    Player::sprite.setTextureRect(textureRect);
    Player::sprite.setPosition(position.x, position.y);

    CollisionObject::boundingBoxes = new std::vector<sf::FloatRect *>();
    CollisionObject::boundingBoxes->push_back(new sf::FloatRect(this->sprite.getGlobalBounds()));

}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        Player::position.y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        Player::position.y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Player::position.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Player::position.x += 1;
    }
}

void Player::Update(sf::RenderWindow &window) {
    Player::sprite.setPosition(Player::position.x, Player::position.y);
}




