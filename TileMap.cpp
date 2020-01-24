#include <string>
#include <SFML/System.hpp>
#include <iostream>
#include "TileMap.h"


TileMap::TileMap(const std::string &tilesetPath, const sf::Vector2u &tileSize, const int *tiles, unsigned int width,
                 unsigned int height, std::vector<int> isWall) : tilesetPath(tilesetPath), tileSize(tileSize),
                                                                 tiles(tiles), width(width),
                                                                 height(height), isWall(isWall) {

    this->tileset = new sf::Texture();
    if (!this->tileset->loadFromFile(tilesetPath)) std::cout << "blad ladowaniA TEXTURY" << std::endl;
    else std::cout << "textura zaladowana" << std::endl;

    CollisionObject::boundingBoxes = new std::vector<sf::FloatRect *>();

    this->vertices = new sf::VertexArray;
    this->vertices->setPrimitiveType(sf::Quads);
    this->vertices->resize(width * height * 4);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int tileNumber = tiles[i + j * width];
            setCollisionBoxes(tileNumber, i, j);
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

void TileMap::setCollisionBoxes(int number, int left, int top) {
    std::for_each(this->isWall.begin(), this->isWall.end(), [this, number, left, top](int wallNumber) {
        if (wallNumber == number) {
            CollisionObject::boundingBoxes->push_back(
                    new sf::FloatRect(sf::Vector2f(left * tileSize.x, top * tileSize.y),
                                      sf::Vector2f(this->tileSize.x, this->tileSize.y)));
        }
    });

}

TileMap::TileMap() {}

void TileMap::Draw(sf::RenderWindow &window) {
    window.draw(this[0]);
}

const int *TileMap::getTiles() const {
    return tiles;
}

unsigned int TileMap::getWidth() const {
    return width;
}

unsigned int TileMap::getHeight() const {
    return height;
}

const std::vector<int> &TileMap::getIsWall() const {
    return isWall;
}




