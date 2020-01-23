//
// Created by klonek on 09.01.20.
//

#include "RendererObject.h"

const sf::Vector2f &RendererObject::getPosition() const {
    return position;
}

void RendererObject::setPosition(const sf::Vector2f &position) {
    RendererObject::position = position;
}

void RendererObject::Draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

void RendererObject::Update(sf::RenderWindow &window) {
    RendererObject::sprite.setPosition(position.x, position.y);
}

void RendererObject::setTexture(const sf::Texture &texture) {
    RendererObject::texture = texture;
}

void RendererObject::setSprite(const sf::Sprite &sprite) {
    RendererObject::sprite = sprite;
}

RendererObject::RendererObject(const sf::Vector2f &position, const sf::Texture &texture, const sf::Sprite &sprite)
        : position(position), texture(texture), sprite(sprite) {}

RendererObject::RendererObject() {}

const sf::Sprite &RendererObject::getSprite() const {
    return sprite;
}
