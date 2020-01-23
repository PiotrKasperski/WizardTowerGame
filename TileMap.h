#include <SFML/Graphics.hpp>
#include "RendererObject.h"
#include "CollisionObject.h"

#ifndef WIZARDTOWERGAME_TILEMAP_H
#define WIZARDTOWERGAME_TILEMAP_H
class TileMap : public sf::Drawable, public CollisionObject {
public:

    TileMap(const std::string &tilesetPath, const sf::Vector2u &tileSize, const int *tiles, unsigned int width,
            unsigned int height);

    std::vector<int> isWall = {1, 2, 3, 4};

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
public:
    void Draw(sf::RenderWindow &window) override;

private:

    sf::VertexArray *vertices;
    sf::Texture *tileset;

    std::string tilesetPath;
    sf::Vector2u tileSize;
    const int *tiles;
    unsigned int width;
    unsigned int height;

    void setCollisionBoxes(int, int, int);
};

#endif //WIZARDTOWERGAME_TILEMAP_H