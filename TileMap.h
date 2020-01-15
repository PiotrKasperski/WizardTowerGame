#include <SFML/Graphics.hpp>
#include "RendererObject.h"

class TileMap : public sf::Drawable {
public:

    TileMap(const std::string &tilesetPath, const sf::Vector2u &tileSize, const int *tiles, unsigned int width,
            unsigned int height);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:

    /*  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
      {
          // apply the transform
          states.transform *= getTransform();

          // apply the tileset texture
          states.texture = &m_tilesset;

          // draw the vertex array
          target.draw(m_vertices, states);
      }*/

    sf::VertexArray *vertices;
    sf::Texture *tileset;

    std::string tilesetPath;
    sf::Vector2u tileSize;
    const int *tiles;
    unsigned int width;
    unsigned int height;
};