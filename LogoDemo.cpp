//
// Created by jonng on 5/30/2021.
//

#include "LogoDemo.h"

LogoDemo::LogoDemo() : current_font(""){
    thin_outline.setFillColor(sf::Color::Transparent);
    thin_outline.setOutlineThickness(2.f);
    thin_outline.setOutlineColor(sf::Color::White);
    grey_frame.setFillColor(sf::Color::Transparent);
    grey_frame.setOutlineThickness(500.f);
    grey_frame.setOutlineColor({22, 22, 22});
    setSize({665.f,300.f});
    setPosition({50.f,55.f});
    setSceneColor(sf::Color::Black);

    setFont("MILKY NICE");
    main_text.setString("Main Text");
    mirror_text.setString("Main Text");
    main_text.setCharacterSize(100);
    mirror_text.setCharacterSize(100);
    main_text.setFillColor(sf::Color::White);
    mirror_text.setFillColor({sf::Color::White.r, sf::Color::White.g, sf::Color::White.b, 100});
    mirror_text.setPosition({main_text.getGlobalBounds().left, main_text.getGlobalBounds().top + main_text.getGlobalBounds().height});
    mirror_text.setScale(1, -0.5);
}

void LogoDemo::setString(std::string text) {
    main_text.setString(text);
    mirror_text.setString(text);
}

void LogoDemo::setTextColor(sf::Color color) {
    main_text.setFillColor(color);
}

void LogoDemo::setTextOpacity(sf::Uint8 opacityValue) {
    main_text.setFillColor({main_text.getFillColor().r,main_text.getFillColor().g,main_text.getFillColor().b,opacityValue});
}

void LogoDemo::setMirrorOpacity(sf::Uint8 opacityValue) {
    mirror_text.setFillColor({mirror_text.getFillColor().r, mirror_text.getFillColor().g, mirror_text.getFillColor().b, opacityValue});
}

void LogoDemo::setTextPosition(sf::Vector2f position) {
    main_text.setPosition(position);
}

void LogoDemo::setMirrorPosition(sf::Vector2f position) {
    mirror_effective_position = position;
    mirror_text.setPosition({mirror_effective_position.x, mirror_effective_position.y + main_text.getGlobalBounds().height + mirror_text.getGlobalBounds().height * (static_cast<float>(1.8))});
}

void LogoDemo::setFontSize(unsigned int fontSize) {
    main_text.setCharacterSize(fontSize);
    mirror_text.setCharacterSize(fontSize);
}

void LogoDemo::setMirrorSkew(float skewValue) {
    mirror_text.setScale(1, skewValue * -1);
    mirror_text.setPosition({mirror_effective_position.x, mirror_effective_position.y + mirror_text.getGlobalBounds().height * (static_cast<float>(1.8))});
}

void LogoDemo::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(demoArea);
    window.draw(mirror_text);
    window.draw(main_text);
    window.draw(thin_outline);
    window.draw(grey_frame);
}

//void LogoDemo::addEventHandler(sf::RenderWindow &main_window, sf::Event event) {
//
//}

//void LogoDemo::update() {
//
//}

sf::FloatRect LogoDemo::getTextGlobalBounds() {
    return main_text.getGlobalBounds();
}

sf::FloatRect LogoDemo::getMirrorGlobalBounds() {
    return mirror_text.getGlobalBounds();
}

void LogoDemo::setMirrorColor(sf::Color color) {
    mirror_text.setFillColor(color);
}

void LogoDemo::setFont(std::string font) {
    if (font != current_font) {
        if(font == "GREAT VIBES")
            setBothFonts(Fonts::getFont(Fonts::GREAT_VIBES));
        else if (font == "ARCADE")
            setBothFonts(Fonts::getFont(Fonts::ARCADE));
        else if (font == "THE FLESH")
            setBothFonts(Fonts::getFont(Fonts::THE_FLESH));
        else if (font == "MILKY NICE")
            setBothFonts(Fonts::getFont(Fonts::MILKY_NICE));
        else if (font == "OPEN SANS")
            setBothFonts(Fonts::getFont(Fonts::OPEN_SANS));
        else
            exit(10);
    }
    current_font = font;
}

void LogoDemo::setBothFonts(sf::Font& font) {
    main_text.setFont(font);
    mirror_text.setFont(font);
}

void LogoDemo::setSize(sf::Vector2f size) {
    demoArea.setSize(size);
    thin_outline.setSize(size);
    grey_frame.setSize({size.x + thin_outline.getOutlineThickness() * 2, size.y + thin_outline.getOutlineThickness() * 2});
}

void LogoDemo::setPosition(sf::Vector2f position) {
    demoArea.setPosition(position);
    thin_outline.setPosition(position);
    grey_frame.setPosition({position.x - thin_outline.getOutlineThickness(), position.y - thin_outline.getOutlineThickness()});
}

void LogoDemo::setSceneColor(sf::Color color) {
    demoArea.setFillColor(color);
}

void LogoDemo::setTextPositionFromBottomLeft(sf::Vector2f position) {
    main_text.setPosition({demoArea.getPosition().x+position.x,demoArea.getPosition().y+demoArea.getSize().y-position.y});
}

void LogoDemo::setMirrorPositionFromBottomLeft(sf::Vector2f position) {
    mirror_effective_position = {demoArea.getPosition().x+position.x,demoArea.getPosition().y+demoArea.getSize().y-position.y};
    mirror_text.setPosition({mirror_effective_position.x, mirror_effective_position.y + mirror_text.getGlobalBounds().height * (static_cast<float>(1.8))});

}
