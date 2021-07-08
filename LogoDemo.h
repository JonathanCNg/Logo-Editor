//
// Created by jonng on 5/30/2021.
//

#ifndef FINALPROJECTCS8_LOGODEMO_H
#define FINALPROJECTCS8_LOGODEMO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include <cassert>

class LogoDemo : public sf::Drawable, public sf::Transformable {
public:
    LogoDemo();
    void setString(std::string text);
    void setTextColor(sf::Color color);
    void setTextOpacity(sf::Uint8 opacityValue);
    void setMirrorOpacity(sf::Uint8 opacityValue);
    void setTextPosition(sf::Vector2f position);
    void setMirrorPosition(sf::Vector2f position);
    void setFontSize(unsigned int fontSize);
    void setMirrorSkew(float skewValue); //0 to (-1)*skewValue
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
//    void addEventHandler(sf::RenderWindow& main_window, sf::Event event);
//    void update();
    sf::FloatRect getTextGlobalBounds();
    sf::FloatRect getMirrorGlobalBounds();
    void setMirrorColor(sf::Color color);
    void setFont(std::string font);
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setSceneColor(sf::Color color);
    void setTextPositionFromBottomLeft(sf::Vector2f position);
    void setMirrorPositionFromBottomLeft(sf::Vector2f position);
private:
    sf::RectangleShape demoArea, thin_outline, grey_frame;
    sf::Text main_text;
    sf::Text mirror_text;
    sf::Vector2f mirror_effective_position;
    std::string current_font;
    void setBothFonts(sf::Font& font);
};


#endif //FINALPROJECTCS8_LOGODEMO_H
