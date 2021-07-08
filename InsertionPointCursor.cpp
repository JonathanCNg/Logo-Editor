//
// Created by jonng on 4/11/2021.
//

#include "InsertionPointCursor.h"

InsertionPointCursor::InsertionPointCursor() {
    disable();
    setFont(Fonts::getFont(Fonts::MILKY_NICE));
    setFillColor(sf::Color::White);
    setCharacterSize(40);
}
void InsertionPointCursor::enable() {
    is_enabled = true;
}
void InsertionPointCursor::disable() {
    is_enabled = false;
    setString(' ');
}
void InsertionPointCursor::update() {
    if (is_enabled) {
        if(the_clock.getElapsedTime().asMilliseconds() > 500) {
            setString(' ');
        }
        if(the_clock.getElapsedTime().asMilliseconds() > 1000) {
            setString('|');
            the_clock.restart();
        }
    }
}

float InsertionPointCursor::getTopY() const {
    return top_y;
}

void InsertionPointCursor::setTopY(float topY) {
    top_y = topY;
}

float InsertionPointCursor::getLeftX() const {
    return left_x;
}

void InsertionPointCursor::setLeftX(float leftX) {
    left_x = leftX;
}
