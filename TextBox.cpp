//
// Created by jonng on 4/11/2021.
//

#include "TextBox.h"

TextBox::TextBox() {
    setOutlineColor(sf::Color::White);
    setFillColor({55,55,55});
    setOutlineThickness(2.f);
    setSize({900.0f,50.0f});
    setPosition({10.0f,110.0f});
}
bool TextBox::contains(sf::Vector2i aVector) {
    return ((aVector.x > getGlobalBounds().left) && (aVector.x < getGlobalBounds().left+getGlobalBounds().width) && (aVector.y > getGlobalBounds().top) && (aVector.y < getGlobalBounds().top+getGlobalBounds().height));
}