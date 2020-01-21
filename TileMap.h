
#ifndef WIZARDTOWERGAME_TILEMAP_H
#define WIZARDTOWERGAME_TILEMAP_H
#include <SFML/Graphics.hpp>
#include "RendererObject.h"
#include "CollisionObject.h"

class TileMap : public sf::Drawable, public CollisionObject {
public:

    TileMap(const std::string &tilesetPath, const sf::Vector2u &tileSize, const int *tiles, unsigned int width,
            unsigned int height, std::vector<int> isWall);

    TileMap();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:

    std::vector<int> isWall;
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