//
// Created by jonng on 6/5/2021.
//

#include "FontStyleChooser.h"

FontStyleChooser::FontStyleChooser() {
    font_dropdown_menu.setOutlineThickness(1.f);
    font_label.setCharacterSize(17);
    font_label.setString("Font Style");
    font_dropdown_menu.addItem("ARCADE");
    font_dropdown_menu.addItem("GREAT VIBES");
    font_dropdown_menu.addItem("MILKY NICE");
    font_dropdown_menu.addItem("OPEN SANS");
    font_dropdown_menu.addItem("THE FLESH");
    font_dropdown_menu.setDisplayedItem("MILKY NICE");
    font_dropdown_menu.setSize({260.f,30.f});
    setPosition({765.f,120.f});
}

void FontStyleChooser::addEventHandler(RenderWindow &window, sf::Event event) {
    font_dropdown_menu.addEventHandler(window,event);
}

void FontStyleChooser::setPosition(sf::Vector2f position) {
    font_label.setPosition(position);
    font_dropdown_menu.setPosition({position.x,position.y+font_label.getGlobalBounds().height + 10.f});
}

void FontStyleChooser::draw(RenderTarget &window, sf::RenderStates state) const {
    window.draw(font_label);
    window.draw(font_dropdown_menu);
}

std::string FontStyleChooser::getFontChoice() {
    return font_dropdown_menu.getDisplayedItem();
}

void FontStyleChooser::setFontChoice(const std::string& fontChoice) {
    font_dropdown_menu.setDisplayedItem(fontChoice);
}

void FontStyleChooser::reset() {
    setFontChoice("MILKY NICE");
}

