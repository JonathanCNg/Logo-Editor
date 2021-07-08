//
// Created by jonng on 4/11/2021.
//
#ifndef TYPINGINSFML_MOUSEEVENTS_CPP
#define TYPINGINSFML_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template <class T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& aWindow) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return hovered(object,aWindow);
    }
    else
        return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    sf::IntRect windowBounds = {0, 0, static_cast<int>(window.getSize().x), static_cast<int>(window.getSize().y)};
    return (event.type == sf::Event::MouseButtonPressed && windowBounds.contains(static_cast<sf::Vector2i>(sf::Mouse::getPosition(window))));
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    return (object.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))));
}

template<class T>
bool MouseEvents<T>::mouseReleased(T &object, sf::RenderWindow &aWindow) {
    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return hovered(object,aWindow);
    }
    else
        return false;
}

template<class T>
bool MouseEvents<T>::mouseReleased(sf::RenderWindow &window, sf::Event event) {
    sf::IntRect windowBounds = {0, 0, static_cast<int>(window.getSize().x), static_cast<int>(window.getSize().y)};
    return (event.type == sf::Event::MouseButtonReleased && windowBounds.contains(static_cast<sf::Vector2i>(sf::Mouse::getPosition(window))));
}

#endif //TYPINGINSFML_MOUSEEVENTS_CPP