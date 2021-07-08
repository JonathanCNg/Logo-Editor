//
// Created by jonng on 4/11/2021.
//

#include "Label.h"

Label::Label() : Label("Label"){}
Label::Label(std::string labelText) {
    setFont(Fonts::getFont(Fonts::MILKY_NICE));
    setFillColor(sf::Color::White);
    setCharacterSize(20);
    setString(labelText);
};