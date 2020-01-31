//
// Created by klonek on 16.01.20.
//

#ifndef WIZARDTOWERGAME_CAMERA_H
#define WIZARDTOWERGAME_CAMERA_H


#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Camera {
    sf::View camera;
    sf::RenderWindow *window;
public:
    Camera(sf::RenderWindow &window, sf::Vector2f position);

    void Update(sf::Vector2f position);
};


#endif //WIZARDTOWERGAME_CAMERA_H
