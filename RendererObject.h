//
// Created by klonek on 09.01.20.
//

#ifndef WIZARDTOWERGAME_RENDEREROBJECT_H
#define WIZARDTOWERGAME_RENDEREROBJECT_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class RendererObject {

public:
    virtual void Draw(sf::RenderWindow &window);

    virtual void Update(sf::RenderWindow &window);

    virtual const sf::Vector2f &getPosition() const;

    virtual void setPosition(const sf::Vector2f &position);

    virtual void setTexture(const sf::Texture &texture);

    virtual void setSprite(const sf::Sprite &sprite);

    RendererObject(const sf::Vector2f &position, const sf::Texture &texture, const sf::Sprite &sprite);

    RendererObject();

    bool operator==(const RendererObject &rhs) const;

    bool operator!=(const RendererObject &rhs) const;

    const sf::Sprite &getSprite() const;

protected:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //WIZARDTOWERGAME_RENDEREROBJECT_H
