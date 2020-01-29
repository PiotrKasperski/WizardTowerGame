//
// Created by igor on 23.01.2020.
//

#include "Hud.h"
void Hud::initFont() {
    this->font.loadFromFile("../Fonts/font.ttf");
}
void Hud::initHpBar() {
    this->hpBarBackground.setSize(sf::Vector2f(100.f, 10.f));
    this->hpBarBackground.setFillColor(sf::Color(50,50,50,200));
    this->hpBarBackground.setPosition(sf::Vector2f(20,10));

    this->hpBarCurrent.setSize(sf::Vector2f((this->player->getMaxLife() / this->player->getCurrentLife() * 100), 10.f));
    this->hpBarCurrent.setFillColor(sf::Color(250,20,20,200));
    this->hpBarCurrent.setPosition(this->hpBarBackground.getPosition());

}

void Hud::InitLvlText() {
    this->lvlText.setFont(font);
    this->lvlText.setFillColor(sf::Color::Red);
    this->lvlText.setCharacterSize(10);
    this->lvlText.setString(std::to_string(this->player->getLevel()));
    this->lvlText.setPosition(sf::Vector2f(20,20));

}
void Hud::initExpBar() {
    this->expBarBackground.setSize(sf::Vector2f(100.f, 10.f));
    this->expBarBackground.setFillColor(sf::Color(50,50,50,200));
    this->expBarBackground.setPosition(sf::Vector2f(20,45));

    this->expBarCurrent.setSize(sf::Vector2f(100.f, 10.f));
    this->expBarCurrent.setFillColor(sf::Color::Yellow);
    this->expBarCurrent.setPosition(this->expBarBackground.getPosition());

}
Hud::Hud(Player* player) {
    this->player = player;
    this->initFont();
    this->initHpBar();
    this->InitLvlText();
    this->initExpBar();
}
Hud::~Hud() = default;

void Hud::updateHpBar(sf::RenderWindow& window) {
    this->hpBarBackground.setPosition(window.mapPixelToCoords(sf::Vector2i(20,10)));
    this->hpBarCurrent.setPosition(this->hpBarBackground.getPosition());
    auto lifePercentage = (float)(this->player->getCurrentLife() * 100.f / this->player->getMaxLife()) ;
    if(this->player->getCurrentLife() > 0)
        this->hpBarCurrent.setSize(sf::Vector2f(lifePercentage, 10));

}
void Hud::updateLvlText(sf::RenderWindow& window) {
    this->lvlText.setString(std::to_string(this->player->getLevel()));
    this->lvlText.setPosition(window.mapPixelToCoords(sf::Vector2i(2, 20)));
}
void Hud::updateExpBar(sf::RenderWindow& window) {
    this->expBarBackground.setPosition(window.mapPixelToCoords(sf::Vector2i(20,21)));
    this->expBarCurrent.setPosition(this->expBarBackground.getPosition());
    this->expBarCurrent.setSize(sf::Vector2f(100.f, 10.f));

}
void Hud::Update(sf::RenderWindow &window) {
    this->updateHpBar(window);
    this->updateExpBar(window);
    this->updateLvlText(window);
}

void Hud::drawHpBar(sf::RenderWindow& window) {
    window.draw(this->hpBarBackground);
    window.draw(this->hpBarCurrent);

}
void Hud::drawLvlText(sf::RenderWindow& window) {
    window.draw(this->lvlText);
}
void Hud::drawExp(sf::RenderWindow& window) {
    window.draw(this->expBarBackground);
    window.draw(this->expBarCurrent);
}

    void Hud::Draw(sf::RenderWindow &window) {
        this->updateHpBar(window);
        this->updateExpBar(window);
        this->updateLvlText(window);
        this->drawExp(window);
        this->drawHpBar(window);
        this->drawLvlText(window);
    }