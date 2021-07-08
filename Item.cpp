//
// Created by jonng on 5/2/2021.
//

#include "Item.h"

Item::Item() {
    text.setFont(Fonts::getFont(Fonts::MILKY_NICE));
    setIsColored(false);
}
void Item::setPosition(Vector2f position) {
    text_box.setPosition(position);
    centerTextInBox();
}
void Item::setString(String label) {
    text.setString(label);
    centerTextInBox();
}
void Item::draw (RenderTarget& target, RenderStates states) const {
    target.draw(text_box);
    target.draw(text);
}
FloatRect Item::getGlobalBounds() {
    return text_box.getGlobalBounds();
}
void Item::setSize(Vector2f size) {
    text_box.setSize(size);
    centerTextInBox();
}
float Item::getOutlineThickness() {
    return text_box.getOutlineThickness();
}
void Item::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    if (MouseEvents<TextBox>::hovered(text_box,window)) {
        setIsColored(true);
    }
    else {
        setIsColored(false);
    }
}
bool Item::contains (Vector2i aVector) {
    return text_box.contains(aVector);
}
String Item::getString() {
    return text.getString();
}
void Item::setCharacterSize(unsigned int size) {
    text.setCharacterSize(size);
}
void Item::centerTextInBox() {
    text.setPosition(text_box.getGlobalBounds().left+text_box.getGlobalBounds().width/2-text.getGlobalBounds().width/2, text_box.getGlobalBounds().top+text_box.getGlobalBounds().height/2-text.getGlobalBounds().height/1.3f);
}
void Item::setIsColored(bool aBoolean) {
    if(aBoolean) {
        text_box.setFillColor({66,66,200});
    }
    else {
        text_box.setFillColor({66,66,66});
    }
}

void Item::setOutlineThickness(float thickness) {
    text_box.setOutlineThickness(thickness);
}
