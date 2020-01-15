#include <string>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"


TileMap::TileMap(const std::string &tilesetPath, const sf::Vector2u &tileSize, const int *tiles, unsigned int width,
                 unsigned int height) : tilesetPath(tilesetPath), tileSize(tileSize), tiles(tiles), width(width),
                                        height(height) {

    this->tileset = new sf::Texture();
    if (!this->tileset->loadFromFile(tilesetPath)) std::cout << "blad ladowaniA TEXTURY" << std::endl;
    else std::cout << "textura zaladowana" << std::endl;

    this->vertices = new sf::VertexArray;
    this->vertices->setPrimitiveType(sf::Quads);
    this->vertices->resize(width * height * 4);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int tileNumber = tiles[i + j * width];

            int tu = tileNumber % (this->tileset->getSize().x / tileSize.x);
            int tv = tileNumber / (this->tileset->getSize().x / tileSize.x);

            sf::Vertex *quad = &vertices[0][(i + j * width) * 4];
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

        }
    }
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // apply the transform
    //states.transform *= getTransform();

    // apply the tileset texture
    states.texture = this->tileset;

    // draw the vertex array
    target.draw(this->vertices[0], states);
}




