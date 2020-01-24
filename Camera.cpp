//
// Created by klonek on 16.01.20.
//

#include "Camera.h"

Camera::Camera(sf::RenderWindow &window, sf::Vector2f position) {
    this->window = &window;
    this->camera = sf::View(position, sf::Vector2f(window.getSize().x, window.getSize().y));
    window.setView(this->camera);
}

void Camera::Update(sf::Vector2f position) {
    this->camera.setCenter(position);
    this->window->setView(this->camera);
}
