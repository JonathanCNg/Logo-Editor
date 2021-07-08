//
// Created by jonng on 5/30/2021.
//

#include "LogoTextEntry.h"

//TextInput LogoTextEntry::the_text_input;
//std::string LogoTextEntry::cows("Cows go moo");

LogoTextEntry::LogoTextEntry() {
    the_label.setString("Logo Text");
    the_label.setCharacterSize(17);
    setString("YOUR LOGO");
    setBoxSize({260.f,30.f});
    setPosition({765.f,50.f});
    the_text_input.setOutlineThickness(1.f);
}

void LogoTextEntry::setPosition(sf::Vector2f position) {
    the_label.setPosition(position);
    the_text_input.setPosition({the_label.getPosition().x,the_label.getPosition().y+the_label.getGlobalBounds().height+10.f});
}

std::string LogoTextEntry::getString() {
    return the_text_input.getString();
}

void LogoTextEntry::draw(RenderTarget &window, sf::RenderStates states) const {
    window.draw(the_label);
    window.draw(the_text_input);
}

void LogoTextEntry::addEventHandler(RenderWindow &window, sf::Event event) {
    the_text_input.addEventHandler(window,event);
}

void LogoTextEntry::update() {
    the_text_input.update();
}

void LogoTextEntry::setBoxSize(sf::Vector2f size) {
    the_text_input.setSize(size);
}

bool LogoTextEntry::boxContains(sf::Vector2i position) {
    return (the_text_input.getGlobalBounds().contains((sf::Vector2f)position));
}

void LogoTextEntry::enable() {
    the_text_input.enable();
}

void LogoTextEntry::disable() {
    the_text_input.disable();
}

void LogoTextEntry::setString(const std::string& labelString) {
    the_text_input.setString(labelString);
}

void LogoTextEntry::reset() {
    setString("YOUR LOGO");
}
